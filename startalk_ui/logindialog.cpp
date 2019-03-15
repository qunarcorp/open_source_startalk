#include "logindialog.h"
#include <QDesktopWidget>
#include "ui_logindialog.h"
#include "logindialog.h"
#include "LanguageHelper.h"
#include "Session.h"
#include "Account.h"
#include "AccountData.h"
#include "DealMessageBox.h"
#include "MainDialog.h"
#include "LogProcess.h"
#include "LogWriter.h"
#include "Updateinfordialog.h"
#include "SystemDefine.h"
#include "Framework.h"

#include "SystemIcon.h"
#include "StaticData.h"
#include "webloginwidget.h"
#include <QMouseEvent>

#include "gloableeventobject.h"
#include <QDesktopServices>
#include "loginmanager.h"
#include "accountmanager.h"
#include "QRCodeWidget.h"

#include "UIFrame.h"
#include "LoginController.h"
#include "advtoolbar.h"
#include "AdvData.h"
#include "UiHelper.h"
#include "ConfigureHelper.h"
#include "diywidgit/customviews/qframelayout.h"
#include "portraithelper.h"
#include "UserSettingData.h"
#include "FriendsSearcher.h"

#include "diywidgit/customviews/pinnedlistview.h"
#include "accountlistwidget.h"
#include <QMenu>
#include <QWidgetAction>
#include "SystemConfigData.h"

namespace Biz{
    class Account;
    class CallbackReceiver;
    class AdvDataItem;
}
#include "chattoolbar.h"
LoginDialog::LoginDialog(QWidget *parent)
    : LocalManDialog(parent)
	,ui(new Ui::LoginDialog)
	,m_pAccountListWidget(new AccountListWidget(this))
	/*,pbtnercode(new QPushButton())*/
{
    ui->setupUi(this);
    mReceiver = new Biz::CallbackReceiver(this);

    using namespace Qt;
    auto remove = WindowTitleHint;
    auto add = FramelessWindowHint | WindowMinMaxButtonsHint|Tool;
    setAttribute(Qt::WA_AlwaysShowToolTips, true);
    setAttribute(Qt::WA_TranslucentBackground, true);
    overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));

#ifdef QCHAT
    setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
#else
    setWindowIcon(QIcon(":/Images/Deal.ico"));
#endif
    setWindowTitle(T_("Application_Name"));


    auto titlebar = ui->titlebarWidget;
    titlebar->setSizeable(false);
    connect(titlebar, &TitlebarWidget::sgMinOnClicked, this, &LoginDialog::onMin);
    connect(titlebar, &TitlebarWidget::sgCloseOnClicked, this, &LoginDialog::onClose);

    dlg = new ProgressDialog(this);
#ifdef _WINDOWS
    LogProcess::Instance()->setHwnd((HWND)this->winId());
#endif

	 MainApp::UIFrame::getLoginController()->registLoginDialog(this);

	
    connect(Biz::Session::getLoginManager(), &Biz::LoginManager::sgUpdateLoginInfo, this, &LoginDialog::onUpdateLoginInfo);

   


    ui->username->setTextMargins(6,0,6,0);
    ui->password->setTextMargins(6,0,6,0);

    QString rem = T_("LoginWidget_Remember");


    ui->remember->setText(T_("LoginWidget_Remember"));
// 	QString strpwddesc = T_("login_rememberpw"); 
// 	ui->remember->setText(T_("login_rememberpw"));
    ui->autologin->setText(T_("LoginWidget_AutoLogin"));
// 	QString strautodesc = T_("login_auto"); 
// 	ui->autologin->setText(T_("login_auto"));
    ui->submit->setText(T_("LoginWidget_Submit"));
