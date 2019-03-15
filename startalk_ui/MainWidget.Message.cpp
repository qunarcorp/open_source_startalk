#include "MainWidget.h"
#include "ui_MainWidget.h"
#include "LanguageHelper.h"
#include <QPushButton>
#include <QGraphicsDropShadowEffect>
#include <QDesktopServices>
#include <QMenu>
#include <QKeyEvent>
#include <QInputDialog>
#include <QXmppUtils.h>
#include "RosterListWidget.h"
#include "GroupListView.h"
#include "rostertreeview.h"
#include "ChatDialog.h"
#include "BaseChatDialog.h"
#include "GroupChatDialog.h"
#include "Framework.h"
#include "AddGroupDialog.h"

#include "../LocalManBiz/Account.h"
#include "../LocalManBiz/Session.h"
#include "../LocalManBiz/AccountData.h"
#include "../LocalManBiz/ConfigureHelper.h"
#include "../LocalManBiz/XmppMessage.h"
#include "../LocalManBiz/RosterList.h"
#include "../LocalManBiz/RosterProfile.h"
#include "../LocalManUtils/SystemDefine.h"
#include "../LocalManBiz/CallbackReceiver.h"
#include "../LocalManBiz/SettingData.h"
#include "../LocalManBiz/XmppMessage.h"

#include "NotifyWindow.h"
#include "SettingTabView.h"
#include "SettingDetail.h"
#include "StatusButton.h"
#include "UiHelper.h"
#include "define.h"


#include "QApplication"
#include <QLineEdit>
#include "logindialog.h"
#include "Session.h"
#include "SystemConfigData.h"
#include "QFileDialog"
#include "AboutDialog.h"
#include "Updateinfordialog.h"
#include "ProgressDialog.h"
#include "RosterList.h"
#include "passwordinput.h"
#include "MainDialog.h"
#include "sysmessagedialog.h"
#include "../QXmpp/custom/QXmppMucRoomMemberIq.h"
#include "SystemIcon.h"
#include "RosterList.h"
#include "createnewgroup.h"

#include "diywidgit/printscreen/SnipScreenTool.h"
#include "MessageListData.h"
#include "GroupListData.h"
#include "SettingDetail.h"
#include "portraithelper.h"

#include "newsdialog.h"

#include "userminiprofile.h"
#include "conversationlistwidget.h"
#include "presencechangewidget.h"
#include "QXmppPresence.h"

#include "MainDialog.h"
#ifdef QCHAT
#include "Personinfordialog.h"
#include "Ordermanagedialog.h"
#endif // QCHAT

#include "JoinGroupFailedDialog.h"
#include "trayiconhovernoticewidget.h"

#include "gloableeventobject.h"

#ifdef _WINDOWS_
#include <WinUser.h>
#endif

#include "slidingstackedwidget.h"
#include "SystemDefine.h"

#include "CustomDefine.h"
#include "Personinfor_employdialog.h"

#include "StaticData.h"

#include "UserVcardManager.h"
#include "FriendsExtendPanel.h"
#include "friendsmanager.h"
#include "MenuRobotDialog.h"
#include "RobotManager.h"
#include "addfriendanswer.h"
#include "accountmanager.h"
#include "GroupManager.h"
#include "conversationmanager.h"
#include "virtualaccountmanager.h"
#include "advertinfodialog.h"
#include "RobotSearchView.h"

#include "ConversationController.h"
#include "MainDialogController.h"
#include "virtualaccountcontroller.h"
#include "UIFrame.h"
#include "advinformanager.h"
#include "jsonobject/noteinfo.h"
#include "dataapplication.h"
#include "constants.h"

#include "Ordermanagedialog.h"
#include "vidioandaudiodialog.h"
#include "UIFrame.h"
#include "NotifyCenterController.h"
#include "Account.h"
#include "jsonobject/encryptinfo.h"
#include "encryptchatcontroller.h"
#include "qcloudmanager.h"


void MainWidget::onWeiDaoYouMessageReceived(const QSharedPointer<Biz::XmppMessage>& msg)
{
	if (msg.isNull())
		return;
	if (msg->ConversationID().isEmpty())
	{
		Log::e("robotmsg peerid empty " + msg->MessageID());
		return;
	}
	// 创建会话窗口
	QString newsJid = msg->ConversationID();
	QString displayName = Biz::Session::currentAccount().getUserNameById(newsJid);
	if(MainApp::UIFrame::getConversationController()->hasConversation(newsJid))
	{
		QList<int> unNoticeMsgType;
		unNoticeMsgType << Biz::MediaTypeShockAndPostBackCookie;
		unNoticeMsgType << Biz::MediaTypeClientCookie;
		unNoticeMsgType << Biz::MediaTypeRobotNotice;

		messageNotify(newsJid,displayName,msg);
		// 保存最近回话
		Biz::Session::getConverSationManager()->saveConversationInfo(msg,NULL);
	}else{
		MainApp::UIFrame::getConversationController()->addRawHtmlItem(newsJid,MainApp::ConversationController::sDefaultExtendPanel);
		this->onWeiDaoYouMessageReceived(msg);
	}
}

