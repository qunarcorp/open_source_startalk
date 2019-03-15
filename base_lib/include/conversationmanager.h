

#ifndef CONVERSATIONMANAGER_H
#define CONVERSATIONMANAGER_H

#include <QObject>
#include "managerbase.h"
#include "RosterList.h"

#include "CustomDefine.h"
//#include "../QLua/qtalklua.h"

namespace Biz
{
	class XmppMessage;
    class ImSession;
    class SearchResulteItemGroupModule;
    class ConversationMarkInfo;
	class RosterNode;
	class PersonConfInfo;
	class CollectionBindUserInfo;
	class CollectionSessionInfor;
	class MessageListData;
	class NoticeStrInfor;
	class ConversationParam;

	enum TransReply
	{
		ReplayShop,
		ReplayVisitor
	};
	struct TransReplyValue
	{
		bool ReplayShopvalue;
		bool ReplayVisitorvalue;
		TransReplyValue()
		{
			ReplayVisitorvalue= false;
			ReplayShopvalue = false;
		}
	};
	class ConverSationManager : public ManagerBase
	{
		Q_OBJECT

	public:
		ConverSationManager();
		~ConverSationManager();
	public:
		virtual void initManager();
		virtual void unInitManager();

		void getRecentChatMessage(const QString& jid, Biz::UnitCallback<QSharedPointer<Biz::XmppMessage>>* callback);
        void resendMessage(const QString& messageid);
		void insertMsg(const QSharedPointer<Biz::XmppMessage>& msg);
		void SendWelcomeInfo(const QString& userid, const QString& chatid);
		void SendProductInfo(const QString& msg, const QString& url, const QString& strJid );

		void SendEncryptMessage(const QString&conversationId, const QString&body, int type);

		void onWelcomeToWebMsg(const QString& strUserid, const quint64 chatid);
		void SendSystemNotifyInfo(const QString& strUserid, const QString& strInfor);

        void sendRevokeMessage(const QString& msgid,Biz::UnitCallback<QSharedPointer<Biz::XmppMessage>>* callback);
		QString getSticktop(){return sSetTopMostKey;}
#pragma region 阅读指针
		// 设置群组会话已读
        void setGroupConversationMessageRead(const QString& strJid);
		// 设置个人会话的消息已读
        void setConversationMessageRead(const QString& strJid);
        // 设置本地的会话的未读数为0,不需要发送任何readmark消息，不需要同步给其他平台客户端的
        void setLocalCoversationMessageRead(const QString& strJid);
		// 设置所有消息为已读
        void setAllMessageRead();
		// 设置消息已首收到
		void setMessageStateReceived(bool  isConsult,const QString& to ,const QString& virtualid,const QStringList& ids);
		// 同步消息已读状态给服务器
		void  setMessageStateReaded(const QString& conversationid);
		// 获取扩展会话的未读数
		void getLinkItemUnReadCount(const QString strJid, Biz::UnitCallback<int>* callback);
#pragma endregion 阅读指针

#pragma region 会话列表
		void updateRecentImSessionConfigrationofLocal(QString xmppid,int addOption,int removeOption);
        void updateRecentImSessionConfigration(QString xmppid,int addOption,int removeOption);
		void updateRecentImSessionMsgNotice(QString xmppid,int addOption,int removeOption);
        void getChatingSessions();
        void getChatingSessionsWithCallback(Biz::UnitCallback<QList<Biz::ImSession>>* callback);
        void saveConversationInfo(const QSharedPointer<Biz::XmppMessage>& msg, GeneralCallback* callback);
        void removeChartingImSession(const QString& jid);
        void updateRemoteConfig();
		void updateRemoteConfigEx(QString xmppid, int addOption, int removeOption);
        void updateRemoteConfig(const QList<Biz::ImSession>& imsessions);
		void getChatingSessionsLastMsg();
		void updateMarkupName(const QString &jid, const QString& markupname);

		//收到消息提醒和不提醒的漫游设置
		void updateNoticeRemoteConfig(const QList<Biz::ImSession>& imsessions);

		void mergeTopMostConversation2Imsession();
#pragma endregion 会话列表
       
