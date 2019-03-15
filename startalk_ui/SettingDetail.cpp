#include "SettingDetail.h"
#include <QDesktopServices>
#include <QSpinBox>
#include <QPainter>
#include <QFileDialog>
#include <QGuiApplication>
#include <QClipboard>
#include <QColorDialog>


#include "ui_SettingDetail.h"
#include "LanguageHelper.h"
#include "SystemDefine.h"
#include "Session.h"
#include "Account.h"
#include "UserSettingData.h"
#include "UtilHelper.h"
#include "AccountData.h"
#include "ConfigureHelper.h"
#include "BizCallback.h"
#include "Checkversionupdate.h"
#include "portraithelper.h"
#include "SettingData.h"
#include "Framework.h"
#include "SystemConfigData.h"
#include "../3rd/hotkey/MyGlobalShortCut.h"

#include "CallbackReceiver.h"
#include "ProgressDialog.h"
#include "StaticData.h"
#include "gloableeventobject.h"
#include "diywidgit/customviews/qframelayout.h"
#include "accountmanager.h"
#include "UserVcardManager.h"
#include "voicesetting.h"

#include "CustomDefine.h"
#include "jsonobject/httpresult.h"


#include "editablesettings.h"

#include "UIFrame.h"
#include "NotifyCenterController.h"
#include "conversationmanager.h"
#include "PersonCfgManager.h"

#include "ConversationController.h"
#include "workstatuswidget.h"
#include "UiHelper.h"

QString SettingDetail::KPushInfoDic = "kPushInfoDic";

SettingDetail::SettingDetail(QWidget *parent)
    : LocalManWidget(parent)
    , progressDialog(new ProgressDialog(this))
    , mReceiver(new Biz::CallbackReceiver(this))
{
    ui = new Ui::SettingDetail();
    ui->setupUi(this);
	dlg = new SettingHotKeyDialog(this);
    using namespace Qt;
    auto remove = WindowTitleHint;
    // WindowStaysOnTopHint add by wangchao 2018.08.30 子窗口默认显示在父窗口上方
    auto add = FramelessWindowHint | WindowMinMaxButtonsHint | WindowStaysOnTopHint;//|Popup 
    setAttribute(Qt::WA_AlwaysShowToolTips, true);
	setAttribute(Qt::WA_TranslucentBackground, true);
    overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));
#ifdef QCHAT
	setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
	ui->widget_12->setVisible(true);
	ui->radioButton_defaultvoice->setVisible(true);
	ui->radioButton_newsetvoice->setVisible(true);
	ui->messagenotice->setEnabled(false);
	ui->messagepopup->setEnabled(false);
	ui->push_set->setVisible(false);
#else
	
	ui->widget_12->setVisible(false);
	setWindowIcon(QIcon(":/Images/Deal.ico"));
	ui->radioButton_defaultvoice->setVisible(false);
	ui->radioButton_newsetvoice->setVisible(false);
	ui->QuickReplay->setVisible(false);
#endif

    setWindowTitle(QString(T_("MainWidget_Setting")));

    innerConnect();
	connect(dlg, &SettingHotKeyDialog::sgSetOkButtonInfor, this, &SettingDetail::onOkHotKey);
	disconnect(&Biz::Session::currentAccount(), &Biz::Account::SgProgressDisplay, this, &SettingDetail::onProgressDisplay );
    connect(&Biz::Session::currentAccount(), &Biz::Account::SgProgressDisplay, this, &SettingDetail::onProgressDisplay);
    
    auto titlebar = ui->titlebar;
    titlebar->setSizeable(false);
    connect(titlebar, &TitlebarWidget::sgMinOnClicked, this, &LocalManWidget::onClose);
    connect(titlebar, &TitlebarWidget::sgCloseOnClicked, this, &SettingDetail::onClose);

 	Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
	SetEditHotKey(settingconfig->AutoReplyActiveHotKey());
#ifndef _WINDOWS
	ui->gengxin->setVisible(false);
	ui->btn_hotkey->setVisible(false);
#endif


	connect(ui->clearCache,&QPushButton::clicked,[](bool){
		Framework::clearCaches();
	});

	connect(ui->collectInfo,&QPushButton::clicked,[this](bool){
		//Framework::collectLogs();
		//修改成，在后台进行默默打包，然后发送给配置的人员
		ui->logcoll_label->setText(QStringLiteral("开始收集日志..."));
		MainApp::UIFrame::getConversationController()->collectLogsandSend();
		//Biz::Session::getAccountManager()->collectLogsandSend();
		
	});

    QFrameLayout* pLayout = new QFrameLayout(ui->widget_3);
    pLayout->appendWidget(ui->scrollArea,ALINE_FILL);
    pLayout->appendWidget(ui->scrolltip_up,ALINE_TOP|ALINE_MATCHWIDTH);
    pLayout->appendWidget(ui->scrolltip_down,ALINE_BOTTOM|ALINE_MATCHWIDTH);
    ui->scrolltip_up->setVisible(false);
    ui->scrolltip_down->setVisible(false);

    connect(ui->btn_account,&QPushButton::clicked,this,&SettingDetail::onTabBtnClicked);
    connect(ui->btn_autoreplay,&QPushButton::clicked,this,&SettingDetail::onTabBtnClicked);
    connect(ui->btn_conversation,&QPushButton::clicked,this,&SettingDetail::onTabBtnClicked);
    connect(ui->btn_fontsize,&QPushButton::clicked,this,&SettingDetail::onTabBtnClicked);
    connect(ui->btn_friends,&QPushButton::clicked,this,&SettingDetail::onTabBtnClicked);
    connect(ui->btn_hotkey,&QPushButton::clicked,this,&SettingDetail::onTabBtnClicked);
    connect(ui->btn_msgnotice,&QPushButton::clicked,this,&SettingDetail::onTabBtnClicked);
    connect(ui->btn_path,&QPushButton::clicked,this,&SettingDetail::onTabBtnClicked);
    connect(ui->btn_version,&QPushButton::clicked,this,&SettingDetail::onTabBtnClicked);
 //   connect(ui->btn_welcome,&QPushButton::clicked,this,&SettingDetail::onTabBtnClicked);
    connect(ui->btn_other,&QPushButton::clicked,this,&SettingDetail::onTabBtnClicked);

    ui->btn_account->click();
	ui->btn_welcome->setVisible(false);
#ifndef QCHAT
    ui->btn_welcome->setVisible(false);
	ui->groupBox->setVisible(false);
#else
	
#endif // QCHAT

	connect(ui->pbVoiceSetting, &QPushButton::clicked, this, &SettingDetail::onVoiceSetting);

    //connect(ui->workingstatus, &QPushButton::clicked, this, &SettingDetail::onWorkStatusClicked);

	ui->changeuserpath->setVisible(false);
	ui->defaultpath->setVisible(false);

	

}

SettingDetail::~SettingDetail()
{
    delete ui;
	if (dlg != NULL)
	{
		delete dlg;
		dlg = NULL;
	}
}


void SettingDetail::onSyetemSetting()
{
   
}

void SettingDetail::onProfileSetting()
{
    
}

