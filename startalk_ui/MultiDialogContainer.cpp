#include "MultiDialogContainer.h"
#include "ui_MultiDialogContainer.h"
#include <QMouseEvent>
#include <QXmppUtils.h>
#include <QImageReader>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QDesktopServices>
#include <QUrl>
#include <QCoreApplication>
#include <QClipboard>

#include "Session.h"
#include "Account.h"
#include "AccountData.h"
#include "ConfigureHelper.h"
#include "SystemConfigData.h"
#include "../LocalManBiz/SettingData.h"
#include "RecentItemView.h"
#include "LanguageHelper.h"
#include "NotifyCenterController.h"
#include "GroupListData.h"
#include "Framework.h"
#include "SystemIcon.h"
#include "SettingDetail.h"
#include "createnewgroup.h"
#include "portraithelper.h"
#include "SystemDefine.h"
#include "CallbackReceiver.h"
#include "gloableeventobject.h"
#include "CustomDefine.h"
#include "groupscontroller.h"
#include "MessageListData.h"
#include "ChatDialog.h"
#include "newsdialog.h"
#include "MenuRobotDialog.h"
#include "ExtendedSessionListView.h"
#include "loginmanager.h"
#include "MainWidget.h"
#include "GroupManager.h"
#include "UserVcardManager.h"
#include "conversationmanager.h"
#include "MessageManager.h"
#include "GroupChatDialog.h"
#include "SearchUserListWidget.h"
#include "diywidgit/customviews/qframelayout.h"

#include "ConversationController.h"
#include "UIFrame.h"

#include "chattoolbar.h"
#include "advinformanager.h"
#include "combinationcontroller.h"
#include "Ordermanagedialog.h"
#include "InnerWebBrowserrObject.h"
#include "UiHelper.h"
#include "editablesettings.h"
#include "consultchatdialog.h"

const int CREAT_GROUPCHAT_OPTION_TAB = 0x01;
const int CREAT_GROUPCHAT_OPTION_WINDOW = 0x10;

MultiDialogContainer::MultiDialogContainer(QWidget *parent) 
	: QWidget(parent)
	, ui(new Ui::MultiDialogContainer)
	, animationing(false)
	, bReConnected(false)
	, isAutoReConnentWhenDisconnected(false)
	//, mRobotListDlg(NULL)
	, mFriendMessageDlg(NULL)
	, m_pSearchUserListWidget(NULL)
	, m_pWorkPlaceView(NULL)
	, mbtnCollerofChange(false)
{
	mReceiver = new Biz::CallbackReceiver(this);

	ui->setupUi(this);

	pExtendListStatcked = ui->extendListStacked;

	using namespace Qt;
	auto remove = WindowTitleHint;
	auto add = FramelessWindowHint | WindowMinMaxButtonsHint;
	setAttribute(Qt::WA_AlwaysShowToolTips, true);
	setAttribute(Qt::WA_TranslucentBackground, true);
	overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));
	//setWindowIcon(QIcon(":/Images/Deal.ico"));
	setAttribute(Qt::WA_StyledBackground, true);
#ifdef QCHAT
	setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
#else
	setWindowIcon(QIcon(":/Images/Deal.ico"));
