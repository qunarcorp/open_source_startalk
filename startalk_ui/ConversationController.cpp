#include "ConversationController.h"
#include <QJsonDocument>
#include "ChatDialog.h"
#include "GroupChatDialog.h"
#include "newsdialog.h"
#include "MenuRobotDialog.h"
#include "EmotionTabDialog.h"
#include "Quickreplymsgdialog.h"
#include "MultiDialogContainer.h"
#include "ExtendedSessionListView.h"
#include "RosterListWidget.h"
#include "LanguageHelper.h"
#include "NotifyCenterController.h"
#include "messagebubble/MessageParser.h"
#include "AdvData.h"
#include "Account.h"
#include "XmppMessage.h"
#include "Player.h"
#include "CustomDefine.h"
#include "StaticData.h"
#include "SettingData.h"
#include "AccountData.h"

#include "Session.h"
#include "UserVcardManager.h"
#include "conversationmanager.h"
#include "advinformanager.h"
#include "MessageManager.h"

#include "GroupManager.h"
#include "accountmanager.h"
#include "RobotManager.h"
#include "UIFrame.h"
#include "MainDialogController.h"
#include "slidingstackedwidget.h"
#include "trayiconhovernoticewidget.h"

#include "editablesettings.h"
#include "vidioandaudiodialog.h"
#include "GroupListData.h"
#include "conversationlistwidget.h"
#include "SystemConfigData.h"
#include "qcloudmanager.h"
#include "Ordermanagedialog.h"
#include "UIFrame.h"
#include "encryptchatcontroller.h"
#include "virtualaccountcontroller.h"
#include "virtualaccountmanager.h"
#include "passwordinput.h"
#include "collectiontreeview.h"
#include "jsonobject/systemnotify.h"

#include "consultchatdialog.h"

#include "jsonobject/conversationparam.h"

namespace MainApp
{

	// 数值无意义，但是保证唯一
	const QString   ConversationController::sDefaultExtendPanel = "7f69e0fbb9ea43eab045873558ca996b";

	ConversationController::ConversationController(QObject *parent)
		: ControllerBase(parent)
		, m_pContainer(NULL)
		, mbActiveItem(false)
	{
		mNoActiveList.append(Util::SUBSCRIPTIONNUM_ID);
		mNoActiveList.append(Util::COLLECTION_DIALOG_ID);
	}

	ConversationController::ConversationController()
		: ControllerBase(NULL)
		, m_pContainer(NULL)
	{
	}

	ConversationController::~ConversationController()
	{

	}

	void ConversationController::initController()
	{
		connect(Biz::Session::getGroupManager(),&Biz::GroupManager::sgGroupDestroyed,this,&ConversationController::onGroupDestroyed);
		connect(Biz::Session::getGroupManager(),&Biz::GroupManager::sgGroupLeavedReceived,this,&ConversationController::onGroupLeaved);
		connect(Biz::Session::getGroupManager(),&Biz::GroupManager::sgDestroyGroupFail,this,&ConversationController::onDestroyGroupFail);

		connect(Biz::Session::getUserVcardManager(),&Biz::UserVcardManager::sgGroupHeaderUpdate,this,&ConversationController::updateGroupHeader);


		connect(Biz::Session::getConverSationManager(),&Biz::ConverSationManager::sgRecentBuddiesResult,this,&ConversationController::onRecentImSessionRecv);

		connect(Biz::Session::getRobotManager(),&Biz::RobotManager::sgRobotVcardUpdated,this,&ConversationController::onRobotVcardUpdate);
		connect(Biz::Session::getRobotManager(),&Biz::RobotManager::sgSubScriptionReceived,this,&ConversationController::onSubscriptMessageRecveid);

		connect(Biz::Session::getAdvInforManager(), &Biz::AdvInforManager::sgImages, this, &ConversationController::onShowAdvWidget);

		connect(Biz::Session::getLoginManager(), &Biz::LoginManager::sgDisconnected, this, &ConversationController::onDisconnect);

		connect(Biz::Session::getConverSationManager(), &Biz::ConverSationManager::sgConversationUnreadCountChange,
			this, &ConversationController::onUpdateUnReadCount);

		connect(Biz::Session::getConverSationManager(), &Biz::ConverSationManager::sgAllConversationReaded,
			this, &ConversationController::onAllConversationMessageReaded);

		connect(Biz::Session::getConverSationManager(), &Biz::ConverSationManager::sgConversationReadedByOtherClient, 
			this, &ConversationController::onConversationReadedByOtherClient);
		connect(Biz::Session::getConverSationManager(), &Biz::ConverSationManager::sgAllConversationReadedByOtherClient, 
			this, &ConversationController::onAllConversationReadedByOtherClient);

		//机器人列表
		connect(Biz::Session::getRobotManager(),&Biz::RobotManager::sgAllRobotList,this,&ConversationController::onAllRobotIdList);

		connect (Biz::Session::getMessageManager (),&Biz::MessageManager::sgAtMessageInUnreadMessage, this,&ConversationController::onAtMessageFindInUnreadMessage);

		//转移的消息回馈
		connect (Biz::Session::getConverSationManager (),&Biz::ConverSationManager::sgTransReply, this,&ConversationController::onTransReplay, Qt::DirectConnection);

		//手动的删除会话列表中的item
		connect (Biz::Session::getConverSationManager (),&Biz::ConverSationManager::sgRemoveRecentItem, this,&ConversationController::onRemoveRecentItem);

		//被创建的群和被拖入群中的信号
		connect(Biz::Session::getGroupManager(), &Biz::GroupManager::sgGroupCoverAdd, this, &ConversationController::onGroupCoverAdd);

		//自己会话密码的
		connect(Biz::Session::getqCloudManager(), &Biz::qCloudManager::sgSelfConversationKey, this, &ConversationController::onSelfConversationKey);

		//connect(Biz::Session::getConverSationManager (), &Biz::ConverSationManager::sgEncryptEvent, this, &ConversationController::onEncryptEvent);

		connect(Biz::Session::getConverSationManager(), &Biz::ConverSationManager::sgShowEmpty, this, &ConversationController::onShowEmpty);

		connect(Biz::Session::getConverSationManager(), &Biz::ConverSationManager::sgRectChatLastMsg, this, &ConversationController::onRectChatLastMsg);

		//下发的presence
		connect(Biz::Session::getConverSationManager(), &Biz::ConverSationManager::sgPresenceOpenChat, this, &ConversationController::onPresenceOpenChat);

		connect(Biz::Session::getConverSationManager(), &Biz::ConverSationManager::sgPresenceGlobleNotice, this, &ConversationController::onPresenceGlobalNotice);
		connect(Biz::Session::getConverSationManager(), &Biz::ConverSationManager::sgPresenceAppointNotice, this, &ConversationController::onPresenceAppointNotice);
	}

	void ConversationController::unInitController()
	{
	}

	void ConversationController::registChatDialogContainer( MultiDialogContainer* pChatsContainer)
	{
		this->m_pContainer = pChatsContainer;

		RecentExtendedSessionListView* pDefaultExtendView = new RecentExtendedSessionListView(m_pContainer->getExtendPanelStacked());
		pDefaultExtendView->setLindedId(sDefaultExtendPanel);

		m_pContainer->getExtendPanelStacked()->addWidget(pDefaultExtendView);
		m_pContainer->getExtendPanelStacked()->setCurrentWidget(pDefaultExtendView);
		bindExtendViewEvents(pDefaultExtendView);
		m_jid2ExtendView.insert(sDefaultExtendPanel,pDefaultExtendView);

	}


	void ConversationController::activeNextUnreadConversation(bool promotWithCount)
	{
		auto cbSuccess  = [this](const QString& conversationId){
			RecentExtendedSessionListView* pExtendView = getExtendedSessionViewByConversationId(conversationId);
			if (NULL!=pExtendView)
			{
				pExtendView->getRosterListView()->autoScroll (conversationId,QAbstractItemView::PositionAtTop);
			}
		};
		auto cbFail     = [this]{
			setScolltoTop();
		};
		auto nextUnreadConversatinCb = createCallback<QString> (cbSuccess,cbFail);
		// 数据库中获取未读的消息数
		Biz::Session::getMessageManager ()->getLastUnreadConversationId (promotWithCount,nextUnreadConversatinCb);
	}



	void ConversationController::activeConversation(const QString& conversationID)
	{
		// 前提得有这个会话,可以只有列表内容，没有会话框
		// 区分群组、个人、机器人，新闻
		// 没有窗口的时候创建窗口,有窗口的时候置顶
		// 清除未读消息、设置主窗口标题
		// 设置会话列表中的激活项
		if (hasConversation(conversationID))
		{
			//屏蔽这地方的理由是，离线接到消息后，
			//上线后，发现有些item中未读消息无前面小红点
			emit sgConversationActived(conversationID);
			QString lastConversionID = topConversationId();
			if (conversationID!=lastConversionID)
				emit sgCurrentConversationChange(conversationID,lastConversionID);


			QString extendId = getConversationsExtendId(conversationID);
			Q_ASSERT(NULL!=m_pContainer);
			RecentExtendedSessionListView* pExtendView = getExtendedSessionListView(extendId);
			Q_ASSERT(NULL!=pExtendView);

			if (NULL == pExtendView)
				return;

			pExtendView->getRosterListView()->activityChatDialog(conversationID);

			// 群组
			if (pExtendView->getRosterListView()->isGroupChatItem(conversationID))
			{
				BaseChatDialog* pDialog = createNewGroupChatDialog(conversationID);
				activeBaseChatDialog(pDialog);

				////Biz::Session::getGroupManager()->getGroupNickName(conversationID);
				QString title = Biz::Session::getGroupManager()->getGroupLocalNickNamebyId(conversationID);
				MainApp::UIFrame::getMainDialogController()->setMainDialogTitle(title);
			}

			// consult
			if (pExtendView->getRosterListView()->isConsultChatItem(conversationID))
			{
				BaseChatDialog* pDialog = createNewConsultDialog(conversationID);
				ConsultChatDialog* pConsoltDialog = dynamic_cast<ConsultChatDialog*>(pDialog);
				if (NULL!=pConsoltDialog)
				{

					pConsoltDialog->setVirtualJid(pExtendView->getRosterListView()->getConsultVirtualJid(conversationID));
					pConsoltDialog->setRealJid(pExtendView->getRosterListView()->getConsultRealJid(conversationID));
					pConsoltDialog->setIsSeat(pExtendView->getRosterListView()->getConsultIsSeatFlag(conversationID));
					pConsoltDialog->resetUI();
				}

				activeBaseChatDialog(pDialog);

				QString title = Biz::Session::getUserVcardManager()->getUserNameByConversationId(conversationID);
				MainApp::UIFrame::getMainDialogController()->setMainDialogTitle(title);

#ifdef QCHAT
				doGetZhongbaoParam(conversationID);
#endif // QCHAT

			}
			// 个人
			if (pExtendView->getRosterListView()->isSimpleChatItem(conversationID))
			{
				BaseChatDialog* pDialog = createNewChatDialog(conversationID);
				activeBaseChatDialog(pDialog);

				QString title = Biz::Session::getUserVcardManager()->getUserNameByConversationId(conversationID);
				MainApp::UIFrame::getMainDialogController()->setMainDialogTitle(title);

#ifdef QCHAT
				doGetZhongbaoParam(conversationID);
#endif // QCHAT

			}
			// 新闻
			if (pExtendView->getRosterListView()->isNewsChatItem(conversationID))
			{
				BaseChatDialog* pDialog = createNewNewsDialog(conversationID);
				activeBaseChatDialog(pDialog);

				QString title = Biz::Session::getUserVcardManager()->getUserNameByConversationId(conversationID);
				MainApp::UIFrame::getMainDialogController()->setMainDialogTitle(title);
			}
			// 机器人
			if (pExtendView->getRosterListView()->isRobotChatItem(conversationID))
			{
				QString extendid = Biz::Session::getRobotManager()->getBelongExtendId(conversationID);
				if (!extendid.isEmpty())
				{
					QString belongExtendName = Biz::Session::getUserVcardManager()->getUserNameByConversationId(extendid);
					addLinkedItem(extendid,belongExtendName,sDefaultExtendPanel);
				}

				BaseChatDialog* pDialog = createNewMenuChatDialog(conversationID);
				activeBaseChatDialog(pDialog);

				if (Biz::MessageUtil::compareUserId(conversationID, Util::QIANGDAN_DIALOG_ID))
				{
					m_pContainer->showEmptyChatdialog();
				}


				QString title = Biz::Session::getUserVcardManager()->getUserNameByConversationId(conversationID);
				MainApp::UIFrame::getMainDialogController()->setMainDialogTitle(title);
			}
			// link
			if (pExtendView->getRosterListView()->isLinkedItem(conversationID))
			{
				activeLinkedPannel(conversationID,true);
			}

			if (pExtendView->getRosterListView()->isRawHtmlItem(conversationID))
			{
				BaseChatDialog* pDialog = createNewRawHtmlDialog(conversationID);
				activeBaseChatDialog(pDialog);

				QString title = Biz::Session::getUserVcardManager()->getUserNameByConversationId(conversationID);
				MainApp::UIFrame::getMainDialogController()->setMainDialogTitle(title);
			}

			MainApp::UIFrame::getMainDialogController()->activeChatsTab();
			activeLinkedPannel(pExtendView->getLindedId(),false);

		}
	}