void SettingDetail::innerConnect()
{
    connect(ui->cbEnableChatLru,&QCheckBox::stateChanged,[this]{
        ui->cbChatLruLimit->setEnabled(ui->cbEnableChatLru->isChecked());
        if (ui->cbEnableChatLru->isChecked() != Biz::Session::getEditableSettings()->LimitMaxBasechatDialogCount())
        {
            Biz::Session::getEditableSettings()->LimitMaxBasechatDialogCount(ui->cbEnableChatLru->isChecked());
            Biz::Session::saveEditableSettings();
        }
    });

    connect(ui->cbChatLruLimit,&QComboBox::currentTextChanged,[this](const QString& text){
        int limitSize = text.toInt();
        if (limitSize != Biz::Session::getEditableSettings()->LimitMaxBasechatDialogCountN())
        {
            Biz::Session::getEditableSettings()->LimitMaxBasechatDialogCountN(limitSize);
            Biz::Session::saveEditableSettings();
        }
    });

    connect(ui->accountExit,&QPushButton::clicked,[this](bool checked){
        //注销
        // MainApp::Framework::onLogout();
		MainApp::Framework::onQuit();
         this->close();
    });

    connect(ui->messagesound,&QCheckBox::stateChanged,[this](int st){
        // 开启或者关闭消息声音   
        Qt::CheckState state = ui->messagesound->checkState();
        Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
        settingconfig->MsgSound(state!=Qt::CheckState::Unchecked);
		Biz::Session::saveSettingConfig();
    });

	connect(ui->messagenotice,&QCheckBox::stateChanged,[this](bool bcheck){
		Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
		settingconfig->IsShowMessageNotice(bcheck);
		Biz::Session::saveSettingConfig();
	});
	connect(ui->messagepopup,&QCheckBox::stateChanged,[this](bool bcheck){
		Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
		settingconfig->IsAutoShowMainDialog(bcheck);
		Biz::Session::saveSettingConfig();
	});


	//提取消息
	connect(ui->lineEdit_message,&QLineEdit::textChanged,[this](const QString& text){
		Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
		settingconfig->MessageHotKey(text);
		Biz::Session::saveSettingConfig();
	});

	//捕捉屏幕
	connect(ui->lineEdit_screen,&QLineEdit::textChanged,[this](const QString& text){
		
		Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
		settingconfig->ScreenHotKey(text);
		Biz::Session::saveSettingConfig();
	});

	//收索人员
	connect(ui->lineEdit_search,&QLineEdit::textChanged,[this](const QString& text){
		
		Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
		settingconfig->SearchHotKey(text);
		Biz::Session::saveSettingConfig();
	});

	connect(ui->lineEdit_mbord,&QLineEdit::textChanged,[this](const QString& text){

		Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
		settingconfig->MbordHotKey(text);
		Biz::Session::saveSettingConfig();
	});

	connect(ui->lineEdit_message, &LineEdit::LineEditClicked, this, &SettingDetail::messageClicked);
	connect(ui->lineEdit_screen, &LineEdit::LineEditClicked, this, &SettingDetail::screenClicked);
	connect(ui->lineEdit_search, &LineEdit::LineEditClicked, this, &SettingDetail::searchClicked);
	connect(ui->lineEdit_mbord, &LineEdit::LineEditClicked, this, &SettingDetail::onmbordHotKey);
	//

	connect(ui->SendMessagecombox,&QComboBox::currentTextChanged,[this](const QString& text){
		// 提醒选项改变
		int index = ui->SendMessagecombox->currentIndex();
		Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
		QString strSendHot;
		if (index == 0)
		{
			strSendHot = "Enter";
		}
		else if (index == 1)
		{
			strSendHot = "Ctrl+Enter";
		}
		else if (index == 2)
		{
			strSendHot = "Shift+Enter";
		}
		settingconfig->MSendHotKey(strSendHot);
		Biz::Session::saveSettingConfig();
	});

	connect(ui->ar_enabled,&QCheckBox::stateChanged,[this](int state){
		Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
		settingconfig->AutoReplyEnable(ui->ar_enabled->isChecked());
		Biz::Session::saveSettingConfig();
	});
	void (QSpinBox:: *spinBoxSignal)(int) = &QSpinBox::valueChanged;
	connect(ui->ar_timer,spinBoxSignal,[this](int value){
		Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
		settingconfig->AutoReplyTimer(value);
		Biz::Session::saveSettingConfig();
	});

//     connect(ui->ar_enabled_1,&QCheckBox::stateChanged,[this](int state){
// 
// 		bool bret = ui->ar_enabled_1->isChecked();
// 		
// 		ui->radioButton_anytime->setEnabled(bret);
// 		ui->radioButton_awaypc->setEnabled(bret);
// 		ui->ar_timer_1->setEnabled(bret);
// 
// 
// 		
//        
//     });


// 	void (QSpinBox:: *spinBoxSignal)(int) = &QSpinBox::valueChanged;
// 	connect(ui->ar_timer_1,spinBoxSignal,[this](int value){
// 
// 
// 	});

	//随时接到push 消息

	
	connect(ui->radioButton_anytime, &QRadioButton::clicked, [this]()
	{
		ui->radioButton_anytime->setChecked(true);
		ui->radioButton_awaypc->setChecked(false);

		Biz::Session::currentAccount().setPresence(QXmppPresence::push);
		ui->ar_timer->setEnabled(true);
	});

	connect(ui->radioButton_awaypc, &QRadioButton::clicked, [this]()
	{
		ui->radioButton_awaypc->setChecked(true);
		ui->radioButton_anytime->setChecked(false);
		ui->ar_timer->setEnabled(true);
	});


	connect(ui->savepush, &QPushButton::clicked, [this](){
		setPushStatus();
		MainApp::UIFrame::getNotifyCenterController ()->alertMessage(QStringLiteral("保存成功!"));
	});


    connect(ui->ar_message,&QComboBox::currentTextChanged,[this](const QString &text){
        Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
        settingconfig->AutoReplySystemMessage(text);
        Biz::Session::saveSettingConfig();
    });

    auto raidoChangeFun = [this](){
        bool systemMessage = ui->ar_systemmsg->isChecked();
        Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
        settingconfig->AutoReplyMessageOption(systemMessage);
        Biz::Session::saveSettingConfig();
        ui->ar_message->setEnabled(systemMessage);
        ui->ar_usermsgcontent->setEnabled(!systemMessage);
    };
    connect(ui->ar_systemmsg,&QRadioButton::clicked,raidoChangeFun);
    connect(ui->ar_usermsg,&QRadioButton::clicked,raidoChangeFun);

    connect(ui->ar_usermsgcontent,&QTextEdit::textChanged,[this](){
        Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
        QString text = ui->ar_usermsgcontent->toPlainText();
        settingconfig->AutoReplyUserMessage(text);
        Biz::Session::saveSettingConfig();
    });

	//自动回复的框子
	//繁忙
	connect(ui->checkBox_busy,&QCheckBox::stateChanged,[this](bool status){
		Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
		settingconfig->Busystatus(status);
		status ?ui->lineEdit_busy->setEnabled(true):ui->lineEdit_busy->setEnabled(false);
		Biz::Session::saveSettingConfig();

	} );

	connect(ui->lineEdit_busy, &QTextEdit::textChanged, [this](){
		Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
		QString text = ui->lineEdit_busy->toPlainText();
		settingconfig->BusyMsg(text);
		Biz::Session::saveSettingConfig();
	});

	//离开
	connect(ui->checkBox_away,&QCheckBox::stateChanged,[this](bool status){

		Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
		settingconfig->Awaystatus(status);
		status ?ui->lineEdit_away->setEnabled(true):ui->lineEdit_away->setEnabled(false);
		Biz::Session::saveSettingConfig();

	});

	connect(ui->lineEdit_away, &QTextEdit::textChanged, [this](){
		Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
		QString text = ui->lineEdit_away->toPlainText();
		settingconfig->AwayMsg(text);
		Biz::Session::saveSettingConfig();
	});
    connect(ui->gengxin,&QPushButton::clicked,[this](){
        connect(&Biz::Session::currentAccount(),&Biz::Account::sgCheckUpdateBeta,this,&SettingDetail::onCheckUpdate,Qt::BlockingQueuedConnection);

		QString clipbordText = QApplication::clipboard()->text();
		if ("updateFromTestFlight" == clipbordText)
		{
			Biz::Session::currentAccount().asyncCheckUpdate(true);
		} else {
			Biz::Session::currentAccount().asyncCheckUpdate(false);
		}
        
        ui->gengxin->setEnabled(false);
    });

    connect(ui->openuserpath,&QPushButton::clicked,[this](){
        QString userpath = ui->userpath->text();
        if (userpath.isEmpty())
        {
            userpath = Biz::ConfigureHelper::getRootDir();
        }
#ifdef _WINDOWS
        userpath.replace("/","\\");//将地址中的"/"替换为"\"，因为在Windows下使用的是"\"。
        QProcess::startDetached("explorer " + userpath);
#else
        userpath.replace("\\", "/");
        QProcess::execute("nautilus " +  userpath + "\"");
#endif

    });

    connect(ui->changeuserpath,&QPushButton::clicked,[this](){
        QString userpath = ui->userpath->text();
        if (userpath.isEmpty())
        {
            userpath = Biz::ConfigureHelper::getRootDir();
        }

        QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
            userpath,
            QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

        ui->userpath->setText(dir);
        Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
        settingconfig->UserPath(dir);

    });

    connect(ui->defaultpath,&QPushButton::clicked,[this](){
        Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
        settingconfig->UserPath("");
        QString userpath =   Biz::ConfigureHelper::getRootDir();
        ui->userpath->setText(userpath);
        settingconfig->UserPath(userpath);

    });

 	auto raidoChangeHotKeyFun = [this](){
 		bool ClickedRet = ui->radioEnableButton->isChecked();
 		Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
 		settingconfig->AutoReplyActiveHotKey(ClickedRet);
 		Biz::Session::saveSettingConfig();

		SetEditHotKey(ClickedRet);
 	};
	connect(ui->radioEnableButton,&QRadioButton::clicked,raidoChangeHotKeyFun);
	connect(ui->radioUnEnableButton,&QRadioButton::clicked,raidoChangeHotKeyFun);


	connect(ui->openuserSavepath,&QPushButton::clicked,[this](){
		QString userpath = ui->userSaveAspath->text();
		if (userpath.isEmpty())
		{
			userpath = Biz::ConfigureHelper::getRootDir();
		}
#ifdef _WINDOWS
		userpath.replace("/","\\");//将地址中的"/"替换为"\"，因为在Windows下使用的是"\"。
		QProcess::startDetached("explorer " + userpath);
#else
		userpath.replace("\\", "/");
		QProcess::execute("nautilus " +  userpath + "\"");
#endif

	});

	connect(ui->changeuserSavepath,&QPushButton::clicked,[this](){
		QString userpath = ui->userSaveAspath->text();
		if (userpath.isEmpty())
		{
			userpath = Biz::ConfigureHelper::getRootDir();
		}

		QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
			userpath,
			QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
		if (dir.isEmpty())
		{
			dir = userpath;
		}
	/*	else //这地方判断一下此目录是否能够写文件，如果能够写文件，就继续，否则弹一个错误提示
		{
//  			QFileInfo infor(dir, "test/test.txt");
// // 			bool bret = infor.isWritable();
// 			QFile tmpfile(infor.absoluteFilePath());
// 			bool bret = tmpfile.open(QIODevice::WriteOnly);
// 			if (!bret)
// 			{
// 				MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("所选择的路径没有写文件的权限"));
// 				dir = userpath;
// 				tmpfile.close();
// 				QFile::remove(infor.absoluteFilePath());
// 			}
		}*/

		ui->userSaveAspath->setText(dir);
		Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
		settingconfig->UserSaveAsPath(dir);
		Biz::Session::saveSettingConfig();

	});
	connect(ui->defaultSavepath,&QPushButton::clicked,[this](){
		Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
		settingconfig->UserSaveAsPath("");
		QString userpath =  Biz::ConfigureHelper::getDeskWindowPath();
		ui->userSaveAspath->setText(userpath);
		settingconfig->UserSaveAsPath(userpath);

	});

    connect(ui->max_session,&QComboBox::currentTextChanged,[this](const QString& text){
        // 提醒选项改变
        int max = ui->max_session->currentText().toInt();
        Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
        settingconfig->MaxSessionLimited(max);
        Biz::Session::saveSettingConfig();
    });

	//好友设置
	connect(ui->friendsMode,&QComboBox::currentTextChanged,[this](const QString& text){
		// 提醒选项改变
		int index = ui->friendsMode->currentIndex();
		if (index == 2)
		{
			ui->friendquest_label->setEnabled(true);
			ui->lineEdit_quest->setEnabled(true);
			ui->friendanswer_label->setEnabled(true);
			ui->lineEdit_answer->setEnabled(true);
		}
		else
		{
			ui->friendquest_label->setEnabled(false);
			ui->lineEdit_quest->setEnabled(false);
			ui->friendanswer_label->setEnabled(false);
			ui->lineEdit_answer->setEnabled(false);
		}
		
	});

	connect(ui->pb_friendset,&QPushButton::clicked,[this](){
		
		QString strquest ;
		QString stranswer;
		int index = ui->friendsMode->currentIndex();
		if (index == 2)
		{
			strquest = ui->lineEdit_quest->text();
			stranswer = ui->lineEdit_answer->text();
		}

		Biz::Session::getFriendManager()->setSelfFriendVerify(index, strquest, stranswer);

	});

	//欢迎语信息
	auto raidoChangeWelcomeFun = [this](){
		bool ClickedRet = ui->ResetRadio->isChecked();
		Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
		settingconfig->AutoReplyWelcomeoption(ClickedRet);
		Biz::Session::saveSettingConfig();
		ui->lineEdit_Rewelcome->setEnabled(ClickedRet);
		ui->selfsetWelcomeEdit->setEnabled(!ClickedRet);
	};
	connect(ui->ResetRadio,&QRadioButton::clicked,raidoChangeWelcomeFun);
	connect(ui->selfsetRadio,&QRadioButton::clicked,raidoChangeWelcomeFun);

	connect(ui->selfsetWelcomeEdit,&QTextEdit::textChanged,[this](){
		Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
		QString text = ui->selfsetWelcomeEdit->toPlainText();
		settingconfig->SelfSetWelcome(text);
		Biz::Session::saveSettingConfig();
	});
	
	connect(ui->lineEdit_Rewelcome,&QLineEdit::textChanged,[this](){
		Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
		QString text = ui->lineEdit_Rewelcome->text();
		settingconfig->SelfSetWelcome(text);
		Biz::Session::saveSettingConfig();
	});

	connect(ui->ReplyWelcome_enabled,&QCheckBox::stateChanged,[this](int state){
		Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
		bool bret = ui->ReplyWelcome_enabled->isChecked();
		settingconfig->AutoReplyWelcomeEnable(ui->ReplyWelcome_enabled->isChecked());
		Biz::Session::saveSettingConfig();
	});

	connect(ui->checkBox_fontSize, &QCheckBox::stateChanged, [this](int state){
		Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
		bool bret = ui->checkBox_fontSize->isChecked();
		settingconfig->SetFontSize(ui->checkBox_fontSize->isChecked());
		Biz::Session::saveSettingConfig();

		ui->checkBox_fontSize->isChecked()?GloableEventObject::getInstance()->sgFontSizeChange(settingconfig->MFontSize()):
			GloableEventObject::getInstance()->sgFontSizeChange(14);
	});

    // 其他设置
    connect(ui->cbAutoStartup,&QCheckBox::stateChanged,[this]{
        Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
        bool bret = ui->cbAutoStartup->isChecked();
        if (bret!=settingconfig->AutoStartUp())
        {
            QSettings reg("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",QSettings::NativeFormat);  
            QStringList curKeys = reg.childKeys();
            if (bret)
            {
                QString curPath = qApp->applicationFilePath();
#ifdef _WINDOWS
                curPath = curPath.replace("/","\\");
#endif // _WINDOWS

                
#ifdef QCHAT
                 reg.setValue("QChatIM",curPath);
#else

#ifndef QIM64
                reg.setValue("QunarIM",curPath);
#else
                reg.setValue("qim",curPath);
#endif // QIM32
               
#endif
            }
            else
            {
#ifdef QCHAT
                reg.remove("QChatIM");
#else
                if (curKeys.contains("QunarIM"))
                    reg.remove("QunarIM");
                if (curKeys.contains("qim"))
                    reg.remove("qim");
#endif
            }
            
            
            settingconfig->AutoStartUp(bret);
            Biz::Session::saveSettingConfig();
        }
    });
    connect(ui->cbQuitOnClose,&QCheckBox::stateChanged,[this]{
        Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
        bool bret = ui->cbQuitOnClose->isChecked();
        int option = bret ? Biz::QuitOnCloseOption::QOC_QUIT : Biz::QuitOnCloseOption::QOC_IGNORE ;
        if (option!=settingconfig->QuitOnClose())
        {
            settingconfig->QuitOnClose(option);
            Biz::Session::saveSettingConfig();
        }
    });
    connect(ui->cbNoticeGroupDestroy,&QCheckBox::stateChanged,[this]{
        Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
        bool bret = ui->cbNoticeGroupDestroy->isChecked();
        if (bret!=settingconfig->MessageBoxNotice())
        {
            settingconfig->MessageBoxNotice(bret);
            Biz::Session::saveSettingConfig();
        }
    });

    auto mailSplitSetting = [this](){
        bool ClickedRet = ui->tbMailSplitDefault->isChecked();
        Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
        int splitChar = ui->tbMailSplitDefault->isChecked()?Biz::MSC_SEMICOLON:Biz::MSC_COMMA;
        if (splitChar!=settingconfig->MailSplite())
        {
            settingconfig->MailSplite(splitChar);
            Biz::Session::saveSettingConfig();
        }
    };
    connect(ui->tbMailSplitDefault,&QRadioButton::clicked,mailSplitSetting);
    connect(ui->tbMailSplitComma,&QRadioButton::clicked,mailSplitSetting);

    connect(ui->cbAutoShake,&QPushButton::clicked,[this](bool bcheck){
        Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
        bool bret = ui->cbAutoShake->isChecked();
        if (bret!=settingconfig->AutoShake())
        {
            settingconfig->AutoShake(bret);
            Biz::Session::saveSettingConfig();
        }
    });

	//请求次数
	void (QSpinBox:: *spinBoxRequest)(int) = &QSpinBox::valueChanged;
	connect(ui->requesttm, spinBoxRequest, [this](int value) {
		Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
		settingconfig->RequestTm(value);
		Biz::Session::saveSettingConfig();
	});

	//历史框中的消息数的条数
	connect(ui->cbEnableChatHistoryMsg,&QCheckBox::stateChanged,[this]{
		ui->cbChatHistoryMsgLimit->setEnabled(ui->cbEnableChatHistoryMsg->isChecked());
		if (ui->cbEnableChatHistoryMsg->isChecked() != Biz::Session::getEditableSettings()->ChatHistoryMsgable())
		{
			Biz::Session::getEditableSettings()->ChatHistoryMsgable(ui->cbEnableChatHistoryMsg->isChecked());
			Biz::Session::saveEditableSettings();
			if (ui->cbEnableChatHistoryMsg->isChecked())
			{
				emit Biz::Session::getConverSationManager()->sgHistoryMsgCount(Biz::Session::getEditableSettings()->ChatHistoryMsgCount());
			}
		}
	});

	connect(ui->cbChatHistoryMsgLimit,&QComboBox::currentTextChanged,[this](const QString& text){
		int limitSize = text.toInt();
		int ncount = Biz::Session::getEditableSettings()->ChatHistoryMsgCount();
		if (limitSize != Biz::Session::getEditableSettings()->ChatHistoryMsgCount())
		{
			emit Biz::Session::getConverSationManager()->sgHistoryMsgCount(limitSize);
			Biz::Session::getEditableSettings()->ChatHistoryMsgCount(limitSize);
			Biz::Session::saveEditableSettings();
		}
	});

	//最近会话列表中的数据
	auto raidoRecentListCheckFun = [this](){
		bool ClickedRet = ui->radioButton_loadAll->isChecked();
		Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
		settingconfig->RecentListShow(ClickedRet);
		Biz::Session::saveSettingConfig();
		ui->radioButton_unRead->setChecked(!ClickedRet);
		ui->radioButton_loadAll->setChecked(ClickedRet);
		//
		emit Biz::Session::getConverSationManager()->sgCoversationRectentListShow(ClickedRet);

	};
	connect(ui->radioButton_unRead,&QRadioButton::clicked,raidoRecentListCheckFun);
	connect(ui->radioButton_loadAll,&QRadioButton::clicked,raidoRecentListCheckFun);


	auto radiovoiceFun = [this]()
	{
		bool clickret = ui->radioButton_defaultvoice->isChecked();
		Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
		settingconfig->DefaultVoiceSet(clickret);
		ui->radioButton_newsetvoice->setChecked(!clickret);
		ui->radioButton_defaultvoice->setChecked(clickret);
		Biz::Session::saveSettingConfig();

	};
	connect(ui->radioButton_defaultvoice, &QRadioButton::clicked, [this](){
		bool clickret = ui->radioButton_defaultvoice->isChecked();
		Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
		settingconfig->DefaultVoiceSet(clickret);
		ui->radioButton_newsetvoice->setChecked(!clickret);
		ui->radioButton_defaultvoice->setChecked(clickret);
		Biz::Session::saveSettingConfig();
	});
	connect(ui->radioButton_newsetvoice, &QRadioButton::clicked, [this](){
		bool clickret = ui->radioButton_newsetvoice->isChecked();
		Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();
		settingconfig->DefaultVoiceSet(!clickret);
		ui->radioButton_newsetvoice->setChecked(clickret);
		ui->radioButton_defaultvoice->setChecked(!clickret);
		Biz::Session::saveSettingConfig();
	});

	
	connect(ui->cbHttpLog, &QPushButton::clicked,[this](bool bcheck){
		Biz::EditableSettings* peditsetting = Biz::Session::getEditableSettings();
		bool bret = ui->cbHttpLog->isChecked();
		bret?peditsetting->ShowInnerLog(Biz::EditableSettings::INNERLOGOPTION::ILO_HTTPLOG):
			peditsetting->ShowInnerLog(Biz::EditableSettings::INNERLOGOPTION::ILO_LOGNONE);
		
		Biz::Session::saveEditableSettings();
		
	});

	connect(ui->cbEsc_hideChat, &QPushButton::clicked,[this](bool bcheck){
		Biz::AllUserSettingData* psetting = Biz::Session::getSettingConfig();
		bool bret = ui->cbEsc_hideChat->isChecked();
		if (bret!=psetting->EscHideChat())
		{
			psetting->EscHideChat(bret);
			Biz::Session::saveSettingConfig();
		}
	});

	connect(ui->cbGroupChatMember_ShowOrHide, &QPushButton::clicked, [this](bool bcheck){
		Biz::AllUserSettingData* psetting = Biz::Session::getSettingConfig();
		bool bret = ui->cbGroupChatMember_ShowOrHide->isChecked();
		if (bret!=psetting->ShowGroupMemberlist())
		{
			psetting->ShowGroupMemberlist(bret);
			Biz::Session::saveSettingConfig();
		}
	});


	connect(ui->push_set, &QPushButton::clicked, [this](bool bcheck){
		Log::e("SettingDetail::onPushStatus ");
		bool bret = ui->push_set->isChecked();
		auto callback = mReceiver->createCallback<QString>([this](QString strRet)
		{
			if (strRet.isEmpty())
			{
				MainApp::UIFrame::getNotifyCenterController ()->popupNotice ( QStringLiteral("设置push错误!!"));
				Log::e(QStringLiteral("SettingDetail::onWorkStatusClicked radioButton_StandardModel 服务器返回是空值!!") );
				return;
			}
			Biz::HttpResultBase resultJson(NULL);
			resultJson.unserializeFromString(strRet);
			bool bRet = resultJson.ret();
			QString errmsg = resultJson.errmsg();

			if(!bRet ){

				MainApp::UIFrame::getNotifyCenterController ()->popupNotice (errmsg.isEmpty() ? QStringLiteral("设置push错误!!"):errmsg);
				return;
			}
		

		}, []{});

		Biz::Session::getAccountManager()->setPushStatus(bret?1:0,callback);
	});

	//点击了收集日志按钮后，出现的信息
	connect(Biz::Session::getAccountManager(), &Biz::AccountManager::sgcollectLogsInfo, this, &SettingDetail::onCollectLogsInfo);

	connect( ui->cbScrollbarOnblew, &QPushButton::clicked, [this](bool bcheck){
		Biz::AllUserSettingData* psetting = Biz::Session::getSettingConfig();
		bool bret = ui->cbScrollbarOnblew->isChecked();
		if (bret!=psetting->ScrollbaronBlew())
		{
			psetting->ScrollbaronBlew(bret);
			Biz::Session::saveSettingConfig();
		}
	});

	connect( ui->pbt_tasktextclr, &QPushButton::clicked, [this](bool bcheck){
		Biz::AllUserSettingData* psetting = Biz::Session::getSettingConfig();
		int  nFirstClr = psetting->TaskTextClr();

		QColor curColor = MainApp::intToQColor(nFirstClr);
		QColor color = QColorDialog::getColor(curColor,this);
		if (color.isValid())
		{
			QPixmap pixmaptask(ui->pbt_tasktextclr->size());
			
			pixmaptask.fill(color);
			ui->pbt_tasktextclr->setIconSize(ui->pbt_tasktextclr->size());
			ui->pbt_tasktextclr->setIcon(QIcon(pixmaptask));

			int nafterClr = MainApp::QColorToInt(color);
			if (nFirstClr != nafterClr)
			{
				psetting->TaskTextClr(nafterClr);
				Biz::Session::saveSettingConfig();
			}
		}
		
		
	});


	connect( ui->pbt_darkclr, &QPushButton::clicked, [this](bool bcheck){
		Biz::AllUserSettingData* psetting = Biz::Session::getSettingConfig();
		int  nFirstClr = psetting->DarkDescClr();

		QColor curColor = MainApp::intToQColor(nFirstClr);
		QColor color = QColorDialog::getColor(curColor,this);
		if (color.isValid())
		{
			QPixmap pixmapdark(ui->pbt_darkclr->size());

			pixmapdark.fill(color);
			ui->pbt_darkclr->setIconSize(ui->pbt_darkclr->size());
			ui->pbt_darkclr->setIcon(QIcon(pixmapdark));

			int nafterClr = MainApp::QColorToInt(color);
			if (nFirstClr != nafterClr)
			{
				psetting->DarkDescClr(nafterClr);
				Biz::Session::saveSettingConfig();
			}
		}


	});

	connect( ui->pbt_lightclr, &QPushButton::clicked, [this](bool bcheck){
		Biz::AllUserSettingData* psetting = Biz::Session::getSettingConfig();
		int  nFirstClr = psetting->LightDescClr();

		QColor curColor = MainApp::intToQColor(nFirstClr);
		QColor color = QColorDialog::getColor(curColor,this);
		if (color.isValid())
		{
			QPixmap pixmaplight(ui->pbt_lightclr->size());

			pixmaplight.fill(color);
			ui->pbt_lightclr->setIconSize(ui->pbt_lightclr->size());
			ui->pbt_lightclr->setIcon(QIcon(pixmaplight));

			int nafterClr = MainApp::QColorToInt(color);
			if (nFirstClr != nafterClr)
			{
				psetting->LightDescClr(nafterClr);
				Biz::Session::saveSettingConfig();
			}
		}


	});


	connect(ui->QuickReplay, &QPushButton::clicked, [this](bool bcheck){
		Log::e("SettingDetail::onPushStatus ");
		Biz::AllUserSettingData* psetting = Biz::Session::getSettingConfig();
		bool bret = ui->QuickReplay->isChecked();
		if (bret!=psetting->QuickReply())
		{
			psetting->QuickReply(bret);
			Biz::Session::saveSettingConfig();
		}
	});

}

