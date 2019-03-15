#include "GroupChatDialog.h"
#include "ui_GroupChatDialog.h"
#include "SettingData.h"
#include <QClipboard>
#include <QPalette>
#include <QFileDialog>
#include <QTextBlock>
#include <QImageReader>
#include <QXmppUtils.h>
#include <QToolTip>
#include <QLabel>
#include <QDesktopServices>
#include <QColorDialog>
#include <QKeyEvent>
#include <QtConcurrent/QtConcurrent>
#include <QFontMetrics>



#include "WebPage.h"
#include "ChatCommObject.h"
#include "LanguageHelper.h"
#include "CallbackReceiver.h"
#include "GroupVisitorMVD.h"
#include "Session.h"
#include "AccountData.h"
#include "Account.h"
#include "ConfigureHelper.h"
#include "SettingData.h"
#include "LanguageHelper.h"
#include "SelectContactDialog.h"
#include "diywidgit/printscreen/SnipScreenTool.h"
#include "diywidgit/customviews/qframelayout.h"
#include "ConfigureHelper.h"
#include "XmppMessage.h"
#include <QKeyEvent>
#include "NotifyWindow.h"


#include "MultiDialogContainer.h"
#include "atnoticetip.h"

#include "GroupListData.h"
#include "group_setting.h"
#include "passwordinput.h"
#include "SpellHelper.h"
#include "../QXmpp/custom/QXmppMucRoomMemberIq.h"
#include "groupvisitorsortproxymodel.h"
#include "portraithelper.h"
#include "createnewgroup.h"

#include "BizCallback.h"

#include "userminiprofile.h"

#include "Historyrecorddialog.h"
#include "SystemConfigData.h"
#include "Ordermanagedialog.h"
#include "UserVcardManager.h"
#include "UiHelper.h"
#include "GroupManager.h"
#include "accountmanager.h"
#include "UserVcardManager.h"
#include "EmotionManager.h"
#include "GroupMemberModule.h"
#include "advertinfodialog.h"
#include "conversationmanager.h"
#include "DownloadManager.h"
#include "UserVcardManager.h"
#include "MessageManager.h"
#include "webview.h"
#include "ConversationController.h"
#include "NotifyCenterController.h"

#include "MainDialogController.h"
#include "UIFrame.h"
#include "messagebubble/MessageParser.h"

#include "ChatWebPage.h"
#include "ChatDisplayOptionWidget.h"

#include "CustomDefine.h"
#include "dataapplication.h"
#include "CloseableButtonView.h"
#include "messagebubble/MessageUnreadMessageTip.h"

#include "editablesettings.h"

#include "groupfileview.h"
#include "groupfilelistview.h"

#include "selgroupmember.h"
#include "videoroomdialog.h"
#include "vidioandaudiodialog.h"
#include "jsonobject/systemnotify.h"
#include "searchatresultdialog.h"
#include "groupmsgfilterview.h"

#include "noticeinfotip.h"

#include "constants.h"



#pragma comment(lib,"Qt5Concurrent.lib")




const QString extendButtonStyleTemplete =  
    "QPushButton#externBtn{                    "
    "    border-top-left-radius: 10px;         "
    "	 border-bottom-left-radius: 10px;      "
    "   background-color:#FFFFFF;              "
    "    border:none;           "
    "    image: %1;                            " 
    "}                                         "
    "                                          "
    "QPushButton#externBtn:hover{              "
    "    image:%2;                             " 
    "}                                         "
    "                                          "
    "QPushButton#externBtn:pressed{            "
    "    image:%3;                             " 
    "}                                         "        ;

const int GroupChatDialog::sMinNameWidth = 500;
const int GroupChatDialog::sMinNoticeWidth = 500;

GroupChatDialog::GroupChatDialog(MultiDialogContainer* cntainer,QWidget *parent)
    : BaseChatDialog(parent)
    ,ui(new Ui::GroupChatDialog)
    ,pContainer(cntainer)
    , searchAtResultDlg(new SearchAtResultDialog(this))
    ,mEditMenu(NULL)
    ,mActionEditCopy(NULL)
    ,mActionEditPast(NULL)
    ,mActionEditSelectAll(NULL)
    ,mbhover(false)
	,mbloaded(false)
{

    ui->setupUi(this);
    setupWebView (ui->webView);
    initExtendBtn();
    ui->name->installEventFilter(this);
    ui->noticy->installEventFilter(this);
    setupTextEdit (ui->textEdit);

    ui->productbtn->setVisible(false);
	int nToolBarMask = DISABLEFUNCTION::BTN_ALL_FUNCTION;
	// 群组聊天要去掉 会话转移/震动/快速回复，机器人 功能
	// 小于5.6的版本 还需要去掉音视频功能
	nToolBarMask = nToolBarMask& (~(BTN_TRANS|BTN_SHOCK|BTN_QUICK|BTN_ROBOT|BTN_CLOSESESSION));
#if (QT_VERSION < QT_VERSION_CHECK(5, 6, 0))
	nToolBarMask = nToolBarMask& (~BTN_VIDIOAUD);
#endif
	// qchat 去掉 二维码扫描功能
	if (PlatfromCode::PLATFROM_QCHAT == Util::nPlatformType)
	{
		ui->productbtn->setVisible(true);
		nToolBarMask = nToolBarMask& (~BTN_RCODE);
	}

	ui->toolbar->setBtnEenable(nToolBarMask);
	ui->toolbar->setGroupVideoButtonNoArrow();
	ui->name->setCursor(QCursor(Qt::PointingHandCursor));
	ui->headerimage->setCursor(QCursor(Qt::PointingHandCursor));

	connect(ui->toolbar, &ChatToolBar::sgVidioAction, this, &GroupChatDialog::onVidioandAudioGroupChat);
	connect(mCommObject, &ChatCommObject::sggotovideoRoom, this, &GroupChatDialog::ongotoVideoRoom);

	connect(ui->toolbar,&ChatToolBar::sgCodeHightLight,this,&BaseChatDialog::onCodeHightLight);
	connect(ui->toolbar,&ChatToolBar::sgCodeStyle,this,&BaseChatDialog::onCodeStyle);
	connect(ui->toolbar,&ChatToolBar::sgCodeType,this,&BaseChatDialog::onCodeType);
	connect(ui->toolbar, &ChatToolBar::sgGroupFilterMsg, this, &GroupChatDialog::onGroupFilterMsg);
	connect(ui->productbtn, &QPushButton::clicked, this, &GroupChatDialog::onpbAdvertInfo);
	connect(Biz::Session::getConverSationManager(), &Biz::ConverSationManager::sgShowProductInfo, this, &GroupChatDialog::doShowProductInfo);

	setTextEditStyle();

}
void GroupChatDialog::initExtendBtn()
{
    ui->externWidget->installEventFilter(this);
    ui->externBtn->installEventFilter(this);
    ui->rightPanel->installEventFilter(this);
    ui->rightPanel->setVisible(true);
    ui->externBtn->setVisible(false);
    ui->externWidget->setVisible(!ui->rightPanel->isVisible());

    connect(ui->externBtn,&QPushButton::clicked,[this](bool checked){
        // 如果右边栏展开，给合上
        ui->rightPanel->setVisible(!ui->rightPanel->isVisible());
        ui->externBtn->setVisible(!ui->rightPanel->isVisible());

        ui->externWidget->setVisible(!ui->rightPanel->isVisible());

        hideEXtendPanel(true);
    });

    QFrameLayout* pLayout = new QFrameLayout(ui->webviewPanel);
    pLayout->appendWidget(ui->webView,AlinementPolicy::ALINE_FILL);
    pLayout->appendWidget(ui->externWidget,AlinementPolicy::ALINE_MATCHHEIGHT|AlinementPolicy::ALINE_RIGHT);
    pLayout->appendWidget(ui->externBtn,AlinementPolicy::ALINE_MATCHHEIGHT|AlinementPolicy::ALINE_RIGHT);
    pLayout->appendWidget(mpUpUnread,AlinementPolicy::ALINE_RIGHT|AlinementPolicy::ALINE_BOTTOM,QMargins(0,0,20,30));
    pLayout->appendWidget(mpAtNotice,AlinementPolicy::ALINE_RIGHT|AlinementPolicy::ALINE_TOP,QMargins(0,30,20,0));
    pLayout->appendWidget(m_pShareToButton,ALINE_BOTTOM|ALINE_HCENTER,QMargins(0,0,0,30));
    ui->webviewPanel->setLayout(pLayout);

    connect(ui->toolbar,&ChatToolBar::sgSendFile,this,&GroupChatDialog::onSelectAndSendFile);
    connect(ui->toolbar,&ChatToolBar::sgShareMessage,this,&BaseChatDialog::onBtnActionShareLocalMessage);
    connect (ui->toolbar,&ChatToolBar::sgOpenInternalUrl,this,&BaseChatDialog::openInternalUrl);
	connect (ui->toolbar,&ChatToolBar::sgSendRequestUrl,this,&BaseChatDialog::sendRequestUrl);

//     QFrameLayout* pFunctionsLayout = new QFrameLayout(ui->chatbar);
//     pFunctionsLayout->appendWidget(ui->titleview,ALINE_FILL);
//     pFunctionsLayout->appendWidget(ui->functions,ALINE_TOP|ALINE_RIGHT,QMargins(0,1,130,0));

	//mTimerloader = startTimer(6000);

	Biz::AllUserSettingData *psetting = Biz::Session::getSettingConfig();
	bool bret = psetting->ShowGroupMemberlist();

	ui->rightPanel->setVisible(bret);

	
}

void GroupChatDialog::initSettings()
{
    using namespace Qt;
    auto remove = WindowTitleHint;
    auto add = FramelessWindowHint | WindowMinMaxButtonsHint;
    setAttribute(Qt::WA_AlwaysShowToolTips, true);
    setAttribute(Qt::WA_TranslucentBackground, true); 
    //setAutoFillBackground(true);
    overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));
#ifdef QCHAT
    setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
#else
    setWindowIcon(QIcon(":/Images/Deal.ico"));
