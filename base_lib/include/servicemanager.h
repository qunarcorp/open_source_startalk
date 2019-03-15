#ifndef SERVICEMANAGER_H
#define SERVICEMANAGER_H

#include <QObject>
#include <QDir>
#include <QPair>
#include "managerbase.h"
#include "DispathThread.h"
#include "QXmppClient.h"
#include "XmppMessage.h"
#include "friendsmanager.h"
#include "CustomDefine.h"

namespace Biz {
    class IXmppService;

    class IHttpService;

    class IDaoService;

    class XmppMessage;

    class MessageListData;

    class RobotVcard;

    class IoldService;

    class ImSelfPerson;

    class ImSession;

    class GroupMemberModule;

    class qclude_mainInfor;

    class qclude_subInfor;
	
    class QuickReplyGroup;
    class QuickReplyContent; 

    class ServiceManager : public ManagerBase {
    Q_OBJECT

    public:
        ServiceManager(QObject *parent);

        ~ServiceManager();

        virtual void initManager();

        virtual void unInitManager();

    public:
        virtual DispathThread *getLogicThread()    = 0;

        virtual QThread *getMainThread()     = 0;

        virtual IXmppService *getXmppService()    = 0;

        virtual IHttpService *getHttpService()    = 0;

        virtual IDaoService *getDaoService()     = 0;

        virtual QXmppClient *getXmppClient()     = 0;

        // 下面这个在重构完成之后需要干掉 [12/16/2015 wz.wang]
        virtual IoldService *getOldService()     = 0;
    };

    class IXmppService {
    public :
        virtual void doSendMessage(const QSharedPointer<Biz::XmppMessage> &msg, Biz::GeneralCallback *callback,
                                   Biz::GeneralCallback *presendcallback) = 0;
    };

    class IHttpService {
    public :
        virtual void
        uploadFileWithCheck(const QString &filepath, Biz::ProgressedUnitCallback<QString, quint64> *callback) = 0;

        virtual void
        uploadImageWithCheck(const QString &filepath, Biz::ProgressedUnitCallback<QString, quint64> *callback) = 0;

        virtual void getDownloadFile(const QString &urlimage, const QDir &idr, const QString &filename,
                                     Biz::ProgressedUnitCallback<QString, qint64> *callback) = 0;

        virtual void getOnlineUsers(Biz::UnitCallback<QStringList> *callback) = 0;

        virtual void
        updateMucVcard(const QString &muc_name, const QString &nickName, const QString &subject, const QString &desc,
                       const QString &picUrl,
                       Biz::UnitCallback<QVariantList> *callback, bool flage = true) = 0;

        virtual void setChatSelfInfo(const QString &strUserInfor, Biz::UnitCallback<QString> *callback) = 0;

        virtual void getCityByIpaddr(const QString &strIpaddr, Biz::UnitCallback<QString> *callback) = 0;

        virtual void getProductionInfo(const QString &strProductId, const QString &businessid,
                                       Biz::UnitCallback<QVariantMap> *callback) = 0;

        virtual QString getTkey() = 0;

        virtual QString getUser() = 0;

        virtual void setCancelSend(const QString &messageid) = 0;
    };


    class IoldService {
    public :
        virtual void doLoginXmppService() = 0;

        virtual void doLogoutXmppService() = 0;

        virtual void downloadNewVersion(const double version, const QString &url, const QString &fileMd5,
                                        Biz::UnitCallback<QString> *callback) = 0;

        virtual QString getUserNameById(const QString &id) = 0;
    };

    enum SessionSaveType {
        SESSION_RECENT = 0x1,
        SESSION_CHATING = 0x2,
        SESSION_LOCAL = 0x4
    };

    class IDaoService {
    public :

        // 消息
        virtual QSharedPointer<Biz::MessageListData>
        getCollectionMessages(const QString &parentid, const QString &peerID, quint64 lastTime, int count) = 0;

        virtual QSharedPointer<Biz::MessageListData> getMessages(const QString &, quint64, int) = 0;

        virtual QSharedPointer<Biz::MessageListData>
        getMessagebetweenId(const QString &conversationId, const QString &atmsgid, const QString &firstmsgid) = 0;

        virtual QSharedPointer<Biz::MessageListData> getAllFileMessage(const QString &conversationId) = 0;