void MainWidget::onRobotReceived(const QSharedPointer<Biz::XmppMessage>& msg)
{
	if (msg.isNull())
		return;
	if (msg->ConversationID().isEmpty())
	{
		Log::e("robotmsg peerid empty " + msg->MessageID());
		return;
	}
	// 创建会话窗口
	QString newsJid = msg->ConversationID();
	QString displayName = Biz::Session::currentAccount().getUserNameById(newsJid);
	if(MainApp::UIFrame::getConversationController()->hasConversation(newsJid))
	{
		QList<int> unNoticeMsgType;
		unNoticeMsgType << Biz::MediaTypeShockAndPostBackCookie;
		unNoticeMsgType << Biz::MediaTypeClientCookie;
		unNoticeMsgType << Biz::MediaTypeRobotNotice;

		if (!unNoticeMsgType.contains(msg->MediaType()))
		{
			messageNotify(newsJid,displayName,msg);
			// 保存最近回话
			Biz::Session::getConverSationManager()->saveConversationInfo(msg,NULL);
		}
		else
		{
			// 消息路由       
			BaseChatDialog* pDialog = MainApp::UIFrame::getConversationController()->findConversationBaseChatDialog(newsJid);
			if (NULL!=pDialog)
				pDialog->onMessageReceived(msg);

			QStringList ids;
			ids <<msg->MessageID();
			Biz::Session::getConverSationManager()->setConversationMessageRead(newsJid);
		}
	}else{
		MainApp::UIFrame::getConversationController()->addRobotChatRosterItem(newsJid,MainApp::ConversationController::sDefaultExtendPanel);
		this->onRobotReceived(msg);
	}

}



void MainWidget::onGroupMessageReceived( const QSharedPointer<Biz::XmppMessage>& msg )
{
	if (msg.isNull())
	{
		Log::e("group message droped,by is null");
		return ;
	}

	// 预下载音频文件
	if (msg->MediaType() == Biz::MediaTypeVoice)
		Biz::Session::currentAccount().downLoadVoiceAttachment(msg);

	QString groupJid = Biz::MessageUtil::makeSureGroupJid(msg->ConversationID());
	//QString displayName = Biz::Session::getGroupManager()->getGroupNickName(groupJid);
	QString displayName = Biz::Session::getGroupManager()->getGroupLocalNickNamebyId(groupJid);
	MainApp::UIFrame::getConversationController()->updateJidLastTimeStamp(groupJid,msg->UtcTime());


	Biz::GroupListData *gld = Biz::Session::currentAccount().getGroupsData();
	if (NULL != gld)
	{
		Biz::GroupSetting* pgs = gld->getGroupSetting(groupJid);
		int noption = pgs->GroupMsgNoticeOption();

		if (NULL!=pgs &&Biz::GroupSetting::RECV_WITHOUT_NOTICE == pgs->GroupMsgNoticeOption() )
		{
			showAtNotice(groupJid, msg);
			MainApp::UIFrame::getConversationController()->updateChatContent(groupJid, msg);
			// 有窗口就传给他，没有就算了，也不提示，入库了，默默走人       
			//Biz::Session::getConverSationManager()->setGroupConversationMessageRead(groupJid);

			BaseChatDialog* pDialog  = MainApp::UIFrame::getConversationController()->findConversationBaseChatDialog(groupJid);
			if (NULL!=pDialog)
			{
				pDialog->onMessageReceived(msg);
			}
			Log::e("group message droped,by is without noticy"+msg->MessageID());

			// 更新未读
			if (!MainApp::UIFrame::getConversationController()->isTopChatDialog(groupJid))
			{
				if (msg->MsgDirection() == Biz::MessageDirection::MessageTypeOther)
				{
					QMap<QString,quint64> params;
					params.insert(groupJid,0);
					Biz::Session::getConverSationManager()->updateReadMarkByLastTime(params);
				}
			}
			else//如果是顶层窗口，则里面发送已阅读的message到server
			{
				// //如果这个里有未读的消息就发送readmark
				// 认定 别人发来的消息，自己又是在线状态，程序有激活窗口时，将此会话置为已读 + 顶层窗口
				// 认定 自己发的消息（本端和其他平台），该消息应该置为已读
				if (Biz::MessageDirection::MessageTypeOther == msg->MsgDirection())
				{
					if ( dataApp->value (Constant::CACHE_KEY_CURRENTPRESENCE).toInt () ==QXmppPresence::Online
						&& NULL!=QApplication::activeWindow() )
					{
						MainApp::UIFrame::getConversationController()->clearConversationAllRead(groupJid);
					}
					else
					{
						QMap<QString,quint64> params;
						params.insert(groupJid,0);
						Biz::Session::getConverSationManager()->updateReadMarkByLastTime(params);
					}
				}
				else
				{
					MainApp::UIFrame::getConversationController()->clearConversationAllRead(groupJid);
				}

			}

			return;
		}
	}

	if(MainApp::UIFrame::getConversationController()->hasConversation(groupJid))
	{
		mstrCurrentMsgOfOwerId = groupJid;
		Biz::Session::getConverSationManager()->saveConversationInfo(msg,NULL);  

		showAtNotice(groupJid, msg);

		// 消息提醒参数设定

		messageNotify(groupJid,displayName,msg);
		MainApp::UIFrame::getConversationController()->updateChatContent(groupJid, msg);
	}
	else
	{
		QString groupJid = Biz::MessageUtil::makeSureGroupJid(msg->ConversationID());
		QString displayName = Biz::Session::currentAccount().getGroupNickName(groupJid);
		if(displayName.isEmpty())
			displayName = Biz::MessageUtil::makeSureUserId(groupJid);
		MainApp::UIFrame::getConversationController()->addGroupChatRosterItem(groupJid,MainApp::ConversationController::sDefaultExtendPanel);
		onGroupMessageReceived(msg);
	}
}



void MainWidget::onTypingMessageReceived(const QSharedPointer<Biz::XmppMessage>& msg)
{
	if (msg.isNull())
		return ;
	QString strUserid = msg->ConversationID();
	ChatDialog* pDialog = dynamic_cast<ChatDialog*>(MainApp::UIFrame::getConversationController()->findConversationBaseChatDialog(strUserid));
	if (NULL!=pDialog)
	{
		pDialog->onTypingMessageReceived(msg);
	}


}

void MainWidget::onMessageReceived( const QSharedPointer<Biz::XmppMessage>& msg )
{
	onMessageReceivedInner(msg,false);
}


