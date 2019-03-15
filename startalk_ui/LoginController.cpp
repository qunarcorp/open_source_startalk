#include "LoginController.h"
#include "webloginwidget.h"
#include "logindialog.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QDesktopServices>
#include <QCoreApplication>
#include "Session.h"
#include "loginmanager.h"
#include "Account.h"
#include "SystemIcon.h"
#include "LoginParamSettingDialog.h"


#include "UserSettingData.h"
#include "ConfigureHelper.h"
#include "accountmanager.h"

#include "Framework.h"
#include "SystemDefine.h"
#include "Updateinfordialog.h"


#include "ProgressDialog.h"
#include "StaticData.h"
#include "editablesettings.h"

#include "UIFrame.h"
#include "NotifyCenterController.h"
#include "ConfigureHelper.h"
#include "UiHelper.h"
#include "ercodeloginwidget.h"
#include "navmanagerdialog.h"

namespace MainApp
{
	LoginController::LoginController()
	    : ControllerBase(NULL)
        , m_pWebLoginDialog(NULL)
        , m_pLoginDialog(NULL)
        //, m_pLoginParamSettingDialog(NULL)
		,m_pNavManagerDialog(NULL)
        , m_loginReTryTiemLimited(1)
		, m_pErCodeLoginDialog(NULL)
	{
		mVersion = "1.0";
		mErcodeType = 1;
	    mercodeTime.setDuration(2*1000);
		connect(&mercodeTime,&QTimeLine::finished,[this](){
			mercodeTime.stop();

			doGetAuthInfor(mErcodeKey, mErcodeType);

		});
	}
	
	LoginController::~LoginController()
	{
	
	}

    void LoginController::initController()
    {
        connect(Biz::Session::getLoginManager(), &Biz::LoginManager::sgConnected, this, &LoginController::onLoginSucceed);
        connect(Biz::Session::getLoginManager(), &Biz::LoginManager::sgWebLogin,this,&LoginController::onWebLogin);
         connect(Biz::Session::getLoginManager(),&Biz::LoginManager::sgLoginFail,this,&LoginController::onLoginFail);
		 connect(Biz::Session::getLoginManager(), &Biz::LoginManager::sgErCodeLogin, this, &LoginController::onErCodeLogin);
		 connect(Biz::Session::getLoginManager(), &Biz::LoginManager::sgLoginOut, this, &LoginController::onLoginKitOut);
    }

    void LoginController::unInitController()
    {
    }

	void LoginController::registLoginDialog(LoginDialog* pLoginDialog)
    {
        m_pLoginDialog = pLoginDialog;
    }

	void LoginController::showWebLoginDialog()
    {
        if (NULL!=m_pLoginDialog)
        {
            m_pLoginDialog->hide();
        }
        if (NULL == m_pWebLoginDialog)
        {
            m_pWebLoginDialog = new WebLoginWidget;
        }
        m_pWebLoginDialog->show();

        disconnect(&SystemIcon::instance(), &SystemIcon::sgDoubleClick, this,&LoginController::onSystemTrayDbClieck);
        connect(&SystemIcon::instance(), &SystemIcon::sgDoubleClick, this,&LoginController::onSystemTrayDbClieck);

    }

    void LoginController::showNormalLoginDialog()
    {
        if (NULL!=m_pWebLoginDialog)
        {
            m_pWebLoginDialog->hide();
            m_pWebLoginDialog->deleteLater();
            m_pWebLoginDialog = NULL;
        }
		if (NULL != m_pErCodeLoginDialog)
		{
			m_pErCodeLoginDialog->hide();
			m_pErCodeLoginDialog->deleteLater();
			m_pErCodeLoginDialog = NULL;
		}
        if (NULL!=m_pLoginDialog)
        {
            m_pLoginDialog->show();
            m_pLoginDialog->activateWindow();
        }

        disconnect(&SystemIcon::instance(), &SystemIcon::sgDoubleClick, this,&LoginController::onSystemTrayDbClieck);
        connect(&SystemIcon::instance(), &SystemIcon::sgDoubleClick, this,&LoginController::onSystemTrayDbClieck);
    }

	void LoginController::setErrorTipsAtNormalLoginDialog(const QString& errMsg) { 
        if (NULL!=m_pLoginDialog)
        {
			m_pLoginDialog->setLoginTip(errMsg,true); 
        } 
	}

    void LoginController::onWebLogin()
    {
        showWebLoginDialog();
        if (NULL!=m_pLoginDialog)
        {
            m_pLoginDialog->resetLoginWidget();
        }
    }