#endif

    mReceiver = new Biz::CallbackReceiver(this);

    // 自家ui
    
    connect(ui->textEdit, &TextEdit::textChanged, this, &GroupChatDialog::onInputChanged);
    connect(ui->sendbtn, &QPushButton::clicked, this, &GroupChatDialog::onSendClick);
    connect(ui->addGroupItem, &QPushButton::clicked, this, &GroupChatDialog::onInviteClicked);
    connect(ui->leaveButton, &QPushButton::clicked, this, &GroupChatDialog::onLeaveClicked);

    // 网页 
    // 绑定js回调事件
    connect(mCommObject, &ChatCommObject::sgShowNewMessageTip,this, &GroupChatDialog::onShowUnreadMsgPop);

    connect(mCommObject, &ChatCommObject::sgShowUpUnreadMessageTip,this,&GroupChatDialog::onShowUnreadMessageTip);
    connect(mCommObject, &ChatCommObject::sgQueryMore, this, &GroupChatDialog::onHistoryMore);

    connect(mCommObject, &ChatCommObject::sgGroupPopMenu, this, &GroupChatDialog::onPopMenu);

	//findmao的回调
	connect(mCommObject, &ChatCommObject::sgReturnfirstMsgid, this, &GroupChatDialog::onReturnfirstMsgid);

    // 扩展 
    connect(SnipScreenTool::getInstance(), &SnipScreenTool::sgFinish, this, &GroupChatDialog::onSnapFinish);
    connect(SnipScreenTool::getInstance(), &SnipScreenTool::sgCancel, this, &GroupChatDialog::onSnapCancel);


    // 搜索联系人
    connect(searchAtResultDlg, &SearchAtResultDialog::sgatItemSelected, this, &GroupChatDialog::onSearchResult);

    // 群成员时间
    connect(Biz::Session::getGroupManager(), &Biz::GroupManager::sgGroupMemberRemoved, this, &GroupChatDialog::onGroupMemberRemoved);
    connect(Biz::Session::getGroupManager(), &Biz::GroupManager::sgGroupMemberChanged, this, &GroupChatDialog::onGroupMemberAddedAff);
    connect(Biz::Session::getGroupManager(), &Biz::GroupManager::sgGroupMemberListReceived,this,&GroupChatDialog::onGroupMemberListReceived);

    // 全局事件

    connect(Biz::Session::getGroupManager(), &Biz::GroupManager::sgMemberInvitedByOtherReceived,this, &GroupChatDialog::onRoomInvitePresenceReceived);
    connect(Biz::Session::getGroupManager(), &Biz::GroupManager::sgDelRegisterReceived, this, &GroupChatDialog::onRoomLeaveOfMember);

    //权限改变的信号和槽的关联

    disconnect(Biz::Session::getGroupManager(), &Biz::GroupManager::sgGroupAuthFaild,
        this, &GroupChatDialog::onGroupAuthFaild);
    connect(Biz::Session::getGroupManager(), &Biz::GroupManager::sgGroupAuthFaild,
        this, &GroupChatDialog::onGroupAuthFaild);
    connect(Biz::Session::getUserVcardManager(), &Biz::UserVcardManager::sgOnlineUserChanged,this,&GroupChatDialog::onUpdatePresence);
    connect(Biz::Session::getGroupManager (), &Biz::GroupManager::sgGroupVcardUpdated,this,&GroupChatDialog::onRoomNameListReceived);
    connect(Biz::Session::getGroupManager (), &Biz::GroupManager::sgGroupSubjectHasChanged,this,&GroupChatDialog::onRoomVcardChanged);

    connect(ui->webView, &webview::loadFinished, this, &GroupChatDialog::onLoadHtmlFinish);

	connect(ui->pbRefresh, &QPushButton::clicked, this, &GroupChatDialog::onRefreshGroupMember);
    mPage = new ChatWebPage(this);
    mPage->addChatChannelToHtml("CLIENT_API", mCommObject);
    ui->webView->setPage(mPage);

    loadChatHtml(ui->webView, "/html/groupdialog.html");
    ui->webView->installEventFilter(this);

    ui->textEdit->installEventFilter(this);
	

    ui->textEdit->setFocus();

    ui->addGroupItem->setEnabled(false);


    ui->textEdit->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->textEdit, &TextEdit::customContextMenuRequested, this, &GroupChatDialog::onShowEditMenu);

    ui->borderinput->setVisible(false);

    mGroupVisitorModel = new GroupVisitorModel(this);
    mGroupVisitorSortProxyModel = new GroupVisitorSortProxyModel(this);
    mGroupVisitorSortProxyModel->setSourceModel(mGroupVisitorModel);
    ui->listView->setModel(mGroupVisitorSortProxyModel);
    mGroupVisitorSortProxyModel->sort(0);   



    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listView->setItemDelegate(new VisitorItemDelegate());
    ui->listView->setStyleSheet("border:0px;");

    connect(ui->listView,&QListView::doubleClicked,this,&GroupChatDialog::doubleClicked);

    
    QPixmap pixmap = Biz::PortraitHelper::getGroupPortrait(conversationId());
    pixmap = QPixmap::fromImage(pixmap.toImage().scaled(ui->headerimage->size()));
    ui->headerimage->setPixmap(pixmap);
    ui->headerimage->installEventFilter(this);
    

    connect(Biz::Session::getUserVcardManager(),&Biz::UserVcardManager::sgGroupHeaderUpdate,this,&GroupChatDialog::onUpdateGroupHeader);
    bWebLoaded = false;


    //对textedit进行设置
    ui->textEdit->setAcceptDrops(false);
    ui->frametextedit->setAcceptDrops(true);
    ui->frametextedit->installEventFilter(this);
    ui->webviewPanel->setAcceptDrops(true);
    ui->webviewPanel->installEventFilter(this);
    ui->webView->installEventFilter(this);


    
   


    //菜单（）
    m_MemberMenu = new QMenu(ui->listView);

    // 设置管理员
    mActionProfile = m_MemberMenu->addAction(QStringLiteral("查看该成员资料"));
    m_MemberMenu->addSeparator();
    mActionSetAdmin = m_MemberMenu->addAction(QStringLiteral("设置为管理员"));
    mActionCancleAdmin = m_MemberMenu->addAction(QStringLiteral("取消管理员"));
    m_MemberMenu->addSeparator();
    mActionKick = m_MemberMenu->addAction(QStringLiteral("踢出该成员"));


    connect(mActionSetAdmin,&QAction::triggered,this,&GroupChatDialog::SetAdmin);
    connect(mActionCancleAdmin,&QAction::triggered,this,&GroupChatDialog::CancleAdmin);
    connect(mActionKick,&QAction::triggered,this,&GroupChatDialog::MoveMember);
    connect(mActionProfile,&QAction::triggered,this,&GroupChatDialog::onMemberProfile);

    ui->leaveButton->setVisible(false);


    Biz::GroupSetting* setting = Biz::Session::currentAccount().getGroupsData()->getGroupSetting(conversationId());
    if (NULL!=setting)
    {
        QString subJect = setting->Subjuct();
        ui->noticy->setText(subJect);
        ui->noticy->setToolTip(subJect);
    }

    connect(Biz::Session::getConverSationManager(), &Biz::ConverSationManager::sgReloadConversationMsg, this, &GroupChatDialog::OnReloadOfflineMsg);

	mGetHistoryMessageTimerout.setDuration(1000*8);
    connect(&mGetHistoryMessageTimerout,&QTimeLine::finished,[this](){
        Log::e("group chat get more history timeout");
        this->doMergeMessageCache(QSharedPointer<Biz::MessageListData>());
    });

    ui->widget->installEventFilter(this);
    connect(Biz::Session::getUserVcardManager(), &Biz::UserVcardManager::sgUseVcardChanged,this,&GroupChatDialog::onRosterCardChangeUpdate);

    connect(Biz::Session::getUserVcardManager(), &Biz::UserVcardManager::sgPortraitUpdate, this, &GroupChatDialog::onRosterPortraitUpdate);

    connect(GloableEventObject::getInstance(), &GloableEventObject::sgFontSizeChange,this, &GroupChatDialog::onGloableFontSizeChanged);

    if (Biz::Session::getSettingConfig()->SetFontSize())
    {
        InitFontSize();
    }

    connect(MainApp::UIFrame::getMainDialogController(),&MainApp::MainDialogController::sgMainDialogVisableChange,
        this,&GroupChatDialog::onMainDialogVisableChange);
    connect(GloableEventObject::getInstance(),&GloableEventObject::sgMainDialogActivitied, 
        this,&GroupChatDialog::onMainDialogVisableChange);



    QSharedPointer<Biz::XmppMessage> msg (new Biz::XmppMessage(Biz::Session::currentAccount().accountData().UserID()));
    msg->ConversationID(conversationId());
    msg->MsgSourceType(Biz::GroupMessage);
    Biz::Session::getConverSationManager()->saveConversationInfo(msg,NULL);

    connect (ui->btnMore,&QPushButton::clicked,[this]{
        GroupFileListViewSingleton::getInstance ()->refreshFileMessage (conversationId ());
    });
	connect(MainApp::UIFrame::getConversationController(),&ConversationController::sgGroupChatMsgFilter,this,&GroupChatDialog::onGroupChatMsgFilter);

	connect(MainApp::UIFrame::getConversationController(),&ConversationController::sgGroupChatMsgAtFilter,this,&GroupChatDialog::onGroupChatMsgAtFilter);

     refreshFileMessage (); 

	 ShowInputWillSendMsg();

	loadGroupMember();
}

GroupChatDialog::~GroupChatDialog()
{
    ui->webView->deleteLater();
    delete ui;
    ui = NULL;
	
}

void GroupChatDialog::onSetTitle(const QString& groupJid, const QString& displayName)
{

    ui->toolbar->setConversationId(groupJid);

    ui->borderinput->setVisible(true);
    setCounversationId(groupJid);


    QString title = Biz::Session::getGroupManager()->getGroupLocalNickNamebyId(groupJid);//Biz::Session::getGroupManager()->getGroupNickName(groupJid);
    ui->name->setText(title);
    this->setWindowTitle(title);



    if (0==mGroupVisitorModel->rowCount())
    {
        mGroupVisitorModel->createItem("blank",0, T_("GroupChatDialog_InitGroupList"), VisitorItem::NONE);
    }

    Log::e(QString("GroupChatDialog::onSetTitle %1").arg(groupJid));
}

void GroupChatDialog::onMessageReceived(const QSharedPointer<Biz::XmppMessage>& msg)
{

    if(msg->ConversationID() != conversationId()){
        return;
    }

    Log::e("GroupChatDialog::onMessageReceived "+msg->MessageID());
	m_cctext = msg->cctext();
	m_bu = msg->bu();
    if(!bWebLoaded)
    {
        m_lstMsgCatch.append(msg);
    }
    else
    {

		//dochangeBodyAtInofr(msg);

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

				appendMessage(false, false, msg, 1); 
				
			}
			
        }
		else
		{
			//这地方不应该在此调用clearConversationAllRead(conversationId());

			//MainApp::UIFrame::getConversationController()->clearConversationAllRead(conversationId());
			appendMessage(false, false, msg, 1); // 当期窗口，让回调判定是否需要显示未读数
		}
        
    }
}


void GroupChatDialog::preFormatMessageToHtml(QSharedPointer<Biz::XmppMessage> spMessage,bool isHistory,bool hasMore, bool& bshow)
{
	//判断是否是该聊天框
	if (spMessage->ConversationID() != conversationId() )
	{
		//
		return;
	}
	m_cctext = spMessage->cctext();
	m_bu = spMessage->bu();
    if (!isHistory && Biz::MessageUtil::chargeIsAtNotice(spMessage))
    {
        if (Biz::MessageTypeSelf != spMessage->MsgDirection())
        {
            QString msgStr;
            MessageParser::getInstance()->getShotTranslatedMessage(spMessage,msgStr);
            showAtNotice(spMessage->Resource(),msgStr, spMessage->MessageID());
        }
    }
	if (Biz::MessageUtil::chargeIsAtNotice(spMessage))
	{
		MainApp::UIFrame::getConversationController()->addAtInfor(conversationId(), spMessage->SenderJid(), spMessage->MessageID());
	}
	
	if (Biz::MessageMediaType::MediaTypeFile == spMessage->MediaType ())
	{
		refreshFileMessage ();
	}
 }

void GroupChatDialog::closeEvent(QCloseEvent *event)
{
    Biz::Session::getSettingConfig()->GroupChatDlgWidth(this->width());
    Biz::Session::getSettingConfig()->GroupChatDlgHeight(this->height());
    emit sgCloseDlg(conversationId());
}

