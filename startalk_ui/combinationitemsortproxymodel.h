#ifndef COMBINATIONITEMSORTPROXYMODEL_H
#define COMBINATIONITEMSORTPROXYMODEL_H

#include <QSortFilterProxyModel>

class CombinationItemSortProxyModel : public QSortFilterProxyModel
{
	Q_OBJECT

public:
	CombinationItemSortProxyModel(QObject *parent);
	~CombinationItemSortProxyModel();

private:
	bool lessThan(const QModelIndex &left, const QModelIndex &right) const;
	bool filterAcceptsRow(int, const QModelIndex&) const;
};

#endif // COMBINATIONITEMSORTPROXYMODEL_H