void SettingDetail::innerDisconnect()
{
    
}


SettingDetail* SettingDetail::pInstance = NULL;
SettingDetail* SettingDetail::instance()
{
    if (pInstance==NULL)
    {
        pInstance = new SettingDetail();
    }
    return pInstance;
}

void SettingDetail::loadConfigration()
{
    QString selurl = Biz::Session::currentAccount().accountData().UserID();
    QPixmap header = Biz::PortraitHelper::getUserPortrait(selurl);

    QString name = Biz::Session::getUserVcardManager()->getUserNameByConversationId(Biz::MessageUtil::makeSureUserJid(Biz::Session::getAccountManager()->accountData().UserID()));
    //ui->header->setScaledContents(true);
	header = QPixmap::fromImage(header.toImage().scaled(ui->header->size()));

    ui->header->setPixmap(header);
    ui->name->setText(name);

    Biz::AllUserSettingData* settingconfig = Biz::Session::getSettingConfig();


    //ui->messagenotice->setChecked(settingconfig->IsShowMessageNotice());
    //ui->messagepopup->setChecked(settingconfig->IsAutoShowMainDialog());

    ui->messagesound->setChecked((settingconfig->MsgSound()==0)?Qt::CheckState::Unchecked:Qt::CheckState::Checked);

    QString strMainVerion = Biz::ConfigureHelper::appVersionInfo();
#ifdef QCHAT
	QString strDesc = QString("QCHAT %1 ").arg(strMainVerion);
	ui->messagenotice->setChecked(true);
	ui->messagepopup->setChecked(true);
	ui->QuickReplay->setChecked(settingconfig->QuickReply());
#else
	QString strDesc = QString("QTalk %1 ").arg(strMainVerion);
	ui->messagenotice->setChecked(settingconfig->IsShowMessageNotice());
	ui->messagepopup->setChecked(settingconfig->IsAutoShowMainDialog());
#endif // QCHAT

    
    ui->version->setText(strDesc);

	//热键
	QString tmphotkey = settingconfig->MessageHotKey();
	ui->lineEdit_message->setText(tmphotkey);
	tmphotkey = settingconfig->ScreenHotKey();
	ui->lineEdit_screen->setText(tmphotkey);
	tmphotkey = settingconfig->SearchHotKey();
	ui->lineEdit_search->setText(tmphotkey);
	tmphotkey = settingconfig->MbordHotKey();
	ui->lineEdit_mbord->setText(tmphotkey);

	tmphotkey = settingconfig->MSendHotKey();
	if (tmphotkey == "Enter")
	{
		ui->SendMessagecombox->setCurrentIndex(0);
	}
	else if (tmphotkey == "Ctrl+Enter")
	{
		ui->SendMessagecombox->setCurrentIndex(1);
	}
	else if (tmphotkey == "Shift+Enter")
	{
		ui->SendMessagecombox->setCurrentIndex(2);
	}

	ui->ar_enabled->setChecked(settingconfig->AutoReplyEnable());
	ui->ar_timer->setValue(settingconfig->AutoReplyTimer());
	ui->ar_message->setCurrentText(settingconfig->AutoReplySystemMessage());
	ui->ar_usermsgcontent->setText(settingconfig->AutoReplyUserMessage());
	ui->ar_systemmsg->setChecked(settingconfig->AutoReplyMessageOption());
	ui->ar_message->setEnabled(settingconfig->AutoReplyMessageOption());
	ui->ar_usermsg->setChecked(!settingconfig->AutoReplyMessageOption());
	ui->ar_usermsgcontent->setEnabled(!settingconfig->AutoReplyMessageOption());

	//从数据库里拿相关的push记录
	initPush();

	
	ui->checkBox_busy->setChecked(settingconfig->Busystatus());
	ui->checkBox_away->setChecked(settingconfig->Awaystatus());
	ui->lineEdit_busy->setEnabled(settingconfig->Busystatus());
	ui->lineEdit_away->setEnabled(settingconfig->Awaystatus());
	ui->lineEdit_busy->setText(settingconfig->BusyMsg());
	ui->lineEdit_away->setText(settingconfig->AwayMsg());

    QString userpath = settingconfig->UserPath();
    if (userpath.isEmpty())
    {
        userpath = Biz::ConfigureHelper::getRootDir();
    }
    ui->userpath->setText(userpath);

	ui->radioEnableButton->setChecked(settingconfig->AutoReplyActiveHotKey());
	ui->radioUnEnableButton->setChecked(!settingconfig->AutoReplyActiveHotKey());

    QString userSavepath =    settingconfig->UserSaveAsPath();
	if (userSavepath.isEmpty())
	{
		userSavepath = Biz::ConfigureHelper::getDeskWindowPath();
		settingconfig->UserSaveAsPath(userSavepath);
		Biz::Session::saveSettingConfig();
	}
	ui->userSaveAspath->setText(userSavepath);
	

    // 最大会话数
    QSet<int> maxSessions;
    maxSessions << 50 <<100 << 200 << 500 << 1000 << 2000 << 5000 << 10000;
    if (maxSessions.contains(settingconfig->MaxSessionLimited()))
    {
        ui->max_session->setCurrentText(QString::number(settingconfig->MaxSessionLimited()));
    }
    else
    {
        ui->max_session->setCurrentText(QString::number(50));
        settingconfig->MaxSessionLimited(50);
    }

    Biz::EditableSettings* pEditableSettings = Biz::Session::getEditableSettings();
    ui->cbChatLruLimit->setCurrentText(QString::number(pEditableSettings->LimitMaxBasechatDialogCountN()));
    ui->cbChatLruLimit->setEnabled(pEditableSettings->LimitMaxBasechatDialogCount());
    ui->cbEnableChatLru->setChecked(pEditableSettings->LimitMaxBasechatDialogCount());
	//好友设置
	int friendmode = settingconfig->SelfFriendMode();
	ui->friendsMode->setCurrentIndex(friendmode);
	if (friendmode != 2 )
	{
		ui->friendquest_label->setEnabled(false);
		ui->friendanswer_label->setEnabled(false);
		ui->lineEdit_quest->setEnabled(false);
		ui->lineEdit_answer->setEnabled(false);
	}
	else
	{
		ui->friendquest_label->setEnabled(true);
		ui->friendanswer_label->setEnabled(true);
		ui->lineEdit_quest->setEnabled(true);
		ui->lineEdit_answer->setEnabled(true);

		ui->lineEdit_quest->setText(settingconfig->SelfFriendQuestion());
		ui->lineEdit_answer->setText(settingconfig->SelfFriendAnswer());
	}


	//欢迎回复语
	ui->ReplyWelcome_enabled->setChecked(settingconfig->AutoReplyWelcomeEnable());
	ui->ResetRadio->setChecked(settingconfig->AutoReplyWelcomeoption());
	ui->lineEdit_Rewelcome->setEnabled(settingconfig->AutoReplyWelcomeoption());
	ui->lineEdit_Rewelcome->setText(settingconfig->ReSetWelcome());
	ui->selfsetRadio->setChecked(!settingconfig->AutoReplyWelcomeoption());
	ui->selfsetWelcomeEdit->setEnabled(!settingconfig->AutoReplyWelcomeoption());
	ui->selfsetWelcomeEdit->setText(settingconfig->SelfSetWelcome());

	//zihaosezhi
	ui->checkBox_fontSize->setChecked(settingconfig->SetFontSize());


    if (Util::GLOBAL_INTERNAL_VERSION < Biz::Session::getAccountManager()->accountData().LastestVersion())
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
        
        ui->btn_version->setIcon(QIcon(retPixMap));
        ui->newversion->setText(QString::number(Biz::Session::getAccountManager()->accountData().LastestVersion()));
        ui->newversion->adjustSize();
        ui->newversion->setVisible(true);
    }
    else
    {
        ui->btn_version->setIcon(QIcon());
        ui->newversion->setVisible(false);
    }

    

    QSettings reg("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",QSettings::NativeFormat);  
    QStringList curKeys = reg.childKeys();
    bool bIsAutoStartUp = settingconfig->AutoStartUp();
