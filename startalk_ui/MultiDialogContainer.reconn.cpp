#include "MultiDialogContainer.h"
#include "ui_MultiDialogContainer.h"
#include <QMouseEvent>
#include <QXmppUtils.h>
#include <QImageReader>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QDesktopServices>
#include <QUrl>
#include "Session.h"
#include "Account.h"
#include "AccountData.h"
#include "ConfigureHelper.h"

#include "../LocalManBiz/SettingData.h"
#include "RecentItemView.h"
#include "LanguageHelper.h"

#include "GroupListData.h"
#include "Framework.h"
#include "SystemIcon.h"
#include "SettingDetail.h"
#include "createnewgroup.h"
#include "portraithelper.h"
#include "SystemDefine.h"
#include "CallbackReceiver.h"
#include "gloableeventobject.h"
#include "UiHelper.h"

#include "SystemConfigData.h"
#include "webview.h"
#include "UIFrame.h"
#include "NotifyCenterController.h"
#include "editablesettings.h"

void MultiDialogContainer::initTipPopBtn()
{
    ui->rightpanel->installEventFilter(this);

    m_pReconnectPushBtn = new QPushButton(this);
    m_pReconnectPushBtn->setFixedHeight(32);
    m_pReconnectPushBtn->setStyleSheet(
        "border:none;"
        "background-color:#DF8006;"
        "color:#FFFFFF;"
        );
    connect(m_pReconnectPushBtn,&QPushButton::clicked,[this](){ 
			this->onReconnect(false);
    });
    connect(Biz::Session::getLoginManager(),&Biz::LoginManager::sgConnected,this,&MultiDialogContainer::onLoginSuccess);
    connect(Biz::Session::getLoginManager(),&Biz::LoginManager::sgLoginFail,this,&MultiDialogContainer::onLoginFail);
	connect(Biz::Session::getLoginManager(), &Biz::LoginManager::sgServerPolicyViolationRelogin, this, &MultiDialogContainer::onServerPolicyViolationRelogin);
    // 计算显示位置
    m_pReconnectPushBtn->setVisible(false);
}



void MultiDialogContainer::onReconnetCount(int frame)
{
    int frameValue = 60-frame;
    m_pReconnectPushBtn->setText(QStringLiteral("与服务器连接断开\n%1秒后自动重连，点击立即重连").arg(frameValue));
    m_pReconnectPushBtn->setFixedWidth(ui->rightpanel->width());
    m_pReconnectPushBtn->move(0,this->height()-32); // 42是下部绝对高度
    m_pReconnectPushBtn->setVisible(true);
    m_pReconnectPushBtn->setEnabled(true);
	
    Log::e(QStringLiteral("与服务器连接断开\n%1秒后自动重连，点击立即重连").arg(frameValue));

    if (0 == frameValue)
    {
        onReconnect(true);
    }
}


void MultiDialogContainer::onDisconnect()
{
	//首先让界面上的图像变灰
    Log::e("MultiDialogContainer::onDisconnect");
    autoReConnTimer.start();
    disconnect(&Biz::Session::currentAccount(),&Biz::Account::sgNetworkAvailableChange,this,&MultiDialogContainer::onNetworkDisabled);

	disconnect(&Biz::Session::currentAccount(),&Biz::Account::sgNetworkAvailableChange,this,&MultiDialogContainer::onNetworkAvailabeChange);
    connect(&Biz::Session::currentAccount(),&Biz::Account::sgNetworkAvailableChange,this,&MultiDialogContainer::onNetworkAvailabeChange);

	disconnect(Biz::Session::getLoginManager(),&Biz::LoginManager::sgUpdateLoginInfo,this,&MultiDialogContainer::onReLoginFail);
	connect(Biz::Session::getLoginManager(),&Biz::LoginManager::sgUpdateLoginInfo,this,&MultiDialogContainer::onReLoginFail);
}

void MultiDialogContainer::onNetworkAvailabeChange(bool newState,bool oldState)
{
     Log::e("MultiDialogContainer::onNetworkAvailabeChange :" + QString::number(newState));
    if (newState)
    {
        onReconnect(true);
		SystemIcon::instance().onDisconnect();
    }
}

void MultiDialogContainer::onReconnect(bool autoConn)
{
	
    Log::e("MultiDialogContainer::onReconnect :" + QString::number(autoConn));
    isAutoReConnentWhenDisconnected = autoConn;

    if (!autoConn)
    {
        disconnect(&Biz::Session::currentAccount(),&Biz::Account::sgNetworkAvailableChange,this,&MultiDialogContainer::onNetworkAvailabeChange);
    }

    autoReConnTimer.stop();
    m_pReconnectPushBtn->setEnabled(false);
    bReConnected = true;
    m_pReconnectPushBtn->setText(QStringLiteral("重连中..."));

    emit sgReConnToServer(autoConn);
}



