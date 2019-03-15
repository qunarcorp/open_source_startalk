#ifndef DAOHELPER_H
#define DAOHELPER_H

#include "CoreObject.h"
#include <QSqlDatabase>
#include "XmppMessage.h"
#include "servicemanager.h"

namespace Biz {
    enum MessageDirection;

    class Player;

    class RoomVcard;

    class Roster;

    class RosterList;

    class XmppMessage;

    class MessageListData;

    class RosterItem;

    class DAOParam4RecentBoddy;

    class ImSession;

    class qclude_mainInfor;

    class qclude_subInfor;

    class RecordInforBegEndTm;

    class XmppMessageAttachment;

    class GroupMemberModule;

    class IDaoService;

    class RobotVcard;

	class QuickReplyGroup;
	class QuickReplyContent;

    extern const QString &USERINFO_VCARD;
    extern const QString &ROOMINFO_TABLENAME;

    class DAOLogic : public QObject, public IDaoService {
    Q_OBJECT

    public:
        enum MessageFlag {
            SEND_MSG_FAILED = 0x00,
            SEND_MSG_SUCCEED = 0x01,
        };

        DAOLogic(const QString &userID);

        ~DAOLogic();

    public:
        int getSystemMsgTableRecordCount();
        // 读消息

        QSharedPointer<Biz::MessageListData> getSystemMsgbyMsgType(const QStringList &typelist, quint64 tm);

        QSharedPointer<Biz::MessageListData> getMessages(const QString &, quint64, int);

        QSharedPointer<Biz::MessageListData>
        getHistoryMessages(const QString &peerID, quint64 lastTime, int count, int direction);

        QSharedPointer<Biz::XmppMessage> getMessageById(const QString &msgid);

        QSharedPointer<Biz::XmppMessage> getRectentMessageByConversationId(const QString &jid);

        QSharedPointer<Biz::MessageListData> getRectentListLastMessage(int savetypefilter);

        QSharedPointer<Biz::XmppMessage>
        getNextUnPlayVoiceMessage(const QString &strCounversationId, const QString &strMsgId);

        QSharedPointer<Biz::MessageListData>
        getMessagebetweenId(const QString &conversationId, const QString &atmsgid, const QString &firstmsgid);

        virtual QSharedPointer<Biz::XmppMessage>
        getLastUnreadMessage(bool bWithNotice, bool bTopMost, quint64 timestamp);

        virtual QSharedPointer<Biz::MessageListData> getAddFriendsInfo(const QString &, quint64, int, int);

        virtual QSharedPointer<Biz::MessageListData> getAllUnreadMessage(const QString &conversationId);

        virtual QSharedPointer<Biz::MessageListData> getAllUnreadMessageFromOther(const QString &conversationID);

        virtual QSharedPointer<Biz::MessageListData> getAllUnSetRecviedMessage();

        virtual QSharedPointer<Biz::MessageListData> getAllFileMessage(const QString &conversationId);

        virtual QSharedPointer<Biz::MessageListData> getMessageListByIds(const QStringList &ids);


        QStringList getSystemMsgType();

        virtual void insertAttachInfo(const QSharedPointer<Biz::AttachMentInfo> &Attachinfor);

        virtual QSharedPointer<Biz::AttachMentInfo> getAttachInfoByUrl(const QString &Name);

        virtual void insertAttachInfo(const QList<QSharedPointer<Biz::AttachMentInfo>> &Attachinforlist);

        virtual void insertChatInfo(const QList<QSharedPointer<Biz::ImSelfPerson>> &userinfor);

        void DoFailUpdateVcardVersion(const QStringList &userJidlist);

        void DoFailUpdateRoomVcardVersion(const QStringList &groupJidlist);

        virtual QMap<QString, int> getUsersVcardVersion(const QStringList &userjid);

        virtual void DeleteAllFriend();

        virtual QStringList getAllFriendsuis();

        virtual QString IsWebDisplayInWebInfo(const QString &userid);

        virtual void DeleteOneFriendInfor(int type, const QString &userid);

        virtual void UpdateAddFriendsInforStatus(const QString &userid, int status);

        virtual void DeleteOneFriend(const QString &userid);

