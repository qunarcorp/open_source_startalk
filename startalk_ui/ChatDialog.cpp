#include "ChatDialog.h"
#include "ui_ChatDialog.h"
#include <time.h>
#include <QClipboard>
#include <QPalette>
#include <QTextBlock>
#include <QDesktopServices>
#include "Account.h"
#include "Session.h"
#include "XmppMessage.h"
#include "UserSettingData.h"
#include "RosterProfile.h"
#include "AccountData.h"
#include "ConfigureHelper.h"
#include "CallbackReceiver.h"
#include "SettingData.h"
#include "WebPage.h"
#include "ChatCommObject.h"
#include "LanguageHelper.h"
#include "StatisticsItem.h"
#include "diywidgit/printscreen/SnipScreenTool.h"
#include "diywidgit/customviews/qframelayout.h"
#include <QFileDialog>
#include <QFontDialog>
#include <QSplitter>
#include <QXmppUtils.h>
#include <QImageReader>
#include <QImage>
#include <QColorDialog>
#include "AddGroupDialog.h"
#include "UiHelper.h"
#include "portraithelper.h"
#include "Historyrecorddialog.h"
#include "SystemConfigData.h"
#include "gloableeventobject.h"
#ifdef QCHAT
#include "Transferchatdialog.h"
#endif
#include "userminiprofile.h"
#include "Ordermanagedialog.h"
#include "UiHelper.h"

#include "UserVcardManager.h"
#include "conversationmanager.h"
#include "MessageManager.h"
#include "EmotionManager.h"
#include "UserVcardManager.h"
#include "accountmanager.h"

#include "advertinfodialog.h"
#include "TitlebarWidget.h"
#include "DownloadManager.h"
#include "draggablewebview.h"
#include "accountmanager.h"
#include "WebService.h"
#include "UIFrame.h"
#include "ConversationController.h"
#include "MainDialogController.h"


#include "messagebubble/MessageParser.h"
#include "messagebubble/MessageUnreadMessageTip.h"
#include "ChatDisplayOptionWidget.h"
#include "ChatWebPage.h"

#include "Ordermanagedialog.h"

#include "jsonobject/noteinfo.h"
#include "jsonobject/product.h"
#include "dataapplication.h"
#include "jsonobject/productinfo.h"

#include "CloseableButtonView.h"
#include "editablesettings.h"
#include "vidioandaudiodialog.h"
#include "UIFrame.h"
#include "ConversationController.h"
#include "NotifyCenterController.h"
#include "setpwdinfor.h"
#include "qcloudmanager.h"
#include "aescommon.h"
#include "passwordinput.h"
#include "encryptchatcontroller.h"
#include "encryptchatdialog.h"
#include "jsonobject/systemnotify.h"
#include "noticeinfotip.h"
#include "constants.h"
#include <QTextCursor>

ChatDialog::ChatDialog(MultiDialogContainer* cntainer,QWidget *parent)
    : BaseChatDialog(parent)
    ,ui(new Ui::ChatDialog)
    , pContainer(cntainer)
    , mTypingTick(QDateTime::currentMSecsSinceEpoch())
    ,mEditMenu(NULL)
    ,mActionCopy(NULL)
    ,mActionPast(NULL)
    ,mActionSelectAll(NULL)
    ,mbhover(false)
	,m_bInhertAttribute(true)
	,m_EncryptChatdlg(NULL)
{
    ui->setupUi(this);

    setupWebView (ui->webView);
    using namespace Qt;
    auto remove = WindowTitleHint;
    auto add = FramelessWindowHint | WindowMinMaxButtonsHint;
    setAttribute(Qt::WA_AlwaysShowToolTips, true);
    setAttribute(Qt::WA_TranslucentBackground, true); 
    //setAutoFillBackground(true);
    overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));
#ifdef QCHAT
	setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
	ui->leJid->setVisible(false);
#else
    setWindowIcon(QIcon(":/Images/Deal.ico"));
#endif

    mReceiver = new Biz::CallbackReceiver(this);

    
    connect(ui->sendbtn, &QPushButton::clicked, this, &ChatDialog::onSendClick);

    connect(ui->textEdit, &TextEdit::textChanged, this, &ChatDialog::onInputChanged);
    connect(mCommObject, &ChatCommObject::sgQueryMore, this, &ChatDialog::onHistoryMore);
	


    connect(ui->trace,&QPushButton::clicked,[this](){
        emit pContainer->sgTracertUser(Biz::MessageUtil::makeSureUserId(conversationId()));
    });


    connect(SnipScreenTool::getInstance(), &SnipScreenTool::sgFinish, this, &ChatDialog::onSnapFinish);
    connect(SnipScreenTool::getInstance(), &SnipScreenTool::sgCancel, this, &ChatDialog::onSnapCancel);


    mPage = new ChatWebPage(this); 
    loadNormalHtml();
	 

#if (QT_VERSION < QT_VERSION_CHECK(5, 6, 0))
	connect(mPage, &WebPage::openLink, this, &BaseChatDialog::linkClicked);
//	mPage->setLinkDelegationPolicy(QWebPage::DelegateAllLinks); 
//	connect(mPage,&QWebPage::linkClicked,this,&BaseChatDialog::linkClicked);
#else

#endif

    ui->textEdit->setFocus();
    ui->textEdit->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->textEdit, &TextEdit::customContextMenuRequested, this, &ChatDialog::onShowEditMenu);
    ui->border->setVisible(false);

    //对textedit进行设置
    ui->textEdit->setAcceptDrops(false);
    ui->frametextedit->setAcceptDrops(true);
    ui->frametextedit->installEventFilter(this);

    ui->webviewFrame->setAcceptDrops(true);
    ui->webviewFrame->installEventFilter(this);
    ui->webView->installEventFilter(this);

	int nToolFunctionMask = DISABLEFUNCTION::BTN_ALL_FUNCTION;
	// 个人消息要去掉 机器人，会话转移，快速回复，关闭会话 的功能 
	nToolFunctionMask = nToolFunctionMask & ~(BTN_ROBOT|BTN_TRANS|BTN_CLOSESESSION|BTN_QUICK);
#ifndef QCHAT
	nToolFunctionMask = nToolFunctionMask & ~(BTN_QUICK);
#endif // !QCHAT

	// 低于 5.6 版本需要关闭 音视频功能 QChat 也关闭QChat
#ifdef QCHAT
	nToolFunctionMask = nToolFunctionMask& (~BTN_VIDIOAUD);
#elif (QT_VERSION < QT_VERSION_CHECK(5, 6, 0))
	nToolFunctionMask = nToolFunctionMask& (~BTN_VIDIOAUD);
#endif // DEBUG

    //对单对单聊天时，群的建立
	if (Util::PlatfromCode::PLATFROM_QCHAT == Util::nPlatformType)
	{
		//屏蔽发送邮件按钮
		ui->sendmail->setVisible(false);
		// 禁用查看组织架构按钮,是否需要显示需要根据登陆者的身份来
		ui->trace->setVisible(false);
		// 启用显示产品扩展框按钮
		ui->showProduct->setVisible(true);
		ui->showProduct->setCheckable(true);

		nToolFunctionMask = nToolFunctionMask& (~BTN_RCODE);
	} else {
		ui->showProduct->setVisible(false);
	}

	ui->toolbar->setBtnEenable(nToolFunctionMask);

    connect(ui->pushButton_muc, &QPushButton::clicked, [this](bool){
		this->showSigleCreateMuc();
	} );
    ui->pushButton_muc->setToolTip(QStringLiteral("创建群聊天"));

   
	connect(ui->showProduct, &QPushButton::clicked, [this](bool bChecked){
		MainApp::UIFrame::getConversationController()->setChatDialogRightPanelVisible(bChecked);
	});
	connect(ui->productbtn, &QPushButton::clicked, this, &ChatDialog::onpbAdvertInfo);
	connect(Biz::Session::getConverSationManager(), &Biz::ConverSationManager::sgShowProductInfo, this, &ChatDialog::doShowProductInfo);

    connect(mCommObject,& ChatCommObject::sgShowNewMessageTip,this, &ChatDialog::onShowUnreadMsgPop);
    connect(mCommObject, &ChatCommObject::sgShowUpUnreadMessageTip,this,&ChatDialog::onShowUnreadMessageTip);
    connect(mCommObject,& ChatCommObject::sgHideNewMessageTip,this, &ChatDialog::onHideUnreadMsgPop);
    connect(mCommObject, &ChatCommObject::sgTransChatRecord, [this](const QString& from){
		return this->showTransChatHistory(from);
	});

    connect (mCommObject,&ChatCommObject::sgReplyWechatUser, this, &ChatDialog::onReplyWechatUser);

	connect(mCommObject, &ChatCommObject::sghttpgetapicall, this, &ChatDialog::onhttpgetapicall);


    connect(ui->sendmail,&QPushButton::clicked,[this](bool check){
        QDesktopServices bs;        
        bs.openUrl(QUrl(QString("mailto:%1@qunar.com").arg(Biz::MessageUtil::makeSureUserId(conversationId()))));
    });



    connect(Biz::Session::getUserVcardManager(), &Biz::UserVcardManager::sgOnlineUserChanged,this,&ChatDialog::onUpdatePresence);
    ui->name->installEventFilter(this);
    ui->leJid->installEventFilter(this);
    ui->leNotice->installEventFilter(this);
    ui->undbclicked->installEventFilter(this);
    ui->widget_4->installEventFilter(this);
    ui->sendbtn->installEventFilter(this);

    //离线消息的相应
    connect(Biz::Session::getConverSationManager(), &Biz::ConverSationManager::sgReloadConversationMsg, this, &ChatDialog::onReloadSimpleOfflineMsg);

	mGetHistoryMessageTimerout.setDuration(1000*8);
    connect(&mGetHistoryMessageTimerout,&QTimeLine::finished,[this](){
        Log::e("get more chardialog history timeout");
        this->doMergeMessageCache(QSharedPointer<Biz::MessageListData>());
    });


    mTypingFlagObtain.setDuration(1000*5);
    connect(&mTypingFlagObtain,&QTimeLine::finished,[this]()
	{
#ifdef QCHAT
		this->ui->typing->setVisible(false);
#else
		this->ui->typing->setVisible(true);
		//心情短语
		ui->typing->setToolTip(mMoodInfo);
		QString strlimit = MainApp::getMaxLineCountLimitText(mMoodInfo, 280, 1, ui->typing->font());
		ui->typing->setText(strlimit); 
#endif 
		
	});
    ui->typing->setVisible(false);
    ui->productbtn->setVisible(false);

#ifndef _WINDOWS
	ui->toolbar->setBtnDisable(BTN_RCODE|BTN_HISTORYLOCAL|BTN_VIDIOAUD);
