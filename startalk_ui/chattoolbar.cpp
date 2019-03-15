#include "chattoolbar.h"
#include <QFileDialog>

#include "ChatDisplayOptionWidget.h"
#include "EmotionTabDialog.h"

#include "Session.h"
#include "Account.h"
#include "AccountData.h"
#include "accountmanager.h"
#include "SettingData.h"
#include "diywidgit/printscreen/SnipScreenTool.h"
#include "gloableeventobject.h"
#include "ConfigureHelper.h"
#include "Quickreplymsgdialog.h"
#include "Transferchatdialog.h"
#include "UIFrame.h"
#include "ConversationController.h"
#include "Historyrecorddialog.h"
#include "Ordermanagedialog.h"

#include "QRCodeWidget.h"
#include "jsonobject/CheckConfigInfo.h"

#include "SystemDefine.h"
#include "WebService.h"

#include "TransferSessionDlg.h"

#include "LoginController.h"
#include "Framework.h"

#include "DAOLogic.h"

ChatToolBar::ChatToolBar(QWidget *parent)
    : QWidget(parent)
	, mAudioaction(NULL)
	, mVidioaction(NULL)
	, mVidioAndAudio(NULL)
	, showMask(0)
{
    ui.setupUi(this);

    connect(ui.btnFont, &QPushButton::clicked, this, &ChatToolBar::onFontClicked);
    connect(ui.btnEmotion, &QPushButton::clicked, this, &ChatToolBar::onEmotionClicked);
    connect(ui.btnJietu,&QPushButton::clicked, this, &ChatToolBar::onJietuClicked);
    connect(ui.btnJietusetting,&QPushButton::clicked, this, &ChatToolBar::onBtnJietuSetting);
    connect(ui.btnSendPic,&QPushButton::clicked, this, &ChatToolBar::onSendFileClicked);

    ui.btnSendVoice->setIcon(QIcon(QPixmap(":/Images/voice.png")));
    ui.btnSendVoice->setIconSize(QSize(20, 20));
    ui.btnSendVoice->setVisible(false);
   


    connect(ui.btnQuickReply,&QPushButton::clicked, this, &ChatToolBar::onQuickReplyMsg);
    ui.btnQuickReply->setToolTip(QStringLiteral("快捷回复语"));

    connect(ui.btnTransfer, &QPushButton::clicked, this, &ChatToolBar::onTransferChat);
    ui.btnTransfer->setToolTip(QStringLiteral("转移会话"));

    connect(ui.btnShake,&QPushButton::clicked,this,&ChatToolBar::onShakeClicked);

    connect(ui.btnRCode,&QPushButton::clicked,this,&ChatToolBar::onScanRcode);


    connect(ui.historyRecord, &QPushButton::clicked, this, &ChatToolBar::onHistoryRecord);
    connect(ui.historyRecordWeb, &QPushButton::clicked, this, &ChatToolBar::onHistoryRecordWeb);

    connect(ui.btnShare, &QPushButton::clicked,[this]{ emit sgShareMessage();});
	connect(ui.btnRobot, &QPushButton::clicked,[this]{ emit sgOpenRobot();});
	connect(ui.btnCloseSession, &QPushButton::clicked,[this]{ emit sgCloseSessionBtnClicked();});
	ui.historyRecord->setVisible(false);


     ui.btnToolbarMore->setVisible(false);


    mTransferChatMenu   = NULL;
    mTransferNum        = NULL;
    mTransferRelation   = NULL;
    mTransferCollega    = NULL;

    mJietusetting       = NULL;
    mHideMainwidge      = NULL;
    mMakeQtalkJietu     = NULL;
    mGnome_ScreenShot   = NULL;

	//对于音视频按钮的弹出式菜单的初始化
	mVidioAndAudio = new QMenu(ui.vidioandaudio);
	
	mAudioaction = mVidioAndAudio->addAction(QIcon(":/Images/icon/audio.png"), QStringLiteral("实时音频(beta)"));
	connect(mAudioaction, &QAction::triggered, this, &ChatToolBar::onAudioAction);
	mVidioaction = mVidioAndAudio->addAction(QIcon(":/Images/icon/vidio.png"), QStringLiteral("实时视频(beta)"));
	connect(mVidioaction, &QAction::triggered, this, &ChatToolBar::onVidioAction);
	ui.vidioandaudio->setMenu(mVidioAndAudio);

	initCodeControl();

	
}