        virtual void insertAddFriendsInfor(const QString &userid, int byStatus, int status, const QString &descJson);

        virtual void insertFriendsInfor(QList<FriendsInfor> friendslst);

        virtual QStringList getExtendPath(const QString &peerid);

        virtual QString getBelongExtendId(const QString &peerid);

        virtual void insertExtends(const QStringList &list, const QString &exterdId);

        /************************************************************************/
        /*  设置未读消息
        /*  1 创建个人配置的存储表
        /*  2 保存系统配置
        /*  3 获取所有系统配置
        /*  4 获取单个系统配置
        /************************************************************************/
        void createPersonConfTable();

        void deletePersonConfTable();

        virtual void savePersionConfigInfoEx(const QMap<QString, QVariant> &personConfList);

        virtual void savePersionConfigInfo(const QList<QSharedPointer<Biz::PersonConfInfo>> &personConfList);

        virtual QMap<QString, QSharedPointer<Biz::PersonConfInfo>> getAllPersonConf();

        virtual QMap<QString, QVariant> getAllPersonConfEx();

        virtual int getVersionsWithPersonConfig();

        virtual QSharedPointer<Biz::PersonConfInfo> getPersonConf(const QString &key);

        virtual QSharedPointer<Biz::PersonConfInfo> getPersonConfEx(const QString &key);

        /*设置未读消息 end*/

        QMap<QString, QString> getAllExtendsPair();

        void getMessagesCountById(const QString &peerID, int &msgcount, quint64 &longtm); // unused

        void getGroupInfo(QMap<QString, QString> &groupInfo);

        void getGroupLasttime(quint64 &lasttime);

        void getAllMessageAndUpdate();

        quint64 getLastMsgTime(const QString &peerid);

        quint64 getLastMsgTime();

        quint64 getMsgTimebyId(const QString &id);

        void getLastMsgTimePerSession(QMap<QString, quint64> &map);

        quint64 getNotelastmsgtm(const QString &userid);

        void insertChatMessage(const XmppMessage &msg, bool bReplace = false);

        void insertChatMessage(const QSharedPointer<Biz::MessageListData> &xmppMessages);

        void insertWebUserInfo(const WebUserInfo &webuserinfo);

        void DelWebUserInfo(const QString &userid);

        void getWebUserInfo(QMap<QString, QSharedPointer<Biz::WebUserInfo>> &);

        void createBaseTable();

        void createIndex();

        bool isMessageIdExist(const QString &msgId);


        void createUserVcardTable();

        int getVcardVersion(const QString &uid);

        bool updateVcardVersion(const QString &uid, int version, const QString &url);

        QStringList getFailUpdateVcardUserIds();

        QStringList getFailUpdateVcardRoomIds();

        void createRecentImSessionTable(); //之前的最近联系人

        // 最近联系人数据库操作 （新的联系人，采用增量的方式获取）
        void createConfigTabel();

        void createMessageTabel();

        void createLocalMessageStateTable();

        void createRemoteMessageStateTable();

        void createRecentIm_SessionTable();

        void createPlayInfoTable();

        void createRoomVcardInfoTable();

        void createExtendSessionTable();

        void createAllUserVcardInforTable();

        void createAttachmentTable();

        void createSystemMessage();

        // end of 创建数据库表们
#pragma region 会话管理

        void insertRecentImSession(const ImSession &param, int savetypefilter = SESSION_CHATING | SESSION_RECENT);

        int updateRecentImSessionConfigration(QString xmppid, int addOption, int removeOption);

        void checkoutRecentImSessions(QList<ImSession> &paramlst, int savetypefilter);

        void checkoutRecentImSessionsByGroup(QStringList &roomid);

        void checkoutRecentImSessionsWithoutMessage(QList<ImSession> &sessions);

		int getSessionChatByConversationId(const QString &jid);

        virtual void removeRecentImSessions(const QString &jid); // userid or groupjid
        void removeSaveTypeImSession(const QString &jid, int satetype);

        virtual QList<ImSession> checkoutUnreadSessions();

        virtual void buildIMSessionListFromMessages(const QStringList &newconversationids);

#pragma endregion 会话管理

#pragma region 黑名单 星标
		// 星标联系人
		void getStarPersons(QStringList &starlist);

#pragma endregion 黑名单 星标

#pragma region 消息管理

