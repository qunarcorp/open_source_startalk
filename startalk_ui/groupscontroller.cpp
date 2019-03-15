#include "groupscontroller.h"
#include "Session.h"
#include "SystemConfigData.h"
#include "accountmanager.h"
#include "AccountData.h"
#include "UserVcardManager.h"
#include "GroupManager.h"
#include "UIFrame.h"
#include "NotifyCenterController.h"

#include "Session.h"
#include "GroupManager.h"
#include "accountmanager.h"
#include "UserVcardManager.h"

#include "UIFrame.h"
#include "ConversationController.h"

#include "GroupListView.h"
#include "XmppMessage.h"

#include "portraithelper.h"
#include "GroupListData.h"

#include "conversationmanager.h"
#include "CustomDefine.h"


namespace MainApp
{

    int GroupsController::sMemberMaxCount = 600;
    int GroupsController::sMemberWarningCount = 200;

	GroupsController::GroupsController(QObject *parent)
        : ControllerBase(parent)
	{
	}
    GroupsController::GroupsController()
        : ControllerBase(NULL)
    {
    }
	
	GroupsController::~GroupsController()
	{
	
	}
	

    void GroupsController::initController()
    {
        // 群组列表初始化
        /*
        *	群组列表初始化
        *      1 启动时获取群列表初始化   Biz::GroupManager::sgRoomListReceived
        *      2 运行时动态添加群组       Biz::GroupManager::sgGroupJoidSuccess
        *      3 群组被销毁，也可能是其他客户端销毁然后同步过来
        *      4 群组被退出，类似于销毁
        *      5 群组名片变更了。及时更细。
        */
        connect(Biz::Session::getGroupManager(), &Biz::GroupManager::sgRoomListReceived,this, &GroupsController::onGroupListReceived);
        connect(Biz::Session::getGroupManager(), &Biz::GroupManager::sgGroupJoinedSuccess, this, &GroupsController::onGroupAdded);
        connect(Biz::Session::getGroupManager(), &Biz::GroupManager::sgGroupDestroyed,this, &GroupsController::onGroupDelItem);
        connect(Biz::Session::getGroupManager(), &Biz::GroupManager::sgGroupLeavedReceived, this, &GroupsController::onGroupDelItem);
        connect(Biz::Session::getGroupManager (),&Biz::GroupManager::sgGroupVcardUpdated,this, &GroupsController::onRoomListNameReceived);
	
    }

    void GroupsController::unInitController()
    {

    }

	
	
	bool GroupsController::checkNewLimitedCount(int countToInvited)
	{
	    if (Biz::Session::getSystemConfig()->UpdateLimited())
	    {
            // 2016年9月9日 给用服版本的最大上线ren's人数变成70人
	        sMemberMaxCount = 70;
	    }
	
	    if (countToInvited>sMemberMaxCount)
	    {
	        QString message =  QString(QStringLiteral("群组人数共%1人，超出了群组安全上限%2人，请联系IT创建").arg(countToInvited).arg(sMemberMaxCount));
	        
            MainApp::UIFrame::getNotifyCenterController ()->alertMessage (message);

	        return false;
	    } 
		//这提示暂时不要
// 		else if (countToInvited>sMemberWarningCount)
// 		{
// 			QString message =  QString(QStringLiteral("群组人数共%1人，超出建议值200人，是否继续?").arg(countToInvited));
// 
// 			if (!MainApp::UIFrame::getNotifyCenterController ()->alertMessageWithCancle(message))
// 				return false;
// 		}
	    return true;
	}

    void GroupsController::createNewGroup(QStringList members,Biz::UnitCallback<QString>* callback)
    {
        QString strSelfId = Biz::Session::getAccountManager()->accountData().UserID();
        members.removeOne(strSelfId);
        members.insert(0,strSelfId);
        
        if (!checkNewLimitedCount(members.size()))
            return;
            
        QStringList memberNames;
        for (QString userid:members)
        {
            QString strName = Biz::Session::getUserVcardManager()->getUserNameByConversationId(userid);
            QString strAbsName = Biz::MessageUtil::makeSureUserId(strName);
            memberNames.append(strAbsName);
            memberNames = memberNames.toSet().toList();
            if (memberNames.size()>2)
                break;
        }

        QString groupname = memberNames.join(",");
        if (memberNames.size() >= 3)
            groupname += "...";
        
     
        Biz::Session::getGroupManager()->createGroup(groupname,members,callback);
    }

    void GroupsController::inviteMembers(const QString& groupjid,QStringList members,Biz::UnitCallback<QStringList>*callback)
    {
        if (!checkNewLimitedCount(members.size()))
            return;
        Biz::Session::getGroupManager()->inviteGroupMembers(groupjid,members,callback);
    }



