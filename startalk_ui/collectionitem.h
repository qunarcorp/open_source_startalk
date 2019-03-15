#ifndef COLLECTIONITEM_H
#define COLLECTIONITEM_H

#include <QObject>
#include <QStandardItem>
#include <QItemDelegate>
#include <QPainter>

class CollectionItem : public QObject, public QStandardItem
{
	Q_OBJECT

public:
	enum CollectionItemType
	{
		CollectionBindUser,
		CollectionBindItem
	};
	enum CollectionRoles
	{
		CollectionBindType = Qt::UserRole + 1000,
		UserID,
		BindUserDisplayName,
		BindItemDisplayName,
		Avatar,
		UnreadUserCount,
		UnreadItemCount,
		LastMessageTime
	};
	CollectionItem();
	CollectionItem(const QString& userid, const QString&userdispname);
	CollectionItem(const QString& userid, const QString&displayname, const QString& chatTime);
	~CollectionItem();
	void setCollectionItemType(int type);
	void setAvatar(const QImage& image);
	void setBindUserUnReadCount(int ncount);
	void setBindUserItemUnReadCount(int ncount);
	void setBindUserDisplay(const QString& displayname);
	void setBindUserItemDisplay(const QString& displayname);
private:
	
};




class CollectionItemDelegate:public QItemDelegate
{
public:
	CollectionItemDelegate();
	QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const;
	void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;
};
#endif // COLLECTIONITEM_H
