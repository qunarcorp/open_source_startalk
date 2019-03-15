#include "combinationitemsortproxymodel.h"
#include "combinationitem.h"
#include "SystemDefine.h"

CombinationItemSortProxyModel::CombinationItemSortProxyModel(QObject *parent)
	: QSortFilterProxyModel(parent)
{
	setDynamicSortFilter(true);
	setFilterRole(Qt::DisplayRole);
	setFilterCaseSensitivity(Qt::CaseInsensitive);
}

CombinationItemSortProxyModel::~CombinationItemSortProxyModel()
{

}

bool CombinationItemSortProxyModel::lessThan( const QModelIndex &left, const QModelIndex &right ) const
{
    bool desc = false;

    QList<QString> sortids;
    sortids << Util::WorkPlaceId;
	sortids << Util::StarPersonId;
    sortids << Util::GroupsId;
    sortids << Util::OrganizationId;
    sortids << Util::FriendsId;
    sortids << Util::SUBSCRIPTIONNUM_ID;
    sortids << Util::BlackFriendsId;
    
    QString leftId = left.data(CombinationItem::Combinationid).toString ();
    QString rightId = right.data(CombinationItem::Combinationid).toString ();

    if (!leftId.isEmpty() && !rightId.isEmpty())
    {
        if (sortids.contains (leftId) && !sortids.contains (rightId))
            return !desc;
        else if (!sortids.contains (leftId) && sortids.contains (rightId))
            return desc;
        else
            return sortids.indexOf (leftId) < sortids.indexOf (rightId)?!desc:desc;
    }

	return desc;
}

bool CombinationItemSortProxyModel::filterAcceptsRow( int, const QModelIndex& ) const
{
	return true;
}