	BaseChatDialog* ConversationController::createNewConsultDialog(const QString& conversationId)
	{
		if (conversationId.isEmpty() || NULL==m_pContainer )
			return NULL;

		if (m_conversationId2DialogMap.contains(conversationId))
			return dynamic_cast<ConsultChatDialog*>(m_conversationId2DialogMap.value(conversationId));

		ConsultChatDialog* chatDlg = NULL;
		chatDlg = new ConsultChatDialog(m_pContainer); 
		chatDlg->SetChatType(Biz::consult);
		chatDlg->setCounversationId(conversationId);

		QString id = conversationId.mid(0, conversationId.indexOf("|shop"));
		QString displayName = Biz::Session::getUserVcardManager()->getUserNameByConversationId(id);

		chatDlg->onLoadRoster(conversationId, displayName);
		addBaseChatDialog(conversationId,chatDlg);
#ifdef QCHAT
		doGetZhongbaoParam(conversationId);
#endif // QCHAT

		// 看看如果是虚拟账号，需要进行 session, 获取 realid
		if (Biz::Session::getVirtualManager()->IsVirtualAccount(conversationId/*Biz::MessageUtil::makeSureUserId(conversationId)*/))
		{
			Biz::Session::getVirtualManager()->getRealAccountbyVirtualAccount(Biz::MessageUtil::makeSureUserId(conversationId));
		}

		return chatDlg;
	}

	BaseChatDialog* ConversationController::createNewChatDialog(const QString& conversationId)
	{
		if (conversationId.isEmpty() || NULL==m_pContainer )
			return NULL;


		if (UtilHelper::isVirtualAccountId(conversationId,""))
		{
			QString virtualid = UtilHelper::getvirtualfromID(conversationId);
			QString realjid = UtilHelper::getRealIdfromID(conversationId);
			return createNewConsultDialog(conversationId);
		}

		if (Biz::Session::getVirtualManager()->IsVirtualAccount(conversationId))
		{
			return createNewConsultDialog(conversationId);
		}

		if (m_conversationId2DialogMap.contains(conversationId))
			return dynamic_cast<ChatDialog*>(m_conversationId2DialogMap.value(conversationId));

		ChatDialog* chatDlg = NULL;
		chatDlg = new ChatDialog(m_pContainer); 
		chatDlg->SetChatType(Biz::ChatMessage);
		chatDlg->setCounversationId(conversationId);

		QString displayName = Biz::Session::getUserVcardManager()->getUserNameByConversationId(conversationId);

		chatDlg->onLoadRoster(conversationId, displayName);
		addBaseChatDialog(conversationId,chatDlg);
#ifdef QCHAT
		doGetZhongbaoParam(conversationId);
#endif  // QCHAT

		// 看看如果是虚拟账号，需要进行session,获取realid
		if (Biz::Session::getVirtualManager()->IsVirtualAccount(Biz::MessageUtil::makeSureUserId(conversationId)))
		{
			Biz::Session::getVirtualManager()->getRealAccountbyVirtualAccount(Biz::MessageUtil::makeSureUserId(conversationId));
		}

		return chatDlg;
	}

	BaseChatDialog* ConversationController::createNewGroupChatDialog(const QString& conversationId)
	{
		if (conversationId.isEmpty() || NULL == m_pContainer)
			return NULL;
		QStringList strkey = m_conversationId2DialogMap.keys();
		if (m_conversationId2DialogMap.contains(conversationId))
			return m_conversationId2DialogMap.value(conversationId);

		GroupChatDialog* gpChatDlg = new GroupChatDialog(m_pContainer);
		gpChatDlg->SetChatType(Biz::GroupMessage);
		gpChatDlg->setCounversationId(conversationId);
		gpChatDlg->initSettings();
		gpChatDlg->onSetTitle(conversationId, "");
		addBaseChatDialog(conversationId,gpChatDlg);

		return gpChatDlg;
	}

	BaseChatDialog* ConversationController::createNewMenuChatDialog(const QString& conversationId, int type)
	{
		if (conversationId.isEmpty() || NULL == m_pContainer)
			return NULL;
		if (m_conversationId2DialogMap.contains(conversationId))
			return m_conversationId2DialogMap.value(conversationId);

		//由于应用了代收，这地方需要判断一下是群还是二人
		QString displayName;
		if (conversationId.contains("@conference."))
		{
			displayName = Biz::Session::getGroupManager()->getGroupLocalNickNamebyId(conversationId);
		}
		else
			displayName = Biz::Session::getUserVcardManager()->getUserNameByConversationId(conversationId);

		MenuRobotDialog* pDialog = new MenuRobotDialog(m_pContainer);
		pDialog->setCounversationId(conversationId);
		pDialog->SetChatType(type);
		pDialog->onLoadRoster(conversationId,displayName);
		pDialog->setupUiQss("");


		m_conversationId2DialogMap.insert(conversationId,pDialog);

		m_pContainer->getBaseChatDialogStatckWidget()->addWidget(pDialog);

		if ( Biz::MessageUtil::compareUserId(Util::SYSTEMNEWS_DIALOG_ID,conversationId) || Biz::MessageUtil::compareUserId(Util::NOTICENEWS_DIALOG_ID,conversationId) )
		{
			pDialog->setInputAreaVisable(false);
			pDialog->setMenuAreaVisable(false);
		}

		return pDialog;
	}

	BaseChatDialog* ConversationController::createNewNewsDialog(const QString& conversationId)
	{
		if (conversationId.isEmpty())
			return NULL;
		if (m_conversationId2DialogMap.contains(conversationId) && NULL!=m_conversationId2DialogMap.value(conversationId))
			return m_conversationId2DialogMap.value(conversationId);

		NewsDialog* pNewsDialog = new NewsDialog(m_pContainer,Biz::NEWSDIALOG);
		pNewsDialog->setCounversationId(conversationId);
		QString displayName = Biz::Session::getUserVcardManager()->getUserNameByConversationId(conversationId);

		pNewsDialog->onLoadRoster(conversationId, displayName);
		m_conversationId2DialogMap.insert(conversationId,pNewsDialog);
		m_pContainer->getBaseChatDialogStatckWidget()->addWidget(pNewsDialog);
		return pNewsDialog;
	}

	BaseChatDialog* ConversationController::createNewRawHtmlDialog(const QString& conversationId)
	{
		if (conversationId.isEmpty())
			return NULL;
		if (m_conversationId2DialogMap.contains(conversationId) && NULL!=m_conversationId2DialogMap.value(conversationId))
			return m_conversationId2DialogMap.value(conversationId);

		NewsDialog* pNewsDialog = new NewsDialog(m_pContainer,Biz::NEWSDIALOG);

		m_conversationId2DialogMap.insert(conversationId,pNewsDialog);
		m_pContainer->getBaseChatDialogStatckWidget()->addWidget(pNewsDialog);
		return pNewsDialog;
	}

	void ConversationController::addGroupChatRosterItem(const QString& conversationId,const QString& extendId)
	{
		Q_ASSERT(NULL!=m_pContainer);
		RecentExtendedSessionListView* pExtendView = getExtendedSessionListView(extendId);
		Q_ASSERT(NULL!=pExtendView);
		if (NULL == pExtendView)
			return;
		pExtendView->getRosterListView()->addGroupChatDialog(conversationId);

		//是否是接收不提示消息的项
		//因为从群组列表中点进来的项
		updateNoticetip(conversationId, pExtendView->getRosterListView());

		m_pContainer->updateConversationCountTip(getCouversationCount());
		//updateChatContent(conversationId, QSharedPointer<Biz::XmppMessage>());
		// 把最外层的那个列表的第一个置为激活状态
		if (pExtendView->getBelongExtendid().isEmpty()
			&& 1 == pExtendView->getRosterListView()->count())
		{
			activeConversation(conversationId);
		}

	}

	void ConversationController::addRobotChatRosterItem(const QString& conversationId,const QString& extendId)
	{
		Q_UNUSED(extendId);


		QSharedPointer<Biz::RobotVcard> spRobotVcard
			= Biz::Session::getRobotManager()->getRobotVcard(Biz::MessageUtil::makeSureUserId(conversationId));

		bool bPackage = true;
		if (!spRobotVcard.isNull())
		{
			QString rawData = spRobotVcard->RbtRawInfo();
			QJsonDocument doc = QJsonDocument::fromJson(rawData.toUtf8());
			QVariantMap paramMap = doc.toVariant().toMap();
			if (paramMap.contains("packageable"))
				bPackage = paramMap.value("packageable").toBool();
		}

		QString extendid = Biz::Session::getRobotManager()->getBelongExtendId(conversationId);
		if (bPackage && !extendid.isEmpty() && extendid != sDefaultExtendPanel)
		{
			QString belongExtendName = Biz::Session::getUserVcardManager()->getUserNameByConversationId(extendid);
			addLinkedItem(extendid,belongExtendName,sDefaultExtendPanel);
		}
		else
		{
			extendid = sDefaultExtendPanel;
		}

		RecentExtendedSessionListView* pExtendView = getExtendedSessionListView(extendid);
		Q_ASSERT(NULL!=pExtendView);
		if (NULL == pExtendView)
			return;


		pExtendView->getRosterListView()->addRobotDialog(conversationId);
		m_pContainer->updateConversationCountTip(getCouversationCount());

		// 把最外层的那个列表的第一个置为激活状态
		if (pExtendView->getBelongExtendid().isEmpty()
			&& 1 == pExtendView->getRosterListView()->count())
		{
			activeConversation(conversationId);
		}
	}

	void ConversationController::addNewsDialogRosterItem(const QString& conversatinId,const QString& extendid)
	{
		Q_ASSERT(NULL!=m_pContainer);
		RecentExtendedSessionListView* pExtendView = getExtendedSessionListView(extendid);
		Q_ASSERT(NULL!=pExtendView);
		if (NULL == pExtendView)
			return;

		pExtendView->getRosterListView()->addNewsDialog(conversatinId);
		m_pContainer->updateConversationCountTip(getCouversationCount());
		updateChatContent(conversatinId, QSharedPointer<Biz::XmppMessage>());
		// 把最外层的那个列表的第一个置为激活状态
		if (pExtendView->getBelongExtendid().isEmpty()
			&& 1 == pExtendView->getRosterListView()->count())
		{
			activeConversation(conversatinId);
		}
	}