#endif
	
	
	connect(Biz::Session::getConverSationManager(), &Biz::ConverSationManager::sgTransferResult, this, &ChatDialog::onTransferReturnResult);
    connect(&Biz::Session::currentAccount(), &Biz::Account::sgChatWebUpdateStatus, this, &ChatDialog::onChatWebUpdateStatus);
    connect(&Biz::Session::currentAccount(), &Biz::Account::sgTransferResultInfor, this, &ChatDialog::onTransferInfor);
	connect(&Biz::Session::currentAccount(), &Biz::Account::sgTransferFailInfor, this, &ChatDialog::onTranferFailInfor);
    connect(Biz::Session::getConverSationManager(), &Biz::ConverSationManager::sgShowWelcome, this, &ChatDialog::doShowWelcome);
    this->setupTextEdit (ui->textEdit);
    connect(Biz::Session::getUserVcardManager(), &Biz::UserVcardManager::sgUseVcardChanged,this,&ChatDialog::onVcardUpdate);
    connect(Biz::Session::getUserVcardManager(), &Biz::UserVcardManager::sgPortraitUpdate, this, &ChatDialog::onRosterCardUpdate);

    connect(GloableEventObject::getInstance(), &GloableEventObject::sgFontSizeChange, this, &ChatDialog::onGloableFontSizeChanged);
    connect(Biz::Session::getConverSationManager(), &Biz::ConverSationManager::sgShowSystemNotifyInfo, this, &ChatDialog::onShowSystemNotifyInfo);
    hideRightExtendPanel();

    connect(ui->rightwidget,&RightExtendPanel::visibleChange,
        this,&ChatDialog::onRightFunctionPanelVisibleChange);

    connect(ui->rightwidget,&RightExtendPanel::rightClose,
        [this]{
            hideRightExtendPanel();
    });

    connect(ui->toolbar,&ChatToolBar::sgSendFile,this,&ChatDialog::onSelectAndSendFile);
    connect(ui->toolbar,&ChatToolBar::sgSendShake,this,&ChatDialog::onSendShakeMessage);
    connect(ui->toolbar,&ChatToolBar::sgItemSelected,this,&ChatDialog::onSendQuickReplay);
    connect(ui->toolbar,&ChatToolBar::sgShareMessage,this,&BaseChatDialog::onBtnActionShareLocalMessage);
    connect (ui->toolbar,&ChatToolBar::sgOpenInternalUrl,this,&BaseChatDialog::openInternalUrl);
	connect (ui->toolbar,&ChatToolBar::sgSendRequestUrl,this,&BaseChatDialog::sendRequestUrl);

	connect(ui->toolbar,&ChatToolBar::sgCodeHightLight,this,&BaseChatDialog::onCodeHightLight);
	connect(ui->toolbar,&ChatToolBar::sgCodeStyle,this,&BaseChatDialog::onCodeStyle);
	connect(ui->toolbar,&ChatToolBar::sgCodeType,this,&BaseChatDialog::onCodeType);
	connect(ui->toolbar, &ChatToolBar::sgOpenRobot, this, &ChatDialog::onOpenRobot);

	connect(ui->toolbar, &ChatToolBar::sgchatencrypt, this, &ChatDialog::onChatEncrypt);

	connect(Biz::Session::getUserVcardManager(), &Biz::UserVcardManager::sgUserMoodInforChanged, this, &ChatDialog::onUserMoodInforChange);
	connect(Biz::Session::getUserVcardManager(), &Biz::UserVcardManager::sgUserofCity, this, &ChatDialog::onUserOfCity);




    connect(MainApp::UIFrame::getMainDialogController(),&MainApp::MainDialogController::sgMainDialogVisableChange,
        this,&ChatDialog::onMainDialogVisableChange);

    connect(GloableEventObject::getInstance(),&GloableEventObject::sgMainDialogActivitied, 
        this,&ChatDialog::onMainDialogVisableChange);
    
	connect(MainApp::UIFrame::getConversationController(),&MainApp::ConversationController::sgRobotSendMsg,
		this,&ChatDialog::onRobotSendMsg);

	QFrameLayout* pFunctionsLayout = new QFrameLayout(ui->chattitle);
	pFunctionsLayout->appendWidget(ui->infopannel,ALINE_FILL);
	pFunctionsLayout->appendWidget(ui->funtionpanel,ALINE_TOP|ALINE_RIGHT,QMargins(0,1,130,0));
	pFunctionsLayout->appendWidget(ui->resourceinfo,ALINE_BOTTOM|ALINE_RIGHT,QMargins(0,30,72,1));


    ui->platformIcon->setVisible(false);
	ui->headerimage->installEventFilter(this);
	ui->status->setVisible(false);

    QFrameLayout* pWebFrameLayout = new QFrameLayout(ui->webviewFrame);
    pWebFrameLayout->appendWidget(ui->webView,ALINE_FILL);
    pWebFrameLayout->appendWidget(mpUpUnread,ALINE_RIGHT|ALINE_BOTTOM,QMargins(0,0,20,30));
    pWebFrameLayout->appendWidget(m_pShareToButton,ALINE_BOTTOM|ALINE_HCENTER,QMargins(0,0,0,30));

	//隐藏图像的
	ui->name->setCursor(QCursor(Qt::PointingHandCursor));
	ui->headerimage->setCursor(QCursor(Qt::PointingHandCursor));
	//隐藏
	ui->down->setVisible(false);
	ui->menupanel->setVisible(false);
	ui->dealing->setVisible(false);
	ui->btnfilter->setVisible(false);
	
	connect(ui->toolbar, &ChatToolBar::sgSendProductCard,this, &BaseChatDialog::onSendProductCard);

	//音频和视频的触发响应
	connect(ui->toolbar, &ChatToolBar::sgAudioAction, this, &ChatDialog::onAudioChat);
	connect(ui->toolbar, &ChatToolBar::sgVidioAction, this, &ChatDialog::onVidioChat);

	//加密部分的内容，应该放到encryptchatcontroller中去实现
	connect(MainApp::UIFrame::getEncryptChatcontroller(), &EncryptChatController::sgCancelEncryptChat, this,
		&ChatDialog::onCancelEncryptChat);

	connect(MainApp::UIFrame::getEncryptChatcontroller(), &EncryptChatController::sgDecryptChat, this,
		&ChatDialog::onDecryptChat);

	connect(MainApp::UIFrame::getEncryptChatcontroller(), &EncryptChatController::sgEncryptChat, this,
		&ChatDialog::onEncryptChat);

	connect(MainApp::UIFrame::getEncryptChatcontroller(), &EncryptChatController::sgCloseEncryptChat, this,
		&ChatDialog::onCloseEncryptChat);


	connect(Biz::Session::getConverSationManager(), &Biz::ConverSationManager::sgEncryptMsgInfo, this, &ChatDialog::onEncryptMsgInfo);
	connect(mCommObject, &ChatCommObject::sgGroupPopMenu, this, &ChatDialog::onPopMenu);
	connect(Biz::Session::getUserVcardManager(), &Biz::UserVcardManager::sgPortraitUpdate, this, &ChatDialog::onPortraitUpdate);
	connect(MainApp::UIFrame::getEncryptChatcontroller(), &EncryptChatController::sgLocalArgeeOrRefuse, this, &ChatDialog::onLocalArgeeOrRefuse);
	setTextEditStyle();
}


ChatDialog::~ChatDialog()
{
    ui->webView->deleteLater();
    delete ui;
    ui = NULL;
}

void ChatDialog::onLoadRoster( const QString& userID, const QString& displayName )
{
	 Q_ASSERT(!displayName.isEmpty());
    this->setWindowTitle(displayName);

	ui->name->setText(displayName);


    ui->leJid->setText(Biz::MessageUtil::makeSureUserId(userID));
    ui->border->setVisible(true);
    setCounversationId(Biz::MessageUtil::makeSureUserJid(userID));
    ui->toolbar->setConversationId(conversationId());

    QString groupName = Biz::Session::currentAccount().getUserGroup(userID);
	ui->leNotice->setToolTip(groupName);
	setleNotice(groupName);


    doSetHeaderImage();
	
	Biz::Session::getUserVcardManager()->getUserMoodInfobyId(conversationId());
	// 不是Chat会话 更什么数据库 Consult 也会掉过来
	if(getChatType() != Biz::MessageSourceType::consult){
		QSharedPointer<Biz::XmppMessage> msg (new Biz::XmppMessage(conversationId()));
		msg->MsgSourceType(Biz::ChatMessage);
		Biz::Session::getConverSationManager()->saveConversationInfo(msg,NULL);
	}
#ifdef QCHAT
    if (!Biz::Session::currentAccount().getUserNameById(conversationId()).isEmpty())
    {
        ui->trace->setVisible(true);
    }

#endif // QCHAT

    //发送改变字体信号
    if (Biz::Session::getSettingConfig()->SetFontSize())
    {
        InitFontSize();
    }
	ShowInputWillSendMsg();
}

void ChatDialog::onHistoryAppend( const QSharedPointer<Biz::MessageListData>& messageList )
{
	if (messageList.isNull())
	{
		return;
	}
    appendMessage(true, messageList->HasMore(), messageList->getMessageList(), 1);
	int nMessagesize = messageList->getMessageList().size();

	//用了新的方式，这种就不需要了
	//这个地方必须拿到是对方的最后一条聊天记录，如果随便拿最后一条就有问题
	for (int nI = nMessagesize-1; nI >=0; nI--)
	{
		QSharedPointer <Biz::XmppMessage> msg = messageList->getMessageList().at(nI);
		if (!msg.isNull())
		{
			if ( (msg->ConversationID() == conversationId() ) && ( msg->MsgDirection() == Biz::MessageTypeOther) )
			{
				showPlatInfor(msg);
				break;
			}
		}
		
	}

}


void ChatDialog::onTypingMessageReceived(const QSharedPointer<Biz::XmppMessage>& msg)
{
	if (msg.isNull())
	{
		return;
	}
    if(msg->ConversationID() != conversationId()){
        return;
    }

    if (m_bWebLoadFinshed && QTimeLine::NotRunning == mTypingFlagObtain.state())
    {
        mTypingFlagObtain.start();
		
        ui->typing->setVisible(true);
		ui->typing->setText(QStringLiteral("正在输入..."));
    }
}


void ChatDialog::onMessageReceived( const QSharedPointer<Biz::XmppMessage>& msg )
{
	if (msg.isNull())
	{
		return;
	}
    if(msg->ConversationID() != conversationId()){
        return;
    }

    if (!m_bWebLoadFinshed)
    {
        m_lstMsgCatch.push_back(msg);
        Log::e("ChatDialog::onMessageReceived push to msgcatch" + msg->MessageID());
        return;
    }

    updateCurrentTick(msg->UtcTime());
    m_cctext = msg->cctext();
	m_bu = msg->bu();
	// 心情短语
	QString strMoodInfo = mMoodInfo;
	ui->typing->setToolTip(strMoodInfo);
	QString strlimit = MainApp::getMaxLineCountLimitText(strMoodInfo, 280, 1, ui->typing->font());
	ui->typing->setText(strlimit);
	
	

    if (conversationId()!=MainApp::UIFrame::getConversationController()->topConversationId() || 
        !MainApp::UIFrame::getMainDialogController()->isMainDialogActive())
    {
		Biz::AllUserSettingData* psetting = Biz::Session::getSettingConfig();
		if (psetting->ScrollbaronBlew())
		{
			onShowUnreadMessageTip();
			appendMessage(false, false, msg, 2); 
			
		}
		else
		{
			appendUnreadTipMessage(msg);
			// 回话消息
			appendMessage(false, false, msg);
		}
    }
	else
	{
		// 回话消息
		appendMessage(false, false, msg);
	}

	

   showPlatInfor(msg);
}

void ChatDialog::preFormatMessageToHtml(QSharedPointer<Biz::XmppMessage> spMessage,bool isHistory,bool hasMore,bool &bshow)
{
	if (spMessage.isNull())
	{
		return;
	}
    QString channelIdInMsg = spMessage->ChannelId();
    setChannelId(channelIdInMsg);
    if (!isHistory || !ui->rightwidget->isVisible())
    {
        onMessageDispatch(spMessage);
    }

	m_cctext = spMessage->cctext();
	m_bu = spMessage->bu();
}



void ChatDialog::afterSendCode()
{
	ui->toolbar->setCodeHightLight(false);
}



void ChatDialog::onInputChanged()
{
	 
    // 五秒钟发送一个typing
    if (5000 < QDateTime::currentMSecsSinceEpoch()-mTypingTick)
    {

        if(conversationId().isEmpty() || MainApp::UIFrame::getConversationController()->IsUserIdInAllRobotList(conversationId()))
            return;

        QSharedPointer<Biz::XmppMessage> message(new Biz::XmppMessage(conversationId()));
        auto callback = mReceiver->createCallback([this, message]()
        {
            int a = 10;
            a =20;
        }, []{});
        Biz::Session::currentAccount().doSendTypingMessage(message, callback);
        mTypingTick = QDateTime::currentMSecsSinceEpoch();
    }
	appendWillSendMsg();

// 	QTextCursor cursor = ui->textEdit->textCursor();
// 	QTextCharFormat format;
// 	format.setFontFamily(Biz::Session::getSettingConfig()->MFontFamily());
// 	format.setFontWeight(Biz::Session::getSettingConfig()->MFontSize());
// 	format.setForeground(Qt::red);
// 	cursor.setCharFormat(format);
// 	ui->textEdit->setCurrentCharFormat(format);

	//setTextEditStyle();
}



void ChatDialog::getHistoryByPage(int count, quint64 timestamp, Biz::UnitCallback<QSharedPointer<Biz::MessageListData>>* callback)
{
	if (mChatType == CollectionChatType)
	{
		Biz::Session::getMessageManager()->getCollectionHistoryMessageList(mparentId,conversationId(),count,timestamp,callback);
	}
	else
	{
		Biz::Session::getMessageManager()->getHistoryMessageList(conversationId(),count,timestamp,callback);
	}
}


