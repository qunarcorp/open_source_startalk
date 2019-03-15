#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QList>
#include <QReadWriteLock>
#include "CoreObject.h"
#include "IXmlSerializeable.h"
#include "DispathThread.h"
#include "BizCallback.h"
#include "AsyncHandler.h"
#include "QXmppPresence.h"
#include "../QXmpp/custom/QXmppMucRoomListIq.h"
#include "../QXmpp/custom/QXmppMucRoomMemberIq.h"
#include "RosterList.h"
#include "define.h"
#include "QReadWriteLock"

#include "servicemanager.h"


namespace ApiResponse{
    class RosterProfile;
    class StatusItem;
}
namespace Biz
{
    class StatisticsItem;
    class AccountData;
    class AsyncRequest;
    class UserSettingData;
    class Client;
    class HttpService;
    class LvtuService;
    class RosterList;
    class Roster;
    class XmppMessage;
    class MessageListData;
    class SearchResultModule;
    class RoomVcard;
    class CallbackReceiver;
    class RosterItem;
    class GroupListData;
    class DAOParam4RecentBoddy;
    class ImSession;

    class EmotionPackageListModule;
    class RecordInfor;
    class RecordInforBegEndTmList;


    class EmotionPackageListModule;
    class RecordInfor;

    class CheckConfigInfo;
	class AdverConfigInfo;
    //跨线程对象，所有信号在主线程被触发
    class Account 
        : public ServiceManager
        , public IXmppService
        , public IoldService
    {
        Q_OBJECT
    public:
        virtual DispathThread* getLogicThread();
        virtual QThread* getMainThread();
        virtual IXmppService* getXmppService();
        virtual IHttpService* getHttpService();
        virtual IDaoService* getDaoService();
        virtual QXmppClient* getXmppClient();
        virtual IoldService* getOldService();
    public:
        virtual void    doLoginXmppService();
        virtual void    doLogoutXmppService();
		
    public:
        Account(const QString& loginAccount, const QString& loginPassword);
        ~Account();
        void logout();

        void SetRecordInfor(QList<Biz::RecordInfor>& infor);
        QList<Biz::RecordInfor> getRecordInfor();
        AccountData& accountData();
        QSharedPointer<Biz::UserSettingData> configureData();
		void setconfigureData(const QSharedPointer<Biz::UserSettingData>& usersettingdata);
        void resetAccountInfo(const QString& loginAccount, const QString& loginPassword, bool isrememeber=false, bool isautologin=false);
        void setAccountSaveVersion(quint64 ver);
        void setAccountData(AccountData*);
        void saveAccountData();
        void loadUserData();
		void doSendCancelFile(const QString&conversationId, bool bret);
       

        void doSendMessage(const QSharedPointer<Biz::XmppMessage>&, GeneralCallback* callback,GeneralCallback* presendcallback);
        void doSendTypingMessage(const QSharedPointer<Biz::XmppMessage>&, GeneralCallback* callback);

        void SetSystemMessageById(const QString& msgid, const QString& strTitle, int status);


        void getHistoryRecordMessageList(const QString& userId, int count, quint64 lasttime, UnitCallback<QSharedPointer<Biz::MessageListData>>* callback, int direction=0 );
        void getHistoryRecordContainsFind(const QString& userId, const QString& strfind,int nTotalCount, UnitCallback<Biz::RecordInforBegEndTmList>* callback);


        // 获取离线消息
        QSharedPointer<ApiResponse::RosterProfile> findUserByUserID(const QString& userID);

        void downloadNewVersion(const double version/*const int version*/,const QString& fileMd5,const QString& url,Biz::UnitCallback<QString>* callback);


        //更改群名字
        void setUpdateMucVCard(const QString& groupId,const QString& groupName, const QString& topic, UnitCallback<QString>* callback);
        void getUpdateMucVcard(const QString& groupId,UnitCallback<QVariantList>* callback);
        // 群设置相关
        inline GroupListData* getGroupsData() {return mGroupListData;};
        inline QSharedPointer<Biz::CheckConfigInfo> getCheckConfingInfo(){return mCheckConfigInfo;};
        inline void setCheckConfigInfo(const QSharedPointer<Biz::CheckConfigInfo>& spInfo){mCheckConfigInfo=spInfo;};
        void setPresence(int presence);
        void getRosterSuoxieList();
		void httpgeturlapi(const QString&url);
		//广告信息
		inline QSharedPointer<Biz::AdverConfigInfo> getAdvConfingInfo(){return mAdvConfigInfo;};
		inline void setAdvConfigInfo(const QSharedPointer<Biz::AdverConfigInfo>& spAdvInfo){mAdvConfigInfo=spAdvInfo;};


        // to move to manager 
        void updateAvatar(const QString& userId, const QString& localFile);
        


        //add liuhj 发送文件或者图片
        //void doCancelSend();
        void parseRousterInfo(const QVariantMap& rosterNode);
        void findRosterUsers(const QString& key, QList<RosterNode*>& result,bool accurate = false);
        void findRosterUsers(const QString& key, QStringList& result);

        QString getUserGroup(const QString& key);
        RosterGroup* findRosterGroup(const QString& key);
		RosterGroup* getRootRosterGroup();
        QString findChatRosterGroupNameById();
        RosterGroup* findChatRosterGroup(const QString& key);
        void  saveGroupListData();
        QString getGroupUIDByGroupName(const QString& groupName);

        // 搜索联系人顺便再群内搜索
        QString  exitsmyfile(const QString& strPath, const QString& filename, const QString&fileMd5);

        void downLoadVoiceAttachment(const QSharedPointer<XmppMessage>& msg);
        void onInitUserData(QMap<QString, QString> dataMap);
        QString getGroupNickName(const QString& jid);
        void onAddGroupNameItem(const QString& jid, const QString& name);
        //modify
        QString getUserIDByName(const QString& username);
        QString getUserNameById(const QString& id);
		QString getUserMarkNameByJId(const QString&jid);

        


        inline qint64 getTimeOffsetFromServer()
		{
			Log::e(QString("getTimeOffsetFromServer timeOffsetFromServer=%1").arg(timeOffsetFromServer));
			return timeOffsetFromServer;
		};
        inline void setTimeOffsetFromServer(quint64 serviceTime)
		{  
			Log::e(QString("setTimeOffsetFromServer serviceTime=%1, currentTime=%2").arg(serviceTime * 1000).arg(QDateTime::currentMSecsSinceEpoch()));
			timeOffsetFromServer = QDateTime::currentMSecsSinceEpoch()-serviceTime*1000;
			Log::e(QString("setTimeOffsetFromServer timeOffsetFromServer=%1").arg(timeOffsetFromServer));
		};
        void getMessagePeerIdList( Biz::UnitCallback< QList<Biz::RecordInfor> >* callback, const QString msg = "", const QString relationps="");


        // 异步升级
        void asyncCheckUpdate(bool bTestFlight);

        void getRecentlasttimByid(const QString& strgroupid, Biz::UnitCallback< quint64 >* callback);


       // void doCreateNewGroup(const QStringList& userlst,Biz::UnitCallback<QString>* callback);

        void onSavePersonInfor(const QString& str);

        void SetSelfInfor(const ImSelfPerson&seflInfor);
        void GetChatAllUserUins(QString&);
        QStringList GetChatRosterUins();


        void reportEvent(const QMap<QString,QVariant>& params);
        void logReportEvent(const QString& e,quint64 t);


        void DeleteGroupLstPathFile();
        void doGetGroupExternFlagbyJid(const QString& Jid, Biz::UnitCallback<int>* callback);

        void DeleteCatch();
		
    private:
        QList<Biz::RecordInfor> listRecord;
        // 保存 账户信息，账号密码
        AccountData* mAccountData;
        // 个人的配置信息
        QSharedPointer<Biz::UserSettingData> mConfigureData;
        GroupListData* mGroupListData;
        //广告信息
        QSharedPointer<Biz::AdverConfigInfo> mAdvConfigInfo;
        QSharedPointer<Biz::CheckConfigInfo> mCheckConfigInfo;
	

        QMap<QString, QSharedPointer<ApiResponse::RosterProfile>> mRosters;//暂时只存应答，如果需要序列化就转换一次对象
        //ClientThread
        DispathThread mBizThread;

        QThread* mMainthread;
        //xmpp服务
        Client* mClient;

        CallbackReceiver* mReceiver;
        QMap<QString, QString> mUsermap; // userid 2 username {wz.wang,王征wz}
        QMap<QString, QString> mUsermap2; // username 2 userid {王征wz,wz.wang}

        QSharedPointer<RosterGroup> spRootRosterGroup; // 组织架构 //  must thread safe
       

        // 服务器时间
        quint64 timeOffsetFromServer;
        QReadWriteLock dataLock;
        Qt::HANDLE m_MainThreadId;

        QStringList machinelist;

signals:
        void sgRosterListChanged(const QVariantList& rosterList);
        void sgUserFullNameChanged(const QString& fullName);
        void sgPresenceChanged(const QVariantList& presenceList);
        void sgFontSettingChanged();

        void sgRevokeMessage(const QSharedPointer<Biz::XmppMessage>& message);
        void sgMessageReceived(const QSharedPointer<XmppMessage>&, int count);
        void sgSystemMessageReceived(const QSharedPointer<XmppMessage>&);
        void sgGroupMessageReceived(const QSharedPointer<XmppMessage>&, int count);

        void sgOfflineMessageReceived(const QString& groupid,const QSharedPointer<Biz::MessageListData>& msgs);
        void sgTypingMessageReceived(const QSharedPointer<XmppMessage>& typing);

        //通知给界面的

        void sgClientUpdate(const QSharedPointer<CheckVersionUpdate>& updateinfo);
        void sgCheckUpdateBeta(const QSharedPointer<Biz::CheckVersionUpdate>& pUpdateInfo);
        
        //进行展示进度条的信号,用于报告下载升级包的。
        void SgProgressDisplay(const qint64 done, const qint64 total);
       


        //群的通知
        void sgGroupJoinStatusChanged(const QString& groupJid,bool);
        void sgRoomListReceived(const QXmppMucRoomListIq&);

        
        void sgRooLeaveReceived(const QString& jid);
        void sgMemberInvitedByOtherReceived(const QString& jid, const QString& userid,const QString& status);
        void sgRegistHotKey(const QString& hotkey, int ntype);
        void sgUnRegistHotkey(int ntype);

        void sgInitGroupNameList(QVariantList vcardList);

        
        void sgDisplayName();

        void sgInitUserData(QMap<QString,QString> userdatas);
        void sgAddGroupNameItem(const QString& jid, const QString& name);
        

        void sgChatWebInforClose(bool bret);
        void sgWebChatMessageReceived(const QString& chatid, const QString&strurl);
		void sgWebChatMessageReceivedEx(const QSharedPointer<XmppMessage>&);

        void sgPersonInfor(const QString& iq);
        void sgSaveInforResult(const QString&strRest);
        void sgCleanData();

        void sgWebChatEndReceived(const QString&struserid);
        void sgTransferChat(const QString& strid, const QString& strReson);
        void sgChatWebUpdateStatus(const QString& strid, bool bRet);
        void sgTransferResultInfor(const QSharedPointer<Biz::XmppMessage>& message);
		void sgTransferFailInfor(const QString&);
        void sgNetworkAvailableChange(bool newState,bool oldState);
        
		
        void sgMachineList(QVariantList machineList);
        void sgMachineListRecive(const QStringList &);

		//推送的广告信息
		void sgAdvPushMessageReceived();

		

        public slots:
                void onRosterListChanged(const QVariantList& rosterList);
                void onCleanData();
                void onMachineList(QVariantList machinelist);

    }; 
}

#endif // ACCOUNT_H