#ifdef QCHAT
    if (curKeys.contains("QChatIM"))
        bIsAutoStartUp = true;
#else
    if (curKeys.contains("QunarIM"))
        bIsAutoStartUp = true;
    else if (curKeys.contains("qim"))
        bIsAutoStartUp = true;
    
#endif
    ui->cbAutoStartup->setChecked(bIsAutoStartUp);

    ui->cbQuitOnClose->setChecked(settingconfig->QuitOnClose()==Biz::QOC_QUIT);
    ui->tbMailSplitDefault->setChecked(settingconfig->MailSplite()==Biz::MSC_SEMICOLON);
    ui->cbNoticeGroupDestroy->setChecked(settingconfig->MessageBoxNotice());

	//请求次数
	ui->requesttm->setValue(settingconfig->RequestTm());

	//历史框中会话数的设置
	ui->cbChatHistoryMsgLimit->setCurrentText(QString::number(pEditableSettings->ChatHistoryMsgCount()));
	ui->cbEnableChatHistoryMsg->setEnabled(pEditableSettings->ChatHistoryMsgable());
	ui->cbEnableChatHistoryMsg->setChecked(pEditableSettings->ChatHistoryMsgable());

	//最近会话列表的显示样式
	ui->radioButton_loadAll->setChecked(settingconfig->RecentListShow());
	ui->radioButton_unRead->setChecked(!settingconfig->RecentListShow());

	//qchat中声音的设置
	ui->radioButton_defaultvoice->setChecked(settingconfig->DefaultVoiceSet());
	ui->radioButton_newsetvoice->setChecked(!settingconfig->DefaultVoiceSet());

	//http请求日志的设置(由于这里特殊，写在了editablesetting.dat文件中)
	Biz::EditableSettings *peditstting = Biz::Session::getEditableSettings();
	if (Biz::EditableSettings::INNERLOGOPTION::ILO_HTTPLOG == 
		(Biz::Session::getEditableSettings()->ShowInnerLog() & Biz::EditableSettings::INNERLOGOPTION::ILO_HTTPLOG))
	{
		ui->cbHttpLog->setChecked(true);
	}
	else
	{
		ui->cbHttpLog->setChecked(false);
	}
	

	ui->cbEsc_hideChat->setChecked(settingconfig->EscHideChat());

	//群成员列表的展示与否
	ui->cbGroupChatMember_ShowOrHide->setChecked(settingconfig->ShowGroupMemberlist());

	ui->cbScrollbarOnblew->setChecked(settingconfig->ScrollbaronBlew());

	QSize size = ui->pbt_tasktextclr->size() ;

	QPixmap pixmaptask(ui->pbt_tasktextclr->size());
	QColor color = MainApp::intToQColor(settingconfig->TaskTextClr());
	pixmaptask.fill(color);
	ui->pbt_tasktextclr->setIconSize(ui->pbt_tasktextclr->size());
	ui->pbt_tasktextclr->setIcon(QIcon(pixmaptask));

	QPixmap pixmapdarkclr(ui->pbt_darkclr->size());
	QColor color_dark = MainApp::intToQColor(settingconfig->DarkDescClr());
	pixmapdarkclr.fill(color_dark);
	ui->pbt_darkclr->setIconSize(ui->pbt_darkclr->size());
	ui->pbt_darkclr->setIcon(QIcon(pixmapdarkclr));

	QPixmap pixmaplightclr(ui->pbt_lightclr->size());
	QColor color_light = MainApp::intToQColor(settingconfig->LightDescClr());
	pixmaplightclr.fill(color_light);
	ui->pbt_lightclr->setIconSize(ui->pbt_lightclr->size());
	ui->pbt_lightclr->setIcon(QIcon(pixmaplightclr));
	
}