// 	QString strlogindesc = T_("login"); 
// 	ui->submit->setText(T_("login"));


    ui->loginpic->setIcon(QIcon(QPixmap(":/Images/defaultportrait.png")));

    connect(ui->submit, &QPushButton::clicked, this, &LoginDialog::onSubmit);
    connect(ui->autologin, &QCheckBox::stateChanged, this, &LoginDialog::onAutoLoginStateChanged);
    connect(ui->remember, &QCheckBox::stateChanged, this, &LoginDialog::onRememberStateChanged);

   

    connect(ui->username,&QLineEdit::textChanged,[this]{
        ui->password->clear();
    });

    ui->cbxPresence->setEditable(false);
    ui->cbxPresence->addItem(T_("Presence_online"));
    ui->cbxPresence->addItem(T_("Presence_away"));
    ui->cbxPresence->addItem(T_("Presence_busy"));
	//密码框不能输入中文
	QRegExp rx("^[^\u4e00-\u9fa5]*$/");
	ui->password->setValidator(new QRegExpValidator(rx, ui->password));

    Biz::Account* account = new Biz::Account("","");       
    Biz::Session::registerAccount(account);//
    Biz::Session::init();
    MainApp::UIFrame::initialize();

    QFrameLayout* pLayot = new QFrameLayout(ui->passwordPanel);
    pLayot->appendWidget(ui->password,ALINE_FILL);
    pLayot->appendWidget(ui->closeEye,ALINE_MATCHHEIGHT|ALINE_RIGHT);

	QFrameLayout*pUserLayout = new QFrameLayout(ui->usernamePanel);
	pUserLayout->appendWidget(ui->username, ALINE_FILL);
	pUserLayout->appendWidget(ui->select_account, ALINE_MATCHHEIGHT|ALINE_RIGHT);

    connect(ui->password,&QLineEdit::textChanged,[this]{
        ui->closeEye->setVisible(!ui->password->text().isEmpty());
        ui->closeEye->setChecked(false);
    });
    connect(ui->closeEye,&QPushButton::clicked,[this]{
		
        ui->password->setEchoMode(ui->closeEye->isChecked()?QLineEdit::Normal:QLineEdit::Password);
    });

	connect(ui->select_account, &QPushButton::clicked, [this](bool bret){
		ShowAccountListWidget(bret);
	});

    connect(Biz::Session::getLoginManager(),&Biz::LoginManager::sgLoginInfo,this,&LoginDialog::onLoginInfo);

    connect(ui->otherlogin,&QPushButton::clicked,[this]{
        emit Biz::Session::getLoginManager()->sgWebLogin();
    });

    connect(ui->loginsetting,&QPushButton::clicked,[this]{
        MainApp::UIFrame::getLoginController()->showLoginParamSettingDialog();
    });
	ui->loginsetting->setToolTip(QStringLiteral("服务器配置"));
#ifndef QCHAT
    ui->otherlogin->setVisible(false);
	ui->pbtercode->setVisible(false);
#endif // QCHAT

	//版本信息
	QString strVerinfo= QString("ver:%1").arg(Util::GLOBAL_INTERNAL_VERSION);
	ui->label_ver->setText(strVerinfo);
	ui->label_ver->setToolTip(strVerinfo);

    loadLastAccountItem();


    connect(Biz::Session::getLoginManager(), &Biz::LoginManager::sgConnected, this, &LoginDialog::onLoginSucceed);
    connect(Biz::Session::getLoginManager(), &Biz::LoginManager::sgLoginFail, this, &LoginDialog::onLoginFailure);
    connect(Biz::Session::getLoginManager(), &Biz::LoginManager::sgDisconnected, this, &LoginDialog::onDisconnect);

	connect(Biz::Session::getLoginManager(), &Biz::LoginManager::sgServerPolicyViolation, this, &LoginDialog::onServerPolicyVillation);

	disconnect(&Biz::Session::currentAccount(), &Biz::Account::SgProgressDisplay, this, &LoginDialog::onProgressDisplay );
	connect(&Biz::Session::currentAccount(), &Biz::Account::SgProgressDisplay, this, &LoginDialog::onProgressDisplay );

	ui->usernamePanel->installEventFilter(this);
	ui->username->installEventFilter(this);
	ui->password->installEventFilter(this);
	connect(m_pAccountListWidget, &AccountListWidget::sgAccountItemSelected, this, &LoginDialog::onAccountItemSelected);

	//这里放一个二维码的按钮
