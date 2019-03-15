#ifndef COMBINATIONITEM_H
#define COMBINATIONITEM_H

#include <QStandardItem>
#include <QItemDelegate>

class CombinationItem : public QObject, public QStandardItem
{
	Q_OBJECT

public:
	CombinationItem(const QString& id, const QString& gpName);
	~CombinationItem();
	QString getCombinationItemid();
    void setCombinationExtendable(bool bExtendable);
    void setIconImage(const QImage& image);
	void setCombinationUnReadIconable(bool banble);
	void setCombinationUnReadIconCount(int count);
	enum userRoles
	{
		Combinationid = Qt::UserRole + 1,
		Avatar,
        BackWardEnable,
		BackWardAvatar,
		UnReadIconEnable,
		UnReadCount
	};
private:
	
};
class CombinationItemDelegate : public QItemDelegate
{
public:
	CombinationItemDelegate();
	QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const;
	void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;

private:
};
#endif // COMBINATIONITEM_H
