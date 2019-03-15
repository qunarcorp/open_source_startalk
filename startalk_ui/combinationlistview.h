#ifndef COMBINATIONLISTVIEW_H
#define COMBINATIONLISTVIEW_H

#include <QListView>
class CombinationItemModel;
class CombinationItemSortProxyModel;
class CombinationListView : public QListView
{
	Q_OBJECT

public:
	CombinationListView(QWidget *parent);
	~CombinationListView();
	void addOneItem(const QString& jid,const QString& name);
	void setItemExtendable(const QString& id,bool bExtendable);
    void setItemImage(const QString& id, const QImage& image);
	void setItemUnReadIconable(const QString& id, bool bExtendable);
	void setItemUnReadCount(const QString&id, int ncount);
	void deleteOneItem(const QString&jid, const QString& strDisplayname);
private slots:
	void onitemClicked(const QModelIndex&);
	void onItemdoubleClicked(const QModelIndex& index);
	void onWorkSpaceCountChange(int ncount);
signals:
	void sgcombinationItemClicked(const QString& id);
private:
	CombinationItemModel *mcombinationItemModel;
	CombinationItemSortProxyModel* pSortFilterModel;
	quint64 lastDbClickTick;
};

#endif // COMBINATIONLISTVIEW_H