void ChatDialog::onGetMore( quint64 timestamp, int count, bool firstcall, bool breviewmore )
{
	Log::e("ChatDialog  onGetMore begin" );
    if (conversationId().isEmpty())
        return;
    if (firstcall)
    {
        mGetHistoryMessageTimerout.stop();
        mGetHistoryMessageTimerout.start();
    }
    count = timestamp==0?5:count;
    timestamp = timestamp==0? Constant::INT64_MAX_T :timestamp;

    auto callback = mReceiver->createCallback<QSharedPointer<Biz::MessageListData>>([this,firstcall, breviewmore](const QSharedPointer<Biz::MessageListData>& messageList )
    {
		quint64 getmsgendticked =  QDateTime::currentMSecsSinceEpoch();
		Log::e(QString("ChatDialog::onGetMore callback %1 conversationId=%2").arg(getmsgendticked).arg(conversationId()));
		
        Log::e("ChatDialog::onGetMore callback " + conversationId() );
		if (!breviewmore)
		{
			onClearContents();
		}
		mCommObject->jsSetloadStatus(mPage, 1);
        onHistoryAppend(messageList);
        Biz::Session::getConverSationManager()->setConversationMessageRead(conversationId());
        if (firstcall)
		{
            doMergeMessageCache(messageList);

			if (!messageList.isNull())
				setLastInforItem(messageList->getMessageList());
		}
		quint64 getbegintickedtm =  QDateTime::currentMSecsSinceEpoch();
		Log().rt("login---"+QStringLiteral("二人消息加载完") + QString(" -------> loginendime:%1").arg(getbegintickedtm));
		
    }, [this]{ mCommObject->jsSetloadStatus(mPage, 1);});

    
    if (firstcall)
    {
        // 获取当前会话的 所有未读消息，如果数据库里面没有消息，则向上拿五条。
        auto getAllUnreadMessageCallback = mReceiver->createCallback<QSharedPointer<Biz::MessageListData>>([this,count,timestamp,callback](const QSharedPointer<Biz::MessageListData>& unreadmessage )
        {
			Log::e("ChatDialog is first message  unRead callback " );
            disconnect(MainApp::UIFrame::getConversationController(),&MainApp::ConversationController::sgCurrentConversationChange,this,&ChatDialog::onCurrentConversationChange);
            connect(MainApp::UIFrame::getConversationController(),&MainApp::ConversationController::sgCurrentConversationChange,this,&ChatDialog::onCurrentConversationChange);
            disconnect(MainApp::UIFrame::getConversationController(),&MainApp::ConversationController::sgConversationActived,
                this,&ChatDialog::onConversationActived);
            connect(MainApp::UIFrame::getConversationController(),&MainApp::ConversationController::sgConversationActived,
                this,&ChatDialog::onConversationActived);

            if (unreadmessage->getMessageList().isEmpty())
            {
				 Log::e("ChatDialog is first message  unRead is Empty" );
				getHistoryByPage(count,timestamp,callback);
            }
            else
            {
                // 写一个以下为未读消息
                QSharedPointer<Biz::XmppMessage> message(new Biz::XmppMessage(""));
                message->MsgSourceType(Biz::MessageSourceType::RevertMsgType);
                message->MediaType(Biz::MessageMediaType::MediaTypeText);
                message->UtcTime(unreadmessage->getMessageList().at(0)->UtcTime());
                unreadmessage->getMessageList().insert(0,message);
                callback->doCompleted(unreadmessage);

                if (unreadmessage->getMessageList().size()>5)
                {
                    mpUpUnread->setAnchoragePoint(MessageUnreadTip::sKey);
					if ((unreadmessage->getMessageList().size()-1) > 0 )
					{
						mpUpUnread->setUpUnreadText(QStringLiteral("%1条新消息").arg(unreadmessage->getMessageList().size()-1));
						// 由于未读数不好确定，这个功能需要先下掉
						//mpUpUnread->show();
					}
                    
                }
            }

            disconnect(mCommObject, &ChatCommObject::sgHideNewMessageTip,this, &ChatDialog::onHideUnreadMsgPop);
            disconnect(mCommObject, &ChatCommObject::sgHideUpUnreadMessageTip,this,&ChatDialog::onHideUpUnreadMessageTip);
            connect(mCommObject, &ChatCommObject::sgHideNewMessageTip,this, &ChatDialog::onHideUnreadMsgPop);
            connect(mCommObject, &ChatCommObject::sgHideUpUnreadMessageTip,this,&ChatDialog::onHideUpUnreadMessageTip);
            Log::e("ChatDialog::get unread message callback" );
        }, []{ });
		Log::e("ChatDialog  getAllUnreadMessageList begin" );
        Biz::Session::getMessageManager()->getAllUnreadMessageList(conversationId(),getAllUnreadMessageCallback);
    }
    else
	{
		Log::e(QString("ChatDialog not first getHistoryMessageList begin %1 ").arg(mChatType) );
		getHistoryByPage(count,timestamp,callback);
	}
}

void ChatDialog::onHistoryMore( quint64 timestamp, int height )
{
    onGetMore(timestamp, GETHISTORYCOUNTLIMITED, false, true);
}

void ChatDialog::closeEvent(QCloseEvent *event)
{
    Biz::Session::getSettingConfig()->ChatDlgWidth(this->width());
    Biz::Session::getSettingConfig()->ChatDlgHeight(this->height());
    emit sgCloseDlg(conversationId());
}
void ChatDialog::onClose(bool)
{
    this->close();
}

bool ChatDialog::eventFilter(QObject *obj, QEvent *event)
{
    do 
    {
        if (obj == ui->frametextedit)
        {
            if (event->type() == QEvent::DragEnter 
                || event->type() == QEvent::DragMove)
            {
                QDragEnterEvent* pE = (QDragEnterEvent*)event;
                pE->setDropAction(Qt::MoveAction);
                pE->accept();
                QString objNmae = ui->frametextedit->objectName();
                ui->frametextedit->setStyleSheet("QWidget#"+ objNmae + "{border:1px solid #2693D5;}");
                break;
            }

            if (event->type() == QEvent::DragLeave)
            {
                QString style = ui->frametextedit->styleSheet();
                QString objNmae = ui->frametextedit->objectName();
                ui->frametextedit->setStyleSheet("QWidget#"+ objNmae + "{border:none;}");
            }


            if (event->type() == QEvent::Drop)
            {
                QDragEnterEvent* pE = (QDragEnterEvent*)event;
                QString strcurrent = pE->mimeData()->text();
                QString objNmae = ui->frametextedit->objectName();
                ui->frametextedit->setStyleSheet("QWidget#"+ objNmae + "{border:none;}");

#ifndef _WINDOWS
				if (strcurrent.right(2) == "\r\n")
				{
					strcurrent = strcurrent.left(strcurrent.length() - 2);
				}
#endif // _WINDOWS

                dropFileToEdit(strcurrent);
                pE->accept();  

                break;
            }   
            break;
        }


        if (obj==ui->undbclicked || obj == ui->widget_4)
        {
            if (event->type() == QEvent::MouseButtonDblClick)
            {
                return true;
            }
        }
        if (obj == ui->leJid || obj == ui->leNotice )
        {
            if (event->type() == QEvent::MouseButtonDblClick)
            {

                QLabel* plabel = dynamic_cast<QLabel*>(obj);
                if (NULL!=plabel)
                    plabel->setSelection(0,plabel->text().size());

                QLineEdit* pEdit = dynamic_cast<QLineEdit*>(obj);
                if (NULL!=pEdit)
                    pEdit->selectAll();

                return true;
            }
        }
		if (obj == ui->name)
		{
			if (event->type() == QEvent::MouseButtonPress && m_bInhertAttribute)
			{
				onShowChatUserInfor();
				return true;
			}
			if (event->type() == QEvent::Enter)
			{
				mbhover = true;
				ui->name->repaint();
				return true;
			}
			if (event->type() == QEvent::Leave)
			{
				mbhover = false;
				ui->name->repaint();
				return true;
			}
			
		}
		if (obj == ui->headerimage)
		{
			if ((event->type() == QEvent::MouseButtonDblClick || event->type() == QEvent::MouseButtonPress) && m_bInhertAttribute)
			{
				onShowChatUserInfor();
				return true;
			}
		}
       

        if (obj == ui->webviewFrame)
        {
            if (event->type() == QEvent::DragEnter 
                || event->type() == QEvent::DragMove)
            {
                QDragEnterEvent* pE = (QDragEnterEvent*)event;
                if (ui->webView != pE->source())
                {
                    QString objNmae = ui->webviewFrame->objectName();
                    ui->webviewFrame->setStyleSheet("QWidget#"+ objNmae + "{border:1px solid #2693D5;}");
                    pE->setDropAction(Qt::MoveAction);
                    pE->accept();
                }
                break;
            }

            if (event->type() == QEvent::DragLeave)
            {
                QString objNmae = ui->webviewFrame->objectName();
                ui->webviewFrame->setStyleSheet("QWidget#"+ objNmae + "{border:none;}");
            }

            if (event->type() == QEvent::Drop)
            {
                QDragEnterEvent* pE = (QDragEnterEvent*)event;

				webview *source =
					qobject_cast<webview *>(pE->source());

                if (!source) {
                    QString strcurrent = pE->mimeData()->text();
                    dropFileToWebArea(strcurrent);
                    pE->accept();  

                    QString objNmae = ui->webviewFrame->objectName();
                    ui->webviewFrame->setStyleSheet("QWidget#"+ objNmae + "{border:none;}");
                }

                break;
            }
        }
    } while (false);

    return BaseChatDialog::eventFilter(obj, event);
}

void ChatDialog::onSnapFinish(const QString& wid)
{
	if(conversationId() != wid)
        return;
    QString localPath = Biz::ConfigureHelper::user_ImagesPath(Biz::Session::currentAccount().accountData().UserID());
    QString fileName = localPath + QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz.png");
    bool bret = QApplication::clipboard()->pixmap().save(fileName, "PNG");
	if (!bret)
	{
		Log::e(QString("ChatDialog::onSnapFinish save jietu file is not fail"));
	}


    ui->textEdit->insertImage(fileName);
    //发送图片
    //SendPic(fileName);
    ui->textEdit->setFocus();

    //如果隐藏了，就显示出来
    Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
    if (settingconfig->SetJietu())
    {
        emit GloableEventObject::getInstance()->sgShowMainWidge();
    }

}

void ChatDialog::onSnapCancel(const QString& wid)
{
	if(conversationId() != wid)
        return;
    ui->textEdit->setFocus();
}
void ChatDialog::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("text/uri-list"))
    {
        event->acceptProposedAction();
    }
}
void ChatDialog::dropEvent(QDropEvent *event)
{
    //     QList<QUrl> urls = event->mimeData()->urls();
    //     if (urls.isEmpty())
    //     {
    //         return;
    //     }
    // 
    //     foreach(QUrl url,urls){
    //         QString filePath = url.toLocalFile();
    //         appendLocalMedia(filePath);
    //     }
}







void ChatDialog::onRosterCardUpdate(const QString& jid)
{
    if (Biz::MessageUtil::compareJid(jid,conversationId()))
    {
        doSetHeaderImage();
    }
}

void ChatDialog::onShowUnreadMsgPop(const QString& nickname, const QString& messageid)
{
    mpUpUnread->setDownUnreadText(QStringLiteral("有新消息"));
    mpUpUnread->setAnchoragePoint(messageid);
    //mpUpUnread->show();

}

void ChatDialog::onHideUnreadMsgPop()
{
    if (MainApp::UIFrame::getConversationController()->topConversationId()==conversationId() && CloseableButtonView::ShowType::ST_DOWNUNREAD==mpUpUnread->getShowType())
    {
        mpUpUnread->hide();
    }
}


void ChatDialog::showSigleCreateMuc()
{
	QString conversion = conversationId();
	MainApp::UIFrame::getMainDialogController()->showCreateGroupDialog(conversion);
} 

void ChatDialog::updatePresence(const QString& userId, int status)
{
    doSetHeaderImage();
}


void ChatDialog::onUpdateVoiceImage(const QString& messageid,const QString& img)
{
	mCommObject->updateVoiceImage(mPage, messageid, img);
}

void ChatDialog::dropFileToEdit(const QString& filePath)
{
    //根据拖拽得到的url,在map中找Localcopy
    QString strLocpy = getLocalCopyByUrl(filePath);
    if (strLocpy.isEmpty())
    {
        return;
    }

    //把路径切换到orgin文件夹下
    QString strFileFiler;
    QString strFileName;
    QString newFile = Biz::ConfigureHelper::getOrginFromPath(strLocpy/*filePath*/, strFileName, strFileFiler);

    QString localPath = newFile;//filePath;//newFile;//filePath;
    bool b = QFile::exists(newFile/*filePath*/);
    if (0 == localPath.indexOf("file:///",0,Qt::CaseInsensitive))
    {
        localPath = localPath.mid(QString("file:///").length());
    }


    if (QFile::exists(localPath))
    {
        QString fileExtern = localPath.right(QString(".ico").length());
        if (0!=fileExtern.compare(".ico"))
        {
            appendLocalPicture(localPath);
        }
    }
    else
    {
        //如果不存在，则要下载
        auto callbackOrgin = mReceiver->createCallback<QString>([this](QString localPath)
        {

            ui->textEdit->insertPlainText(localPath);
            ui->textEdit->setFocus();
            ui->textEdit->ensurePolished();

        }, []{});

        if(!currentImageurlSrc.isEmpty())
        {
            Biz::Session::getDownLoadManager()->downloadFile(currentImageurlSrc, strFileName,strFileFiler,"",false,callbackOrgin);
        }
    }
}

