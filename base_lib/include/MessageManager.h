#pragma once
#include <QObject>
#include "managerbase.h"

namespace Biz
{
	class XmppMessage;
    class MessageListData;
    struct GroupHistoryRequestParam;
	class MessageManager : public ManagerBase
	{
		Q_OBJECT
	public:
		MessageManager();
		~MessageManager();
	public:
		virtual void initManager();
		virtual void unInitManager();
    public:
		void setLastMsgTime(quint64 lstmsgtime) {mlastMsgtime = lstmsgtime;};
        void getMessageById(const QString& messageid, Biz::UnitCallback<QSharedPointer<Biz::XmppMessage>>* callback);
        void getMessageListByIds(const QStringList& ids,Biz::UnitCallback<QString>* callback);
        void getAllUnreadMessageList(const QString& conversationId,UnitCallback<QSharedPointer<Biz::MessageListData>>* callback );
        
        void getAllFileMessage(const QString& conversationId,UnitCallback<QSharedPointer<Biz::MessageListData>>* callback);

        void getLastUnreadConversationId(bool bWithNotice,Biz::UnitCallback<QString>* callback);

        void getGroupsLastMessageTime(Biz::UnitCallback<QMap<QString,quint64>>* uicb);

		void getMessageByBetweenId(const QString& conversationId, const QString& atmsgid, const QString& firstMsgid, UnitCallback<QSharedPointer<Biz::MessageListData>>* callback );
		
		void getHistoryMessageList(const QString& userId, int count, quint64 lasttime, UnitCallback<QSharedPointer<Biz::MessageListData>>* callback );
		void getGroupHistoryMessageList(const QString& userId, int count, quint64 lasttime, UnitCallback<QSharedPointer<Biz::MessageListData>>* callback );
		void getHistorySystemMsgList(const QString& userId, int count, quint64 lasttime, UnitCallback<QSharedPointer<Biz::MessageListData>>* callback);
		void getCollectionHistoryMessageList(const QString& parentid, const QString& userId, int count, quint64 lasttime, UnitCallback<QSharedPointer<Biz::MessageListData>>* callback);


    public:
        void getMessageFromServer();
    private:
		quint64 mlastMsgtime;
        
signals:
        void sgUpdateMessageSendStatus(const QSharedPointer<Biz::XmppMessage>& spMessage);
        void sgGetMessageFromServerProgress(bool end);
        void sgAtMessageInUnreadMessage(const QString& conversationid,QSharedPointer<Biz::XmppMessage> spMessage);
		void sgHistoryError(const QString& errMsg);
	public slots:
		void getOndutyMsg(const QString& virid);
		void onRevokeMessageReceived(const QSharedPointer<Biz::XmppMessage>& msg);
	};
}