#endif



	connect(ui->lineEdit, &QLineEdit::textChanged, this, &MultiDialogContainer::onSearchTextChanged);
	connect(ui->lineEdit, &LineEdit::sgPaste, this, &MultiDialogContainer::onEditPast);


	ui->lineEdit->installEventFilter(this);

	ui->splitter->setStretchFactor(0, 3);
	ui->splitter->setStretchFactor(1, 7);

	pHandler = ui->splitter->handle(1);
	pHandler->setStyleSheet("QWidget { background-color: #00000000 }");
	pHandler->installEventFilter(this);

	this->installEventFilter(this);



	connect(ui->createnewgroup,&QPushButton::clicked,[this](bool checked){
		CreateNewGroup *pdlg = CreateNewGroupSingleton::getInstance();
		if (pdlg)
		{
			auto callback = mReceiver->createCallback<int>([this,pdlg](int res){
				if (res == CreateNewGroup::CREATE_GROUP_RESULT_SUCCESS)
				{
					QString groupJid = pdlg->getGroupJid();
					QString groupname = pdlg->getGroupName();
					MainApp::UIFrame::getConversationController()->createNewGroupChatDialog(groupJid);
					MainApp::UIFrame::getConversationController()->addGroupChatRosterItem(groupJid,MainApp::ConversationController::sDefaultExtendPanel);
					MainApp::UIFrame::getConversationController()->activeConversation(groupJid);
				}
			},[]()
			{});
			pdlg->isCreateNewGroup(true);
			pdlg->setCallBack(callback);
			pdlg->showNormal();
			pdlg->activateWindow();
		}

	});




	initTipPopBtn();

	showEmptyChatdialog();

	connect(ui->openchat,&QPushButton::clicked,this,&MultiDialogContainer::onOpenGroupChat);
	connect(ui->openchat_simple,&QPushButton::clicked,this,&MultiDialogContainer::onOpenUserChat);


	ui->staffgroup->installEventFilter(this);
	ui->staffuser->installEventFilter(this);

	autoReConnTimer.setDuration(1000*60);
	autoReConnTimer.setFrameRange(0,60);
	autoReConnTimer.setCurveShape(QTimeLine::LinearCurve);
	connect(&autoReConnTimer,&QTimeLine::frameChanged,this,&MultiDialogContainer::onReconnetCount);

	InitSubscriptionListView();

	connect(Biz::Session::getUserVcardManager(), &Biz::UserVcardManager::sgHDPortraitUpdate,this, &MultiDialogContainer::onHDProtraitUpdate);
	connect(Biz::Session::getConverSationManager(),&Biz::ConverSationManager::sgTopMostConversationChanged,
		this,&MultiDialogContainer::onTopMostConversationChanged);

	//消息提醒的响应
	connect(Biz::Session::getConverSationManager(), &Biz::ConverSationManager::sgNoticeTipConversationChanged, 
		this, &MultiDialogContainer::onNoticeTipConversationChanged);

	ui->label_email->setVisible(false);
	ui->user_email->setVisible(false);

	m_pSearchUserListWidget = new SearchUserListWidget();
	m_pSearchUserListWidget->setParent(this);
	m_pSearchUserListWidget->hide();
	connect(m_pSearchUserListWidget, &SearchUserListWidget::sgItemSelected, this, &MultiDialogContainer::onSearchChatResult);
	connect(m_pSearchUserListWidget, &SearchUserListWidget::sgGroupSelected, this, &MultiDialogContainer::onSearchGroupResult);
	connect(m_pSearchUserListWidget, &SearchUserListWidget::sgRobotSelected, this, &MultiDialogContainer::onRobotResult);
	connect(m_pSearchUserListWidget, &SearchUserListWidget::sgMoreSelected, this, &MultiDialogContainer::onMoreSelectResult);
	connect(m_pSearchUserListWidget, &SearchUserListWidget::sgHistoryRecord, this, &MultiDialogContainer::onHistoryRecord);
	QFrameLayout* pLayout = new QFrameLayout(ui->tbk1);
	pLayout->appendWidget(ui->tbk2,AlinementPolicy::ALINE_FILL);
	pLayout->appendWidget(m_pSearchUserListWidget,AlinementPolicy::ALINE_TOPLEFT,QMargins(25,45,0,0));
	ui->tbk1->setLayout(pLayout);

	MainApp::UIFrame::getConversationController()->registChatDialogContainer(this);
	MainApp::UIFrame::getCombinationController()->registCombinationContainer(this);

	connect(ui->loadUnread,&QPushButton::clicked,[this]{
		MainApp::UIFrame::getConversationController()->loadTopAndUnreadConversations();   
	});

	connect(ui->loadAll,&QPushButton::clicked,[this]{
		MainApp::UIFrame::getConversationController()->loadAllChattingConversation();
	});

	connect(Biz::Session::getConverSationManager(),&Biz::ConverSationManager::sgCoversationRectentListShow, [this](bool bstyle){
		if (bstyle)
		{
			MainApp::UIFrame::getConversationController()->loadAllChattingConversation();
		}
		else
		{
			MainApp::UIFrame::getConversationController()->loadTopAndUnreadConversations();   
		}
	});


	QFrameLayout* pFLayout = new QFrameLayout(ui->sessionListPanel);
	pFLayout->appendWidget(ui->advedSessionPanel,ALINE_FILL);
	pFLayout->appendWidget(ui->menupanel,ALINE_BOTTOM|ALINE_MATCHWIDTH,QMargins(0,0,0,-2*32));

	ui->sessionListPanel->installEventFilter(this);
	ui->menupanel->installEventFilter(this);
	ui->menupanel->setVisible(false);
	updateConversationCountTip(0);
	////默认图片的展示
	QPixmap pixmap = QPixmap(QString::fromUtf8(":/Images/im_default_header.png"));
	pixmap.setDevicePixelRatio(this->devicePixelRatio());
	ui->label->setPixmap(pixmap);

	ui->advtool->setVisible(false);


	QFrameLayout* pspitterRightLayout = new QFrameLayout(ui->spitter_right);
	pspitterRightLayout->appendWidget(ui->custemwidgets,ALINE_FILL);
	pspitterRightLayout->appendWidget(ui->webwidgets, ALINE_FILL);

	QFrameLayout* pSearchPanel = new QFrameLayout(ui->lineEditPanel);
	pSearchPanel->appendWidget(ui->linesubpanel,ALINE_MATCHWIDTH|ALINE_VCENTER);
	pSearchPanel->appendWidget(ui->loadmsgprogress,ALINE_MATCHWIDTH|ALINE_BOTTOM);
	connect(Biz::Session::getMessageManager(),&Biz::MessageManager::sgGetMessageFromServerProgress,this,&MultiDialogContainer::onLoadMessageProgress);
	ui->loadmsgprogress->setMinimum(0);
	ui->loadmsgprogress->setMaximum(99);
	ui->loadmsgprogress->setValue(0);

	m_pLoadMessageProgressTimeer = new QTimeLine(1000,ui->loadmsgprogress);
	m_pLoadMessageProgressTimeer->setFrameRange(0,99);
	connect(m_pLoadMessageProgressTimeer,&QTimeLine::frameChanged,[this](int frame){
		ui->loadmsgprogress->setValue(frame);
	});
	connect(m_pLoadMessageProgressTimeer,&QTimeLine::finished,[this](){
		m_pLoadMessageProgressTimeer->setDirection(m_pLoadMessageProgressTimeer->direction()==QTimeLine::Forward?QTimeLine::Backward:QTimeLine::Forward);
		m_pLoadMessageProgressTimeer->start();
	});

	m_pWorkPlaceView = new webview(this);
	WebPage* pPage = new WebPage(this);
	m_pWorkPlaceView->setPage(pPage);
	InnerWebBrowserrObject* pWebPageClintApi = new InnerWebBrowserrObject(NULL);
	pPage->addChatChannelToHtml("ClientApi", pWebPageClintApi);
	pWebPageClintApi->setWebPage(pPage);
	ui->webwidgetstack->addWidget(m_pWorkPlaceView);

	connect (pWebPageClintApi,&WebViewCommObject::sgOpenUrlInInnerWebBrowser,[this](const QString& url){ 
		QMap<QString,QString> contextInfo;
		contextInfo.insert ("fromjid","");
		contextInfo.insert ("chattype","");
		CommentWebViewSingleton::getInstance()->openCommonUrlWithCookie(QUrl(url).toEncoded(),contextInfo);
	});
	showEmptyChatdialog ();
	InitNoteInfor();
}

