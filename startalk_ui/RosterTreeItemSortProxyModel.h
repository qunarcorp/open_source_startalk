#ifndef ROSTERTREEITEMSORTPROXYMODEL_H
#define ROSTERTREEITEMSORTPROXYMODEL_H

#include <QSortFilterProxyModel>

class RosterTreeItemSortProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    RosterTreeItemSortProxyModel(QObject *parent);
    ~RosterTreeItemSortProxyModel();
    public slots:

private:
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const;
    bool filterAcceptsRow(int, const QModelIndex&) const;

};

#endif // ROSTERTREEITEMSORTPROXYMODEL_H
