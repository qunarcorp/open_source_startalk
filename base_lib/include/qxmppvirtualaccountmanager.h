#ifndef QXMPPVIRTUALACCOUNTMANAGER_H
#define QXMPPVIRTUALACCOUNTMANAGER_H

#include <QObject>
#include "QXmppClientExtension.h"
//#include "qxmppvirtualaccountiq.h"
class QVirtualAccountIdentityIq;
class QVirtualAccountListIq;
class QVirtualAccountSessionIq;
class QVirtualAccountEndChatIq;

class QXMPP_EXPORT QXmppVirtualAccountManager : public QXmppClientExtension
{
	Q_OBJECT

public:
	QXmppVirtualAccountManager();
	~QXmppVirtualAccountManager();
	void getVirtualAccountIdenty(QVirtualAccountIdentityIq&iq);
	void getvirtualaccountList(const QString&id, QVirtualAccountListIq&iq);
	void getRealAccountbyVirtualAccount(const QString&id, QVirtualAccountSessionIq&iq);
	void setVirtualAccountEndChat(const QString&id, QVirtualAccountEndChatIq&iq);

protected:
	virtual bool handleStanza(const QDomElement &stanza);
	virtual bool handleIq(const QDomElement& iq);
	virtual bool handlePresence(const QDomElement& presence);

signals:
	void sgTimeoutEndChat(const QString& virtualId);
	void sgChangeVirtualOfRealId(const QString& virtualId, const QString&realid);
private:
	
};

#endif // QXMPPVIRTUALACCOUNTMANAGER_H
