#include "rosterItemSortFilterProxyModel.h"
#include "rosterItem.h"
#include "UiHelper.h"

rosterItemSortFilterProxyModel::rosterItemSortFilterProxyModel(QObject* parent):
    QSortFilterProxyModel(parent),
    m_showOfflineContacts(true),
    m_sortByName(false)
{
    setDynamicSortFilter(true);
    setFilterRole(Qt::DisplayRole);
    setFilterCaseSensitivity(Qt::CaseInsensitive);
}

bool rosterItemSortFilterProxyModel::lessThan(const QModelIndex &left, const QModelIndex &right) const
{
    auto leftDateTime = left.data(rosterItem::LastMessageTime).toDateTime();
    auto rightDateTime = right.data(rosterItem::LastMessageTime).toDateTime();
    if(leftDateTime.toTime_t() == rightDateTime.toTime_t()){

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
    }
    return leftDateTime.toTime_t() > rightDateTime.toTime_t();

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

bool rosterItemSortFilterProxyModel::filterAcceptsRow(int source_row, const QModelIndex& source_parent) const
{
    if(!filterRegExp().isEmpty())
        return QSortFilterProxyModel::filterAcceptsRow(source_row, source_parent);

    if(m_showOfflineContacts)
        return true;

    QModelIndex index = sourceModel()->index(source_row, 0, source_parent);

    int presenceType = sourceModel()->data(index, rosterItem::PresenceType).toInt();

    if(presenceType == QXmppPresence::Available)
        return true;
    else
        return false;
}

void rosterItemSortFilterProxyModel::setShowOfflineContacts(bool showOfflineContacts)
{
    m_showOfflineContacts = showOfflineContacts;
    invalidateFilter();
}

void rosterItemSortFilterProxyModel::sortByName(bool sortByName)
{
    m_sortByName = sortByName;
    invalidate();
}