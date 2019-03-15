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

#include "constants.h"

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
#include "UIFrame.h"
#include "NotifyCenterController.h"

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

//////////////////////////////////////////////////////////////////////////
#include "QMessageBox"

// managers
#include "UserVcardManager.h"
#include "friendsmanager.h"
#include "RobotManager.h"
#include "accountmanager.h"
#include "GroupManager.h"
#include "conversationmanager.h"
#include "staffmanager.h"

// controller
#include "UIFrame.h"
#include "ConversationController.h"
#include "MainDialogController.h"
#include "LoginController.h"

// diywidget
#include "advertinfodialog.h"
#include "RobotSearchView.h"
#include "addfriendanswer.h"
#include "MenuRobotDialog.h"
#include "FriendsExtendPanel.h"
#include "FriendsSearcher.h"
#include "MultiDialogContainer.h"
#include "userprofilewidget.h"
#include "combinationitem.h"

#include "groupquitview.h"

const int CREAT_GROUPCHAT_OPTION_TAB = 0x01;
const int CREAT_GROUPCHAT_OPTION_WINDOW = 0x10;

#include "FriendsSearcher.h"
#include "accountmanager.h"
#include "PlaySound.h"
#include "combinationlistview.h"
#include "combinationcontroller.h"
#include "dataapplication.h"

#include "diywidgit/customviews/qframelayout.h"
#include "Ordermanagedialog.h"
#include "PersonCfgManager.h"
#include "AccountData.h"
#include "editablesettings.h"
#include "setpwdinfor.h"
#include "qcloudmanager.h"

