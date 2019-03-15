#pragma once

#include "QXmppIq.h"
#include "QXmppMucIq.h"

class QXMPP_EXPORT QXmppMucRoomMemberIq :   public QXmppIq
{   

public:
    class QXMPP_EXPORT Item
    {
    public:
        QString jid() const;
        void setJid(const QString &jid);

        QString name() const;
        void setName(const QString &name);

        QXmppMucItem::Affiliation affiliation() const;
        void setAffiliation(const QXmppMucItem::Affiliation& role);
    private:
        QString m_jid;
        QString m_name;
        QXmppMucItem::Affiliation m_affiliation;
    };

    QXmppMucRoomMemberIq(void);
    ~QXmppMucRoomMemberIq(void);
    
    QList<QXmppMucRoomMemberIq::Item>& items();

    static bool isMucRoomMemberIq(const QDomElement &element);
protected:
    /// \cond
    void parseElementFromChild(const QDomElement &element);
    void toXmlElementFromChild(QXmlStreamWriter *writer) const;
    /// \endcond
private:
    QList<Item> m_items;
};