ChatToolBar::~ChatToolBar()
{

}


void ChatToolBar::setBtnEenable(int nMask)
{
	this->showMask = nMask;
	ui.btnQuickReply->setVisible( ((nMask&BTN_QUICK) == BTN_QUICK));
	ui.btnTransfer->setVisible( ((nMask&BTN_TRANS)==BTN_TRANS));
	ui.btnShake->setVisible(((nMask&BTN_SHOCK)==BTN_SHOCK));
	ui.historyRecord->setVisible(((nMask&BTN_HISTORYLOCAL)==BTN_HISTORYLOCAL));
	ui.historyRecordWeb->setVisible(((nMask&BTN_HISTORY)==BTN_HISTORY));
	ui.btnRCode->setVisible(((nMask&BTN_RCODE)==BTN_RCODE));
	ui.vidioandaudio->setVisible(((nMask&BTN_VIDIOAUD) == BTN_VIDIOAUD));
	ui.btnRobot->setVisible(((nMask&BTN_ROBOT) == BTN_ROBOT)) ;
	ui.btnCloseSession->setVisible(((nMask&BTN_CLOSESESSION) == BTN_CLOSESESSION)) ;


	bool  sendcode = (nMask & BTN_CODE) == BTN_CODE;
	ui.code_checkBox->setVisible(sendcode);
	ui.codeStyle_comboBox->setVisible(sendcode);
	ui.codetype_comboBox->setVisible(sendcode);

	if (!MainApp::UIFrame::getConversationController()->IsAccountInAskIds(Biz::MessageUtil::makeSureUserId(Biz::Session::currentAccount().accountData().UserID())))
	{
		ui.btnRobot->setVisible(false);
	}
	ui.btnPingFen->setVisible(false);
}


int ChatToolBar::getBtnEnableMask()
{
	return showMask;
}


void ChatToolBar::setConversationId(const QString& conversationId)
{
    mConversationId = conversationId;
    addFunctionBtns();
}


void ChatToolBar::onFontClicked(bool)
{
    ChatDisplayOptionWidget* pOptionWidget = ChatDisplayOptionWidgetSingleton::getInstance();
    QPoint editPos = mapToGlobal(ui.btnFont->pos());
    int nWidth = pOptionWidget->geometry().width();
    int nHeight = pOptionWidget->geometry().height();
    int x = editPos.rx() - nWidth/2;
    int y = editPos.ry() - ui.btnFont->height()-nHeight;
    pOptionWidget->move(editPos.rx() - nWidth/2, editPos.ry() -nHeight);
    pOptionWidget->reShow();
}


void ChatToolBar::onEmotionClicked(bool)
{
    EmotionTabDialog *mEmotionDlg = EmotionTabDialogSingleton::getInstance();
    if(mEmotionDlg)
    {
        QPoint editPos = mapToGlobal(ui.btnEmotion->pos());
        int nWidth = mEmotionDlg->geometry().width();
        int nHeight = mEmotionDlg->geometry().height();
        int x = editPos.rx() - nWidth/2;
        int y = editPos.ry() - ui.btnEmotion->height()-nHeight;
        mEmotionDlg->move(editPos.rx() - nWidth/2, editPos.ry() -nHeight);
        if(!mEmotionDlg->isVisible())
        {
            mEmotionDlg->setConversionId(mConversationId);
            mEmotionDlg->autoshow();
        }
        else
        {
            mEmotionDlg->hide();
        }
    }
}