        virtual void deleleConversationMessage(const QString &conversaionid);

#pragma endregion 消息管理

        void getPicData(QMap<QString, QString> &picMap);

        void getUserData(QMap<QString, QString> &dataMap);

        bool userDataExist();

        void getMessagePeerid(QStringList &);

        void getMessagePeeridbySendid(QStringList &, const QString &sendid);

        void getMessagePeeridbymsg(const QString &msgcontent, QStringList &peeridlist);

        void getMessagePeeridbymsgAndSendid(QStringList &, const QString &sendid, const QString &msgcontent);

        Biz::RecordInforBegEndTm getMessagebyPeerid(const QString &peerID, quint64 timestamp, int count);

        void getRecordInforbycontains(const QString &peerID, const QString &strfindid, quint64 &tm);

        quint64 getRecentlasttimeByid(const QString &groupjid);

        // 消息附件数据存储
        void insertMessageAttachment(const QSharedPointer<Biz::XmppMessageAttachment> &xma);

        void getMessageAttchment(const QString &url, QList<QSharedPointer<Biz::XmppMessageAttachment>> &retlist);

        void getAllMessageAttchment(QList<QSharedPointer<Biz::XmppMessageAttachment>> &retlist);


        void getMessageIdbyUserid(const QString &userid, QStringList &listmsgid);

        /************************************************************************/
        /*  设置未读消息
        /*  1 设置某个会话中某个时间点之前的所有消息为已读的
        /*  2 设置某个会话中的某条消息为已读状态
        /*  3 获取一个会话的未读数
        /*  4 获取所有未读数
        /*  5 获取所有未读的二人回话消息
        /*  6 设置某条消息为已读
        /*  7 设置某些消息为已读
        /*  8 设置所有消息为已读
        /*  9 获取一个扩展id的未读数
        /*  10 更新一个消息的状态，有增加，有删除
        /*  11 批量更新群组的消息未读标记，将小于第一条已读消息的所有消息被设置成已读
        /************************************************************************/
        int updateMessageStatusByLasttime(const QString &peerid, quint64 qmsglst);

        virtual QMap<QString, int> updateMessageStatusByLasttime(const QMap<QString, quint64> &cid_time_mapping);

        int getUnreadCount(const QString &jid, quint64 lstm);

        virtual QMap<QString, int> getConversationsUnreadCount(const QStringList &ids);

        int getUnreadCountExceptConversations(const QStringList &ids);

        void getChatUnreadMsgIds(QStringList &listmsgid);

        void updateMessageReadStatus(const QString &msgId);

        void setAllMessageRead(quint64 lsttm);

        int getExtendIdUnreadCount(const QString &id);

        void updateMessageStatusSending2SendFail();

        virtual int updateRemoteMessageStatus(const QStringList &msgList, int addoption, int removeoption);

        virtual int updateLocalMessageStatus(const QStringList &msgList, int addoption, int removeoption);

        virtual QMap<QString, QPair<int, int>> getMessageStatus(const QStringList &msglistids);

        /*设置未读消息 end*/

        int getGroupExternFlagbyJid(const QString &jid);

        void saveUserInfo(const QVariantList &rosterNode);

        void saveUserInfo(const QList<QSharedPointer<Biz::Player>> userinfos);

        void deleteNoteHereUsers();

        QMap<QString, QSharedPointer<Biz::Player>> searchUsers(const QString &key, bool bMohu);

        QList<QSharedPointer<Biz::RoomVcard>> searchGroups(const QString &key);

        virtual QList<QSharedPointer<Biz::FriendsInfor>> searchFriend(const QString &key);

        virtual QList<QSharedPointer<Biz::RobotVcard>> searchRobot(const QString &key);

        int getMaxPlayVersion();

        void CleanAllMessage();

        void saveRoomVcardInfos(const QList<QSharedPointer<Biz::RoomVcard>> &roomvcards);

        void updateRoomVcardInforbyDomain(const QSharedPointer<Biz::RoomVcard> &onerome, bool type = false);

        void deleteRoomVcard(const QString &roomid);

        void updateRoomVcardInfors(const Biz::RoomVcard &onerome);