void GroupChatDialog::onGroupMemberListReceived(const QString& groupBareJid,const QList<QSharedPointer<Biz::GroupMemberModule>>& members)
{
    if (groupBareJid != conversationId()) 
        return;
	Log::e(QString("GroupChatDialog::onGroupMemberListReceived(Client send emit mAccount->sgGroupMemberListReceived groupBareJid=%1 members=%2)")
		.arg(groupBareJid).arg(members.size()));
    // merge 删除列表中存在二数据中存在的，更新列表中存在的，增加列表中不存在的
    QStringList memberExistids = mGroupVisitorModel->GetGroupItemMap().keys();

    QStringList toUpdateIds;
    QStringList theFullIds;

    for (QSharedPointer<Biz::GroupMemberModule> spMember : members)
    {
        if (spMember.isNull() || spMember->m_resourceJid.isEmpty ())
            continue;

        QString memberid = spMember->m_resourceJid;
        theFullIds.append(memberid);
		if (spMember->m_affiliation == QXmppMucItem::OwnerAffiliation)
		{
			mGroupCreator = memberid;
		}

        if (memberExistids.contains(memberid))
        {
            mGroupVisitorModel->updateAffic(spMember->m_resourceJid,(int)(spMember->m_affiliation));
            memberExistids.removeOne(memberid);
        }
        else
        {
            // 不存在，增加
			QString strresourcedisplay = Biz::Session::getUserVcardManager()->getUserNameByConversationId(spMember->m_resourceJid);
			if (strresourcedisplay.isEmpty())
			{
				strresourcedisplay = spMember->m_resource;
			}
            mGroupVisitorModel->createItem(spMember->m_resourceJid ,
                spMember->m_affiliation, 
               /* spMember->m_resource*/strresourcedisplay,
                Biz::Session::getUserVcardManager()->isUserOnline(spMember->m_resourceJid)?VisitorItem::ONLINE:VisitorItem::OFFLINE);
            mGroupVisitorModel->updateAffic(spMember->m_resourceJid,(int)(spMember->m_affiliation));
            VisitorItem* pItem = mGroupVisitorModel->getItemFromBareJid(spMember->m_resourceJid);
            if( pItem )
                pItem->setMemberJid(spMember->m_resourceJid);	

            toUpdateIds.append(memberid);
        }
    }
    for (QString memberexistid:memberExistids)
    {
        // 不存在的删除
        if (!theFullIds.contains(memberexistid))
        {
            mGroupVisitorModel->removeItem(memberexistid);
        }
    }

    if (!toUpdateIds.isEmpty())
    {
        //插入到群用户关联表中
        Biz::Session::getUserVcardManager()->getGroupMemberOnline(groupBareJid,toUpdateIds);
        // 获取成员列表的头像信息
        //Biz::Session::getUserVcardManager()->getDomainUsersVcardByVersionandImage(toUpdateIds);
    }

    if (mGroupVisitorModel->GetGroupItemMap().size()>0)
    {
        mGroupVisitorModel->wheelMove();
        ui->addGroupItem->setEnabled(true);
    }
    doUpdateGroupMemberCount();
	quint64 getbegintickedtm =  QDateTime::currentMSecsSinceEpoch();
	Log().rt("login---"+QStringLiteral("群成员加载完") + QString(" -------> loginendime:%1").arg(getbegintickedtm));
}

void GroupChatDialog::dropFileToEdit(const QString& filePath)
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

    QString localPath = newFile;//newFile;//filePath;
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
void GroupChatDialog::dropFileToWebArea(const QString& filePath)
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
void GroupChatDialog::onInputChanged()
{
    QString text = ui->textEdit->toPlainText();
    if(text.length() <=0 )
    {
		appendWillSendMsg();
        searchAtResultDlg->setVisible(false);
        return;
    }
	appendWillSendMsg();

    int curPos = ui->textEdit->textCursor().position();
    if(curPos > 0)
    {
		
       // QStringList listFilter;
		QMap<QString, QString> listFilter;// <id, value>
        startPos = qMax(text.lastIndexOf("@"),text.lastIndexOf(QStringLiteral("＠")));
        if (-1==startPos)
        {
			searchAtResultDlg->setVisible(false);
            return;
        }
		//判断一下@和光标之间的值
        QString searchKey = text.mid(startPos+1, curPos-startPos - 1);
        // 经过过滤的（拼音过滤，uid过滤，原文本过滤）
        QMap<QString,VisitorItem*> groupMembers = mGroupVisitorModel->GetGroupItemMap();
        for (VisitorItem* pitem:groupMembers.values())
        {
            QString userid = Biz::MessageUtil::makeSureUserId(pitem->MemberJid());
			//这地方的坑，就是，如果右侧的群成员没有拉取到，那么这地方就是空
            QString userName = pitem->data(Qt::DisplayRole).toString();/*Biz::Session::currentAccount().getUserNameById(userid);*///pitem->data(Qt::DisplayRole).toString();(由于改备注被修改了显示的名字)
            if (userName.compare(userid, Qt::CaseInsensitive) == 0) //这里涉及到跨域的时候，username和userid相等的情况
            {
                userName = pitem->data(Qt::DisplayRole).toString();
            }
            QString userNamePy = Biz::SpellHelper::MakeSpellCode(userName,(Biz::SpellHelper::SpellOptions)0).trimmed();

            if ((!userid.isEmpty()&&!userName.isEmpty()) 
                && (searchKey.isEmpty() || userid.contains(searchKey,Qt::CaseInsensitive) || userName.contains(searchKey,Qt::CaseInsensitive) || userNamePy.contains(searchKey,Qt::CaseInsensitive)))
            {
                listFilter.insert(userid, userName);
            }

        }

        //listFilter.sort();
        if(listFilter.size() > 0)
        {
			int a = searchAtResultDlg->minimumHeight();
			searchAtResultDlg->setList(listFilter);
			int nheight = (listFilter.size()>5 ? 5 : listFilter.size()) * SearchAtResultDialog::ItemHeight + 3;
			searchAtResultDlg->resize(QSize(SearchAtResultDialog::ItemWidth, nheight)); // list列表默认高度19，上下panding2

			searchAtResultDlg->setFixedHeight(nheight);

            QRect  rect = ui->textEdit->cursorRect();
			int rectnx = rect.topRight().rx();
			int rectny = rect.topRight().ry();
			int nHeight = rect.height();
            QPoint editPos = ui->textEdit->viewport()->mapToGlobal(rect.topRight());

			int editnx = editPos.rx();
			int editny = editPos.ry();

			int nx = editPos.rx();
			int ny = editPos.ry()- nheight - 3;

			searchAtResultDlg->move(editPos.rx(), editPos.ry()- nheight - 3);

			if (!searchAtResultDlg->isVisible())
            {
				searchAtResultDlg->setVisible(true);
            }
			int nsize = listFilter.size();
			QRect rectatdlg = searchAtResultDlg->geometry();
			int dlgwidth = rectatdlg.width();
			int dlgheight = rectatdlg.height();
            ui->textEdit->activateWindow();
            ui->textEdit->setFocus();        
        }else{
			searchAtResultDlg->setVisible(false);
        }

    }
	else
	{
		searchAtResultDlg->setVisible(false);
	}
}
void GroupChatDialog::onClose(bool)
{
    this->close();
}
void GroupChatDialog::onInviteClicked(bool)
{
    QMap<QString,QString> members;

    if( mGroupVisitorModel )
    {
        QMap<QString,VisitorItem*> items = mGroupVisitorModel->GetGroupItemMap();
        for (VisitorItem* item : items.values())
        {
            members.insert(item->MemberJid(),item->nickName());
        }
    }


    CreateNewGroup *pDiolog = CreateNewGroupSingleton::getInstance();
    if (pDiolog)
    {
        pDiolog->setCallBack(NULL);
        pDiolog->isCreateNewGroup(false);
        pDiolog->setMemberList(members);
        pDiolog->setGroupJid(conversationId());
        pDiolog->showNormal();
        pDiolog->activateWindow();
    }

}
void GroupChatDialog::onLeaveClicked(bool)
{
    this->close();

    MainApp::UIFrame::getConversationController()->removeConversation(conversationId());
    Biz::Session::getConverSationManager()->removeChartingImSession(conversationId());
}
void GroupChatDialog::onGroupMemberAddedAff(const QString& groupJid,const Biz::GroupMemberModule& amember)
{
    if(groupJid != conversationId()){
        return;
    }

    //删除列头
    if(mGroupVisitorModel->getItemFromBareJid("blank") != NULL)
        mGroupVisitorModel->removeItem("blank");


    if( !mGroupVisitorModel->getItemFromBareJid(amember.m_resourceJid) )
    {
        mGroupVisitorModel->createItem(amember.m_resourceJid , amember.m_affiliation, amember.m_resource, VisitorItem::ONLINE);
    }

    VisitorItem* pItem = mGroupVisitorModel->getItemFromBareJid(amember.m_resourceJid);
    if( pItem )
    {
        pItem->setData(amember.m_affiliation, VisitorItem::UserAffiliationType);
        pItem->setPresence(VisitorItem::ONLINE);
    }

    ui->addGroupItem->setEnabled(true);
    int count = mGroupVisitorModel->GetCountItem();
    int onlineCount = mGroupVisitorModel->getOnlineMemberCount();

    QString strText = QStringLiteral("群成员(%2/%1)").arg(count).arg(onlineCount);
    ui->groupListTitle->setText(strText);

    doUpdateGroupMemberCount();
}
void GroupChatDialog::onGroupMemberRemoved(const QString& groupJid,const QString& fullName)
{
    if(groupJid != conversationId()){
        return;
    }

    //先下线，再判断是否退群
    mGroupVisitorModel->updatePresence(groupJid,VisitorItem::OFFLINE);

    int count = mGroupVisitorModel->GetCountItem();
    int onlineCount = mGroupVisitorModel->getOnlineMemberCount();

    QString strText = QStringLiteral("群成员(%2/%1)").arg(count).arg(onlineCount);
    ui->groupListTitle->setText(strText);

    doUpdateGroupMemberCount();

}
bool GroupChatDialog::eventFilter(QObject *obj, QEvent *event)
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
                QString objNmae = ui->frametextedit->objectName();
                ui->frametextedit->setStyleSheet("QWidget#"+ objNmae + "{border:none;}");
                break;
            }
            if (event->type() == QEvent::Drop)
            {
                QDragEnterEvent* pE = (QDragEnterEvent*)event;
                QString strcurrent = pE->mimeData()->text();
#ifndef _WINDOWS
				if (strcurrent.right(2) == "\r\n")
				{
					strcurrent = strcurrent.left(strcurrent.length() - 2);
				}
#endif // _WINDOWS

                dropFileToEdit(strcurrent);
                pE->accept();  
                QString objNmae = ui->frametextedit->objectName();
                ui->frametextedit->setStyleSheet("QWidget#"+ objNmae + "{border:none;}");

                break;
            }
            break;
        }


        if (obj == ui->webviewPanel)
        {
            if (event->type() == QEvent::DragEnter 
                || event->type() == QEvent::DragMove)
            {
                QDragEnterEvent* pE = (QDragEnterEvent*)event;
                if (ui->webView != pE->source())
                {
                    QString objNmae = ui->webviewPanel->objectName();
                    ui->webviewPanel->setStyleSheet("QWidget#"+ objNmae + "{border:1px solid #2693D5;}");
                    pE->setDropAction(Qt::MoveAction);
                    pE->accept();
                }
                break;
            }

            if (event->type() == QEvent::DragLeave)
            {
                QString objNmae = ui->webviewPanel->objectName();
                ui->webviewPanel->setStyleSheet("QWidget#"+ objNmae + "{border:none;}");
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

                    QString objNmae = ui->webviewPanel->objectName();
                    ui->webviewPanel->setStyleSheet("QWidget#"+ objNmae + "{border:none;}");
                }

                break;
            }


        }

		if (obj == ui->textEdit && searchAtResultDlg->isVisible())
        {
            if (event->type() == QEvent::KeyPress) 
            {
                QKeyEvent *keyEvent = reinterpret_cast<QKeyEvent*>(event);
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
                else if (keyEvent->key() == Qt::Key_Return)
                {
                    SearchSelected();
                    return true;
                } 
            }else if(event->type() == QEvent::FocusOut)
            {
				if (!searchAtResultDlg->isActiveWindow())
					searchAtResultDlg->setVisible(false);
            }

            break;
        }

		if (obj == ui->rightPanel || obj == ui->externBtn || obj == ui->externWidget )
		{
			if (event->type() == QEvent::Enter) 
			{
				showExtendPanel(true);
			}
			else if(event->type() == QEvent::Leave)
			{
				QString objName = obj->objectName();
				hideEXtendPanel(false);
			}
			break;
		}
		if ( obj == ui->noticy )
		{
			if (event->type() == QEvent::MouseButtonDblClick)
			{
				QLabel* plabel = (QLabel*)obj;
				plabel->setSelection(0,plabel->text().size());

                return true;
            }
        }
        if (obj == ui->name)
        {
            if (event->type() == QEvent::MouseButtonPress)
            {
                mbhover = false;
                onSetting(true);
                break;
            }
            if(event->type() == QEvent::Enter)
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
            if (event->type() == QEvent::MouseButtonDblClick
                || event->type() == QEvent::MouseButtonPress)
            {
                onSetting(true);
                break;
            }
        }
        if (obj == this)
        {
            QKeyEvent *keyEvent = dynamic_cast<QKeyEvent*>(event);
            if (NULL!=keyEvent && keyEvent->modifiers() == (Qt::ShiftModifier | Qt::AltModifier | Qt::ControlModifier) && keyEvent->key() == Qt::Key_M)
            {
                static bool showmatype = true;
                QString str = QString("setMatypeDisplay('%1')").arg(showmatype?"":"none");
                showmatype = !showmatype;
                mPage->runLocalJavaScript(str);
            }      

            if (QEvent::WindowDeactivate == event->type())
            {
                hideEXtendPanel(true);
            }
            break;
        }

        if (obj == ui->widget)
        {
            if (event->type() == QEvent::MouseButtonDblClick)
            {
                return true;
            }
			break;
        }
		

    } while (false);

    return BaseChatDialog::eventFilter(obj, event);
}
void GroupChatDialog::onYijianClicked(bool)
{
    QDesktopServices bs;        
    bs.openUrl(QUrl("https://github.com/qunarcorp/qtalk"));
}
void GroupChatDialog::onSnapFinish(const QString& wid)
{
    if(conversationId() != wid)
        return;
    QString localPath = Biz::ConfigureHelper::user_ImagesPath(Biz::Session::currentAccount().accountData().UserID());
    QString fileName = localPath + QDateTime::currentDateTime().toString("yyyyMMddhhmmsszzz.png");
    QApplication::clipboard()->pixmap().save(fileName, "PNG");

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
void GroupChatDialog::onSnapCancel(const QString& wid)
{
    if(conversationId() != wid)
        return;
    ui->textEdit->setFocus();
}
void GroupChatDialog::SearchMoveDown()
{
	searchAtResultDlg->setMoveDown();
}
void GroupChatDialog::SearchMoveUp()
{
	searchAtResultDlg->setMoveUp();
}
void GroupChatDialog::SearchSelected()
{
	searchAtResultDlg->selectItem();
}
void GroupChatDialog::onSearchResult(const QString& text)
{
    QTextCursor cursor = ui->textEdit->textCursor();
    int curPos =cursor.position();

	QString atText = Biz::Session::getUserVcardManager()->getUserNameByConversationId(text);
    if(startPos >=0 && curPos >= startPos/*curPos - startPos < 8*/)
    {
        while (cursor.position() > startPos+1)
            cursor.deletePreviousChar();
        cursor.insertText(atText+" ");
        startPos = 0;
    }
}

void GroupChatDialog::onShowUnreadMsgPop(const QString& nickname, const QString& messageid)
{
    mpUpUnread->setDownUnreadText(QStringLiteral("有新消息"));
    mpUpUnread->setAnchoragePoint(messageid);
    //mpUpUnread->show();
}


void GroupChatDialog::onHideUnreadMsgPop()
{
    if (MainApp::UIFrame::getConversationController()->topConversationId()==conversationId() && CloseableButtonView::ShowType::ST_DOWNUNREAD==mpUpUnread->getShowType())
    {
        mpUpUnread->hide();
    }
}


void GroupChatDialog::onHideUpUnreadMessageTip()
{
    if (MainApp::UIFrame::getConversationController()->topConversationId()==conversationId() && CloseableButtonView::ShowType::ST_UPUNREAD==mpUpUnread->getShowType())
    {
        mpUpUnread->hide();
    }
}
void GroupChatDialog::onShowUnreadMessageTip()
{
	auto getAllUnreadMessageCallback = mReceiver->createCallback<QSharedPointer<Biz::MessageListData>>([this](const QSharedPointer<Biz::MessageListData>& unreadmessage )
	{
		mpUpUnread->setAnchoragePoint(MessageUnreadTip::sKey);
		if(unreadmessage->getMessageList().size() > 0)
		{
			mpUpUnread->setUpUnreadText(QStringLiteral("%1条新消息").arg(unreadmessage->getMessageList().size()));
			//mpUpUnread->show();
		}
	}, []{ });
	Biz::Session::getMessageManager()->getAllUnreadMessageList(conversationId(),getAllUnreadMessageCallback);
}


//进行拖拽文件的事件
void GroupChatDialog::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("text/uri-list"))
    {
        event->acceptProposedAction();
    }
}