        void setVoicePlayed(const QString& messageid);
        void getNextUnPlayedMessage(const QString& conversation,const QString& messageid,Biz::UnitCallback<QSharedPointer<Biz::XmppMessage>>* callback);

        void searchUserInGlobal(const QString& key, Biz::UnitCallback<QList<SearchResulteItemGroupModule>>* callback);
		void searchUserInGlobalbyLua(const QString& key, Biz::UnitCallback<QList<SearchResulteItemGroupModule>>* callback);
		void searchInforMore(const QString& key, const QString& searchkey, Biz::UnitCallback<QList<SearchResulteItemGroupModule>>* callback);

		//在组织架构里面查找
		void searchUserInOrganize(const QString& key, Biz::UnitCallback<QList<Biz::RosterNode*>>* callback);
		//在好友中查找
		void searchUserInFriends(const QString& key, Biz::UnitCallback<QList<Biz::RosterNode*>>* callback);

        /*!
         * 功能 : 彻底删除会话记录以及关联消息
         */
        void deleteConversation(const QString& conversationId);

        /*!
         * 功能 : 加载带有未读消息和置顶的
         */
        void loadTopAndUnreadConversations(Biz::UnitCallback<QList<ImSession>>* callback);

        /*!
         * 功能 : 加载一般的会话列表
         */
        void loadAllChattingConversation(Biz::UnitCallback<QList<ImSession>>* callback);

        /*!
         * 功能 : 获取一条消息，在这里转个一步
         */
        void getMessageByIdAsync(const QString& msgid,Biz::UnitCallback<QSharedPointer<Biz::XmppMessage>>* callback);

        /*!
         * 功能 : 抢单
         */
        void dealWechatDeal(const QUrl& url,Biz::UnitCallback<QString>* callabck);

        /*!
         * 功能 : 获取一个会话的备注信息，用于展示，更新等
         */
        void getConversationMarkInfo(const QString& conversations,Biz::UnitCallback<QSharedPointer<Biz::ConversationMarkInfo>>* callback);

        /*!
         * 功能 : 保存一个会话的备注信息
         */
        void saveConversationMarkInfo(const QSharedPointer<Biz::ConversationMarkInfo>& spInfo);

        void sendShareMessage(const QString& shareconversationId,const QString& conversationid,const QString& url,Biz::GeneralCallback* callback);
        
		void setZhongbaoInfor(const QString&id,const QString&value);

		void getZhongbaoparam(const QString&id, Biz::UnitCallback<QString>* callback);

		//代收绑定信息
		void getCollectionBindUser(Biz::UnitCallback<QList <QSharedPointer<Biz::CollectionBindUserInfo>>>* callback);

		//根据绑定代收id的, 获取子聊天框
		void getCollectionConversationIdbyBindUserId(const QString& id, Biz::UnitCallback<QMap<QString, int>>* callback);

		void setCollectionReadFlag(const QString&parentid, const QString& userid, Biz::UnitCallback<bool>* callback);

		void getCollectionBindUserUnReadCount(const QString&id, Biz::UnitCallback<int>* callback);
		void getCollectionBindUserItemUnReadCount(const QString&parentid, const QString&id, Biz::UnitCallback<int>* callback);
		void getCollectionBindUserList(Biz::UnitCallback<QList <QSharedPointer<Biz::CollectionBindUserInfo>>>* callback);
		void getNoticeLinkInfo(const QString& url, Biz::UnitCallback<QSharedPointer<Biz::NoticeStrInfor>>* callback);

		void closeRemoteSession(const QString& userid, const QString& shopName);
    public:
		void updateReadMarkByMsgIds(const QString& conversationId, const QStringList& msgids);
		//void updateReadMarkByLastTime(const QString& conversationId, quint64 lastTime);
		void updateReadMarkByLastTime(const QMap<QString,quint64>& cid_time_mapping);
		void updataAllMessageRead(quint64 lstm);
		void getRecentListFromServer();
    private:
		static QString sSetMarkupName;
        static QString sSetTopMostKey;
		
		static QString sSetZhongbaoConversationKey;
		QMap<QString, QString> zhongbaoInformap;
		