        QList<QSharedPointer<Biz::RoomVcard>> getRoomVcardInfos();

        QList<QSharedPointer<Biz::RoomVcard>> getRoomVcardInfos(const QStringList &ids);

        QMap<QString, QSharedPointer<Biz::RoomVcard>> getRoomVcardInfosbyIds(const QStringList &ids);

        void deleteRecent7DayMessage();

        void setSystemMessageById(const QString &msgid, const QString &msgType, int status = 0);

        void updateSystemMessageById(const QString &msgid, int status);

        void insertSystemMessage(const QList<QSharedPointer<Biz::SystemMessageInfo>> &SystemMessagelist);

        void updateSystemMessageByInfor(const QSharedPointer<Biz::SystemMessageInfo> &systemsg);

        /*
         *	机器人相关的接口
         *      1 保存机器人信息，存在则覆盖
         *      2 删除机器人信息
         *      3 获取机器人最大版本号
         *      4 获取所有机器人id
         *      5 获取机器人信息
         *      6 创建机器人库表
         *      7 获取所有机器人信息
         */
        void insertRobotInfo(const QList<QSharedPointer<Biz::RobotVcard>> &rbtInfos);

        void deleteInvalidRobot(const QStringList &exceptList);

        int getMaxRobotVersion();

        QStringList getAllRobotIds();

        QSharedPointer<Biz::RobotVcard> getRobotInfoById(const QString &robotid);

        void createRobotTable();

        QList<QSharedPointer<Biz::RobotVcard>> getAllRobotInfos();

        /* 机器人接口完毕 */

        void getWebChatIdAndName(QMap<QString, QSharedPointer<Biz::ImSelfPerson>> &);

        void updateWebInfo(const QString &userid, const QString &city);

        /*
         *	备注信息相关的接口
         *      1 创建备注信息表
         *      2 增加、修改备注信息
         *      3 获取所有的备注信息
         *      4 获取单个备注信息
         */
        void createConversationMarkTable();

        void updateConversationMark(const QList<QSharedPointer<Biz::ConversationMarkInfo>> &spInfos);

        QMap<QString, QSharedPointer<Biz::ConversationMarkInfo>> getConversationMark(const QStringList &conversations);

        QMap<QString, QSharedPointer<Biz::ConversationMarkInfo>> getAllConversationMark();
        /* 备注信息接口完毕 */

        /*
         *	心情短语的接口
         *      1 创建心情短语信息表
         *      2 增加、修改心情短语信息
         *      3 获取单个人心情短语信息
         *      
         */
        void createUserMoodInfoTable();

        void updateUserMoodInfo(const QList<QSharedPointer<Biz::UserMoodInfo>> &spUsermoodInfos);

        QSharedPointer<Biz::UserMoodInfo> getUserMoodInfo(const QString &userid);

        /*
         *  黑名单的相关接口
         *
         *
         */
        void createBlackNameTable();

        void insertBlackNameInfo(const QStringList &blklist);

        void deleteInvalidBlackName(const QStringList &exceptList);

        QStringList getAllBlackNameIds();

        void DeletBlackNameInfo(const QString &id);

        /*
         *  群里有哪些成员的相关接口
         *
         *
         */
        void createUserRelationGroupTable();

        void insertUserRelationGroupRecord(const QString &groupJid,
                                           const QList<QSharedPointer<Biz::GroupMemberModule>> &members);

        void delteUserRelationGroupRecord(const QString &groupJid, const QString &userjid);

        void updateRole(const QString &groupJid, const QString &jid, int role);

        QList<QSharedPointer<Biz::GroupMemberModule>> getMembersBygroupId(const QString &groupJid);

        QStringList getMemberslistBygroupJid(const QString &groupJid);

        void deleteGroupMember(const QString &groupJid);

        void syncUserNameToGroupMemberTable();

        void syncUserNameToGroupMemberTableFromUVcard();

        QString getUserIdByGroupResource(const QString &groupid, const QString &resource);

        void removeDeletedGroupMembers(const QStringList &groupids);

        void removeDeletedInGrouopMembers(const QStringList &groupids);

        QMap<QString, QList<QSharedPointer<Biz::RoomVcard>>> getRoomVcardInforByDomain();

