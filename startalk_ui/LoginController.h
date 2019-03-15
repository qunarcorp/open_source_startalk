#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H

#include "ControllerBase.h"

#include "define.h"
#include "ProgressDialog.h"


class WebLoginWidget;
class LoginDialog;
class LoginParamSettingDialog;
class ErCodeLoginWidget;
class NavManagerDialog;

namespace MainApp
{
	class LoginController : public ControllerBase
	{
		Q_OBJECT
	
	public:
	    LoginController();
	    ~LoginController();
    public:
        virtual void initController();
        virtual void unInitController();
    public:
		void doErCodeInfoCancel(const QString& qrcodekey);
		void doErCodeInfoToServer(const QString& qrcodekey);
		void showErCodeLoginDialog();
        void showWebLoginDialog();
        void showNormalLoginDialog();
        void showLoginParamSettingDialog();
        void preSignin();
        void signin();
		
		void setErrorTipsAtNormalLoginDialog(const QString& errMsg);
		
    public:
        void registLoginDialog(LoginDialog* pLoginDialog);
		void doGetAuthInfor(const QString&Key, int phase);
		void startLogin();
    private:
        void versionUpdateNotice(bool bForceUpdate,const QSharedPointer<Biz::CheckVersionUpdate>& versionPath);
	private:
		ErCodeLoginWidget*  m_pErCodeLoginDialog;
	    WebLoginWidget*     m_pWebLoginDialog;
        LoginDialog*        m_pLoginDialog;
        //LoginParamSettingDialog* m_pLoginParamSettingDialog;
		NavManagerDialog *m_pNavManagerDialog;
		QTimeLine mercodeTime;
        int m_loginReTryTiemLimited;
		QString mErcodeKey;
		QString mVersion;
		int mErcodeType;
        public slots:
            void onWebLogin();
            void onLoginSucceed();
            void onSystemTrayDbClieck();
            void onLoginFail(int nMainError, int nSubError);	
			void onErCodeLogin();
			void onLoginKitOut();
    };
}

#endif // LOGINCONTROLLER_H