MainWidget::MainWidget()
	: ui(new Ui::MainWidget)
	, mRecentChatMultiDialog(new MultiDialogContainer(this))
	, mPresentWidget(new PresenceChangeWidget(NULL))
	, mcombinationlistview(NULL)
	,mawayTimesNumber(5)
	,mbenablepush(false)
	,mbayway(false)
	,mbSendPush(false)
	,m_label(new QLabel())
	,mactionChatPwd(NULL)
	,mactionPwdBox(NULL)
{
#ifdef _WINDOWS
	shortcutMsg = NULL;
	shortcutscreen = NULL;
	shortcutsearch = NULL;
	shortcutbord = NULL;
#endif // 
	mReceiver = new Biz::CallbackReceiver(this);
	ui->setupUi(this);

	ui->multicontainer_layout->addWidget(mRecentChatMultiDialog.data());

	connect(ui->mainMenuBtn, &QPushButton::pressed, this, &MainWidget::onMainMenuButtonPressed);
	//connect(ui->portrait, &QPushButton::clicked, this, &MainWidget::onPortraitClicked);

	connect(Biz::Session::getUserVcardManager(), &Biz::UserVcardManager::sgPortraitUpdate, this, &MainWidget::onSelfCardUpdate);
	//connect(Biz::Session::getUserVcardManager(), &Biz::UserVcardManager::sgCalculateGroupHeader,this, &MainWidget::calculateGroupImage);

	connect(Biz::Session::getLoginManager(), &Biz::LoginManager::sgConnected, this, &MainWidget::onLoginSucceed);


	initRecentItem();
	initChattingListItem();
	initCombinationListItem();
	initRobotEvent();

	foreach(auto item, tabItems){
		connect(item->btn, &QToolButton::clicked, this, &MainWidget::onTabClicked);
	}

	ui->pbDingdan->setVisible(false);

	m_settingsMenu = new QMenu(ui->mainMenuBtn);

	QAction* addGroup = m_settingsMenu->addAction(QStringLiteral("新建群组"));
	connect(addGroup, SIGNAL(triggered()), SLOT(Action_Menu_addGroup()), Qt::QueuedConnection);

	QAction* searchRbt = m_settingsMenu->addAction(QStringLiteral("查找公众号"));
	connect(searchRbt, &QAction::triggered, this, &MainWidget::onSearchRobot, Qt::QueuedConnection);

	QAction* searchfriends = m_settingsMenu->addAction(QStringLiteral("查找好友"));
	connect(searchfriends, &QAction::triggered, this, &MainWidget::onSearchFriends, Qt::QueuedConnection);

	//     auto actionAbout = m_settingsMenu->addAction(QStringLiteral("关于"));
	//     connect(actionAbout, &QAction::triggered, this, &MainWidget::onAbout, Qt::QueuedConnection);
	//     
#ifndef QCHAT
	auto actionQuitGroup = m_settingsMenu->addAction(QStringLiteral("批量退群"));
	connect(actionQuitGroup, &QAction::triggered, this, &MainWidget::onQuitGroup, Qt::QueuedConnection);

	//m_settingsMenu->addSeparator();

	mactionPwdBox = m_settingsMenu->addAction(QStringLiteral("创建会话密码箱"));
	connect(mactionPwdBox, &QAction::triggered, this, &MainWidget::onCreatePwdBox, Qt::QueuedConnection);

	// 	mactionChatPwd = m_settingsMenu->addAction(QStringLiteral("删除会话密码箱"));
	// 	connect(mactionChatPwd, &QAction::triggered, this, &MainWidget::onDeleteChatPwd, Qt::QueuedConnection);
	//mactionChatPwd->setDisabled(true);


	auto actionCollectionSet = m_settingsMenu->addAction(QStringLiteral("代收设置"));
	connect(actionCollectionSet, &QAction::triggered, this, &MainWidget::onCollectionSet, Qt::QueuedConnection);
#endif // !QCHAT


	m_settingsMenu->addSeparator();

	auto actionLogout = m_settingsMenu->addAction(QStringLiteral("注销"));
	connect(actionLogout, &QAction::triggered, this, &MainWidget::onLogout, Qt::QueuedConnection);

	auto actionQuit =  m_settingsMenu->addAction(QStringLiteral("退出"));
	connect(actionQuit, &QAction::triggered, this, &MainWidget::onQuit, Qt::QueuedConnection);

	ui->chatsbtn->click();
	ui->portrait->installEventFilter(this);

	connect(&NotifyWindow::instance(),&NotifyWindow::sgOpenConversation,this,&MainWidget::onShowRecentWidget);
	connect(mRecentChatMultiDialog.data(), &MultiDialogContainer::sgReConnToServer, this, &MainWidget::onReConnToServer);
	connect(Biz::Session::getLoginManager(), &Biz::LoginManager::sgCheckAutoUpdate, this, &MainWidget::onAutoUpdateVersion);

	//注册热键
	connect(&Biz::Session::currentAccount(), &Biz::Account::sgRegistHotKey, this, &MainWidget::onRegistHotKey);
	connect(&Biz::Session::currentAccount(), &Biz::Account::sgUnRegistHotkey, this, &MainWidget::onUnRegistHotKey);
	connect(UserMiniProfile::getInstance(), &UserMiniProfile::sgSendFile, MainApp::UIFrame::getConversationController(), &MainApp::ConversationController::onSimpleChatDialogSendFile);

	//钩子的热键
	Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
	if (settingconfig->AutoReplyActiveHotKey())
	{
		InitKeyHook();
	}


	this->installEventFilter(this);

	connect(ui->setting,&QPushButton::clicked,[this](bool checked){
		SettingDetail::instance()->showSetting();
	});


	mPresentWidget->setVisible(false);

	connect(mPresentWidget.data(),&PresenceChangeWidget::sgPresenceChange,[this](int i){
		setPresence(i);
	});

	connect(ui->precencebtn,&QPushButton::clicked,[this](bool b){
		QPoint pos = ui->precencebtn->mapToGlobal(QPoint(0,0));
		mPresentWidget->move(pos.x(),pos.y()+16);
		mPresentWidget->setVisible(true);
	});


	//显示自己的图像
	QString userId = Biz::Session::currentAccount().accountData().UserID();
	QPixmap pixmap = Biz::PortraitHelper::getUserPortrait(userId);
	pixmap = QPixmap::fromImage(pixmap.toImage().scaled(ui->portrait->size()));
	ui->portrait->setPixmap(pixmap);
#ifdef QCHAT
	// 	群组的按钮屏蔽掉
	// 	ui->groupbtn->setVisible(false);
	connect(ui->pbDingdan, &QPushButton::clicked, this, &MainWidget::onDingdan);
	ui->pbDingdan->setToolTip(QStringLiteral("订单信息"));
#endif


	connect(&Biz::Session::currentAccount(),&Biz::Account::sgRevokeMessage,this,&MainWidget::onRevokeMessageReceived);
	connect(&Biz::Session::currentAccount(),&Biz::Account::sgWebChatMessageReceivedEx,this,&MainWidget::onWebChatMessageReceivedEx);

	connect(GloableEventObject::getInstance(),&GloableEventObject::sgMainDialogActivitied,[this](bool acti){
		if (acti)
		{
			SystemIcon::instance().stopTrayIcon();
			TrayIconHoverNoticeWidgetSingleton::getInstance()->markAllItemRead();
		}
	});
	connect(TrayIconHoverNoticeWidgetSingleton::getInstance(),&TrayIconHoverNoticeWidget::sgOpenItem,this,&MainWidget::onShowRecentWidget);

	connect(mRecentChatMultiDialog.data(), &MultiDialogContainer::sgResizeMainWidget, [this](bool bret){
		emit sgResizeMainWidget(bret);
	} );

	connect(ui->questionBtn, &QPushButton::clicked, [this](bool bret){
#ifdef QCHAT
		//"http://qt.qunar.com/questions.pdf";
		QString val = Biz::Session::getSystemConfig()->getSimpleapiUrl() + Biz::Session::getEditableSettings()->question(); 
		QDesktopServices::openUrl(QUrl(val));
		onPersonCfgChange();
#else
		//"http://qt.qunar.com/helps/help_win.html?id=1";
		QString val = Biz::Session::getSystemConfig()->getHttpFileHost() + Biz::Session::getEditableSettings()->gethelp();

		CommentWebViewSingleton::getInstance()->openCommonUrl(val);
#endif
	} );

	MainApp::UIFrame::getMainDialogController()->registMainWidget(this);

	connect(MainApp::UIFrame::getCombinationController(), &CombinationController::sgchatsbtn, this, [this]{
		ui->chatsbtn->click();
	});

	connect(MainApp::UIFrame::getCombinationController(), &CombinationController::sgCombinationbtn, this, [this]{
		ui->combinationbtn->click();
	});

	connect(&Biz::Session::currentAccount(), &Biz::Account::sgMessageReceived, this, &MainWidget::onMessageReceived);
	connect(&Biz::Session::currentAccount(), &Biz::Account::sgTypingMessageReceived,this,&MainWidget::onTypingMessageReceived);
	connect(&Biz::Session::currentAccount(), &Biz::Account::sgSystemMessageReceived, this, &MainWidget::onSystemMessageReceived);
	connect(&Biz::Session::currentAccount(), &Biz::Account::sgGroupMessageReceived, this, &MainWidget::onGroupMessageReceived);
	connect(this, &MainWidget::sgGroupMessageReceived, this, &MainWidget::onGroupMessageReceived, Qt::QueuedConnection);


	connect(Biz::Session::getGroupManager(), &Biz::GroupManager::sgDelRegisterReceived,this,&MainWidget::onDelRegisterRecvied);


	QFrameLayout* playout = new QFrameLayout(ui->chatbtnpannel);
	playout->appendWidget (ui->chatsbtn,ALINE_FILL);
	playout->appendWidget (ui->unreadcount,ALINE_RIGHT|ALINE_TOP,QMargins(0,0,0,0));
	playout->appendWidget (ui->unreadpromot, ALINE_RIGHT|ALINE_TOP,QMargins(0,0,8,0));
	ui->chatbtnpannel->setLayout(playout);
	ui->unreadcount->setVisible(false);
	ui->unreadpromot->setVisible(false);
	ui->chatsbtn->installEventFilter(this);
	connect(Biz::Session::getConverSationManager(),&Biz::ConverSationManager::sgAllMessageUnreadCountChanged,this,&MainWidget::onUnreadMsgChanged);

	//组合按钮上需要要显示一个有要处理的工作任务
	QFrameLayout* playoutcombination = new QFrameLayout(ui->combinationPannel);
	playoutcombination->appendWidget (ui->combinationbtn,ALINE_FILL);
	playoutcombination->appendWidget (ui->unreadworksIcon,ALINE_HCENTER|ALINE_TOP,QMargins(7,0,0,0));
	ui->combinationPannel->setLayout(playoutcombination);
	ui->unreadworksIcon->setVisible(false);
	ui->combinationbtn->installEventFilter(this);
	connect(Biz::Session::getStaffManager(),&Biz::StaffManager::sgWorkSpaceWaitCount,this,&MainWidget::onUnreadWorksChanged);

	//setting 按钮上还要放置一个红点，标志有版本需要更新
	QFrameLayout* layoutSetting = new QFrameLayout(ui->setting);
	m_label->setParent(ui->setting);
	m_label->setFixedSize(QSize(28, 28));
	layoutSetting->appendWidget(m_label,AlinementPolicy::ALINE_LEFT| AlinementPolicy::ALINE_VCENTER);//AlinementPolicy::ALINE_TOPLEFT

	connect(Biz::Session::getLoginManager(), &Biz::LoginManager::sgLoginUpdate, this, &MainWidget::OnLoginUpdate);
	connect(Biz::Session::getLoginManager(), &Biz::LoginManager::sgzhuxiao, this, &MainWidget::onZhuxiao);
}

