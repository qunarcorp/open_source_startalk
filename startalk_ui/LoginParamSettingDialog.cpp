#include "LoginParamSettingDialog.h"

#include <QtConcurrent/QtConcurrent>
#include "WebService.h"
#include "jsonobject/navigation.h"



#include "Session.h"
#include "SystemConfigData.h"
#include "AccountData.h"
#include "ConfigureHelper.h"

#include "ui_LoginParamSettingDialog.h"


#include "editablesettings.h"

#include "constants.h"
#include "accountmanager.h"
#include "loginmanager.h"
#include "navmanagerdialog.h"

LoginParamSettingDialog::LoginParamSettingDialog(QWidget *parent)
    : LocalManWidget(parent)
    , ui(new Ui::LoginParamSettingDialog())
{
    ui->setupUi(this);
     mReceiver = new Biz::CallbackReceiver(this);


    using namespace Qt;
    auto remove = WindowTitleHint;
    auto add = FramelessWindowHint | WindowMinMaxButtonsHint | Popup;
    setAttribute(Qt::WA_AlwaysShowToolTips, true);
    overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));
#ifdef QCHAT
    setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
#else
    setWindowIcon(QIcon(":/Images/Deal.ico"));
#endif

    auto titlebar = ui->titlebar;
    titlebar->setSizeable(false);
    connect(titlebar, &TitlebarWidget::sgMinOnClicked, this, &LocalManWidget::onMin);
    //connect(titlebar, &TitlebarWidget::sgCloseOnClicked, this, &LocalManWidget::onMin);

    connect(ui->apply,&QPushButton::clicked,this,&LoginParamSettingDialog::onApplyConfig);
    connect(ui->reset,&QPushButton::clicked,this,&LoginParamSettingDialog::onResetConfig);
    connect (ui->preview,&QPushButton::clicked,this,&LoginParamSettingDialog::onPreviewConfig);

    connect(ui->cb_betaenable   ,&QCheckBox::clicked,this,&LoginParamSettingDialog::onBetaEnableChanged);
    connect(ui->cb_pbenable     ,&QCheckBox::clicked,this,&LoginParamSettingDialog::onPbEnableChanged);

	connect(ui->pbt_NavManager, &QPushButton::clicked, this, &LoginParamSettingDialog::onNavManager);
    

    setPreViewVisible(false);
    ui->preview->setChecked(false);

	/////////////////////////////////////
	ui->widget_10->setVisible(false);
	ui->widget_11->setVisible(false);
	ui->reset->setVisible(false);
	ui->preview->setVisible(false);
	ui->pbt_NavManager->setVisible(false);
	 connect(titlebar, &TitlebarWidget::sgCloseOnClicked, this, &LoginParamSettingDialog::onLoginDialogClose);
}

LoginParamSettingDialog::~LoginParamSettingDialog()
{

}

void LoginParamSettingDialog::autoshow(QPoint point)
{
    initData();
    move(point);
    show();
    activateWindow();
}

void LoginParamSettingDialog::onApplyConfig(bool)
{
    // 如果变化导航了，强制刷新获取导航的时间，使登录过程获取导航
    QString curNav = ui->le_navurl->placeholderText();
    QString newNav = ui->le_navurl->text();
	int bbeta = false;
    if (!newNav.isEmpty () && 0 != newNav.compare (curNav))
    {
		Biz::Session::getAccountManager()->accountData().NavAddr(newNav);
    }

	
    if (ui->cb_pbenable->isChecked() != Biz::Session::getEditableSettings()->PbEnable())
    {
        Biz::Session::getEditableSettings()->PbEnable(ui->cb_pbenable->isChecked());
        Biz::ConfigureHelper::saveEditSettings(*Biz::Session::getEditableSettings());
    }

    if (ui->cb_betaenable->isChecked() != Biz::Session::getEditableSettings()->BetaEnvEnable())
    {
		bbeta = true;
        Biz::Session::getEditableSettings()->BetaEnvEnable(ui->cb_betaenable->isChecked());
        Biz::ConfigureHelper::saveEditSettings(*Biz::Session::getEditableSettings());
    }
	//只要点击了应用按钮，就应该拿导航
	Biz::Session::getLoginNavSetting ()->LastUpdataTime (0);
	Biz::Session::saveLoginNavSetting ();
	if (Biz::Session::getEditableSettings()->BetaEnvEnable() || bbeta)
	{
		_restart();
	}
	else
	{
		this->hide();
	}
	
    //_restart();
}

