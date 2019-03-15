#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QTableView>
#include "Historyrecordmodel.h"
#include <QList>

class TableView : public QTableView
{
	Q_OBJECT

public:
	TableView(QWidget *parent = 0);
	~TableView();

	void addRow(QStringList rowList);
	void addRowInFront(QStringList rowList);
	int rowCount();
	void SetHeaderList(const QStringList& list);
	void setRowData(const QModelIndex& index,const QStringList& data);
	QHeaderView *head;
	QList<QStringList> GetAllRowData();
signals:
	void updateCount(int count); 
public slots:
	void remove();
	void clear();
	void changeValue();  
private:
	void initHeader();

	HistoryRecordModel *model;
	QList<QStringList> grid_data_list;
	HistoryRecordDelegate *delegate;
	QStringList mstrheaderList;
	

	
};

#endif // TABLEVIEW_H