    void LoginController::onLoginSucceed()
    {
        disconnect(&SystemIcon::instance(), &SystemIcon::sgDoubleClick, this,&LoginController::onSystemTrayDbClieck);

        if (NULL!=m_pWebLoginDialog)
        {
            m_pWebLoginDialog->hide();
            m_pWebLoginDialog->deleteLater();
            m_pWebLoginDialog = NULL;
        }
		if (NULL != m_pErCodeLoginDialog)
		{
			m_pErCodeLoginDialog->hide();
			m_pErCodeLoginDialog->deleteLater();
			m_pErCodeLoginDialog = NULL;
		}
        m_loginReTryTiemLimited = 1;
    }

    void LoginController::onSystemTrayDbClieck()
    {
        if (NULL!=m_pWebLoginDialog)
        {
            m_pWebLoginDialog->show();
            m_pWebLoginDialog->activateWindow();
            return;
        }

        if (NULL!=m_pLoginDialog)
        {
            m_pLoginDialog->show();
            m_pLoginDialog->activateWindow();
        }
    }

    void LoginController::showLoginParamSettingDialog()
    {
//         if (NULL == m_pLoginParamSettingDialog)
//         {
//             m_pLoginParamSettingDialog = new LoginParamSettingDialog(m_pLoginDialog);
//         }
//         QPoint pos = m_pLoginDialog->pos();
//         pos.setX(pos.x()+(m_pLoginDialog->width()-m_pLoginParamSettingDialog->width())/2);
//         pos.setY(pos.y()+(m_pLoginDialog->height()-m_pLoginParamSettingDialog->height())/2);
//         m_pLoginParamSettingDialog->autoshow(pos);

		if (NULL == m_pNavManagerDialog)
		{
			m_pNavManagerDialog = new NavManagerDialog(/*m_pLoginDialog*/);
		}
		
		m_pNavManagerDialog->showNavManagerDialog();

    }

    void LoginController::onLoginFail(int nMainError, int nSubError)
    {
        if (nMainError == QXmppClient::XmppStreamError)
        {
			Log::e(QString("LoginController::onLoginFail nMainError= %1").arg(nMainError));
            if (QXmppStanza::Error::Condition::FailurePolicyViolation == nSubError || QXmppStanza::Error::Condition::ServerSendPolicyViolation == nSubError)
            {
				Log::e(QString("LoginController::onLoginFail nSubError= %1").arg(nSubError));
                QSharedPointer<Biz::UserSettingData> spSetting =  Biz::Session::getAccountManager()->getCurrentUserSettingData();
                if (!spSetting.isNull())
                {
                    spSetting->LoginToken("");
                    Biz::ConfigureHelper::saveConfigureData(Biz::Session::getAccountManager()->accountData().UserID(),*spSetting.data());
                }
				Log::e("LoginController::onLoginFail() onLogout");

				
                MainApp::Framework::onLogout();
            }
			
			
            // 有几种情况会发生outofdate
            // 1 断线之后读秒过错中，其他客户端登陆导致本地token失效
            // 2 七天过后本地token失效
            // token失效之后尝试一次登陆，如果再失败则退出到登陆页
            if (QXmppStanza::Error::Condition::FailureOutOfDate == nSubError)
            {
				Log::e("LoginController::onLoginFail() QXmppStanza::Error::Condition::FailureOutOfDate == nSubError");
                if (m_loginReTryTiemLimited>0)
                {
                    m_loginReTryTiemLimited--;
					Log::e("LoginController::onLoginFail() m_loginReTryTiemLimited >0 ");
                    Biz::Session::getLoginManager()->startLoginWidthgetToken();
                }
                else
                {
					Log::e("LoginController::onLoginFail（） m_loginReTryTiemLimited <=0 ");
                    QSharedPointer<Biz::UserSettingData> spSetting =  Biz::Session::getAccountManager()->getCurrentUserSettingData();
                    if (!spSetting.isNull())
                    {
                        spSetting->LoginToken("");
                        Biz::ConfigureHelper::saveConfigureData(Biz::Session::getAccountManager()->accountData().UserID(),*spSetting.data());
                        MainApp::Framework::onLogout();
                    }
                }
                
            }

        }
    }