	void ConversationController::addSimpleChatRosterItem(const QString& conversationId,const QString& extendId)
	{
		Q_ASSERT(NULL!=m_pContainer);

		if (UtilHelper::isVirtualAccountId(conversationId,""))
		{
			QString virtualid = UtilHelper::getvirtualfromID(conversationId);
			QString realjid = UtilHelper::getRealIdfromID(conversationId);
			return addConsultChatRosterItem(conversationId,extendId,virtualid,realjid,true);
		}

		if (Biz::Session::getVirtualManager()->IsVirtualAccount(conversationId))
		{
			return addConsultChatRosterItem(conversationId,extendId,conversationId,"",false);
		}

		RecentExtendedSessionListView* pExtendView = getExtendedSessionListView(extendId);
		if (NULL == pExtendView)
			return;
		QSharedPointer<Biz::ImSelfPerson> spPerson = Biz::Session::getUserVcardManager ()->userVcard (conversationId);

		if (spPerson.isNull () || (Biz::ImSelfPerson::UserSaveType::UserSaveType_Local != (Biz::ImSelfPerson::UserSaveType::UserSaveType_Local&spPerson->nUserType)))
		{
			Biz::Session::getUserVcardManager()->getDomainUsersVcardByVersionandImage(QStringList(conversationId));
		}

		pExtendView->getRosterListView()->addChatDialog(conversationId);
		m_pContainer->updateConversationCountTip(getCouversationCount());
		//updateChatContent(conversationId, QSharedPointer<Biz::XmppMessage>());

		// 最外层，最顶上的会话设置为激活状态
		if (pExtendView->getBelongExtendid().isEmpty()
			&& 1 == pExtendView->getRosterListView()->count())
		{
			activeConversation(conversationId);
		}

		updateMarkInfo(conversationId);

	}

	void ConversationController::addConsultChatRosterItem(const QString& conversationId,const QString& extendId,const QString& virtualid,const QString& realseat,bool isSeat)
	{
		Q_ASSERT(NULL!=m_pContainer);
		RecentExtendedSessionListView* pExtendView = getExtendedSessionListView(extendId);
		if (NULL == pExtendView)
			return;
		QSharedPointer<Biz::ImSelfPerson> spPerson = Biz::Session::getUserVcardManager ()->userVcard (conversationId);

		if (spPerson.isNull () || (Biz::ImSelfPerson::UserSaveType::UserSaveType_Local != (Biz::ImSelfPerson::UserSaveType::UserSaveType_Local&spPerson->nUserType)))
		{
			Biz::Session::getUserVcardManager()->getDomainUsersVcardByVersionandImage(QStringList(conversationId));
		}

		pExtendView->getRosterListView()->addConsultDialog(conversationId,virtualid,realseat,isSeat);
		m_pContainer->updateConversationCountTip(getCouversationCount());
		//updateChatContent(conversationId, QSharedPointer<Biz::XmppMessage>());

		// 最外层，最顶上的会话设置为激活状态
		if (pExtendView->getBelongExtendid().isEmpty()
			&& 1 == pExtendView->getRosterListView()->count())
		{
			activeConversation(conversationId);
		}

		updateMarkInfo(conversationId);

	}



	void ConversationController::addLinkedItem(
		const QString& extendid,
		const QString& extendPannelTitle,
		const QString& belongExtendid)
	{
		if (extendid.isEmpty())
			return;

		if (hasExtendedListView(extendid))
			return;

		RecentExtendedSessionListView* pBelongExtendView = getExtendedSessionListView(belongExtendid);
		if (NULL == pBelongExtendView)
			return;

		// 先创建一个扇出对象
		RecentExtendedSessionListView* pExtendView = new RecentExtendedSessionListView(m_pContainer);
		m_pContainer->getExtendPanelStacked()->addWidget(pExtendView);

		pExtendView->setBelongExtendid(belongExtendid);
		pExtendView->setLindedId(extendid);
		pExtendView->setExtendTitleVisable(true);
		pExtendView->setExtendTitle(extendPannelTitle);
		m_jid2ExtendView.insert(extendid,pExtendView);
		bindExtendViewEvents(pExtendView);


		pBelongExtendView->getRosterListView()->addLinkItem(extendid,extendPannelTitle,belongExtendid);

	}


	void ConversationController::addRawHtmlItem(const QString& conversationId,const QString& extendId)
	{
		Q_ASSERT(NULL!=m_pContainer);
		RecentExtendedSessionListView* pExtendView = getExtendedSessionListView(extendId);
		if (NULL == pExtendView)
			return;

		Biz::Session::getUserVcardManager()->getDomainUsersVcardByVersionandImage(QStringList(conversationId));
		pExtendView->getRosterListView()->addRawHtmlDialog(conversationId);
		m_pContainer->updateConversationCountTip(getCouversationCount());

		// 最外层，最顶上的会话设置为激活状态
		if (pExtendView->getBelongExtendid().isEmpty()
			&& 1 == pExtendView->getRosterListView()->count())
		{
			activeConversation(conversationId);
		}

		updateMarkInfo(conversationId);
	}

	BaseChatDialog* ConversationController::findConversationBaseChatDialog(const QString& conversationId)
	{
		if (m_conversationId2DialogMap.contains(conversationId))
		{
			return m_conversationId2DialogMap.value(conversationId);
		}
		return NULL;
	}

	/*!
	* 功能 : 在登出时调用，需要清理会话列表，左侧会话窗口,但是不需要把所有未读抹掉
	*/
	void ConversationController::clearAllConversation()
	{
		for (RecentExtendedSessionListView* pExtendview : m_jid2ExtendView.values())
		{
			if (NULL!=pExtendview)
			{
				pExtendview->getRosterListView()->clearData();
				m_pContainer->getExtendPanelStacked()->removeWidget(pExtendview);
				pExtendview->deleteLater();
			}
		}

		m_jid2ExtendView.clear();
		//         for (QString conversationId : m_conversationId2DialogMap.keys())
		//         {
		//             removeBaseChatDialog(conversationId);
		//         }
	}

	void ConversationController::removeBaseChatDialog(const QString& coversationID)
	{
		// 删除对dialog的保持
		if (m_conversationId2DialogMap.contains(coversationID)
			&& NULL!=m_pContainer)
		{
			BaseChatDialog* pDialog = m_conversationId2DialogMap.value(coversationID);
			m_pContainer->getBaseChatDialogStatckWidget()->removeWidget(pDialog);
			pDialog->deleteLater();
			m_conversationId2DialogMap.remove(coversationID);
			m_queueBaseChatDialogs.removeOne(pDialog);
			//删除这个chat框左边最近联系人的@ 信息
			//还是的判断一下是否有未读，如果有未读的，这地方的@不取消
			// 			RecentExtendedSessionListView* pExtendView = getExtendedSessionViewByConversationId(coversationID);
			// 			if (NULL != pExtendView)
			// 			{
			// 				if (pExtendView->getRosterListView()->getunReadCount(coversationID) == 0)
			// 				{
			// 					this->clearAtNotice(coversationID);
			// 				}
			// 			}



			if (m_conversationId2DialogMap.isEmpty())
			{
				m_pContainer->showEmptyChatdialog();
			}

			ChatDialog* pChatDialog = dynamic_cast<ChatDialog*>(pDialog);
			if (NULL != pChatDialog)
			{
				resizeMainDialogBySimpleChatRightPannel();
			}
		}
	}


	void ConversationController::removeLinkedPannel(const QString& linkedPannel)
	{

	}

	void ConversationController::removeConversation(const QString& conversationID)
	{
		RecentExtendedSessionListView* pExtendView = getExtendedSessionViewByConversationId(conversationID);
		if (NULL != pExtendView)
		{
			if (pExtendView->getRosterListView()->hasCouversation(conversationID))
			{
				pExtendView->getRosterListView()->deleteItem(conversationID);
				removeBaseChatDialog(conversationID);
				clearConversationAllRead(conversationID);
			
				int nUnreadCount = pExtendView->getRosterListView()->getunReadCount(conversationID);
				m_pContainer->updateConversationCountTip(getCouversationCount());

				if (nUnreadCount >0)
				{
					emit Biz::Session::getConverSationManager()->sgAllConversationReaded();
				}
				
				Biz::Session::getConverSationManager()->updateRecentImSessionConfigrationofLocal(conversationID,0,Biz::SESSION_CFG_TOPMOST);
				//Biz::Session::getConverSationManager()->updateRecentImSessionConfigration(conversationID,0,Biz::SESSION_CFG_TOPMOST);
				
				if (m_willSendMsg.contains(conversationID))
				{
					m_willSendMsg.remove(conversationID);
				}
			}
		}
	}

	/*!
	* 功能 : 貌似没用
	*/
	int ConversationController::getBaseChatDialogCount()
	{
		return 0;
	}

	/*!
	* 功能 : 会话列表中是否已经存在这个id
	*/
	bool ConversationController::hasConversation(const QString& conversationId)
	{
		Q_ASSERT(NULL!=m_pContainer);
		// 顶层列表
		for (RecentExtendedSessionListView* pExtendView:m_jid2ExtendView.values())
		{
			if (NULL!=pExtendView && pExtendView->getRosterListView()->hasCouversation(conversationId))
			{
				return true;
			}
		}
		return false;
	}


	/*!
	* 功能 : 获取某个会话所在的会话组的id
	*/
	QString ConversationController::getConversationsExtendId(const QString& conversationId)
	{
		// 顶层列表
		for (RecentExtendedSessionListView* pExtendView:m_jid2ExtendView.values())
		{
			if (NULL!=pExtendView && pExtendView->getRosterListView()->hasCouversation(conversationId))
			{
				return m_jid2ExtendView.key(pExtendView);
			}
		}
		return sDefaultExtendPanel;
	}


	/*!
	* 功能 : 清除某个会话的未读消息
	*/
	void ConversationController::clearConversationAllRead(const QString& conversationID)
	{

		if (hasConversation(conversationID))
		{
			QString extendId = getConversationsExtendId(conversationID);
			RecentExtendedSessionListView* pExtendView = getExtendedSessionListView(extendId);
			Q_ASSERT(NULL!=pExtendView);

			if (NULL == pExtendView)
				return;


			// 群组
			if (pExtendView->getRosterListView()->isGroupChatItem(conversationID))
			{
				Biz::Session::getConverSationManager()->setGroupConversationMessageRead(conversationID);
			}
			if (pExtendView->getRosterListView()->isSimpleChatItem(conversationID))
			{
				Biz::Session::getConverSationManager()->setConversationMessageRead(conversationID);
			}
			if (pExtendView->getRosterListView()->isConsultChatItem(conversationID))
			{
				Biz::Session::getConverSationManager()->setConversationMessageRead(conversationID);
			}

			if (pExtendView->getRosterListView()->isRobotChatItem(conversationID)
				|| pExtendView->getRosterListView()->isNewsChatItem(conversationID))
			{
				Biz::Session::getConverSationManager()->setLocalCoversationMessageRead(conversationID);
			}
		}
	}

	bool ConversationController::isTopChatDialog(const QString& coversationId)
	{
		return topConversationId() == coversationId;
	}

	QString ConversationController::topConversationId()
	{
		BaseChatDialog* pDialog = dynamic_cast<BaseChatDialog*>(m_pContainer->getBaseChatDialogStatckWidget()->currentWidget());
		return NULL!=pDialog?pDialog->conversationId():"";
	}