#include "UIFrame.h"
#include "ConversationController.h"
void GroupChatDialog::doubleClicked(const QModelIndex& index)
{
    QString userjid = index.data(VisitorItem::UserJid).toString();
    userjid = Biz::MessageUtil::makeSureUserJid(userjid);

    if(userjid.isEmpty())
        return;

    MainApp::UIFrame::getConversationController()->createNewChatDialog(userjid);
    MainApp::UIFrame::getConversationController()->addSimpleChatRosterItem(userjid,MainApp::ConversationController::sDefaultExtendPanel);
    MainApp::UIFrame::getConversationController()->activeConversation(userjid);
    MainApp::UIFrame::getConversationController()->moveSessionToTop(userjid);
}





void GroupChatDialog::showAtNotice(const QString& sender,const QString& msg,const QString &msgid)
{
    mpAtNotice->setAtTipText(QStringLiteral("有人@了你"));
    mpAtNotice->setAnchoragePoint(msgid);
    mpAtNotice->show();
}


void GroupChatDialog::showAtBlock( const QString&id, const QString&msgid )
{
	if(conversationId() != id)
		return;
	mpAtNotice->setAtTipText(QStringLiteral("有人@了你"));
	mpAtNotice->setAnchoragePoint(msgid);
	mpAtNotice->show();
}

void GroupChatDialog::onSendFile( const QString&filePath )
{

}

void GroupChatDialog::contextMenuEvent(QContextMenuEvent *e)
{
    QModelIndexList list =  ui->listView->selectionModel()->selectedIndexes();

    if (list.size()>0)
    {
        m_MemberMenu->close();

        QMap<QString, VisitorItem*> mjidGroupItemMap = mGroupVisitorModel->GetGroupItemMap();

        QString SelectUserId = list.at(0).data(VisitorItem::UserJid).toString();
        QString strSelfId = Biz::MessageUtil::makeSureUserJid(Biz::Session::currentAccount().accountData().UserID());

        if (mjidGroupItemMap.contains(SelectUserId) && mjidGroupItemMap.contains(strSelfId))
        {
            // 对方数据
            VisitorItem* selectItem = mjidGroupItemMap.value(SelectUserId);
            int nTargetAffic = selectItem->data(VisitorItem::UserAffiliationType).toInt();
            m_SelectUserId = selectItem->data(VisitorItem::UserJid).toString();

            // 操作者的数据
            VisitorItem* myItem = mjidGroupItemMap.value(strSelfId);
            int nMyAffic = myItem->data(VisitorItem::UserAffiliationType).toInt();

            mActionSetAdmin->setEnabled(
                nMyAffic==QXmppMucItem::OwnerAffiliation    // 自己是群主
                && SelectUserId!=strSelfId                  // 不能提升自己为管理员
                && nTargetAffic < QXmppMucItem::AdminAffiliation // 目标不是管理员
                );
            mActionCancleAdmin->setEnabled(
                nMyAffic==QXmppMucItem::OwnerAffiliation    // 自己是群主
                && nTargetAffic == QXmppMucItem::AdminAffiliation // 目标已是管理员
                );

            mActionSetAdmin->setVisible(nTargetAffic != QXmppMucItem::AdminAffiliation);
            mActionCancleAdmin->setVisible(nTargetAffic == QXmppMucItem::AdminAffiliation);

            mActionKick->setEnabled(
                nMyAffic>=QXmppMucItem::AdminAffiliation    // 自己是群主,或者管理员
                && SelectUserId!=strSelfId                  // 不能操作自己
                && nTargetAffic <= QXmppMucItem::AdminAffiliation   // 目标不是群主
                && nMyAffic > nTargetAffic                  // 操作者的权限高于被操作者
                );

            QRect rect;
            rect = ui->listView->rect();
            QPoint pt = QCursor::pos();

            m_MemberMenu->exec(pt);
        }
    }

}
void GroupChatDialog::onSetting(bool b)
{
	//获取群的群主

    Biz::Session::getUserVcardManager()->getRoomVcardByforce(conversationId());
    GroupSettingDialog* gsd = GroupSettingDialog::getInstance();
    gsd->hide();
    gsd->setupData(conversationId());
    gsd->initUi();
    gsd->activateWindow();
    gsd->showNormal();
	gsd->setGroupCreator(mGroupCreator);
}
void GroupChatDialog::SetAdmin()
{
    QModelIndexList list =  ui->listView->selectionModel()->selectedIndexes();

    if (list.size()>0)
    {
        QModelIndex index = list.at(0);

        QString SelectUserId = index.data(VisitorItem::UserJid).toString();
        QString name = index.data(Qt::DisplayRole).toString();
        Biz::Session::getGroupManager()->setMemberAffiliation(conversationId(),name,SelectUserId,QXmppMucItem::AdminAffiliation);
        mGroupVisitorModel->updateAffic(SelectUserId,QXmppMucItem::AdminAffiliation);
    }
}
void GroupChatDialog::CancleAdmin()
{
    QModelIndexList list =  ui->listView->selectionModel()->selectedIndexes();
    if (list.size()>0)
    {
        QModelIndex index = list.at(0);

        QString SelectUserId = index.data(VisitorItem::UserJid).toString();
        QString name = index.data(Qt::DisplayRole).toString();
        Biz::Session::getGroupManager()->setMemberAffiliation(conversationId(),name,SelectUserId,QXmppMucItem::MemberAffiliation);
        mGroupVisitorModel->updateAffic(SelectUserId,QXmppMucItem::MemberAffiliation);
    }
}

void GroupChatDialog::MoveMember()
{
    QModelIndexList list =  ui->listView->selectionModel()->selectedIndexes();
    if (list.size()>0)
    {
        QModelIndex index = list.at(0);
        QString SelectUserId = index.data(VisitorItem::UserJid).toString();

        QSharedPointer<Biz::ImSelfPerson> spPerson = Biz::Session::getUserVcardManager()->userVcard(SelectUserId);
        QString name;
        if (!spPerson.isNull())
        {
            name = spPerson->strNickName;
        }
        if (name.isEmpty())
        {
            name = index.data(Qt::DisplayRole).toString(); // -->这个name不一定是nickname,只能覆盖qtalk大多数用户
        }

        Biz::Session::getGroupManager()->kickMember(conversationId(),name,SelectUserId);
    }
}

void GroupChatDialog::onItemClicked(QAction *action)
{
    QVariantMap map = action->data().value<QVariantMap>();
    QString userId = map["userid"].toString();
    QString dispName = map["name"].toString();


    if(!userId.isEmpty())
    {
        if(action->text() == T_("GroupChatDialog_item_action4"))
        {
            MainApp::UIFrame::getConversationController()->createNewChatDialog(userId);
            MainApp::UIFrame::getConversationController()->addSimpleChatRosterItem(userId,MainApp::ConversationController::sDefaultExtendPanel);
            MainApp::UIFrame::getConversationController()->activeConversation(userId);
        }else if(action->text() == T_("GroupChatDialog_item_action5"))
        {
            MainApp::UIFrame::getConversationController()->createNewChatDialog(userId);
            MainApp::UIFrame::getConversationController()->addSimpleChatRosterItem(userId,MainApp::ConversationController::sDefaultExtendPanel);
            MainApp::UIFrame::getConversationController()->activeConversation(userId);
            MainApp::UIFrame::getConversationController()->emitSimpleChatDialogSendFile(userId);

        }else if(action->text() == T_("GroupChatDialog_item_action6"))
        {
            QDesktopServices bs;        
            bs.openUrl(QUrl(QString("mailto:%1@qunar.com").arg(userId)));
        }else if (action->text() == T_("GroupChatDialog_item_action7"))
        {
            int a =  10;
            a =20;
        }


    }
}

void GroupChatDialog::onGroupAuthFaild(const QString& jid)
{
    // 密码错误
    Q_UNUSED(jid);
}

void GroupChatDialog::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
    {
		if (searchAtResultDlg->isVisible())
        {
			searchAtResultDlg->hide();
        }
    }
    return BaseChatDialog::keyPressEvent(event);
}



bool GroupChatDialog::matchKey(const QStringList &grouplist, const QString&strkey)
{
    bool bret = false;
    foreach (QString str, grouplist)
    {
        if (str.contains(strkey,Qt::CaseInsensitive) )
        {
            bret = true;
            break;
        }
    } 

    return bret;
}