MultiDialogContainer::~MultiDialogContainer()
{
	Biz::Session::getSettingConfig()->MultiChatDlgWidth(this->width());
	Biz::Session::getSettingConfig()->MultiChatDlgHeight(this->height());
	Biz::Session::currentAccount().saveGroupListData();
}




void MultiDialogContainer::onSearchTextChanged(const QString & text)
{

	if(text.length() <=0 )
	{
		m_pSearchUserListWidget->hide();
		return;
	}

	auto searchUserFunc = [this,text]{
		auto callback = mReceiver->createCallback<QList<Biz::SearchResulteItemGroupModule>>(
			[this,text](const QList<Biz::SearchResulteItemGroupModule>& results){
				m_pSearchUserListWidget->setSearchKey(text);
				m_pSearchUserListWidget->setListData(results);
				ui->lineEdit->activateWindow();
				ui->lineEdit->setFocus();   

		},[]{});

		Biz::Session::getConverSationManager()->searchUserInGlobal(text,callback);
		//改进需要用lua的，未调试完
		//Biz::Session::getConverSationManager()->searchUserInGlobalbyLua(text, callback);

	};


	if (text.length()<3) 
	{
		QTimeLine* pTimeLine = new QTimeLine(300);
		connect(pTimeLine,&QTimeLine::finished,[this,text,pTimeLine,searchUserFunc]{
			pTimeLine->deleteLater();
			QString strCurentText = ui->lineEdit->text();
			if (strCurentText == text)
				searchUserFunc();
		});
		pTimeLine->start();
	}
	else
	{
		searchUserFunc();
	}

}

void MultiDialogContainer::onEditPast()
{
	const QMimeData* mimeDatasource = QApplication::clipboard()->mimeData();
	if (mimeDatasource->hasText())
	{
		QString plainText = mimeDatasource->text();
		ui->lineEdit->setText (plainText.trimmed());
	}
}



void MultiDialogContainer::onSearchChatResult(const QString& conversationId)
{
	ui->lineEdit->setText("");

	QStringList consultParam = conversationId.split(",");
	if (consultParam.length() == 3)
	{
		QString virturalid = consultParam.at(0);
		QString to = consultParam.at(1);
		int qchatid = consultParam.at(2).toInt();
		if ( !virturalid.isEmpty() && !to.isEmpty() && (qchatid==Biz::consultmsgType::VistorToOnDuty || qchatid==Biz::consultmsgType::OnDutyToVistor))
		{
			virturalid = Biz::MessageUtil::makeSureUserJid(virturalid);
			to = Biz::MessageUtil::makeSureUserJid(to);

			QString conversationID = virturalid;
			if (Biz::consultmsgType::OnDutyToVistor == qchatid)
				conversationID = Biz::XmppMessage::makeConsultConversation5Id(to,virturalid);

			MainApp::UIFrame::getConversationController()->addConsultChatRosterItem(conversationID,MainApp::ConversationController::sDefaultExtendPanel,virturalid,to,Biz::consultmsgType::OnDutyToVistor == qchatid);
			MainApp::UIFrame::getConversationController()->activeConversation(conversationID);
			MainApp::UIFrame::getConversationController()->moveSessionToTop(conversationID);

			return;
		}
	} 

	QString cid = Biz::MessageUtil::makeSureUserJid(conversationId);
	MainApp::UIFrame::getConversationController()->createNewChatDialog(cid);
	MainApp::UIFrame::getConversationController()->addSimpleChatRosterItem(cid,MainApp::ConversationController::sDefaultExtendPanel);
	MainApp::UIFrame::getConversationController()->activeConversation(cid);
	MainApp::UIFrame::getConversationController()->moveSessionToTop(cid);
}


void MultiDialogContainer::onSearchGroupResult(const QString& conversationId)
{
	QString groupName = Biz::MessageUtil::makeSureUserId(conversationId);
	Biz::GroupListData* pGld = Biz::Session::currentAccount().getGroupsData();
	Biz::GroupSetting* pSetting = NULL;
	if (NULL!=pGld && NULL!= (pSetting=pGld->getGroupSetting(conversationId)) )
	{
		groupName = pSetting->Name();
	}

	MainApp::UIFrame::getConversationController()->createNewGroupChatDialog(conversationId);
	MainApp::UIFrame::getConversationController()->addGroupChatRosterItem(conversationId,MainApp::ConversationController::sDefaultExtendPanel);
	MainApp::UIFrame::getConversationController()->activeConversation(conversationId);
	MainApp::UIFrame::getConversationController()->moveSessionToTop(conversationId);
	ui->lineEdit->setText("");
}



void MultiDialogContainer::onRobotResult(const QString& conversationId)
{
	ui->lineEdit->setText("");
	QString rbtJid = Biz::MessageUtil::makeSureUserJid(conversationId);
	MainApp::UIFrame::getConversationController()->createNewMenuChatDialog(rbtJid);
	MainApp::UIFrame::getConversationController()->addRobotChatRosterItem(rbtJid,"");
	MainApp::UIFrame::getConversationController()->activeConversation(rbtJid);
	MainApp::UIFrame::getConversationController()->moveSessionToTop(rbtJid);
}


