#include "collectiontreeitemsortproxymodel.h"

CollectionTreeItemSortProxyModel::CollectionTreeItemSortProxyModel(QObject *parent)
	: QSortFilterProxyModel(parent)
{
	setDynamicSortFilter(true);
	setFilterRole(Qt::DisplayRole);
	setFilterCaseSensitivity(Qt::CaseInsensitive);
}

CollectionTreeItemSortProxyModel::~CollectionTreeItemSortProxyModel()
{

}

bool CollectionTreeItemSortProxyModel::lessThan( const QModelIndex &left, const QModelIndex &right ) const
{
	return true;
}
