#include "Tableview.h"
#include <QHeaderView>

TableView::TableView(QWidget *parent)
	: QTableView(parent)
{
    model = new HistoryRecordModel();
    this->setModel(model);
    this->initHeader();
    model->setModalDatas(&grid_data_list);
	this->setAlternatingRowColors(true);
    this->setStyleSheet( "QTableView{border:none;selection-background-color: blue}" ); 
	this->setSelectionBehavior(QAbstractItemView::SelectRows);
	this->horizontalHeader()->setStretchLastSection(true);
	this->horizontalHeader()->setHighlightSections(false);
    this->horizontalHeader()->setCascadingSectionResizes(true);
	this->verticalHeader()->setVisible(false);
	this->setShowGrid(false);
	this->setEditTriggers(QAbstractItemView::NoEditTriggers);
	this->setSelectionMode(QAbstractItemView::ExtendedSelection);
	head = new QHeaderView(Qt::Horizontal);
	head->setSectionResizeMode(QHeaderView::Interactive);
	this->setHorizontalHeader(head);
  
//   	head->resizeSection(0, 160);
//   	head->resizeSection(1, 300);
//   	head->resizeSection(2, 150);
//   	head->resizeSection(3, 70);
// 	
	delegate = new HistoryRecordDelegate();
	this->setItemDelegate(delegate);

	connect(model, &HistoryRecordModel::updateCount, this, &TableView::updateCount);
	
}

TableView::~TableView()
{
	if(delegate) {
		delete delegate;
		delegate = NULL;
	}

	if(model) {
		delete model;
		model = NULL;
	}
	grid_data_list.clear();
}

void TableView::addRow(QStringList rowList)
{
	grid_data_list.append(rowList);
	model->refrushModel();
}
void TableView::addRowInFront(QStringList rowList)
{
	
	grid_data_list.push_front(rowList);
	model->refrushModel();
}
void TableView::remove()
{
	QModelIndexList model_index_list = this->selectedIndexes();
	int model_count = model_index_list.count();
	if(model_count <= 0)
		return;

	QList<int> list_row;
	for(int i=model_count-1; i>=0; i--)
	{
		QModelIndex model_index = model_index_list.at(i);
		int row = model_index.row();
		if(!list_row.contains(row))
			list_row.append(row);
	}

	if(list_row.isEmpty())
		return;

	qSort(list_row);

	for(int i=list_row.count()-1; i>=0; i--)
	{
		grid_data_list.removeAt(list_row.at(i));
	}

	model->refrushModel();
}
void TableView::clear()
{
	grid_data_list.clear();
	model->refrushModel();
}

int TableView::rowCount()
{
	return model->rowCount(QModelIndex());
}
void TableView::initHeader()
{
// 	int nwidth = 749;//this->width();
// 	setColumnWidth(0, (nwidth*0.4));
// 	setColumnWidth(1, nwidth*0.3);
// 	setColumnWidth(2, nwidth*0.2);
// 	setColumnWidth(3, nwidth*0.1);
	//resizeColumnsToContents();
	//QStringList header;
	//header << QStringLiteral("联系人") << QStringLiteral("群名") << QStringLiteral("最后会话时间") << QStringLiteral("信息条数");
	model->setHorizontalHeaderList(mstrheaderList);
}
void TableView::changeValue()
{
	//杩欓噷浠?0琛屽熬鍒楄繘琛屾洿鏂?
	int row_count = this->rowCount();
	if(row_count < 10)
		return;

	for(int i=0; i<10; i++)
	{
		QStringList file_list = grid_data_list.at(i);
		int progress = rand()%100;
		QStringList row_list;
		row_list <<  file_list.at(0) << file_list.at(1) << QString::number(progress) << file_list.at(3) << file_list.at(4) << file_list.at(5);
		grid_data_list.replace(i, row_list);
	}

	model->refrushModel();
}

void TableView::SetHeaderList( const QStringList& list )
{
	mstrheaderList = list;
	initHeader();
}

void TableView::setRowData( const QModelIndex& index,const QStringList& data )
{
	if (NULL!=model)
	{
		QModelIndex idx = model->index(index.row(),index.column());
		QString str = model->data(idx,Qt::DisplayRole).toString();
		bool bret = model->setData(idx,data,Qt::DisplayRole);
		int a =10;
		a =20;
	}
}

QList<QStringList> TableView::GetAllRowData()
{
	return grid_data_list;
}