bool MultiDialogContainer::eventFilter(QObject *obj, QEvent *event)
{
	QKeyEvent *keyEvent = dynamic_cast<QKeyEvent*>(event);
	if (NULL!=keyEvent && keyEvent->modifiers() == (Qt::ShiftModifier | Qt::AltModifier) && keyEvent->key() == Qt::Key_O && !animationing)
	{
		if (!ui->lineEdit->hasFocus())
		{
			ui->lineEdit->setFocus();
		}

		QPushButton* poptip = new QPushButton(this);
		poptip->setStyleSheet("background-color: rgba(0, 0, 0,0);"
			"border: 1px solid;");
		QPropertyAnimation* popanimation = new QPropertyAnimation(poptip, "geometry" );
		popanimation->setDuration(300);
		popanimation->setStartValue(QRect(0,0,this->width(),this->height()));
		QRect rect = ui->lineEdit->rect();
		QPoint pt = ui->lineEdit->mapToGlobal(rect.topLeft());
		QPoint pt2 = ui->lineEdit->mapToGlobal(rect.bottomRight());
		popanimation->setEndValue(QRect(mapFromGlobal(pt),mapFromGlobal(pt2)));
		connect(popanimation,&QAbstractAnimation::finished,this,&MultiDialogContainer::onAnimationFinish);
		poptip->show();
		popanimation->start();
		animationing = true;
		return true;
	}      

	if (obj == ui->lineEdit) 
	{
		if (event->type() == QEvent::KeyPress) 
		{
			QKeyEvent *keyEvent = dynamic_cast<QKeyEvent*>(event);
			if (NULL == keyEvent)
			{
				return false;
			}
			if (keyEvent->modifiers() == (Qt::ShiftModifier | Qt::AltModifier) && keyEvent->key() == Qt::Key_O)
			{
				return true;
			}
			if (keyEvent->key() == Qt::Key_Down)
			{
				SearchMoveDown();
				return true;
			}             
			else if (keyEvent->key() == Qt::Key_Up)
			{
				SearchMoveUp();
				return true;
			} 
			else if (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter)
			{
				if(m_pSearchUserListWidget->isVisible())
				{
					// 跳转选中item
					SearchSelected();
				}
				else
				{
					// 相应回车搜索
					onSearchTextChanged(ui->lineEdit->text());
				}
				
				return true;
			} 
			else if (keyEvent->key() == Qt::Key_Escape)
			{
				if (NULL!=m_pSearchUserListWidget)
				{
					m_pSearchUserListWidget->hide();
				}
			}
		}else if(event->type() == QEvent::FocusOut)
		{

			if (NULL!=m_pSearchUserListWidget )
			{
				QPoint currsorPos = QCursor::pos();
				QPoint rectPos = m_pSearchUserListWidget->mapFromGlobal(currsorPos);
				if ( !m_pSearchUserListWidget->rect().contains(rectPos))
				{
					m_pSearchUserListWidget->hide();
				}
			}
		}
	}

	if( obj == this )  
	{  
		if(QEvent::WindowActivate == event->type())  
		{  
			emit GloableEventObject::getInstance()->sgMainDialogActivitied(true);

		}  
		if (QEvent::WindowDeactivate == event->type())
		{
			emit GloableEventObject::getInstance()->sgMainDialogActivitied(false);
			if (NULL!=m_pSearchUserListWidget )
			{
				QPoint currsorPos = QCursor::pos();
				QPoint rectPos = m_pSearchUserListWidget->mapFromGlobal(currsorPos);
				if ( !m_pSearchUserListWidget->rect().contains(rectPos))
				{
					m_pSearchUserListWidget->hide();
				}
			}
		}
	}  

#pragma region spliter 左右托
	if (obj == pHandler)
	{
		int ntype = (int)event->type();
		if (QEvent::Enter == event->type())
		{
			pHandler->setStyleSheet("QWidget { "
				"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
				"stop: 0.3 #00000000, stop: 0.5 #CA5100,"
				"stop: 0.5 #CA5100, stop: 0.7 #00000000);"
				" }");
		}
		if (QEvent::Leave == event->type())
		{
			pHandler->setStyleSheet("QWidget { background-color: #00000000 }");
		}
	}

	if (obj == ui->rightpanel)
	{
		if (QEvent::Resize == event->type())
		{
			if (m_pReconnectPushBtn->isVisible())
			{
				m_pReconnectPushBtn->setFixedWidth(ui->rightpanel->width());
			}
		}
	}
#pragma endregion

	if ((obj == ui->staffgroup || obj == ui->staffuser)&&QEvent::MouseButtonDblClick==event->type())
	{
		return true;
	}

	if ( (obj == ui->grouppath || obj == ui->groupdata || obj == ui->user_id || obj == ui->user_email || obj == ui->staffusersgroup || obj == ui->user_name)
		&& QEvent::MouseButtonDblClick==event->type())
	{
		//((QLabel*)obj)->setSelection(0,((QLabel*)obj)->text().length());
	}

#pragma region 会话列表区域的晃入晃出
	if (obj == ui->sessionListPanel)
	{
		//这个功能暂时先移走
		/*  if (QEvent::Enter == event->type())
		{
		ui->menupanel->setVisible(true);
		}
		if (QEvent::Leave == event->type())
		{
		ui->menupanel->setVisible(false);
		animotionDown();
		}
		*/
	}

	if (obj == ui->menupanel)
	{
		if (QEvent::Enter == event->type())
		{
			animotionUp();
		}
		if (QEvent::Leave == event->type())
		{
			animotionDown();
		}
	}
#pragma endregion 会话列表区域的晃入晃出

	return QWidget::eventFilter(obj, event);
}