void SettingDetail::showSetting(bool flag)
{
	Biz::Session::getFriendManager()->getSelfVerifyMode();
    loadConfigration();
    showNormal();
    activateWindow();


#ifdef QCHAT

	//这里判断是否客服，如果是客服才显示工作模式及让客服进行更改
	bool isEmployee = (Biz::EUserTypeEmployee==(Biz::EUserTypeEmployee&Biz::Session::getAccountManager()->accountData().EUserType()));
	if(isEmployee)
	{
		ui->funspanel->setVisible(!isEmployee);
	}
	else
	{
		// 同步数据
		auto getWorkstatusCallback = mReceiver->createCallback<QList<QSharedPointer<Biz::WorkStatusData>>>([this](const QList<QSharedPointer<Biz::WorkStatusData>>& list){
			//Log::e("get workstatus result  " + QString::number(status));
			if (list.size() <= 0)
			{
				QVBoxLayout *layout = new QVBoxLayout(ui->scrollWorkstatus);
				
				
				WorkStatuswidget*wkstat = new WorkStatuswidget(this);
				wkstat->setTitleInfor(QStringLiteral("获取工作模式失败,需重启客户端重新获取"));
					
					
				
				ui->scrollWorkstatus->setLayout(layout);
				ui->scrollWorkstatus->setFixedHeight(130);
				ui->scrollArea_workstatus->setWidget(ui->scrollWorkstatus);
			}
			else
			{
				QVBoxLayout *layout = new QVBoxLayout(ui->scrollWorkstatus);
				int nI = 0;
				for (QSharedPointer<Biz::WorkStatusData> wkitem:list)
				{
					WorkStatuswidget*wkstat = new WorkStatuswidget(this);
					wkstat->setTitleInfor(wkitem->sname());
					wkstat->setStatus(wkitem->st());
					wkstat->setSid(wkitem->sid());
					layout->addWidget(wkstat);
					nI++;
				}
				ui->scrollWorkstatus->setLayout(layout);
				ui->scrollWorkstatus->setFixedHeight(nI*130);
				ui->scrollArea_workstatus->setWidget(ui->scrollWorkstatus);
			}


		},[this]{

			QVBoxLayout *layout = new QVBoxLayout(ui->scrollWorkstatus);

			WorkStatuswidget*wkstat = new WorkStatuswidget(this);
			wkstat->setTitleInfor(QStringLiteral("获取工作模式失败,需重启客户端重新获取"));

			ui->scrollWorkstatus->setLayout(layout);
			ui->scrollWorkstatus->setFixedHeight(130);
			ui->scrollArea_workstatus->setWidget(ui->scrollWorkstatus);

			Log::e("get workstatus result fail");
		});
		Biz::Session::getAccountManager()->getWorkStatus(getWorkstatusCallback);
		ui->funspanel->setVisible(true);
	}
	
    
#else
    ui->funspanel->setVisible(false);

	auto getPushstatusCallback = mReceiver->createCallback<bool>([this](bool status){
		Log::e("get pushstatus result " + QString::number(status));
		
		ui->push_set->setChecked(status);

	},[]{
		Log::e("get workstatus result fail");
	});
	Biz::Session::getAccountManager()->getPushStatus(getPushstatusCallback);
	

#endif // QCHAT

// 	if (flag == true)
// 	{
// 		
// 		ui->btn_msgnotice->clicked(true);
// 		
// 		ui->btn_msgnotice->setChecked(true);
// 	}
}