        virtual QSharedPointer<Biz::MessageListData> getAllUnreadMessage(const QString &conversationId) = 0;

        virtual QSharedPointer<Biz::MessageListData> getAllUnreadMessageFromOther(const QString &conversationID) = 0;

        virtual QSharedPointer<Biz::MessageListData> getMessageListByIds(const QStringList &ids) = 0;

        virtual QSharedPointer<Biz::MessageListData> getSystemMsgbyMsgType(const QStringList &typelist, quint64 tm) =0;

        virtual QSharedPointer<Biz::MessageListData> getAllUnSetRecviedMessage() = 0;

        virtual QSharedPointer<Biz::XmppMessage> getMessageById(const QString &msgid)= 0;

        virtual QSharedPointer<Biz::XmppMessage>
        getLastUnreadMessage(bool bWithNotice, bool bTopMost, quint64 timestamp) = 0;

        virtual QSharedPointer<Biz::MessageListData>
        getGroupMsgFilter(const QString &groupjid, const QStringList &ids, int count) =0;

        virtual QSharedPointer<Biz::MessageListData>
        getGroupMsgAtFilter(const QString &groupjid, const QStringList &msgids) = 0;

        virtual QStringList getSystemMsgType() = 0;


        virtual int getSystemMsgTableRecordCount() = 0;

        virtual void getGroupLasttime(quint64 &lasttime) = 0;

        virtual void removeDeletedInGrouopMembers(const QStringList &groupids) = 0;

        virtual void updateSystemMessageById(const QString &msgid, int status) = 0;

        virtual void updateWebInfo(const QString &userid, const QString &city) = 0;

        virtual void updateRoomVcardInforbyDomain(const QSharedPointer<Biz::RoomVcard> &onerome, bool bret = false) = 0;

        virtual void insertMessageAttachment(const QSharedPointer<Biz::XmppMessageAttachment> &xma) = 0;

        virtual void
        getMessageAttchment(const QString &url, QList<QSharedPointer<Biz::XmppMessageAttachment>> &retlist) = 0;

        virtual void getAllMessageAttchment(QList<QSharedPointer<Biz::XmppMessageAttachment>> &retlist) = 0;

        virtual QMap<QString, QList<QSharedPointer<Biz::RoomVcard>>> getRoomVcardInforByDomain() = 0;

// 		virtual QSharedPointer<Biz::AttachMentInfo> getAttachInfoByUrl( const QString& Name ) = 0;
// 		virtual void insertAttachInfo(const QList <QSharedPointer<Biz::AttachMentInfo>>& Attachinforlist) = 0;
// 		virtual void insertAttachInfo(const QSharedPointer<Biz::AttachMentInfo>& Attachinfor) = 0;
        virtual void insertChatInfo(const QList<QSharedPointer<Biz::ImSelfPerson>> &userinfor) = 0;

        virtual void DoFailUpdateVcardVersion(const QStringList &userJidlist) = 0;

        virtual QStringList getFailUpdateVcardUserIds() = 0;

        virtual void DoFailUpdateRoomVcardVersion(const QStringList &groupJidlist) = 0;

        virtual void checkoutRecentImSessions(QList<ImSession> &paramlst, int savetypefilter) = 0;

        virtual void checkoutRecentImSessionsWithoutMessage(QList<ImSession> &sessions) = 0;
		
		virtual int getSessionChatByConversationId(const QString &jid) = 0;

        virtual void insertRecentImSession(const ImSession &param, int savetypefilter = SESSION_CHATING | SESSION_RECENT) = 0;

        virtual void removeSaveTypeImSession(const QString &jid, int satetype) = 0;


        //插入web用户信息到表数据库中
        virtual QString IsWebDisplayInWebInfo(const QString &userid) = 0;

        virtual void insertWebUserInfo(const WebUserInfo &webuserinfo) = 0;

        virtual void insertChatMessage(const XmppMessage &msg, bool bReplace = false) = 0;

        virtual void insertChatMessage(const QSharedPointer<Biz::MessageListData> &xmppMessages) = 0;

        virtual void setAllMessageRead(quint64 lsttm) = 0;

        virtual void setSystemMessageById(const QString &msgid, const QString &strTitle, int status = 0) = 0;