void MainWidget::onMessageReceivedInner( const QSharedPointer<Biz::XmppMessage>& msg,bool bsend )
{
	if (msg.isNull())
	{
		Log::e("simplechat message droped,by is null");
		return ;
	}
	m_cctext = msg->cctext();
	m_bu = msg->bu();
	// 预下载音频文件
	if (msg->MediaType() == Biz::MediaTypeVoice)
	{
		Biz::Session::currentAccount().downLoadVoiceAttachment(msg);
	}
	//视频
	if ( (msg->MediaType() == Biz::MediaTypeaudioReceiveRtc) && ((msg->MsgDirection() == Biz::MessageTypeOther)
		|| msg->MediaType() == Biz::MediaTypeVideoPingRespon ))
	{
#if (QT_VERSION < QT_VERSION_CHECK(5, 6, 0))
		MainApp::UIFrame::getNotifyCenterController()->alertMessage(QStringLiteral("qt库版本低，暂不支持视频"));
		return;
#endif
		VidioAndAudioDialog *dlg = MainApp::UIFrame::getConversationController()->getVidioChatById(msg->ConversationID());
		if (dlg)
		{
			dlg->setUrl(Biz::Session::getSystemConfig()->getVidioAndAudio_Host());
			dlg->onShowDlg(msg->ConversationID());

			QString strconversaionId = msg->ConversationID();
			connect(dlg, &VidioAndAudioDialog::sgLoadFinished, [this,strconversaionId, dlg](const QString& id){
				if (strconversaionId == id)
				{
					dlg->callVidioOrAudio(AudeoVidioType::VIDEOTYPE);
				}

			});
		}
		msg->Body(QStringLiteral("视频聊天"));
	}
	//音频
	if ( (msg->MediaType() == Biz::MediaTypeaudioReceiveRtcAudio) && (msg->MsgDirection() == Biz::MessageTypeOther)
		|| msg->MediaType() == Biz::MediaTypeAudeoPingRespon)
	{
#if (QT_VERSION < QT_VERSION_CHECK(5, 6, 0))

		MainApp::UIFrame::getNotifyCenterController()->alertMessage(QStringLiteral("qt库版本低，暂不支持音频"));
		return;
#endif
		VidioAndAudioDialog *dlg = MainApp::UIFrame::getConversationController()->getVidioChatById(msg->ConversationID());
		if (dlg)
		{
			dlg->setUrl(Biz::Session::getSystemConfig()->getVidioAndAudio_Host());
			dlg->onShowDlg(msg->ConversationID());

			QString strconversaionId = msg->ConversationID();
			connect(dlg, &VidioAndAudioDialog::sgLoadFinished, [this, strconversaionId, dlg](const QString& id){
				if (strconversaionId == id)
				{
					dlg->callVidioOrAudio(AudeoVidioType::AUDEOTYPE);
				}

			});

		}
		msg->Body(QStringLiteral("语音聊天"));
	}
	//端到端加密的一些操作
	doEncryptMessage(msg);
	if (msg->MsgSourceType() == Biz::collection)
	{
		doCollectionInfor(msg);
	}

	//抖动
	if (msg->MediaType() == Biz::MediaTypeShockAndPostBackCookie)
	{
		if (!MainApp::UIFrame::getMainDialogController()->isMainDialogVisible())
			MainApp::UIFrame::getMainDialogController()->actieMainDialog();

		if (Biz::Session::getSettingConfig()->AutoShake())
		{
			emit GloableEventObject::getInstance()->sgShake();
		}
	}

	QString strUserid = msg->ConversationID();
	Q_ASSERT(!strUserid.isEmpty());
	if (strUserid.isEmpty())
	{
		return;
	}

	if(MainApp::UIFrame::getConversationController()->hasConversation(strUserid))
	{
		QString conversationId = msg->ConversationID();
		mstrCurrentMsgOfOwerId = strUserid;
		Biz::Session::getConverSationManager()->saveConversationInfo(msg,NULL);



		QString dislplayName = Biz::Session::getUserVcardManager()->getUserNameByConversationId(conversationId);
		QString groupJid = Biz::MessageUtil::makeSureGroupJid(msg->ConversationID());
		Biz::GroupListData *gld = Biz::Session::currentAccount().getGroupsData();
		if (NULL != gld)
		{
			Biz::GroupSetting* pgs = gld->getGroupSetting(groupJid);
			int noption = pgs->GroupMsgNoticeOption();

			if (NULL!=pgs &&Biz::GroupSetting::RECV_WITHOUT_NOTICE == pgs->GroupMsgNoticeOption() )
			{
				showAtNotice(groupJid, msg);
				MainApp::UIFrame::getConversationController()->updateChatContent(groupJid, msg);
				// 有窗口就传给他，没有就算了，也不提示，入库了，默默走人       
				//Biz::Session::getConverSationManager()->setGroupConversationMessageRead(groupJid);

				BaseChatDialog* pDialog  = MainApp::UIFrame::getConversationController()->findConversationBaseChatDialog(groupJid);
				if (NULL!=pDialog)
				{
					pDialog->onMessageReceived(msg);
				}
				Log::e("group message droped,by is without noticy"+msg->MessageID());

				// 更新未读
				if (!MainApp::UIFrame::getConversationController()->isTopChatDialog(groupJid))
				{
					if (msg->MsgDirection() == Biz::MessageDirection::MessageTypeOther)
					{
						QMap<QString,quint64> params;
						params.insert(groupJid,0);
						Biz::Session::getConverSationManager()->updateReadMarkByLastTime(params);
					}
				}
				else//如果是顶层窗口，则里面发送已阅读的message到server
				{
					// //如果这个里有未读的消息就发送readmark
					// 认定 别人发来的消息，自己又是在线状态，程序有激活窗口时，将此会话置为已读 + 顶层窗口
					// 认定 自己发的消息（本端和其他平台），该消息应该置为已读
					if (Biz::MessageDirection::MessageTypeOther == msg->MsgDirection())
					{
						if ( dataApp->value (Constant::CACHE_KEY_CURRENTPRESENCE).toInt () ==QXmppPresence::Online
							&& NULL!=QApplication::activeWindow() )
						{
							MainApp::UIFrame::getConversationController()->clearConversationAllRead(groupJid);
						}
						else
						{
							QMap<QString,quint64> params;
							params.insert(groupJid,0);
							Biz::Session::getConverSationManager()->updateReadMarkByLastTime(params);
						}
					}
					else
					{
						MainApp::UIFrame::getConversationController()->clearConversationAllRead(groupJid);
					}

				}
				return;
			}
		}

		// 消息提醒
		messageNotify(conversationId,dislplayName,msg);

		MainApp::UIFrame::getConversationController()->updateChatContent(conversationId, msg);


		// 自动变成在线(如果是收到抄送的消息，也不给变成在线)
		if (Biz::MessageDirection::MessageTypeSelf == msg->MsgDirection()&& !msg->MsgCarbon() &&!bsend )
		{
			setPresence(QXmppPresence::Online);
#ifdef _WINDOWS_
			dataApp->put (Constant::CACHE_KEY_LASTONLINETIME,(quint64)::GetTickCount());
#endif
		}

		// 自动回复
#ifdef _WINDOWS_
		Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
#ifdef QCHAT

		if (dataApp->value(Constant::CACHE_KEY_CURRENTPRESENCE).toInt()!=QXmppPresence::Online 
			&& (settingconfig->Busystatus() || settingconfig->Awaystatus())
			&& Biz::MessageDirection::MessageTypeSelf != msg->MsgDirection() 
			&& !bsend 
			&& !msg->autoReply() && msg->MediaType() != Biz::MessageMediaType::MediaTypeTransShop)
		{
			autoReply(msg->ConversationID());
		}
#else
		if (dataApp->value(Constant::CACHE_KEY_CURRENTPRESENCE).toInt()!=QXmppPresence::Online 
			&& settingconfig->AutoReplyEnable() 
			&& Biz::MessageDirection::MessageTypeSelf != msg->MsgDirection() 
			&& !bsend 
			&& !msg->autoReply()&& msg->MsgSourceType() != Biz::collection)
		{
			autoReply(msg->ConversationID());
		}
#endif // QCHAT

#endif
	}
	else
	{
		QString conversationId = msg->ConversationID();
		if (Biz::consult == msg->MsgSourceType())
		{
			bool bIsSeat = false;
			QString realJid = "";
			if (Biz::MessageDirection::MessageTypeSelf == msg->MsgDirection())
			{
				bIsSeat = Biz::consultmsgType::OnDutyToVistor == msg->qchatid();
				realJid = msg->Realto();
			} else {
				bIsSeat = Biz::consultmsgType::VistorToOnDuty == msg->qchatid();
				realJid = msg->Realfrom();
			}
			MainApp::UIFrame::getConversationController()->addConsultChatRosterItem(conversationId,MainApp::ConversationController::sDefaultExtendPanel,msg->virtualId(),realJid,bIsSeat);
		} 
		else if (msg->MsgSourceType() != Biz::collection)
		{
			// 创建新的会话窗口,先有会话，additem的时候才能自动置顶
			MainApp::UIFrame::getConversationController()->addSimpleChatRosterItem(conversationId,MainApp::ConversationController::sDefaultExtendPanel);
		}
		else
		{
			MainApp::UIFrame::getConversationController()->addColloctionChatRosterItem(conversationId,MainApp::ConversationController::sDefaultExtendPanel);
		}

		this->onMessageReceived(msg);
	}
}

