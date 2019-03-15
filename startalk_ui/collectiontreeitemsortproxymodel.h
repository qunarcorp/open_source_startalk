#ifndef COLLECTIONTREEITEMSORTPROXYMODEL_H
#define COLLECTIONTREEITEMSORTPROXYMODEL_H

#include <QSortFilterProxyModel>

class CollectionTreeItemSortProxyModel : public QSortFilterProxyModel
{
	Q_OBJECT

public:
	CollectionTreeItemSortProxyModel(QObject *parent);
	~CollectionTreeItemSortProxyModel();

private:
	 bool lessThan(const QModelIndex &left, const QModelIndex &right) const;
};

#endif // COLLECTIONTREEITEMSORTPROXYMODEL_H
