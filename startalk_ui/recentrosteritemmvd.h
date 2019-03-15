#ifndef RECENTROSTERITEMMVD_H
#define RECENTROSTERITEMMVD_H

#include <QObject>

#include <QStandardItemModel>
#include <QItemDelegate>
class RecentRosterItem;


class RecentRosterModel : public QStandardItemModel
{
    Q_OBJECT
public:
    RecentRosterModel(QObject *parent);
    ~RecentRosterModel();
    RecentRosterItem* getItemFromUid(const QString& bareJid);
    void createItem(const QString& id, const QString& displayname,int viewid);
    void createGroupItem(const QString& id, const QString& displayname, int viewid);
    void removeItem(const QString& id, const QString& displayname);
    void updatevCard(const QString& id, const QImage& path);
    void updateUnReadCount(const QString&jid, int count);
private:    
    QMap<QString, RecentRosterItem*> m_uidItemMap;
};


class RecentRosterItem : public QObject, public QStandardItem {
    Q_OBJECT
public:
    RecentRosterItem(const QString& jid, const QString& gpName, bool autoJoin);
    RecentRosterItem(QObject* parent);
    ~RecentRosterItem();
    void setUID(const QString& id);
    void setAvatar(const QImage& image);
    void setViewId(int viewid);
    void setDispalyName(const QString& name);
    void setIsGroupChat(bool b = false);
    void setUnreadeCount(int count);
    enum DataKeys
    {
        GroupJid = Qt::UserRole + 1,
        GroupPY,
        Avatar,
        AutoJoin,
        AutoJoinPic,
        DispalyName,
        ViewID,
        UserID,
        IsGroupChat,
        UnreadeCount
    };
}; 

class RecentRosterItemDelegate : public QItemDelegate
{
public:
    RecentRosterItemDelegate();
    virtual QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    const int AVATER_HEIGHT;
    const int AVATER_WIDTH;
};


#endif // RECENTROSTERITEMMVD_H