void LoginParamSettingDialog::onResetConfig(bool)
{
    if (Biz::Session::getEditableSettings()->PbEnable())
    {
        Biz::Session::getEditableSettings()->PbEnable(false);
        Biz::ConfigureHelper::saveEditSettings(*Biz::Session::getEditableSettings());
    }

    if (Biz::Session::getEditableSettings()->BetaEnvEnable())
    {
        Biz::Session::getEditableSettings()->BetaEnvEnable(false);
        Biz::ConfigureHelper::saveEditSettings(*Biz::Session::getEditableSettings());
    }

    _restart();
}

void LoginParamSettingDialog::initData()
{
	QString strhttpnav = Biz::Session::getLoginManager()->getNavConfig();
	
    ui->le_navurl->setPlaceholderText(strhttpnav);
	ui->le_navurl->setToolTip(strhttpnav);
    setPreViewVisible (false);
    ui->preview->setChecked(false);

    ui->le_domain->setText("");
    ui->le_filehost->setText("");
    ui->le_xmpphost->setText("");
    ui->le_xmppport->setText("");
    ui->le_httphost->setText("");

    ui->cb_betaenable->setChecked(Biz::Session::getEditableSettings()->BetaEnvEnable());
    ui->cb_pbenable->setChecked(Biz::Session::getEditableSettings()->PbEnable());
}

void LoginParamSettingDialog::onPbEnableChanged(bool)
{
}

void LoginParamSettingDialog::onBetaEnableChanged(bool)
{
   
}

void LoginParamSettingDialog::_restart()
{
#ifdef _WINDOWS
	QProcess::startDetached(qApp->applicationFilePath(), QStringList()); 
	
	QCoreApplication::exit(0);
	
#else
	QProcess::startDetached(qApp->applicationFilePath(), QStringList()); 
	QTimeLine* pTimeLine = new QTimeLine(1000);
	connect(pTimeLine,&QTimeLine::finished,[pTimeLine,this]{
		pTimeLine->deleteLater();
		//QCoreApplication::exit(0);
		qApp->quit();
	});
	pTimeLine->start();
#endif 

   
}

void LoginParamSettingDialog::setPreViewVisible(bool visible)
{
    ui->previews->setVisible(visible);
    int height = visible? 286 : 146;
    
    ui->content->setFixedHeight(height);
    this->setFixedHeight (ui->content->height()+28);
}

void LoginParamSettingDialog::onPreviewConfig(bool)
{
    // 如果是变为可见，那么就重新请求一下nav

/*    ui->le_domain->setText("");
    ui->le_filehost->setText("");
    ui->le_xmpphost->setText("");
    ui->le_xmppport->setText("");
    ui->le_httphost->setText("");
    setPreViewVisible (ui->preview->isChecked());

    if (ui->preview->isChecked())
    {
        auto navCb = mReceiver->createCallback<QString>([this](const QString& navValue){

            Biz::Navigation navData(NULL);
            navData.unserializeFromString (navValue);

            if (NULL != navData.baseaddess ())
            {
                Biz::BaseaddessNode* pbn = (Biz::BaseaddessNode*)navData.baseaddess ();
                ui->le_xmpphost->setText(pbn->xmpp ());
                ui->le_xmppport->setText(QString::number (pbn->xmppport ()));
                ui->le_domain->setText(pbn->domain ());
                ui->le_httphost->setText(pbn->apiurl ());
                ui->le_filehost->setText(pbn->fileurl ());
            }


        },[this]{

        });
        QtConcurrent::run(WebService::getLoginNav,navCb);
    }*/
}

void LoginParamSettingDialog::onNavManager( bool bret)
{
// 	NavManagerDialog *pnavdialog = NavManagerDialogSingleton::getInstance();
// 	if (pnavdialog)
// 	{
// 		pnavdialog->showNormal();
// 	}
}

void LoginParamSettingDialog::onLoginDialogClose( bool )
{
	this->close();
}