	WId ConversationController::topConversationWid()
	{
		BaseChatDialog* pDialog = dynamic_cast<BaseChatDialog*>(m_pContainer->getBaseChatDialogStatckWidget()->currentWidget());
		return NULL!=pDialog?pDialog->winId():0;
	}

	void ConversationController::onUpdateUnReadCount(const QMap<QString,int>& cidUnreadCntMapping)
	{
		foreach(QString key,cidUnreadCntMapping.keys()){
			int value = cidUnreadCntMapping.value(key);

			QString extendId = getConversationsExtendId(key);
			RecentExtendedSessionListView* pBelongExtend = getExtendedSessionListView(extendId);
			//Q_ASSERT(NULL!=pBelongExtend);
			if (NULL == pBelongExtend)
				return;


			// 需要去更新它的父节点,如果是跟节点就算了
			QString upperExtendid = pBelongExtend->getBelongExtendid();
			if (!upperExtendid.isEmpty())
			{
				RecentExtendedSessionListView* pUpperExtend = getExtendedSessionListView(upperExtendid);
				Q_ASSERT(NULL != pUpperExtend);
				if (NULL != pUpperExtend)
				{
					pUpperExtend->getRosterListView()->updateLinkItemUnReadCount(extendId);
				}
			}

			pBelongExtend->getRosterListView()->updateUnReadCount(key, value);

			if (0 == value)
			{
				TrayIconHoverNoticeWidgetSingleton::getInstance()->markItemRead(key);
			}
		}
	}



	void ConversationController::moveSessionToTop(const QString& conversationId)
	{

		RecentExtendedSessionListView* pExtendView = getExtendedSessionViewByConversationId(conversationId);
		if (NULL!=pExtendView)
		{
			this->updateJidLastTimeStamp(conversationId,QDateTime::currentDateTime().toMSecsSinceEpoch()-Biz::Session::currentAccount().getTimeOffsetFromServer());
		}
	}

	bool ConversationController::hasExtendedListView(const QString& extendid)
	{
		return m_jid2ExtendView.contains(extendid);
	}

	bool ConversationController::hasNewExtendedListView( const QString& extendid )
	{
		return m_jid2ExtendListView.contains(extendid);
	}

	RecentExtendedSessionListView* ConversationController::getExtendedSessionListView(const QString& extendid)
	{
		if (m_jid2ExtendView.contains(extendid))
			return dynamic_cast<RecentExtendedSessionListView*>(m_jid2ExtendView.value(extendid));

		return NULL;
	}

	RecentExtendedSessionListView* ConversationController::getExtendedSessionViewByConversationId(const QString& converdationId)
	{
		QString extendId = getConversationsExtendId(converdationId);

		return getExtendedSessionListView(extendId);
	}

	void ConversationController::activeLinkedPannel(const QString& pannelId,bool bAcitiveConversation)
	{
		if (m_jid2ExtendView.contains(pannelId))
		{
			if (sDefaultExtendPanel!=pannelId)
			{
				QWidget* pWidget = m_jid2ExtendView.value(pannelId);
				if (m_pContainer->getExtendPanelStacked()->currentWidget()!=pWidget)
				{
					m_pContainer->getExtendPanelStacked()->slideInWidget(pWidget, SlidingStackedWidget::RIGHT2LEFT);
				}
			}
			else
			{
				onBackToWidget(sDefaultExtendPanel);
			}

		}
		if (m_jid2ExtendListView.contains(pannelId))
		{
			if (sDefaultExtendPanel!=pannelId)
			{
				QWidget* pWidget = m_jid2ExtendListView.value(pannelId);
				if (m_pContainer->getExtendPanelStacked()->currentWidget()!=pWidget)
				{
					m_pContainer->getExtendPanelStacked()->slideInWidget(pWidget, SlidingStackedWidget::RIGHT2LEFT);
					CollectionTreeView *ptreeview = (CollectionTreeView *)((ExtendedSessionListView*)pWidget)->getCombinationListView();
					if (ptreeview)
					{
						ptreeview->initList();
					}

				}
			}
			else
			{
				onCollectBackToWidget(sDefaultExtendPanel);
			}
		}
	}


	void ConversationController::resizeMainDialogBySimpleChatRightPannel()
	{
		bool bSetExtendSize = false;
		for (BaseChatDialog* pBaseDialog : m_conversationId2DialogMap.values())
		{
			ChatDialog* pChatDialog = dynamic_cast<ChatDialog*>(pBaseDialog);
			if (NULL!=pChatDialog && pChatDialog->IsVisibleRightExtendPanel())
			{
				bSetExtendSize = true;
				break;
			}
		}

		MainApp::UIFrame::getMainDialogController()->resizeMainDialogSize(bSetExtendSize);
	}

	void ConversationController::emitSimpleChatDialogSendFile(const QString& conversationId)
	{
		if (m_conversationId2DialogMap.contains(conversationId))
		{
			ChatDialog* pDialog = dynamic_cast<ChatDialog*>(m_conversationId2DialogMap.value(conversationId));
			if (NULL!= pDialog)
			{
				pDialog->selectFileAndSend();
			}
		}
	}

	void ConversationController::onBackToWidget(const QString& userid)
	{
		if (NULL == m_pContainer)
			return;

		if (m_jid2ExtendView.contains(userid))
		{
			m_pContainer->getExtendPanelStacked()->slideInWidget(m_jid2ExtendView.value(userid), SlidingStackedWidget::LEFT2RIGHT);
		}
		else
		{
			m_pContainer->getExtendPanelStacked()->slideInWidget(m_jid2ExtendView.value(sDefaultExtendPanel), SlidingStackedWidget::LEFT2RIGHT);
		}
	}

	void ConversationController::onCollectBackToWidget( const QString&userid )
	{
		if (NULL == m_pContainer)
			return;

		if (m_jid2ExtendView.contains(userid))
		{
			m_pContainer->getExtendPanelStacked()->slideInWidget(m_jid2ExtendView.value(userid), SlidingStackedWidget::LEFT2RIGHT);
		}
		else
		{
			m_pContainer->getExtendPanelStacked()->slideInWidget(m_jid2ExtendView.value(sDefaultExtendPanel), SlidingStackedWidget::LEFT2RIGHT);
		}
	}

	void ConversationController::onSimpleChatDialogSendFile(const QString& conversationId)
	{
		emitSimpleChatDialogSendFile(conversationId);
	}

	void ConversationController::bindExtendViewEvents(const RecentExtendedSessionListView* pExtendView)
	{
		Q_ASSERT(NULL!=pExtendView);
		Q_ASSERT(NULL!=pExtendView->getRosterListView());
		if (NULL!=pExtendView && NULL != pExtendView->getRosterListView())
		{
			RosterListWidget* pRosterView = pExtendView->getRosterListView();
			connect(pExtendView, &ExtendedSessionListView::sgBackButtonClicked,this,&MainApp::ConversationController::onBackToWidget);
		}
	}

	void ConversationController::bindExtendListViewEvents( const ExtendedSessionListView*pExtendView )
	{
		Q_ASSERT(NULL!=pExtendView);
		Q_ASSERT(NULL!=pExtendView->getCombinationListView());
		if (NULL!=pExtendView && NULL != pExtendView->getCombinationListView())
		{
			ExtendedSessionListView* pRosterView = pExtendView->getCombinationListView();
			connect(pExtendView, &ExtendedSessionListView::sgBackButtonClicked,this,&MainApp::ConversationController::onCollectBackToWidget);
		}
	}

	void ConversationController::onGroupLeaved(const QString& groupJid)
	{
		removeConversation(groupJid);
		Biz::Session::getConverSationManager()->removeChartingImSession(groupJid);

	}

	void ConversationController::onGroupDestroyed(const QString& groupjid)
	{
		removeConversation(groupjid);
		Biz::Session::getConverSationManager()->removeChartingImSession(groupjid);
		QString gname = Biz::Session::currentAccount().getGroupNickName(groupjid);
		if (!gname.isEmpty() && Biz::Session::getSettingConfig()->MessageBoxNotice())
		{
			QString message = QString(T_("groupDestroyed")).arg(gname);
			MainApp::UIFrame::getNotifyCenterController ()->alertMessage (message);
		}
	}


	void ConversationController::onDestroyGroupFail(const QString& jid,int code)
	{
		QString gname = Biz::MessageUtil::makeSureUserId(jid);
		if (!gname.isEmpty())
		{
			QString errorTxt = T_(QString("DestroyGroupFail_%1").arg(code));
			if (errorTxt.isEmpty())
			{
				errorTxt = QString("%1").arg(code);
			}
			QString message = QString(T_("DestroyGroupFail")).arg(gname).arg(errorTxt);
			MainApp::UIFrame::getNotifyCenterController ()->alertMessage (message);
		}
	}