void MainWidget::onSystemMessageReceived( const QSharedPointer<Biz::XmppMessage>& msg )
{
	if (msg.isNull())
		return ;

	QString displayName = T_("SysMessageDlg_Title");
	QString newsJid = Biz::MessageUtil::makeSureUserJid(msg->ConversationID());//Util::NEWS_DIALOG_ID;

	if(MainApp::UIFrame::getConversationController()->hasConversation(newsJid))
	{
		Biz::Session::getConverSationManager()->saveConversationInfo(msg,NULL);
		// 消息提醒
		messageNotify(newsJid,displayName,msg);
		MainApp::UIFrame::getConversationController()->updateChatContent(newsJid, msg);
	}else{
		MainApp::UIFrame::getConversationController()->addNewsDialogRosterItem(newsJid,MainApp::ConversationController::sDefaultExtendPanel);
		this->onSystemMessageReceived(msg);
	}
}


// slots to note xmpp Biz::Account::sgWebChatMessageReceivedEx
void MainWidget::onWebChatMessageReceivedEx( const QSharedPointer<Biz::XmppMessage>& msg)
{
	if (msg.isNull())
	{
		Log::e("MainWidget::onWebChatMessageReceivedEx, msg body is null");
		return ;
	}
	QString strUserid = msg->ConversationID();
	Q_ASSERT(!strUserid.isEmpty() && strUserid.contains("@"));
	if (strUserid.isEmpty())
		return;

	QString body = msg->Body();
	Biz::NoteInfo noteInfo;
	noteInfo.unserializeFromString(body);

	if ("cheche" == noteInfo.bu())
	{
		Log::e("MainWidget::onWebChatMessageReceived cheche push emit sgOnSendWelcomeToWebMsg");

		Biz::Session::getConverSationManager()->SendWelcomeInfo(strUserid,QString::number(noteInfo.chatid()));
		ShowWebWindowsEx(strUserid, "", noteInfo.url(), msg);
	}
	else
	{
		auto cb = mReceiver->createCallback<quint64>([this, strUserid, msg](quint64 lstmsgtm)
		{
			QString body = msg->Body();
			Biz::NoteInfo noteInfo;
			noteInfo.unserializeFromString(body);
			//发欢迎语先屏蔽
			/* #pragma region send_welcome_message
			if (lstmsgtm > 0)
			{
			quint64 currentsend = QDateTime::currentMSecsSinceEpoch() - Biz::Session::currentAccount().getTimeOffsetFromServer();
			if ((currentsend - lstmsgtm) > (24 * 60 * 60 * 1000))
			{
			Log::e(QString(" MainWidget::ShowWebWindows emit sgOnSendWelcomeToWebMsg(%1)").arg(strUserid));
			Biz::Session::getConverSationManager()->SendWelcomeInfo(strUserid, QString::number(noteInfo.chatid()));
			}
			else
			{
			//提示一下标明在24小时之内有过聊天，不给发送欢迎信息
			Biz::Session::getConverSationManager()->SendSystemNotifyInfo(strUserid, QStringLiteral("24小时内,只给该客户发送一次欢迎语"));
			Log::e(QString("MainWidget::ShowWebWindows not emit sgOnSendWelcomeToWebMsg(%1) < 24h").arg(strUserid));
			}
			}
			else
			{
			Log::e("MainWidget::onWebChatMessageReceived push emit sgOnSendWelcomeToWebMsg");
			Biz::Session::getConverSationManager()->SendWelcomeInfo(strUserid, QString::number(noteInfo.chatid()));
			}
			#pragma endregion send_welcome_message*/

			// 消息路由
			ShowWebWindowsEx(strUserid, "", noteInfo.url(), msg);
		}, [this,  strUserid, msg]{
			QString body = msg->Body();
			Biz::NoteInfo noteInfo;
			noteInfo.unserializeFromString(body);
			// 消息路由
			ShowWebWindowsEx(strUserid, "", noteInfo.url(), msg);
		});

		Biz::Session::getAccountManager()->getNotelastmsgtm(strUserid, cb);
	}
}