		public:
			static QString sSetNoticeTipKey;
	private:
		void GetTopMostRemoteParase(const QStringList& keys, const QSharedPointer<Biz::PersonConfInfo>& PersonCfg);
		void GetZhongbaoRemoteParase(const QStringList& keys, const QSharedPointer<Biz::PersonConfInfo>& PersonCfg );
		void InitZhongbao();
		void GetMarkupRemoteParase(const QStringList& keys, const QSharedPointer<Biz::PersonConfInfo>& personCfg);
signals:
		void sgCollectionBindUser(QList <QSharedPointer<Biz::CollectionBindUserInfo>> inforlist );
		void sgEncryptMsgInfo(const QString&conversationId, const QSharedPointer<Biz::XmppMessage>& msg);
		void sgShowEmpty(const QString& conversationId);
		//手动删除最近会话列表的item
		void sgRemoveRecentItem(const QString& jid);
		//历史框中消息的条数
		void sgHistoryMsgCount(int ncount);
		void sgCoversationRectentListShow(bool bStyle);
		//显示机器人
		void sgConverSationMenuRobotType(const QString& conversationId);
		//显示回话的消息
		void sgConverSationShowMsg(const QString& conversation);
		void sgShowWelcome(const QString& userid, const QSharedPointer<Biz::XmppMessage>& msg);
		void sgShowProductInfo(const QString& userid, const QSharedPointer<Biz::XmppMessage>& msg);
		void sgShowSystemNotifyInfo(const QString& userid, const QString& notifyInfo);



		void sgCloseRobotDialog(const QString& rbtid);

		// 清除单一会话的未读通知，at标记
        void sgConversationReadedByOtherClient(const QString& conversationid,quint64 lasttime);
		// 清除所有会话的未读通知，at标记
        void sgAllConversationReadedByOtherClient(quint64 lasttime);

		// 多个会话的未读数变更通知。
        void sgConversationUnreadCountChange(const QMap<QString,int>& cidUnreadCntMapping);

		// 一键已读，只有一个地方触发才对
		void sgAllConversationReaded(); // read by onekey

		// 下面两个都是报告全局有多少未读数得，看上去重复了。
		void sgAllMessageUnreadCountChanged(int unreadCount,bool hasNoCountUnreadMsg); // zongshu

		// 我自己发送出去的消息的状态变更
		void sgConversationMessageStateChange(const QString& conversationId,QMap<QString,QPair<int,int>> msgStatus);

		// 置顶变化
        void sgTopMostConversationChanged(const QList<Biz::ImSession>& changedSessions);
		
		// 消息提醒变化
		void sgNoticeTipConversationChanged(const QList<Biz::ImSession>& changeSession);

        void sgRecentBuddiesResult(const QList<Biz::ImSession>& imSessions );
        void sgChatDialogAddRecent(QList<Biz::ImSession> session);

        void sgReloadConversationMsg(const QString& conversationid);

		//转移的回复
		void sgTransReply( const QString&, int );
		void sgTransVistorInfo(const QString&conversationId, const QString& productUrl, const QString& vistorLocal);
		void sgRecivedRetmsg(const QString&, int);
		void sgTransferResult(const QString& peerid, const QString& transid, bool bret, int type);
		//加密会话的相关
		void sgEncryptEvent(int type, const QString& infor, const QString& conversationId);
		
		//最后列表中获取最后一条消息
		void sgRectChatLastMsg(const QSharedPointer<Biz::MessageListData>& msglist );
		
		//presence 下发一个通知
		void sgPresenceOpenChat( const QSharedPointer<Biz::ConversationParam>& spConversationParam, quint64 stime);
		void sgPresenceGlobleNotice(const QString&data);
		void sgPresenceAppointNotice(const QString&data);

		void sgRealConversationJidChange(const QString& virtualid,const QString&realjid);

        public slots:
            void onPersonCfgChange(const QStringList& changedKeys);
			void onMessageUnreadCountChanged();
			void onConnected();
			void onPersonCfgChangezhongbao();
			
			
	};
}
#endif // CONVERSATIONMANAGER_H