void SettingDetail::messageClicked()
{
	//SettingHotKeyDialog dlg;
	if (dlg != NULL)
	{
		dlg->SetHotKey(ui->lineEdit_message->text(), 1);
		emit Biz::Session::currentAccount().sgUnRegistHotkey(1);
		dlg->show();
		dlg->activateWindow();
	}

	
	
}

void SettingDetail::screenClicked()
{
	if (dlg != NULL)
	{
		dlg->SetHotKey(ui->lineEdit_screen->text(), 2);
		emit Biz::Session::currentAccount().sgUnRegistHotkey(2);
		dlg->show();
		dlg->activateWindow();
	}

}
void SettingDetail::searchClicked()
{
	if (dlg != NULL)
	{
		dlg->SetHotKey(ui->lineEdit_search->text(), 3);
		emit Biz::Session::currentAccount().sgUnRegistHotkey(3);
		dlg->show();
		dlg->activateWindow();
	}
}
void SettingDetail::onmbordHotKey()
{
	if (dlg != NULL)
	{
		dlg->SetHotKey(ui->lineEdit_mbord->text(), 4);
		emit Biz::Session::currentAccount().sgUnRegistHotkey(4);
		dlg->show();
		dlg->activateWindow();
	}
}
void SettingDetail::onOkHotKey(const QString&strhotkey, int ntype)
{
	switch (ntype)
	{
	case 1:
		ui->lineEdit_message->setText(strhotkey);
		//MyGlobalShortCut* shortcutGetMsg = new MyGlobalShortCut(strhotkey, this);
		//connect(shortcutGetMsg, &MyGlobalShortCut::activated, this, &MainWidget::hotKeyGetMsg);

		break;
	case 2:
		{
			ui->lineEdit_screen->setText(strhotkey);
#ifdef _WINDOWS
			MyGlobalShortCut* shortcutscreen = new MyGlobalShortCut(strhotkey, this);
			bool bret = shortcutscreen->unregisterHotKey();
			bret = shortcutscreen->registerHotKey();
			if (!bret)
			{
				UIFrame::getNotifyCenterController()->alertMessage(QStringLiteral("该快捷键注册失败！"));
				return;
			}
#else

#endif // _WINDOWS
		}
		

		
		break;
	case 3:
		ui->lineEdit_search->setText(strhotkey);
		break;
	case 4:
		ui->lineEdit_mbord->setText(strhotkey);
		break;
	default:
		break;
	}
	QString ttthotkey = strhotkey;
	QString strtmp = ttthotkey.replace(" ", "");
	emit Biz::Session::currentAccount().sgRegistHotKey(strhotkey, ntype);
}