        virtual void saveRoomVcardInfos(const QList<QSharedPointer<Biz::RoomVcard>> &roomvcards) = 0;

        virtual quint64 getLastMsgTime() = 0;

        virtual quint64 getLastMsgTime(const QString &userid) = 0;

        virtual void getMessageIdbyUserid(const QString &userid, QStringList &listmsgid) = 0;

        virtual void deleleConversationMessage(const QString &conversaionid) = 0;

        virtual bool isMessageIdExist(const QString &msgId) = 0;

        virtual QSharedPointer<Biz::XmppMessage> getRectentMessageByConversationId(const QString &jid)=0;

        virtual QSharedPointer<Biz::MessageListData> getRectentListLastMessage(int savetypefilter)= 0;

        /*
         *	好友
         */
        virtual void DeleteAllFriend() = 0;

        virtual QStringList getAllFriendsuis() = 0;

        virtual quint64 getNotelastmsgtm(const QString &userid) = 0;


        /*
         *	群会话
         */
        virtual void deleteRoomVcard(const QString &roomid) = 0;

        virtual QMap<QString, int> getUsersVcardVersion(const QStringList &userjid) = 0;

        virtual void getWebChatIdAndName(QMap<QString, QSharedPointer<Biz::ImSelfPerson>> &) = 0;

        virtual QList<QSharedPointer<Biz::RoomVcard>> getRoomVcardInfos(const QStringList &ids) = 0;

        virtual QMap<QString, QSharedPointer<Biz::RoomVcard>> getRoomVcardInfosbyIds(const QStringList &ids)=0;

        virtual QStringList getFailUpdateVcardRoomIds() = 0;

        virtual QMap<QString, int> getGroupMenberMsgCount(const QString &groupjid)=0;

        virtual QMap<QString, quint64> getGroupsEarliestUnradMessageTime() = 0;

        /*
         *	扩展会话列表
         */
        virtual QString getBelongExtendId(const QString &peerid) = 0;

        virtual QStringList getExtendPath(const QString &peerid) = 0;

        virtual void insertExtends(const QStringList &list, const QString &exterdId) = 0;

        virtual QMap<QString, QString> getAllExtendsPair()=0;

        virtual int getExtendIdUnreadCount(const QString &id) = 0;

        virtual void insertFriendsInfor(QList<FriendsInfor> friendslst) = 0;

        virtual void
        insertAddFriendsInfor(const QString &userid, int byStatus, int status, const QString &descJson) = 0;

        virtual QSharedPointer<Biz::MessageListData> getAddFriendsInfo(const QString &, quint64, int, int) = 0;

        virtual void DeleteOneFriend(const QString &userid) = 0;

        virtual void UpdateAddFriendsInforStatus(const QString &userid, int status) = 0;

        virtual void DeleteOneFriendInfor(int type, const QString &userid) = 0;

        virtual int updateRecentImSessionConfigration(QString xmppid, int addOption, int removeOption) = 0;

        virtual void removeRecentImSessions(const QString &jid) = 0;

        virtual QList<ImSession> checkoutUnreadSessions() = 0;

        virtual void buildIMSessionListFromMessages(const QStringList &newconversationids) = 0;


		virtual void getStarPersons(QStringList &starlist) = 0;

        /*
         *	机器人列表
         */
        virtual QStringList getAllRobotIds()=0;

        virtual QList<QSharedPointer<Biz::RobotVcard>> getAllRobotInfos() = 0;

        virtual QSharedPointer<Biz::RobotVcard> getRobotInfoById(const QString &robotid)=0;

        virtual void insertRobotInfo(const QList<QSharedPointer<Biz::RobotVcard>> &rbtInfos)=0;

        virtual void deleteInvalidRobot(const QStringList &exceptList)=0;

        /*
        * 个人配置列表
        */
        virtual void savePersionConfigInfoEx(const QMap<QString, QVariant> &personConfList) = 0;

        virtual void savePersionConfigInfo(const QList<QSharedPointer<Biz::PersonConfInfo>> &personConfList) = 0;

        virtual QMap<QString, QSharedPointer<Biz::PersonConfInfo>> getAllPersonConf() = 0;

        virtual QMap<QString, QVariant> getAllPersonConfEx() = 0;

        virtual int getVersionsWithPersonConfig() = 0;