void MainWidget::onUserPresenceChanged(int index)
{
	Biz::Session::currentAccount().setPresence(index);
}
void MainWidget::onPortraitClicked(bool)
{
#ifdef QCHAT

	UserProfileWidgetSingleton::getInstance()->setUser(Biz::Session::getAccountManager()->accountData().UserID())->showNormal();
	UserProfileWidgetSingleton::getInstance()->ShowWidget();
	UserProfileWidgetSingleton::getInstance()->activateWindow();


#else

	UserProfileWidgetSingleton::getInstance()->setUser(Biz::Session::getAccountManager()->accountData().UserID())->showNormal();
	UserProfileWidgetSingleton::getInstance()->activateWindow();
	return;
	QString fileName = QFileDialog::getOpenFileName(this,"","","Images(*.png *.jpeg *.jpg *.tiff, *.gif)");
	if (!fileName.isNull())
	{
		Biz::Session::currentAccount().updateAvatar(Biz::Session::currentAccount().accountData().UserID(), fileName); 
		QPixmap pixmap = Biz::PortraitHelper::loadPixmap(fileName);
		pixmap = QPixmap::fromImage(pixmap.toImage().scaled(ui->portrait->size()));
		ui->portrait->setPixmap(pixmap);
	}
#endif // QCHAT


}
MainWidget::~MainWidget()
{
	delete ui;
	ui = NULL;
	killTimer(mTimerId);
	killTimer(mAwayPrecentTimer);
	qDeleteAll(tabItems);
	tabItems.clear();
	killTimer(mWorkSpaceTimer);

#ifdef _WINDOWS    
	if(shortcutMsg)
	{
		delete shortcutMsg;
		shortcutMsg = NULL;
	}
	if(shortcutscreen)
	{
		delete shortcutscreen;
		shortcutscreen = NULL;
	}
	if(shortcutsearch)
	{
		delete shortcutsearch;
		shortcutsearch = NULL;
	}
	if(shortcutbord)
	{
		delete shortcutbord;
		shortcutbord = NULL;
	}
#endif    
}

void MainWidget::onTabClicked( bool )
{
	auto btn = (StatusButton*)sender();

	QObject();
	foreach(auto item, tabItems)
	{
		item->btn->setChecked(item->btn == btn);
		if(item->btn == btn)
		{
			getLevelStacked()->setCurrentWidget(item->level1);

			if (item->btn == ui->combinationbtn)
			{
				Biz::Session::getStaffManager()->getUserWorkspaceWaitCount();
				mRecentChatMultiDialog->showEmptyChatdialog();
				//这地方调用一下，拉取全量的群列表,每次拉取
				// 				auto callback = mReceiver->createCallback<QStringList>([this](const QStringList& list){
				// 				
				// 				
				// 				//	m_pContainer->showEmptyChatdialog();
				// 				
				// 				},[]{});
				// 				
				// 				Biz::Session::getGroupManager()->getJoinedRoomListOnLogin(callback);
			}
		}
	}
}




/*!
* 功能 :初始化会话列表，左边那竖列的容器
*/
void MainWidget::initChattingListItem()
{
	TabItems* item = new TabItems();
	tabItems.append(item);
	item->btn = ui->chatsbtn;
	item->level1 = mRecentChatMultiDialog->getSessionList();
	getLevelStacked()->setCurrentWidget(mRecentChatMultiDialog->getSessionList());

	item->title = T_("MainWidget_Tab3");
	getLevelStacked()->addWidget(item->level1);
	ui->chatsbtn->setToolTip(T_("MainWidget_Tab3"));
	connect(item->btn,&QPushButton::clicked,mRecentChatMultiDialog.data(),&MultiDialogContainer::onRecentTabShow);

}

/*!
* 功能 :设置会话框的大小
*/
void MainWidget::initRecentItem()
{

	int w = Biz::Session::getSettingConfig()->MultiChatDlgWidth();
	int h = Biz::Session::getSettingConfig()->MultiChatDlgHeight();

	w = w<0?0:w;
	h = h<0?0:h;

	mRecentChatMultiDialog->resize(w,h);
}

/*!
* 功能 : 主窗口订单按钮被电击
*/
void MainWidget::onDingdan()
{
#ifdef QCHAT
	CommentWebViewSingleton::getInstance()->showOrderManageDlg();

	Biz::StaticData::reportTakeCountEvent("10019",1,"GetOrderClicked");
#endif

}



/*!
* 功能 :主窗口设置按钮点击
*/
void MainWidget::onMainMenuButtonPressed()
{
	m_settingsMenu->exec(ui->mainMenuBtn->mapToGlobal(QPoint(0, -1*m_settingsMenu->sizeHint().height())));
}

/*!
* 功能 : 左侧加号->创建群组
*/
void MainWidget::Action_Menu_addGroup()
{
	CreateNewGroup* pdlg = CreateNewGroupSingleton::getInstance();
	if (pdlg)
	{
		auto callback = mReceiver->createCallback<int>([this,pdlg](int res){
			if (res == CreateNewGroup::CREATE_GROUP_RESULT_SUCCESS)
			{
				QString groupJid = pdlg->getGroupJid();
				QString groupname = pdlg->getGroupName();
				if (mRecentChatMultiDialog)
				{
					MainApp::UIFrame::getCombinationController()->onGroupChatDialog(groupJid,"",false);
					MainApp::UIFrame::getConversationController()->updateJidLastTimeStamp(
						groupJid,
						QDateTime::currentDateTime().toMSecsSinceEpoch()-Biz::Session::currentAccount().getTimeOffsetFromServer());
				}
			}
		},[this](){});

		pdlg->isCreateNewGroup(true);
		pdlg->showNormal();
		pdlg->activateWindow();
		pdlg->setCallBack(callback);
	}

}

/*!
* 功能 : 左侧加号-注销
*/
void MainWidget::onLogout(bool)
{
	Framework::onLogout(); // call MainWidget::doLogout delay

	disconnect(&SystemIcon::instance(), &SystemIcon::sgDoubleClick, this,&MainWidget::onSystemTrayDbClieck);

#ifdef _WINDOWS
#ifndef _DEBUG
#ifdef QCHAT
    QString mutexid = "QCHAT" + Biz::Session::currentAccount().accountData().UserID();
#else
    QString mutexid = "QTALK" + Biz::Session::currentAccount().accountData().UserID() + Biz::Session::getLoginManager()->getNavConfig();
#endif // QCHAT


	auto signalton = Framework::hMutex;
	ReleaseMutex(signalton);
	CloseHandle(signalton);
	Framework::hMutex = NULL;

#endif // !DEBUG
#endif

}

