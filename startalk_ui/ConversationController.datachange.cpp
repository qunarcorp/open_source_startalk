#include "ConversationController.h"
#include "ChatDialog.h"
#include "GroupChatDialog.h"
#include "newsdialog.h"
#include "MenuRobotDialog.h"
#include "UIFrame.h"
#include "MainDialogController.h"

#include "EmotionTabDialog.h"
#include "Quickreplymsgdialog.h"
#include "Session.h"
#include "UserVcardManager.h"

#include "ExtendedSessionListView.h"
#include "portraithelper.h"
#include "Account.h"
#include "CustomDefine.h"
#include "conversationmanager.h"
#include "SystemIcon.h"
#include "AtInforData.h"
#include "./messagebubble/MessageParser.h"
#include "accountmanager.h" 
namespace MainApp
{
    void ConversationController::updateGroupHeader(const QString& jid)
    {
        RecentExtendedSessionListView* pExtendListView = getExtendedSessionViewByConversationId(jid);
        if (NULL!=pExtendListView)
        {
            pExtendListView->getRosterListView()->updateGroupHeader(jid);
        }

    }


    void ConversationController::updateAtCount(const QString& id,int count, int type, const QString&senduser)
    {
        RecentExtendedSessionListView* pExtendListView = getExtendedSessionViewByConversationId(id);
        if (NULL!=pExtendListView)
        {
            pExtendListView->getRosterListView()->updateAtCount(id,count, type);
        }
    }


    void ConversationController::updateJidLastTimeStamp(const QString& conversationId,quint64 time)
    { 
		Log::e(QString("%1 updateJidLastTimeStamp:conversationId(%2),time(%3)").arg(QStringLiteral("准备更新会话列表")).arg(conversationId).arg(time));
        RecentExtendedSessionListView* pExtendView = getExtendedSessionViewByConversationId(conversationId);
        if (NULL!=pExtendView)
        {
			Log::e(QString("%1 updateJidLastTimeStamp:conversationId(%2),time(%3)").arg(QStringLiteral("将设置会话的最后时间")).arg(conversationId).arg(time));
            pExtendView->getRosterListView()->updateConversationLastTimeStamp(
                conversationId,
                time);

            if (this->isTopChatDialog(conversationId))
            {
                pExtendView->getRosterListView()->autoScroll(conversationId);
            }

            // 更新一下所属的父窗口item的位置
            QString linkedId = pExtendView->getLindedId();
            RecentExtendedSessionListView* pBelongExtendView = getExtendedSessionViewByConversationId(linkedId);
            if (NULL!=pBelongExtendView)
            {
                pBelongExtendView->getRosterListView()->updateConversationLastTimeStamp(linkedId,time);
            }
        }
    }


    void ConversationController::updateSessionConfigration(const QString& conversationId,int configvalue)
    {
        RecentExtendedSessionListView* pExtendView = getExtendedSessionViewByConversationId(conversationId);
        if (NULL!=pExtendView)
        {
            pExtendView->getRosterListView()->updateTopMost(conversationId,
                (configvalue&Biz::SESSION_CFG_TOPMOST)==Biz::SESSION_CFG_TOPMOST);

			//消息提示的设置
			pExtendView->getRosterListView()->updateNoticeTip(conversationId,configvalue);
            pExtendView->getRosterListView()->updateNoticeOption(conversationId,(configvalue&Biz::SESSION_CFG_SILENCE)!=Biz::SESSION_CFG_SILENCE);

        }
    }



    void ConversationController::setAllMessageRead()
    {
		

		Biz::Session::getConverSationManager()->setAllMessageRead();
    }
	void ConversationController::onAllConversationMessageReaded()
	{
		for (RecentExtendedSessionListView* pExtend : m_jid2ExtendView.values())
		{
			if (NULL != pExtend)
			{
				pExtend->getRosterListView()->updateAllConversationUnreadCount();
			}
		}

        SystemIcon::instance().stopTrayIcon();
        UIFrame::getMainDialogController()->taskTabFlush(false);
	}

    void ConversationController::increaseAtNotice(const QString& conversationId,int count, int type, const QString&atmsgid)
    {
        RecentExtendedSessionListView* pExtendView = getExtendedSessionViewByConversationId(conversationId);
        if (NULL!=pExtendView)
        {
            pExtendView->getRosterListView()->increaseAtCount(conversationId,count,type, atmsgid);
        }
    }

    void ConversationController::clearAtNotice(const QString& id)
    {
        RecentExtendedSessionListView* pExtendView = getExtendedSessionViewByConversationId(id);
        if (NULL!=pExtendView)
        {
            pExtendView->getRosterListView()->updateAtCount(id,0,Biz::AtOne);
        }
    }


    void ConversationController::updatePresence(const QString& userId, int presence)
    {
        BaseChatDialog* pDialog = findConversationBaseChatDialog(userId);
        if (NULL!=pDialog)
        {
            pDialog->updatePresence(userId,presence);
        }
    }

