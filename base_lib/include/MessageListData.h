#pragma once
#include "CoreObject.h"
#include <QMetaType>
#include "XmppMessage.h"
#include "Player.h"
namespace Biz
{
    class MessageListData : public QObject
    {
		Q_OBJECT
    public:
        MessageListData(void);
		MessageListData(const MessageListData&rh);
		const MessageListData& operator=(const MessageListData&rh);
        ~MessageListData(void);
        void addMessageItem(QSharedPointer<XmppMessage>);
        bool HasMore() const { return bHasMore; }
        void HasMore(bool val) { bHasMore = val; }
        long getTimeStamp();
        void RemoveMessageItem(int idx);
        QList<QSharedPointer<XmppMessage>>& getMessageList() { return mList; }
		void setReadMsgLst(quint64 msglst) {ulstReadMsg = msglst;}
		quint64 getReadMsglst(){return ulstReadMsg;}
		QString getGroupJid(){return strGroupJid;}
		void setGroupJid(const QString&strgroupjid){strGroupJid = strgroupjid;}
    private:
        QList<QSharedPointer<XmppMessage>> mList;       
        bool bHasMore;
		quint64 ulstReadMsg;
		QString strGroupJid;
		bool bFilterSystem;
        
    };



	class RecordInfor
	{
	public:
		RecordInfor(){};
		RecordInfor(const RecordInfor&rh)
		{
			this->strgroupjid = rh.strgroupjid;
			this->strgroupnickName = rh.strgroupnickName;
			this->messagelistdata = rh.messagelistdata;
			this->msgcount = rh.msgcount;
			this->msgtime = rh.msgtime;
		}
		const RecordInfor& operator=(const RecordInfor&rh)
		{
			this->strgroupjid = rh.strgroupjid;
			this->strgroupnickName = rh.strgroupnickName;
			this->messagelistdata = rh.messagelistdata;
			this->msgcount = rh.msgcount;
			this->msgtime = rh.msgtime;
			return *this;
		}
		~RecordInfor(){};
		QString strgroupjid;
		QString strgroupnickName;
		int msgcount;
		qint64 msgtime;
		QSharedPointer<Biz::MessageListData> messagelistdata;
	};

	class RecordInforBegEndTm
	{
	public:
		RecordInforBegEndTm(){uBeginTm=0; uEndTm=0;};
		~RecordInforBegEndTm(){};
		RecordInforBegEndTm(const RecordInforBegEndTm&recordbetm){ this->uBeginTm = recordbetm.uBeginTm; this->uEndTm = recordbetm.uEndTm;};

		quint64 uBeginTm;
		quint64 uEndTm;
	};

	class RecordInforBegEndTmList
	{
	public:
		RecordInforBegEndTmList(){};
		~RecordInforBegEndTmList(){};
		void setcontainsmsgtim(quint64 msgtm)
		{
			mcontainsmsgtm = msgtm;
		}
		quint64 getcontainsmsgtime() const 
		{
			return mcontainsmsgtm;
		}
		void setRecordInforinsertlist(const RecordInforBegEndTm& tm)
		{
			mList.append(tm);
		}
		const QList<RecordInforBegEndTm>& getRecordInforList() const { return mList; }
	private:
		QList<RecordInforBegEndTm> mList;
		quint64 mcontainsmsgtm;
	};

    class SearchResultModule
    {
    public:
        SearchResultModule(void);
        SearchResultModule(const SearchResultModule&rh);
        const SearchResultModule& operator=(const SearchResultModule&rh);

        ~SearchResultModule(void);

        inline const QList<QPair<QString,QString>>& getResultList() const  { return resultList;};
        inline void settResultList(const QList<QPair<QString,QString>>& list) {this->resultList = list;};

        inline const QStringList& getRooms() const {return roomList;};
        inline void setRooms(const QStringList& list){this->roomList = list;};
    private:
        QList<QPair<QString,QString>> resultList;
        QStringList roomList;
    }; 
	

	class AddFriendsRecordInfo
	{
	public:
		AddFriendsRecordInfo();
		~AddFriendsRecordInfo();
		QString getUserid();
		quint64 getRequesTime();
		int getbyAddStatus();
		quint64 getResponsTime();
	private:
		QString mstrUserid;
		quint64 requestTime;
		int byAddStatus;
		quint64 responseTime;
		int status;

	};

    class SearchResulteItemModule
    {
    public:
        QString conversationId;
        QString valueFirst;
        QString valueSecend;
        MessageSourceType chatType; 
    };
    class SearchResulteItemGroupModule 
    {
    public:
		SearchResulteItemGroupModule(){hasmore = false;}
        QList<SearchResulteItemModule> mItemList;
        QString groupName;
		QString id;
		bool hasmore;
    };


}

	Q_DECLARE_METATYPE(Biz::MessageListData);