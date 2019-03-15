#include "RosterTreeItemSortProxyModel.h"
#include "rosterItem.h"
#include "UiHelper.h"

RosterTreeItemSortProxyModel::RosterTreeItemSortProxyModel(QObject *parent)
    : QSortFilterProxyModel(parent)
{
    setDynamicSortFilter(true);
    setFilterRole(Qt::DisplayRole);
    setFilterCaseSensitivity(Qt::CaseInsensitive);
}

RosterTreeItemSortProxyModel::~RosterTreeItemSortProxyModel()
{

}

bool RosterTreeItemSortProxyModel::lessThan(const QModelIndex &left, const QModelIndex &right) const
{
    QString leftGroupName = left.data(rosterItem::GroupDisplayName).toString();
    QString rightGroupName = right.data(rosterItem::GroupDisplayName).toString();
    if(!leftGroupName.isEmpty() && rightGroupName.isEmpty())
        return false;
    else if(leftGroupName.isEmpty() && !rightGroupName.isEmpty())
        return true;
    else if(!leftGroupName.isEmpty() && !rightGroupName.isEmpty())
    {
        QString leftDisplayName = left.data(rosterItem::DisplayName_PINYIN).toString();
        QString rightDisplayName = right.data(rosterItem::DisplayName_PINYIN).toString();
        return leftDisplayName.compare(rightDisplayName) < 0;
    }
    //两个子节点，比在线状态
    else if(leftGroupName.isEmpty() && rightGroupName.isEmpty())
    {
        int leftPresenceType = left.data(rosterItem::PresenceType).toInt();
        int rightPresenceType= right.data(rosterItem::PresenceType).toInt();
        if(leftPresenceType != PresenceStatus::OFFLINE && rightPresenceType == PresenceStatus::OFFLINE)
            return true;
        if(leftPresenceType == PresenceStatus::OFFLINE && rightPresenceType != PresenceStatus::OFFLINE)
            return false;
        if(leftPresenceType == rightPresenceType){
            //相等比较名称
            QString leftDisplayName = left.data(rosterItem::DisplayName_PINYIN).toString();
            QString rightDisplayName = right.data(rosterItem::DisplayName_PINYIN).toString();
            return leftDisplayName.compare(rightDisplayName) < 0;
        }else{
            return leftPresenceType<rightPresenceType;
        }
    }
    return false;
    /*if(leftDateTime.toTime_t() == rightDateTime.toTime_t()){

        QString leftName = "";
        {
            if(!left.data(Qt::DisplayRole).toString().isEmpty())
                leftName = left.data(Qt::DisplayRole).toString();
            else
                leftName = left.data(rosterItem::UserID).toString();
        }
        QString rightName = "";
        {
            if(!right.data(Qt::DisplayRole).toString().isEmpty())
                rightName = right.data(Qt::DisplayRole).toString();
            else
                rightName = right.data(rosterItem::UserID).toString();
        }

        return leftName.compare(rightName);
    }*/
    //return leftDateTime.toTime_t() > rightDateTime.toTime_t();

    //if(m_sortByName)
    //{
    //    int compare = left.data().toString().compare(right.data().toString(), Qt::CaseInsensitive);
    //    if(compare < 0)
    //        return true;
    //    else
    //        return false;
    //}
    //else
    //{
    //    int leftPresenceType = sourceModel()->data(left, rosterItem::PresenceType).toInt();
    //    int leftStatusType = sourceModel()->data(left, rosterItem::StatusType).toInt();
    //    int rightPresenceType = sourceModel()->data(right, rosterItem::PresenceType).toInt();
    //    int rightStatusType = sourceModel()->data(right, rosterItem::StatusType).toInt();

    //    if(leftPresenceType == rightPresenceType)
    //    {
    //        if(leftStatusType == rightStatusType)
    //        {
    //            // based on display text
    //            int compare = left.data().toString().compare(right.data().toString(), Qt::CaseInsensitive);
    //            if(compare < 0)
    //                return true;
    //            else
    //                return false;
    //        }
    //        else
    //        {
    //            return MainApp::comparisonWeightsPresenceStatusType(static_cast<QXmppPresence::AvailableStatusType>(leftStatusType)) <
    //                MainApp::comparisonWeightsPresenceStatusType(static_cast<QXmppPresence::AvailableStatusType>(rightStatusType));
    //        }
    //    }
    //    else
    //        return MainApp::comparisonWeightsPresenceType(static_cast<QXmppPresence::Type>(leftPresenceType)) <
    //        MainApp::comparisonWeightsPresenceType(static_cast<QXmppPresence::Type>(rightPresenceType));
    //}
}

bool RosterTreeItemSortProxyModel::filterAcceptsRow(int source_row, const QModelIndex& source_parent) const
{
    if(!filterRegExp().isEmpty())
        return QSortFilterProxyModel::filterAcceptsRow(source_row, source_parent);
    return true;
    /*QModelIndex index = sourceModel()->index(source_row, 0, source_parent);
    int presenceType = sourceModel()->data(index, rosterItem::PresenceType).toInt();
    if(presenceType == PresenceStatus::ONLINE)
        return true;
    else
        return false;*/
}

