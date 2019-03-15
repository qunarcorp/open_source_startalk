#pragma once

#include "QXmppIq.h"

class QXMPP_EXPORT QXmppMucRoomListIq :   public QXmppIq
{

public:
    class QXMPP_EXPORT Item
    {
    public:
        QString host() const;
        void setHost(const QString &host);

        QString name() const;
        void setName(const QString &name);
        
        QString jid();
    private:
        QString m_host;
        QString m_name;
    };

public:
    QXmppMucRoomListIq(void);
    ~QXmppMucRoomListIq(void);
    
    QList<QXmppMucRoomListIq::Item> items() const;
    QStringList roomList() const;
    static bool isMucRoomListIq(const QDomElement &element);
protected:
    /// \cond
    void parseElementFromChild(const QDomElement &element);
    void toXmlElementFromChild(QXmlStreamWriter *writer) const;
    /// \endcond
private:
    QList<QXmppMucRoomListIq::Item> m_items;
    QStringList m_roomList;
};