void MainWidget::onRevokeMessageReceived(const QSharedPointer<Biz::XmppMessage>& msg)
{
	if (msg.isNull())
		return ;

	QString conversationId = msg->ConversationID();

	// 消息路由       
	BaseChatDialog* pDialog = MainApp::UIFrame::getConversationController()->findConversationBaseChatDialog(conversationId);
	if (NULL!=pDialog)
		pDialog->onMessageReceived(msg);


	MainApp::UIFrame::getConversationController()->updateChatContent(conversationId, msg);
}

void MainWidget::showAtNotice(const QString&groupJid, const QSharedPointer<Biz::XmppMessage>& msg)
{
	if (Biz::AtOne == Biz::MessageUtil::chargeIsAtNotice(msg))
	{
		MainApp::UIFrame::getConversationController()->increaseAtNotice(groupJid,1,Biz::AtOne, msg->MessageID());
		MainApp::UIFrame::getConversationController()->addAtInfor(groupJid, msg->SenderJid(), msg->MessageID());

	}

	if (Biz::AtAll == Biz::MessageUtil::chargeIsAtNotice(msg))
	{
		QString strdisplay = Biz::Session::currentAccount().getUserNameById(msg->SenderJid());
		MainApp::UIFrame::getConversationController()->increaseAtNotice(groupJid,1,Biz::AtAll,msg->MessageID());
		MainApp::UIFrame::getConversationController()->addAtInfor(groupJid, msg->SenderJid(), msg->MessageID());

	}
}




