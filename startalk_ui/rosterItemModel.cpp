#include "rosterItemModel.h"
#include "RosterList.h"
#include "Session.h"
#include "UserLogin.h"
#include "ConfigureHelper.h"
#include "AccountData.h"
#include "Account.h"
#include "RosterProfile.h"
#include "CallbackReceiver.h"
#include "UiHelper.h"
#include "portraithelper.h"

rosterItemModel::rosterItemModel(QObject* parent) : QStandardItemModel(parent)
{
    mReceiver = new Biz::CallbackReceiver(this);
}

 rosterItem* rosterItemModel::getRosterItemFromBareJid(const QString& bareJid)
 {
     if(m_jidRosterItemMap.contains(bareJid))
         return m_jidRosterItemMap[bareJid];
     else
         return 0;
 }

rosterItem* rosterItemModel::getOrCreateItem(const QString& userID, Biz::RosterItem* pItem/* = NULL*/)
{
    Log::assert(!userID.isEmpty());
   
    if(m_jidRosterItemMap.contains(userID)) {
        return m_jidRosterItemMap[userID];
    } else {
        rosterItem* item = NULL;
        if(pItem)
        {
            QString chatTime = QDateTime::fromMSecsSinceEpoch(pItem->lastMsgTime).toString("yyyy-MM-dd hh:mm:ss");            
            item = new rosterItem(userID, pItem->lastMsg, chatTime);        
            item->setUnreadCount(pItem->unReadCount);
        }
        else
        {
            item = new rosterItem(userID,"", "");
        }

        connect(item, &rosterItem::sgUnreadCountChanged, this, &rosterItemModel::onItemUnreadCountChanged);
        m_jidRosterItemMap[userID] = item;

        item->setUserId(userID);
      
        QImage image = Biz::PortraitHelper::getUserPortraitImage(userID);
        item->setAvatar(image);


        appendRow(item);

        /* auto callback = mReceiver->createCallback<QSharedPointer<ApiResponse::RosterProfile>>([this, item,userID](const QSharedPointer<ApiResponse::RosterProfile>& val)
        {
        userInfoUpdate(item, *val);
        }, []{});
        Biz::Session::currentAccount().getQunarUserInfo(userID, callback);*/
        return item;
    }
}

//void rosterItemModel::updatePresence(const QString& bareJid, const QMap<QString, QXmppPresence>& presences)
//{
//    rosterItem *item = getOrCreateItem(bareJid);
//    if (!presences.isEmpty())
//        item->setPresence(*presences.begin());
//    else
//        item->setPresence(QXmppPresence(QXmppPresence::Unavailable));
//}

void rosterItemModel::updateAvatar(const QString& bareJid, const QImage& image)
{
    getOrCreateItem(bareJid)->setAvatar(image);
}

void rosterItemModel::updatePresence(const QVariantList& presenceList)
{
    for(QVariant var : presenceList)
    {
        QVariantMap mapitem = var.toMap();   
        int presence = mapitem["S"].toInt();
        QString userid = mapitem["U"].toString();
        if (m_jidRosterItemMap.contains(userid))
        {
            if(presence == 6)
                getOrCreateItem(mapitem["U"].toString())->setPresencce(PresenceStatus::ONLINE);
            else
                getOrCreateItem(mapitem["U"].toString())->setPresencce(PresenceStatus::OFFLINE);
        }
        
    }
    //getOrCreateItem(bareJid)->setPresencce(status);
}

void rosterItemModel::updateName(const QString& bareJid, const QString& name)
{
//     if (!name.isEmpty())
//         getOrCreateItem(bareJid)->setName(name);
}

void rosterItemModel::clear()
{
    QStandardItemModel::clear();
    m_jidRosterItemMap.clear();
}

void rosterItemModel::removeRosterEntry(const QString& bareJid)
{
    rosterItem* item = getRosterItemFromBareJid(bareJid);
    if(item)
    {
        removeRow(item->row());
    }
}

bool rosterItemModel::setData( const QModelIndex &index, const QVariant &value, int role /*= Qt::EditRole*/ )
{
    return QStandardItemModel::setData(index, value, role);
}

void rosterItemModel::initRosterList(const QList<Biz::RosterItem*>& rosterList)
{
    foreach(Biz::RosterItem* pItem, rosterList){
        getOrCreateItem(pItem->userId,pItem);
        //getOrCreateItem(pItem->userId, pItem.value());
    }
}

void rosterItemModel::updateUnreadCount( const QString& userID, const int count )
{

}

void rosterItemModel::onItemUnreadCountChanged()
{
    auto total = 0;
    foreach(auto itor, m_jidRosterItemMap){
        total += itor->getUnreadCount();
    }
    emit sgUnreadMessageCountChanged(total);
}