void MultiDialogContainer::SearchMoveDown()
{
	if (NULL!=m_pSearchUserListWidget && m_pSearchUserListWidget->getcount() > 0)
	{
		m_pSearchUserListWidget->setMoveDown();
	}
}
void MultiDialogContainer::SearchMoveUp()
{
	if (NULL!=m_pSearchUserListWidget && m_pSearchUserListWidget->getcount() > 0)
	{
		m_pSearchUserListWidget->setMoveUp();
	}
}
void MultiDialogContainer::SearchSelected()
{
	if (NULL!=m_pSearchUserListWidget)
	{
		m_pSearchUserListWidget->selectItem();
	}
}




void MultiDialogContainer::closeEvent(QCloseEvent *)
{
	Biz::Session::getSettingConfig()->MultiChatDlgWidth(this->width());
	Biz::Session::getSettingConfig()->MultiChatDlgHeight(this->height());
}


QStackedWidget* MultiDialogContainer::getBaseChatDialogStatckWidget()
{
	return ui->webwidgetstack;
}

void MultiDialogContainer::onClose(bool)
{
	this->hide();
	MainApp::Framework::showOrHideMainWindow(0);
}


void MultiDialogContainer::keyPressEvent(QKeyEvent *event)
{
	int a = 9;
	a = 8;
}
void MultiDialogContainer::onAnimationFinish()
{

	QAbstractAnimation* an = (QAbstractAnimation*)sender();
	QWidget* pw = (QWidget*)((QPropertyAnimation*)an)->targetObject();
	pw->hide();
	an->deleteLater();
	pw->deleteLater();
	animationing = false;
}






QStackedWidget* MultiDialogContainer::getLevelStacked()
{
	return ui->levelStacked;
}

QWidget* MultiDialogContainer::getSessionList()
{
	return ui->sessionListPanel;
	//return (QWidget*)pDefaultExtendView;
}


void MultiDialogContainer::onJiagouTabShow()
{
	showCustemWidget(ui->emptysessionpage);
}

void MultiDialogContainer::onJiagouGroupAttached(const QString& groupjid)
{
	showCustemWidget(ui->staffgroup);

	Biz::RosterGroup* rGroup = Biz::Session::currentAccount().findRosterGroup(groupjid);

	if (NULL!=rGroup)
	{
		QString groupdata = QString(QStringLiteral("当前部门内一共有%1人")
			.arg(rGroup->getRosterListWithChildren().size()));
		ui->label_2->setText(QStringLiteral("部门:"));

		ui->grouppath->setText(groupjid);
		ui->grouppath->setToolTip(groupjid);
		ui->label_3->setText(QStringLiteral("统计:"));
		ui->groupdata->setText(groupdata);
		ui->openchat->setText(QStringLiteral("创建群组"));
		ui->openchat->setEnabled(true);

		//群图像
		QPixmap pixmap = Biz::PortraitHelper::getGroupPortrait(groupjid);
		pixmap = QPixmap::fromImage(pixmap.toImage().scaled(ui->label->size()));
		ui->label->setPixmap(pixmap);
	}
	else
	{
		//群ID
		ui->label_2->setText("ID:");
		//由于群的在界面上展示很长，故设置的时候取@前面的值
		ui->grouppath->setText(Biz::MessageUtil::makeSureGroupId(groupjid));
		ui->grouppath->setToolTip(groupjid);
		//群名
		QString strGroupName = Biz::Session::getGroupManager()->getGroupNickName(groupjid);
		ui->label_3->setText(QStringLiteral("群名:"));
		strGroupName = MainApp::getMaxLineCountLimitText(strGroupName, 400,1, ui->label_3->font());
		ui->groupdata->setText(strGroupName);

		ui->openchat->setText(QStringLiteral("发起会话"));
		ui->openchat->setEnabled(true);

		//群图像
		QPixmap pixmap = Biz::PortraitHelper::getGroupPortrait(groupjid);
		pixmap = QPixmap::fromImage(pixmap.toImage().scaled(ui->label->size()));
		ui->label->setPixmap(pixmap);

	}
}




void MultiDialogContainer::onJiagouUserAttached(const QString& userid)
{
	showCustemWidget(ui->staffuser);

	if (!userid.isEmpty())
	{
		QString groupName = Biz::Session::currentAccount().getUserGroup(userid);
		QString userName = Biz::Session::currentAccount().getUserNameById(userid);
		if (userName.isEmpty())
		{
			userName = userid;
		}
		ui->staffusersgroup->setText(groupName);
		ui->user_id->setText(userid);
		ui->user_id->setProperty("real_jid",userid);
		ui->user_name->setText(userName);

		ui->user_email->setText(userid+"@qunar.com");
		ui->openchat_simple->setEnabled(true);
		QPixmap pixmap = Biz::PortraitHelper::getUserPortrait(userid, 200);
		pixmap.setDevicePixelRatio(this->devicePixelRatio());
		//pixmap = QPixmap::fromImage(pixmap.toImage().scaled(ui->user_headimage->size()));
		ui->user_headimage->setPixmap(pixmap);

#ifdef QCHAT
		ui->label_email->setVisible(false);
		ui->user_email->setVisible(false);
#endif

	}
	else
	{
		ui->openchat_simple->setEnabled(false);
		ui->staffusersgroup->setText("");
		ui->user_id->setText("");
		ui->user_name->setText("");
		ui->user_email->setText("");
	}

}