	void LoginController::signin()
    {
        if (Biz::Session::getEditableSettings ()->CancelVersionUpdate ())
        {
			//还是要去获取导航
			auto navCb = createCallback([this]{

				Biz::Session::getLoginManager()->startLogin();
				
			},[this]{

				Biz::Session::getLoginManager()->startLogin();
				Log::e (QStringLiteral("非版本更新获取导航失败"));
			});

			Biz::Session::getLoginManager()->getLoginNav(navCb);

            return;
        }

        auto onCheckUpdateFail = [this]{
            emit Biz::Session::getLoginManager()->sgUpdateLoginInfo(QStringLiteral("检查版本失败,请检查网络连接"));
            Log::e (QStringLiteral("检查版本失败,请检查网络连接"));
			if (!QApplication::activeModalWidget())
			{
				MainApp::UIFrame::getNotifyCenterController ()->alertMessage (QStringLiteral("检查版本失败,请检查网络连接"));
			}
            
        };

        auto onCheckUpdateSuccess = [this](const QSharedPointer<Biz::CheckVersionUpdate>& spInfo){
            Biz::Session::getAccountManager()->accountData().LastestVersion(spInfo->lastVersion.toInt());
			Biz::Session::getAccountManager()->accountData().MainChatVersion(spInfo->mainChatverno.toLongLong());

            do 
            {
                if (spInfo->forceUpdate)
                {
                    // 去提示0
                    versionUpdateNotice(true,spInfo);
                    break;
                }
                
                if (spInfo->Rerecommand)
                {
                    // 去提示1
                    versionUpdateNotice(false,spInfo);
                    break;
                }

                if (spInfo->recommand)
                {
                    if (Util::GLOBAL_INTERNAL_VERSION == Biz::Session::getAccountManager()->accountData().SaveVersion())
                    {
                         Log::e(QStringLiteral("已骚扰过一次，现在直接登录"));
                    }
                    else
                    {
                        // 去提示1
                        versionUpdateNotice(false,spInfo);
                        break;
                    }
                }

				Biz::Session::getLoginManager()->sgLoginUpdate();
                startLogin();
				
            } while (false);
            // do nothing
        };

        Biz::UnitCallback<QSharedPointer<Biz::CheckVersionUpdate>>* callback 
            = createCallback<QSharedPointer<Biz::CheckVersionUpdate>>(onCheckUpdateSuccess,onCheckUpdateFail);
        Biz::Session::getLoginManager()->doSigninXmpp(callback);
    }

	void LoginController::versionUpdateNotice(bool bForceUpdate,const QSharedPointer<Biz::CheckVersionUpdate>& update)
    {
        UpdateInforDialog box;
        box.setCheckVersionUpdate(update);
        box.setEditStringText(update->updateMessage);
        box.setButton(bForceUpdate ? UpdateInforDialog::MessageButton_Once :  UpdateInforDialog::MessageButton_Once | UpdateInforDialog::MessageButton_Later);
        box.show();
        box.move ((QApplication::desktop()->screenGeometry().width() - box.width()) / 2,
            (QApplication::desktop()->screenGeometry().height() - box.height()) / 2);
        box.setFixedSize( box.width (),box.height ());

        QString newVersionUrl = bForceUpdate?update->downloadUrl:update->betaurl;
        if (UpdateInforDialog::UpdateUserChoose::UpdateUserChooseOnce == box.exec())
        {
			
            quint64 lastversion = update->lastVersion.toULong();
            ProgressDialog* pDialog = m_pLoginDialog->getUpdateProgressDialog();
            if (NULL!=pDialog)
            {
				
                pDialog->show();
            }

            auto callback = createCallback<QString>(
                [bForceUpdate, this,pDialog](QString savepath){
                    pDialog->setSavePath(savepath);

            },[bForceUpdate,this]{
                ProgressDialog* pDialog = m_pLoginDialog->getUpdateProgressDialog();
                QString strdownloadhttp = Biz::Session::getEditableSettings()->SupportWeb();
                pDialog->hide();
                
                QString strTitleInfor = QStringLiteral("<h3>更新失败,请链接下行地址重新下载!\n\n<a href=\"%1\">%1</a></h3>").arg(strdownloadhttp);
                
                MainApp::UIFrame::getNotifyCenterController ()->alertMessage (strTitleInfor);
                QDesktopServices bs;
                bs.openUrl(QUrl(QString("%1").arg(strdownloadhttp)));
                return;
            });
            Biz::StaticData::reportTakeTimeEvent("90001",1,"DownloadNewFile");
            Biz::Session::currentAccount().downloadNewVersion(lastversion,newVersionUrl,update->md5,callback);

        }
        else
        {
            if (update->forceUpdate)
            {
                qApp->quit();
                return;
            }
            if (update->recommand)
            {
                //把当前的版本写到一个配置文件中
                Biz::Session::currentAccount().setAccountSaveVersion(Util::GLOBAL_INTERNAL_VERSION);
            }

            Log::e(QStringLiteral("拒绝版本更新，直接登录"));
			Biz::Session::getLoginManager()->sgLoginUpdate();
            Biz::Session::getLoginManager()->startLogin();
            return;
        }
    }