	// 会话列表创建或变更，通过信号通知到更新 
	void ConversationController::onRecentImSessionRecv(const QList<Biz::ImSession>& imSessions)
	{
		if (!m_pContainer || imSessions.isEmpty())
			return;

		Log::e(QString("MainWidget::onRecentImSessionRecv %1").arg(imSessions.size()));
		Biz::LogReporter r(QStringLiteral("创建最近联系人列表"));

		if (!m_jid2ExtendView.contains(sDefaultExtendPanel))
		{
			RecentExtendedSessionListView* pDefaultExtendView = new RecentExtendedSessionListView(m_pContainer->getExtendPanelStacked());
			pDefaultExtendView->setLindedId(sDefaultExtendPanel);

			m_pContainer->getExtendPanelStacked()->addWidget(pDefaultExtendView);
			m_pContainer->getExtendPanelStacked()->setCurrentWidget(pDefaultExtendView);
			bindExtendViewEvents(pDefaultExtendView);
			m_jid2ExtendView.insert(sDefaultExtendPanel,pDefaultExtendView);

		}
		if (!m_jid2ExtendListView.contains(sDefaultExtendPanel))
		{
			RecentExtendedSessionListView* pDefaultExtendView = new RecentExtendedSessionListView(m_pContainer->getExtendPanelStacked());
			pDefaultExtendView->setLindedId(sDefaultExtendPanel);

			m_pContainer->getExtendPanelStacked()->addWidget(pDefaultExtendView);
			m_pContainer->getExtendPanelStacked()->setCurrentWidget(pDefaultExtendView);
			bindExtendListViewEvents(pDefaultExtendView);
			m_jid2ExtendListView.insert(sDefaultExtendPanel,pDefaultExtendView);
		}


		int nCount =  getBaseChatDialogCount();


		Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
		int limit = settingconfig->MaxSessionLimited();
		int tmpCount = imSessions.length()>limit?limit:imSessions.length();
		QList<Biz::ImSession> limitedSession = imSessions.mid(0,tmpCount);

		QMap<QString,int> cidUnreadCntMapping;
		QMap<QString,quint64> cidLastTimeMapping;

		foreach(Biz::ImSession imSession,limitedSession)
		{
			QString conversationId = "";
			if (Biz::headline == imSession.chatType 
				|| Biz::MessageUtil::compareUserId(Util::NEWS_DIALOG_ID,imSession.xmppid)
				)
			{

				conversationId = Biz::MessageUtil::makeSureUserJid(imSession.xmppid);
				addNewsDialogRosterItem(conversationId,MainApp::ConversationController::sDefaultExtendPanel);
				Biz::Session::getConverSationManager()->setLocalCoversationMessageRead(conversationId);
			} 
			else if ( Biz::MessageUtil::compareUserId(Util::SUBSCRIPTIONNUM_ID,imSession.xmppid) )
			{
				continue;
			}
			else if (Biz::ChatMessage == imSession.chatType)
			{
#ifdef QCHAT     //这是为了兼容之前的问题
				if (Biz::MessageUtil::compareUserId("rbt-system",imSession.xmppid) || Biz::MessageUtil::compareUserId("rbt-notice",imSession.xmppid) )
				{
					continue;
				}

#endif // QCHAT
				if (Biz::MessageUtil::compareUserId(imSession.xmppid, Util::COLLECTION_DIALOG_ID))
				{
					continue;
				}
				// 二人
				createSimpleChatItem(imSession);
				conversationId = imSession.xmppid;

				cidLastTimeMapping.insert(imSession.xmppid,0);

			}
			else if (Biz::GroupMessage == imSession.chatType)
			{
				// 群组
				createGroupChatItem(imSession);
				conversationId = imSession.xmppid;
				cidLastTimeMapping.insert(imSession.xmppid,0);
			} 
			else if (Biz::subscription == imSession.chatType)
			{
				conversationId = imSession.xmppid;
				addRobotChatRosterItem(conversationId,MainApp::ConversationController::sDefaultExtendPanel);
				if (Biz::MessageUtil::compareUserId(conversationId, Util::QIANGDAN_DIALOG_ID) && limitedSession.indexOf(imSession) == limitedSession.size()-1)
				{
					m_pContainer->showEmptyChatdialog();
				}
			} 
			else if (Biz::subscription_weidaoyou == imSession.chatType)
			{
				conversationId = imSession.xmppid;
				addRawHtmlItem(conversationId,sDefaultExtendPanel);
			}
			else if (Biz::consult == imSession.chatType)
			{
				QString userName;
				conversationId = imSession.xmppid;
				QString realjid = imSession.realJid;
				QString virtualid = conversationId;
				bool isSeat = Util::UtilHelper::isVirtualAccountId(conversationId, Biz::Session::getSystemConfig()->getXmppDomain());

				if (isSeat)
				{
					virtualid = Util::UtilHelper::getvirtualfromID(conversationId);
					if (virtualid.length()<=0)
					{
						continue;
					}
					QString strRealName = Biz::Session::getUserVcardManager()->getUserNameByConversationId(Util::UtilHelper::getRealIdfromID(conversationId));
					QString strVirtualName = Biz::Session::getUserVcardManager()->getUserNameByConversationId(Util::UtilHelper::getvirtualfromID(conversationId));
#ifdef QCHAT
					userName = QStringLiteral("%1(咨询%2店铺中产品)").arg(strRealName).arg(strVirtualName);
#else
					userName = QString("%1-%2").arg(strVirtualName, strRealName);
#endif // QCHAT
				}
				else
				{
					userName = Biz::Session::currentAccount().getUserNameById(imSession.xmppid);
				}


				// 创建新的会话窗口,先有会话，additem的时候才能自动置顶
				addConsultChatRosterItem(conversationId,MainApp::ConversationController::sDefaultExtendPanel,virtualid,realjid,isSeat);

			}
			else if (Biz::revoke == imSession.chatType)//撤销消息
			{
				continue;
			}
			else if (Biz::collection == imSession.chatType)
			{
				conversationId = imSession.xmppid;
				addColloctionChatRosterItem(conversationId,MainApp::ConversationController::sDefaultExtendPanel);
			}
			else if (Biz::Note == imSession.chatType)
			{
				createSimpleChatItem(imSession);
				conversationId = imSession.xmppid;
				cidLastTimeMapping.insert(imSession.xmppid,0);
			}
			else if (Biz::encrypt == imSession.chatType)
			{
				createSimpleChatItem(imSession);
				conversationId = imSession.xmppid;
				cidLastTimeMapping.insert(imSession.xmppid,0);
			}

			if (!conversationId.isEmpty())
			{
				updateJidLastTimeStamp(conversationId,imSession.lastupdateTime);
				updateSessionConfigration(conversationId,imSession.configration);
				cidUnreadCntMapping.insert(conversationId,imSession.unreadCount);
			}
		}

		onUpdateUnReadCount(cidUnreadCntMapping);
		Biz::Session::getConverSationManager()->updateReadMarkByLastTime(cidLastTimeMapping);

		if (imSessions.size()>0 && !mbActiveItem)
		{
			Biz::ImSession ims = imSessions[0];
			QString imsXmppid = ims.xmppid;
			if (!mNoActiveList.contains(imsXmppid))
			{
				mbActiveItem = true;
				activeConversation(ims.xmppid);
			}
		}
		//将滚动条移动到顶部
		setScolltoTop();

		//拿取最后一条消息
		Biz::Session::getConverSationManager()->getChatingSessionsLastMsg();

		
	}

	void ConversationController::loadTopAndUnreadConversations()
	{
		Biz::UnitCallback<QList<Biz::ImSession>>* callback =
			createCallback<QList<Biz::ImSession>>(
			[this](const QList<Biz::ImSession>& imsessions) {
				this->clearAllConversation();
				this->onRecentImSessionRecv(imsessions);
		},[]{});
		Biz::Session::getConverSationManager()->loadTopAndUnreadConversations(callback);
	}

	void ConversationController::loadAllChattingConversation()
	{
		Biz::UnitCallback<QList<Biz::ImSession>>* callback =
			createCallback<QList<Biz::ImSession>>(
			[this](const QList<Biz::ImSession>& imsessions) {
				this->clearAllConversation();
				this->onRecentImSessionRecv(imsessions);
		},[]{});
		Biz::Session::getConverSationManager()->loadAllChattingConversation(callback);
	}

	int ConversationController::getCouversationCount()
	{
		int totle = 0;
		for (RecentExtendedSessionListView* pextendView : m_jid2ExtendView.values())
		{
			QStringList strkey = m_jid2ExtendView.keys();
			QString strkeyval = m_jid2ExtendView.key(pextendView);
			if (NULL!=pextendView && NULL!=pextendView->getRosterListView() && (m_jid2ExtendView.size()>1 ? strkeyval == sDefaultExtendPanel:true))
			{
				totle += pextendView->getRosterListView()->count();
			}
		}

		return totle;
	}


	void ConversationController::addBaseChatDialog(const QString& conversationId, BaseChatDialog* pDialog)
	{
		m_conversationId2DialogMap.insert(conversationId,pDialog);
		m_queueBaseChatDialogs.push_front(pDialog);

		m_pContainer->getBaseChatDialogStatckWidget()->addWidget(pDialog);

		if (Biz::Session::getEditableSettings()->LimitMaxBasechatDialogCount())
		{
			QList<BaseChatDialog*> pBaseChatDialogList = m_queueBaseChatDialogs;
			if (pBaseChatDialogList.size()>Biz::Session::getEditableSettings()->LimitMaxBasechatDialogCountN())
			{
				// 删除第sMaxBaseChatDialogLimit个以后的
				while (pBaseChatDialogList.size()>Biz::Session::getEditableSettings()->LimitMaxBasechatDialogCountN())
				{
					BaseChatDialog* pLastChatDialog = pBaseChatDialogList.last();
					pBaseChatDialogList.pop_back();

					QString conversationId = pLastChatDialog->conversationId();

					// 不是顶层的删掉了
					removeBaseChatDialog(conversationId);
				}
			}
		}
	}

	void ConversationController::activeBaseChatDialog(BaseChatDialog* pDialog)
	{
		m_pContainer->showChatDialog(pDialog);

		if (m_queueBaseChatDialogs.contains(pDialog))
		{
			BaseChatDialog* pBaseChatDialog = pDialog;
			m_queueBaseChatDialogs.removeOne(pBaseChatDialog);
			m_queueBaseChatDialogs.push_front(pDialog);
		}



	}

	void ConversationController::updateNoticetip( const QString& conversationId, const ConversationListWidget* rosterlistwidget )
	{
		if (conversationId.contains("@"))
		{
			Biz::GroupListData *gld = Biz::Session::currentAccount().getGroupsData();
			if (NULL != gld)
			{
				Biz::GroupSetting* pgs = gld->getGroupSetting(conversationId);
				if (NULL!=pgs)
				{
					int optionNitice = pgs->GroupMsgNoticeOption();

					if(Biz::GroupSetting::RECV_WITHOUT_NOTICE == (Biz::GroupSetting::RECV_WITHOUT_NOTICE&optionNitice))
					{
						Biz::Session::getConverSationManager()->updateRecentImSessionMsgNotice(conversationId,Biz::SESSION_CFG_SILENCE,0);
						((ConversationListWidget*)rosterlistwidget)->updateNoticeTip(conversationId, optionNitice);
					}

				}
			}
		}
	}

	void ConversationController::shouldOverrideUrlLoading(const QUrl& url)
	{
		//localscheme://windows.robot.deal?param=json
		do 
		{
			if ("localscheme" == url.scheme())
			{
				QString path = url.host();
				if ("windows.robot.deal" == url.host())
				{
					QUrlQuery quq(url);
					QString strJsonParmm = quq.queryItemValue("param");
					QJsonDocument doc = QJsonDocument::fromJson(strJsonParmm.toUtf8());
					QString msgid = doc.toVariant().toMap().value("msgid").toString();
					if (!msgid.isEmpty())
					{
						auto callback = createCallback<QSharedPointer<Biz::XmppMessage>>(
							[this,msgid](const QSharedPointer<Biz::XmppMessage>& spMessage){
								if (!spMessage.isNull())
								{
									QString strJsonData = spMessage->ExtendInfo();
									QVariantMap jsonMap = QJsonDocument::fromJson(strJsonData.toUtf8()).toVariant().toMap();

									QString dealurl     = jsonMap.value("dealurl").toString();
									QString dealid      = jsonMap.value("dealid").toString();
									int nTimeOut        = jsonMap.value("timeout").toInt();
									if (!dealurl.isEmpty())
									{
										if (0==nTimeOut)
											nTimeOut = 20;
										// 出会话block


										// 抢单url给增加个qchatid
										QUrl url(dealurl);
										QUrlQuery quq(url);
										quq.addQueryItem("qchat_id",
											Biz::MessageUtil::makeSureUserJid(
											Biz::Session::getAccountManager()->accountData().UserID()));
										url.setQuery(quq);


										auto callback = createCallback<QString>([this,spMessage,dealid,nTimeOut,msgid](const QString& result){
											QJsonDocument doc = QJsonDocument::fromJson(result.toUtf8());

											QVariantMap resultMap = doc.toVariant().toMap();
											if (resultMap.contains("ret")&&!resultMap.value("ret").toInt())
											{
												QString errMsg = QStringLiteral("请求失败");
												if (resultMap.contains("error_msg")&&!resultMap.value("error_msg").isNull())
													errMsg = resultMap.value("error_msg").toString();
												// 自己给自己发一条消息
												QSharedPointer<Biz::XmppMessage> errmessage(new Biz::XmppMessage(spMessage->ConversationID()));
												errmessage->ChannelId(spMessage->ChannelId());
												errmessage->MsgSourceType(spMessage->MsgSourceType());
												errmessage->MediaType(Biz::MediaTypeRobotNotice);
												errmessage->MessageID(QUuid::createUuid().toString().replace("{", "").replace("}", "").replace("-", ""));

												errmessage->UtcTime(QDateTime::currentMSecsSinceEpoch()-Biz::Session::currentAccount().getTimeOffsetFromServer());
												QJsonObject obj;
												obj.insert("result",0);
												obj.insert("errorinfo",errMsg);
												obj.insert("dealid",dealid);
												obj.insert("localmessage",true);
												QString extenInfo = QJsonDocument(obj).toJson(QJsonDocument::Compact);
												errmessage->ExtendInfo(extenInfo);
												errmessage->Body(extenInfo);

												Biz::Session::getRobotManager()->patchALocalMessage(errmessage);
											}
											else
											{
												QString conversationId = spMessage->ConversationID();
												MenuRobotDialog* pRobotDialog = dynamic_cast<MenuRobotDialog*>(
													findConversationBaseChatDialog(conversationId));
												if (NULL!=pRobotDialog)
													pRobotDialog->setRobotDealBlock(nTimeOut,msgid);
											}

										},[]{});

										// 抢单
										Biz::Session::getConverSationManager()->dealWechatDeal(url,callback);
									}
								}
						},[]{});
						Biz::Session::getConverSationManager()->getMessageByIdAsync(msgid,callback);
						break;
					}
				}
			}
		} while (false);
	}

