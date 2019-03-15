#ifndef ROSTERITEMSORTFILTERPROXYMODEL_H
#define ROSTERITEMSORTFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>

class rosterItemSortFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    rosterItemSortFilterProxyModel(QObject* parent = 0);

    public slots:
        void setShowOfflineContacts(bool);
        void sortByName(bool);

private:
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const;
    bool filterAcceptsRow(int, const QModelIndex&) const;

    bool m_showOfflineContacts;
    bool m_sortByName;
};

#endif // ROSTERITEMSORTFILTERPROXYMODEL_H