//	pbtnercode->setFixedSize(QSize(25, 25));
	//pbtnercode->setFlat(true);
	//pbtnercode->setVisible(true);
// 	pbtnercode->setStyleSheet(
// 		"QPushButton{border:none;border-image: url(:/Images/icon/ercode.png);}"
// 		"QPushButton:hover{border-image: url(:/Images/icon/ercode_hover.png);}");
// 	pbtnercode->setIcon(QIcon(":/Images/icon/ercode.png"));
//	pbtnercode->setText("按钮");
	//pbtnercode->show();
//	pbtnercode->setParent(ui->tippannel);

//	QFrameLayout* playout = new QFrameLayout(ui->tippannel);
//	playout->appendWidget (pbtnercode,ALINE_RIGHT|ALINE_BOTTOM/*,QMargins(0,0,25,0)*/);
	
	//
	connect(ui->pbtercode, &QPushButton::clicked, [this]{
		emit Biz::Session::getLoginManager()->sgErCodeLogin();
	});

	//
}

LoginDialog::~LoginDialog()
{
    delete ui;
    ui = NULL;
    qApp->quit();
}


void LoginDialog::onLoginSucceed()
{
    Biz::LogReporter r(QStringLiteral("登录成功，显示主界面"));

#ifdef _WINDOWS
#ifndef _DEBUG
#ifdef QCHAT
    QString mutexid = "QCHAT" + Biz::Session::currentAccount().accountData().UserID();
#else
    QString mutexid = "QTALK" + Biz::Session::currentAccount().accountData().UserID() + Biz::Session::getLoginManager()->getNavConfig();
#endif // QCHAT
	{ //清除已存在的句柄
		auto signalton = Framework::hMutex;
		if (NULL != signalton)
		{
			ReleaseMutex(signalton);
			CloseHandle(signalton);
			Framework::hMutex = NULL;
		}
	}

    HANDLE signalton = CreateMutex(NULL, FALSE,mutexid.toStdWString().c_str());
    Framework::hMutex = signalton;
    if(GetLastError() == ERROR_ALREADY_EXISTS && Util::checkOneProgress){
        updateLoginInfo(QStringLiteral("账户已经登录，不可重复登录"));

        return;
    }
#endif // !DEBUG
#endif

    onSuccess();
    this->close();
    emit sgLoginSuccess(Biz::Session::currentAccount().accountData().UserID());
    emit GloableEventObject::getInstance()->sgShowDeleteCatchMenu();
}

void LoginDialog::onLoginFailure(int nMainError,int nSubError)
{
	if (nSubError != QXmppStanza::Error::Condition::ServerSendPolicyViolation)
	{
		QString errStr = MainApp::translateXmppError(nMainError,nSubError);
		updateLoginInfo(errStr);
	}
   
}

void LoginDialog::onDisconnect()
{
    Log::e("LoginDialog::onDisconnect");
    Biz::Session::unregisterAccount();
}

void LoginDialog::onProgressDisplay(const qint64 done, const qint64 total)
{
    dlg->setRangeBar(done, total);
}

void LoginDialog::onAutoLoginStateChanged( int checkedStatus )
{
    if(checkedStatus == Qt::Checked){
        ui->autologin->setChecked(true);
        ui->remember->setEnabled(true);
    }
}