void GroupChatDialog::getMoreHistoryMsg(quint64 timestamp, int count,bool firstcall, bool breviewmore)
{
    if (conversationId().isEmpty())
        return;

    if (firstcall)
    {
        mGetHistoryMessageTimerout.stop();
        mGetHistoryMessageTimerout.start();
    }
	mbloaded = true;
    count = timestamp==0?5:count;
    timestamp = timestamp==0?Constant::INT64_MAX_T:timestamp;
	//不让定时器去在次的加载
	mbloaded = true;

    auto callback = mReceiver->createCallback<QSharedPointer<Biz::MessageListData>>([this,firstcall, breviewmore](const QSharedPointer<Biz::MessageListData>& messageList )
    {
		
		quint64 getmsgendticked =  QDateTime::currentMSecsSinceEpoch();
		Log::e(QString("GroupChatDialog::getMoreHistoryMsg getmsg end %1 groupjid=%2").arg(getmsgendticked).arg(conversationId()));
        Log::e("GroupChatDialog::onGetMore callback" );
		//先清单原来的数据，然后展示新的数据
		if (!breviewmore)
		{
			onClearContents();
		}
		
		mCommObject->jsSetloadStatus(mPage, 1);
        onHistoryAppend(messageList);

		getmsgendticked =  QDateTime::currentMSecsSinceEpoch();
		Log::e(QString("GroupChatDialog::getMoreHistoryMsg showmsg end %1 groupjid=%2").arg(getmsgendticked).arg(conversationId()));
		Log::e("GroupChatDialog::onGetMore callback" );
        Biz::Session::getConverSationManager()->setGroupConversationMessageRead(conversationId());
        if (firstcall)
		{
            doMergeMessageCache(messageList);
			setLastInforItem(messageList->getMessageList());
		}

		quint64 getbegintickedtm =  QDateTime::currentMSecsSinceEpoch();
		Log().rt("login---"+QStringLiteral("群消息加载完") + QString(" -------> loginendime:%1").arg(getbegintickedtm));
		//MainApp::UIFrame::getConversationController()->updateChatContent(conversationId(), QSharedPointer<Biz::XmppMessage>());


    }, []{ });


    if (firstcall)
    {
		
        // 获取当前会话的 所有未读消息，如果数据库里面没有消息，则向上拿五条。
        auto getAllUnreadMessageCallback = mReceiver->createCallback<QSharedPointer<Biz::MessageListData>>([this,count,timestamp,callback](const QSharedPointer<Biz::MessageListData>& unreadmessage )
        {
			quint64 getmsgendticked =  QDateTime::currentMSecsSinceEpoch();
			Log::e(QString("first GroupChatDialog::getMoreHistoryMsg getAllUnreadMessageList end %1 groupjid=%2").arg(getmsgendticked).arg(conversationId()));
            disconnect(MainApp::UIFrame::getConversationController(),&MainApp::ConversationController::sgCurrentConversationChange,this,&GroupChatDialog::onCurrentConversationChange);
            connect(MainApp::UIFrame::getConversationController(),&MainApp::ConversationController::sgCurrentConversationChange,this,&GroupChatDialog::onCurrentConversationChange);
            disconnect(MainApp::UIFrame::getConversationController(),&MainApp::ConversationController::sgConversationActived,
                this,&GroupChatDialog::onConversationActived);
            connect(MainApp::UIFrame::getConversationController(),&MainApp::ConversationController::sgConversationActived,
                this,&GroupChatDialog::onConversationActived);

            if (unreadmessage->getMessageList().isEmpty())
            {
				Log::e(QString("GroupChatDialog::getMoreHistoryMsg groupjid=%1 unreadmessage->getMessageList().isEmpty()").arg(conversationId()));
				quint64 getmsgendticked =  QDateTime::currentMSecsSinceEpoch();
				Log::e(QString(" unread is empty first GroupChatDialog::getMoreHistoryMsg getmsg begin %1 groupjid=%2").arg(getmsgendticked).arg(conversationId()));
                Biz::Session::getMessageManager()->getGroupHistoryMessageList(conversationId(),count,timestamp,callback);
            }
            else
            {
                // 写一个以下为未读消息
				Log::e(QString("GroupChatDialog::getMoreHistoryMsg groupjid=%1 unreadmessage->getMessageList().is not Empty()").arg(conversationId()));
                QSharedPointer<Biz::XmppMessage> message(new Biz::XmppMessage(""));
                message->MsgSourceType(Biz::MessageSourceType::RevertMsgType);
                message->MediaType(Biz::MessageMediaType::MediaTypeText);
                message->UtcTime(unreadmessage->getMessageList().at(0)->UtcTime());
                unreadmessage->getMessageList().insert(0,message);
                callback->doCompleted(unreadmessage);
				Log::e(QString("GroupChatDialog::getMoreHistoryMsg groupjid=%1 callback->doCompleted after").arg(conversationId()));
                for (QSharedPointer<Biz::XmppMessage> spMessage : unreadmessage->getMessageList ())
                {
                    if (Biz::MessageUtil::chargeIsAtNotice(spMessage))
                    {
                        if (Biz::MessageTypeSelf != spMessage->MsgDirection())
                        {
                            QString msgStr;
                            MessageParser::getInstance()->getShotTranslatedMessage(spMessage,msgStr);
                            showAtNotice(spMessage->Resource(),msgStr, spMessage->MessageID());
                        }
                    }
                }

				
                if (unreadmessage->getMessageList().size()>5)
                {
                    mpUpUnread->setAnchoragePoint(MessageUnreadTip::sKey);
                    mpUpUnread->setUpUnreadText(QStringLiteral("%1条新消息").arg(unreadmessage->getMessageList().size()-1));
                    //mpUpUnread->show();
                }
				Log::e(QString("GroupChatDialog::getMoreHistoryMsg groupjid=%1 unreadmsg dohandle after").arg(conversationId()));
            }

            disconnect(mCommObject, &ChatCommObject::sgHideNewMessageTip,this, &GroupChatDialog::onHideUnreadMsgPop);
            disconnect(mCommObject, &ChatCommObject::sgHideUpUnreadMessageTip,this,&GroupChatDialog::onHideUpUnreadMessageTip);
            connect(mCommObject, &ChatCommObject::sgHideNewMessageTip,this, &GroupChatDialog::onHideUnreadMsgPop);
            connect(mCommObject, &ChatCommObject::sgHideUpUnreadMessageTip,this,&GroupChatDialog::onHideUpUnreadMessageTip);
            Log::e("GroupChatDialog::get unread message callback" );
			
        }, []{ });
		quint64 getmsgendticked =  QDateTime::currentMSecsSinceEpoch();
		Log::e(QString("first GroupChatDialog::getMoreHistoryMsg getAllUnreadMessageList begin %1 groupjid=%2").arg(getmsgendticked).arg(conversationId()));
        Biz::Session::getMessageManager()->getAllUnreadMessageList(conversationId(),getAllUnreadMessageCallback);
    }
    else
	{
		quint64 getmsgendticked =  QDateTime::currentMSecsSinceEpoch();
		Log::e(QString("not first GroupChatDialog::getMoreHistoryMsg getmsg begin %1 groupjid=%2").arg(getmsgendticked).arg(conversationId()));
        Biz::Session::getMessageManager()->getGroupHistoryMessageList(conversationId(),count,timestamp,callback);
	}

}
void GroupChatDialog::onHistoryAppend( const QSharedPointer<Biz::MessageListData>& messageList )
{
    appendMessage(true, messageList->HasMore(), messageList->getMessageList(), 1);
}

void GroupChatDialog::onHistoryMore(quint64 tk, int height)
{
	
	quint64 getmsgendticked =  QDateTime::currentMSecsSinceEpoch();
	Log::e(QString("GroupChatDialog::onHistoryMore begin %1 conversationId=%2").arg(getmsgendticked).arg(conversationId()));

    if (0 == tk)
        tk = Constant::INT64_MAX_T;
    getMoreHistoryMsg(tk,GETHISTORYCOUNTLIMITED,NULL, true);
}


void GroupChatDialog::showExtendPanel(bool bforece)
{
    if (ui->externBtn->isVisible())
        return;

    if (bforece)
    {
        ui->externBtn->setStyleSheet(QString(extendButtonStyleTemplete)
            .arg(!ui->rightPanel->isVisible()?"url(:/Images/expend_tol_normal.png)":"url(:/Images/expend_tor_normal.png)")
            .arg(!ui->rightPanel->isVisible()?"url(:/Images/expend_tol_hover.png)":"url(:/Images/expend_tor_hover.png)")
            .arg(!ui->rightPanel->isVisible()?"url(:/Images/expend_tol_press.png)":"url(:/Images/expend_tor_press.png)")
            );

        ui->externBtn->setVisible(true);

    }
    else
    {
        QPoint gCurPos = QCursor::pos();// 全局的坐标
        QRect webviewRect = ui->webviewPanel->rect();
        webviewRect.setLeft(webviewRect.right()-20);// 20 = ui.extendbtn width
        if ( webviewRect.contains(ui->webviewPanel->mapFromGlobal(gCurPos)))
        {
            ui->externBtn->setVisible(true);
            ui->externBtn->setStyleSheet(QString(extendButtonStyleTemplete)
                .arg(!ui->rightPanel->isVisible()?"url(:/Images/expend_tol_normal.png)":"url(:/Images/expend_tor_normal.png)")
                .arg(!ui->rightPanel->isVisible()?"url(:/Images/expend_tol_hover.png)":"url(:/Images/expend_tor_hover.png)")
                .arg(!ui->rightPanel->isVisible()?"url(:/Images/expend_tol_press.png)":"url(:/Images/expend_tor_press.png)")
                );
        }
    }

}

void GroupChatDialog::hideEXtendPanel(bool force)
{
    if (force)
    {
        ui->externBtn->setVisible(false);
        ui->externBtn->setStyleSheet(QString(extendButtonStyleTemplete)
            .arg(!ui->rightPanel->isVisible()?"url(:/Images/expend_tol_normal.png)":"url(:/Images/expend_tor_normal.png)")
            .arg(!ui->rightPanel->isVisible()?"url(:/Images/expend_tol_hover.png)":"url(:/Images/expend_tor_hover.png)")
            .arg(!ui->rightPanel->isVisible()?"url(:/Images/expend_tol_press.png)":"url(:/Images/expend_tor_press.png)")
            );
        return;
    }
    QPoint gCurPos = QCursor::pos();// 全局的坐标
    QRect extendBtnRect = ui->externBtn->rect();
    do 
    {
        if (ui->externBtn->isVisible() && extendBtnRect.contains(ui->externBtn->mapFromGlobal(gCurPos)))
        {
            continue;
        }
        ui->externBtn->setVisible(false);
        ui->externBtn->setStyleSheet(QString(extendButtonStyleTemplete)
            .arg(!ui->rightPanel->isVisible()?"url(:/Images/expend_tol_normal.png)":"url(:/Images/expend_tor_normal.png)")
            .arg(!ui->rightPanel->isVisible()?"url(:/Images/expend_tol_hover.png)":"url(:/Images/expend_tor_hover.png)")
            .arg(!ui->rightPanel->isVisible()?"url(:/Images/expend_tol_press.png)":"url(:/Images/expend_tor_press.png)")
            );
    } while (false);
}


void GroupChatDialog::onRoomInvitePresenceReceived(const QString& jid, const QString& userJid,const QString& status)
{
    if(jid != conversationId()){
        return;
    }
    if (userJid.isEmpty())
        return;

    QString displayName = Biz::Session::currentAccount().getUserNameById(userJid);

    if( mGroupVisitorModel->getItemFromBareJid(userJid)  == NULL)
    {
        mGroupVisitorModel->createItem(Biz::MessageUtil::makeSureUserJid(userJid) ,
            QXmppMucItem::NoAffiliation, 
            displayName,
            Biz::Session::getUserVcardManager()->isUserOnline(Biz::MessageUtil::makeSureUserJid(userJid))?VisitorItem::ONLINE:VisitorItem::OFFLINE);

        Biz::Session::getUserVcardManager()->getDomainUsersVcardByVersionandImage(QStringList(Biz::MessageUtil::makeSureUserJid(userJid)));


    }

    VisitorItem* vi = mGroupVisitorModel->getItemFromBareJid(userJid);
    if( NULL!= vi )
    {
        vi->setPresence(status.compare("online",Qt::CaseInsensitive)==0?VisitorItem::ONLINE:VisitorItem::OFFLINE);
    }


    ui->addGroupItem->setEnabled(true);
    int count = mGroupVisitorModel->GetCountItem();
    int onlineCount = mGroupVisitorModel->getOnlineMemberCount();

    QString strText = QStringLiteral("群成员(%2/%1)").arg(count).arg(onlineCount);
    ui->groupListTitle->setText(strText);
}