	void LoginController::preSignin()
    {
#ifndef QCHAT
        Biz::Session::getAccountManager()->resetCurrentUserData(Biz::Session::getAccountManager()->accountData().LoginAccount()); 
#endif // QCHAT
		 signin();
    }
	void LoginController::showErCodeLoginDialog()
	{
		if (NULL!=m_pLoginDialog)
		{
			m_pLoginDialog->hide();
		}
		if (NULL == m_pErCodeLoginDialog)
		{
			m_pErCodeLoginDialog = new ErCodeLoginWidget;
		}
		m_pErCodeLoginDialog->show();
		m_pErCodeLoginDialog->initErcode();

		disconnect(&SystemIcon::instance(), &SystemIcon::sgDoubleClick, this,&LoginController::onSystemTrayDbClieck);
		connect(&SystemIcon::instance(), &SystemIcon::sgDoubleClick, this,&LoginController::onSystemTrayDbClieck);
	}
	void LoginController::onErCodeLogin()
	{
		showErCodeLoginDialog();
		if (NULL!=m_pLoginDialog)
		{
			m_pLoginDialog->resetLoginWidget();
		}
	}


	void LoginController::doErCodeInfoToServer( const QString& qrcodekey )
	{
		if (qrcodekey.isEmpty())
		{
			return;
		}

		mErcodeKey = qrcodekey;

		auto ontoServerSuccess = [this](const  QString& retInfor){

			if(!retInfor.isEmpty())
			{
				if(retInfor.toInt() <=0)
				{
					emit Biz::Session::getLoginManager()->sgResultInfor(QStringLiteral("后台验证失败,请点击二维码进行刷新"));
				}
				else
				{
					//启动定时器进行调用服务器的接口
					mErcodeType = retInfor.toInt();
					mercodeTime.start();
				}
				
			}
			else
			{
				//报一个信息给界面
				emit Biz::Session::getLoginManager()->sgResultInfor(QStringLiteral("后台验证失败,请点击二维码进行刷新"));
			}
			
		};
		auto ontoSeverFail = [this]{
			//报一个信息出去dak
			emit Biz::Session::getLoginManager()->sgResultInfor(QStringLiteral("后台验证失败,请点击二维码进行刷新"));
		};


		Biz::UnitCallback<QString>* callback 
			= createCallback<QString>(ontoServerSuccess,ontoSeverFail);
		Biz::Session::getLoginManager()->doErCodeInfoToServer( qrcodekey,callback);


	}


	void LoginController::doErCodeInfoCancel( const QString& qrcodekey )
	{
		mercodeTime.stop();
		if (qrcodekey.isEmpty())
		{
			return;
		}


		auto ontoServerSuccess = [this](bool bret){

			if(bret)
			{
				
				Log::e(QStringLiteral("扫码框中的取消成功"));
			}
			else
			{
				
				Log::e(QStringLiteral("扫码框中的取消失败"));
			}

		};
		auto ontoSeverFail = [this]{
			
			Log::e(QStringLiteral("扫码框中的取消回调失败"));
		};


		Biz::UnitCallback<bool>* callback 
			= createCallback<bool>(ontoServerSuccess,ontoSeverFail);
		Biz::Session::getLoginManager()->doErCodeInfoCancel( qrcodekey,callback);
	}