void LoginDialog::onRememberStateChanged( int checkedStatus )
{
    if(checkedStatus == Qt::Unchecked){
        ui->remember->setChecked(false);
        ui->autologin->setEnabled(false);
        ui->autologin->setChecked(false);

        ui->password->setText("");
        Biz::Session::getAccountManager()->accountData().savedPassword("");
    }
    else if (checkedStatus == Qt::Checked)
    {
        ui->remember->setChecked(true);
        ui->autologin->setEnabled(true);
    }

    Biz::Session::getAccountManager()->accountData().IsAutoLogin(ui->autologin->isChecked());
    Biz::Session::getAccountManager()->accountData().IsSaveAccount(ui->remember->isChecked());
    Biz::ConfigureHelper::saveAccount(Biz::Session::getAccountManager()->accountData());
}

void LoginDialog::onSubmit(bool)
{    
	quint64 getbegintickedtm =  QDateTime::currentMSecsSinceEpoch();
	Log().rt("login---"+QStringLiteral("点击登录按钮") + QString(" -------> begintime:%1").arg(getbegintickedtm));
	
    setLoginTip("",false);
    QString username = ui->username->text().toLower();
    QString psw = ui->password->text();

    if (Util::ENV_OPTION)
    {
        if (username.isEmpty() || psw.isEmpty())
        {
            MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("账号密码不能为空,请重新登录"));
            return;
        }
    }

    bool isrememeber = ui->remember->isChecked();
    bool isautologin = ui->autologin->isChecked();


    if (Biz::Session::getAccountManager()->accountData().LoginAccount() != username || Biz::Session::getAccountManager()->accountData().LoginPassword()!=psw)
    {
        // 时间赶，先写这样，大范围重置怕会有问题
        Biz::Session::getAccountManager()->getCurrentUserSettingData()->QCookie("");
        Biz::Session::getAccountManager()->getCurrentUserSettingData()->VCookie("");
        Biz::Session::getAccountManager()->getCurrentUserSettingData()->TCookie("");
        Biz::Session::getAccountManager()->getCurrentUserSettingData()->SCookie("");
        Biz::Session::getAccountManager()->getCurrentUserSettingData()->LoginToken("");
        Biz::Session::getAccountManager()->getCurrentUserSettingData()->LoginTokenUserName("");
    }


    Biz::Session::currentAccount().resetAccountInfo(username,psw,  isrememeber, isautologin);
    Biz::AccountData& ad = Biz::Session::getAccountManager()->accountData();
    ad.LoginAccount(username);
    ad.LoginPassword(psw);
    ad.IsSaveAccount(isrememeber);
    ad.IsAutoLogin(isautologin);
	ad.UserID(username);
    ad.Presence(ui->cbxPresence->currentIndex());

    ui->submit->setEnabled(false);
    ui->enablePanel->setEnabled(false);

    if (MainApp::checkMutex())
    {
        updateLoginInfo(QStringLiteral("账户已经登录，不可重复登录"));
    }
    else
    {
        MainApp::UIFrame::getLoginController()->preSignin();
    }
}

void LoginDialog::loadLastAccountItem()
{
    auto lastItem = Biz::Session::loadAccount();


    if(lastItem->LoginAccount().isEmpty()){
        delete lastItem;
        return;
    }
    mSaveVersion = lastItem->SaveVersion();

	if (lastItem->LoginAccount().contains("@"))
	{
		QString text = lastItem->LoginAccount();
		text = text.left(text.lastIndexOf(QChar('@')));
		ui->username->setText(text);
	}
    else
        ui->username->setText(lastItem->LoginAccount());

    ui->password->setText(lastItem->savedPassword());
    ui->remember->setChecked(lastItem->IsSaveAccount());
    ui->autologin->setChecked(lastItem->IsAutoLogin());


    QString lastId = Biz::Session::currentAccount().accountData().UserID();
    QPixmap header = Biz::PortraitHelper::getUserPortrait(lastId);
    QIcon icon;
    icon.addPixmap(header, QIcon::Normal, QIcon::Off);
    icon.addPixmap(header, QIcon::Disabled, QIcon::Off);
    ui->loginpic->setIcon(icon);

    if(ui->autologin->isChecked()){
        ui->submit->click();
    }
    delete lastItem;
    lastItem = NULL;
}