void ChatDialog::dropFileToWebArea(const QString& filePath)
{
    //把路径切换到orgin文件夹下
    QString localPath = filePath;
    if (0 == localPath.indexOf("file:///",0,Qt::CaseInsensitive))
    {
        localPath = localPath.mid(QString("file:///").length());
    }

    if (QFile::exists(localPath))
    {
        appendLocalFile(localPath);
    }
}

void ChatDialog::showEvent(QShowEvent *)
{
	QString groupName = Biz::Session::currentAccount().getUserGroup(conversationId());
	ui->leNotice->setToolTip(groupName);
	setleNotice(groupName);

    ui->textEdit->activateWindow();
    ui->textEdit->setFocus();


	QString strText = ui->leJid->text();
	QFontMetrics fontMetrics(ui->leJid->font());
	ui->leJid->setFixedWidth(350);
	QString strlimit = MainApp::getMaxLineCountLimitText(strText, 350, 1, ui->leJid->font());
	ui->leJid->setText(strlimit);
	ui->leJid->setFixedWidth(fontMetrics.width(strlimit) + 10);

	//心情短语
	strText = ui->typing->text();
	strlimit = MainApp::getMaxLineCountLimitText(strText,280, 1, ui->typing->font());
	ui->typing->setText(strlimit);

	//userid
	strText = ui->leNotice->toolTip();
	setleNotice(strText);


	if (mPage && mCommObject)
	{
		mCommObject->setcounthtmlMsgCount(mPage, Biz::Session::getEditableSettings()->ChatHistoryMsgCount());
	}


}

void ChatDialog::onLoadRosterDisplayname(const QString& userID, const QString& displayName)
{
    this->setWindowTitle(displayName);

    Q_ASSERT(!displayName.isEmpty());
	
    ui->name->setText(displayName);
	
    ui->leJid->setText(Biz::MessageUtil::makeSureUserId(userID));

    ui->border->setVisible(true);
    QString groupName = Biz::Session::currentAccount().getUserGroup(userID);
	ui->leNotice->setToolTip(groupName);
    ui->leNotice->setText(groupName);

    doSetHeaderImage();
}

void ChatDialog::onUpdatePresence(const QStringList& onlineUsers)
{
    doSetHeaderImage();
}


void ChatDialog::getImageSize(int& w,int& h)
{
    int rawW = w;
    int rawH = h;


    int maxw = ui->webView->width()*0.6; //最大60%宽
    if (maxw!=0)
    {
        // rw,rh等比缩放
        if (rawW > maxw)
        {
            w = maxw;
            h = maxw*rawH/rawW;
        }
    }
    else
    {
        w = 0;
        h = 0;
    }
}



void ChatDialog::onReloadSimpleOfflineMsg(const QString &userid)
{

	if (Biz::MessageUtil::compareJid(userid,conversationId()))
	{
		
		m_bWebLoadFinshed = false;
		onGetMore(Constant::INT64_MAX_T, 10, true);
    }
}

void ChatDialog::onLoadHtmlFinish(bool b)
{
	quint64 getmsgendticked =  QDateTime::currentMSecsSinceEpoch();
	Log::e(QString("ChatDialog::onLoadHtmlFinish  %1 conversationId=%2").arg(getmsgendticked).arg(conversationId()));
	onSetHistoryMsgCount( Biz::Session::getEditableSettings()->ChatHistoryMsgCount());
	mCommObject->jsSetloadStatus(mPage,0);
    onGetMore(Constant::INT64_MAX_T, 5, true);



}

void ChatDialog::onLoadHtmlFinishByReConn(bool b)
{
	onSetHistoryMsgCount( Biz::Session::getEditableSettings()->ChatHistoryMsgCount());
	mCommObject->jsSetloadStatus(mPage, 0);
    onGetMore(Constant::INT64_MAX_T, 10, true);
}

void ChatDialog::doMergeMessageCache(const QSharedPointer<Biz::MessageListData>& messageList)
{
    mGetHistoryMessageTimerout.stop();

    m_bWebLoadFinshed = true;
	mCommObject->jsSetloadStatus(mPage, 1);
    Log::e(QString("on chatdialog history messages callback: historysize:%1;cathesize:%2,%3")
        .arg(messageList.isNull()?0:messageList->getMessageList().length())
        .arg(m_lstMsgCatch.length())
        .arg(conversationId()));

    foreach(QSharedPointer<Biz::XmppMessage> spMsg,m_lstMsgCatch)
    {
        bool bfinded = false;

        if (!messageList.isNull())
        {
            for (QSharedPointer<Biz::XmppMessage> messgeItem: messageList->getMessageList())
            {
				if (!messgeItem.isNull())
				{
					if (spMsg->MessageID() == messgeItem->MessageID())
					{
						bfinded = true;
						break;
					}
				}
                
            }
        }

        if (!bfinded)
        {
            onMessageReceived(spMsg);
            Log::e(QString("on chatdialog history messages callback: messageonline merged %1 ").
                arg(spMsg->MessageID()));
        }
    }

    m_lstMsgCatch.clear();

	mCommObject->scrollToEnd(mPage);
}


void ChatDialog::onSelectResult(WId id, const QString& strSelect)
{
    if (id == this->winId() && !strSelect.isEmpty())
    {
        //ui->textEdit->setText(strSelect);
        ui->textEdit->setPlainText(strSelect);
        QTextCursor  currentCursor = ui->textEdit->textCursor();
        currentCursor.movePosition(QTextCursor::WordRight);
        ui->textEdit->setTextCursor(currentCursor);
        ui->textEdit->setFocus();
    }
}

void ChatDialog::onClearContents(bool bret)
{
	//disconnect(ui->webView, &webview::loadFinished, this,&ChatDialog::onLoadHtmlFinish);
	//disconnect(ui->webView, &webview::loadFinished, this,&ChatDialog::onLoadHtmlFinishByReConn);
	
	//loadChatHtml(ui->webView, "/commonresource/html/dialog.html");
	mCommObject->cleanHistroyRecordPage(mPage);
	
	Biz::Session::getAttachmentManager()->cleanImageAttachlistbyId(conversationId());
	
}

void ChatDialog::onChatWebUpdateStatus( const QString& groupjid, bool bret )
{
    doSetHeaderImage();
}

void ChatDialog::onTransferInfor( const QSharedPointer<Biz::XmppMessage>& message )
{
	if (message.isNull())
	{
		return;
	}
    if (!Biz::MessageUtil::compareJid(message->ConversationID(),conversationId()))
    {
        return;
    }

    QString strTransUserid;
    QString userid = message->ConversationID();
    QString strBody = message->Body();
	QByteArray Date = strBody.toUtf8();
    QJsonParseError Json_Parse_Error;
    QJsonDocument Json_Data = QJsonDocument::fromJson(Date,&Json_Parse_Error);
    if(Json_Parse_Error.error == QJsonParseError::NoError)
    {
        QVariantMap resultMap = Json_Data.toVariant().toMap();
        strTransUserid = resultMap["TransId"].toString(); 
    }
    QString strDisplayname = Biz::Session::currentAccount().getUserNameById(strTransUserid);
    if (strDisplayname.isEmpty())
    {
        strDisplayname = strTransUserid;
    }

    if ( (message->MediaType() == Biz::MediaTypeTransVisitor) )
    {
        quint64 tm = message->UtcTime();
        QString strcurrentm = QDateTime::fromMSecsSinceEpoch(tm).toString("hh:mm:ss");
		mCommObject->systemnotify(mPage,QStringLiteral("%1 会话已经成功转移给同事[%2]").arg(strcurrentm).arg(strDisplayname));
    }

}

void ChatDialog::onShowChatUserInfor()
{
    if (conversationId().isEmpty())
    {
        return;
    }
#ifndef QCHAT
	Biz::Session::getUserVcardManager()->getDomainUsersVcardByforce(QStringList(conversationId()));
    UserMiniProfile::getInstance()->setUserid(conversationId());
    UserMiniProfile::getInstance()->autoshow();
#else
    QString strBuffer = conversationId();
	QString strRealId;
	//判断是否是虚拟账号
	if (UtilHelper::isVirtualAccountId(strBuffer, Biz::Session::getSystemConfig()->getXmppDomain()))
	{
		strRealId = UtilHelper::getRealIdfromID(strBuffer);
	}
	else
	{
		strRealId = strBuffer;
	}
	Biz::Session::getUserVcardManager()->getDomainUsersVcardByforce(QStringList(strRealId));
    QString strNickname = Biz::Session::currentAccount().getUserNameById(strRealId);
    if (strNickname.isEmpty())
    {
        strNickname = strBuffer;
    }
    UserMiniProfile::getInstance()->setUserid(strRealId, strNickname, strRealId + "@qunar.com");
    UserMiniProfile::getInstance()->autoshow();

#endif
}


void ChatDialog::onShowEditMenu( const QPoint&pt )
{
    if (mEditMenu == NULL)
    {
        mEditMenu = new QMenu(ui->textEdit);

        mActionSelectAll = new QAction(T_("GroupTextEditMenu_item_All"), ui->textEdit);
        connect(mActionSelectAll, &QAction::triggered, this, &ChatDialog::onEditSelectAll);
        mEditMenu->addAction(mActionSelectAll);

        mActionCopy = new QAction(T_("GroupTextEditMenu_item_copy"), ui->textEdit);
        connect(mActionCopy, &QAction::triggered, this, &ChatDialog::onEditCopy);
        mEditMenu->addAction(mActionCopy);

        mActionPast = new QAction(T_("GroupTextEditMenu_item_past"), ui->textEdit);
        connect(mActionPast, &QAction::triggered, this, &ChatDialog::onEditPast);
        mEditMenu->addAction(mActionPast);
    }

    if( ui->textEdit->toPlainText().length() > 0 || (ui->textEdit->toPlainText().length() == 0 && !getSelectImagePath().isEmpty()) )
    {

        mActionCopy->setEnabled(true);
        mActionSelectAll->setEnabled(true);

    }else{
        mActionCopy->setEnabled(false);
        mActionSelectAll->setEnabled(false);
    }



    mEditMenu->exec(QCursor::pos());

}

void ChatDialog::onEditCopy()
{
    ui->textEdit->copy();
}

void ChatDialog::onEditPast()
{
    emit ui->textEdit->sgPaste();
}

void ChatDialog::onEditSelectAll()
{
    ui->textEdit->selectAll();
}

void ChatDialog::doSetHeaderImage()
{
	if(mChatType != NormalChatType && mChatType != 8)
	{
		return;
	}

    if (Biz::MessageUtil::compareJid(Util::NEWS_DIALOG_ID,conversationId()) 
		|| MainApp::UIFrame::getConversationController()->IsUserIdInAllRobotList(conversationId())
		|| Biz::MessageUtil::compareJid(conversationId(), Util::SYSTEMNEWS_DIALOG_ID)
		|| Biz::MessageUtil::compareJid(conversationId(), Util::NOTICENEWS_DIALOG_ID)
		|| Biz::MessageUtil::compareJid(conversationId(), Util::QIANGDAN_DIALOG_ID))
    {
        return;
    }

    QPixmap pixmap = Biz::PortraitHelper::getUserPortrait(conversationId());

    if (Biz::Session::getUserVcardManager()->isUserOnline(conversationId()))
    {
		pixmap = QPixmap::fromImage(pixmap.toImage().scaled(ui->headerimage->size()));
       
        ui->headerimage->setPixmap(pixmap);


		ui->status->setText(QStringLiteral("[在线]"));
		ui->status->setVisible(true);
		

	}
    else
    {
        QImage colourImg = pixmap.toImage();
        imageToGray(colourImg);

		QPixmap grayImage = QPixmap::fromImage(colourImg.scaled(ui->headerimage->size()));
		
		ui->headerimage->setPixmap(grayImage);

		ui->status->setText(QStringLiteral("[离线]"));
		ui->status->setVisible(true);
		

// 		offlineStateIcon = QPixmap::fromImage(offlineStateIcon.toImage().scaled(ui->headerimage->getlbStaticSize()));
//       
// 		ui->headerimage->showStatic(true);
// 		ui->headerimage->setlbStaticPixmap(offlineStateIcon);
    }
}