	void LoginController::doGetAuthInfor( const QString&Key,int phase )
	{
		if (Key.isEmpty())
		{
			return;
		}

		auto ontoServerSuccess = [this](const QString& data){

			QVariantMap jsonMap = QJsonDocument::fromJson(data.toUtf8()).toVariant().toMap();
			QString strtvalue = jsonMap.value("t").toString();
			QString strvvalue = jsonMap.value("v").toString();
			if (strtvalue.compare("1") == 0) //认证成功
			{
				QString stradata = jsonMap.value("a").toString();
				QString strddata = jsonMap.value("d").toString();
				if (!stradata.isEmpty())
				{
					QString userheadimageurl = jsonMap.value("a").toString();
					QString usernick = jsonMap.value("u").toString();

					//调用新的接口继续
					mErcodeType = 2;
					doGetAuthInfor(mErcodeKey, mErcodeType);

					//紧接着需要把这个人的图像和id 传出去
					emit Biz::Session::getLoginManager()->sgAuthUserInfor(userheadimageurl, usernick);
					
				}
				else
				{

					QVariant datavar = jsonMap["d"];


					//这个时候认证成功了手机端点击了确认登录
					QVariantMap jsonMapdata = datavar.toMap();
					QString strq = jsonMapdata.value("q").toString();
					QString strv = jsonMapdata.value("v").toString();
					QString strt = jsonMapdata.value("t").toString();

					//
					QString userid = strq.mid(strq.indexOf("U.") + QString("U.").length());
					Biz::Session::getAccountManager()->resetCurrentUserData(userid);
					QSharedPointer<Biz::UserSettingData> spUserSetting = 
						Biz::Session::getAccountManager()->getCurrentUserSettingData();
					spUserSetting->VCookie(strv);
					spUserSetting->TCookie(strt);
					spUserSetting->QCookie(strq);
					spUserSetting->LoginTokenUserName(userid);


					if (!spUserSetting->QCookie().isEmpty() &&
						!spUserSetting->VCookie().isEmpty() &&
						!spUserSetting->TCookie().isEmpty() )
					{
						Biz::Session::getAccountManager()->setCurrentUserSettingData(spUserSetting);

						Biz::ConfigureHelper::saveConfigureData(Biz::Session::getAccountManager()->accountData().UserID(),*spUserSetting.data());
						Log::e("WebLoginWidget::chargeLoginCookies MainApp::UIFrame::getLoginController()->signin()");
						MainApp::UIFrame::getLoginController()->signin();
						
						//正在登录的一些信息传上界面
						Biz::Session::getLoginManager()->sgResultInfor(QStringLiteral("正在登录..."));
					}
					else
					{
						mercodeTime.stop();
						emit Biz::Session::getLoginManager()->sgResultInfor(QStringLiteral("后台验证失败,请点击二维码进行刷新"));
					}
				}
				
			}
			else if (strtvalue.compare("2") == 0) //二维码失效
			{
				//失效,发信号到界面
				emit Biz::Session::getLoginManager()->sgResultInfor(QStringLiteral("超时,请更新二维码后,重新扫码。"));
				mercodeTime.stop();
			}
			else if (strtvalue.compare("3") == 0) //还未认证
			{
				//继续循环
				mercodeTime.start();
			}

		};
		auto ontoSeverFail = [this]{
			//报一个信息出去
			mercodeTime.stop();
			emit Biz::Session::getLoginManager()->sgResultInfor(QStringLiteral("授权失败,请更新二维码后,重新扫码。"));
		};


		Biz::UnitCallback<QString>* callback 
			= createCallback<QString>(ontoServerSuccess,ontoSeverFail);
		Biz::Session::getLoginManager()->doErCodeAuthInfo( Key, phase,callback);

	}

	void LoginController::onLoginKitOut()
	{
		// Framework::onLogout(); // call MainWidget::doLogout delay
	}

	void LoginController::startLogin()
	{
#ifdef QCHAT
		//这个时候需要判断UserSettingData中的LoginTokenUserName的值于loginAccount是否一样，不一样则需要获取qvt
		QSharedPointer<Biz::UserSettingData> spData = Biz::Session::getAccountManager()->getCurrentUserSettingData();

		if (spData->QCookie().isEmpty() || 
			spData->VCookie().isEmpty() || 
			spData->TCookie().isEmpty() ||
			spData->LoginToken().isEmpty() ||
			spData->LoginTokenUserName().compare(Biz::Session::getAccountManager()->accountData().UserID()) != 0)
		{ //qvt或者token 不存在的情况

			if (MainApp::checkMutex())
			{
				Biz::Session::getLoginManager()->sgUpdateLoginInfo(QStringLiteral("账户已经登录，不可重复登录"));
				return;
			}

			//先要去获取导航，然后，进行qvt的请求，否则，如果先登录了beta 再次登录线上，那么获取导航肯定失败
			Log::e(QStringLiteral("LoginController::preSignin()需要重新拿qvt然后换token登录"));
			if (spData->QCookie().isEmpty() || 
				spData->VCookie().isEmpty() || 
				spData->TCookie().isEmpty() ||  spData->LoginTokenUserName().compare(Biz::Session::getAccountManager()->accountData().UserID()) != 0)
			{
				Biz::Session::getLoginManager()->startLoginWidthgetToken();
				return;
			}

			if (spData->LoginToken().isEmpty())
			{
				Biz::Session::getLoginManager()->getLoginToken();
				return;
			}
			
		}
		else // qvt 存在的情况，直接拿qvt 换token
		{
			// 直接登录
			Log::e(QStringLiteral("LoginController::preSignin()直接登录"));
			Biz::Session::getLoginManager()->startLogin();
		}
#else

		Biz::Session::getLoginManager()->startLogin();
#endif // QCHAT

	}
}