void MultiDialogContainer::onOpenGroupChat()
{

	QString groupName =  ui->grouppath->toolTip();//ui->grouppath->text();
	if (groupName.isEmpty())
	{
		return;
	}
	Biz::RosterGroup* rGroup = Biz::Session::currentAccount().findRosterGroup(groupName);
	if (NULL!=rGroup)
	{
		int member = rGroup->getRosterListWithChildren().size(); 
		int tipCount = 10;
		if (member > tipCount)
		{
			QString message =  QString(QStringLiteral("您当前邀请了%1人，已超过%2人，请确定邀请所有人进群吗？").arg(member).arg(tipCount));
			bool ret = MainApp::UIFrame::getNotifyCenterController ()->alertMessageWithCancle(message);
			if (!ret)
			{
				return;
			}
		}
		// 创建个新群
		QStringList userlst;
		QList<Biz::RosterNode*> nodelst;
		rGroup->findNode("",nodelst,false);
		foreach(Biz::RosterNode* pNode,nodelst)
		{
			userlst.push_back(pNode->userId);
		}
		auto callback = mReceiver->createCallback<QString>([this](const QString& groupjid){
			Log::e(QString("CreateNewGroup::onCreateGroupBtnClick callback success"));
			MainApp::UIFrame::getConversationController()->createNewGroupChatDialog(groupjid);
			MainApp::UIFrame::getConversationController()->addGroupChatRosterItem(groupjid,MainApp::ConversationController::sDefaultExtendPanel);
			MainApp::UIFrame::getConversationController()->activeConversation(groupjid);

		},[this]{
			Log::e(QString("CreateNewGroup::onCreateGroupBtnClick callback fail"));
			MainApp::UIFrame::getNotifyCenterController ()->alertMessage (T_("CreateGroupMsg_Error"));

		});
		MainApp::UIFrame::getGroupsController()->createNewGroup(userlst,callback);
	}
	else
	{
		QString groupJid = Biz::MessageUtil::makeSureGroupJid(groupName);

		MainApp::UIFrame::getConversationController()->createNewGroupChatDialog(groupJid);
		MainApp::UIFrame::getConversationController()->addGroupChatRosterItem(groupJid,MainApp::ConversationController::sDefaultExtendPanel);
		MainApp::UIFrame::getConversationController()->activeConversation(groupJid);
		MainApp::UIFrame::getConversationController()->moveSessionToTop(groupJid);

	}
}

void MultiDialogContainer::onOpenUserChat()
{
	if (mbtnCollerofChange)
	{
		//Biz::Session::getLoginManager()->doSignoutXmpp();
		//MainApp::Framework::onLogout();
		//this->close();
		//切换到该账号
		//弹出一个登录框
		QProcess process(this);

		QString curPath = qApp->applicationFilePath();

#ifdef _WINDOWS

		curPath = curPath.replace("/","\\");
		process.startDetached(curPath);
#else
		QProcess::execute(curPath);
#endif // _WINDOWS

	}
	else
	{
		QString userid =  ui->user_id->property("real_jid").toString();
		QString displayName = ui->user_name->text();

		if (userid.isEmpty() || userid == "NULL")
		{
			return;
		}
		QString conversationId = Biz::MessageUtil::makeSureUserJid(userid);
		//这个地方区分一下点击的是机器人的“发起会话”按钮，还是其他的
		if (MainApp::UIFrame::getConversationController()->IsUserIdInAllRobotList(conversationId))
		{
			MainApp::UIFrame::getConversationController()->createNewMenuChatDialog(conversationId);
			MainApp::UIFrame::getConversationController()->addRobotChatRosterItem(conversationId,"");
			MainApp::UIFrame::getConversationController()->activeConversation(conversationId);
			MainApp::UIFrame::getConversationController()->moveSessionToTop(conversationId);
		}
		else
		{
			MainApp::UIFrame::getConversationController()->createNewChatDialog(conversationId);
			MainApp::UIFrame::getConversationController()->addSimpleChatRosterItem(conversationId,MainApp::ConversationController::sDefaultExtendPanel);
			MainApp::UIFrame::getConversationController()->activeConversation(conversationId);
			MainApp::UIFrame::getConversationController()->moveSessionToTop(conversationId);
		} 
	}


}

void MultiDialogContainer::onRecentTabShow()
{

}




void MultiDialogContainer::InitSubscriptionListView()
{
	connect(Biz::Session::getConverSationManager(),&Biz::ConverSationManager::sgCloseRobotDialog,this,&MultiDialogContainer::onCloseRobotWidget);
	connect(Biz::Session::getLoginManager(),&Biz::LoginManager::sgLoginStatusChange,this,&MultiDialogContainer::onLoginStatusChange);

}

void MultiDialogContainer::showEmptyChatdialog()
{
	mbtnCollerofChange = false;
	showCustemWidget(ui->emptysessionpage);
}


void MultiDialogContainer::showChatDialog(QWidget* view)
{
	mbtnCollerofChange = false;
	showWebWidget(view);
}


void MultiDialogContainer::showWorkPlaceWidget()
{
	showWebWidget(m_pWorkPlaceView);
	//每次都加载一下页面，目的是让页面上小红点进行更新
	if (NULL!=m_pWorkPlaceView)
	{
		QString url = Biz::Session::getSystemConfig ()->getHttpFileHost ()  + Biz::Session::getEditableSettings()->getworkplace();
		m_pWorkPlaceView->load (QUrl(url));
	}
	mbtnCollerofChange = false;
}