/*!
* 功能 : 左侧加号-退出
*/
void MainWidget::onQuit(bool)
{
	Framework::onQuit();
}


/*!
* 功能 :自己的头像发生了变更
*/
void MainWidget::onSelfCardUpdate(const QString& vcard)
{
	QString bareJid = vcard;
	if (Biz::MessageUtil::compareJid(vcard,Biz::Session::currentAccount().accountData().UserID()))
	{
		QPixmap pixmap = Biz::PortraitHelper::getUserPortrait(vcard);
		pixmap = QPixmap::fromImage(pixmap.toImage().scaled(ui->portrait->size()));

		ui->portrait->setPixmap(pixmap);
	}
}


/*!
* 功能 : 登录状态事件监听->断线了
*/
void MainWidget::onDisconnect()
{
	Log::e("MainWidget::onDisconnect");
	mRecentChatMultiDialog->onDisconnect();
	SystemIcon::instance().onDisconnect();
}


bool MainWidget::eventFilter(QObject *obj, QEvent *event)
{
	if (this == obj)
	{
		if (event->type() == QEvent::MouseMove 
			|| event->type() == QEvent::KeyPress
			|| event->type() == QEvent::Show)
		{
			if (dataApp->value (Constant::CACHE_KEY_AUTOAWAY).toBool ())
			{
				setPresence(QXmppPresence::Online);
				dataApp->put (Constant::CACHE_KEY_AUTOAWAY,false);
				return true;
			}
		}
	}
	if (obj == ui->portrait)
	{
		if (event->type() == QEvent::MouseButtonDblClick 
			|| event->type() == QEvent::MouseButtonPress)
		{
			onPortraitClicked(true);
			return true;
		}
	}

	if (obj == ui->chatsbtn)
	{
		if (QEvent::MouseButtonDblClick == event->type ())
		{
			if (ui->unreadpromot->isVisible() || ui->unreadcount->isVisible())
			{
				bool bGetSilentConversation = ui->unreadpromot->isVisible();
				MainApp::UIFrame::getConversationController ()->activeNextUnreadConversation (!bGetSilentConversation);
			}

			return true;
		}
	}
	return QWidget::eventFilter(obj, event);
}


void MainWidget::timerEvent( QTimerEvent *event )
{
	if (mTimerId == event->timerId())
	{
		if (Biz::Session::getLoginManager()->isLogin())
		{
			Biz::Session::getUserVcardManager()->getOnlineUsersOnTimer();
		}
	}


	if (mAwayPrecentTimer == event->timerId())
	{
#ifdef _WINDOWS_
		Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
		LASTINPUTINFO lpi;
		lpi.cbSize = sizeof(lpi);
		GetLastInputInfo(&lpi);
		qint64 offset = ::GetTickCount()-lpi.dwTime;
#ifdef QCHAT
		qint64 awayOffset = 1000*60*mawayTimesNumber;
#else
		qint64 awayOffset = 1000*60*settingconfig->AutoReplyTimer();
#endif
		quint64 lastOnlineTime = dataApp->value (Constant::CACHE_KEY_LASTONLINETIME).toULongLong ();

		if (offset >= awayOffset  
			&& ::GetTickCount()-lastOnlineTime >=awayOffset)
		{
			// 系统无操作事件超过阈值，并且距离上次在线事件也超过阈值。有可能系统无操作事件段中收到了自己用别的客户端发送的消息，导致变成在线状态。
			if (QXmppPresence::Online == dataApp->value (Constant::CACHE_KEY_CURRENTPRESENCE).toInt ())
			{
				// 从online掉下来，说明是自动离开的
				setPresence(QXmppPresence::Away);
				dataApp->put (Constant::CACHE_KEY_AUTOAWAY,true);
				//这事把ui上的状态变成



			} else {
				// 当前不是在线状态。不需要设置别的状态
			}
		}
		else
		{
			// 没有带到阈值，设置为在线。
			if (dataApp->value (Constant::CACHE_KEY_AUTOAWAY).toBool ())
			{
				// 自动离开的就自动在线，不自动离开的，就不自动在线。
				setPresence(QXmppPresence::Online);
				dataApp->put (Constant::CACHE_KEY_AUTOAWAY,false);
			}
		}

#endif
	}
	if (mWorkSpaceTimer == event->timerId())
	{
		if (Biz::Session::getLoginManager()->isLogin())
		{
			Biz::Session::getStaffManager()->getUserWorkspaceWaitCount();
		}
	}
}


/*!
* 功能 : pubapi
*/
void MainWidget::doLogout()
{
	Log::e("MainWidget::doLogout");
	// 主动退出，不进行断线监听,必须在 Biz::Session::currentAccount().sgLogout(); 之前调用
	disconnect(Biz::Session::getLoginManager(), &Biz::LoginManager::sgDisconnected, this, &MainWidget::onDisconnect);
	disconnect(&SystemIcon::instance(), &SystemIcon::sgDoubleClick, this,&MainWidget::onSystemTrayDbClieck);

	// 关闭所有聊天窗口
	MainApp::UIFrame::getConversationController()->clearAllConversation();

	mRecentChatMultiDialog->close();

	//注销的时，还需要把组织架构给销毁
	emit Biz::Session::currentAccount().sgCleanData();
	//emit Biz::Session::getLoginManager()->sgLoginOut();

#ifdef _WINDOWS
#ifndef _DEBUG
#ifdef QCHAT
	QString mutexid = "QCHAT" + Biz::Session::currentAccount().accountData().UserID();
#else
	QString mutexid = "QTALK" + Biz::Session::currentAccount().accountData().UserID()
		+ Biz::Session::getLoginManager()->getNavConfig();
#endif
	auto signalton = Framework::hMutex;
	if (NULL != signalton)
	{
		ReleaseMutex(signalton);
		CloseHandle(signalton);
		Framework::hMutex = NULL;
	}

#endif // !DEBUG
#endif

}




