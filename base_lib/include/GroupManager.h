#ifndef GROUPMANAGER_H
#define GROUPMANAGER_H

#include <QObject>
#include "managerbase.h"
#include "../QXmpp/base/QXmppDataForm.h"
#include "RosterList.h"
#include "MessageListData.h"


class QXmppMucManagerNegative;
class QXmppChatSelfInfoIq;
class QXmppRoomNegative;
class QXmppMucRoomMemberIq;
class QXmppMucRoomListIq;
class QXmppPresence;

namespace Biz
{
    class RoomVcard;
	class GroupMemberModule;
	struct  RoomVcardRequestParam;

	class GroupManager : public ManagerBase
	{
	    Q_OBJECT
	
	public:
	    GroupManager();
	    ~GroupManager();
	
    public:

        void joinGroup(const QString& groupJid,Biz::UnitCallback<bool>* callback);
        void createGroup(const QString& groupName,const QStringList& members,Biz::UnitCallback<QString>* callback);
        
        void destroyGroup(const QString& groupJid);
        // 邀请一批人
        void inviteGroupMembers(const QString& groupJid ,const QStringList& userjids,Biz::UnitCallback<QStringList>* callback);

        void leaveGroup(const QString& groupJid);
		void getGroupMember(const QString& groupJid,Biz::UnitCallback<QList<QSharedPointer<Biz::GroupMemberModule>>>* callback);
		void getGroupMemberRefresh(const QString& groupJid);
		void getGroupMemberbyInfor(const QString& groupJid,Biz::UnitCallback<QList<QSharedPointer<Biz::GroupMemberModule>>>* callback);

        void setMemberAffiliation(const QString& groupJid, const QString& selectname,const QString& memberJid, int nAffil);
        void kickMember(const QString& groupJid,const QString& nickName, const QString& userid);
        void getJoinedRoomListOnLogin(Biz::UnitCallback<QStringList>* callback);
        void getJoinedRoomList();
        void requestConfigration(const QString& groupid);
        void setGroupConfigration(const QString& groupid, const QString& key, const QVariant& val,QXmppDataForm::Field::Type type );
		//增量获取群列表
		void getIncrementJoinedRoom(quint64 lasttime, Biz::UnitCallback<QMap<QString, QSharedPointer<Biz::IncreaRoomInfo>>>* callback);

        void saveSelfInfo(const QString& strInfor);
        QString getGroupNickName(const QString& jid);
		QString getGroupLocalNickNamebyId(const QString&jid);

		//最早那im_session表中的数据
		void getRecentCheckoutChatting();
		void getGroupVideoRoomAddr(Biz::UnitCallback<QString>* callback);

		void getGroupMemberMsgCount(const QString&groupjid, Biz::UnitCallback<QMap<QString,int>>*callback);

		//guo
		void getGroupFilterHistoryMessageList(const QString& conversationId, const QStringList& ids, int count,  UnitCallback<QSharedPointer<Biz::MessageListData>>* callback );

		void getGroupAtFilterHistoryMessageList(const QString& conversationId, const QStringList& msgids,  UnitCallback<QSharedPointer<Biz::MessageListData>>* callback);

		//设置消息提醒状态
		void setMessageNotice(const QString& groupjid, int type);

		void doGetMsgNotice();
    public:
	    virtual void initManager();
	    virtual void unInitManager();

    private:
        void _getGroupMemberOnLine(const QString& groupid);
	    void _getGroupMemberOnLine(const QString& groupid,Biz::UnitCallback<QList<QSharedPointer<Biz::GroupMemberModule>>>*callback);
		void getGroupMemberImageByVersion(const QString&groupjid, const QStringList& recivedmemberidlist);
		void doMergeGroup(const QMap<QString, QSharedPointer<Biz::RoomVcard>> &roominfomap);
		void updateGroupInforTodb(const QList<QSharedPointer<Biz::RoomVcard>>& roomlist);
		QList<QSharedPointer<Biz::RoomVcardRequestParam>> getMucVcardParams(const QMap<QString, QSharedPointer<Biz::RoomVcard>>& informap);
		void _getGroupMemberOnLinebyInfo(const QString& groupid);
		void _getGroupMemberOnLinebyInfo(const QString& groupid,Biz::UnitCallback<QList<QSharedPointer<Biz::GroupMemberModule>>>*callback);
		