void GroupChatDialog::onRoomLeaveOfMember(const QString& gjd, const QString& jid)
{
    if(!Biz::MessageUtil::compareJid(gjd,conversationId()) || Biz::MessageUtil::compareJid(jid,Biz::Session::getAccountManager()->accountData().UserID())){
        return;
    }
    QString userid = Biz::MessageUtil::makeSureUserJid(jid);

    if( mGroupVisitorModel->getItemFromBareJid(userid))
    {
        mGroupVisitorModel->removeItem(userid);
    }

    ui->addGroupItem->setEnabled(true);
    int count = mGroupVisitorModel->GetCountItem();
    int onlineCount = mGroupVisitorModel->getOnlineMemberCount();

    QString strText = QStringLiteral("群成员(%2/%1)").arg(count).arg(onlineCount);
    ui->groupListTitle->setText(strText);
}

void GroupChatDialog::onUpdateVoiceImage(const QString& messageid,const QString& img)
{
    mCommObject->updateVoiceImage(mPage, messageid, img);
}

void GroupChatDialog::onPopMenu(const QString& userjid)
{
    // 根据群号和resource找到userid
//     auto getUserIdSuccess   = [this,resource](const QString& userId){
//         if (userId.isEmpty())
//         {
//             Log::e(QString("get userid by groupid and resource empty %1 %2").arg(this->conversationId(),resource));
//             return;
//         }
// 		Biz::Session::getUserVcardManager()->getDomainUsersVcardByforce(QStringList(Biz::MessageUtil::makeSureUserJid(userId)));
// 
//         UserMiniProfile::getInstance()->setUserid(userId);
// 
//         UserMiniProfile::getInstance()->autoshow();
// 
//         //让图片换成最新的
//         SetChangeIcon(Biz::MessageUtil::makeSureUserJid(userId));
//     };
//     auto getUserIdFail      = [this]{
//         MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("获取用户该用户资料失败"));
//     };
//     auto getUseridByResourceCallback = mReceiver->createCallback<QString>(getUserIdSuccess,getUserIdFail);
//     Biz::Session::getAccountManager()->getUserIdByGroupResource(conversationId(),resource,getUseridByResourceCallback);

	Biz::Session::getUserVcardManager()->getDomainUsersVcardByforce(QStringList(Biz::MessageUtil::makeSureUserJid(userjid)));
	UserMiniProfile::getInstance()->setUserid(userjid);
	UserMiniProfile::getInstance()->autoshow();
	//让图片换成最新的
	SetChangeIcon(Biz::MessageUtil::makeSureUserJid(userjid));
}

void GroupChatDialog::showEvent(QShowEvent *)
{
	ui->textEdit->activateWindow();
	ui->textEdit->setFocus();

	QString NameText = ui->name->text();
	NameText = MainApp::getMaxLineCountLimitText(NameText, ui->name->width(), 1, ui->name->font());
	ui->name->setText(NameText);

	QString strText = ui->noticy->toolTip();
	
	int nwidthLay = ui->widget_5->width();
	int nwidthText = QFontMetrics(ui->noticy->font()).width(ui->noticy->toolTip());
	if (nwidthText > nwidthLay)
	{
		int nwidth = ui->noticy->width();
		ui->noticy->resize(nwidthLay, ui->noticy->height());
	}
	QString strlimit = MainApp::getMaxLineCountLimitText(strText, qMax(nwidthLay, nwidthText), 1, ui->noticy->font());
	ui->noticy->setText(strlimit);
	
	if (mPage && mCommObject)
	{
		onSetHistoryMsgCount(Biz::Session::getEditableSettings()->ChatHistoryMsgCount());
	}
	
// 	mloadhtmlTimeout = new QTimeLine(5000);
// 	connect(mloadhtmlTimeout,&QTimeLine::finished,[this]{
// 		mloadhtmlTimeout->stop();
// 
// 		onSetHistoryMsgCount(Biz::Session::getEditableSettings()->ChatHistoryMsgCount());
// 		getMoreHistoryMsg(-1, 5, true);
// 	});
// 	mloadhtmlTimeout->start();

	
}

void GroupChatDialog::updatePresence(const QString& userId, int status)
{

}
void GroupChatDialog::onUpdatePresence(const QStringList& onlineUsers)
{
    QMap<QString,VisitorItem*> memberMap = mGroupVisitorModel->GetGroupItemMap();
    for (QString memberid:memberMap.keys())
    {
        if (Biz::Session::getUserVcardManager()->isUserOnline(memberid))
        {
            if (VisitorItem::Status::ONLINE!=mGroupVisitorModel->getStatus(memberid))
            {
                mGroupVisitorModel->updatePresence(memberid,VisitorItem::ONLINE);
            }
        }
        else
        {
            if (VisitorItem::Status::OFFLINE!=mGroupVisitorModel->getStatus(memberid))
            {
                mGroupVisitorModel->updatePresence(memberid,VisitorItem::OFFLINE);
            }
        }
    }

    doUpdateGroupMemberCount();
}

void GroupChatDialog::wheelEvent(QWheelEvent *event)
{
    int numDegress = event->delta()/8;
    int numSteps = numDegress/15;
    if (event->orientation() == Qt::Vertical)
    {

        if (numDegress*8 < 0)
        {
            mGroupVisitorModel->wheelMove();
        }
    }
    event->accept();
}
void GroupChatDialog::getImageSize(int& w,int& h)
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


void GroupChatDialog::onRoomNameListReceived(const QStringList& groupJids)
{
	QString strConvsationId = conversationId();
    if (groupJids.contains (Biz::MessageUtil::makeSureGroupJid(conversationId ())))
    {
        Biz::GroupListData* pList = Biz::Session::getAccountManager ()->getGroupsData ();

        if (NULL!=pList )
        {
            Biz::GroupSetting* pSetting = pList->getGroupSetting(conversationId ());
            if (NULL!=pSetting)
            {
                QString groupName = pSetting->Name ();
                if (!groupName.isEmpty ())
                {
                    onSetTitle (conversationId (),groupName);
                }
            }
        }
    }
}

void GroupChatDialog::onRoomVcardChanged(const QString& groupJid)
{
	QString strgroupjid = conversationId();
    if (conversationId() == groupJid)
    {
        Biz::GroupListData* pGld = Biz::Session::currentAccount().getGroupsData();
        Biz::GroupSetting* pSetting = NULL;
        if (NULL!=pGld && NULL!= (pSetting=pGld->getGroupSetting(groupJid)) )
        {
			QString body = pSetting->Subjuct();
			// title
			ui->noticy->setText(body);
			ui->noticy->setToolTip(body);
			// webview 
            QString jsText = QString(T_("SubjectChange_Notify")).arg(QStringLiteral("系统提示"),"",body);
            mCommObject->systemnotify(mPage,jsText);
            mCommObject->scrollToEnd(mPage);
        }
    }
}

void GroupChatDialog::OnReloadOfflineMsg(const QString&groupid)
{
    if (conversationId() == groupid)
    {
		Log::e(QString("GroupChatDialog::OnReloadOfflineMsg conversationId=%1").arg(conversationId()));
		getMoreHistoryMsg(Constant::INT64_MAX_T, 10, true);
        refreshFileMessage ();
    }
}

void GroupChatDialog::onLoadHtmlFinish(bool b)
{
	quint64 getmsgendticked =  QDateTime::currentMSecsSinceEpoch();
	Log::e(QString("GroupChatDialog::onLoadHtmlFinish end %1 conversationId=%2").arg(getmsgendticked).arg(conversationId()));

	mbloaded = true;
	//获取历史记录
	onSetHistoryMsgCount(Biz::Session::getEditableSettings()->ChatHistoryMsgCount());
	mCommObject->jsSetloadStatus(mPage, 0);
	getMoreHistoryMsg(Constant::INT64_MAX_T, 5, true);
	//loadGroupMember();
}

void GroupChatDialog::onLoadHtmlFinishByReConn(bool b)
{
	onSetHistoryMsgCount(Biz::Session::getEditableSettings()->ChatHistoryMsgCount());
	Log::e(QString("GroupChatDialog::onLoadHtmlFinishByReConn conversationId=%2").arg(conversationId()));
	getMoreHistoryMsg(Constant::INT64_MAX_T, 10, true);

	loadGroupMember();


}

void GroupChatDialog::doMergeMessageCache(const QSharedPointer<Biz::MessageListData>& messageList)
{
    mGetHistoryMessageTimerout.stop();

    bWebLoaded = true;

    Log::e(QString("on groupchat history messages callback: historysize:%1;cathesize:%2,%3")
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
                if (spMsg->MessageID() == messgeItem->MessageID())
                {
                    bfinded = true;
                    break;
                }
            }
        }

        if (!bfinded)
        {
            onMessageReceived(spMsg);
            Log::e(QString("on groupchat history messages callback: messageonline merged %1 ").
                arg(spMsg->MessageID()));
        }
    }

	m_lstMsgCatch.clear();
	QString strconversation = conversationId();
	mCommObject->scrollToEnd(mPage);
	mCommObject->setScollPos(0, mPage);
	mCommObject->jsSetloadStatus(mPage, 1);
}

void GroupChatDialog::doUpdateGroupMemberCount()
{
    int count = mGroupVisitorModel->GetCountItem();
    int onlineCount = mGroupVisitorModel->getOnlineMemberCount();

    QString strText = QStringLiteral("群成员(%2/%1)").arg(count).arg(onlineCount);
    ui->groupListTitle->setText(strText);

    if (count <= Biz::Session::getEditableSettings()->GroupMailLimited())
    {
        disconnect(ui->sendmail,&QPushButton::clicked,this,&GroupChatDialog::onSendMailForbidden);
        disconnect(ui->sendmail,&QPushButton::clicked,this,&GroupChatDialog::onSendMail);
        connect(ui->sendmail,&QPushButton::clicked,this,&GroupChatDialog::onSendMail);
    }
    else
    {
        disconnect(ui->sendmail,&QPushButton::clicked,this,&GroupChatDialog::onSendMailForbidden);
        disconnect(ui->sendmail,&QPushButton::clicked,this,&GroupChatDialog::onSendMail);
        connect(ui->sendmail,&QPushButton::clicked,this,&GroupChatDialog::onSendMailForbidden);
    }
}

void GroupChatDialog::onClearContents(bool bret)
{
 	//disconnect(ui->webView, &webview::loadFinished, this,&GroupChatDialog::onLoadHtmlFinish);

	Log::e("in GroupChatDialog::onClearContents ");
	mCommObject->cleanHistroyRecordPage(mPage);
	Biz::Session::getAttachmentManager()->cleanImageAttachlistbyId(conversationId());

}

void GroupChatDialog::onEditCopy()
{
    ui->textEdit->copy();
}

void GroupChatDialog::onEditPast()
{
    //ui->textEdit->paste();
    emit ui->textEdit->sgPaste();
}

void GroupChatDialog::onEditSelectAll()
{
    ui->textEdit->selectAll();
}