void ChatDialog::setupUiQss(QString qssfileName)
{
    MainApp::setSheetsStyle(this,qssfileName);
    ui->textEdit->onInputTextSizeChange(Biz::Session::getSettingConfig()->MInputFontSize());
}

void ChatDialog::setNoticeInfo( const QString& notice )
{
    if (notice.isEmpty())
    {
        return;
    }
    QString strInfo = QStringLiteral("客人来自于:%1").arg(notice);
	ui->leNotice->setToolTip(strInfo);
    setleNotice(strInfo);
}

void ChatDialog::doShowWelcome( const QString&userid, const QSharedPointer<Biz::XmppMessage>& msg)
{
    if(!Biz::MessageUtil::compareUserId(userid,conversationId()))
        return;

    appendMessage(false, false, msg);
}

void ChatDialog::onVcardUpdate( const QStringList& userinforlist )
{
	QString id = conversationId();
	id = id.mid(0, id.indexOf("|shop"));
    if (userinforlist.contains(id))
    {
        QSharedPointer<Biz::ImSelfPerson> spInfo = Biz::Session::getUserVcardManager()->userVcard(id);
        if (!spInfo.isNull())
        {
            QString fileName = Biz::PortraitHelper::getUserPortraitPath(id);

            QString displayname = spInfo->displayName();
            ui->name->setText(displayname);
            ui->leJid->setText(Biz::MessageUtil::makeSureUserId(spInfo->strUserId));
            doSetHeaderImage();
        }
    }
}

void ChatDialog::InitFontSize()
{
    int fontSize = Biz::Session::getSettingConfig()->MFontSize();

    SetfontSize(fontSize);


}
void ChatDialog::SetfontSize(int nsize)
{
    if (nsize < 14)
    {
        nsize = 14;
    }
    else if (nsize >20 )
    {
        nsize = 20;
    }
    ui->name->setStyleSheet(QString("font-size:%1px;").arg(nsize));
    ui->leJid->setStyleSheet(QString("font-size:%1px;").arg(nsize));
    ui->leNotice->setStyleSheet(QString("font-size:%1px;").arg(nsize));
	
}

void ChatDialog::onpbAdvertInfo()
{
    AdvertInfoDialog *pAdvertInfo = AdvertInfoDialog::instance();
    if (pAdvertInfo)
    {
        pAdvertInfo->setJid(conversationId());
        pAdvertInfo->showAdvertInfoDlg();
    }
}

void ChatDialog::doShowProductInfo( const QString&userid, const QSharedPointer<Biz::XmppMessage>& msg)
{
    if(!Biz::MessageUtil::compareJid(userid,conversationId()))
        return;

    appendMessage(false, false, msg);
}

void ChatDialog::onShowSystemNotifyInfo( const QString& strUsrId, const QString& strInfo )
{
    if(!Biz::MessageUtil::compareJid(conversationId(),strUsrId))
        return;

	mCommObject->systemnotify(mPage,strInfo);
}

void ChatDialog::onGloableFontSizeChanged( int size )
{
    SetfontSize(size);
}



void ChatDialog::showTransChatHistory(const QString& from)
{
	QString strUrl = Biz::Session::getEditableSettings()->SessionHistory();
	QUrl qu(strUrl);
	QUrlQuery quq(qu);
	quq.addQueryItem("from", from);
	quq.addQueryItem("to", Biz::MessageUtil::makeSureUserId(conversationId())); 
	quq.addQueryItem("u", Biz::Session::getAccountManager()->accountData().UserID());
	quq.addQueryItem("k", WebService::sSecurityKey);
	qu.setQuery(quq);
	strUrl = qu.toString();
	CommentWebViewSingleton::getInstance()->setQunarCookie();
	CommentWebViewSingleton::getInstance()->openCommonUrl(strUrl);
}


void ChatDialog::onSendFile( const QString&filePath )
{
	Biz::EditableSettings *peditSetting = Biz::Session::getEditableSettings();
	QString strLoginRecived = peditSetting->DefaultLogRecived();

	QSharedPointer<Biz::XmppMessage> message(new Biz::XmppMessage(strLoginRecived));
	message->UtcTime(QDateTime::currentDateTime().toMSecsSinceEpoch()-Biz::Session::currentAccount().getTimeOffsetFromServer());
	message->MediaType(Biz::MediaTypeFile);
	message->MsgDirection(Biz::MessageTypeSelf);
	message->MsgSourceType(Biz::UnKnow);

	QStack<QString> mstack;
	mstack.append(filePath);
	message->localUrls(mstack);
	auto guid = QUuid::createUuid().toString().replace("{", "").replace("}", "").replace("-", "");
	message->SendFileID(guid);
	message->MessageID(guid);

	message->LocalFlag(Biz::MESSAGESTATE_LOCAL_SENDSUCCESS);

	auto callback = receiver->createCallback([]{}, [this](){
		// 发送图片失败
		QString sendAttachmentFail = T_("sendMessageFail");
		mCommObject->systemnotify(mPage,sendAttachmentFail);
		mCommObject->scrollToEnd(mPage);
		cleanWillSendMsg();
		Biz::Session::getAccountManager()->sgcollectLogsInfo(QStringLiteral(""));
	});
	auto presendcallback = receiver->createCallback([this, message, strLoginRecived](){
		Biz::Session::getAccountManager()->sgcollectLogsInfo(QStringLiteral("日志收集并发送完成"));
		quint64 getmsgendticked =  QDateTime::currentMSecsSinceEpoch();
		Log::e(QString("BaseChatDialog::onSendClick end %1 conversationId=%2").arg(getmsgendticked).arg(conversationId()));
		appendMessage(false,false,message);
		MainApp::UIFrame::getConversationController()->addSimpleChatRosterItem(strLoginRecived,MainApp::ConversationController::sDefaultExtendPanel);

		MainApp::UIFrame::getConversationController()->updateJidLastTimeStamp(strLoginRecived, QDateTime::currentDateTime().toMSecsSinceEpoch()-Biz::Session::currentAccount().getTimeOffsetFromServer());
		MainApp::UIFrame::getConversationController()->activeConversation(strLoginRecived);
	},[this](){});

	messageSendPrepare (message);
	quint64 getmsgendticked =  QDateTime::currentMSecsSinceEpoch();
	Log::e(QString("BaseChatDialog::onSendClick begin %1 conversationId=%2").arg(getmsgendticked).arg(conversationId()));


	Biz::Session::currentAccount().doSendMessage(message, presendcallback, callback);
	
}
void ChatDialog::showRightExtendPanel(  )
{
    if (ui->rightwidget->getTabCount()>0)
    {
        rightPanelShowed = true;
        ui->rightwidget->setVisible(rightPanelShowed);
        ui->showProduct->setChecked(rightPanelShowed);
    }
    else
    {
        hideRightExtendPanel();
    }
    
}

void ChatDialog::hideRightExtendPanel()
{
    rightPanelShowed = false;
    ui->rightwidget->setVisible(rightPanelShowed);
    ui->showProduct->setChecked(rightPanelShowed);
}

void ChatDialog::onMessageDispatch(const QSharedPointer<Biz::XmppMessage>& spMessage)
{
    if (onProductInfo888Message(spMessage))
        return;
    if (onNoteMessage(spMessage))
        return;
}

bool ChatDialog::onNoteMessage(const QSharedPointer<Biz::XmppMessage>& spMessage)
{
	if (spMessage.isNull())
	{
		return false;
	}
    if (!spMessage.isNull() && Biz::MessageTypeNote ==spMessage->MediaType())
    {
        QString body = spMessage->Body();
        Biz::NoteInfo noteInfo;
        noteInfo.unserializeFromString(body);

		 Biz::ProductInfo* pDetailInfo = (Biz::ProductInfo*)noteInfo.data();
		 if (pDetailInfo != NULL)
		 {
			mProductId =  pDetailInfo->productId();
		 }
		
		mBusinessline = noteInfo.bu();
        if (!noteInfo.url().isEmpty())
        {

			QString strUrl = noteInfo.url();
			//strUrl = "QunariPhone://hy?url=https%3A%2F%2Ftouch.qunar.com%2Fplus%2Fproduct_detail%3Fpid%3D000291253336%26moduleId%3D439747%26sourceFrom%3Dvisa";
			if (strUrl.contains("://hy?"))
			{
				QUrl url(strUrl);
				QUrlQuery queryurl(url);
				strUrl = queryurl.queryItemValue("url");

				strUrl = QUrl::fromPercentEncoding(strUrl.toLatin1());
			}

			if (strUrl.indexOf("http://") == 0
				|| strUrl.indexOf("https://") == 0)
			{
				ui->rightwidget->addWebTab(QStringLiteral("产品详情"), QStringLiteral("产品详情页"), RightExtendPanel::EXTENDID::PRODUCTINFO,strUrl/*noteInfo.url()*/);
				showRightExtendPanel();
			}
            
        }

        if (!noteInfo.ip().isEmpty())
        {
            auto callback = mReceiver->createCallback<QString>([this](QString city)
            {
				if (city.length()>0)
				{
					QString strInfo = QStringLiteral("客人来自于:%1").arg(city);
					ui->leNotice->setToolTip(strInfo);
					setleNotice(strInfo);
				}
            }, []{});

            Biz::Session::getUserVcardManager()->getCityByIpAddr(noteInfo.ip(),callback);
        }
        return true;
    }
    return false;
}

bool ChatDialog::onProductInfo888Message(const QSharedPointer<Biz::XmppMessage>& spMessage)
{
    if (!spMessage.isNull() && Biz::MediaTypeProduct ==spMessage->MediaType())
    {
        QString extendInfo = spMessage->ExtendInfo();
        Biz::ProductCard productCard;
        productCard.unserializeFromString(extendInfo);
        if (!productCard.descdetail().isEmpty())
        {
            ui->rightwidget->addTab(QStringLiteral("产品详情"), QStringLiteral("产品详情页"), RightExtendPanel::EXTENDID::PRODUCTINFO888);
            LabelExtendPanelItem* tabExtend = dynamic_cast<LabelExtendPanelItem*>(ui->rightwidget->getExtendView(RightExtendPanel::EXTENDID::PRODUCTINFO888));
            if (NULL!=tabExtend)
            {
                QLabel* plabel = dynamic_cast<QLabel*>(tabExtend->m_contentView);
                if (NULL!=plabel)
                {
                    plabel->setText(productCard.descdetail());
                    plabel->setToolTip(productCard.descdetail());
                }
            }
            showRightExtendPanel();
        }
        return true;
    }
    return false;
}

bool ChatDialog::IsVisibleRightExtendPanel()
{
    QString cid = conversationId();
    return rightPanelShowed;
}
void ChatDialog::onRightFunctionPanelVisibleChange()
{
    MainApp::UIFrame::getConversationController()->resizeMainDialogBySimpleChatRightPannel();
}

void ChatDialog::setChannelId(const QString& channelIdInMsg)
{
    if (!channelIdInMsg.isEmpty())
    {
        QVariantMap channelObj = QJsonDocument::fromJson(channelIdInMsg.toUtf8()).toVariant().toMap();
        QJsonObject sendChannelId = QJsonObject::fromVariantMap(channelObj);
        if (channelObj.contains("cn") && !channelObj.value("cn").toString().isEmpty())
        {
            sendChannelId.insert("cn",channelObj.value("cn").toString());
            sendChannelId.insert("d",QString("send"));
        }
        this->channelId = QJsonDocument(sendChannelId).toJson(QJsonDocument::Compact);
    }
}

void ChatDialog::selectFileAndSend()
{
    ui->toolbar->emitSendFileBtn();
}

void ChatDialog::onSelectAndSendFile(const QString& strAbsFilePath)
{
    if (!strAbsFilePath.isEmpty())
    {
        //发送图片
        if (Biz::ConfigureHelper::IsPicFile(strAbsFilePath))
            sendPicutre(strAbsFilePath);
        else
            sendFile(strAbsFilePath);
        ui->textEdit->setFocus();
        updateCurrentTick(QDateTime::currentMSecsSinceEpoch());
    }
}

void ChatDialog::onTransChatPersenSelect(WId id,const QString &strPersonId)
{

}