void MainWidget::autoReply(const QString& peerid)
{
	QSharedPointer<Biz::XmppMessage> message(new Biz::XmppMessage(peerid));
	Biz::AllUserSettingData* pSettingData = Biz::Session::getSettingConfig();
#ifdef QCHAT
	//如果当前状态是离开
	QString text;
	if (dataApp->value(Constant::CACHE_KEY_CURRENTPRESENCE).toInt()==QXmppPresence::Away && pSettingData->Awaystatus())
	{

		text = QString(QStringLiteral("[自动回复]:%1")).arg(pSettingData->AwayMsg());
	}
	else if (dataApp->value(Constant::CACHE_KEY_CURRENTPRESENCE).toInt()==QXmppPresence::busy && pSettingData->Busystatus())
	{
		text = QString(QStringLiteral("[自动回复]:%1")).arg(pSettingData->BusyMsg());
	}
	else
	{
		return;
	}
#else
	QString text = QString(QStringLiteral("[自动回复]:%1")).arg( 
		pSettingData->AutoReplyMessageOption()?
		pSettingData->AutoReplySystemMessage():
		pSettingData->AutoReplyUserMessage());
#endif // QCHAT



	message->Body(text);
	message->UtcTime(QDateTime::currentDateTime().toMSecsSinceEpoch()-Biz::Session::currentAccount().getTimeOffsetFromServer());
	message->MsgDirection(Biz::MessageTypeSelf);

	message->autoReply(true);
	message->cctext(m_cctext);
	message->bu(m_bu);

	//直接判断peerid的值
	if (Util::UtilHelper::isVirtualAccountId(peerid, Biz::Session::getSystemConfig()->getXmppDomain()))
	{
		return;
		message->MsgSourceType(Biz::consult);

		QString realtoId = Util::UtilHelper::getRealIdfromID(peerid);
		QString virtualId = UtilHelper::getvirtualfromID(peerid);
		message->Realto(realtoId);
		message->Realfrom(Biz::Session::currentAccount().accountData().UserID());
		message->ConversationID(virtualId);
		message->from(Biz::Session::currentAccount().accountData().UserID());
		message->qchatid(Biz::consultmsgType::OnDutyToVistor);

	}
	else
	{
		message->MsgSourceType(Biz::ChatMessage);
	}

	auto callback = mReceiver->createCallback([this, message,peerid]()
	{
		if(message->ConversationID() != peerid ){
			return;
		}

		onMessageReceivedInner(message,true);

	}, []{});
	Biz::Session::currentAccount().doSendMessage(message, callback,NULL);

	//     auto sendmsgfun = [this,message,peerid]{
	//         auto callback = mReceiver->createCallback([this, message,peerid]()
	//         {
	//             if(message->ConversationID() != peerid ){
	//                 return;
	//             }
	// 
	//             onMessageReceivedInner(message,true);
	// 
	//         }, []{});
	//         Biz::Session::currentAccount().doSendMessage(message, callback,NULL);
	//     };





	//判断是否虚拟账号
	/* if (MainApp::UIFrame::getVirtualAccountController()->IsVirtualAccount(Biz::MessageUtil::makeSureUserId(peerid)))
	{
	QString strRealId = MainApp::UIFrame::getVirtualAccountController()->getRealAccount(Biz::MessageUtil::makeSureUserId(peerid));
	if (strRealId.isEmpty())
	{
	auto callback = mReceiver->createCallback<QString>([this,message,sendmsgfun](QString realname)
	{
	if (realname.isEmpty())
	{
	realname = message->ConversationID();
	}
	QSharedPointer<Biz::XmppMessage> msg = message;
	message->Realto(realname);
	message->Realfrom(Biz::Session::currentAccount().accountData().UserID());
	message->MsgSourceType(Biz::consult);

	sendmsgfun();

	}, []{});
	Biz::Session::getVirtualManager()->getRealAccountbyVirtualAccount(Biz::MessageUtil::makeSureUserId(peerid), callback);
	}
	else
	{
	message->Chatid(Biz::consultmsgType::VistorToOnDuty);
	message->Realto(strRealId);
	message->Realfrom(Biz::Session::currentAccount().accountData().UserID());
	message->MsgSourceType(Biz::consult);
	}
	}
	//判断是否是虚拟账号来发的消息的真实账号
	else if (!MainApp::UIFrame::getConversationController()->getvraccountbychating(peerid).isEmpty())
	{
	QString str = Util::UtilHelper::getRealIdfromID(message->ConversationID());
	QString strRealto = !str.isEmpty()?str:message->ConversationID();
	QString strTo = MainApp::UIFrame::getConversationController()->getvraccountbychating(peerid);
	//qtalk和qchat的区别在于，qtalk中聊天框是虚拟账号，
	//qchat中聊天框是真实存在的人
	message->ConversationID(strTo);
	message->from(Biz::MessageUtil::makeSureUserJid(Biz::Session::currentAccount().accountData().UserID()) );
	message->virtualId(strTo);
	message->Realto(strRealto);
	message->Realfrom(Biz::MessageUtil::makeSureUserJid(Biz::Session::currentAccount().accountData().UserID()));
	message->Chatid(Biz::consultmsgType::OnDutyToVistor);
	message->MsgSourceType(Biz::consult);
	}
	else 
	{

	}

	sendmsgfun();*/
}



/*!
* 功能 : 完成消息提醒，会话排序（更新时间戳）,消息路由，更新阅读指针
*/
void MainWidget::messageNotify(const QString& peerid,const QString& displayname,const QSharedPointer<Biz::XmppMessage>& msg)
{
	Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();




	// 界面没有焦点 托盘闪动，无论哪种消息，都会闪动托盘
	if (NULL==QApplication::activeWindow() || &NotifyWindow::instance()==QApplication::activeWindow())
	{
		// 弹出消息提醒窗口  
		if (settingconfig->IsShowMessageNotice())
			NotifyWindow::showNotifyMessage(peerid,displayname,msg);



		// 任务栏闪动
		MainApp::UIFrame::getMainDialogController()->taskTabFlush(true);

		// 自动弹出会话窗口,只有在会话窗口被关闭的时候生效
		if (settingconfig->IsAutoShowMainDialog()
			&& !MainApp::UIFrame::getMainDialogController()->isMainDialogVisible())
		{
			MainApp::UIFrame::getMainDialogController()->actieMainDialog();
			MainApp::UIFrame::getConversationController()->activeConversation(peerid);
		}

		MainApp::UIFrame::getMainDialogController()->setMainDialogTitle(displayname);

		if (msg->MsgDirection() == Biz::MessageDirection::MessageTypeOther)
		{
			SystemIcon::instance().flashTrayIcon();
			TrayIconHoverNoticeWidgetSingleton::getInstance()->addUnreadMessage(msg);
		}
	}

	QString conversationId = peerid;

	// 更新时间戳
	MainApp::UIFrame::getConversationController()->updateJidLastTimeStamp(conversationId,msg->UtcTime());

	// 消息路由       
	BaseChatDialog* pDialog = MainApp::UIFrame::getConversationController()->findConversationBaseChatDialog(conversationId);
	if (NULL!=pDialog)
		pDialog->onMessageReceived(msg);

	// 更新未读
	if (!MainApp::UIFrame::getConversationController()->isTopChatDialog(conversationId))
	{
		if (msg->MsgDirection() == Biz::MessageDirection::MessageTypeOther)
		{
			QMap<QString,quint64> params;
			params.insert(peerid,0);
			Biz::Session::getConverSationManager()->updateReadMarkByLastTime(params);
		}
	}
	else//如果是顶层窗口，则里面发送已阅读的message到server
	{
		// //如果这个里有未读的消息就发送readmark
		// 认定 别人发来的消息，自己又是在线状态，程序有激活窗口时，将此会话置为已读 + 顶层窗口
		// 认定 自己发的消息（本端和其他平台），该消息应该置为已读
		if (Biz::MessageDirection::MessageTypeOther == msg->MsgDirection())
		{
			if ( dataApp->value(Constant::CACHE_KEY_CURRENTPRESENCE).toInt () == QXmppPresence::Online
				&& NULL!=QApplication::activeWindow() )
			{
				MainApp::UIFrame::getConversationController()->clearConversationAllRead(conversationId);
			}
			else
			{
				QMap<QString,quint64> params;
				params.insert(peerid,0);
				Biz::Session::getConverSationManager()->updateReadMarkByLastTime(params);
			}
		}
		else
		{
			MainApp::UIFrame::getConversationController()->clearConversationAllRead(conversationId);
		}

	}
}