/*!
* 功能 : pubapi
*/
void MainWidget::showAddGroup(const QString&preeid)
{
	QMap<QString,QString> membermap;
	QString userid = Biz::Session::currentAccount().getUserIDByName(preeid);
	if (userid.isEmpty())
	{
		userid = preeid;

	}
	QString name = Biz::Session::currentAccount().getUserNameById(userid);
	membermap.insert(userid,name);

	CreateNewGroup *pdlg = CreateNewGroupSingleton::getInstance();
	if (pdlg)
	{
		auto callback = mReceiver->createCallback<int>([this,pdlg](int res){
			if (res == CreateNewGroup::CREATE_GROUP_RESULT_SUCCESS)
			{
				QString groupJid = pdlg->getGroupJid();
				QString groupname = pdlg->getGroupName();
				MainApp::UIFrame::getCombinationController()->onGroupChatDialog(groupJid,"",false);
				MainApp::UIFrame::getConversationController()->updateJidLastTimeStamp(groupJid,
					QDateTime::currentDateTime().toMSecsSinceEpoch()-Biz::Session::currentAccount().getTimeOffsetFromServer());
			}
		},[]()
		{});

		pdlg->isCreateNewGroup(true);
		pdlg->setCallBack(callback);
		pdlg->setMemberList(membermap);
		pdlg->showNormal();
		pdlg->activateWindow();
	}

	return;

}

/*!
* 功能 : 当双击托盘的时候，或者点击消息通知的时候，打开固定的会话
*/
void MainWidget::onShowRecentWidget(const QString& jid)
{
	MainApp::UIFrame::getMainDialogController()->actieMainDialog();
	MainApp::UIFrame::getConversationController()->activeConversation(jid);
}


/*!
* 功能 : 在线状态变更了，应该2分钟回掉一次。
*/
void MainWidget::onPresenceChanged(const QVariantList& presenceList)
{
	for(QVariant var : presenceList)
	{
		QVariantMap mapitem = var.toMap();   
		QString userId = mapitem["U"].toString();
		int presence = mapitem["S"].toInt();
		MainApp::UIFrame::getConversationController()->updatePresence(userId,presence);
	}
}

/*!
* 功能 : 登录事件
*/
void MainWidget::onLoginSucceed()
{
	Log::e("MainWidget::onLoginSucceed");

	disconnect(&SystemIcon::instance(), &SystemIcon::sgDoubleClick, this,&MainWidget::onSystemTrayDbClieck);
	connect(&SystemIcon::instance(), &SystemIcon::sgDoubleClick, this,&MainWidget::onSystemTrayDbClieck);

	// 创建断线监听
	connect(Biz::Session::getLoginManager(), &Biz::LoginManager::sgDisconnected, this, &MainWidget::onDisconnect);

	if(mRecentChatMultiDialog->isHidden())
	{
		mRecentChatMultiDialog->showNormal();
	}
	QString userId = Biz::Session::currentAccount().accountData().UserID();
	mTimerId = startTimer(1000 * 60 * 2);
	Biz::Session::getUserVcardManager()->getOnlineUsersOnTimer();//主动触发一次
	 
#ifndef QCHAT 
	mAwayPrecentTimer = startTimer(1000*1);
	mWorkSpaceTimer = startTimer(1000*30); //半分钟请求一次工作区的为完成工作任务
	Biz::Session::getStaffManager()->getUserWorkspaceWaitCount();

#endif // !QCHAT




	//load portrit
	//这个地方应该更具版本号进行判断是否需要下载图片进行更新

	Biz::Session::getUserVcardManager()->getDomainUsersVcardByVersion(Biz::MessageUtil::makeSureUserJid(userId));

	setPresence(QXmppPresence::Online);

	dataApp->put (Constant::CACHE_KEY_CURRENTPRESENCE,QXmppPresence::Online);


#ifndef QCHAT

	//这个时候弹出升级后的changelog
	Biz::EditableSettings *editableSettings = Biz::Session::getEditableSettings();
	if (editableSettings->CurrentVersion() < Util::GLOBAL_INTERNAL_VERSION)
	{
		//"http://qt.qunar.com/helps/help_win.html?id=0";
		QString val = Biz::Session::getSystemConfig()->getHttpFileHost() + Biz::Session::getEditableSettings()->getchangelog();

		CommentWebViewSingleton::getInstance()->openCommonUrl(val);
		CommentWebViewSingleton::getInstance()->showActiveDlg();
		//存下最新的version号
		editableSettings->CurrentVersion(Util::GLOBAL_INTERNAL_VERSION);
		Biz::Session::saveEditableSettings();
	}


#endif // QCHAT


	SystemIcon::instance().onConnected();
#ifdef QCHAT
	//如果登录的用户名的类型非商户端，群组的按钮也被屏蔽
	bool isEmployee = (Biz::EUserTypeEmployee==(Biz::EUserTypeEmployee&Biz::Session::getAccountManager()->accountData().EUserType()));

	ui->pbDingdan->setVisible(!isEmployee);
	//如果不是客服，这地方也应该把combinationcontroller中的组织架构也屏蔽掉
	if (isEmployee)
	{
		UIFrame::getCombinationController()->hideCombinationContainerOfOrganizaItem();
	}


	//如果是qchat，手機端push消息的設置
	QSharedPointer<Biz::PersonConfInfo> spPersonCfg = 
		Biz::Session::getPersonCfgManager()->getPersonCfgInfo(SettingDetail::KPushInfoDic);
	if (spPersonCfg.isNull())
	{
		return;
	}
	QString jsonString = spPersonCfg->infoValue();
	QVariantMap jsonMaps 
		= QJsonDocument::fromJson(jsonString.toUtf8()).toVariant().toMap();


	bool bret = jsonMaps.value("anytime").toBool();
	if(bret)
	{
		Biz::Session::currentAccount().setPresence(QXmppPresence::push);
		setPresence(QXmppPresence::push);
		mbayway = true;
	}
	else
	{
		mbayway = false;
		mawayTimesNumber = jsonMaps.value("awaytime").toInt();

	}


#endif
	quint64 getbegintickedtm =  QDateTime::currentMSecsSinceEpoch();
	Log().rt("login---"+QStringLiteral("登录完成") + QString(" -------> loginendime:%1").arg(getbegintickedtm));

}



