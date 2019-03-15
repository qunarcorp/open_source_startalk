#ifndef PORTRAITMANAGER_H
#define PORTRAITMANAGER_H

#include <QObject>
#include "managerbase.h"
#include "RosterList.h"
#include "ParamObjects.h"

namespace Biz
{
	class WebUserInfo;
    class GroupMemberModule;
	class UserMoodInfo;
	class RoomVcard;

	struct DownloadInfo
	{
		DownloadInfo()
		{
			bHDPortrait = false;
			bIsGroup = false;
			bDownloading = false;
		}
		QString Portrait;
		QString PicUrl;
		bool bHDPortrait;
		bool bIsGroup;
		bool bDownloading;
	};

    class UserVcardManager : public ManagerBase
    {
        Q_OBJECT
		enum DOWNLOADTYPE
		{
			DOWNLOADTYPEBYFORCE,
			DOWNLOADTYPEBYVERSION,
			DOWNLOADTYPEBYVERSIONANDIMAGE,
		};
    public:
        UserVcardManager();
        ~UserVcardManager();
    public:
        virtual void initManager();
        virtual void unInitManager();
    public:
		void setAllUserVcard(QMap<QString, QSharedPointer<Biz::ImSelfPerson>> allvcardmap);
		QSharedPointer<Biz::ImSelfPerson> userVcard(const QString& jid);
        void uploadPortrait(const QString& filepath);
        void updatePortrait(const QString& uid);

        void updatePortrait(const QStringList& userids,Biz::UnitCallback< QList<QString> >*cb);
		//得到组织架构，最近联系人，好友的名片信息
		
        /*
         *	对象是否在线
         */
        bool isUserOnline(const QString& uid);

        /*
         *	定时获取全部在线人员
         */
        void getOnlineUsersOnTimer();

        /*
         *	及时获取在线成员
         */
        void getOnlineUsers(Biz::UnitCallback<QStringList>* callback);

        /*
         *	设置一个人为在线
         */
        void setUserOnline(const QString& uid);

		/*
		*   强制下载图片
		*/
		//这里需要强制的下载
		void getDomainUsersVcardByforce(const QStringList& userjids);

		//代收获取个人名片接口
		void getDomainCollectionUsersVcardByfore(const QStringList& userjids);

		//代收中获取群接口
		void getCollectionRoomVcardByfore(const QString& groupjid);

		//根据版本号获取本地图片的path
		void getDomainUsersVcardByVersion(const QString& userJid);

		/*
		*   根据version判断是否需要下载图片
		*/
		//原则是本地的版本号 >= 0 且 图片存在就不继续进行下载名片和图片了
		void getDomainUsersVcardByVersionandImage(const QStringList& userjids);

		/*
		*   群中根据version判断是否需要下载图片, 
		*/
		void getRoomVcardByVersion(const QString& groupJid);

		/*
		*   群中强制下载群名片和群图片, 
		*/
		void getRoomVcardByforce(const QString& groupJid);

		void getDomainRoomVcardFirst(const QSharedPointer<Biz::RoomVcardRequestParam> spParam);

        /*!
         * 功能 : 缓存临时的成员信息
         */
        void addUserVcard(const QSharedPointer<Biz::ImSelfPerson>& person,bool bSolidify = true);

        QString getUserNameByConversationId(const QString& conversationId);
		QString getWebChatNamebyuserid( const QString& userid );
		QString getWebChatIdbyuserName( const QString& userName );
		QString getSupplerNamebyuserid(const QString& userid);
		
		void getCityByIpAddr(const QString& strIp, Biz::UnitCallback< QString >*cb);

        void getGroupMemberOnline(const QString& groupJid, const QStringList& memberJids);