        QMap<QString, int> getGroupMenberMsgCount(const QString &groupjid);

        QSharedPointer<Biz::MessageListData>
        getGroupMsgFilter(const QString &groupjid, const QStringList &ids, int count);

        QSharedPointer<Biz::MessageListData> getGroupMsgAtFilter(const QString &groupjid, const QStringList &msgids);

        void updateGroupInforTodb(const QList<QSharedPointer<Biz::RoomVcard>> &roomlist);

        virtual QMap<QString, quint64> getGroupsEarliestUnradMessageTime();

        /*
        *  最近联系人列表中的相关
        */

        void createRecentUserListTable();

        void insertRecentUserListRecord(const QList<QSharedPointer<Biz::RecentListInfor>> &inforlist);

        QList<QSharedPointer<Biz::RecentListInfor>> getRecentUserListRecord();

        void deleteAllRecord();

        /*
        *   增量群信息表中相关的
        */
        void createIncreaRoomInfoTable();

        void insertIncreaRoomInfo(const QList<QSharedPointer<Biz::IncreaRoomInfo>> &roomlist);

        void delteIncreaRoomRecord(const QStringList &roomidlist);

        void deleteRemoveImSessionRoomInfor(const QStringList &roomidlist);

        /*
        *  主密码表和子密码表的相关
        */
        void createMainPwdInfoTable(); //存放打开密码箱所需
        void createSubPwdInfoTable();  //存放子密码信息的地方
        void insertMainPwdinfo(const QList<QSharedPointer<Biz::qclude_mainInfor>> &qcludemainfor);

        void insertMainPwdinfo(const QSharedPointer<Biz::qclude_mainInfor> &qcludemainforone);

        void insertSubPwdinfo(const QList<QSharedPointer<Biz::qclude_subInfor>> &qcludesubfor);

        void insertSubPwdinfo(const QSharedPointer<Biz::qclude_subInfor> &qcludesubinforone);

        QString getSelfConversationKey();

        quint64 getqCloudmaxversionfromMain(int type);

        quint64 getqCloudmaxversionfromSub(int type);

        QString getSubkeybyconversationId(const QString &conversationId);

        int getqCloudofqidInMain(int type);

        int getqCloudofqidInSub(const QString &conversionId);

        void deleteqCloudSub(const QString &conversationId);

        QSharedPointer<Biz::qclude_mainInfor> getqCloudChatMainInfoBytype(int type);

        void deleteqCloudAllSub();

        void deleteqCloudAllMain();

        //根据msg的时间和conversationId 获取是否有回复过的消息
        bool getReplymsg(const QString &conversaitonId, quint64 lasttime);

        QString getDomainDisplayNameById(const QString &jid);

        /*
        *    代收的相关表
        */

        void createClientConfigTable();

        void createCollectionSessionListTable();

        void insertCollectionSessionlistInfo(const QList<QSharedPointer<Biz::CollectionSessionInfor>> &qsessionlist);

        void insertCollectionSessionlistInfo(const QSharedPointer<Biz::CollectionSessionInfor> &qsession);

        void createCollectionUserTable();

        void insertcollectionBindUserlistInfor(const QList<QSharedPointer<Biz::CollectionBindUserInfo>> &qbinduserlist);

        int getMaxCollectionBindUserVersion();

        QList<QSharedPointer<Biz::CollectionBindUserInfo>> getCollectionBindList();

        QMap<QString, int> getCollectionConversationIdbyBindUserId(const QString &id);

        int getUnReadCountOfBindUser(const QString &id);

        int getUnReadCountOfItem(const QString &parentid, const QString &id);

        bool setCollectionUpdateMessageReadItem(const QString &parentid, const QString &id);

        QSharedPointer<Biz::MessageListData>
        getCollectionMessages(const QString &parentid, const QString &peerID, quint64 lastTime, int count);