void ChatDialog::onSendShakeMessage()
{
    if(conversationId().isEmpty())
        return;

    QSharedPointer<Biz::XmppMessage> message(new Biz::XmppMessage(conversationId()));
    QString text = QStringLiteral("给你发送了一个窗口抖动。");

    message->Body(text);
    message->UtcTime(QDateTime::currentDateTime().toMSecsSinceEpoch()-Biz::Session::currentAccount().getTimeOffsetFromServer());
    message->MediaType(Biz::MediaTypeShockAndPostBackCookie);
    message->MsgDirection(Biz::MessageTypeSelf);
    message->MsgSourceType(Biz::ChatMessage);
	message->cctext(m_cctext);
	message->bu(m_bu);
    auto callback = mReceiver->createCallback([this, message]()
    {
        if(message->ConversationID() != conversationId() ){
            return;
        }
        // 自己不追加
        mCommObject->systemnotify(mPage,QStringLiteral("你发送了一个窗口抖动"));
        mCommObject->scrollToEnd(mPage);
        Biz::Session::getConverSationManager()->saveConversationInfo(message,NULL);
		MainApp::UIFrame::getConversationController()->updateChatContent( conversationId(), message);
    }, []{});

   

    Biz::Session::currentAccount().doSendMessage(message, callback,NULL);

    updateCurrentTick(message->UtcTime());
}

void ChatDialog::onSendQuickReplay(const QString& jid,const QString& message)
{
    if (jid==conversationId()&&!message.isEmpty())
    {
		if(!Biz::Session::getSettingConfig()->QuickReply())
		{
			ui->textEdit->setPlainText(message);
			QTextCursor  currentCursor = ui->textEdit->textCursor();
			currentCursor.movePosition(QTextCursor::WordRight);
			ui->textEdit->setTextCursor(currentCursor);
			ui->textEdit->setFocus();
		}
		else
		{
			//直接把消息发送出去
			onSendMessageByType(message, Biz::MediaTypeText, Biz::ChatMessage, jid);
		}

		
    }
}

void ChatDialog::onUserMoodInforChange( const QString& userid, const QString&moodinfor )
{
	QString strconvid = conversationId();
	if (!userid.isEmpty() && Biz::MessageUtil::compareJid(conversationId(),userid))
	{
		ui->typing->setVisible(true);
		ui->typing->setToolTip(moodinfor);
		QString strlimit = MainApp::getMaxLineCountLimitText(moodinfor, 280, 1, ui->typing->font());
		ui->typing->setText(strlimit);
		//setlimitInfoInLabel(ui->typing, moodinfor, 190);
		mMoodInfo = moodinfor;
	}

	
}

void ChatDialog::onUserOfCity( const QString& userid, const QString&city )
{
	if ( Biz::MessageUtil::compareJid(conversationId(),userid) &&! city.isEmpty())
	{
		QString strInfo = QStringLiteral("客人来自于:%1").arg(city);
		ui->leNotice->setToolTip(strInfo);
		setleNotice(strInfo);
	}
	
}

void ChatDialog::onTranferFailInfor( const QString& strDisplayname )
{
	mCommObject->systemnotify(mPage,QStringLiteral("会话已经成功转移给同事[%1],失败！！！").arg(strDisplayname));
}

void ChatDialog::onHideUpUnreadMessageTip()
{
    if (MainApp::UIFrame::getConversationController()->topConversationId()==conversationId() && CloseableButtonView::ShowType::ST_UPUNREAD==mpUpUnread->getShowType())
    {
        mpUpUnread->hide();
    }
}

void ChatDialog::onShowUnreadMessageTip()
{
    auto getAllUnreadMessageCallback = mReceiver->createCallback<QSharedPointer<Biz::MessageListData>>([this](const QSharedPointer<Biz::MessageListData>& unreadmessage )
    {
        mpUpUnread->setAnchoragePoint(MessageUnreadTip::sKey);
		if (unreadmessage->getMessageList().size() > 0)
		{
			mpUpUnread->setUpUnreadText(QStringLiteral("%1条新消息").arg(unreadmessage->getMessageList().size()));
			//mpUpUnread->show();
		}
        
    }, []{ });
    Biz::Session::getMessageManager()->getAllUnreadMessageList(conversationId(),getAllUnreadMessageCallback);
}

void ChatDialog::paintEvent( QPaintEvent *event )
{
	if (m_bInhertAttribute)
	{
		QPainter painter(this);
		// 之前位置计算的不对 geometry不是获取当前窗口坐标而是父窗口 根据相对当前窗口位置 重新计算 横线位置 by cyz
		//QRect rect = ui->name->geometry();
		QRect rect = ui->name->rect();
	//	QPoint pos = ui->name->pos();
		QPoint dpos = ui->name->mapTo(this, QPoint(0, 0));
		//int nwidth = ui->headerimage->size().width() + ui->horizontalLayout_7->spacing();
		QPoint mbeginpt = QPoint(rect.bottomLeft().x() + dpos.x(), rect.bottomRight().y()-2 + dpos.y() );
		QPoint mendpt = QPoint(rect.bottomRight().x() + dpos.x() , rect.bottomRight().y()-2 + dpos.y() );
		QPen pen(QColor(0, 0, 0));

		painter.setPen(pen);
		if (mbhover)
		{
			painter.drawLine(mbeginpt, mendpt);
		}
	}

	BaseChatDialog::paintEvent(event);
}

void ChatDialog::onhttpgetapicall( const QString& url )
{
	Biz::Session::currentAccount().httpgeturlapi(url);
}

void ChatDialog::onAudioChat()
{

	if (MainApp::UIFrame::getConversationController()->IsVidioChatExist(conversationId()))
	{
		VidioAndAudioDialog *dlg = MainApp::UIFrame::getConversationController()->getVidioChatById(conversationId());
		if (dlg)
		{
			dlg->setUrl(Biz::Session::getSystemConfig()->getVidioAndAudio_Host());
			dlg->onShowDlg(conversationId(), true);
		}
		return;
	}

	//先发送消息
	sendVidioOrAutioMessage(AudeoVidioType::AUDEOTYPE);

	//调用js函数
	VidioAndAudioDialog *dlg = MainApp::UIFrame::getConversationController()->getVidioChatById(conversationId());
	if (dlg)
	{
		dlg->setUrl(Biz::Session::getSystemConfig()->getVidioAndAudio_Host());
		dlg->onShowDlg(conversationId());


		QString strconversaionId = conversationId();
		connect(dlg, &VidioAndAudioDialog::sgLoadFinished, [this, strconversaionId, dlg](const QString& id){
			if (strconversaionId == id)
			{
				dlg->callVidioOrAudioStart(AudeoVidioType::AUDEOTYPE);
			}

		});
	}
	
}
#include "noteeditdialog.h"
void ChatDialog::onVidioChat()
{
	////////////

// 	setpwdInfor pwd(this);
// 
// 	pwd.setFixedSize( pwd.width (),pwd.height ());
// 	pwd.showPwdInfor(1);
// 	
// 	if (pwd.exec() == setpwdInfor::ChooseOK)
// 	{
// 		int a = 5;
// 		a = 9;
// 	}
// 	return;
// 	NoteEditDialog *pdlg = NoteEditDialogSingleton::getInstance();
// 	if (pdlg)
// 	{
// 		pdlg->ShowNoteEditDialog();
// 	}
// 	return;
	//////////////////

	if (MainApp::UIFrame::getConversationController()->IsVidioChatExist(conversationId()))
	{
		VidioAndAudioDialog *dlg = MainApp::UIFrame::getConversationController()->getVidioChatById(conversationId());
		if (dlg)
		{
			dlg->setUrl(Biz::Session::getSystemConfig()->getVidioAndAudio_Host());
			dlg->onShowDlg(conversationId(), true);
		}
		return;
	}


	//先发送消息
	sendVidioOrAutioMessage(AudeoVidioType::VIDEOTYPE);
	//调用js函数
	VidioAndAudioDialog *dlg = MainApp::UIFrame::getConversationController()->getVidioChatById(conversationId());
	if (dlg)
	{
		dlg->setUrl(Biz::Session::getSystemConfig()->getVidioAndAudio_Host());
		dlg->onShowDlg(conversationId());

		QString strconversaionId = conversationId();
		connect(dlg, &VidioAndAudioDialog::sgLoadFinished, [this, strconversaionId, dlg](const QString& id){
			Log::e("ChatDialog::onVidioChat() sgLoadFinished received ");
			if (strconversaionId == id)
			{
				Log::e("ChatDialog::onVidioChat() sgLoadFinished received  strconversaionId == id ");
				dlg->callVidioOrAudioStart(AudeoVidioType::VIDEOTYPE);
			}

		});
	}
	
}

void ChatDialog::loadNormalHtml()
{
	connect(ui->webView, &webview::loadFinished, this,&ChatDialog::onLoadHtmlFinish);

	ui->webView->setContextMenuPolicy(Qt::CustomContextMenu);
	
	mPage->addChatChannelToHtml("CLIENT_API", mCommObject);
	ui->webView->setPage(mPage); 
	loadChatHtml(ui->webView, "/html/dialog.html"); 

}
void ChatDialog::setDisplayName( const QString& displayname )
{
	ui->name->setText(displayname);
}

void ChatDialog::messageSendPrepare(const QSharedPointer<Biz::XmppMessage>& spMessage)
{
	if (spMessage.isNull())
	{
		return;
	}
    //发送一条消息时，发送
    Biz::Session::getConverSationManager()->setConversationMessageRead(conversationId());
    spMessage->MsgSourceType(Biz::ChatMessage);
    spMessage->ChannelId(channelId);
#ifdef QCHAT
    spMessage->BackupInfo (makeBackupInfo (spMessage->Body ()));
#endif // QCHAT

}

void ChatDialog::showPlatInfor( const QSharedPointer<Biz::XmppMessage>& message )
{
	if (message.isNull())
	{
		return;
	}
	QString strresource =  message->Resource();

	if (!strresource.isEmpty())
	{

		int vbpos = strresource.indexOf("V[");
		if (vbpos < 0)
		{
			return;
		}
		int vepos = strresource.indexOf("]_P[");
		if(vepos < 0)
		{
			return;
		}
		QString strVersion = strresource.mid(vbpos + 2, vepos - vbpos - 2);

		int pbpos = strresource.indexOf("_P[");
		if (pbpos < 0)
		{
			return;
		}
		int pepos = strresource.indexOf("]_D[");
		if(pepos < 0)
		{
			return ;
		}
		QString strplat = strresource.mid(pbpos + 3, pepos - pbpos - 3);

		int ntype = strresource.lastIndexOf("_PB");
		QString strtype;
		QString strlabel;
		if (ntype > 0)
		{
			strtype = "P";
		}
		else
		{
			strtype = "X";
		}
		
		if (strplat.isEmpty() || strVersion.isEmpty())
		{
			strlabel = QStringLiteral("来自:未知");
		}
		else
		{
			strlabel = QStringLiteral("来自:%1(%3_%2)").arg(strplat).arg(strVersion).arg(strtype);
			ui->label_resource->setToolTip(strlabel);
		}

		QFontMetrics fontMetricsnotice(ui->label_resource->font());
		int nwidthText = fontMetricsnotice.width(strlabel);
		
		if (nwidthText > 200)
		{
			ui->label_resource->setFixedWidth(200);
		}
		QString strlimit = MainApp::getMaxLineCountLimitText(strlabel, ui->label_resource->width(), 1, ui->label_resource->font());
		ui->label_resource->setText(strlimit);
		MainApp::UIFrame::getConversationController()->insertChatIdVerinfo(conversationId(), strlabel);
	}
	else
	{
		QString strversionInfo = MainApp::UIFrame::getConversationController()->getVerinfobychatId(conversationId());
		if (!strversionInfo.isEmpty())
		{
			ui->label_resource->setText(strversionInfo);
		}
	}
	
}



QString ChatDialog::makeBackupInfo(const QString& body)
{
    QJsonArray jsonArr;

    // @信息的backupinfo

    if (body.contains("@"))
    {
        QJsonArray atArr;
        
        for (QString key:mWechatUserInfoDic.keys())
        {
            QString nickName = key;
            QString userid = mWechatUserInfoDic.value (key);
            if (body.contains("@"+nickName,Qt::CaseInsensitive))
            {
                QJsonObject atNode;
                atNode.insert("jid",userid);
                atNode.insert("text",nickName);
                atArr.append(atNode);
            }
        }

        if (!atArr.isEmpty())
        {
            QJsonObject jsonType;
            jsonType.insert("type",Biz::CHATTYPEATINFO);
            jsonType.insert("data",atArr);
            jsonArr.append(jsonType);
        }
    }

    if (jsonArr.size()>0)
    {
        QString retJson = QJsonDocument(jsonArr).toJson(QJsonDocument::Compact);
        return retJson;
    }
    return "";

}

void ChatDialog::setleNotice( const QString&text )
{
	if (text.isEmpty())
	{
		return;
	}
	QFontMetrics fontMetricsnotice(ui->leNotice->font());
	int nwidthText = fontMetricsnotice.width(text);
	int nwidthLay = ui->undbclicked->width();
	if (nwidthText > nwidthLay)
	{
		ui->leNotice->setFixedWidth(nwidthLay + 10);
	}
	else
	{
		//ui->leNotice->setFixedWidth(nwidthText + 10);
		ui->leNotice->setFixedWidth(qMin(415, nwidthText));
	}
	//ui->leNotice->setFixedWidth(350);
	QString strlimit = MainApp::getMaxLineCountLimitText(text, ui->leNotice->width()  ,1, ui->leNotice->font());
	ui->leNotice->setText(strlimit);
	//ui->leNotice->setFixedWidth(fontMetricsnotice.width(strlimit) + 10);

}