void MultiDialogContainer::onFriendsUserAttached(const QString& userid, bool btype)
{
	mbtnCollerofChange = false;
	ui->staffuser->setStyleSheet(QStringLiteral("QWidget{font-family:%1;}").arg("微软雅黑"));
	ui->staffuser->setStyleSheet(
		"QPushButton{"
		"font-size:16px;"
		"border-radius: 0px;"
		"color:#FFFFFF;"
		"background-color:#3DCE3D;"
		"}"
		"QPushButton:disabled{"
		"background-color:#9DE69D;"
		"	}"
		"QPushButton:hover{"
		"	background-color:#38C738;"
		"	}"
		"QPushButton:pressed{"
		"	background-color:#2FB82F;"
		"	}"
		"	QLabel"
		"	{"
		"color:#A6A6A6;"
		"		font-size:16px;"
		"	}"

		"	QLineEdit#user_id,#user_name"
		"	{"
		"color:#444444;"
		"		font-size:16px;"
		"border:none;"
		"background:#00000000;"
		"readonly:true;"
		"	}"
		);

	showCustemWidget(ui->staffuser);
	if (!userid.isEmpty())
	{
		QString groupName = Biz::Session::currentAccount().getUserGroup(userid);
		QString userName = Biz::Session::currentAccount().getUserNameById(userid);

		ui->staffusersgroup->setText(groupName);
		ui->user_id->setText(Biz::MessageUtil::makeSureUserId(userid));
		ui->user_id->setProperty("real_jid",userid);
		ui->user_name->setText(userName);

		ui->user_email->setText(userid+"@qunar.com");
		ui->openchat_simple->setEnabled(true);
		QPixmap pixmap = Biz::PortraitHelper::getUserPortrait(userid, 200);
		//pixmap = QPixmap::fromImage(pixmap.toImage().scaled(ui->user_headimage->size()));
		pixmap.setDevicePixelRatio(this->devicePixelRatio());
		ui->user_headimage->setPixmap(pixmap);
		if (!btype)
		{
			ui->openchat_simple->setVisible(false);
		}
		else
		{
			ui->openchat_simple->setVisible(true);
		}
#ifdef QCHAT
		ui->label_6->setVisible(false);
		//ui->group_name->setVisible(false);
		ui->staffusersgroup->setVisible(false);
		ui->user_email->setVisible(false);
		ui->label_email->setVisible(false);
		ui->user_email->setVisible(false);
#endif

	}
	else
	{
		ui->openchat_simple->setEnabled(false);
		ui->staffusersgroup->setText("");
		ui->user_id->setText("");
		ui->user_name->setText("");
		ui->user_email->setText("");
	}
}


void MultiDialogContainer::onHDProtraitUpdate(const QString& userjid)
{
	QString thisUserid = ui->user_id->property("real_jid").toString();
	if (Biz::MessageUtil::compareJid(userjid,thisUserid))
	{
		QPixmap pixmap = Biz::PortraitHelper::getUserPortraitWithoutDownload(userjid,200);
		pixmap.setDevicePixelRatio(this->devicePixelRatio());
		ui->user_headimage->setPixmap(pixmap);
	}
}


void MultiDialogContainer::onLoginStatusChange(Biz::LoginStatus oldstatus,Biz::LoginStatus newstatus)
{
	if (newstatus == Biz::LoginStatus_Connect)
	{
	}
}

void MultiDialogContainer::updateUnReadPositionImage( const QString&id )
{
	// 	 ExtendedSessionListView* pBelongExtend = pDefaultExtendView;
	// 
	// 	 if (m_jid2ChatItemHandle.contains(id))
	// 	 {
	// 		 ChatItemHandles* handle = m_jid2ChatItemHandle[id];
	// 		 pBelongExtend = handle->pExtendedView;
	// 		 if (pBelongExtend != pDefaultExtendView)
	// 		 {
	// 			 // 需要去更新它的父节点
	// 			 QString extendid = pBelongExtend->getLindedId();
	// 			 if (!extendid.isEmpty() && extendid!=id )
	// 			 {
	// 				 pDefaultExtendView->getRosterListView()->updateLinkItemUnReadCount(extendid);
	// 			 }
	// 		 }
	// 	 }
	// 	 pBelongExtend->getRosterListView()->updateUnReadPositionImage(id);

}




void MultiDialogContainer::onCloseRobotWidget(const QString& rbtid)
{
	MainApp::UIFrame::getConversationController()->removeConversation(rbtid);
	Biz::Session::getConverSationManager()->removeChartingImSession(rbtid);
}


void MultiDialogContainer::onTopMostConversationChanged(const QList<Biz::ImSession>& changedSession)
{
	for(Biz::ImSession session:changedSession)
		MainApp::UIFrame::getConversationController()->updateSessionConfigration(session.xmppid,session.configration);
}

SlidingStackedWidget* MultiDialogContainer::getExtendPanelStacked()
{
	return ui->extendListStacked;
}


void MultiDialogContainer::showCustemWidget(QWidget* view)
{
	ui->custemwidgets->raise();
	ui->custemstack->setCurrentWidget(view);
	mbtnCollerofChange = false;
}

void MultiDialogContainer::showWebWidget(QWidget* view)
{
	mbtnCollerofChange = false;
	ui->webwidgets->raise();
	ui->webwidgetstack->setCurrentWidget(view);
}

void MultiDialogContainer::animotionUp()
{
	int totleHieght = ui->sessionListPanel->height();
	int normalHeight = ui->couversationCount->height();
	int fromY = totleHieght-normalHeight;

	int offsetY = 2*32;
	QPropertyAnimation* popanimation = new QPropertyAnimation(ui->menupanel, "geometry" );
	popanimation->setDuration(100);
	popanimation->setEasingCurve(QEasingCurve::OutQuad);
	popanimation->setStartValue(QRect(0,fromY,ui->menupanel->width(),normalHeight));
	popanimation->setEndValue(QRect(0,fromY-offsetY,ui->menupanel->width(),normalHeight+offsetY));
	popanimation->start(QPropertyAnimation::DeleteWhenStopped);
}

