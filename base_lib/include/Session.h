#ifndef SESSION_H
#define SESSION_H
#include "CoreObject.h"
#include "servicemanager.h"

namespace Biz
{
	class VidioAndAudioManager;
    class AsyncCallback;
    class XmppMessage;
	class Account;
    class AccountData;
    class AsyncRequest;
    class SystemConfigData;
    class AllUserSettingData;
    class EditableSettings;
    class LoginNavConfigInfo;

    class UserVcardManager;
	class RobotManager;
    class AccountManager;
	class FriendsManager;
	class LoginManager;
    class GroupManager;
	class AttachmentManager;

    class EmotionManager;
    class DownloadManager;
	class ConverSationManager;
    class PersonCfgManager;
	class AdvInforManager;
    class StaffManager;
    class MessageManager;
	class virtualAccountManager;
	class keyManager;
	class portraitManager;
	class LoginAccountConfigInfo;
	class qCloudManager;
	class NavConfigInfo;
	class Session
	{
    public:
        static AccountData* loadAccount();

        static void registerAccount(Account*);
        static void unregisterAccount();

        static Account& currentAccount();
		static void Dispose();
        
        static void loadSystemConfig();
        static SystemConfigData* getSystemConfig();
		static void saveSystemConfig();
        
        static void loadSettingConfig(int,int);
        static void saveSettingConfig();
        static AllUserSettingData* getSettingConfig();

        static void loadEditableSettings();
        static void saveEditableSettings();
        static EditableSettings* getEditableSettings();

        static void loadLoginNavSetting();
        static void saveLoginNavSetting();
        static LoginNavConfigInfo* getLoginNavSetting();
	    static ServiceManager*      getServiceManager();
        static UserVcardManager*    getUserVcardManager();
		static RobotManager*        getRobotManager();
        static AccountManager*      getAccountManager();
		static FriendsManager *     getFriendManager();
		static LoginManager*	    getLoginManager();
        static GroupManager*        getGroupManager();
		static AttachmentManager*   getAttachmentManager();
        static EmotionManager*      getEmoticonManager();
        static DownloadManager*     getDownLoadManager();

		static ConverSationManager* getConverSationManager();
        static PersonCfgManager*    getPersonCfgManager();
		static AdvInforManager*     getAdvInforManager();
        static StaffManager*        getStaffManager();
        static MessageManager*      getMessageManager();
		static VidioAndAudioManager*getVidioAndAudioManager();
		static virtualAccountManager* getVirtualManager();
		static keyManager * getkeyManager();
		static portraitManager*getPortraitManager();
		static qCloudManager*getqCloudManager();
        static void init();
		static void loadLoginAccountConfigInfo();
		static void saveLoginAccountConfigInfo(const QList <QSharedPointer <Biz::LoginAccountConfigInfo>>& list);
		static QList <QSharedPointer <Biz::LoginAccountConfigInfo>> getLoginAccountConfigInfolist();
		
		static void loadNavConfigListInfo();
		static void saveNavConfigListInfo(const QList <QSharedPointer <Biz::NavConfigInfo>>& list);
		static QList <QSharedPointer <Biz::NavConfigInfo>> getNavConfigInfolist();

    private:
        static SystemConfigData*    m_pConfigData;

        static EditableSettings*    m_pEditableSettings;
        static AllUserSettingData*  m_pSettingData;

        static LoginNavConfigInfo*  m_pLoginNavConfig;

		static QList <QSharedPointer <Biz::LoginAccountConfigInfo>> m_LoginAccountlist;

		static QList <QSharedPointer <Biz::NavConfigInfo>> m_NavList;

	}; 
}

#endif // SESSION_H
