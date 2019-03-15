#include "encryptchatcontroller.h"
#include "Session.h"
#include "qcloudmanager.h"
#include "UserVcardManager.h"
#include "aescommon.h"
#include "Account.h"
#include "virtualaccountcontroller.h"
#include "UtilHelper.h"
#include "UIFrame.h"
#include "AccountData.h"
#include "SystemConfigData.h"
#include "virtualaccountmanager.h"
#include "NotifyCenterController.h"
#include "setpwdinfor.h"


namespace MainApp
{
	EncryptChatController::EncryptChatController()
		: ControllerBase(NULL)
		,m_EncryptChatdlg(NULL)
		, mReceiver(new Biz::CallbackReceiver(this))
	{

	}

	EncryptChatController::~EncryptChatController()
	{

	}

	void EncryptChatController::showEncryptChatDialog(const QString&conversationId)
	{
		if (m_EncryptChatdlg==NULL)
		{
			m_EncryptChatdlg = new EncryptChatDialog;
		}
		m_EncryptChatdlg->setConversationId(conversationId);
		m_EncryptChatdlg->show();
	}

	void EncryptChatController::initController()
	{

	}

	void EncryptChatController::unInitController()
	{

	}

	void EncryptChatController::doGetSubKey( const QString&MainKey, const QString&subkey, const QString&conversationId)
	{
		//m_bChatEncry = true;
		//主密码不为空的情况下，检查这个会话密码是否为空，
		auto subcallbacksuccess = [this,MainKey,conversationId,subkey](const QString& strsubKey)
		{
			//这地方为空的情况有2种，第一种确实为空，更本没和这人加密聊过，
			//第二种，拉取失败了，这个时候应该再次的全部拉取一次

			if (strsubKey.isEmpty())
			{
				
				//存放在服务器和本地
				QString strdesc = QStringLiteral("与%1的会话密码").arg(Biz::Session::getUserVcardManager()->getUserNameByConversationId(conversationId));
				Biz::Session::getqCloudManager()->setSaveqcloudSunInfo(conversationId, QStringLiteral("会话密码"), subkey, 100,NULL);
			}


		};
		auto subcallbackfail = []{};

		auto subcallback = mReceiver->createCallback<QString>(subcallbacksuccess, subcallbackfail);

		Biz::Session::getqCloudManager()->getqCloudSubKey(conversationId, subcallback);
	}

	void EncryptChatController::doCreateMainKey(const QString&subkey, const QString& conversationId)
	{
		if ( MainApp::UIFrame::getNotifyCenterController ()->alertMessage("",QStringLiteral("会话密码箱还没有创建,是否创建？")
			,QStringLiteral("取消"),QStringLiteral("创建")) )
		{
			setpwdInfor pwd;

			pwd.setFixedSize( pwd.width (),pwd.height ());
			pwd.showPwdInfor(0);
			if (pwd.exec() == setpwdInfor::ChooseOK)
			{
				QString strtitle = pwd.gettitle();
				QString strdesc = pwd.getdescription();
				QString strpwd = pwd.getpwd();
				//这里需要请求服务器了
				auto callback = mReceiver->createCallback<QString>([this,subkey, conversationId](const QString& bret)
				{
					QJsonDocument Json_Data = QJsonDocument::fromJson(bret.toUtf8());

					QVariantMap dataMap = Json_Data.toVariant().toMap();

					bool ret = dataMap["ret"].toBool();
					QString mainkey = dataMap["key"].toString();

					if(ret)
						//这里进行创建会话密码
							doGetSubKey(mainkey, subkey, conversationId);


				}, []{});

				Biz::Session::getqCloudManager()->setSaveqcloudMainInfo(strtitle, strdesc, strpwd,100, callback);
			}
			else
			{
				//ui->toolbar->SetChatEncrypt(false);
			}
		}
		else
		{
			//ui->toolbar->SetChatEncrypt(false);
		}
	}


}