        virtual QSharedPointer<Biz::PersonConfInfo> getPersonConf(const QString &key) = 0;

        virtual QSharedPointer<Biz::PersonConfInfo> getPersonConfEx(const QString &key) = 0;


        /*
        * 搜索联系人
        */
        virtual QMap<QString, QSharedPointer<Biz::Player>> searchUsers(const QString &key, bool bMohu) = 0;

        virtual QList<QSharedPointer<Biz::RoomVcard>> searchGroups(const QString &key) = 0;

        virtual QList<QSharedPointer<Biz::FriendsInfor>> searchFriend(const QString &key) = 0;

        virtual QList<QSharedPointer<Biz::RobotVcard>> searchRobot(const QString &key) = 0;

        /*
         * 功能 : 会话备注消息
         */
        virtual void updateConversationMark(const QList<QSharedPointer<Biz::ConversationMarkInfo>> &spInfos) = 0;

        virtual QMap<QString, QSharedPointer<Biz::ConversationMarkInfo>>
        getConversationMark(const QStringList &conversations) = 0;

        virtual QMap<QString, QSharedPointer<Biz::ConversationMarkInfo>> getAllConversationMark() = 0;

        /*
         * 功能 : 心情短语
         */
        virtual void updateUserMoodInfo(const QList<QSharedPointer<Biz::UserMoodInfo>> &spInfos) = 0;

        virtual QSharedPointer<Biz::UserMoodInfo> getUserMoodInfo(const QString &userid) = 0;

        /*!
         * 功能 : 消息状态
         */
        virtual void updateMessageReadStatus(const QString &msgId) = 0;

        virtual int updateMessageStatusByLasttime(const QString &peerid, quint64 qmsglst) =0;

        virtual QMap<QString, int> updateMessageStatusByLasttime(const QMap<QString, quint64> &cid_time_mapping) = 0;

        virtual int getUnreadCountExceptConversations(const QStringList &ids) = 0;

        virtual int getUnreadCount(const QString &jid, quint64 lstm) = 0;

        virtual QMap<QString, int> getConversationsUnreadCount(const QStringList &ids) = 0;

        virtual QSharedPointer<Biz::XmppMessage>
        getNextUnPlayVoiceMessage(const QString &strCounversationId, const QString &strMsgId) = 0;

        virtual int updateRemoteMessageStatus(const QStringList &msgList, int addoption, int removeoption) = 0;

        virtual int updateLocalMessageStatus(const QStringList &msgList, int addoption, int removeoption) = 0;

        virtual QMap<QString, QPair<int, int>> getMessageStatus(const QStringList &msglistids) = 0;

        /*
         * 黑名单的插入和删除
         */
        virtual void insertBlackNameInfo(const QStringList &blklist) = 0;

        virtual void DeletBlackNameInfo(const QString &id) = 0;

        virtual void deleteInvalidBlackName(const QStringList &blklist) = 0;

        /*
         * 群中所有的用户相关
         */
        //插入数据
        virtual void insertUserRelationGroupRecord(const QString &groupJid,
                                                   const QList<QSharedPointer<Biz::GroupMemberModule>> &members) = 0;

        //删除数据
        virtual void delteUserRelationGroupRecord(const QString &groupJid, const QString &userjid) = 0;

        //获取一个群中所有的用户
        virtual QList<QSharedPointer<Biz::GroupMemberModule>> getMembersBygroupId(const QString &groupJid) = 0;

        //删掉关于某一个群的所有数据
        virtual void deleteGroupMember(const QString &groupJid) = 0;

        virtual void updateRole(const QString &groupJid, const QString &jid, int role) = 0;

        virtual QString getUserIdByGroupResource(const QString &groupid, const QString &resource) = 0;

        virtual QStringList getMemberslistBygroupJid(const QString &groupJid) = 0;

        virtual void syncUserNameToGroupMemberTable() = 0;

        virtual void syncUserNameToGroupMemberTableFromUVcard() = 0;

        virtual bool getReplymsg(const QString &conversaitonId, quint64 lasttime)=0;

        //获取数据库中本地的群名信息
        virtual void getGroupInfo(QMap<QString, QString> &groupInfo) = 0;

        virtual QString getDomainDisplayNameById(const QString &jid) = 0;

