#ifndef VIRTUALACCOUNTMANAGER_H
#define VIRTUALACCOUNTMANAGER_H

#include "managerbase.h"
#include "qxmppvirtualaccountmanager.h"

class QXmppVirtualAccountManager;

namespace Biz
{
	class virtualAccountManager : public ManagerBase
	{
		Q_OBJECT

	public:
		virtualAccountManager();
		~virtualAccountManager();
		virtual void initManager();

		virtual void unInitManager();
	public:
		QString getRealAccount(const QString&vraccount);
		void getVirtualAccountIdentity();
		void getvirtualaccountList();
		void getRealAccountbyVirtualAccount(const QString& vraccount);
		void setvirtualaccountEndChat(const QString& vraccount);
		void getRealAccountbyVirtualAccount(const QString& vraccount, Biz::UnitCallback<QString>* callback);
		QStringList getOndutyVirtual() {return m_currentvrOfselfId;};
		bool IsVirtualAccount(const QString& id);
		void getRealAccountsbyVirtualAccounts(const QString& vraccount, Biz::UnitCallback<QStringList>* callback);
	private:
		Biz::CallbackReceiver* mCallbackReceiver;
		QXmppVirtualAccountManager* virtualManagerExterd;
		QStringList m_vraccountList; //虚拟账号列表
		QStringList m_currentvrOfselfId;  //当前自己值班的虚拟账号

		QMap<QString, QString> m_vrAccountofrealmap; //虚拟账号对应的真实账号

signals:
		void sgVirtualAccountRealId(const QString&realId, const QString&vraccount);
		void sgTimeOutEnd(const QString& virtualId);
		void sgVirtualAccountChangeRealId(const QString& virtualId, const QString& realid);
	public slots:
		void onConnected();
		void onVirtualAccountListReceived(const QStringList& vraccountlist);
		void onTimeOutEnaChat(const QString& virtualId);
		void onVirtualAccountofrealIdChange(const QString&virtualId, const QString&realId);

		void onVirtualAccountReadId(const QString&realId, const QString&vraccount);
		void onVirtualEndChat(const QString& virtualId);
		void onVirtualAccountChangeRealId(const QString& virtualId, const QString&realId);
	};
}


#endif // VIRTUALACCOUNTMANAGER_H