void ChatDialog::onReplyWechatUser(const QString& messagid)
{
    auto getmessagesuccess = [this](const QSharedPointer<Biz::XmppMessage>& spMessage){
        if (!spMessage.isNull ()&& !spMessage->BackupInfo ().isEmpty ())
        {
            QString backinfo = spMessage->BackupInfo ();
            QJsonDocument doc = QJsonDocument::fromJson (backinfo.toUtf8 ());
            QVariantList vl = doc.toVariant ().toList ();
            for (QVariant vv:vl)
            {
                QVariantMap vm = vv.toMap ();
                if (vm.contains ("type") && 20001 == vm.value ("type").toInt ())
                {
                    QVariantMap vdm = vm.value ("data").toMap ();
                    QString nickname = vdm.value ("nickname").toString ();
                    QString tmpusername = vdm.value ("tmpusername").toString ();
                    ui->textEdit->insertPlainText ("@"+nickname + " ");
                    ui->textEdit->setFocus ();


                    mWechatUserInfoDic.insert (nickname,tmpusername);
                }
            }
        }
    };

    auto getmessagefail = []{};
    auto callback = receiver->createCallback<QSharedPointer<Biz::XmppMessage>>(getmessagesuccess,getmessagefail);
    Biz::Session::getMessageManager ()->getMessageById(messagid,callback);
}

void ChatDialog::onTransferReturnResult( const QString& peerid, const QString& transid, bool bret, int type )
{
	if (!Biz::MessageUtil::compareJid(peerid,conversationId()))
	{
		return;
	}

	
	QString strDisplayname = Biz::Session::currentAccount().getUserNameById(transid);
	if (strDisplayname.isEmpty())
	{
		strDisplayname = transid;
	}
	bool bShopret= false;
	bool bVisitor = false;
	quint64 tm = QDateTime::currentDateTime().toMSecsSinceEpoch()-Biz::Session::currentAccount().getTimeOffsetFromServer();
	QString strcurrentm = QDateTime::fromMSecsSinceEpoch(tm).toString("hh:mm:ss");
	if ( type == Biz::ReplayVisitor)
	{
		bShopret = bret;
		QString strinforSuccess = QStringLiteral("%1 web反馈，会话已经成功转移给web[%2]").arg(strcurrentm).arg(strDisplayname);
		QString strinforfail = QStringLiteral("%1 web反馈，会话转移给web[%2]失败").arg(strcurrentm).arg(strDisplayname);
		QString strinfor = bret ? strinforSuccess:strinforfail;
		mCommObject->systemnotify(mPage,strinfor);

		mCommObject->systemnotify(mPage,QStringLiteral("此次转接会话成功"));
		//过一会自动关闭会话框
		if (bret)
		{
// 			QTimeLine* pTimeLine = new QTimeLine(10000);
// 			connect(pTimeLine,&QTimeLine::finished,[pTimeLine, this]{
// 				pTimeLine->deleteLater();
// 
// 				//关闭会话框
// 				MainApp::UIFrame::getConversationController()->removeConversation(conversationId());
// 				Biz::Session::getConverSationManager()->removeChartingImSession(conversationId());
// 
// 			});
//			mCommObject->systemnotify(mPage,QStringLiteral("转接会话成功, 10秒钟后，自动关闭该对话框"));
//			pTimeLine->start();

		}

	}
	if (type ==  Biz::ReplayShop)
	{
		bVisitor = false;
		QString strinforSuccess = QStringLiteral("%1 同事反馈，会话已经成功转移给同事[%2]").arg(strcurrentm).arg(strDisplayname);
		QString strinforfail = QStringLiteral("%1 同事反馈，会话转移给同事[%2]失败").arg(strcurrentm).arg(strDisplayname);
		QString strinfor = bret ? strinforSuccess:strinforfail;
		mCommObject->systemnotify(mPage,strinfor);
	}
}

void ChatDialog::showProductUrl( const QString& url )
{
	if (url.isEmpty())
	{
		return;
	}

	ui->rightwidget->addWebTab(QStringLiteral("产品详情"), QStringLiteral("产品详情页"), RightExtendPanel::EXTENDID::PRODUCTINFO,url);
	showRightExtendPanel();

}

QString ChatDialog::getProductId()
{
	return mProductId;
}

QString ChatDialog::getbusinessline()
{
	return mBusinessline;
}

void ChatDialog::onOpenRobot()
{
	QString url = Biz::Session::getSystemConfig()->getHttpHost().replace("api", "webchat/inner/robotpc?") + QString("u=%1").arg(conversationId());
	//QString url(QString("http://qcweb.qunar.com/robot/consult?u=%1").arg(conversationId()));
	ui->rightwidget->addWebTab(QStringLiteral("机器人"), QStringLiteral("机器人页"), RightExtendPanel::EXTENDID::ROBOTINFO, url);
	
	showRightExtendPanel();
}

void ChatDialog::onRobotSendMsg( const QString&conversation, const QString&msg )
{
	QString str = conversationId();
	if (!Biz::MessageUtil::compareUserId(conversation,conversationId()) )
	{
		return;
	}

	ui->textEdit->setText(msg);

	onSendClick(true);
}

void ChatDialog::onChatEncrypt( )
{
	//MainApp::UIFrame::getEncryptChatcontroller()->showEncryptChatDialog(conversationId());
	
	if(m_EncryptChatdlg == NULL)
	{
		m_EncryptChatdlg = new EncryptChatDialog(this);
		m_EncryptChatdlg->setConversationId(conversationId());
	}
	m_EncryptChatdlg->show();
	return;


/*	int  nstatus = Qt::Checked;
	if (nstatus == Qt::Unchecked) //取消加密会话
	{
		
		onSendMessage(QStringLiteral("取消"), Biz::EncryptMessageType::EncryptMessageType_Cancel, conversationId());

	}
	else if (nstatus == Qt::Checked) //进行加密会话
	{

		//首先看看是否有会话密码
		auto callbacksuccess = [this](const QString& strMainKey){

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
							auto checkcallbacksuccess = [this](const QString& mainKey){

								QJsonParseError Json_Parse_Error;
								QJsonDocument Json_Data = QJsonDocument::fromJson(mainKey.toUtf8(),&Json_Parse_Error);
								if(Json_Parse_Error.error == QJsonParseError::NoError)
								{
									QVariantMap dataMap = Json_Data.toVariant().toMap();
									QVariant datavar = Json_Data.toVariant();
									bool ret = dataMap["ret"].toBool();
									if (ret)
									{

										doGetSubKey(dataMap["Key"].toString());
									}
									else
									{
										doCreateMainKey();
									}
								}

								
							};
							auto checkcallbackfail = []{};
							auto checkcallback = receiver->createCallback<QString>(checkcallbacksuccess, checkcallbackfail);
							Biz::Session::getqCloudManager()->checkqCloudMainKey(strPwd, checkcallback);


						}
						else
						{
							doCreateMainKey();
						}
					}

				}
				else
				{
					doGetSubKey(strMainKey);
				}
			}
			else
			{
				doCreateMainKey();
			}

			
		};

		auto callbackfail = []{};
		auto callback = receiver->createCallback<QString>(callbacksuccess,callbackfail);
		Biz::Session::getqCloudManager()->getqCloudMainKey(100, callback);
		
	}*/
}

void ChatDialog::onCloseEncryptChat( const QString& Id )
{
	if (Id != conversationId())
	{
		return;
	}
	MainApp::UIFrame::getConversationController()->deleteEncrypt(Id);
	onSendMessage(QStringLiteral("关闭加密会话"), Biz::EncryptMessageType::EncryptMessageType_Close, conversationId());

	mCommObject->systemnotify(mPage,QStringLiteral("关闭与对方的加密会话"));
}

void ChatDialog::doGetSubKey( const QString&MainKey )
{
	//主密码不为空的情况下，检查这个会话密码是否为空，
	auto subcallbacksuccess = [this,MainKey](const QString& strsubKey)
	{
		//这地方为空的情况有2种，第一种确实为空，更本没和这人加密聊过，
		//第二种，拉取失败了，这个时候应该再次的全部拉取一次

		if (strsubKey.isEmpty())
		{
			//创建会话密码
			QString strcreatesubkey = QUuid::createUuid().toString().replace("{","").replace("}","").replace("-","");
			
			MainApp::UIFrame::getConversationController()->addEncrypt(conversationId(), strcreatesubkey);
			//存放在服务器和本地
			QString strdesc = QStringLiteral("与%1的会话密码").arg(Biz::Session::getUserVcardManager()->getUserNameByConversationId(conversationId()));
			Biz::Session::getqCloudManager()->setSaveqcloudSunInfo(conversationId(), QStringLiteral("会话密码"), strcreatesubkey, 100,NULL);

			//然后发给发对方
			QJsonObject obj;
			obj.insert("type", 1);
			obj.insert("pwd", strcreatesubkey);
			QString paramValue = QJsonDocument(obj).toJson (QJsonDocument::Compact);

			onSendMessage(paramValue, Biz::EncryptMessageType::EncryptMessageType_Begin, conversationId());
			mCommObject->systemnotify(mPage,QStringLiteral("同意与对方加密会话"));

			//等待对方应答
			QString strdisplay = Biz::Session::getUserVcardManager()->getUserNameByConversationId(conversationId());
			if (strdisplay.isEmpty())
			{
				strdisplay = conversationId();
			}
			QString Info = QStringLiteral("等待[%1]应答...").arg(strdisplay);
			MainApp::UIFrame::getEncryptChatcontroller()->sgEncryptResponeInfor(ResponeWait, conversationId(), Info);
			return;
		}

		//直接解密后，发给对方
		QString subchatKey;
		bool bret = Aes_CbC_PKCS7_Decrypt(MainKey, strsubKey, subchatKey);

		//发送给对方
		QJsonObject obj;
		obj.insert("type", 1);
		obj.insert("pwd", subchatKey);
		QString paramValue = QJsonDocument(obj).toJson (QJsonDocument::Compact);
		MainApp::UIFrame::getConversationController()->addEncrypt(conversationId(), subchatKey);
		onSendMessage(paramValue, Biz::EncryptMessageType::EncryptMessageType_Begin, conversationId());

		//等待对方应答
		QString strdisplay = Biz::Session::getUserVcardManager()->getUserNameByConversationId(conversationId());
		if (strdisplay.isEmpty())
		{
			strdisplay = conversationId();
		}
		QString Info = QStringLiteral("等待[%1]应答...").arg(strdisplay);
		MainApp::UIFrame::getEncryptChatcontroller()->sgEncryptResponeInfor(ResponeWait, conversationId(), Info);
	};
	auto subcallbackfail = []{};

	auto subcallback = receiver->createCallback<QString>(subcallbacksuccess, subcallbackfail);

	Biz::Session::getqCloudManager()->getqCloudSubKey(conversationId(), subcallback);
}

void ChatDialog::doCreateMainKey()
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

				if(ret)
					//这里进行创建会话密码
						doGetSubKey(mainkey);


			}, []{});

			Biz::Session::getqCloudManager()->setSaveqcloudMainInfo(strtitle, strdesc, strpwd,Biz::ChatPwdBox, callback);
		}
		else
		{
			MainApp::UIFrame::getConversationController()->deleteEncrypt(conversationId());
		}
	}
	else
	{
		MainApp::UIFrame::getConversationController()->deleteEncrypt(conversationId());
	}

}

