#ifndef SUBSCRIPTIONNUMITEM_H
#define SUBSCRIPTIONNUMITEM_H

#include <QObject>
#include <QStandardItem>
#include <QItemDelegate>
#include <QPainter>
class SubscriptionNumItem : public QObject, public QStandardItem
{
	Q_OBJECT

public:
	SubscriptionNumItem(const QString& jid, const QString& gpName, bool autoJoin);
	~SubscriptionNumItem();
	QString getSubcriptionNumName();
	void setSubcriptionNumName(const QString& subscripName);

	void updateSubcriptionNumAvatar();

	QString getSubcriptionNumJid();
	enum userRoles
	{
		SubcriptionNumJid = Qt::UserRole + 1,
		SubcriptionNumPY,
		Avatar,
	};
private:
	
};

class SubscriptionNumItemDelegate : public QItemDelegate
{
public:
	SubscriptionNumItemDelegate();
	QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const;
	void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;

private:
};



#endif // SUBSCRIPTIONNUMITEM_H
