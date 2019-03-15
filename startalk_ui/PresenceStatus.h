#pragma  once
#include "QXmppPresence.h"

class PresenceStatus
{
public:
    enum AvailableStatusType
    {
        ONLINE = 0,      ///< The entity or resource is online.
        AWAY,           ///< The entity or resource is temporarily away.
        AWAY_FOR_EXTEND,             ///< The entity or resource is away for an extended period.
        DO_NOT_DISTURB,            ///< The entity or resource is busy ("Do Not Disturb").
        CHAT,           ///< The entity or resource is actively interested in chatting.
        INVISIBLE,       ///< obsolete XEP-0018: Invisible Presence
        OFFLINE
    };

    static AvailableStatusType getStatus( const QXmppPresence& presence)
    {
        AvailableStatusType status = OFFLINE;
        if(presence.type() == QXmppPresence::Type::Available)
        {
            switch (presence.availableStatusType())
            {
            case QXmppPresence::Online:
                status = ONLINE;
                break;
            case QXmppPresence::Away:
                status = AWAY;
                break;
            case QXmppPresence::XA:
                status = AWAY_FOR_EXTEND;
                break;
            case QXmppPresence::DND:
                status = DO_NOT_DISTURB;
                break;
            case QXmppPresence::Chat:
                status = CHAT;
                break;
            case QXmppPresence::Invisible:
                status = INVISIBLE;
                break;
            default:
                status = OFFLINE;
                break;
            }    
        }//end if
        return status;
    }
};