void ChatToolBar::onJietuClicked(bool)
{

    Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
    if (settingconfig->SetJietu())
    {
        emit GloableEventObject::getInstance()->sgHideMainWidge();
    }
#ifdef _WINDOWS
    SnipScreenTool::getInstance()->Init().Start();
    SnipScreenTool::getInstance()->setConversionId(mConversationId);
#else
    if (settingconfig->SetOSLinuxJietu())
    {
        if (settingconfig->SetJietu())
        {
            emit GloableEventObject::getInstance()->sgHideMainWidge();
        }
        SnipScreenTool::getInstance()->Init().Start();
        SnipScreenTool::getInstance()->setConversionId(mConversationId);
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

void ChatToolBar::onBtnJietuSetting()
{
    if (mJietusetting)
    {
        delete mJietusetting;
        mJietusetting = NULL;
    }
    if (mHideMainwidge)
    {
        delete mHideMainwidge;
        mHideMainwidge = NULL;
    }

    if (mMakeQtalkJietu)
    {
        delete mMakeQtalkJietu;
        mMakeQtalkJietu = NULL;
    }

    if (mGnome_ScreenShot)
    {
        delete mGnome_ScreenShot;
        mGnome_ScreenShot = NULL;
    }
    Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();

    mJietusetting = new QMenu(ui.btnJietusetting);

    mHideMainwidge = new QAction(QStringLiteral("截图时隐藏会话窗口"), ui.btnJietusetting);
    mHideMainwidge->setCheckable(true);


    mHideMainwidge->setChecked(settingconfig->SetJietu());
    connect(mHideMainwidge, &QAction::toggled, this, &ChatToolBar::onHideMainWidgetoggled);
    mJietusetting->addAction(mHideMainwidge);
#ifndef _WINDOWS
    mJietusetting->addSeparator();
    mMakeQtalkJietu = new QAction(QStringLiteral("Qtalk截图"), ui.btnJietusetting);
    mMakeQtalkJietu->setCheckable(true);

    mMakeQtalkJietu->setChecked(settingconfig->SetOSLinuxJietu());
    connect(mMakeQtalkJietu, &QAction::toggled, this, &ChatToolBar::onMakeQutalkJietutoggled);
    mJietusetting->addAction(mMakeQtalkJietu);



    mGnome_ScreenShot = new QAction(QStringLiteral("Gnome-Screen截图"), ui.btnJietusetting);
    mGnome_ScreenShot->setCheckable(true);

    mGnome_ScreenShot->setChecked(settingconfig->SetOSLinux3dJietu());
    connect(mGnome_ScreenShot, &QAction::toggled, this, &ChatToolBar::onGnomeScreenJietutoggled);
    mJietusetting->addAction(mGnome_ScreenShot);
#endif

    mJietusetting->exec(QCursor::pos());
}

void ChatToolBar::onHideMainWidgetoggled( bool bchecked )
{
    mHideMainwidge->setCheckable(bchecked);
    Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
    settingconfig->SetJietu(mHideMainwidge->isCheckable());
    Biz::Session::saveSettingConfig();
    onJietuClicked(true);
}

void ChatToolBar::onMakeQutalkJietutoggled( bool bchecked )
{
    Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();

	bool bret = settingconfig->SetOSLinuxJietu();
	if (!bret)
	{
		mGnome_ScreenShot->setChecked(!bret);
		settingconfig->SetOSLinuxJietu(!bret);

		//mMakeQtalkJietu->setChecked(bret);
		settingconfig->SetOSLinux3dJietu(bret);
		Biz::Session::saveSettingConfig();
	}
}

void ChatToolBar::onGnomeScreenJietutoggled( bool bchecked )
{
    Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();


	bool bret = settingconfig->SetOSLinux3dJietu();
	if (!bret)
	{
		mMakeQtalkJietu->setChecked(!bret);
		settingconfig->SetOSLinux3dJietu(!bret);

		//mGnome_ScreenShot->setChecked(bret);
		settingconfig->SetOSLinuxJietu(bret);
		Biz::Session::saveSettingConfig();
	}

}

void ChatToolBar::onSendFileClicked(bool)
{  
    QString fileName = QFileDialog::getOpenFileName(this, "", "", "All files(*.*)");
    if (!fileName.isNull())
    {
        emit sgSendFile(fileName);
    }
}

void ChatToolBar::onQuickReplyMsg()
{
    QuickReplyMsgDialog* mQuickReplyMsgDlg = QuickReplyMsgDialogSingleton::getInstance();

    QPoint editPos = mapToGlobal(ui.btnQuickReply->pos());
    int nWidth = mQuickReplyMsgDlg->geometry().width();
    int nHeight = mQuickReplyMsgDlg->geometry().height();
    int x = editPos.rx() - nWidth/2;
    int y = editPos.ry() - ui.btnQuickReply->height()-nHeight;

   
    disconnect(mQuickReplyMsgDlg, &QuickReplyMsgDialog::sgItemSelected, this, &ChatToolBar::sgItemSelected);
    connect(mQuickReplyMsgDlg, &QuickReplyMsgDialog::sgItemSelected, this, &ChatToolBar::sgItemSelected);
    mQuickReplyMsgDlg->setWinid(mConversationId);
    
    mQuickReplyMsgDlg->move(editPos.rx() - nWidth/2, editPos.ry() -nHeight);
    mQuickReplyMsgDlg->autoshow();
}

void ChatToolBar::onTransferChat()
{
    if (mTransferChatMenu)
    {
        delete mTransferChatMenu;
        mTransferChatMenu = NULL;
    }
    if (mTransferNum)
    {
        delete mTransferNum;
        mTransferNum = NULL;
    }
    if (mTransferRelation)
    {
        delete mTransferRelation;
        mTransferRelation = NULL;
    }
    if (mTransferCollega)
    {
        delete mTransferCollega;
        mTransferCollega = NULL;
    }
	TransferSessionDlg* mQuickReplyMsgDlg = TransferSessionDlgSingleton::getInstance();

	QPoint editPos = mapToGlobal(ui.btnTransfer->pos());
    int nWidth = mQuickReplyMsgDlg->geometry().width();
    int nHeight = mQuickReplyMsgDlg->geometry().height();
    //int x = editPos.rx() - nWidth/2;
    //int y = editPos.ry() - ui.btnQuickReply->height()-nHeight; 
    //disconnect(mQuickReplyMsgDlg, &QuickReplyMsgDialog::sgItemSelected, this, &ChatToolBar::sgItemSelected);
    //connect(mQuickReplyMsgDlg, &QuickReplyMsgDialog::sgItemSelected, this, &ChatToolBar::sgItemSelected);
    //mQuickReplyMsgDlg->setWinid(mConversationId);
    
	mQuickReplyMsgDlg->move(editPos.rx() + ui.btnTransfer->width()/2.0 - nWidth/2, editPos.ry() - nHeight - 5); 
	mQuickReplyMsgDlg->showTranferDlg(mConversationId);
	return;
	/*
    mTransferChatMenu = new QMenu(ui.btnTransfer);

    mTransferNum = new QAction(QStringLiteral("转移到号码"), ui.btnTransfer);
    connect(mTransferNum, &QAction::triggered, this, &ChatToolBar::onTransferNum);
    mTransferChatMenu->addAction(mTransferNum);

    mTransferCollega = new QAction(QStringLiteral("转移到同事"), ui.btnTransfer);
    connect(mTransferCollega, &QAction::triggered, this, &ChatToolBar::onTransferCollega);
    mTransferChatMenu->addAction(mTransferCollega);

    mTransferChatMenu->exec(QCursor::pos());
	*/
}

void ChatToolBar::onVidioAction(bool bcheck)
{
	emit sgVidioAction();
}

void ChatToolBar::onAudioAction(bool bcheck)
{
	emit sgAudioAction();
}

void ChatToolBar::onTransferNum()
{
    if (!mConversationId.isEmpty())
    {
        TransferChatDialog *dlg = TransferChatDialog::instance(mConversationId);
        if ( dlg)
        {
            dlg->setPeerid(mConversationId);
            dlg->setChatid(QString("%1").arg(MainApp::UIFrame::getConversationController()->getConversationChatId(mConversationId)));
            dlg->setType(TransferType::TRANSFERNUM);
			dlg->setcctext(MainApp::UIFrame::getConversationController()->getcctextbyconversationId(mConversationId));
			dlg->setbu(MainApp::UIFrame::getConversationController()->getbubyconversationId(mConversationId));
			QString strProductId = MainApp::UIFrame::getConversationController()->getProductId(mConversationId);
			QString strBusinessline = MainApp::UIFrame::getConversationController()->getbusinessline(mConversationId);
			dlg->setTransInfo(strProductId, strBusinessline);
            dlg->showTransferDlg();
        }
    }
}

void ChatToolBar::onTransferRelation()
{
    if (!mConversationId.isEmpty())
    {
        TransferChatDialog *dlg = TransferChatDialog::instance(mConversationId);
        if (dlg)
        {
            dlg->setPeerid(mConversationId);
            dlg->setChatid(QString("%1").arg(MainApp::UIFrame::getConversationController()->getConversationChatId(mConversationId)));
            dlg->setType(TransferType::TRANSFERRELATION);
			dlg->setcctext(MainApp::UIFrame::getConversationController()->getcctextbyconversationId(mConversationId));
			dlg->setbu(MainApp::UIFrame::getConversationController()->getbubyconversationId(mConversationId));
			QString strProduction = MainApp::UIFrame::getConversationController()->getProductId(mConversationId);
			QString strVistor = MainApp::UIFrame::getConversationController()->getbusinessline(mConversationId);
			dlg->setTransInfo(strProduction, strVistor);
            dlg->showTransferDlg();
        }
    }
}

void ChatToolBar::onTransferCollega()
{
    if (!mConversationId.isEmpty())
    {
        TransferChatDialog *dlg = TransferChatDialog::instance(mConversationId);
        if (dlg)
        {
            dlg->setPeerid(mConversationId);
            dlg->setChatid(QString("%1").arg(MainApp::UIFrame::getConversationController()->getConversationChatId(mConversationId)));
            dlg->setType(TransferType::TRANSFERCOLLEGA);
			dlg->setcctext(MainApp::UIFrame::getConversationController()->getcctextbyconversationId(mConversationId));
			dlg->setbu(MainApp::UIFrame::getConversationController()->getbubyconversationId(mConversationId));
			QString strProduction = MainApp::UIFrame::getConversationController()->getProductId(mConversationId);
			QString strVistor = MainApp::UIFrame::getConversationController()->getbusinessline(mConversationId);
			dlg->setTransInfo(strProduction, strVistor);
            dlg->showTransferDlg();
        }
    }
}

void ChatToolBar::onShakeClicked(bool)
{
    emit sgSendShake();
}

void ChatToolBar::onHistoryRecord()
{
    HistoryRecordDialog *recorddlg = HistoryRecordDialog::instance(mConversationId);
    if (recorddlg)
    {
        recorddlg->setcurrentgroupid(mConversationId);
        recorddlg->showHistoryRecordDlg(mConversationId);
    }
}

void ChatToolBar::onHistoryRecordWeb()
{
    CommentWebViewSingleton::getInstance()->showHistoryRecordDlg();
}

void ChatToolBar::emitSendFileBtn()
{
    ui.btnSendPic->click();
}

void ChatToolBar::onScanRcode(bool)
{
#ifdef _WINDOWS
	QRCodeWidget* pCode = QRCodeWidgetSingleton::getInstance();
	QPoint editPos = mapToGlobal(ui.btnRCode->pos());
	int nWidth = pCode->geometry().width();
	int nHeight = pCode->geometry().height();
	int x = editPos.rx() - nWidth/2;
	int y = editPos.ry() - ui.btnRCode->height()-nHeight;
	pCode->move(editPos.rx() - nWidth/2, editPos.ry() -nHeight);
	pCode->show();
	pCode->activateWindow();
#endif // _WINDOWS

    
}

void ChatToolBar::addFunctionBtns()
{
    if (!Biz::Session::getAccountManager()->getCheckConfigInfo().isNull())
    {
        QList<IJsonSerializeable*> funcs = Biz::Session::getAccountManager()->getCheckConfigInfo()->trdextendmsg();

        QMenu* pBtnMenu = new QMenu();
        
        for (IJsonSerializeable* func : funcs)
        {
            Biz::TrdExtendMsgNode* pNode = (Biz::TrdExtendMsgNode*)func;
            if (NULL!=pNode)
            {
                if (0 == (pNode->client()&Util::nPlatformType))
                    continue;
                int chattype = Biz::MessageUtil::isGroupJid(mConversationId)?2:1;
				int sessionType = Biz::Session::getServiceManager()->getDaoService()->getSessionChatByConversationId(mConversationId);
				if (0 == (pNode->support()&chattype) && !(sessionType==8&&pNode->support()==4))
                    continue;
#ifdef QCHAT
                if (0 == (pNode->scope()&Biz::Session::getAccountManager()->accountData().EUserType()))
                    continue;
#endif
				QString linkUrl = pNode->linkurl();
                QUrl requestUrl(linkUrl);
                QUrlQuery qu(requestUrl);
                qu.addQueryItem("username",Biz::Session::getAccountManager()->accountData().UserID());
                qu.addQueryItem("rk",WebService::sSecurityKey);
                if (Biz::MessageUtil::isGroupJid(mConversationId))
                    qu.addQueryItem("group_id",mConversationId);
                else
                    qu.addQueryItem("user_id",mConversationId);
                requestUrl.setQuery(qu);

                QString strLink = requestUrl.toEncoded();

                QAction *pAction = NULL;
                pAction = pBtnMenu->addAction(pNode->title());
				if (pNode->linkType()==2) { 
					connect(pAction,&QAction::triggered,[linkUrl,this]{
						emit sgSendRequestUrl(linkUrl);
					});
				} else { 
					connect(pAction,&QAction::triggered,[strLink,this]{
						emit sgOpenInternalUrl(strLink);
					});
				}
            }
        }
		if (Biz::MessageUtil::isGroupJid(mConversationId))
		{
			//增加一个分割线和一个子菜单
			if (funcs.size() > 0)
			{
				pBtnMenu->addSeparator();
			}

			QAction *filter = pBtnMenu->addAction(QStringLiteral("消息过滤"));
			connect(filter, &QAction::triggered, [this]{
				emit sgGroupFilterMsg();
			});
		}
		else
		{
#ifndef QCHAT
			QAction *chatEncrypt = pBtnMenu->addAction(QStringLiteral("会话加密"));
			connect(chatEncrypt, &QAction::triggered, [this]{
				emit sgchatencrypt();
			});
#else
			if (funcs.size() > 0)
			{
				pBtnMenu->addSeparator();
			}
			
			QAction *filter = pBtnMenu->addAction(QStringLiteral("产品卡片"));
			connect(filter, &QAction::triggered, [this]{
				emit sgSendProductCard();
			});
#endif // QCHAT

		}
		
		
        ui.btnToolbarMore->setMenu(pBtnMenu);
        ui.btnToolbarMore->setVisible(!pBtnMenu->isEmpty());
    }
}

void ChatToolBar::initCodeControl()
{
	ui.code_checkBox->setChecked(false);
	connect(ui.code_checkBox,&QCheckBox::stateChanged,[this](int state){

		QString codeStyle = ui.codeStyle_comboBox->currentText();
		QString codeType = ui.codetype_comboBox->currentText();
		emit sgCodeHightLight(ui.code_checkBox->isChecked(), codeStyle, codeType);
	});

	//颜色的框
	QStringList stylelist;
	stylelist << "White"<< "Dark" << "Solarized-Dark" << "Monokai";
	for (QString strtyle: stylelist)
	{
		ui.codeStyle_comboBox->addItem(strtyle);
	}
	
	connect(ui.codeStyle_comboBox,&QComboBox::currentTextChanged,[this](const QString& text){
		
		emit sgCodeStyle(text);
		
	});
	
	QString strType = "C++,Objectivec,Swift,Protobuf,Java,Sql,Http,Javascript,Css,JSon,Erlang,erlang-repl,Php,Xml,VBNet,Ruby,Nginx,CS,Delphi,VBScript,Bash,Fix,Nsis,Haxe,Vim,Brainfuck,Bash,Nimrod,Rust,Ruleslanguage,Rib,Diff,Haml,Glsl,Rsl,Lua,Markdown,Capnproto,Lisp,Profile,Gherkin,Fsharp,Mathematica,Haskell,1c,x86asm,Python,Smalltalk,Tex,Actionscript,Ruby,Nix,Handlebars,Thrift,Vala,Gradle,Ini,Livecodeserver,D,Axapta,Perl,Scala,Cmake,OCaml,Autohotkey,Avrasm,Vhdl,CoffeeScript,Mizar,R,django,oxygene,mel,dos,Apache,scss,monkey,lasso,matlab,scilab,makefile,asciidoc,parser3,clojure,elixir,go";

	QStringList typelist = strType.split(",");
	for (QString typeone: typelist)
	{
		ui.codetype_comboBox->addItem(typeone);
	}

	connect(ui.codetype_comboBox,&QComboBox::currentTextChanged,[this](const QString& text){

		emit sgCodeType(text);

	});

}

void ChatToolBar::setGroupVideoButtonNoArrow()
{
	ui.vidioandaudio->setArrowType(Qt::NoArrow);
	mAudioaction->setVisible(false);
	mVidioaction->setText(QStringLiteral("群视频会议(beta)"));
	ui.vidioandaudio->setPopupMode(QToolButton::InstantPopup);
	ui.vidioandaudio->setToolButtonStyle(Qt::ToolButtonIconOnly);
	ui.vidioandaudio->setStyleSheet("\
								 	QToolButton::menu-indicator{\
																image: None;\
									 }");
	//connect(ui.vidioandaudio, &QPushButton::clicked, this, &ChatToolBar::onVidioandaudioClicked);
}

void ChatToolBar::setCodeHightLight( bool bret )
{
	ui.code_checkBox->setChecked(bret);
}


// void ChatToolBar::onVidioandaudioClicked()
// {
// 	emit sgVidioandAudioClicked();
// }