void MultiDialogContainer::onLoginSuccess()
{
    m_pReconnectPushBtn->setVisible(false);
    m_pReconnectPushBtn->setEnabled(true);

    autoReConnTimer.stop();
    isAutoReConnentWhenDisconnected = true;
    disconnect(&Biz::Session::currentAccount(),&Biz::Account::sgNetworkAvailableChange,this,&MultiDialogContainer::onNetworkAvailabeChange);
	disconnect(&Biz::Session::currentAccount(),&Biz::Account::sgNetworkAvailableChange,this,&MultiDialogContainer::onNetworkDisabled);
	connect(&Biz::Session::currentAccount(),&Biz::Account::sgNetworkAvailableChange,this,&MultiDialogContainer::onNetworkDisabled);
	
	disconnect(Biz::Session::getLoginManager(), &Biz::LoginManager::sghttpRespFail, this, &MultiDialogContainer::onhttpRespFail);
	connect(Biz::Session::getLoginManager(), &Biz::LoginManager::sghttpRespFail, this, &MultiDialogContainer::onhttpRespFail);
    if (NULL!=m_pWorkPlaceView)
    {
        QString url = Biz::Session::getSystemConfig ()->getHttpFileHost ()  + Biz::Session::getEditableSettings()->getworkplace();//"/ops/workspace/index.html";
        m_pWorkPlaceView->load (QUrl(url));
    }
    

}

void MultiDialogContainer::onLoginFail(int nMainError, int nSubError)
{
    if (nMainError!=QXmppClient::XmppStreamError && 
        isAutoReConnentWhenDisconnected && 
        QXmppStanza::Error::Condition::NoCondition == nSubError)
    {

        Log::e(QString("MultiDialogContainer::onLoginFail %1,%2.").arg(nMainError).arg(nSubError));
        emit Biz::Session::getLoginManager()->sgDisconnected();
        return;
    }
    QString errStr = MainApp::translateXmppError(nMainError,nSubError);
    m_pReconnectPushBtn->setText(errStr);
	
    m_pReconnectPushBtn->setFixedWidth(ui->rightpanel->width());
    m_pReconnectPushBtn->move(0,this->height()-32); // 42是下部绝对高度
    m_pReconnectPushBtn->setVisible(true);
    m_pReconnectPushBtn->setEnabled(true);
	Log::e(QString("MultiDialogContainer::onLoginFail msginfor: %1").arg(errStr));
}


void MultiDialogContainer::onNetworkDisabled( bool newstate,bool oldstate )
{
// 	if (!newstate)
// 	{
// 		Biz::Session::currentAccount().logout();
// 	}
}



void MultiDialogContainer::onReLoginFail( const QString&errormsg )
{
	
	m_pReconnectPushBtn->setText(QStringLiteral("重连中,网络异常故障，请退出重登"));
    m_pReconnectPushBtn->setEnabled(true);
    Log::e(QStringLiteral("MultiDialogContainer::onReLoginFail login fail on %1,show error %2").arg(errormsg).arg(QString::number(m_pReconnectPushBtn->isVisible())));
}

void MultiDialogContainer::onhttpRespFail()
{
	
	m_pReconnectPushBtn->setText(QStringLiteral("获取离线消息失败,建议点击此处,\n重连客户端,否则影响使用"));
	m_pReconnectPushBtn->setFixedWidth(ui->rightpanel->width());
	m_pReconnectPushBtn->move(0,this->height()-32); // 42是下部绝对高度
	m_pReconnectPushBtn->setVisible(true);
	m_pReconnectPushBtn->setEnabled(true);
 	Log::e(QString("onhttpRespFail "));


	//socket 主动的断开
	Biz::Session::getLoginManager()->doSignoutXmpp();

}

void MultiDialogContainer::onServerPolicyViolationRelogin( int nerror )
{
	if (nerror == QXmppStanza::Error::Condition::ServerSendPolicyViolationReloginFromNav 
		|| QXmppStanza::Error::Condition::ServerSendPolicyViolationRelogin)
	{
		m_pReconnectPushBtn->setText(QStringLiteral("与服务器连接断开\1秒后自动重连"));
		m_pReconnectPushBtn->setFixedWidth(ui->rightpanel->width());
		m_pReconnectPushBtn->move(0,this->height()-32); // 42是下部绝对高度
		m_pReconnectPushBtn->setVisible(true);
		m_pReconnectPushBtn->setEnabled(true);
	
		Log::e(QStringLiteral("与服务器主动踢人进行连接断开\n1秒后自动重连，点击立即重连"));

		
		onReconnect(true);
		
	}
}