    void ConversationController::onRosterCardUpdate(const QString& jid)
    {
        RecentExtendedSessionListView* pExtendView = getExtendedSessionViewByConversationId(jid);
        if (NULL!=pExtendView)
        {
            pExtendView->getRosterListView()->updatevCard(jid);
        }
    }

    void ConversationController::updateConversationChannelId(const QString& conversationId,const QString& channelid)
    {
        ChatDialog* pDialog = dynamic_cast<ChatDialog*>(findConversationBaseChatDialog(conversationId));
        if (NULL!=pDialog)
        {
            pDialog->setChannelId(channelid);
        }
    }


    void ConversationController::updateMarkInfo(const QString& conversationId)
    {
        auto callback = createCallback<QSharedPointer<Biz::ConversationMarkInfo>>([this,conversationId](const QSharedPointer<Biz::ConversationMarkInfo>& spInfo){
            if (!spInfo.isNull())
            {
                QSharedPointer<Biz::ImSelfPerson> spPerson = Biz::Session::getUserVcardManager()->userVcard(conversationId);
                if (!spPerson.isNull())
                {
                    spPerson->strMarkName = spInfo->markTitle();
                }
                else
                {
                    QSharedPointer<Biz::ImSelfPerson> spNewPerson (new Biz::ImSelfPerson);
                    spNewPerson->strUserId = conversationId;
                    spNewPerson->strMarkName = spInfo->markTitle();
                    Biz::Session::getUserVcardManager()->addUserVcard(spNewPerson);
                }
                QStringList ids;
                ids << conversationId;
                emit Biz::Session::getUserVcardManager()->sgUseVcardChanged(ids);
            }
        },[]{});
        Biz::Session::getConverSationManager()->getConversationMarkInfo(conversationId,callback);
    }


    void ConversationController::updateDisplayName(const QString& conversationId,const QString& displayName)
    {
        MenuRobotDialog* pDialog = dynamic_cast<MenuRobotDialog*>(findConversationBaseChatDialog(conversationId));
        if (NULL!=pDialog)
        {
            pDialog->setDisplayName(displayName);
        }

        RecentExtendedSessionListView* pExtendView = getExtendedSessionViewByConversationId(conversationId);
        if (NULL!=pExtendView)
        {
            pExtendView->getRosterListView()->updateRobotVcard(conversationId,displayName);
        }
    }

    void ConversationController::onRobotVcardUpdate(const QList<QSharedPointer<Biz::RobotVcard>>& robotVcards)
    {
        for (QSharedPointer<Biz::RobotVcard> spVcard:robotVcards)
        {
			if (!spVcard.isNull())
			{
				QString conversationId = Biz::MessageUtil::makeSureUserJid(spVcard->RbtId());
				QString displayName = Biz::Session::getRobotManager()->getRobotName(spVcard->RbtId());
				updateDisplayName(conversationId,displayName);
			}
            
        }
    }

	void ConversationController::addAtInfor( const QString&groupJid, const QString&userjid, const QString&msgid )
	{
		if (groupJid.isEmpty() || userjid.isEmpty() || msgid.isEmpty())
		{
			return;
		}

		if (mAtinformap.contains(groupJid))
		{
			QList<QSharedPointer<AtInforItem>> list = mAtinformap.value(groupJid);
			bool bret = false;
			QSharedPointer<AtInforItem> item;
			for (QSharedPointer<AtInforItem> itemone: list)
			{
				if (!itemone.isNull())
				{
					if (itemone->mUserJid == userjid)
					{
						item = itemone;
						bret = true;
						break;	
					}
				}
				
			}

			if (bret)
			{
				if (!item.isNull())
				{
					item->mMsgId.push_back(msgid);
				}
			}
			else
			{
				QSharedPointer<AtInforItem> item(new AtInforItem);
				item->mUserJid = userjid;
				item->mMsgId.push_back(msgid);
				list.push_back(item);
			}

			mAtinformap.insert(groupJid, list);
		}
		else
		{
			QList<QSharedPointer<AtInforItem>> list;
			QSharedPointer<AtInforItem> item(new AtInforItem);
			item->mUserJid = userjid;
			item->mMsgId.append(msgid);
			list.push_back(item);

			mAtinformap.insert(groupJid, list);
		}
	}

	QStringList ConversationController::getAtInforMemberList(const QString&groupjid)
	{
		QStringList groupmeberlist;
		if (mAtinformap.contains(groupjid))
		{
			for (QSharedPointer<AtInforItem> oneitem: mAtinformap.value(groupjid))
			{
				if (oneitem.isNull())
				{
					groupmeberlist.push_back(oneitem->mUserJid);
				}
				
			}
		}

		return groupmeberlist;
	}

