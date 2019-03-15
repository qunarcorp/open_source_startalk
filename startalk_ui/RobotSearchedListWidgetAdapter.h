#ifndef ROBOTSEARCHEDLISTWIDGETADAPTER_H
#define ROBOTSEARCHEDLISTWIDGETADAPTER_H

#include <QObject>
#include <QStandardItem>
#include <QItemDelegate>
#include <QListView>

#include "ListWidgetBaseAdapter.h"

enum RobotShearchedData
{
	RobotShearchedDataBase = Qt::UserRole,
	RobotShearchedDataRbtId = RobotShearchedDataBase+1
};
namespace Biz{
	class RobotVcard;
}
class RobotListWidgetAdapter : public ListWidgetBaseAdapter
{
public:
	RobotListWidgetAdapter(QListView *parent);
	~RobotListWidgetAdapter();
	virtual QWidget* CreateNewWidget(const QModelIndex& index);
	virtual QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
private:
	
};

class RobotSearchResultListAdapter : public ListWidgetBaseAdapter
{
public:
	RobotSearchResultListAdapter(QListView* parent);
	~RobotSearchResultListAdapter();
	virtual QWidget* CreateNewWidget(const QModelIndex& index);
	virtual QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
	void setRobotVcard(const QMap<QString,QSharedPointer<Biz::RobotVcard>>& rbtMap);
private:
	QMap<QString,QSharedPointer<Biz::RobotVcard>> rbtCatche;
};

#endif // ROBOTSEARCHEDLISTWIDGETADAPTER_H