void SettingDetail::onCheckUpdate(const QSharedPointer<Biz::CheckVersionUpdate>& updateinfo)
{
    disconnect(&Biz::Session::currentAccount(),&Biz::Account::sgCheckUpdateBeta,this,&SettingDetail::onCheckUpdate);
    if (updateinfo.isNull())
    {
        MainApp::UIFrame::getNotifyCenterController ()->alertMessage(QStringLiteral("请求更新失败"));
        ui->gengxin->setEnabled(true);
    }
    else
    {
        QString betaVersionUrl = updateinfo->betaurl; 
        QString lastversion = updateinfo->lastVersion;

        if (!lastversion.isEmpty() && lastversion.toLong() > Util::GLOBAL_INTERNAL_VERSION && !betaVersionUrl.isEmpty())
        {
            if (!MainApp::UIFrame::getNotifyCenterController ()->alertMessageWithCancle(QStringLiteral("发现新版本，是否更新？")))
            {
                //cancle
                ui->gengxin->setEnabled(true);
                return;
            }
             progressDialog->show();

            auto callback = mReceiver->createCallback<QString>(
                [ this](QString savepath){
                    progressDialog->setSavePath(savepath);
					ui->gengxin->setEnabled(true);
					Biz::StaticData::reportTakeTimeEvent("90001",1,"DownloadNewFile Success");
            },[this]{
				Biz::StaticData::reportTakeTimeEvent("90002",1,"DownloadNewFile Fail");
				progressDialog->hide();
                QString strdownloadhttp = Biz::Session::getEditableSettings()->SupportWeb();
				QString strTitleInfor = QStringLiteral("<h3>更新失败,请链接下行地址重新下载!\n\n<a href=\"%1\">%1</a></h3>").arg(strdownloadhttp);
                MainApp::UIFrame::getNotifyCenterController ()->alertMessage (strTitleInfor);
                ui->gengxin->setEnabled(true);
				QDesktopServices bs;
				bs.openUrl(QUrl(strdownloadhttp));
				return;

            });
			
            Biz::Session::currentAccount().downloadNewVersion(/*Util::GLOBAL_INTERNAL_VERSION*/lastversion.toLongLong(),betaVersionUrl,updateinfo->md5,callback);

        }
        else
        {
             MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("已经是最新版本"));
           
            ui->gengxin->setEnabled(true);
        }
    }
}