	void ConversationController::setChatDialogRightPanelVisible(bool show)
	{
		for (BaseChatDialog* pDialog:m_conversationId2DialogMap)
		{
			ChatDialog* pChatDialog = dynamic_cast<ChatDialog*>(pDialog);
			if (NULL!=pChatDialog)
			{
				show ? pChatDialog->showRightExtendPanel() : pChatDialog->hideRightExtendPanel();
			}
		}
	}

	void ConversationController::onSubscriptMessageRecveid(const QSharedPointer<Biz::XmppMessage>& spMessage)
	{
		if (!spMessage.isNull() 
			&& Biz::MediaTypeRobotNotice == spMessage->MediaType() 
			&& Biz::subscription == spMessage->MsgSourceType())
		{

			QString notice = spMessage->ExtendInfo();

			QJsonDocument doc = QJsonDocument::fromJson(notice.toUtf8());
			QVariantMap paramMap = doc.toVariant().toMap();
			if (paramMap.contains("result"))
			{
				bool bResult = paramMap.value("result").toBool();
				QString reusltText = paramMap.value("errorinfo").toString();

				QString dealid = paramMap.value("dealid").toString();
				if (bResult)
				{
					// 解析出临时名片，存储起来,并且发起会话
					QString userjid = paramMap.value("sessionid").toString();

					if (!userjid.isEmpty())
					{
						userjid = Biz::MessageUtil::makeSureUserJid(userjid);
						QString displayName = paramMap.value("nickname").toString();
						QSharedPointer<Biz::ImSelfPerson> spPerson(new Biz::ImSelfPerson);
						spPerson->strUserId = userjid;
						spPerson->strNickName = displayName;
						Biz::Session::getUserVcardManager()->addUserVcard(spPerson);

						QString channelId = spMessage->ChannelId();

						// 当前当前显示了block界面， 500毫秒后发生跳转
						QTimeLine* pDetailOpen = new QTimeLine(500);
						connect(pDetailOpen,&QTimeLine::finished,[this,pDetailOpen,userjid,channelId]{


							pDetailOpen->deleteLater();
							MainApp::UIFrame::getConversationController()->addSimpleChatRosterItem(userjid
								,ConversationController::sDefaultExtendPanel);
							MainApp::UIFrame::getConversationController()->activeConversation(userjid);
							MainApp::UIFrame::getConversationController()->moveSessionToTop(userjid);
							MainApp::UIFrame::getConversationController()->updateConversationChannelId(userjid,channelId);

						});
						pDetailOpen->start();
					}
				}
			}
		}
	}

	quint64 ConversationController::getConversationChatId(const QString& conversationId)
	{
		ConsultChatDialog* pDialog = dynamic_cast<ConsultChatDialog*>(findConversationBaseChatDialog(conversationId));
		if (NULL!=pDialog)
		{
			return pDialog->getChatId().toULongLong();
		}
		return 0;
	}

	void ConversationController::onShowAdvWidget(const QList<QSharedPointer<Biz::AdvDataItem>>& imagelist)
	{
		if (NULL!=m_pContainer)
		{
			m_pContainer->openAdvWidget(imagelist);
		}
	}

	void ConversationController::onCloseAdvWidget()
	{
		if (NULL!=m_pContainer)
		{
			m_pContainer->closeAdvWidget();
		}
	}


	void ConversationController::onDisconnect()
	{
#if 0
		// 断线之后关闭所有会话框体验不是很好，先凭吊 2016年7月27日
		for (QString uid: m_conversationId2DialogMap.keys())
		{
			removeBaseChatDialog(uid);
		}
		m_pContainer->showEmptyChatdialog();
#endif
	}

	void ConversationController::setScolltoTop()
	{
		RecentExtendedSessionListView* pExtendView = getExtendedSessionListView(MainApp::ConversationController::sDefaultExtendPanel);
		Q_ASSERT(NULL!=pExtendView);
		if (NULL == pExtendView)
			return;
		pExtendView->getRosterListView()->autoscrolltoTop();
	}

	void ConversationController::onConversationReadedByOtherClient(const QString& conversationid,quint64 ulLastTimeInDb)
	{
		this->clearAtNotice(conversationid);
	}

	void ConversationController::onAllConversationReadedByOtherClient(quint64 ulLastTimeInDb)
	{
		for (QString cid : m_jid2ExtendView.keys ())
		{
			if (!cid.isEmpty())
			{
				this->clearAtNotice(cid);
			}
		}
	}

	bool ConversationController::IsUserIdInAllRobotList( const QString& userid )
	{
		return m_AllRobotIdList.contains(Biz::MessageUtil::makeSureUserId(userid))?true:false;
	}

	void ConversationController::onAllRobotIdList( const QStringList& robotlist )
	{
		m_AllRobotIdList = robotlist;
	}

	void ConversationController::onAtMessageFindInUnreadMessage(const QString& conversationID,QSharedPointer<Biz::XmppMessage> spmessage)
	{
		if (spmessage.isNull())
		{
			return;
		}
		if (Biz::AtOne == Biz::MessageUtil::chargeIsAtNotice(spmessage))
		{
			MainApp::UIFrame::getConversationController()->increaseAtNotice(conversationID,1,Biz::AtOne);
			MainApp::UIFrame::getConversationController()->addAtInfor(conversationID, spmessage->SenderJid(), spmessage->MessageID());
		}

		if (Biz::AtAll == Biz::MessageUtil::chargeIsAtNotice(spmessage))
		{
			QString strdisplay = Biz::Session::currentAccount().getUserNameById(spmessage->SenderJid());
			MainApp::UIFrame::getConversationController()->increaseAtNotice(conversationID,1,Biz::AtAll,strdisplay);
			MainApp::UIFrame::getConversationController()->addAtInfor(conversationID, spmessage->SenderJid(), spmessage->MessageID());

		}
	}

	void ConversationController::showFriendDetailInfoPage(const QString& jid, bool btype)
	{
		if (NULL!=m_pContainer&&!jid.isEmpty())
		{
			m_pContainer->onFriendsUserAttached (jid, btype);
		}
	}

	void ConversationController::showEmptyPage()
	{
		if (NULL!=m_pContainer)
		{
			m_pContainer->showEmptyChatdialog ();
		}
	}

	void ConversationController::showGroupDetailInfoPage( const QString&jid )
	{
		if (NULL != m_pContainer && !jid.isEmpty())
		{
			m_pContainer->onJiagouGroupAttached(jid);
		}
	}


	void ConversationController::insertChatIdVerinfo( const QString&id , const QString& version )
	{
		mChatidVersionInfomap.insert(id, version);
	}

	QString ConversationController::getVerinfobychatId( const QString& id )
	{
		if (id.isEmpty())
		{
			return "";
		}
		if (mChatidVersionInfomap.contains(id))
		{
			return mChatidVersionInfomap.value(id);
		}
		else
			return "";
	}

	void ConversationController::insertchatingvraccount( const QString&conversaionId, const QString& vraccountId )
	{
		if (vraccountId.isEmpty())
		{
			return;
		}
		mChatidvraccountmap.insert(conversaionId, vraccountId);
	}

	QString ConversationController::getvraccountbychating( const QString& conversationId )
	{
		if(mChatidvraccountmap.contains(conversationId))
			return mChatidvraccountmap.value(conversationId);
		else
			return "";
	}

	void ConversationController::insertVidioChat(const QString& id, VidioAndAudioDialog* dlg)
	{
		if (!m_Vidiomapmap.contains(id) && dlg != NULL)
		{
			m_Vidiomapmap.insert(id, dlg);
		}
	}

	VidioAndAudioDialog * ConversationController::getVidioChatById(const QString& id)
	{
		if (!m_Vidiomapmap.contains(id))
		{
			VidioAndAudioDialog * dlg = new VidioAndAudioDialog();
			if (dlg)
			{
				m_Vidiomapmap.insert(id, dlg);
			}
		}
		return m_Vidiomapmap.value(id);
	}

	void ConversationController::deleteVidioChatById(const QString& id)
	{
		//map中删除
		if (m_Vidiomapmap.contains(id))
		{
			m_Vidiomapmap.remove(id);
		}

	}

	bool ConversationController::IsVidioChatExist(const QString& id)
	{
		return m_Vidiomapmap.contains(id) ? true : false;
	}

	void ConversationController::updateWillSend( const QString& conversationId, const QSharedPointer<MimeTypeMessage>& willsendmsg )
	{
		m_willSendMsg.insert(conversationId, willsendmsg);
	}

	QSharedPointer<MimeTypeMessage> ConversationController::getWillSend( const QString& conversationId )
	{
		QSharedPointer<MimeTypeMessage> retmsg(new MimeTypeMessage);

		if ( m_willSendMsg.contains(conversationId))
		{

			retmsg = m_willSendMsg.value(conversationId);
		}
		return retmsg;
	}

	bool ConversationController::getTransferShopValuebyId( const QString& id )
	{
		if (id.isEmpty())
		{
			return false;
		}
		if (mTransReplayvaluemap.contains(id))
		{
			QSharedPointer<Biz::TransReplyValue> trsvalue= mTransReplayvaluemap.value(id);
			if (!trsvalue.isNull())
			{
				return  trsvalue->ReplayShopvalue ;
			}
			else
				return  false;
		}
		else
			return false;
	}

	bool ConversationController::getTransferVisitorValuebyId( const QString& id )
	{
		if (id.isEmpty())
		{
			return false;
		}
		if (mTransReplayvaluemap.contains(id))
		{
			QSharedPointer<Biz::TransReplyValue> trsvalue= mTransReplayvaluemap.value(id);
			if (!trsvalue.isNull())
			{
				return trsvalue->ReplayVisitorvalue;
			}
			return false;
		}
		else
			return false;
	}

	void ConversationController::showAtInfoBlockByConversation( const QString& conversationID, const QString& atmsgId )
	{
		if (hasConversation(conversationID))
		{
			//屏蔽这地方的理由是，离线接到消息后，
			//上线后，发现有些item中未读消息无前面小红点
			emit sgConversationActived(conversationID);
			QString lastConversionID = topConversationId();
			if (conversationID!=lastConversionID)
				emit sgCurrentConversationChange(conversationID,lastConversionID);


			QString extendId = getConversationsExtendId(conversationID);
			Q_ASSERT(NULL!=m_pContainer);
			RecentExtendedSessionListView* pExtendView = getExtendedSessionListView(extendId);
			Q_ASSERT(NULL!=pExtendView);

			if (NULL == pExtendView)
				return;

			pExtendView->getRosterListView()->activityChatDialog(conversationID);

			// 群组
			if (pExtendView->getRosterListView()->isGroupChatItem(conversationID))
			{
				BaseChatDialog* pDialog = createNewGroupChatDialog(conversationID);
				activeBaseChatDialog(pDialog);

				QString title = Biz::Session::getGroupManager()->getGroupNickName(conversationID);
				MainApp::UIFrame::getMainDialogController()->setMainDialogTitle(title);
				pDialog->showAtBlock(conversationID, atmsgId);
			}



			// 			MainApp::UIFrame::getMainDialogController()->activeChatsTab();
			// 			activeLinkedPannel(pExtendView->getLindedId(),false);

		}
	}