void LoginDialog::keyPressEvent( QKeyEvent* e)
{
    if(e->key() == Qt::Key_Enter  || e->key() ==  Qt::Key_Return)
    {
        ui->submit->click();
    }
	if (e->key() == Qt::Key_Escape)
	{
		if (m_pAccountListWidget->isVisible())
		{
			m_pAccountListWidget->hide();
		}
	}
    LocalManDialog::keyPressEvent(e);
}

bool LoginDialog::eventFilter( QObject *obj, QEvent *event )
{
	do 
	{
		if (obj == ui->username && m_pAccountListWidget->isVisible())
		{
			if(event->type() == QEvent::FocusOut)
			{
				if (!m_pAccountListWidget->isActiveWindow())
					m_pAccountListWidget->setVisible(false);
			}
// 			if (event->type() == QEvent::FocusIn)
// 			{
// 				callKeyBord();
// 			}
			break;
		}

	} while (false);
	 return LocalManDialog::eventFilter(obj, event);
}

void LoginDialog::mousePressEvent( QMouseEvent *event )
{
	if (m_pAccountListWidget->isVisible())
	{
		QPoint pt;
		pt.setX(event->x()) ;
		pt.setY(event->y()) ;
		QRect rect = ui->username->geometry();
		if (!rect.contains(pt))
		{
			m_pAccountListWidget->setVisible(false);
			ui->select_account->setIcon(QPixmap(":/Images/icon/commen/select_downhover.png"));
		}

	}
	LocalManDialog::mousePressEvent(event);
}

// void LoginDialog::showEvent( QShowEvent * )
// {
// 	pbtnercode->show();
// }


// void LoginDialog::moveEvent( QMoveEvent *event )
// {
// 	
// }

// void LoginDialog::mouseMoveEvent( QMouseEvent * event)
// {
// 	if (m_pAccountListWidget->isVisible())
// 	{
// 		QPoint editPos = ui->username->mapToGlobal(ui->username->pos());
// 		m_pAccountListWidget->move(editPos.rx()- ui->username->pos().rx(), editPos.ry() + ui->username->height() - ui->username->pos().ry());
// 	}
// 	LocalManDialog::mouseMoveEvent(event);
// }

void LoginDialog::onSuccess()
{
    ui->submit->setEnabled(true);
    ui->enablePanel->setEnabled(true);

    ui->username->setText(Biz::Session::getAccountManager()->accountData().LoginAccount());
    ui->password->setText(Biz::Session::getAccountManager()->accountData().LoginPassword());
    setLoginTip("",false);
}

// slot from Biz::LoginManager::sgUpdateLoginInfo
void LoginDialog::onUpdateLoginInfo( const QString& strmsg )
{
    QString strerrormsg = strmsg;
    if (strerrormsg.isEmpty())
    {
        strerrormsg = T_("ERROREXPLOR"); // 账号异常，请联系qunar
    }
    updateLoginInfo(strerrormsg);
}

void LoginDialog::updateLoginInfo(const QString& errString)
{
    setLoginTip(errString,true);
    ui->submit->setEnabled(true);
    ui->enablePanel->setEnabled(true);
}

// slot from Biz::LoginManager::sgLoginInfo
void LoginDialog::onLoginInfo(const QString& loginInfo)
{
    setLoginTip(loginInfo,false);
}

