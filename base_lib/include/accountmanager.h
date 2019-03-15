#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include <QObject>
#include "managerbase.h"
#include "AccountData.h"
#include "Player.h"
#include "MessageListData.h"
namespace Biz
{
	class GroupListData;
	class ImSelfPerson;
    class CheckConfigInfo;
    class UserSettingData;
	class WorkStatusData;

	class AccountManager : public ManagerBase
	{
		Q_OBJECT

	public:
		AccountManager();
		~AccountManager();

		virtual void initManager();

		virtual void unInitManager();

		AccountData& accountData();

		void getPushStatus(Biz::UnitCallback<bool>* callback);
		void setPushStatus(int status, Biz::UnitCallback<QString>* callback);
        void getWorkStatus(Biz::UnitCallback<QList<QSharedPointer<Biz::WorkStatusData>>>* callback);
		void setWorkStatus(int status, int shopid,Biz::UnitCallback<QString>* callback);
		void updateSystemMessageById(const QString& userid, int status);
		void getSystemMsgTableRecordCount(Biz::UnitCallback<int>* callback);
		void getSystemMsgbyMsgType(const QStringList& msgType,quint64 tm, Biz::UnitCallback<QSharedPointer<Biz::MessageListData>>* callback);
		void getSystemMsgType(Biz::UnitCallback<QStringList>* callback);
		void getNotelastmsgtm(const QString& userid, Biz::UnitCallback<quint64>* callback);
		void getLastmsgtm(const QString& userid, Biz::UnitCallback<quint64>* callback);
		void insertWebInfo(const QSharedPointer <Biz::WebUserInfo>& webinfor );
		void getDisplayNameInWebInfo(const QString& userid, QString& strNick);
		void updateWebInfo(const QString& userid, const QString& city);
		void GetChatAllUserUins(const QString& uis, Biz::UnitCallback<QString>* callback);
		void GetChatRosterUins(Biz::UnitCallback<QStringList>* callback);
		void getShopInfo(const QString&searchkey, Biz::UnitCallback<QString>* callback);
		void getOriganizeByShopId(quint32 shopid, Biz::UnitCallback<QString>* callback);
		QStringList GetChatRosterUins();
		quint64 getLastmsgtm(const QString& userid);

		void sendwelcome(const QString& seatQId, const QString& userQId, const QString& shopid, const QString&businessline);
		void sendNote(const QString& seatQId, const QString& userQId, const QString& shopid, const QString& productId, const QString&businessline );
		void collectLogs(Biz::UnitCallback<QString>* callback);
		void collectLogsToSendEmail(Biz::UnitCallback<QString>* callback);
        // 重新加载当前所选账户的缓存
        void resetCurrentUserData(const QString& userid);

		QStringList GetChatAllUserUins();
		GroupListData* getGroupsData();
		void saveGrouplistData();
        QSharedPointer<Biz::CheckConfigInfo> getCheckConfigInfo();
        QSharedPointer<Biz::UserSettingData> getCurrentUserSettingData();
		void setCurrentUserSettingData(const QSharedPointer<Biz::UserSettingData>& usersettingdata);
        void getUserIdByGroupResource(const QString& groupid,const QString& resource,Biz::UnitCallback<QString>* callback);
		void collectLogsToSendEmailBeforLogin(Biz::UnitCallback<QString>* callback);

signals:
		void sgcollectLogsInfo(const QString&infor);
	private:
		CallbackReceiver* mReceiver;
	        
    };
}


#endif // ACCOUNTMANAGER_H