		/* 快捷回复 相关 */ 
		void createQuickReplyMsgTable();
		bool saveQuickReplyFromService(const QList<QSharedPointer<Biz::QuickReplyGroup>> &replyGroupList,const QList<QSharedPointer<Biz::QuickReplyContent>> &replyContentList);
		bool saveQuickReplyGroupItems(const QList<QSharedPointer<Biz::QuickReplyGroup>> &replyGroupList);
		bool saveQuickReplyContentItems(const QList<QSharedPointer<Biz::QuickReplyContent>> &replyContentList);
		bool updateQuickReplyGroupItems(const QList<QSharedPointer<Biz::QuickReplyGroup>> 
			&replyGroupList);
		bool updateQuickReplyContentItems(const QList<QSharedPointer<Biz::QuickReplyContent>> 
			&replyContentList);
		bool deleteQuickReplyGroupItems(const QList<QSharedPointer<Biz::QuickReplyGroup>> 
			&replyGroupList);
		bool deleteQuickReplyContentItems(const QList<QSharedPointer<Biz::QuickReplyContent>> 
			&replyContentList);
		bool signDeleteQuickReplyGroup(const QString &groupCid);
		bool signDeleteQuickReplyContent(const QString &contentCid);
		int getMaxQuickReplyGroupSeq();
		int getMaxQuickReplyContentSeq(const QString &groupCid);
		QList<QSharedPointer<Biz::QuickReplyGroup>> getQuickReplyGroupItems();
		QList<QSharedPointer<Biz::QuickReplyContent>> getQuickReplyContentItems(const QString &groupCid);
		bool updateQuickReplyGroupSeqs(QList<QSharedPointer<Biz::QuickReplyGroup>> groupList);
		bool updateQuickReplyContentSeqs(QList<QSharedPointer<Biz::QuickReplyContent>> contentList);
		QList<QSharedPointer<Biz::QuickReplyGroup>> getSyncQPGroupList();
		QList<QSharedPointer<Biz::QuickReplyContent>> getSyncQPContentList();
		long getSQPGroupVersion();
		long getSQPContentVersion();
		void updateQuickReplyOptionFlag(int optionFlag);
    protected:
        void TraversalMessageTosystemMessage(const QString &peerid);

        void alterWebUserInforTable();

        void createMessageAttachmentTable();

        void createFriendsInforTable();

        void createFriendsOperaInforTable();

        //qchat 中存放用户信息
        void createWebUserInforTable();

    private:
        void innerInsertBatchMessage(const QSharedPointer<Biz::MessageListData> &xmppMessages);

        void onClearMessageTable();

        QSharedPointer<Biz::XmppMessage> translateXmppMessage(const QSqlQuery &sql);

        QSharedPointer<Biz::XmppMessage> translateXmppMessageOfCollection(const QSqlQuery &sql);

        void innerSaveUserInfoNode(const QVariantList &rosterList,
                                   QVariantList &userids,
                                   QVariantList &names,
                                   QVariantList &departs);

        bool execQueryWithLog(QSqlQuery &query);

        bool execBatchWithLog(QSqlQuery &quert);

        void checkDbVersion(const QString &dbFileName);

        void checkMessageTable();

        int getCurrentDbVersion();

        bool onUpdateDB(int oldVer, int newVer);

        QString mUserID;
        QSqlDatabase mConnection;

        Qt::HANDLE ownerThreadId;


        static QString MESSAGE_TABLENAME;
        static QString CONFIG_TABLENAME;
        static QString SYSTEM_MSG_TABLENAME;
        static QString Im_SESSIONS;
        static QString MESSAGE_ATTACHMENT;
        static QString USER_VCARD;
        static QString PLAYINFO_TABLENAME;
        static QString ROOMINFO_TABLENAME;
        static QString EXTENDSESSIONS_TABLENAME;
        static QString FRIENDSINFO_TABLENAME;
        static QString FRIENDSOPERAINFO_TABLE;
        static QString WEBUSERINFO_TABLE;
        static QString USERINFO_VCARD;
        static QString ATTACHMENTINFO;
        static QString USERRELATIONGROUP_TABLE;//存放群里面有哪些用户
        static QString INCREAROOMINFO_TABLENAME;//增量群的信息

        static QString LOCAL_MESSAGE_STATE;
        static QString REMOTE_MESSAGE_STATE;

		static QString QUICK_REPLY_GROUP;
		static QString QUICK_REPLY_CONTENT;
    };

}
#endif // DAOHELPER_H