	private:
	    QXmppMucManagerNegative* groupExternd;
		//存放本地的群ID和群名
		QMap<QString, QString> mGroupInfoByLocal;
		quint64 mGroupLasttime;
		QString mGroupMsgNoticeList;
signals:
		void sgRecentChattingGroup(const QList<Biz::ImSession> & imsession);
		void sgGroupNoticeTipChange(const QString& groupjid, int addoption, int removeoption);
		
        void sgRoomListReceived(const QStringList& roomList);

        void sgGroupJoinedSuccess(const QString& groupBareId);
        void sgGroupAuthFaild(const QString& groupBareId);
        void sgGroupJoidFailed(const QString& groupBareId);
        void sgGroupMemberChanged(const QString& groupBareId, const Biz::GroupMemberModule& memberModule);
        void sgGroupMemberRemoved(const QString& groupBareId,const QString& userid);
        void sgGroupMemberBeKicked(const QString& groupBareId,const QString& userid,const QString& reason);
        void sgGroupMemberListReceived(const QString& groupBareId,const QList<QSharedPointer<Biz::GroupMemberModule>>& members);
        void sgGroupDestroyed(const QString& groupBareJid);
        void sgDestroyGroupFail(const QString& groupid,int code);
        void sgGroupLeavedReceived(const QString& groupBareJid);
        void sgDelRegisterReceived(const QString& groupBareJid,const QString& userid);
        void sgMemberInvitedByOtherReceived(const QString& jid, const QString& userid,const QString& status);
		void sgGetRoomVcardList(const QString&jid);
		void sgInitRoomVcardListAsync(QList<QSharedPointer<Biz::RoomVcard>> rooms);//进行同步群的名片
		void sgGroupVcardUpdated(const QStringList& groupJids);
        void sgGroupSubjectHasChanged(const QString& groupjid);
		void sgGroupCoverAdd(const QString& groupjid);
        public slots:
            void onGroupInvaitationReceived(const QString &roomJid, const QString &inviter, const QString &reason);
            void onGroupAdded(const QXmppRoomNegative* room);
            void onDestroyGroupFail(const QString& jid,int code);
            void onGroupLeaveRecived(const QString& jid);
            void onSyncInvitedByOtherClientRecived(const QString& roomjid,const QString& userid,const QString&status);
			void onRoomListReceivedOneKeyDomain(const QStringList& roomlist);
            void onInitRoomsVcard(QList<QSharedPointer<Biz::RoomVcard>> list);
            
            public slots:
                void onParticipantChanged(const QXmppRoomNegative* pthis,const QXmppPresence& presence);
                void onParticipantRemoved(const QXmppRoomNegative* pthis,const QXmppPresence& presence);
                void onParticipantBeKicked(const QXmppRoomNegative* pthis,const QString& jid,const QString& reason);
                void onAllowedActionsChanged(const QXmppRoomNegative* pthis,int actions);
                void onDelRegisterReceived(const QXmppRoomNegative* pthis,const QString&roomjid, const QString& userid);
                void onGroupNameUpdate(const QXmppRoomNegative* pthis,const QString&roomjid);
                void onGroupDestroyed(const QXmppRoomNegative* pthis,const QString& jid);

                void onConfigurationReceived(const QXmppRoomNegative* pthis,const QXmppDataForm& form);
				void onConnected();
				void onParticipantCoverAdd(const QXmppRoomNegative* pthis,const QXmppPresence& presence);
    };
}

#endif // GROUPMANAGER_H