/*!
* 功能 : 热键s
*/
void MainWidget::InitKeyHook()
{
	Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
	QString strtmpHotkey = settingconfig->MessageHotKey();
	//注册获取消息的快捷键
	QString tmp = strtmpHotkey.replace(" ", "");
	emit Biz::Session::currentAccount().sgRegistHotKey(tmp, 1);

	//注册截屏的快捷键
	strtmpHotkey = settingconfig->ScreenHotKey();
	tmp = strtmpHotkey.replace(" ", "");
	emit Biz::Session::currentAccount().sgRegistHotKey(tmp, 2);

	strtmpHotkey = settingconfig->MbordHotKey();
	tmp = strtmpHotkey.replace(" ", "");
	emit Biz::Session::currentAccount().sgRegistHotKey(tmp, 4);

	//注册住面板中收索联系人
	strtmpHotkey = settingconfig->SearchHotKey();
	tmp = strtmpHotkey.replace(" ", "");
	emit Biz::Session::currentAccount().sgRegistHotKey(tmp, 3);

}
void MainWidget::onhotKeyGetMsg()
{
	if (!mstrCurrentMsgOfOwerId.isEmpty())
	{
		MainApp::UIFrame::getConversationController()->activeConversation(mstrCurrentMsgOfOwerId);
	}
	MainApp::UIFrame::getMainDialogController()->actieMainDialog();
}
void MainWidget::onhotKeyJietu()
{
	Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
	if (settingconfig->SetJietu())
	{
		emit GloableEventObject::getInstance()->sgHideMainWidge();
	}

#ifdef _WINDOWS
	SnipScreenTool::getInstance()->Init().Start();
	QString topid = MainApp::UIFrame::getConversationController()->topConversationId();
	SnipScreenTool::getInstance()->setConversionId(topid);
#else
	//     QStringList args;
	//     args << "-a" << "--file=/tmp/1.jpg";
	//     QProcess::execute("gnome-screenshot",args);
	// 
	//     QStringList args2;
	//     args2 << "-selection" << "clipboard" << "-target" << "image/jpg" << "-i" << "/tmp/1.jpg";
	//     QProcess::execute("xclip",args2);
	if (settingconfig->SetOSLinuxJietu())
	{
		if (settingconfig->SetJietu())
		{
			emit GloableEventObject::getInstance()->sgHideMainWidge();
		}
		SnipScreenTool::getInstance()->Init().Start();
		SnipScreenTool::getInstance()->setConversionId("");
	}
	if (settingconfig->SetOSLinux3dJietu())
	{
		if (settingconfig->SetJietu())
		{
			emit GloableEventObject::getInstance()->sgHideMainWidge();
		}
		QStringList args;
		args << "-a" << "--file=/tmp/1.jpg";
		QProcess::execute("gnome-screenshot",args);

		QStringList args2;
		args2 << "-selection" << "clipboard" << "-target" << "image/jpg" << "-i" << "/tmp/1.jpg";
		QProcess::execute("xclip",args2);
	}
#endif // _WINDOWS
}
void MainWidget::onhotKeyMainBord()
{
#ifdef QCHAT
	SystemIcon::instance().setIcon(QIcon(":/Images/Deal_chat.ico"));
#else
	SystemIcon::instance().setIcon(QIcon(":/Images/Deal.ico"));
#endif
	MainApp::UIFrame::getMainDialogController()->actieMainDialog();
}
void MainWidget::onhotKeySearch()
{
	MainApp::UIFrame::getMainDialogController()->actieMainDialog();
	mRecentChatMultiDialog->setSearchViewFocus();
}

void MainWidget::onRegistHotKey(const QString&hotkey, int ntype)
{
#ifdef _WINDOWS
	bool bret= false;

	switch (ntype)
	{
	case 1:
		{

			shortcutMsg = new MyGlobalShortCut(hotkey, this);
			bret = shortcutMsg->unregisterHotKey();
			bret = shortcutMsg->registerHotKey();

			connect(shortcutMsg, &MyGlobalShortCut::activated, this, &MainWidget::onhotKeyGetMsg);

		}

		break;
	case 2:
		{
			QString strPersonDefault = "Ctrl+Alt+A";
			QString strSetDefault = "Ctrl+Alt+Q";
			QString strSuccesshotkey;
			QString strRegisterhotkey;
			bool bRegisterRet = false;
			if (hotkey== "Ctrl+Alt+P")
			{
				strRegisterhotkey = strPersonDefault;
			}
			else
			{
				strRegisterhotkey = hotkey;
			}



			shortcutscreen = new MyGlobalShortCut(strRegisterhotkey, this);
			bret = shortcutscreen->unregisterHotKey();
			bret = shortcutscreen->registerHotKey();
			if (!bret)
			{
				shortcutscreen = new MyGlobalShortCut(strSetDefault, this);
				bret = shortcutscreen->unregisterHotKey();
				bret = shortcutscreen->registerHotKey();
				if(bret)
				{
					bRegisterRet = true;
					strSuccesshotkey = strSetDefault;
				}
			}
			else
			{
				bRegisterRet = true;
				strSuccesshotkey = strRegisterhotkey;
			}

			connect(shortcutscreen, &MyGlobalShortCut::activated, this, &MainWidget::onhotKeyJietu);
			if(bRegisterRet)
			{
				Biz::Session::getSettingConfig()->ScreenHotKey(strSuccesshotkey);
				Biz::Session::saveSettingConfig();
			}
		}

		break;
	case 3:
		{
			shortcutsearch = new MyGlobalShortCut(hotkey, this);
			bret = shortcutsearch->unregisterHotKey();
			bret = shortcutsearch->registerHotKey();

			connect(shortcutsearch, &MyGlobalShortCut::activated, this, &MainWidget::onhotKeySearch);

		}

		break;
	case 4:
		{
			shortcutbord = new MyGlobalShortCut(hotkey, this);
			bret = shortcutbord->unregisterHotKey();
			bret = shortcutbord->registerHotKey();

			connect(shortcutbord, &MyGlobalShortCut::activated, this, &MainWidget::onhotKeyMainBord);

		}

		break;
	default:
		break;
	}
#else
#if 0
	bool bret= false;

	switch (ntype)
	{
	case 1:
		{

			shortcutMsg = new QxtGlobalShortcut(QKeySequence(hotkey), this);


			connect(shortcutMsg, &QxtGlobalShortcut::activated, this, &MainWidget::onhotKeyGetMsg);

		}

		break;
	case 2:
		{
			QString strPersonDefault = "Ctrl+Alt+A";
			QString strSetDefault = "Ctrl+Alt+Q";
			QString strSuccesshotkey;
			QString strRegisterhotkey;
			bool bRegisterRet = false;
			if (hotkey== "Ctrl+Alt+P")
			{
				strRegisterhotkey = strPersonDefault;
			}
			else
			{
				strRegisterhotkey = hotkey;
			}


			shortcutscreen = new QxtGlobalShortcut(QKeySequence(strRegisterhotkey), this);

			bool bret = shortcutscreen->setShortcut(QKeySequence(strRegisterhotkey));

			if (!bret)
			{
				shortcutscreen = new QxtGlobalShortcut(QKeySequence(strSetDefault), this);
				bret = shortcutscreen->setShortcut(QKeySequence(strSetDefault));
				if(bret)
				{
					bRegisterRet = true;
					strSuccesshotkey = strSetDefault;
				}
			}
			else
			{
				bRegisterRet = true;
				strSuccesshotkey = strRegisterhotkey;
			}

			connect(shortcutscreen, &QxtGlobalShortcut::activated, this, &MainWidget::onhotKeyJietu);

			if(bRegisterRet)
			{
				Biz::Session::getSettingConfig()->ScreenHotKey(strSuccesshotkey);
				Biz::Session::saveSettingConfig();
			}
		}

		break;
	case 3:
		{
			shortcutsearch = new QxtGlobalShortcut(QKeySequence(hotkey), this);


			connect(shortcutsearch, &QxtGlobalShortcut::activated, this, &MainWidget::onhotKeySearch);

		}

		break;
	case 4:
		{
			shortcutbord = new QxtGlobalShortcut(QKeySequence(hotkey), this);

			connect(shortcutbord, &QxtGlobalShortcut::activated, this, &MainWidget::onhotKeyMainBord);

		}

		break;
	default:
		break;
	}
#endif
#endif
}