void GroupChatDialog::onShowEditMenu( const QPoint&pt )
{
    if (mEditMenu == NULL)
    {
        mEditMenu = new QMenu(ui->textEdit);

        mActionEditSelectAll = new QAction(T_("GroupTextEditMenu_item_All"), ui->textEdit);
        connect(mActionEditSelectAll, &QAction::triggered, this, &GroupChatDialog::onEditSelectAll);
        mEditMenu->addAction(mActionEditSelectAll);

        mActionEditCopy = new QAction(T_("GroupTextEditMenu_item_copy"), ui->textEdit);
        connect(mActionEditCopy, &QAction::triggered, this, &GroupChatDialog::onEditCopy);
        mEditMenu->addAction(mActionEditCopy);

        mActionEditPast = new QAction(T_("GroupTextEditMenu_item_past"), ui->textEdit);
        connect(mActionEditPast, &QAction::triggered, this, &GroupChatDialog::onEditPast);
        mEditMenu->addAction(mActionEditPast);
    }

    if( ui->textEdit->toPlainText().length() > 0 || (ui->textEdit->toPlainText().length() == 0 && !getSelectImagePath().isEmpty()) )
    {

        mActionEditCopy->setEnabled(true);
        mActionEditSelectAll->setEnabled(true);

    }else{
        mActionEditCopy->setEnabled(false);
        mActionEditSelectAll->setEnabled(false);
    }



    mEditMenu->exec(QCursor::pos());
}



void GroupChatDialog::onSendMailForbidden(bool)
{
    MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("诶呀，功能被禁止了"));
}

void GroupChatDialog::onSendMail(bool)
{
    QList<VisitorItem*> items = mGroupVisitorModel->GetGroupItemMap().values();

    QStringList ids;
    for (VisitorItem* item:items)
    {
        if (NULL!=item && !item->emailAddress().isEmpty())
        {
            ids.push_back(item->emailAddress());
        }
    }
    QString splitchar = Biz::Session::getSettingConfig()->MailSplite()==Biz::MSC_SEMICOLON?";":",";
    QString mailTos = ids.join(splitchar);
    QDesktopServices bs;        
    bs.openUrl(QUrl(QString("mailto:%1").arg(mailTos)));
}

void GroupChatDialog::onRosterPortraitUpdate(const QString& jid)
{
    //关键是群组中，还需要给html页面中聊天消息进行换个人的icon
	//在这地方加一个判断，看看这个jid是否是这个群成员
	QStringList memberlist = mGroupVisitorModel->GetGroupItemMap().keys();
	if (!memberlist.contains(jid))
	{
		return;
	}

    SetChangeIcon(jid);

    Log::e(QString("onRosterPortraitUpdate groupjid=%1 updateuserid=%2").arg(conversationId()).arg(jid));
    mGroupVisitorModel->updateData(jid);
}

void GroupChatDialog::onRefreshGroupMember()
{
	if (conversationId().isEmpty())
	{
		return;
	}

	auto callback = mReceiver->createCallback<QList<QSharedPointer<Biz::GroupMemberModule>>>([this](const QList<QSharedPointer<Biz::GroupMemberModule>>& list){

		onGroupMemberListReceived(this->conversationId(),list);
		
	},[this]{
	});

	Biz::Session::getGroupManager()->getGroupMemberbyInfor(this->conversationId(),callback);


}

void GroupChatDialog::onRosterCardChangeUpdate(const QStringList& userinforlist)
{
    for (QString userjid: userinforlist)
    {
        QSharedPointer<Biz::ImSelfPerson> person = Biz::Session::getUserVcardManager()->userVcard(userjid);
        if (!person.isNull())
        {
            QString userId = Biz::MessageUtil::makeSureUserJid(person->strUserId);
            QString displayname = person->displayName();
            mGroupVisitorModel->updateDisplayName(userId,displayname);
            mGroupVisitorModel->updateData(userId);

            mCommObject->jsChangeGroupMemberName(mPage, userId, displayname);
        }
    }
}

void GroupChatDialog::SetFontSize( int nsize )
{
    if (nsize < 14)
    {
        nsize = 14;
    }
    else if (nsize >20 )
    {
        nsize = 20;
    }

    mGroupVisitorModel->setItemFontSize(nsize);
    ui->groupListTitle->setStyleSheet(QString("font-size:%1px;").arg(nsize));
    ui->name->setStyleSheet(QString("font-size:%1px;").arg(nsize));
    ui->noticy->setStyleSheet(QString("font-size:%1px;").arg(nsize));
}

void GroupChatDialog::InitFontSize()
{
    int fontSize = Biz::Session::getSettingConfig()->MFontSize();

    SetFontSize(fontSize);
}

void GroupChatDialog::onpbAdvertInfo()
{
    AdvertInfoDialog *pAdvertInfo = AdvertInfoDialog::instance();
    if (pAdvertInfo)
    {
        pAdvertInfo->setJid(conversationId());
        pAdvertInfo->showAdvertInfoDlg();
    }
}

void GroupChatDialog::doShowProductInfo( const QString&userid, const QSharedPointer<Biz::XmppMessage>&msg )
{
    if(!Biz::MessageUtil::compareJid(userid,conversationId()))
        return;

    appendMessage(false, false, msg);
}

void GroupChatDialog::onGloableFontSizeChanged( int size )
{
    SetFontSize(size);
}


