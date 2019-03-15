#ifndef GROUPVISITORSORTPROXYMODEL_H
#define GROUPVISITORSORTPROXYMODEL_H

#include <QSortFilterProxyModel>

class GroupVisitorSortProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    GroupVisitorSortProxyModel(QObject *parent);
    ~GroupVisitorSortProxyModel();
private:
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const;
    bool filterAcceptsRow(int, const QModelIndex&) const;
    
};

#endif // GROUPVISITORSORTPROXYMODEL_H