void SettingDetail::onProgressDisplay(const qint64 done, const qint64 total)
{
    progressDialog->setRangeBar(done, total);
}

void SettingDetail::SetEditHotKey(bool bRet)
{
	ui->radioEnableButton->setChecked(bRet);
	ui->radioUnEnableButton->setChecked(!bRet);


	ui->lineEdit_message->setEnabled(bRet);
	ui->lineEdit_screen->setEnabled(bRet);
	ui->lineEdit_search->setEnabled(bRet);
	ui->lineEdit_mbord->setEnabled(bRet);
  	OnSetRegisterOrUnRegister(bRet);
}

void SettingDetail::OnSetRegisterOrUnRegister(bool bret)
{

	if (bret)
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
	else
	{
		emit Biz::Session::currentAccount().sgUnRegistHotkey(1);
		emit Biz::Session::currentAccount().sgUnRegistHotkey(2);
		emit Biz::Session::currentAccount().sgUnRegistHotkey(3);
		emit Biz::Session::currentAccount().sgUnRegistHotkey(4);
	}


}

void SettingDetail::onTabBtnClicked(bool)
{
    QObject* pSender = sender();
    if (pSender == ui->btn_account)
        ui->stackedWidget->setCurrentWidget(ui->page_account);
    if (pSender == ui->btn_autoreplay)
#ifdef QCHAT
		 ui->stackedWidget->setCurrentWidget(ui->page_replay);
#else
		 ui->stackedWidget->setCurrentWidget(ui->page_qtalkReplay);
#endif // QCHAT

        //ui->stackedWidget->setCurrentWidget(ui->page_replay);
    if (pSender == ui->btn_conversation)
        ui->stackedWidget->setCurrentWidget(ui->page_chat);
    if (pSender == ui->btn_fontsize)
        ui->stackedWidget->setCurrentWidget(ui->page_font);
    if (pSender == ui->btn_friends)
        ui->stackedWidget->setCurrentWidget(ui->page_friends);
    if (pSender == ui->btn_hotkey)
        ui->stackedWidget->setCurrentWidget(ui->page_hotkey);
    if (pSender == ui->btn_msgnotice)
        ui->stackedWidget->setCurrentWidget(ui->page_msgnotice);
    if (pSender == ui->btn_path)
        ui->stackedWidget->setCurrentWidget(ui->page_path);
    if (pSender == ui->btn_version)
        ui->stackedWidget->setCurrentWidget(ui->page_version);
    if (pSender == ui->btn_welcome)
        ui->stackedWidget->setCurrentWidget(ui->page_welcome);
    if (pSender == ui->btn_other)
        ui->stackedWidget->setCurrentWidget(ui->page_other);
}

void SettingDetail::onVoiceSetting()
{
	VoiceSettingsingleton::getInstance()->exec();
}

void SettingDetail::onWorkStatusClicked(bool bcheck)
{
//     Log::e("SettingDetail::onWorkStatusClicked " + QString::number(bcheck));
// 
//     auto callback = mReceiver->createCallback<QString>([this](QString strRet)
//     {
// 		Biz::HttpResultBase resultJson(NULL);
// 		resultJson.unserializeFromString(strRet);
// 		bool bRet = resultJson.ret();
// 		QString errmsg = resultJson.errmsg();
// 
// 		if(!bRet ){
// 
// 			MainApp::UIFrame::getNotifyCenterController ()->popupNotice (errmsg.isEmpty() ? QStringLiteral("设置状态错误!!"):errmsg);
// 			return;
// 		}
//         
// 
//     }, []{});
// 
//     Biz::Session::getAccountManager()->setWorkStatus(bcheck?Biz::WorkStatusData::STATUS::ST_SERVICE:Biz::WorkStatusData::STATUS::ST_rest,callback);
}

void SettingDetail::setPushStatus()
{
	QJsonObject jsonValue;
	

	bool bret = ui->radioButton_anytime->isChecked();
	jsonValue.insert("anytime", QString("%1").arg(bret));
	jsonValue.insert("awaypc", QString("%1").arg(!bret));
	jsonValue.insert("awaytime", QString("%1").arg(ui->ar_timer_1->value()));

	QString value = QJsonDocument(jsonValue).toJson(QJsonDocument::Compact);
	Log::e("SettingDetail::setPushStatus---Biz::Session::getPersonCfgManager()->savePersonCfgInfo");
	Biz::Session::getPersonCfgManager()->savePersonCfgInfo(KPushInfoDic,value);

	//這時需要往服務器發送狀態

	if (ui->radioButton_anytime->isChecked())
	{
		Biz::Session::currentAccount().setPresence(QXmppPresence::push);
	}

	
}

void SettingDetail::initPush()
{
	QSharedPointer<Biz::PersonConfInfo> spPersonCfg = 
		Biz::Session::getPersonCfgManager()->getPersonCfgInfo(KPushInfoDic);
	if (spPersonCfg.isNull())
	{
		//ui->ar_enabled_1->setChecked(true);
		ui->radioButton_anytime->setEnabled(true);
		ui->radioButton_awaypc->setEnabled(true);
		ui->ar_timer_1->setValue(5);


		return;
	}
	QString jsonString = spPersonCfg->infoValue();

	QVariantMap jsonMaps 
		= QJsonDocument::fromJson(jsonString.toUtf8()).toVariant().toMap();
	

	ui->radioButton_anytime->setEnabled(true);
	ui->radioButton_awaypc->setEnabled(true);

	bool bret = jsonMaps.value("anytime").toBool();
	ui->radioButton_anytime->setChecked(bret);
	
	

	bret = jsonMaps.value("awaypc").toBool();
	ui->radioButton_awaypc->setChecked(bret);


	int num = jsonMaps.value("awaytime").toInt();
	ui->ar_timer_1->setValue(num);
}

void SettingDetail::onCollectLogsInfo( const QString& infor )
{
	ui->logcoll_label->setText(infor);
}


void SettingDetail::onClose(bool bret)
{
	ui->logcoll_label->setText("");
	LocalManWidget::onClose(bret);
}
