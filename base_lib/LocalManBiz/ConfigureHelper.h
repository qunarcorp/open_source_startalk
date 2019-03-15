#ifndef CONFIGUREHELPER_H
#define CONFIGUREHELPER_H

#include "CoreObject.h"
#include "ISerializeable.h"
#include <QIcon>


namespace Biz
{
    class AccountData;
    class UserSettingData;
    class AccountList;
    class GroupListData;
    class SystemConfigData;
    class AllUserSettingData;
    class EmotionPackageListModule;
    class EditableSettings;
    class CheckConfigInfo;
    class ImSelfPerson;
    class LoginNavConfigInfo;
    class AdverConfigInfo;
    class DomainListInfo;
	class LoginAccountConfigInfo;
	class NavConfigInfo;
    class ConfigureHelper : public QObject
    {
    public:
        // 域列表存取
        static DomainListInfo* loadDomainListConfigData();
        static void saveDomainListConfigData(DomainListInfo& domainsinfo);

        //广告信息存取
        static AdverConfigInfo*loadAdvConfigureData(const QString&userID);
        static void saveAdvConfigureData(const QString& userID, AdverConfigInfo& adverconfig);


        // 获取配置信息
        static CheckConfigInfo* loadCheckConfigureData( const QString& userID );
        static void saveCheckConfigureData( const QString& userID, CheckConfigInfo& configure );

        // 获取登陆导航,多账户共享，同accountdata
        static LoginNavConfigInfo* loadNavConfigureData();
        static void saveNavConfigureData( LoginNavConfigInfo& configure );

		static void deleteNavConfigureFile();

		static void deleteRsaPubKey();


		//删除文件夹中的所有文件，不管后缀名了（只要是名称一样的，都必须给删掉）
		static void user_DeleteAllPortraitPath(const QString& userID, const QString& peerID);
		static void user_DeleteAllRawPortraitPath(const QString& userID, const QString& peerID);
        // 最近使用过的表情


        static QString getEmoticonsCachePath();
        static QString getUserSLPath(const QString& userID);
        static QString GetSettingConfigurePath();
        static QString QuickReplyListConfigurePath(const QString& userID);
        static QString user_DatabasePath(const QString&);
        static QString user_PortraitPath(const QString& userID, const QString& peerID, const QString& strsuffer="");
        static QString user_RawPortraitPath(const QString& userID, const QString& peerID, const QString& strsuffer="");
        static QString user_ImagesPath( const QString& userID);
        static void saveAccount(AccountData& accountData);
        static AccountData* loadAccountData();
        static void removeAccount();

        static QString ThemePath();

        static QString UserTempPath(const QString& userID);
        static QString SystemTempPath();

        static UserSettingData* loadConfigureData( const QString& userID );
        static void saveConfigureData( const QString& userID, UserSettingData& configure );

        static QString appVersionInfo();

        static void saveAccountList(AccountList& accountData);
        static AccountList* loadAccountList();

        static void saveGroupList( const QString& userID, GroupListData& accountList);
        static GroupListData* loadGroupList(const QString& userID);

        static void saveSystemConfig( SystemConfigData& config);
        static SystemConfigData* loadSystemConfig();
        static SystemConfigData* loadSystemConfig(bool bBeta);

        static AllUserSettingData* loadSettingConfig(int,int);
        static void saveSettingConfig( AllUserSettingData& configData);

        static EditableSettings* loadEditableSettings();
        static void saveEditSettings(EditableSettings& data);

        static QString getServerVersion();
        static void setServerVersion(const QString& ver);
        static QString GetBufferMD5(const QString& ver);
        static QString GetFileMD5(const QString& strfilePath);
        static bool IsPicFile(const QString& strfilePath);
        static QIcon GetFileIcon(const QString& file_name);

        static QString getLogsDir();
        static QString getRootDir();
        static QString getQunarDataDir();
        static QString getDeskWindowPath();
		static QString getRsaDataDir();

        static QString getOrginFromPath(const QString&path,QString&fileName,QString& strFileFiler);

        static void SaveEmotionList(const QString& userID, EmotionPackageListModule& emotionList);
        static EmotionPackageListModule *loadEmotionList(const QString& userID);
        static QString GetDebugOrReleasePath(const QString& path);

        static void DeleteGroupLstPathFile(const QString&UserID);
        static bool IsValidateEmail(const QString&stremail);
        static bool IsValidateMobile(const QString&strmobile);

        static QString getDisplayName(const QSharedPointer<Biz::ImSelfPerson>& person);
        static bool IsFullPathFileorImage(const QString& url);

        static QString getLocalSavePath(const QString & strLocalPath);

        static void parseLoginNavInfo(const QString& value, bool bret=false);

		static void parseLoginSecondNavInfo(const QString& value);


        static QString makeFullUrl(const QString& strUrl);

        static QString bubbleConfigPath(const QString& userID);

        static void removeNavFile();

		static QString getSufferfromImageUrl(const QString& url);

		static QString getImageLocalSavePath(const QString& url,const QString& conversationId);
		static QString getImageLocalSaveName(const QString& url);

		static bool IsValidFile(const QString&filePath); 

		static QList<QSharedPointer<Biz::LoginAccountConfigInfo>> loadLoginAccountConfigInforList(bool bEncrypt);
		static void saveLoginAccountConfigInforList(const QList<QSharedPointer<Biz::LoginAccountConfigInfo>>& loginAccountlist, bool bEncrypt);

		static QList<QSharedPointer<Biz::NavConfigInfo>> loadNavConfigInforList(bool bEncrypt);
		static void saveNavConfigInforList(const QList<QSharedPointer<Biz::NavConfigInfo>>& Navlist, bool bEncrypt);

		static void WirteFile(const QString& fileName, const QString& Path, const QString&content);

    private:
        static void innerSaveData(const QString& path, ISerializeable& ,bool bEncrypt=false);
        static void innerLoadData(const QString& path, ISerializeable** pData, bool bEncrypt = false);

        static QString mServerVersion;
		
		static QString getfileName( const QString& strfilename );
		//在文件夹中根据id查找该文件
		static QString getfileNameFromDir( const QString&userid, const QString& strfileDir);
		//获取该文件夹中的所有文件信息
		static QFileInfoList getFileListFromDir(const QString& strfileDir);
        
    }; 
}

#endif // CONFIGUREHELPER_H
