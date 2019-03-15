#ifndef HISTORYRECORDMODEL_H
#define HISTORYRECORDMODEL_H

#include <QAbstractItemModel>
#include <QItemDelegate>
#include <QStandardItem>

class HistoryRecordItem:public QStandardItem
{
public:
	HistoryRecordItem();
	~HistoryRecordItem();

	void setRelationName(const QString& gpName);

	enum RecordRoles
	{
		RelatePerson = Qt::UserRole + 1,
		GroupName,
		MsgLstTime,
		MsgCount,
	};




};
class HistoryRecordModel : public QAbstractItemModel/*QStandardItemModel*/
{
	Q_OBJECT

public:
	HistoryRecordModel(QObject *parent = 0);
	~HistoryRecordModel();

	//QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
// 	void CreateItem(const QString& RelationPson, const QString& gpName, const QString& msglstTime, const QString& msgcount);
// 	void updateGroupName(const QString& jid, const QString& gpName);
// 	void removeItem(const QString& jid, const QString& fullName);
// 	void updateGroupAvatar(const QString& jid);
//	void clearData();

	void setHorizontalHeaderList(QStringList horizontalHeaderList);
	void setVerticalHeaderList(QStringList verticalHeaderList);
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	int columnCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role) const;  
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
	Qt::ItemFlags flags(const QModelIndex &index) const;
	void setModalDatas(QList< QStringList > *rowlist);
	void refrushModel();

	public:
 	virtual QModelIndex index( int row, int column, const QModelIndex &parent = QModelIndex( ) ) const;
	virtual bool setData( const QModelIndex &index, const QVariant &value, int role = Qt::EditRole );

 	virtual QModelIndex parent( const QModelIndex &child ) const;
signals:
	void updateCount(int count);




private:
	QStringList horizontal_header_list;
	QStringList vertical_header_list;
	QList< QStringList > *arr_row_list;
};

class HistoryRecordDelegate:public QItemDelegate
{
public:
	HistoryRecordDelegate();
	QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const;
	void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;
 
};

#endif // HISTORYRECORDMODEL_H