    void GroupsController::registerGroupListView(GroupListView* listview)
    {
        m_pGroupListView = listview;

        connect(m_pGroupListView, &GroupListView::sgItemDoubleClicked,this,&GroupsController::onOpenNewGroupSession);
        connect (m_pGroupListView, &GroupListView::sgItemClicked,[this](const QString& jid){
            MainApp::UIFrame::getConversationController ()->showGroupDetailInfoPage (jid);
			
        });

        connect(Biz::Session::getUserVcardManager(),&Biz::UserVcardManager::sgGroupHeaderUpdate,[this](const QString& jid){
            if (NULL!=m_pGroupListView)
            {
                m_pGroupListView->setItemImage (jid,Biz::PortraitHelper::getGroupPortraitWithNoticeFlag(jid).toImage());
            }
        });

		connect(Biz::Session::getConverSationManager(),&Biz::ConverSationManager::sgNoticeTipConversationChanged,[this](const QList<Biz::ImSession>& changedSession){
			
			for(Biz::ImSession session:changedSession)
				m_pGroupListView->setGroupNoticeTip(session.xmppid, (session.configration&Biz::SESSION_CFG_SILENCE)!=Biz::SESSION_CFG_SILENCE);
		});
		connect(Biz::Session::getGroupManager(), &Biz::GroupManager::sgRecentChattingGroup, [this](const QList<Biz::ImSession>& sessionlist ){
			for (Biz::ImSession onesession: sessionlist)
			{
					m_groupjidconfigmap.insert(onesession.xmppid, onesession.configration);
			}
		});


    }


    void GroupsController::onGroupListReceived(const QStringList& roomlist)
    {
        if (NULL!=m_pGroupListView)
        {
            Log::e(QString(" GroupListView::onGroupListReceived "+roomlist.size()));
            for (QString groupId : roomlist)
            {
                m_pGroupListView->insertItem (groupId,Biz::MessageUtil::makeSureUserId (groupId));
                m_pGroupListView->setItemImage (groupId,Biz::PortraitHelper::getGroupPortraitWithNoticeFlag(groupId).toImage());

                Biz::GroupListData* gld  = Biz::Session::getAccountManager ()->getGroupsData ();
                if (NULL == gld)
                    return;
                Biz::GroupSetting* setting = gld->getGroupSetting(groupId);
                if (NULL != setting && !setting->Name ().isEmpty())
				{
                    m_pGroupListView->setItemName (groupId,setting->Name ());
					//把消息提示给加上
					int noticetip = 0;
					if (m_groupjidconfigmap.contains(groupId))
					{
						noticetip = m_groupjidconfigmap.value(groupId);
					}
					m_pGroupListView->setGroupNoticeTip(groupId, noticetip);
				}
            }
        }
    }
    void GroupsController::onRoomListNameReceived(const QStringList& groupjids)
    {
        Biz::GroupListData* gld  = Biz::Session::getAccountManager ()->getGroupsData ();
        if (NULL == gld)
            return;
        for(QString jid : groupjids)
        {
            Biz::GroupListData* gld  = Biz::Session::getAccountManager ()->getGroupsData ();
            if (NULL == gld)
                return;
            Biz::GroupSetting* setting = gld->getGroupSetting(jid);
            if (NULL != setting && !setting->Name ().isEmpty())
                m_pGroupListView->setItemName (jid,setting->Name ());
        }
    }
    void GroupsController::onGroupAdded(const QString& jid)
    {
        Log::e(QString(" GroupListView::onGroupAdded "+jid));
        m_pGroupListView->insertItem (jid,Biz::MessageUtil::makeSureUserId (jid));
        m_pGroupListView->setItemImage (jid,Biz::PortraitHelper::getGroupPortraitWithNoticeFlag(jid).toImage());

        Biz::GroupListData* gld  = Biz::Session::getAccountManager ()->getGroupsData ();
        if (NULL == gld)
            return;
        Biz::GroupSetting* setting = gld->getGroupSetting(jid);
        if (NULL != setting && !setting->Name ().isEmpty())
            m_pGroupListView->setItemName (jid,setting->Name ());
    }

    void GroupsController::onGroupDelItem(const QString&jid)
    {
        m_pGroupListView->deleteItem (jid);
    }

    void GroupsController::onOpenNewGroupSession(const QString& groupJid)
    {
        //发送信号，展示最近会话列表
        MainApp::UIFrame::getConversationController()->createNewGroupChatDialog(groupJid);
        MainApp::UIFrame::getConversationController()->addGroupChatRosterItem(groupJid,MainApp::ConversationController::sDefaultExtendPanel);
        MainApp::UIFrame::getConversationController()->activeConversation(groupJid);
        MainApp::UIFrame::getConversationController()->moveSessionToTop(groupJid);
    }



}