        //加密中的相关
        virtual void insertMainPwdinfo(const QList<QSharedPointer<Biz::qclude_mainInfor>> &qcludemainfor) = 0;

        virtual QString getSelfConversationKey() = 0;

        virtual void insertSubPwdinfo(const QList<QSharedPointer<Biz::qclude_subInfor>> &qcludesubfor) = 0;

        virtual quint64 getqCloudmaxversionfromMain(int type) = 0;

        virtual void insertMainPwdinfo(const QSharedPointer<Biz::qclude_mainInfor> &qcludemainforone) = 0;

        virtual void insertSubPwdinfo(const QSharedPointer<Biz::qclude_subInfor> &qcludesubinforone) = 0;

        virtual QString getSubkeybyconversationId(const QString &conversationId) = 0;

        virtual int getqCloudofqidInMain(int type) = 0;

        virtual int getqCloudofqidInSub(const QString &conversionId) = 0;

        virtual void deleteqCloudSub(const QString &conversationId) = 0;

        virtual quint64 getqCloudmaxversionfromSub(int type) = 0;

        virtual QSharedPointer<Biz::qclude_mainInfor> getqCloudChatMainInfoBytype(int type) = 0;

        virtual void deleteqCloudAllSub() = 0;

        virtual void deleteqCloudAllMain() = 0;


        //代收相关
        virtual QMap<QString, int> getCollectionConversationIdbyBindUserId(const QString &id) = 0;

        virtual bool setCollectionUpdateMessageReadItem(const QString &parentid, const QString &id) = 0;

        virtual int getUnReadCountOfBindUser(const QString &id) = 0;

        virtual int getUnReadCountOfItem(const QString &parentid, const QString &id) = 0;

        virtual QList<QSharedPointer<Biz::CollectionBindUserInfo>> getCollectionBindList() = 0;

		/* 快捷回复 相关 */  
		virtual bool saveQuickReplyFromService(const QList<QSharedPointer<Biz::QuickReplyGroup>> &replyGroupList,const QList<QSharedPointer<Biz::QuickReplyContent>> &replyContentList) = 0;
		virtual bool saveQuickReplyGroupItems(const QList<QSharedPointer<Biz::QuickReplyGroup>> &replyGroupList) = 0;
		virtual bool saveQuickReplyContentItems(const QList<QSharedPointer<Biz::QuickReplyContent>> &replyContentList) = 0;
		virtual bool updateQuickReplyGroupItems(const QList<QSharedPointer<Biz::QuickReplyGroup>> 
			&replyGroupList) = 0;
		virtual bool updateQuickReplyContentItems(const QList<QSharedPointer<Biz::QuickReplyContent>> 
			&replyContentList) = 0;
		virtual bool deleteQuickReplyGroupItems(const QList<QSharedPointer<Biz::QuickReplyGroup>> 
			&replyGroupList) = 0;
		virtual bool deleteQuickReplyContentItems(const QList<QSharedPointer<Biz::QuickReplyContent>> 
			&replyContentList) = 0;
		virtual bool signDeleteQuickReplyGroup(const QString &groupCid) = 0;
		virtual bool signDeleteQuickReplyContent(const QString &contentCid) = 0;
		virtual int getMaxQuickReplyGroupSeq(void) = 0;
		virtual int getMaxQuickReplyContentSeq(const QString &groupCid) = 0;
		virtual QList<QSharedPointer<Biz::QuickReplyGroup>> getQuickReplyGroupItems() = 0;
		virtual QList<QSharedPointer<Biz::QuickReplyContent>> getQuickReplyContentItems(const QString &groupCid) = 0;
		virtual bool updateQuickReplyGroupSeqs(QList<QSharedPointer<Biz::QuickReplyGroup>> groupList) = 0;
		virtual bool updateQuickReplyContentSeqs(QList<QSharedPointer<Biz::QuickReplyContent>> contentList) = 0;
		virtual QList<QSharedPointer<Biz::QuickReplyGroup>> getSyncQPGroupList() = 0;
		virtual QList<QSharedPointer<Biz::QuickReplyContent>> getSyncQPContentList() = 0;
		virtual long getSQPGroupVersion() = 0;
		virtual long getSQPContentVersion() = 0;
    };
}

#endif // SERVICEMANAGER_H
