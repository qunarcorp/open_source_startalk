#ifndef SUBSCRIPTIONNUMLISTVIEW_H
#define SUBSCRIPTIONNUMLISTVIEW_H

#include <QListView>
class SubScriptionNumItemModel;
class SubScriptionNumItemSortProxyModel;

class SubScriptionNumListView : public QListView
{
	Q_OBJECT

public:
	SubScriptionNumListView(QWidget *parent);
	~SubScriptionNumListView();
	
private slots:
	void onSubScriptionRecive(const QStringList& list);
private:
	SubScriptionNumItemModel* msubscriptionItemModel;
	SubScriptionNumItemSortProxyModel* pSortFilterModel;
};

#endif // SUBSCRIPTIONNUMLISTVIEW_H