	void ConversationController::onTransReplay( const QString&conversationId, int type )
	{
		if (conversationId.isEmpty())
		{
			return;
		}
		QSharedPointer <Biz::TransReplyValue> trsvalue(new Biz::TransReplyValue);
		if (mTransReplayvaluemap.contains(conversationId))
		{
			trsvalue = mTransReplayvaluemap.value(conversationId);
		}
		if (type == Biz::ReplayShop)
		{
			//
			trsvalue->ReplayShopvalue = true;
		}
		else if (type == Biz::ReplayVisitor)
		{
			trsvalue->ReplayVisitorvalue = true;
		}

		mTransReplayvaluemap.insert(conversationId, trsvalue);

	}


	void ConversationController::onRemoveRecentItem( const QString&jid )
	{
		removeConversation(jid);
	}

	QString ConversationController::getcctextbyconversationId( const QString& conversationId )
	{
		ChatDialog* pDialog = dynamic_cast<ChatDialog*>(findConversationBaseChatDialog(conversationId));
		if (NULL!=pDialog)
		{
			return pDialog->getcctext();
		}
		return "";
	}

	QString ConversationController::getbubyconversationId( const QString&conversationId )
	{
		ChatDialog* pDialog = dynamic_cast<ChatDialog*>(findConversationBaseChatDialog(conversationId));
		if (NULL!=pDialog)
		{
			return pDialog->getbu();
		}
		return "";
	}

	QString ConversationController::getProductId( const QString& conversationId )
	{
		ChatDialog* pDialog = dynamic_cast<ChatDialog*>(findConversationBaseChatDialog(conversationId));
		if (NULL!=pDialog)
		{
			return pDialog->getProductId();
		}
		return "";
	}

	QString ConversationController::getbusinessline( const QString& conversationId )
	{
		ChatDialog* pDialog = dynamic_cast<ChatDialog*>(findConversationBaseChatDialog(conversationId));
		if (NULL!=pDialog)
		{
			return pDialog->getbusinessline();
		}
		return "";
	}

	void ConversationController::createSimpleChatItem( const Biz::ImSession& imSession )
	{
		QString userName = Biz::Session::currentAccount().getUserNameById(imSession.xmppid);

		QString conversationId = imSession.xmppid;
		// 创建新的会话窗口,先有会话，additem的时候才能自动置顶
		addSimpleChatRosterItem(conversationId,MainApp::ConversationController::sDefaultExtendPanel);
	}


	void ConversationController::createGroupChatItem( const Biz::ImSession& imSession )
	{
		QString dispalyName = imSession.xmppid;
		dispalyName = Biz::Session::currentAccount().getGroupNickName(imSession.xmppid);
		if (dispalyName.isEmpty())
		{
			dispalyName = imSession.xmppid;
		}

		addGroupChatRosterItem(imSession.xmppid,MainApp::ConversationController::sDefaultExtendPanel);

		
	}


	void ConversationController::doGetZhongbaoParam( const QString&conversationId )
	{
		//
		auto cbSuccess  = [this, conversationId](const QString& param){
			if (!param.isEmpty())
			{

				mZhongbaoParam.insert(conversationId, param);

			}
		};
		auto cbFail     = [this]{

		};
		auto callback = createCallback<QString> (cbSuccess,cbFail);

		Biz::Session::getConverSationManager ()->getZhongbaoparam(conversationId, callback);
	}

	void ConversationController::onGroupCoverAdd( const QString&jid )
	{
		if (jid.isEmpty())
		{
			return;
		}

		QString dispalyName = jid;
		dispalyName = Biz::Session::currentAccount().getGroupNickName(jid);
		if (dispalyName.isEmpty())
		{
			dispalyName = Biz::MessageUtil::makeSureGroupId(jid);
		}

		addGroupChatRosterItem(jid,MainApp::ConversationController::sDefaultExtendPanel);

		updateJidLastTimeStamp(jid, QDateTime::currentMSecsSinceEpoch() - Biz::Session::currentAccount().getTimeOffsetFromServer());

		QMap<QString,quint64> params;
		params.insert(jid,0);

		Biz::Session::getConverSationManager()->updateReadMarkByLastTime(params);
	}
	void ConversationController::collectLogsandSend()
	{
		//先通过另启动线程，进行收集，收集完后，返回path
		auto cbSuccess  = [this](const QString& strfilePath){
			if (!strfilePath.isEmpty())
			{
				Biz::Session::getAccountManager()->sgcollectLogsInfo(QStringLiteral("开始准备发送日志文件..."));
				Biz::EditableSettings *peditSetting = Biz::Session::getEditableSettings();
				QString strLoginRecived = peditSetting->DefaultLogRecived();

				BaseChatDialog* pDialog = MainApp::UIFrame::getConversationController()->findConversationBaseChatDialog(strLoginRecived);
				if (NULL==pDialog)
				{
					pDialog = createNewChatDialog(strLoginRecived);
				}
				pDialog->onSendFile(strfilePath);
			}
		};
		auto cbFail     = [this]{

		};
		auto callback = createCallback<QString> (cbSuccess,cbFail);

		Biz::Session::getAccountManager ()->collectLogs(callback);
	}

	void ConversationController::collectLogsandSendEmail()
	{
		//先通过另启动线程，进行收集，收集完后，返回path
		auto cbSuccess  = [this](const QString& strfilePath){
			if (!strfilePath.isEmpty())
			{
				Biz::Session::getAccountManager()->sgcollectLogsInfo(QStringLiteral("开始准备发送日志文件..."));
				Biz::EditableSettings *peditSetting = Biz::Session::getEditableSettings();
				QString strLoginRecived = peditSetting->DefaultLogRecived();

				BaseChatDialog* pDialog = MainApp::UIFrame::getConversationController()->findConversationBaseChatDialog(strLoginRecived);
				if (NULL==pDialog)
				{
					pDialog = createNewChatDialog(strLoginRecived);
				}
				pDialog->onSendFile(strfilePath);
			}
		};
		auto cbFail     = [this]{

		};
		auto callback = createCallback<QString> (cbSuccess,cbFail);

		Biz::Session::getAccountManager ()->collectLogs(callback);
	}

	void ConversationController::setAskIds( const QStringList& list )
	{
		m_AskerIds = list;
	}

	bool ConversationController::IsAccountInAskIds( const QString& id )
	{
		if (id.isEmpty())
		{
			return false;
		}
		return m_AskerIds.contains(id)?true:false;
	}

	void ConversationController::onSelfConversationKey( const QString&key )
	{
		mSelfConversationKey = key;
	}

	bool ConversationController::isConversationPwd()
	{
		if (mSelfConversationKey.isEmpty())
		{
			return false;
		}
		else 
			return true;
	}

	QString ConversationController::getConversationKey()
	{
		return mSelfConversationKey;
	}

	void ConversationController::activeCollectionConversation(const QString& parentId, const QString& conversationId )
	{
		if (conversationId.isEmpty())
		{
			return;
		}

		BaseChatDialog* pDialog = createNewMenuChatDialog(conversationId, CollectionChatType);
		if(pDialog)
		{
			pDialog->SetParentId(parentId);
			activeBaseChatDialog(pDialog);
		}

	}

	void ConversationController::activeCollectionUser( const QString&bindUser )
	{
		if (bindUser.isEmpty())
		{
			return;
		}

		m_pContainer->showCollectionBindUserInfo(bindUser);
	}

	void ConversationController::onEncryptEvent( int type, const QString&infor,const QString& conversationId )
	{
		if (conversationId.isEmpty())
		{
			return;
		}

		BaseChatDialog* pDialog = MainApp::UIFrame::getConversationController()->findConversationBaseChatDialog(conversationId);
		if (NULL==pDialog)
		{
			pDialog = createNewChatDialog(conversationId);
		}

		if (type == Biz::EncryptMessageType::EncryptMessageType_Begin)
		{

			if ( MainApp::UIFrame::getNotifyCenterController ()->alertMessage(QStringLiteral("加密会话"),QStringLiteral("是否同意加密会话？")
				,QStringLiteral("拒绝"),QStringLiteral("同意")) )
			{



				pDialog->onSendMessage(QStringLiteral("同意"), Biz::EncryptMessageType::EncryptMessageType_Agree, conversationId);

				//同意了，这个时候，需要保存密码
				//存放在服务器和本地
				QJsonParseError Json_Parse_Error;
				QJsonDocument Json_Data = QJsonDocument::fromJson(infor.toUtf8(),&Json_Parse_Error);
				if(Json_Parse_Error.error == QJsonParseError::NoError)
				{
					QVariantMap dataMap = Json_Data.toVariant().toMap();
					QString strPwd = dataMap["pwd"].toString();

					QString strdesc = QStringLiteral("与%1的会话密码").arg(Biz::Session::getUserVcardManager()->getUserNameByConversationId(conversationId));
					Biz::Session::getqCloudManager()->setSaveqcloudSunInfo(conversationId, QStringLiteral("会话密码"), strPwd,100, NULL);
				}

			}
			else
			{
				pDialog->onSendMessage(QStringLiteral("拒绝"), Biz::EncryptMessageType::EncryptMessageType_Refuse, conversationId);
			}
		}
		else if (type == Biz::EncryptMessageType::EncryptMessageType_Agree)
		{

			QString strdisplay = Biz::Session::getUserVcardManager()->getUserNameByConversationId(conversationId);
			if (strdisplay.isEmpty())
			{
				strdisplay = conversationId;
			}
			QString strInfo= QStringLiteral("[%1]同意加密会话!").arg(strdisplay);

			MainApp::UIFrame::getEncryptChatcontroller()->sgEncryptResponeInfor(ResponeArgee, conversationId, strInfo);

		}
		else if (type == Biz::EncryptMessageType::EncryptMessageType_Refuse)
		{
			QString strdisplay = Biz::Session::getUserVcardManager()->getUserNameByConversationId(conversationId);
			if (strdisplay.isEmpty())
			{
				strdisplay = conversationId;
			}
			QString strInfo= QStringLiteral("[%1]拒绝加密会话!").arg(strdisplay);

			MainApp::UIFrame::getEncryptChatcontroller()->sgEncryptResponeInfor(ResponeRefuse, conversationId, strInfo);

			//如果拒绝，那么需要把内存中的子密码给删除
			deleteEncrypt(conversationId);
		}
		else if (type == Biz::EncryptMessageType::EncryptMessageType_Cancel)
		{
			deleteEncrypt(conversationId);
			QString strdisplay = Biz::Session::getUserVcardManager()->getUserNameByConversationId(conversationId);
			if (strdisplay.isEmpty())
			{
				strdisplay = conversationId;
			}
			QString strInfo= QStringLiteral("[%1]取消加密会话!").arg(strdisplay);
		}
		else if (type == Biz::EncryptMessageType::EncryptMessageType_Close)
		{
			QString strdisplay = Biz::Session::getUserVcardManager()->getUserNameByConversationId(conversationId);
			if (strdisplay.isEmpty())
			{
				strdisplay = conversationId;
			}
			QString strInfo= QStringLiteral("[%1]关闭加密会话!").arg(strdisplay);
			MainApp::UIFrame::getNotifyCenterController ()->popupConversationNotice (strInfo, conversationId);
			deleteEncrypt(conversationId);
		}

	}

	void ConversationController::onShowEmpty( const QString& conversationId )
	{
		m_pContainer->showEmptyChatdialog();

		if (Biz::MessageUtil::compareUserId(conversationId, Util::QIANGDAN_DIALOG_ID))
		{
			//然后弹一个
			CommentWebViewSingleton::getInstance()->showQiangdanDlg();
		}
		// 		else if (Biz::MessageUtil::compareUserId(conversationId, Util::ZHONGBAO_DIALOG_ID))
		// 		{
		// 
		// 			//然后弹一个
		// 			CommentWebViewSingleton::getInstance()->showZhongbaoDlg();
		// 		}



	}