//选择的账号信息
void LoginDialog::onAccountItemSelected( const QSharedPointer<Biz::LoginAccountConfigInfo>& loginaccount )
{
	//选择后，让导航文件的时间为空
	Biz::Session::getLoginNavSetting ()->LastUpdataTime (0);
	Biz::Session::saveLoginNavSetting ();

	QString loginAccountId = loginaccount->LoginAccount();
	if (loginAccountId.contains("@"))
	{
		QString text = loginAccountId;
		text = text.left(text.lastIndexOf(QChar('@')));
		ui->username->setText(text);
	}
	//if(loginAccountId.contains("@"))
	//	ui->username->setText( Biz::MessageUtil::makeSureUserId(loginAccountId));
	else
		ui->username->setText(loginAccountId);

	ui->password->setText(loginaccount->savedPassword());
	ui->remember->setChecked(loginaccount->IsSaveAccount());
	ui->autologin->setChecked(loginaccount->IsAutoLogin());


	if (Biz::MessageUtil::makeSureUserDomain(loginAccountId) == "qtalk")
	{
		loginAccountId.replace("qtalk", Biz::Session::getSystemConfig()->getXmppDomain());
	}

	QPixmap header = Biz::PortraitHelper::getUserPortrait(loginAccountId);
	QIcon icon;
	icon.addPixmap(header, QIcon::Normal, QIcon::Off);
	icon.addPixmap(header, QIcon::Disabled, QIcon::Off);
	ui->loginpic->setIcon(icon);

	if(ui->autologin->isChecked()){
		ui->submit->click();
	}
	ui->select_account->setIcon(QPixmap(":/Images/icon/commen/select_downhover.png"));
	//导航地址给
	Biz::Session::currentAccount().accountData().NavAddr(loginaccount->NAVAddr());

	//选择不同的用户名， 展示谁的图片

}

void LoginDialog::resetLoginWidget()
{
    setLoginTip("",false);
}

void LoginDialog::setLoginTip(const QString& errString,bool bWarnign)
{
    QFontMetrics elidfont(ui->logininfo->font());
    QString shortStr = elidfont.elidedText (errString, Qt::ElideRight,qMax(300,ui->logininfo->width()) );
    QString errorText = shortStr;
    if(bWarnign && !errorText.isEmpty())
        errorText = QString("<span style=\"color:#DF8006;\">%1</span>").arg(shortStr);
    ui->logininfo->setText(errorText);
}

void LoginDialog::ShowAccountListWidget(bool bret)
{
	Biz::Session::loadLoginAccountConfigInfo();
	int ncount = Biz::Session::getLoginAccountConfigInfolist().size();
	if (ncount > 0)
	{
// 		if(bret)
// 		m_pAccountListWidget->setVisible(true);

		if (!m_pAccountListWidget->isVisible())
		{
			m_pAccountListWidget->setVisible(true);
			ui->select_account->setIcon(QPixmap(":/Images/icon/commen/select_up.png"));
		}
		else
		{
			m_pAccountListWidget->setVisible(false);
			ui->select_account->setIcon(QPixmap(":/Images/icon/commen/select_downhover.png"));
		}

		
		
		QRect rect = ui->username->geometry();
		m_pAccountListWidget->setList(Biz::Session::getLoginAccountConfigInfolist());
	
// 		m_pAccountListWidget->setItemSize(QSize(rect.width(),rect.height() -2));
// 		m_pAccountListWidget->setList(Biz::Session::getLoginAccountConfigInfolist());
		//m_pAccountListWidget->resize(QSize(ui->username->width(), ncount*(rect.height() - 2)));
		m_pAccountListWidget->setFixedHeight(ncount*(30+1));
		m_pAccountListWidget->setFixedWidth(ui->username->width());
 	
		QPoint editPos = ui->username->mapToGlobal(rect.bottomLeft());
		m_pAccountListWidget->move(editPos.rx(), editPos.ry() + 3);
		//m_pAccountListWidget->show();
		ui->username->activateWindow();
		ui->username->setFocus();       

		
	}
}

void LoginDialog::callKeyBord()
{
	//先判断系统是否有物理键盘



	//如果没有物理键盘，就调用软键盘
	QString strFile=tr("osk.exe");

	QProcess* pProcess=new QProcess(this);

	pProcess->startDetached(strFile);
}

void LoginDialog::onServerPolicyVillation( int nError, const QString& reason )
{
	//QString errStr = MainApp::translateXmppError(nMainError,nSubError);
	updateLoginInfo(reason);
}
