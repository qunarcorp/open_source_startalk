#ifndef QXMPPROOMNEGATIVE_H
#define QXMPPROOMNEGATIVE_H

#include <QObject>
#include "QXmppStanza.h"
#include "../QXmpp/base/QXmppPresence.h"
#include "../QXmpp/base/QXmppMessage.h"


class QXmppClient;
class QXmppMucRoomNegativePrivate;
class QXmppMucRoomMemberIq;
class QXmppMucInvitaionIqV2;
class QXmppMucJoinIq;
class QXmppMucMsgNoticeIq;

class QXMPP_EXPORT QXmppRoomNegative : public QObject
{
    Q_OBJECT
        Q_PROPERTY(QString jid READ jid CONSTANT)
public:
        ~QXmppRoomNegative();

    QString jid() const;

    void setOwnJid(const QSet<QString>& ownsJids);
    bool isOwnJis(const QString& bareJid);
    

    bool joinRoom(QXmppMucJoinIq& iq);
    bool kickMember(const QString& selectname, const QString& userid,const QString &reason,QXmppMucAdminIq& requstIq);
    bool groupRegister();
    bool groupDeRegister();
	bool getMemberList(const QString& jid,QXmppMucRoomMemberIq& roomMemberIq); 


	bool setConfiguration(const QXmppDataForm &form);
	bool setPermissions(const QList<QXmppMucItem> &permissions);
	bool setMemberAffiliation(const QString &jid, const QString& selectname, QXmppMucItem::Affiliation nAffi);
	bool destroy(const QString& reason,const QString& replaceJid, const QString& replacePwn);
	bool sendInvitaionIq(const QStringList &jids,QXmppMucInvitaionIqV2& iqRef);

	bool setRoomMsgNotice(const QString& jid, int type, QXmppMucMsgNoticeIq&mucmsgiq);
private:
    virtual bool handlePresence(const QDomElement &element);
private:
    QXmppRoomNegative(QXmppClient *client, const QString &jid, QObject *parent);
    QXmppMucRoomNegativePrivate *d;
    friend class QXmppMucManagerNegative;


signals:
    /// This signal is emitted when the configuration form for the room is received.
    void configurationReceived(QXmppRoomNegative* pthis,const QXmppDataForm &configuration);

    /// This signal is emitted if you get kicked from the room.
    void kicked(QXmppRoomNegative* pthis,const QString &jid, const QString &reason);

    /// This signal is emitted when a participant joins the room.
    void participantAdded(QXmppRoomNegative* pthis,const QXmppPresence &presence);

    /// This signal is emitted when a participant leaves the room.
    void participantRemoved(QXmppRoomNegative* pthis,const QXmppPresence &presence);

    // joinfail
    void joinFail(int errorcode);

    /// This signal is emitted when the room had been destroyed by admin.
    void roomDestroyed(QXmppRoomNegative* pthis,const QString& jid);

    void delRegisterRecved(QXmppRoomNegative* pthis,const QString&roomjid, const QString& userid);

    //修改群名
    void sgroomNameUpdate(QXmppRoomNegative* pthis,const QString&roomjid);

    //被拖入群
	void participantCoverAdd(QXmppRoomNegative* pthis,const QXmppPresence &presence);
	 
        private slots:
            void _q_presenceReceived(const QXmppPresence &presence);
            void _q_iqReceived(const QXmppIq& iq);

};

#endif // QXMPPROOMNEGATIVE_H