/*!
* 功能 :note xiaoxi
*/
void MainWidget::ShowWebWindowsEx( const QString&userid, const QString&display, const QString&url, const QSharedPointer<Biz::XmppMessage>& msg )
{
	if (msg.isNull())
	{
		Log::e("ShowWebWindowsEx message droped,by is null");
		return ;
	}


	QString strUserid = msg->ConversationID();
	Q_ASSERT(!strUserid.isEmpty());
	if (strUserid.isEmpty())
	{
		return;
	}

	if(MainApp::UIFrame::getConversationController()->hasConversation(strUserid))
	{
		mstrCurrentMsgOfOwerId = strUserid;
		bool bsend = false; // unkonws param

		QString conversationId = msg->ConversationID();
		QString dislplayName = Biz::Session::getUserVcardManager()->getUserNameByConversationId(conversationId);

		// 消息提醒
		messageNotify(conversationId,dislplayName,msg);
		MainApp::UIFrame::getConversationController()->updateChatContent(conversationId, msg);

		// 自动变成在线
		if (Biz::MessageDirection::MessageTypeSelf == msg->MsgDirection()&&!bsend )
		{
			setPresence(QXmppPresence::Online);
#ifdef _WINDOWS_
			dataApp->put (Constant::CACHE_KEY_LASTONLINETIME,(quint64)::GetTickCount());
#endif
		}

		//存放Im_sessinlist中
		msg->MsgSourceType(Biz::ChatMessage);
		Biz::Session::getConverSationManager()->saveConversationInfo(msg,NULL);
	}
	else
	{
		QString conversationId = msg->ConversationID();
		// 创建新的会话窗口,先有会话，additem的时候才能自动置顶
		MainApp::UIFrame::getConversationController()->addSimpleChatRosterItem(conversationId,MainApp::ConversationController::sDefaultExtendPanel);
		this->ShowWebWindowsEx(userid,display,url,msg);
	}
}

