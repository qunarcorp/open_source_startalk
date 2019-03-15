#ifndef LOGINMANAGER_H
#define LOGINMANAGER_H

#include <QObject>
#include "managerbase.h"
#include "define.h"

class QXmppControlManager;
namespace Biz
{
    enum LoginStatus
    {
        LoginStatus_None=0,
        LoginStatus_Connect,
        LoginStatus_Disconnect
    };

    class LoginNavConfigInfo;
	

	class LoginManager : public ManagerBase
	{
	    Q_OBJECT
	
	public:
	    LoginManager();
	    ~LoginManager();
    public:
        virtual void initManager();
        virtual void unInitManager();
    public:
        inline LoginStatus getCurrentLoginStatus()const {return mLoginStatus;};
        inline bool isLogin(){return mLoginStatus == LoginStatus_Connect;};

    public:
		QString getNavConfig();
        void doSigninXmpp(Biz::UnitCallback<QSharedPointer<Biz::CheckVersionUpdate>>* versioncalback);
        void doSignoutXmpp();
        void startLogin();
        void getLoginToken();
		void startLoginWidthgetToken();
        void getLoginNav(GeneralCallback* callback);
		void getLoginNav(const QString&url, GeneralCallback* callback);
		void getOnlyLoginNav(const QString& url);

        // 判断是否是自动推送升级
        void checkAutoUpdate(const QSharedPointer<Biz::CheckVersionUpdate>& updataInfo );

        void getQVT(Biz::GeneralCallback* getQvtCallback); 
        
        quint64 getServerTimeWithOffset();
		void doErCodeInfoToServer(const QString&qrcodekey, Biz::UnitCallback<QString>* callback);
		void doErCodeInfoCancel(const QString&qrcodeKey, Biz::UnitCallback<bool>* callback);
		void doErCodeAuthInfo(const QString& qrcodeKey, int phase, Biz::UnitCallback<QString>* callback);
    protected:
        QString makeQVTParam();
        void loginWithToken();
		void getRsaKey(const QString& filePathName, int Type, GeneralCallback* callback );
	private:
        LoginStatus mLoginStatus;
		QXmppControlManager* pControlMgr;
signals:
		void sgzhuxiao();
		void sgLoginOut();
        void sgConnected();
        void sgDisconnected();
        void sgLoginStatusChange(LoginStatus oldstatus,LoginStatus newstatus);
        void sgLoginFail(int nFirstError, int nSecendError);
        void sgUpdateLoginInfo(const QString& errmsg);
		void sgServerPolicyViolation(int nError, const QString&reason);

        void sgLoginInfo(const QString& loginInfo);
        void sgVersionUpdated(const QSharedPointer<CheckVersionUpdate>& update, LoginParam loginPar);
        void sgCheckAutoUpdate(const QSharedPointer<Biz::CheckVersionUpdate>& pUpdateInfo,const QString& localPath);
        void sgWebLogin(); // 增强验证
		void sghttpRespFail(); //http 请求失败
		void sgLoginUpdate();
		void sgErCodeLogin();
		void sgResultInfor(const QString& strinfo);
		void sgAuthUserInfor(const QString&userurl, const QString&nickname );
		void sgServerPolicyViolationRelogin(int nError);
		public slots:
			void onConnected();
            void onDisconnected();
			void onKitOffline();
		
    };
}

#endif // LOGINMANAGER_H
