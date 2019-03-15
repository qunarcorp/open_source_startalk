#ifndef ROSTERLISTITEMADAPTER_H
#define ROSTERLISTITEMADAPTER_H

#include <QObject>
#include "ListWidgetBaseAdapter.h"

class RosterListItemAdapter : public ListWidgetBaseAdapter
{
    Q_OBJECT

public:
    RosterListItemAdapter(QListView *parent);
    ~RosterListItemAdapter();

    virtual QWidget* CreateNewWidget(const QModelIndex& index);

    virtual QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

    virtual void updateData(QWidget* pWidget,const QModelIndex& index,const QStyleOptionViewItem& option);

private:
    
};

#endif // ROSTERLISTITEMADAPTER_H