QString GroupChatDialog::makeBackupInfo(const QString& body)
{

    QJsonArray jsonArr;

    // @信息的backupinfo

    if (body.contains("@"))
    {
        QJsonArray atArr;
        QMap<QString,VisitorItem*> members = mGroupVisitorModel->GetGroupItemMap();
        for (QString key:members.keys())
        {
            VisitorItem* amember = members.value(key);
            if (NULL!=amember && !amember->nickName().isEmpty())
            {
                QString nickName = amember->nickName();
                if (body.contains("@"+nickName,Qt::CaseInsensitive))
                {
                    QJsonObject atNode;
                    atNode.insert("jid",key);
                    atNode.insert("text",nickName);
                    atArr.append(atNode);
                }
            }
        }

        if (body.contains("@all",Qt::CaseInsensitive))
        {
            QJsonObject atNode;
            atNode.insert("jid",QString("all"));
            atNode.insert("text",QString("all"));
            atArr.append(atNode);
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

/*void GroupChatDialog::dochangeBodyAtInofr( const QSharedPointer<Biz::XmppMessage>& msg )
{
	if (msg->MediaType() == Biz::MessageTypeAt)
	{
		QString backupInfor = msg->BackupInfo();
		QString body = msg->Body();
		QMap <QString, QString> jidtext;

		//backupinfor 解析出来
		QJsonDocument doc = QJsonDocument::fromJson (backupInfor.toUtf8 ());
		QVariantList vl = doc.toVariant ().toList ();
		for (QVariant vv:vl)
		{
			QVariantMap vm = vv.toMap ();

			QVariantList data = vm["data"].toList();

			for (QVariant datav: data)
			{
				QVariantMap datamap = datav.toMap();
				jidtext.insert(datamap["jid"].toString(), datamap["text"].toString());
			}
		}

		//列表中该用户的值
		QMap<QString,VisitorItem*> groupMembers = mGroupVisitorModel->GetGroupItemMap();
		for (VisitorItem* pitem:groupMembers.values())
		{
			QString userid = Biz::MessageUtil::makeSureUserJid(pitem->MemberJid());
			if (jidtext.contains(userid))
			{
				QString displayname =  Biz::Session::currentAccount().getUserNameById(userid);
				body.replace(jidtext.value(userid),displayname);
			}
			
		}
	}
}*/

void GroupChatDialog::onUpdateGroupHeader(const QString& groujid)
{
    QString strtmp = conversationId();
    if (groujid == conversationId())
    {
        QPixmap pixmap = Biz::PortraitHelper::getGroupPortraitWithNoticeFlag(conversationId());
        pixmap = QPixmap::fromImage(pixmap.toImage().scaled(ui->headerimage->size()));
        ui->headerimage->setPixmap(pixmap);
    }
}

void GroupChatDialog::onMemberProfile()
{
    QModelIndexList list =  ui->listView->selectionModel()->selectedIndexes();

    if (list.size()>0)
    {
        QModelIndex index = list.at(0);

        QString SelectUserId = index.data(VisitorItem::UserJid).toString();
        Biz::Session::getUserVcardManager()->getDomainUsersVcardByforce(QStringList(Biz::MessageUtil::makeSureUserJid(SelectUserId)));
        UserMiniProfile::getInstance()->setUserid(SelectUserId);
        UserMiniProfile::getInstance()->autoshow();
    }
}




void GroupChatDialog::onSelectAndSendFile(const QString& strAbsFilePath)
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

void GroupChatDialog::SetChangeIcon( const QString& jid )
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

void GroupChatDialog::paintEvent( QPaintEvent *event )
{
	QPainter painter(this);
	QRect rect = ui->name->geometry();
	
	int nwidth = ui->headerimage->size().width() + ui->horizontalLayout_8->spacing();
	QPoint mbeginpt = QPoint(rect.bottomLeft().x() + nwidth, rect.bottomRight().y());
	QPoint mendpt = QPoint(rect.bottomRight().x() + 7 + nwidth , rect.bottomRight().y());
	QPen pen(QColor(0, 0, 0));

    painter.setPen(pen);
    if (mbhover)
    {
        painter.drawLine(mbeginpt, mendpt);
    }

    BaseChatDialog::paintEvent(event);
}

void GroupChatDialog::refreshFileMessage()
{
    auto getFilesSuccess    = [this](const QSharedPointer<Biz::MessageListData>& messagelist){

        QLayoutItem *item = NULL;
		//这地方涉及到的callback回调的机制，暂时这样改一下
		if (ui == NULL)
		{
			return;
		}
        QLayout* layout = ui->groupfilelayout;
        while((item = layout->takeAt(0))) {
            if (item->widget()) {
                delete item->widget();
            }
            delete item;
        }

        for (int i=0;i<qMin(3,messagelist->getMessageList ().size ());i++)
        {
            QSharedPointer<Biz::XmppMessage> spMessage = messagelist->getMessageList ().at (i);
            GroupFileView* pFileView = new GroupFileView(ui->groupfilepanel);
            pFileView->setMessage (spMessage);
            ui->groupfilelayout->addWidget(pFileView);
        }

         QSpacerItem* verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
        ui->groupfilelayout->addItem(verticalSpacer);
        
        if (messagelist->getMessageList ().size ()>0)
            ui->groupfilestackview->setCurrentWidget(ui->listpage);
        else
            ui->groupfilestackview->setCurrentWidget(ui->emptypage);
        
    };
    auto getFilesFail       = []{};
    Biz::UnitCallback<QSharedPointer<Biz::MessageListData>>* uicb = 
        mReceiver->createCallback<QSharedPointer<Biz::MessageListData>> (getFilesSuccess,getFilesFail);
    Biz::Session::getMessageManager ()->getAllFileMessage (conversationId (),uicb);
}

void GroupChatDialog::messageSendPrepare(const QSharedPointer<Biz::XmppMessage>& spMessage)
{
     Biz::Session::getConverSationManager()->setGroupConversationMessageRead(conversationId());
    spMessage->SenderJid(Biz::MessageUtil::makeSureUserJid(Biz::Session::currentAccount().accountData().UserID()));
    spMessage->MsgSourceType(Biz::GroupMessage);

    spMessage->BackupInfo(makeBackupInfo(spMessage->Body ()));

	setMsgMediaTypeByAt(spMessage);
}
void GroupChatDialog::setMsgMediaTypeByAt(const QSharedPointer<Biz::XmppMessage>& spMessage)
{
	QString body = spMessage->Body ();
	if (body.contains("@"))
	{
		QJsonArray atArr;
		QMap<QString,VisitorItem*> members = mGroupVisitorModel->GetGroupItemMap();
		for (QString key:members.keys())
		{
			VisitorItem* amember = members.value(key);
			if (NULL!=amember && !amember->nickName().isEmpty())
			{
				QString nickName = amember->nickName();
				if (body.contains("@"+nickName,Qt::CaseInsensitive))
				{
					spMessage->MediaType(Biz::MessageTypeAt);
				}
			}
		}

		if (body.contains("@all",Qt::CaseInsensitive))
		{
			spMessage->MediaType(Biz::MessageTypeAt);
		}
	}
}
void GroupChatDialog::onVidioandAudioGroupChat()
{
	//弹出一个框子，输入会议的名称
	VideoRoomDialog *dlg = VideoRoomDialogSingleton::getInstance();
	if (dlg)
	{
		
		dlg->ShowDlg();
		if (dlg->exec() == 1)
		{
			auto getaddrSuccess = [this, dlg](const QString& resultMsg)
			{

				QJsonDocument doc = QJsonDocument::fromJson(resultMsg.toUtf8());
				QVariantMap root = doc.toVariant().toMap();

				if (root.contains("errcode"))
				{
					int nError = root.value("errcode").toInt();
					if (0 == nError)
					{
						if (root.contains("data"))
						{
							QVariantMap dataMap = root.value("data").toMap();
							QString pcstr = dataMap["server"].toString();
							QString otherstr =  dataMap["navServ"].toString();
							Log::e(QString(" onVidioandAudioGroupChat paras param pcStr=%1").arg(pcstr));
							QUrl url(pcstr);
							if (pcstr.isEmpty() /*|| (url.scheme().compare("https", Qt::CaseInsensitive) != 0)*/)
							{
								Log::e(QStringLiteral(" onVidioandAudioGroupChat pcstr.isEmpty() || no https"));
								MainApp::UIFrame::getNotifyCenterController()->alertMessage(QStringLiteral("获取聊天视频地址失败"));
								return;
							}

							QString strName = dlg->getRoomName();
							//点击确定后，发送消息出去
							//创建一个json串
							QString uuid = QUuid::createUuid().toString().replace("{", "").replace("}", "").replace("-", "");
							quint64 starttm = QDateTime::currentDateTime().toMSecsSinceEpoch() - Biz::Session::currentAccount().getTimeOffsetFromServer();
							quint64 createtm = starttm;

							QJsonObject obj;
							obj.insert("roomName", uuid);
							obj.insert("topic", strName);
							obj.insert("startTime", (qint64)starttm);
							obj.insert("createTime", (qint64)createtm);
							obj.insert("creator", Biz::Session::getAccountManager()->accountData().UserID());
							obj.insert("server", pcstr);
							obj.insert("navServ", otherstr);
							QString json = QJsonDocument(obj).toJson(QJsonDocument::Compact);
							SendGroupRoomVideoMessage(json, conversationId());
							Log::e(QString("pcStr=%1").arg(pcstr));
							//然后打开窗口
							VidioAndAudioDialog *videodlg = MainApp::UIFrame::getConversationController()->getVidioChatById(/*conversationId()*/uuid);
							if (videodlg)
							{
								videodlg->setRoomTitle(strName);
								videodlg->setUrl(pcstr);
								videodlg->setWindowsDefaultSize();
								videodlg->setRoomVideoParam(uuid, strName, starttm);

								videodlg->onShowDlg(conversationId());

								connect(videodlg, &VidioAndAudioDialog::sgLoadFinished, [this, videodlg, pcstr](const QString& id){
									Log::e(QString(" onVidioandAudioGroupChat logdFinished pcStr=%1").arg(pcstr));
									if (conversationId() == id)
									{
										Log::e(QString("onVidioandAudioGroupChat logdFinished pcStr=%1").arg(pcstr));
										videodlg->setStartVideoRoom(conversationId());
									}

								});

							}
						}
						else
						{
							Log::e(QString("onVidioandAudioGroupChat param return data fail"));
							MainApp::UIFrame::getNotifyCenterController()->alertMessage(QStringLiteral("获取聊天视频地址失败"));
							return;
						}
					}
					else
					{
						Log::e(QString("onVidioandAudioGroupChat nerrorcode=%1").arg(nError));
						MainApp::UIFrame::getNotifyCenterController()->alertMessage(QStringLiteral("获取聊天视频地址失败"));
						return;
					}
				}
				else
				{
					Log::e(QString("onVidioandAudioGroupChat return false"));
					MainApp::UIFrame::getNotifyCenterController()->alertMessage(QStringLiteral("获取聊天视频地址失败"));
					return;
				}

				

			};
			auto getaddrfail = [this]{
				Log::e(QString(" onVidioandAudioGroupChat callback  fails"));
				MainApp::UIFrame::getNotifyCenterController()->alertMessage(QStringLiteral("获取聊天视频地址失败"));
				return;
			};
			auto addrcallback =
				mReceiver->createCallback<QString>(getaddrSuccess, getaddrfail);
			Biz::Session::getGroupManager()->getGroupVideoRoomAddr(addrcallback);

		}
	}
}

void GroupChatDialog::ongotoVideoRoom(const QString& id)
{
	//更具id查找externInfo中的内容
	auto getmsgSuccess = [this](const QSharedPointer<Biz::XmppMessage>& message){

		if (!message.isNull())
		{
			QString spExternInfo = message->ExtendInfo();
			if (!spExternInfo.isEmpty())
			{
				Biz::GroupRoomVideoDetail roomdetail;
				roomdetail.unserializeFromString(spExternInfo);

				QString struuid = roomdetail.roomName();
				QString strName = roomdetail.topic();
				quint64 nStarttm = roomdetail.startTime();
				QString strAddr = roomdetail.server();
				//然后打开窗口
				VidioAndAudioDialog *videodlg = MainApp::UIFrame::getConversationController()->getVidioChatById(/*conversationId()*/struuid);
				if (videodlg)
				{
					videodlg->setRoomTitle(strName);
					videodlg->setUrl(strAddr);
					videodlg->setWindowsDefaultSize();
					videodlg->setRoomVideoParam(struuid, strName, nStarttm);
					videodlg->onShowDlg(conversationId());

					connect(videodlg, &VidioAndAudioDialog::sgLoadFinished, [this, videodlg](const QString& id){
						if (conversationId() == id)
						{
							videodlg->setStartVideoRoom(conversationId());
						}

					});


				}
				else
				{
					MainApp::UIFrame::getNotifyCenterController()->alertMessage(QStringLiteral("进入会议室失败"));
					return;
				}

			}
		}
		else
		{
			MainApp::UIFrame::getNotifyCenterController()->alertMessage(QStringLiteral("进入会议室失败"));
			return;
		}

	};
	auto getmsgfail = [this]{
		MainApp::UIFrame::getNotifyCenterController()->alertMessage(QStringLiteral("进入会议室失败"));
		return;
	};
	auto uicb =
		mReceiver->createCallback<QSharedPointer<Biz::XmppMessage>>(getmsgSuccess, getmsgfail);
	Biz::Session::getMessageManager()->getMessageById(id, uicb);
}

void GroupChatDialog::onReturnfirstMsgid( const QString&msgatid, const QString&msgid, const QString& conversationid )
{
	if ( (conversationId() != conversationid ) || msgatid.isEmpty() || msgid.isEmpty())
	{
		return;
	}

	auto getAllUnreadMessageCallback = mReceiver->createCallback<QSharedPointer<Biz::MessageListData>>([msgatid, this](const QSharedPointer<Biz::MessageListData>& messagelist )
	{
		onHistoryAppend(messagelist);

		//然后在find
		mCommObject->jsMsgFindMao(mPage, msgatid);
	}, []{ });
	
	Biz::Session::getMessageManager()->getMessageByBetweenId(conversationId(),msgatid, msgid ,getAllUnreadMessageCallback);
}

void GroupChatDialog::timerEvent( QTimerEvent * timeevent)
{
	
}

void GroupChatDialog::afterSendCode()
{
	ui->toolbar->setCodeHightLight(false);
}

void GroupChatDialog::loadGroupMember()
{
	auto callback = mReceiver->createCallback<QList<QSharedPointer<Biz::GroupMemberModule>>>([this](const QList<QSharedPointer<Biz::GroupMemberModule>>& list){

		quint64 getgroupmemberlist = QDateTime::currentMSecsSinceEpoch();
		Log::e(QString("GroupChatDialog::loadGroupMember begin %1 groupjid=%2").arg(getgroupmemberlist).arg(conversationId()));
		onGroupMemberListReceived(this->conversationId(),list);
		getgroupmemberlist = QDateTime::currentMSecsSinceEpoch();
		Log::e(QString("GroupChatDialog::loadGroupMember end %1 groupjid=%2").arg(getgroupmemberlist).arg(conversationId()));
	},[this]{
		Log::e(QString("GroupChatDialog::loadGroupMember is fail groupjid=%2").arg(conversationId()));
	});

	Biz::Session::getGroupManager()->getGroupMember(this->conversationId(),callback);
}

void GroupChatDialog::onGroupFilterMsg()
{
	GroupMsgFilterViewSingleton::getInstance ()->setGroupId(Biz::MessageUtil::makeSureGroupJid(conversationId()));

	GroupMsgFilterViewSingleton::getInstance ()->showInfo();
	GroupMsgFilterViewSingleton::getInstance ()->show ();
	GroupMsgFilterViewSingleton::getInstance ()->activateWindow ();
}

void GroupChatDialog::onGroupChatMsgFilter( const QString&conversationid, const QStringList&ids )
{

	if (conversationid.isEmpty()|| conversationId().isEmpty() || conversationid != conversationId())
		return;

	if (ids.size() <=0)
	{
		return;
	}


	auto callback = mReceiver->createCallback<QSharedPointer<Biz::MessageListData>>([this](const QSharedPointer<Biz::MessageListData>& messageList )
	{

		
		//先清单原来的数据，然后展示新的数据
		
		onClearContents();
		

		onHistoryAppend(messageList);
		

	}, []{ });

	Biz::Session::getGroupManager()->getGroupFilterHistoryMessageList(conversationId(),ids,60,callback);
	
}


void GroupChatDialog::onGroupChatMsgAtFilter( const QString&conversationid, const QStringList&ids )
{
	if (conversationId().isEmpty() || conversationid != conversationId())
		return;
	if (ids.size() <=0)
	{
		return;
	}
	QStringList msgids;
	for (QString userjid: ids)
	{
		msgids += MainApp::UIFrame::getConversationController()->getMsgIdFromAtInfor(conversationid,userjid);
	}


	auto callback = mReceiver->createCallback<QSharedPointer<Biz::MessageListData>>([this](const QSharedPointer<Biz::MessageListData>& messageList )
	{


		//先清单原来的数据，然后展示新的数据

		onClearContents();


		onHistoryAppend(messageList);


	}, []{ });

	Biz::Session::getGroupManager()->getGroupAtFilterHistoryMessageList(conversationId(),msgids,callback);


}

void GroupChatDialog::resizeEvent( QResizeEvent *event )
{
// 	QString NameText = ui->name->text();
// 	NameText = MainApp::getMaxLineCountLimitText(NameText, ui->name->width(), 1, ui->name->font());
// 	ui->name->setText(NameText);
// 
// 	QString strText = ui->noticy->toolTip();
// 	QString strlimit = MainApp::getMaxLineCountLimitText(strText, ui->noticy->width(), 1, ui->noticy->font());
// 	ui->noticy->setText(strlimit);

	int nnoticy = ui->noticy->width();
	int nwidget5 = ui->widget_5->width();
	ui->noticy->setLineWidth(ui->widget_5->width());
	ui->noticy->resize(nwidget5, ui->noticy->height());
	int afterwidth = ui->noticy->width();

	QString strText = ui->noticy->toolTip();
	QString strlimit = MainApp::getMaxLineCountLimitText(strText, ui->noticy->width(), 1, ui->noticy->font());
	ui->noticy->setText(strlimit);

	if (noticeType == GlobalOfTop)
	{
		if (NULL != m_noticeInfotipGlobal && m_noticeInfotipGlobal->isVisible())
		{
			int top;
			if (noticeType == GlobalOfTop)
			{
				top = ui->chatbar->height();

			}


			int w = ui->webView->width();
			m_noticeInfotipGlobal->setGeometry(QRect(0,top,w,35));
			m_noticeInfotipGlobal->setFixedWidth(w);
			m_noticeInfotipGlobal->move(0,top);
		}
	}
	

	BaseChatDialog::resizeEvent(event);

}

void GroupChatDialog::onShowNotifyInfor( const QList <QSharedPointer<Biz::NoticeStrInfor>>& list, int type )
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
			int top = ui->chatbar->height();


			int w = ui->webView->width();
			m_noticeInfotipGlobal->setGeometry(QRect(0,top,w,35));
			m_noticeInfotipGlobal->setFixedWidth(w);
			m_noticeInfotipGlobal->showTip();
		}
	}

}