		//////以下是心情短语一下函数
		void getUserMoodInfobyId(const QString& userid);
		void getUserMoodInfo(const QString&, Biz::UnitCallback<QSharedPointer<Biz::UserMoodInfo>>* cb);
		void getUserMoodInfos(const QStringList&);
		void setUserMoodInfo(const QString& userid, const QString& moodinfo);
		
		
	private:
		//删除该图片目录下面的其他图片
		void DeleteOldImageFile(const QString& propert);
		//群列表的增加
		void addGrouplist(const QStringList&groupjids);
		//判断参数中的图片，是否存在，如果不存在，就下载图片
		void doRoomVcardImage(const QStringList& spParam);
		//直接在内存中获取，不用在一次的查询库表进行获取
		QMap<QString, int> getUsersVcardVersionbyAllRectVcard(QStringList userjids);
		void doDownloadParam(const QSharedPointer<Biz::ImSelfPerson>& spPerson, int downloadtype);
		void doDownloadInfo(const QList<QSharedPointer<Biz::ImSelfPerson>> spPerson, int Downloadtype, QMap<QString,int> mapversion);
		/*
         *	获取domain下的一组成员的名片
         */
		void getDomainUsersVcard(const QString& domain,const QStringList& userjids,bool bFroceGetPortrait=false);
		void getDomainUsersVcard(const QString& userjid,bool bFroceGetPortrait=false);
		//获取需要去server上取名片的userjids
		QStringList getNeedvcardUserJids(const QStringList&userjids);
		//在mAllRectUserInfo变量中查找没有的userids
		QStringList getidsfromAllRectUserInfo(const QStringList& usersJid);
		void DownloadImage();
		QList<Biz::UserVcardRequestParam> getUserVcardRequestParam(const QStringList& userJidlist);
		QList<QSharedPointer<Biz::RoomVcardRequestParam>> getRoomVcardRequestParam(const QStringList& groupJidlist);
		void InsertUserMoodInfoDB(const QList <QSharedPointer<Biz::UserMoodInfo>>&);
		void insertUservardDB(const QList <QSharedPointer<Biz::ImSelfPerson>>&);
        QStringList userVcardLocalCached(const QStringList& toRequest);
		void FailUpdateUserVcardDB(const QStringList& list);
		void FailUpdateRoomVcardDB(const QStringList& list);
		void getVersionByUserJid(const QString&userJid, Biz::UnitCallback< int >*cb);
       // 在线获取个人的资料信息
        void getDomainUserVcardInfo(
            const QString& domain,
            const QStringList& userjids,
            Biz::UnitCallback<QStringList>* callback);
		void getUserImageOnly(const QString& userjid,Biz::UnitCallback<QString>* cb);
		
    private:
        QStringList onlineUsers;
        QStringList offLineUsers;
		QMap<QString, QSharedPointer<Biz::ImSelfPerson>> mAllRectUserInfo;

		// 一下两个变量用于计算群头像，groupUserIds 存储某个群里的某个 id, currentGroupId 计算当前正在生成那个群的头像
		QMultiMap<QString,QString> mGroupUserIds;
		QStringList loadfailJids;

		//群名片的信息
		QMap<QString, QSharedPointer<Biz::RoomVcard>> mAllRectGroupInfo;
		//qchat中存放群里的群成员信息
		QMap<QString, QStringList> mGroupUsers;
		QStringList mGroupList; //群列表
		
		//这个里面存放的是 <userid, useridurlpic> 对下载进行管理，凡是要下载的都放到这里存放，下载完了的，进行删除
		QMap<QString, DownloadInfo> mPicDowloadUserIds; 

		
signals:
		void sgUserofCity(const QString& userid, const QString& city);
		void sgUserMoodInforChanged(const QString& userid, const QString& moodinfo);
        void sgPortraitUpdate(const QString& uid);
        void sgHDPortraitUpdate(const QString& uid);

        void sgOnlineUserChanged(const QStringList& userlst);
		void sgUseVcardChanged(const QStringList& userinforlist);
		void sgGroupHeaderUpdate(const QString& jid);
		void sgCalculateGroupHeader(const QString& groupid,const QStringList& userlist);
		void sgdownloadProgress(const QString&jid, qint64 done, qint64 total);
		public slots:
			void onConnected();
			void onGroupJoinSuccess(const QString& groupJid);
			
    };
}
#endif // PORTRAITMANAGER_H