void MainWidget::doEncryptMessage(const QSharedPointer<Biz::XmppMessage>& msg)
{
	if (msg.isNull())
	{
		Log::e("doEncryptMessage message droped,by is null");
		return ;
	}


	QString strUserid = msg->ConversationID();
	Q_ASSERT(!strUserid.isEmpty());
	if (strUserid.isEmpty())
	{
		return;
	}

	if (msg->MsgSourceType() == Biz::MessageSourceType::encrypt)
	{

		//创建该聊天框，否则后面的很多
		QString conversationId = Biz::MessageUtil::makeSureUserJid(strUserid);
		// 创建新的会话窗口,先有会话，additem的时候才能自动置顶
		UIFrame::getConversationController()->createNewChatDialog(conversationId);
		UIFrame::getConversationController()->addSimpleChatRosterItem(conversationId,MainApp::ConversationController::sDefaultExtendPanel);
		UIFrame::getConversationController()->activeConversation(conversationId);
		UIFrame::getConversationController()->moveSessionToTop(strUserid);

		if (msg->MediaType() == Biz::EncryptMessageType::EncryptMessageType_Begin)
		{
			QString strdisplayname = Biz::Session::getUserVcardManager()->getUserNameByConversationId(strUserid);
			if (strdisplayname.isEmpty())
			{
				strdisplayname = strUserid;
			}
			QString strinfor = QStringLiteral("是否接受[%1]加密会话？").arg(strdisplayname);
			if (MainApp::UIFrame::getNotifyCenterController()->alertMessage ("",strinfor,QStringLiteral("拒绝"),QStringLiteral("接受")))
			{
				//解析出里面的内容，把key 放到
				QString strbody = msg->Body();
				Biz::BeginEncryptInfo begininfo(NULL);
				begininfo.unserializeFromString(strbody);

				int type = begininfo.type();
				QString pwdOther = begininfo.pwd();
				//如果同意了，给对方发一个同意的message
				Biz::Session::getConverSationManager()->SendEncryptMessage(strUserid, QStringLiteral("同意"), Biz::EncryptMessageType::EncryptMessageType_Agree);

				//紧接着把对方的密码存放在服务器和本地库里面
				auto callbacksuccess = [this,strUserid, pwdOther](const QString& strMainKey){

					QJsonDocument Json_Data = QJsonDocument::fromJson(strMainKey.toUtf8());

					QVariantMap dataMap = Json_Data.toVariant().toMap();
					bool ret = dataMap["ret"].toBool();
					QString MainKey = dataMap["key"].toString();

					if (ret)
					{
						if(MainKey.isEmpty())
						{
							//提示进行输入主密码，然后内存中保存主密码
							PasswordInput *pwd = PasswordInput::getInstance();
							if (pwd)
							{
								if (pwd->exec() == QDialog::Accepted)
								{
									//去本地去验证
									QString strPwd = pwd->getPassword();
									if (!strPwd.isEmpty())
									{
										MainApp::UIFrame::getConversationController()->setMainKey(strPwd);
									}
									auto checkcallbacksuccess = [this,pwdOther,strUserid](const QString& mainKey){

										QJsonParseError Json_Parse_Error;
										QJsonDocument Json_Data = QJsonDocument::fromJson(mainKey.toUtf8(),&Json_Parse_Error);
										if(Json_Parse_Error.error == QJsonParseError::NoError)
										{
											QVariantMap dataMap = Json_Data.toVariant().toMap();

											bool ret = dataMap["ret"].toBool();
											if (ret)
											{

												MainApp::UIFrame::getEncryptChatcontroller()->doGetSubKey(dataMap["Key"].toString(),pwdOther,strUserid );
											}
											else
											{
												MainApp::UIFrame::getEncryptChatcontroller()->doCreateMainKey(pwdOther, strUserid);
											}
										}

										//告诉聊天框，可以进行加密会话了，收到消息后，需要进行解密
										MainApp::UIFrame::getConversationController()->addEncrypt(strUserid, pwdOther);

									};
									auto checkcallbackfail = []{};
									auto checkcallback = mReceiver->createCallback<QString>(checkcallbacksuccess, checkcallbackfail);
									Biz::Session::getqCloudManager()->checkqCloudMainKey(strPwd, checkcallback);


								}
								else
								{
									MainApp::UIFrame::getEncryptChatcontroller()->doCreateMainKey(pwdOther, strUserid);
								}
							}

						}
						else
						{

							MainApp::UIFrame::getEncryptChatcontroller()->doGetSubKey(strMainKey,strUserid, pwdOther);

						}
					}
					else
					{
						MainApp::UIFrame::getEncryptChatcontroller()->doCreateMainKey(pwdOther, strUserid);
					}
				};

				auto callbackfail = []{};
				auto callback = mReceiver->createCallback<QString>(callbacksuccess,callbackfail);
				Biz::Session::getqCloudManager()->getqCloudMainKey(100,callback);




				MainApp::UIFrame::getEncryptChatcontroller()->sgLocalArgeeOrRefuse(strUserid, Biz::EncryptMessageType::EncryptMessageType_Agree);
			}
			else
			{
				//给对方发一个拒绝的message
				Biz::Session::getConverSationManager()->SendEncryptMessage(strUserid, QStringLiteral("拒绝"), Biz::EncryptMessageType::EncryptMessageType_Refuse);
				MainApp::UIFrame::getEncryptChatcontroller()->sgLocalArgeeOrRefuse(strUserid, Biz::EncryptMessageType::EncryptMessageType_Refuse);
			}
		}
		if (msg->MediaType() == Biz::EncryptMessageType::EncryptMessageType_Agree) //对方接受了，弹框提示一下
		{
			QString strdisplay = Biz::Session::getUserVcardManager()->getUserNameByConversationId(strUserid);
			if (strdisplay.isEmpty())
			{
				strdisplay = strUserid;
			}
			QString strInfo= QStringLiteral("[%1]同意加密会话!").arg(strdisplay);
			//MainApp::UIFrame::getNotifyCenterController ()->popupConversationNotice (strInfo, strUserid);
			MainApp::UIFrame::getEncryptChatcontroller()->sgEncryptResponeInfor(ResponeArgee, strUserid, strInfo);
			Biz::Session::getConverSationManager()->sgEncryptMsgInfo(strUserid, msg);
		}
		if (msg->MediaType() == Biz::EncryptMessageType::EncryptMessageType_Refuse) //对方拒绝，也弹框提示
		{
			QString strdisplay = Biz::Session::getUserVcardManager()->getUserNameByConversationId(strUserid);
			if (strdisplay.isEmpty())
			{
				strdisplay = strUserid;
			}
			QString strInfo= QStringLiteral("[%1]拒绝加密会话!").arg(strdisplay);
			//MainApp::UIFrame::getNotifyCenterController ()->popupConversationNotice (strInfo, strUserid);
			MainApp::UIFrame::getEncryptChatcontroller()->sgEncryptResponeInfor(ResponeRefuse, strUserid, strInfo);
		}
		if (msg->MediaType() == Biz::EncryptMessageType::EncryptMessageType_Cancel)//取消请求加密会话， 也弹框提示
		{
			QString strdisplay = Biz::Session::getUserVcardManager()->getUserNameByConversationId(strUserid);
			if (strdisplay.isEmpty())
			{
				strdisplay = strUserid;
			}
			QString strInfo= QStringLiteral("[%1]取消加密会话!").arg(strdisplay);

			MainApp::UIFrame::getEncryptChatcontroller()->sgEncryptResponeInfor(ResponeCancel, strUserid, strInfo);
			MainApp::UIFrame::getConversationController()->deleteEncrypt(strUserid);
			Biz::Session::getConverSationManager()->sgEncryptMsgInfo(strUserid, msg);
		}
		if(msg->MediaType() == Biz::EncryptMessageType::EncryptMessageType_Close) //关闭加密会话，也弹框提示
		{
			QString strdisplay = Biz::Session::getUserVcardManager()->getUserNameByConversationId(strUserid);
			if (strdisplay.isEmpty())
			{
				strdisplay = strUserid;
			}
			QString strInfo= QStringLiteral("[%1]关闭加密会话!").arg(strdisplay);
			MainApp::UIFrame::getEncryptChatcontroller()->sgEncryptResponeInfor(ResponeClose, strUserid, strInfo);
			MainApp::UIFrame::getConversationController()->deleteEncrypt(strUserid);

			Biz::Session::getConverSationManager()->sgEncryptMsgInfo(strUserid, msg);
		}

		return;

	}
}

void MainWidget::doCollectionInfor(const QSharedPointer<Biz::XmppMessage>& msg)
{
	if (msg.isNull())
	{
		return;
	}

	QString strconversationId; 
	if (msg->origintype() == Biz::MessageSourceType::GroupMessage)
	{
		strconversationId = QXmppUtils::jidToBareJid(msg->originfrom());
	}
	else if (msg->origintype() == Biz::MessageSourceType::ChatMessage)
	{
		strconversationId = msg->originfrom();
	}

	BaseChatDialog* pDialog = MainApp::UIFrame::getConversationController()->findConversationBaseChatDialog(strconversationId);
	if (NULL!=pDialog)
		pDialog->onCollectionMessageReceived(msg);
}