void MainWidget::onUnRegistHotKey( int ntype)
{
	Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
#ifdef _WINDOWS
	bool bret = false;
	switch (ntype)
	{
	case 1:
		if (shortcutMsg == NULL)
		{
			QString strtmpHotkey = settingconfig->MessageHotKey();
			shortcutMsg = new MyGlobalShortCut(strtmpHotkey, this);
		}
		bret = shortcutMsg->unregisterHotKey();
		break;
	case 2:
		if (shortcutscreen == NULL)
		{
			QString strtmpHotkey = settingconfig->ScreenHotKey();
			shortcutscreen = new MyGlobalShortCut(strtmpHotkey, this);
		}
		bret = shortcutscreen->unregisterHotKey();
		break;
	case 3:
		if (shortcutsearch == NULL)
		{
			QString strtmpHotkey = settingconfig->SearchHotKey();
			shortcutsearch = new MyGlobalShortCut(strtmpHotkey, this);
		}
		bret = shortcutsearch->unregisterHotKey();
		break;
	case 4:
		if (shortcutbord == NULL)
		{
			QString strtmpHotkey = settingconfig->MbordHotKey();
			shortcutbord = new MyGlobalShortCut(strtmpHotkey, this);
		}
		bret = shortcutbord->unregisterHotKey();
		break;
	default:
		break;
	}
#endif
}


/*!
* 功能 : pubapi,获取功能扩展区域的层叠容器句柄。
*/
QStackedWidget* MainWidget::getLevelStacked()
{
	return mRecentChatMultiDialog->getLevelStacked();
}

/*!
* 功能 : 托盘双击事件
*/
void MainWidget::onSystemTrayDbClieck()
{
	MainApp::UIFrame::getMainDialogController()->actieMainDialog();
}

/*!
* 功能 : 设置当前的在线状态
*/
void MainWidget::setPresence(int presence)
{
	if (dataApp->value (Constant::CACHE_KEY_CURRENTPRESENCE).toInt () == presence)
		return;

	if (presence == QXmppPresence::Online)
	{
		QString strTopJid = MainApp::UIFrame::getConversationController()->topConversationId();
		if (!strTopJid.isEmpty())
		{
			if (strTopJid.contains("@conference"))
			{
				Biz::Session::getConverSationManager()->setGroupConversationMessageRead(strTopJid);
			}
			else
			{
				Biz::Session::getConverSationManager()->setConversationMessageRead(strTopJid);
			}
		}
	}

	QString iconimg;
	do 
	{
		if (presence == QXmppPresence::Online)
		{
			iconimg = ":Images/presence_online.png";
			break;
		}

		if ( presence == QXmppPresence::Away)
		{
			iconimg = ":Images/presence_away.png";
			break;
		}
		if (presence == QXmppPresence::busy)
		{
			iconimg = ":Images/presence_busy.png";
			break;
		}

	} while (false);

	if (!iconimg.isEmpty())
	{
		QPixmap icon(iconimg);

		ui->precencebtn->setIconSize(ui->precencebtn->size());

		ui->precencebtn->setIcon(QIcon(icon));
	}


	dataApp->put(Constant::CACHE_KEY_CURRENTPRESENCE,presence);
	Biz::Session::currentAccount().setPresence(presence);
}

/*!
* 功能 : 收到别的客户端退群的通知 -- 可以挪走
*/
void MainWidget::onDelRegisterRecvied(const QString& groupJid, const QString& jid)
{
	if ( Biz::MessageUtil::compareUserId(jid,Biz::Session::currentAccount().accountData().UserID()))
	{
		Log::e(QString("MainWidget::onDelRegisterRecvied groupJid=%1").arg(groupJid));
		emit Biz::Session::getGroupManager()->sgGroupLeavedReceived(groupJid);
	}
}

/*!
* 功能 :断线重连事件
*/
void MainWidget::onReConnToServer(bool autoConn)
{
	Log::e("MainWidget::onReConnToServer" + QString::number(autoConn));
	if (!autoConn)
	{
		// 手动重连不进行断线监听
		disconnect(Biz::Session::getLoginManager(), &Biz::LoginManager::sgDisconnected, this, &MainWidget::onDisconnect);
	}
	MainApp::UIFrame::getLoginController()->signin();
}

void MainWidget::initRobotEvent()
{
	Biz::RobotManager* pRobot = Biz::Session::getRobotManager();
	connect(pRobot,&Biz::RobotManager::sgSubScriptionReceived,this,&MainWidget::onRobotReceived);
	connect(pRobot,&Biz::RobotManager::sgRobotWeiDaoYouMessage,this,&MainWidget::onWeiDaoYouMessageReceived);
}

/*!
* 功能 : 自动更新
*/
void MainWidget::onAutoUpdateVersion(const QSharedPointer<Biz::CheckVersionUpdate>& updateInfo,const QString& localPaht)
{
#ifdef _WINDOWS
	QString textInfo = QStringLiteral("发现新版本 %1，是否更新?").arg(updateInfo->lastVersion);

	if (MainApp::UIFrame::getNotifyCenterController ()->alertMessageWithCancle (textInfo))
	{
		bool bret = ShellExecute(NULL,NULL,(LPWSTR)localPaht.utf16(),(LPWSTR)QString("/quitinstall=1").utf16(),NULL,SW_SHOW);

		if (!bret)
		{
			Log::e(QString("安装包错误"));
			MainApp::UIFrame::getNotifyCenterController ()->alertMessage(T_("MessageBox_InstallFail"));
			return;
		}
		qApp->quit();
	}
	else
	{
		//把当前的版本写到一个配置文件中
		Biz::Session::currentAccount().setAccountSaveVersion(updateInfo->lastVersion.toLongLong());
	}
#endif // _WINDOWS

}

/*!
* 功能 : 加号 - 搜索机器人
*/
void MainWidget::onSearchRobot()
{
	RobotSearchView::getInstance()->autoshow();
}