	QStringList ConversationController::getMsgIdFromAtInfor(const QString&groupjid, const QString&userjid)
	{
		QStringList msgids;
		if (groupjid.isEmpty() || userjid.isEmpty())
		{
			return msgids;
		}
		if (mAtinformap.contains(groupjid))
		{
			for (QSharedPointer<AtInforItem> oneitem: mAtinformap.value(groupjid))
			{
				if(oneitem->mUserJid == userjid)
				{
					msgids = oneitem->mMsgId;
					break;
				}
			}
		}

		return msgids;
	}

	/*
	目的是：启动时，看到列表中的item是该会话中的最后一条消息，一定要是别人的消息
	1.离线消息加载完后，也需要是拉取到的离线消息中的最后一条
	2.右键删除该item及所有会话记录，然后再打开，创建这个item的时候，也需要最后一条聊天记录
	3.右键关闭该聊天框时，也需要最后一条聊天记录
	4.接收消息时，需要最后一条消息
	5.@all和@你时，永远展示的是@的消息，除非删掉@后
	6.只有3类会话中出现这种情况，单人，群组，系统消息，其他的会话item是不出现的
	*/
	void ConversationController::updateChatContent(const QString& jid, const QSharedPointer<Biz::XmppMessage>& spMsg)
	{
// 		if (spMsg.isNull())
// 		{
// 
// 		
// 		auto callback = createCallback<QSharedPointer<Biz::XmppMessage>>([this,jid](const QSharedPointer<Biz::XmppMessage>& spInfo){
// 			if (!spInfo.isNull())
// 			{
// 				
// 				paramMsgToItem(jid, spInfo);
// 				
// 			}
// 		},[]{});
// 		Biz::Session::getConverSationManager()->getRecentChatMessage(jid,callback);
// 		}
// 		else
		if (!spMsg.isNull())
		{
			paramMsgToItem(jid, spMsg);
		}
	}

	void ConversationController::paramMsgToItem(const QString&jid,const QSharedPointer<Biz::XmppMessage>& spInfo)
	{
		RecentExtendedSessionListView* pExtendView = getExtendedSessionViewByConversationId(jid);
		if (NULL!=pExtendView)
		{
			QString displayName;
			QString sendContent;
			if (jid.contains("@conference."))
			{
				QString senderid = spInfo->Realfrom();
				if (!senderid.isEmpty() )
				{
					if (senderid == Biz::MessageUtil::makeSureUserJid(Biz::Session::getAccountManager()->accountData().UserID()))
					{
						displayName = QStringLiteral("我") + QStringLiteral("：");
					}
					else
					{
						QString strdisp = Biz::Session::getUserVcardManager()->getUserNameByConversationId(senderid);
						if (strdisp.isEmpty())
						{
							strdisp = Biz::MessageUtil::makeSureUserId(senderid);
						}
						displayName += strdisp + QStringLiteral("：");
					}
				}
			}

			
			QString shortBody;
			if (spInfo->MsgSourceType() == Biz::encrypt)
			{
				if (spInfo->MediaType() == Biz::EncryptMessageType_Begin)
				{
					shortBody = QStringLiteral("[开始加密会话]");
				}
				else if (spInfo->MediaType() == Biz::EncryptMessageType_Agree)
				{
					shortBody = QStringLiteral("[同意加密会话]");
				}
				else if (spInfo->MediaType() == Biz::EncryptMessageType_Refuse)
				{
					shortBody = QStringLiteral("[拒绝加密会话]");
				}
				else if (spInfo->MediaType() == Biz::EncryptMessageType_Cancel)
				{
					shortBody = QStringLiteral("[取消加密会话]");
				}
				else if (spInfo->MediaType() == Biz::EncryptMessageType_Close)
				{
					shortBody = QStringLiteral("[关闭加密会话]");
				}
			}
			else  if (spInfo->MediaType() == Biz::MediaTypeCodeHLight)
			{
				shortBody = QStringLiteral("[代码]");
			}
			else if (spInfo->MediaType() == Biz::MessageTypeMarkdown)
			{
				shortBody = QStringLiteral("[markdown]");
			}
			else if (spInfo->MediaType() == Biz::MediaTypeEncrypt)
			{
				shortBody = QStringLiteral("[加密消息]");
			}
			else if (spInfo->MediaType() == Biz::MediaTypeImageNew)
			{
				shortBody = QStringLiteral("[表情]");
			}
			else if (spInfo->MediaType() == Biz::MediaTypeRedPakage)
			{
				shortBody = QStringLiteral("[红包消息]");
			}
			else if (spInfo->MediaType() == Biz::MediaTypeRedPackageNormal)
			{
				shortBody = QStringLiteral("[红包]");
			}
			else
			{
				if (!MessageParser::getInstance()->getShotTranslatedMessage(spInfo,shortBody))
				{

				}
			}
			//顾虑提示符号
			shortBody.replace("<br/>"," ");
			shortBody.replace("<br />"," ");
			shortBody.replace("&nbsp;"," ");
			shortBody.replace("\n", " ");

			displayName += shortBody;
			pExtendView->getRosterListView()->updateChatContent(jid,displayName);
		}
	}
}
