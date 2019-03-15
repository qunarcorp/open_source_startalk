#ifndef PUBLICACCOUNTITEM_H
#define PUBLICACCOUNTITEM_H

#include <QObject>
#include <QStandardItem>
#include <QItemDelegate>

class PublicAccountItem : public QObject, public QStandardItem
{
	Q_OBJECT

public:
	PublicAccountItem(const QString&id, const QString& name);
	~PublicAccountItem();
	QString getPublicAccountItemid();
	void setPublicAccountName(const QString& pName);
	enum userRoles
	{
		PublicAccountid = Qt::UserRole + 1,
		Avatar,
		PulicAccountPY
	};
private:
	
};

class PublicAccountItemDelegate : public QItemDelegate
{
public:
	PublicAccountItemDelegate();
	QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const;
	void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;

private:
};
#endif // PUBLICACCOUNTITEM_H