	void ConversationController::addEncrypt( const QString&conversationId, const QString& encryptpwd )
	{
		if (!mEncryptChat.contains(conversationId))
		{
			mEncryptChat.insert(conversationId, encryptpwd);
		}
	}

	void ConversationController::deleteEncrypt( const QString& conversationId )
	{
		if (mEncryptChat.contains(conversationId))
		{
			mEncryptChat.remove(conversationId);
		}
	}

	QString ConversationController::getEncryptPwdbyconversationId( const QString& conversationId )
	{
		if (mEncryptChat.contains(conversationId))
		{
			return mEncryptChat.value(conversationId);
		}
		return QString("");
	}

	void ConversationController::doCreateChatDialog( const QString&userid, const QString&ExtendInfor )
	{
		QString userName = Biz::Session::currentAccount().getUserNameById(userid);

		QString conversationId = userid;
		// 创建新的会话窗口,先有会话，additem的时候才能自动置顶
		addSimpleChatRosterItem(conversationId,MainApp::ConversationController::sDefaultExtendPanel);

		activeConversation(userid);
	}

	QString ConversationController::doGetZhongbaoparamByconversationId( const QString& id )
	{
		QString strRetparam;
		if (mZhongbaoParam.contains(id))
		{
			strRetparam = mZhongbaoParam.value(id);
		}

		return strRetparam;

	}

	void ConversationController::setZhongbaoInfor(const QString&id, const QString&infor )
	{

		Biz::Session::getConverSationManager()->setZhongbaoInfor(id,infor);
	}

	void ConversationController::addColloctionChatRosterItem( const QString& conversationId,const QString& extendId )
	{
		Q_UNUSED(extendId);

		QSharedPointer<Biz::ImSelfPerson> spUserVcard
			= Biz::Session::getUserVcardManager()->userVcard(Biz::MessageUtil::makeSureUserId(conversationId));

		bool bPackage = true;
		if (!spUserVcard.isNull())
		{
			Biz::Session::getUserVcardManager()->getDomainUsersVcardByVersionandImage(QStringList(conversationId));
		}

		QString belongExtendName = Biz::Session::getUserVcardManager()->getUserNameByConversationId(conversationId);


		if (hasNewExtendedListView(conversationId))
			return;

		RecentExtendedSessionListView* pBelongExtendView = getExtendedSessionListView(sDefaultExtendPanel);
		if (NULL == pBelongExtendView)
			return;

		// 先创建一个扇出对象
		CollectionExtendedListView* pExtendView = new CollectionExtendedListView(m_pContainer);
		m_pContainer->getExtendPanelStacked()->addWidget(pExtendView);

		pExtendView->setBelongExtendid(sDefaultExtendPanel);
		pExtendView->setLindedId(conversationId);
		pExtendView->setExtendTitleVisable(true);
		pExtendView->setExtendTitle(belongExtendName);
		m_jid2ExtendListView.insert(conversationId,pExtendView);
		bindExtendListViewEvents(pExtendView);

		pBelongExtendView->getRosterListView()->addLinkItem(conversationId,belongExtendName,sDefaultExtendPanel);

		m_pContainer->updateConversationCountTip(getCouversationCount());


	}

	void ConversationController::onRectChatLastMsg( const QSharedPointer<Biz::MessageListData>& listmsg )
	{
		if (listmsg.isNull() || listmsg->getMessageList().size() <=0)
		{
			return;
		}

		for(QSharedPointer<Biz::XmppMessage> msg : listmsg->getMessageList())
		{
			if (!msg.isNull())
			{
				QString conversationId = msg->ConversationID();

				RecentExtendedSessionListView* pExtendView = getExtendedSessionListView(sDefaultExtendPanel);
				if (NULL == pExtendView)
					continue;

				bool bret = pExtendView->getRosterListView()->hasCouversation(conversationId);
				if (bret)
				{
					updateChatContent(conversationId, msg);
				}
			}
		}
	}

	void ConversationController::onPresenceOpenChat( const QSharedPointer<Biz::ConversationParam>& spConversationParam, quint64 stime1 )
	{
		Q_UNUSED(stime1);


		if (!spConversationParam.isNull())
		{
			quint64 stime = spConversationParam->timestamp();
			if (stime1<9999999999)
				stime = stime*1000;
			
			if (spConversationParam->type().isEmpty())
			{
				QString jid = spConversationParam->id();

				if (Biz::MessageUtil::isGroupJid(spConversationParam->id()))
				{
					addGroupChatRosterItem(jid,MainApp::ConversationController::sDefaultExtendPanel);
					updateJidLastTimeStamp(jid,stime);
				}
				else 
				{
					addSimpleChatRosterItem(jid,MainApp::ConversationController::sDefaultExtendPanel);
					updateJidLastTimeStamp(jid,stime);
				}
			} else {
				if (Biz::XmppMessage::MessageTypeString_GroupChat == spConversationParam->type() )
				{
					QString jid = spConversationParam->id();
					addGroupChatRosterItem(jid,MainApp::ConversationController::sDefaultExtendPanel);
					// 消息中的时间戳有问题 替换为本地时间戳
					updateJidLastTimeStamp(jid, QDateTime::currentMSecsSinceEpoch());
				} 
				else if (Biz::XmppMessage::MessageTypeString_Chat == spConversationParam->type())
				{
					QString jid = spConversationParam->id();
					addSimpleChatRosterItem(jid,MainApp::ConversationController::sDefaultExtendPanel);
					// 消息中的时间戳有问题 替换为本地时间戳
					updateJidLastTimeStamp(jid, QDateTime::currentMSecsSinceEpoch());
				}
				else if (Biz::XmppMessage::MessageTypeString_Consult == spConversationParam->type())
				{
					if (Biz::consultmsgType::OnDutyToVistor == spConversationParam->qchatid())
					{
						QString virtuanid = spConversationParam->id();
						QString realjid = spConversationParam->realjid();
						QString conversationId = Biz::XmppMessage::makeConsultConversation5Id(realjid,virtuanid);
						addConsultChatRosterItem(conversationId,MainApp::ConversationController::sDefaultExtendPanel,virtuanid,realjid,true);
						updateJidLastTimeStamp(conversationId,stime);
					}
					else {
						QString virtuanid = spConversationParam->id();
						QString realjid = spConversationParam->realjid();

						addConsultChatRosterItem(virtuanid,MainApp::ConversationController::sDefaultExtendPanel,virtuanid,realjid,true);
						updateJidLastTimeStamp(virtuanid,stime);
					}
				}
				else {
					QString jid = spConversationParam->id();
					addSimpleChatRosterItem(jid,MainApp::ConversationController::sDefaultExtendPanel);
					updateJidLastTimeStamp(jid,stime);
				}
			}
		}
	}

	void ConversationController::onPresenceGlobalNotice( const QString& data )
	{
		if (data.isEmpty())
		{
			return;
		}

		QVariantMap bodyJson = QJsonDocument::fromJson(data.toUtf8()).toVariant().toMap();
		QVariantList varlist = bodyJson["noticeStr"].toList();

		if (varlist.size() <= 0)
		{
			return ;
		}

		//	QVariantList varlist = QJsonDocument::fromJson(strUrl.toUtf8()).toVariant().toList();

		QList <QSharedPointer<Biz::NoticeStrInfor>> list;
		for (QVariant varitem: varlist)
		{
			QVariantMap ItemMap = varitem.toMap();
			QSharedPointer<Biz::NoticeStrInfor> notice(new Biz::NoticeStrInfor);
			notice->str( ItemMap["str"].toString());
			notice->type(ItemMap["type"].toString());
			notice->url (ItemMap["url"].toString());
			notice->from(ItemMap["from"].toString());
			notice->to(ItemMap["to"].toString());
			notice->realFrom(ItemMap["realFrom"].toString());
			notice->realTo(ItemMap["realTo"].toString());
			notice->couslt(ItemMap["couslt"].toString());
			notice->strColor(ItemMap["strColor"].toString());
			notice->isCouslt(ItemMap["isCouslt"].toBool());
			list.push_back(notice);
		}


		Q_ASSERT(NULL!=m_pContainer);
		// 全局中找到会话框，都必须有通知提示
		QStringList listIds;
		for (RecentExtendedSessionListView* pExtendView:m_jid2ExtendView.values())
		{
			if (NULL!=pExtendView)
			{
				listIds = pExtendView->getRosterListView()->gethasConversationId();
				break;
			}
		}

		for (QString oneId: listIds)
		{
			if (hasConversation(oneId) && isTopChatDialog(oneId))
			{
				BaseChatDialog* pDialog = MainApp::UIFrame::getConversationController()->findConversationBaseChatDialog(oneId);
				if (NULL!=pDialog)
					pDialog->onShowNotifyInfor(list, GlobalOfTop);
				break;
			}
		}



	}

	void ConversationController::onPresenceAppointNotice( const QString& data )
	{
		if (data.isEmpty())
		{
			return;
		}

		QVariantMap bodyJson = QJsonDocument::fromJson(data.toUtf8()).toVariant().toMap();
		QString strfrom = bodyJson["from"].toString();
		QString strto = bodyJson["to"].toString();
		bool isCouslt = bodyJson["isCouslt"].toBool();
		QString strrealfrom = bodyJson["realFrom"].toString();
		QString strrealto = bodyJson["realTo"].toString();
		QString strcouslt = bodyJson["couslt"].toString();

		QVariantList varlist = bodyJson["noticeStr"].toList();

		if (varlist.size() <= 0)
		{
			return ;
		}

		//	QVariantList varlist = QJsonDocument::fromJson(strUrl.toUtf8()).toVariant().toList();

		QList <QSharedPointer<Biz::NoticeStrInfor>> list;
		for (QVariant varitem: varlist)
		{
			QVariantMap ItemMap = varitem.toMap();
			QSharedPointer<Biz::NoticeStrInfor> notice(new Biz::NoticeStrInfor);
			notice->str( ItemMap["str"].toString());
			notice->type(ItemMap["type"].toString());
			notice->url (ItemMap["url"].toString());
			notice->from(ItemMap["from"].toString());
			notice->to(ItemMap["to"].toString());
			notice->realFrom(ItemMap["realFrom"].toString());
			notice->realTo(ItemMap["realTo"].toString());
			notice->couslt(ItemMap["couslt"].toString());
			notice->strColor(ItemMap["strColor"].toString());
			notice->isCouslt(ItemMap["isCouslt"].toBool());
			list.push_back(notice);
		}


		Q_ASSERT(NULL!=m_pContainer);

		QString strConversationId;
		if (isCouslt)
		{
			if (strcouslt.toInt()== Biz::VistorToOnDuty) // 是客人给客服发的信息
			{
				strConversationId = Biz::XmppMessage::makeConsultConversation5Id(Biz::MessageUtil::makeSureUserJid(strrealfrom),Biz::MessageUtil::makeSureUserJid(strfrom));
			}
			else if (strcouslt.toInt() == Biz::OnDutyToVistor) // 是客服发给客人的信息
			{
				strConversationId = Biz::XmppMessage::makeConsultConversation5Id(Biz::MessageUtil::makeSureUserJid(strfrom),Biz::MessageUtil::makeSureUserJid(strto));
			}

		}
		else
		{
			strConversationId = Biz::MessageUtil::makeSureUserJid(strfrom);
		}

		if (hasConversation(strConversationId) && isTopChatDialog(strConversationId))
		{
			BaseChatDialog* pDialog = MainApp::UIFrame::getConversationController()->findConversationBaseChatDialog(strConversationId);
			if (NULL!=pDialog)
				pDialog->onShowNotifyInfor(list, AppointofBottom);
		}

	}
}