void ChatDialog::onCancelEncryptChat(const QString& Id)
{
	if (Id != conversationId())
	{
		return;
	}
	MainApp::UIFrame::getConversationController()->deleteEncrypt(Id);
	onSendMessage(QStringLiteral("取消"), Biz::EncryptMessageType::EncryptMessageType_Cancel, conversationId());
}
void ChatDialog::onDecryptChat(const QString& Id)
{
	if (Id != conversationId())
	{
		return;
	}

	//
	QString EncryptKey = MainApp::UIFrame::getConversationController()->getEncryptPwdbyconversationId(Id);
	QString MainKey = MainApp::UIFrame::getConversationController()->getMainKey();
	if (EncryptKey.isEmpty() && MainKey.isEmpty())
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
				

				auto subcallbacksuccess = [this,strPwd](const QString& strsubKey)
				{
					//这地方为空的情况有2种，第一种确实为空，更本没和这人加密聊过，
					//第二种，拉取失败了，这个时候应该再次的全部拉取一次

					if (strsubKey.isEmpty())
					{

					}

					//直接解密后，发给对方
					QString subchatKey;
					bool bret = Aes_CbC_PKCS7_Decrypt(strPwd, strsubKey, subchatKey);

					MainApp::UIFrame::getConversationController()->addEncrypt(conversationId(), subchatKey);


					

				};
				auto subcallbackfail = []{};

				auto subcallback = receiver->createCallback<QString>(subcallbacksuccess, subcallbackfail);

				Biz::Session::getqCloudManager()->getqCloudSubKey(conversationId(), subcallback);

			}
		}

	}

	auto callback = mReceiver->createCallback<QSharedPointer<Biz::MessageListData>>([this](const QSharedPointer<Biz::MessageListData>& messageList )
	{
		quint64 getmsgendticked =  QDateTime::currentMSecsSinceEpoch();
		Log::e(QString("ChatDialog::onGetMore callback %1 conversationId=%2").arg(getmsgendticked).arg(conversationId()));

		Log::e("ChatDialog::onGetMore callback " + conversationId() );

		onClearContents();

		mCommObject->jsSetloadStatus(mPage, 1);
		onHistoryAppend(messageList);

	}, [this]{ mCommObject->jsSetloadStatus(mPage, 1);});

	Biz::Session::getMessageManager()->getHistoryMessageList(conversationId(),20,Constant::INT64_MAX_T,callback);

}
void ChatDialog::onEncryptChat(const QString& Id)
{
	if (Id != conversationId())
	{
		return;
	}
	int ntext = 9;
	ntext = 10;
	//首先看看是否有会话密码箱
	auto callbacksuccess = [this](const QString& strMainKey){

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
						auto checkcallbacksuccess = [this](const QString& mainKey){

							QJsonParseError Json_Parse_Error;
							QJsonDocument Json_Data = QJsonDocument::fromJson(mainKey.toUtf8(),&Json_Parse_Error);
							if(Json_Parse_Error.error == QJsonParseError::NoError)
							{
								QVariantMap dataMap = Json_Data.toVariant().toMap();
								
								bool ret = dataMap["ret"].toBool();
								if (ret)
								{

									doGetSubKey(dataMap["Key"].toString());
								}
								else
								{
									doCreateMainKey();
								}
							}
						};
						auto checkcallbackfail = []{};
						auto checkcallback = receiver->createCallback<QString>(checkcallbacksuccess, checkcallbackfail);
						Biz::Session::getqCloudManager()->checkqCloudMainKey(strPwd, checkcallback);
					}
// 					else
// 					{
// 						doCreateMainKey();
// 					}
				}
			}
			else
			{
				doGetSubKey(MainKey);
			}
		}
		else
		{
			doCreateMainKey();
		}

	};

	auto callbackfail = []{};
	auto callback = receiver->createCallback<QString>(callbacksuccess,callbackfail);
	Biz::Session::getqCloudManager()->getqCloudMainKey(100,callback);
}

void ChatDialog::onEncryptMsgInfo( const QString&Id, const QSharedPointer<Biz::XmppMessage>& msg )
{
	if (Id != conversationId() || msg.isNull())
	{
		return;
	}

	QString strbody = msg->Body();
	
	

	if ( (msg->MediaType() == Biz::EncryptMessageType_Agree) )
	{
		mCommObject->systemnotify(mPage,QStringLiteral("对方同意加密会话"));
	}
	else if ((msg->MediaType() == Biz::EncryptMessageType_Cancel))
	{
		mCommObject->systemnotify(mPage,QStringLiteral("对方取消加密会话"));
	}
	else if ((msg->MediaType() == Biz::EncryptMessageType_Refuse))
	{
		mCommObject->systemnotify(mPage,QStringLiteral("对方拒绝加密会话"));
	}
	else if ((msg->MediaType() == Biz::EncryptMessageType_Close))
	{
		mCommObject->systemnotify(mPage,QStringLiteral("对方关闭加密会话"));
	}

	
}

void ChatDialog::onPopMenu( const QString&userjid )
{
	if (mChatType == NormalChatType)
	{
		return;
	}

	Biz::Session::getUserVcardManager()->getDomainCollectionUsersVcardByfore(QStringList(Biz::MessageUtil::makeSureUserJid(userjid)));
	UserMiniProfile::getInstance()->setUserid(userjid);
	UserMiniProfile::getInstance()->autoshow();
	//让图片换成最新的
	SetChangeIcon(Biz::MessageUtil::makeSureUserJid(userjid));
}



void ChatDialog::SetChangeIcon( const QString& jid )
{
	if (jid.isEmpty())
		return;
	QString senderHeadUrl  = Biz::PortraitHelper::getUserPortraitPath(jid);
	if (QFile::exists(senderHeadUrl))
	{
		if (senderHeadUrl.at(0) == ':')
		{
			senderHeadUrl = "./image/default_header.png";
		}
		else
		{
			//这地方要转接一下图片的信息
			senderHeadUrl = Biz::PortraitHelper::getGifCovertPng(senderHeadUrl, QSize(90, 90));
			senderHeadUrl = QUrl::fromLocalFile(senderHeadUrl).toString();
		}
		Log::e(QString("GroupChatDialog::SetChangeIcon() jid=%1 headerUrl=%2").arg(jid).arg(senderHeadUrl));

		mCommObject->jsChangeIcon(mPage, jid, senderHeadUrl);
		
	}
}

void ChatDialog::onPortraitUpdate( const QString& jid )
{
	if (mChatType == NormalChatType)
	{
		return;
	}

	SetChangeIcon(jid);


	QSharedPointer<Biz::ImSelfPerson> person = Biz::Session::getUserVcardManager()->userVcard(jid);
	if (!person.isNull())
	{
		QString userId = Biz::MessageUtil::makeSureUserJid(person->strUserId);
		QString displayname = person->displayName();
		if (displayname.isEmpty())
		{
			displayname = jid;
		}
		
		mCommObject->jsChangeGroupMemberName(mPage, userId, displayname);
	}

	Log::e(QString("onRosterPortraitUpdate groupjid=%1 updateuserid=%2").arg(conversationId()).arg(jid));
}

void ChatDialog::onLocalArgeeOrRefuse( const QString& id, int type )
{
	if (id != conversationId())
	{
		return;
	}

	if ( type == Biz::EncryptMessageType_Agree )
	{
		mCommObject->systemnotify(mPage,QStringLiteral("同意加密会话"));
		if (m_EncryptChatdlg==NULL)
		{
			m_EncryptChatdlg = new EncryptChatDialog(this);
			
		}
		m_EncryptChatdlg->setConversationId(conversationId());

		m_EncryptChatdlg->setEncryptButtonType(true);
	}
	else if ((type == Biz::EncryptMessageType_Cancel))
	{
		mCommObject->systemnotify(mPage,QStringLiteral("取消加密会话"));
	}
	else if ((type == Biz::EncryptMessageType_Refuse))
	{
		mCommObject->systemnotify(mPage,QStringLiteral("拒绝加密会话"));
	}
}

void ChatDialog::resizeEvent( QResizeEvent *event )
{
	QString groupName = Biz::Session::currentAccount().getUserGroup(conversationId());
	ui->leNotice->setToolTip(groupName);
	setleNotice(groupName);

	int nnoticy = ui->leNotice->width();
	int nwidget5 = ui->undbclicked->width();
	ui->leNotice->setFixedWidth(ui->undbclicked->width()+10);
	ui->leNotice->resize(nwidget5+10, ui->leNotice->height());
	int afterwidth = ui->leNotice->width();

	QString strText = ui->leNotice->toolTip();
	QString strlimit = MainApp::getMaxLineCountLimitText(strText, qMin(ui->leNotice->width(), 415), 1, ui->leNotice->font());
	ui->leNotice->setText(strlimit);

	if (noticeType == GlobalOfTop)
	{
		if (NULL != m_noticeInfotipGlobal && m_noticeInfotipGlobal->isVisible())
		{
			int top = ui->chattitle->height();
			
			int w = ui->webView->width();
			m_noticeInfotipGlobal->setGeometry(QRect(0,top,w,35));
			m_noticeInfotipGlobal->setFixedWidth(w);
			m_noticeInfotipGlobal->move(0,top);
		}
	}
	else if (noticeType == AppointofBottom)
	{
		if (NULL != m_noticeInfotipAppoint && m_noticeInfotipAppoint->isVisible())
		{
			int top = ui->webView->height() + ui->chattitle->height() - ui->toolbar->height() - 8;
			
			int w = ui->webView->width();
			m_noticeInfotipAppoint->setGeometry(QRect(0,top,w,35));
			m_noticeInfotipAppoint->setFixedWidth(w);
			m_noticeInfotipAppoint->move(0,top);
		}
	}
	
	BaseChatDialog::resizeEvent(event);
}
void ChatDialog::onOpenUrl( const QString& id )
{
	int npos = id.indexOf("http");
	if (npos == 0)
	{
		CommentWebViewSingleton::getInstance()->openCommonUrl(id);
	}
	else
		GetUrlbyMsgid(id);
}

void ChatDialog::GetUrlbyMsgid( const QString& strid )
{
	auto callback = mReceiver->createCallback<QSharedPointer<Biz::XmppMessage>>([this, strid](QSharedPointer<Biz::XmppMessage> msg)
	{
		if (msg.isNull())
		{
			return;
		}

		do 
		{
			if (msg->MsgSourceType()==Biz::subscription)
			{
				if (msg->MediaType() == Biz::MediaTypeSystem)
				{

					QString jsonString = msg->Body ();
					Biz::SystemNotifyParam snp;
					snp.unserializeFromString (jsonString);


					QString leftPromot = snp.prompt ();
					if (!snp.clickprompt ().isEmpty ())
						leftPromot = snp.clickprompt ();

					Biz::ExtraInfo* pExtraInfo = (Biz::ExtraInfo*)snp.extra ();
					QString rightPromot = (NULL==pExtraInfo?QStringLiteral("已处理"):pExtraInfo->checkedopertext ());

					CommentWebViewSingleton::getInstance()->showSystemOrNoticeUrl(snp.operation_url ());
					//SetChecked(strid, leftPromot,rightPromot);
					Biz::Session::getAccountManager()->updateSystemMessageById(strid, 1);
					break;
				}
				if (msg->MediaType() == Biz::MediaTypeNotice || msg->MediaType() == Biz::MediaTypeSystemLY)
				{
					QVariantMap bodyJson = QJsonDocument::fromJson(msg->Body().toUtf8()).toVariant().toMap();
					QString strUrl = bodyJson.value("link_url_pc").toString();
					if (strUrl.isEmpty())
						strUrl = bodyJson.value("linkurl").toString();

					CommentWebViewSingleton::getInstance()->showSystemOrNoticeUrl(strUrl);
					break;
				}
				break;
			}

		} while (false);
	}, []{});


	if(!strid.isEmpty())
		Biz::Session::getMessageManager()->getMessageById(strid, callback);

}

void ChatDialog::onShowNotifyInfor( const QList <QSharedPointer<Biz::NoticeStrInfor>>& list, int type )
{
	if (list.size() <=0)
	{
		return;
	}
	noticeType = type;
	if (type == GlobalOfTop)
	{
		if (m_noticeInfotipGlobal != NULL)
		{
			delete m_noticeInfotipGlobal;
			m_noticeInfotipGlobal = NULL;
		}
		m_noticeInfotipGlobal = new NoticeInfoTip(this);
		m_noticeInfotipGlobal->setInfor(list);
		if (!m_noticeInfotipGlobal->isVisible())
		{
			int top= ui->chattitle->height();
			
			
			int w = ui->webView->width();
			m_noticeInfotipGlobal->setGeometry(QRect(0,top,w,35));
			m_noticeInfotipGlobal->setFixedWidth(w);
			m_noticeInfotipGlobal->showTip();
		}
	}
	if (type == AppointofBottom)
	{
		if (m_noticeInfotipAppoint != NULL)
		{
			delete m_noticeInfotipAppoint;
			m_noticeInfotipAppoint = NULL;
		}
		m_noticeInfotipAppoint = new NoticeInfoTip(this);
		m_noticeInfotipAppoint->setInfor(list);
		if (!m_noticeInfotipAppoint->isVisible())
		{
			int top = ui->webView->height() + ui->chattitle->height() - ui->toolbar->height() - 8;
			
			int w = ui->webView->width();
			m_noticeInfotipAppoint->setGeometry(QRect(0,top,w,35));
			m_noticeInfotipAppoint->setFixedWidth(w);
			m_noticeInfotipAppoint->showTip();
		}
	}


}