void MultiDialogContainer::animotionDown()
{
	int totleHieght = ui->sessionListPanel->height();
	int normalHeight = ui->couversationCount->height();
	ui->menupanel->move(0,totleHieght-normalHeight);
}

void MultiDialogContainer::updateConversationCountTip(int ncount)
{
	QString info = QStringLiteral("共%1组会话，最多%2组").arg(ncount).arg(Biz::Session::getSettingConfig()->MaxSessionLimited());
	ui->couversationCount->setText(info);
}

void MultiDialogContainer::closeAdvWidget()
{
	QTimeLine* pScale = new QTimeLine(300);
	int w = ui->advtool->height();
	connect(pScale,&QTimeLine::valueChanged,[this,w, pScale](qreal x){
		ui->advtool->setFixedHeight((1-x)*w);
	});
	connect(pScale,&QTimeLine::finished,[pScale,this]{
		pScale->deleteLater();
		ui->advtool->setVisible(false);
	});
	pScale->start();
}

#include "jsonobject/adverconfiginfo.h"

void MultiDialogContainer::openAdvWidget(const QList<QSharedPointer<Biz::AdvDataItem>>& imagelist)
{

	//     JPROPERTY(int,adsce); //广告显示时常
	//     JPROPERTY(bool,carousel); //是否轮播
	//     JPROPERTY(int,carouseldelay); //轮播的间隔时间
	//     JPROPERTY(bool,shown); //是否显示 false 则跳过广告
	//     JPROPERTY(bool,allowskip); // 是否允许跳过
	//     JPROPERTY(QString,skiptips); // 允许跳过时的提示信息
	//     JPROPERTY(QList<IJsonSerializeable*>,adlist);
	//     JPROPERTY(quint64, LastUpdateAdvTime);
	QSharedPointer<Biz::AdverConfigInfo> spConfigInfo = Biz::Session::getAdvInforManager()->getAdvConfigInfo();
	if (spConfigInfo.isNull())
		return; // 数据不足
	if (!spConfigInfo->shown())
		return; // 无广告

	ui->widget_18->setCloseable(spConfigInfo->allowskip()); // 可以关闭

	ui->widget_18->showAllPicture(imagelist);

	ui->advtool->setVisible(true);

	//广告显示框展示的特效
	QTimeLine* pScale = new QTimeLine(300);
	int w = ui->advtool->height();
	connect(pScale,&QTimeLine::valueChanged,[this,w, pScale](qreal x){
		ui->advtool->setFixedHeight(x*w);
	});

	connect(pScale,&QTimeLine::finished,[pScale,this]{
		pScale->deleteLater();
	});

	pScale->start();
}

void MultiDialogContainer::setSearchViewFocus()
{
	ui->lineEdit->setFocus();
}

void MultiDialogContainer::showCollectionBindUserInfo( const QString&userid )
{
	showCustemWidget(ui->staffuser);

	if (!userid.isEmpty())
	{
		QString userName = Biz::Session::currentAccount().getUserNameById(userid);
		if (userName.isEmpty())
		{
			userName = userid;
		}
		ui->staffusersgroup->setVisible(false);
		ui->user_id->setText(userid);
		ui->user_id->setProperty("real_jid",userid);
		ui->user_name->setText(userName);

		ui->label_6->setVisible(false);
		ui->openchat_simple->setEnabled(true);
		ui->openchat_simple->setText(QStringLiteral("切换到该账号"));
		QPixmap pixmap = Biz::PortraitHelper::getUserPortrait(userid, 200);
		pixmap.setDevicePixelRatio(this->devicePixelRatio());
		//pixmap = QPixmap::fromImage(pixmap.toImage().scaled(ui->user_headimage->size()));
		ui->user_headimage->setPixmap(pixmap);


		ui->label_email->setVisible(false);
		ui->user_email->setVisible(false);
		mbtnCollerofChange = true;

	}
}

QWidget* MultiDialogContainer::getCombinationList()
{
	return ui->combinationPanel;
}

SlidingStackedWidget* MultiDialogContainer::getCombinationExtendPanelStacked()
{
	return ui->combinationstacked;
}


void MultiDialogContainer::onLoadMessageProgress(bool end)
{
	ui->loadmsgprogress->setVisible(!end);
	end ? 
		m_pLoadMessageProgressTimeer->stop():
		m_pLoadMessageProgressTimeer->start();
}

void MultiDialogContainer::onNoticeTipConversationChanged( const QList<Biz::ImSession>& changedSession )
{
	for(Biz::ImSession session:changedSession)
		MainApp::UIFrame::getConversationController()->updateSessionConfigration(session.xmppid,session.configration);
}

void MultiDialogContainer::showNoteInfor()
{

	// 	ui->custemwidgets->raise();
	// 	ui->custemstack->setCurrentWidget(ui->noteInfor);
	// 	mbtnCollerofChange = false;
	showCustemWidget(ui->noteInfor);
}

void MultiDialogContainer::onMoreSelectResult(const QString& id, const QString& searchKey)
{
	auto callback = mReceiver->createCallback<QList<Biz::SearchResulteItemGroupModule>>(
		[this](const QList<Biz::SearchResulteItemGroupModule>& results){
			m_pSearchUserListWidget->setListData(results);

	},[]{});

	Biz::Session::getConverSationManager()->searchInforMore(id,searchKey, callback);
}

void MultiDialogContainer::onHistoryRecord()
{
	CommentWebViewSingleton::getInstance()->showHistoryRecordDlg();
}
