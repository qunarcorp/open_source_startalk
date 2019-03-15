#ifndef ROSTERITEM_H
#define ROSTERITEM_H

#include "CoreObject.h"
#include <QStandardItem>
#include <QItemDelegate>
#include <QPainter>
#include "PresenceStatus.h"

class rosterItem : public QObject, public QStandardItem
{
    Q_OBJECT
public:
    enum userRoles
    {
        StatusText = Qt::UserRole + 2,
        IsGroup,
        IsBlock,
        PresenceType,
        UserID,
        Avatar,
        UnreadCount,
        LastMessageTime,
        DisplayName,
        DisplayName_PINYIN,
        GroupDisplayName,
        GroupFullName,
        EntryCount,
        EntryOnlineCount,
        LastTimeDrawTime,
        LastTimeDrawResult,
    };

    rosterItem(const QString& userID, const QString& lastMsg, const QString& chatTime);
    rosterItem(const QString& groupName, const QString& gfullName);

    void setAvatar(const QImage& image);
    void setUserId(const QString& uid);
    void setDisplayName(const QString& dispName);
    void setDisplayPY(const QString& dispName);
    void setGroupName(const QString& gpName);
    void setUnreadCount(int count);
    void setEntryCount(int count);
    void setEntryOnlineCount(int count);
    void setRosterType(int);
    void setIsGroup(int i);
    void setIsBlock(int i);


    QImage getAvatar();    
    QString getUserId();
    QString getGroup();
    int getUnreadCount();
    int getEntryCount();
    int getEntryOnlineCount();
    QString getDisplayName();
    int isGroupItem();
    int getPresence();
    void setPresencce(PresenceStatus::AvailableStatusType);
signals:
    void sgUnreadCountChanged();
};

class rosterItemDelegate : public QItemDelegate
{
public:
    rosterItemDelegate();
    QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const;
    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;
private:
};

#endif // ROSTERITEM_H
