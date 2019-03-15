#ifndef ROBOTMANAGER_H
#define ROBOTMANAGER_H
#include <QSound>
#include "managerbase.h"
#include "DAOLogic.h"
#include "BizCallback.h"
#include <QSound> 
namespace Biz
{
    class RobotVcard;
}

namespace Biz
{
	class RobotManager : public ManagerBase
	{
		Q_OBJECT

	public:
		RobotManager();
		~RobotManager();
	public:
		virtual void initManager();
		virtual void unInitManager();
    public:
		void getRobotList();
        QString getRobotName(const QString& robotid);;
        QStringList getExtendPath(const QString& peerid);
        QString getBelongExtendId(const QString& peerid);
        void initExtendIdPair(const QMap<QString,QString>& pairs);
		QStringList getSubscriptedRobotList();
		void getAllRobot();
        QSharedPointer<Biz::RobotVcard> getRobotVcard(const QString& userid);
        void getRobotVcardOnline(const QString& userid);
        void getRobotVcardOnline(const QString& robotid,Biz::UnitCallback<QSharedPointer<Biz::RobotVcard>>* callback);
		void searchRobot(const QString& keyWord,Biz::UnitCallback<QList<QSharedPointer<Biz::RobotVcard>>>*callback);
		void subscriptRobot(const QString& rbtid,Biz::UnitCallback<QString>* callback);
		void unSubscriptRobot(const QString& rbtid,Biz::UnitCallback<QString>* callback);
		bool isSubScriptedRobot(const QString& rbtid);

        void patchALocalMessage(const QSharedPointer<Biz::XmppMessage>& spmessage);
    private:
       
	   void initRobotList(const QStringList& rbtlst);
	private:
        QMap<QString,QString> mExtendMap;
        QMap<QString,QSharedPointer<Biz::RobotVcard>> mRobotVcards;
        QSound sound;
signals:
        void sgSubScriptionReceived(const QSharedPointer<XmppMessage>& robotMessage);
        void sgRobotVcardUpdated(const QList<QSharedPointer<Biz::RobotVcard>>& updatedList);
        void sgVcardUpdateNotify(const QStringList& rbtids);
		void sgRobotSubscriptedListChange();
        void sgRobotUnsubscripted(const QString& rbtjid);
        void sgRobotWeiDaoYouMessage(const QSharedPointer<Biz::XmppMessage>& message);
		void sgAllRobotList(const QStringList& robotlist);
        public slots:
            void onMessageReceived(const QXmppMessage& msg);
            void onRobotVcardUpdated(const QList<QSharedPointer<Biz::RobotVcard>>& updatedList);
			void onConnected();
	};
}


#endif // ROBOTMANAGER_H