/*!
* 功能 : pubapi 且回到会话页面
*/
void MainWidget::activeChatsBtn()
{
	ui->chatsbtn->click();
}

/*!
* 功能 : 加号 - 搜索好友
*/
void MainWidget::onSearchFriends()
{
	FriendsSearcherSingleton::getInstance()->showNormal();
	FriendsSearcherSingleton::getInstance()->activateWindow();
}

/*!
* 功能 : 初始化 初始化联合列表
*/
void MainWidget::initCombinationListItem()
{
	TabItems* item = new TabItems();
	tabItems.append(item);
	item->btn = ui->combinationbtn;
	item->level1 = mRecentChatMultiDialog->getCombinationList();
	item->level1->setObjectName("CombinationListView");
	getLevelStacked()->setCurrentWidget(mRecentChatMultiDialog->getCombinationList());

	item->title = T_("MainWidget_Tab2");
	getLevelStacked()->addWidget(item->level1);
	ui->combinationbtn->setToolTip(T_("MainWidget_Tab2"));

}

/*!
* 功能 : 未读消息数变更了
*/
void MainWidget::onUnreadMsgChanged(int count,bool bHasTipOfUnreadmark)
{
	ui->unreadcount->setText(QString::number (qMin(count,99)));
	ui->unreadcount->adjustSize();
	ui->unreadcount->setVisible(count!=0);

	ui->unreadpromot->setVisible((count==0) && bHasTipOfUnreadmark);
}

/*!
* 功能 : 加号 - 批量退群
*/
void MainWidget::onQuitGroup(bool)
{
	GroupQuitViewSingleton::getInstance ()->setTips(QStringLiteral("我的群组："));
	GroupQuitViewSingleton::getInstance ()->show ();
	GroupQuitViewSingleton::getInstance ()->activateWindow ();
}

/*!
* 功能 : 事件 - 工作区事件
*/
void MainWidget::onUnreadWorksChanged( int count )
{
	//ui->unreadworksIcon->setText(QString::number (qMin(count,99)));
	ui->unreadworksIcon->setVisible(count !=0);
}


/*!
* 功能 : 事件 - 个人服务状态变更
*/
void MainWidget::onPersonCfgChange(  )
{


	QSharedPointer<Biz::PersonConfInfo> spPersonCfg = 
		Biz::Session::getPersonCfgManager()->getPersonCfgInfo(SettingDetail::KPushInfoDic);

	if (spPersonCfg.isNull())
	{
		return;
	}
	QString jsonString = spPersonCfg->infoValue();

	QVariantMap jsonMaps 
		= QJsonDocument::fromJson(jsonString.toUtf8()).toVariant().toMap();

	bool bret =	jsonMaps.value("pushable").toBool();

	bret = jsonMaps.value("anytime").toBool();

	if (bret)
	{
		QPixmap icon(":Images/presence_more.png");

		ui->precencebtn->setIconSize(ui->precencebtn->size());

		ui->precencebtn->setIcon(QIcon(icon));
	}


}

void MainWidget::OnLoginUpdate()
{
	if (Util::GLOBAL_INTERNAL_VERSION < Biz::Session::getAccountManager()->accountData().MainChatVersion())
	{
		int maxWidth = 5;
		QPixmap retPixMap(maxWidth,maxWidth);
		retPixMap.fill(Qt::transparent);
		QPainter painter(&retPixMap);
		painter.setPen(QColor("#00000000"));

		// 头像 底图 2像素圆角 50*50
		QRect rectangle(0,0, maxWidth, maxWidth);
		QColor background = QColor(0xf5,0x5f,0x56);
		painter.setBrush(QBrush(background));
		painter.drawEllipse(rectangle);
		m_label->setPixmap(retPixMap);
		// 	m_label->setStyleSheet("{"
		// 	"padding:-5px;"
		// 	"color: #FFFFFF;"
		// 	"border-image: url(:Images/tipsIcon.png) 8 8 8 8;"
		// 	"border-top: 8px transparent;"
		// 	"border-bottom: 8px transparent;"
		// 	"border-right: 8px transparent;"
		// 	"border-left: 8px transparent;"
		// 	"}");
		m_label->setVisible(true);
		m_label->show();
	}
	else
	{
		m_label->setVisible(false);
	}
}

void MainWidget::onCreatePwdBox()
{
	//弹框设置密码
	auto callbackkey = mReceiver->createCallback<bool>([this](const bool bret)
	{
		if (bret)
		{
			MainApp::UIFrame::getNotifyCenterController ()->alertMessage("",QStringLiteral("会话密码箱以存在,不需要创建."));
		}
		else
		{
			if ( MainApp::UIFrame::getNotifyCenterController ()->alertMessage("",QStringLiteral("会话密码箱还没有创建,是否创建？")
				,QStringLiteral("取消"),QStringLiteral("创建")) )
			{
				setpwdInfor pwd(this);

				pwd.setFixedSize( pwd.width (),pwd.height ());
				pwd.showPwdInfor(1);
				if (pwd.exec() == setpwdInfor::ChooseOK)
				{
					QString strtitle = pwd.gettitle();
					QString strdesc = pwd.getdescription();
					QString strpwd = pwd.getpwd();
					//这里需要请求服务器了
					auto callback = mReceiver->createCallback<QString>([this](const QString& bret)
					{
						QJsonDocument Json_Data = QJsonDocument::fromJson(bret.toUtf8());

						QVariantMap dataMap = Json_Data.toVariant().toMap();

						bool ret = dataMap["ret"].toBool();
						QString mainkey = dataMap["key"].toString();

					}, []{});

					Biz::Session::getqCloudManager()->setSaveqcloudMainInfo(strtitle, strdesc, strpwd,Biz::ChatPwdBox, callback);
				}
			}
		}

	}, []{});

	Biz::Session::getqCloudManager()->isChatPwdBox(callbackkey);
}

void MainWidget::onCreateChatPwd()
{

}

void MainWidget::onDeleteChatPwd()
{

	auto callback = mReceiver->createCallback<bool>([this](bool bret)
	{

		if(bret)
		{
			Biz::Session::getqCloudManager()->deleteqCloudMainKey(NULL);
		}


	}, []{});
	Biz::Session::getqCloudManager()->deleteqCloudSubAllKey(callback);
}

void MainWidget::onZhuxiao()
{
	this->onLogout(true);
}

void MainWidget::onCollectionSet()
{
	CommentWebViewSingleton::getInstance()->openCollectionSet();
}

// 不清楚抛异常的目的 暂时注释 todo
void MainWidget::keyPressEvent( QKeyEvent * )
{
	//throw std::logic_error("The method or operation is not implemented.");
}
