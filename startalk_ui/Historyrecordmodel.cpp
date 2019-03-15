#include "Historyrecordmodel.h"
#include <QPainter>
HistoryRecordItem::HistoryRecordItem()
{
	//setFilterRole(Qt::DisplayRole);
}
HistoryRecordItem::~HistoryRecordItem()
{

}
void HistoryRecordItem::setRelationName(const QString& gpName)
{

}

HistoryRecordModel::HistoryRecordModel(QObject *parent)
	: QAbstractItemModel(parent),arr_row_list(NULL)
{

}

HistoryRecordModel::~HistoryRecordModel()
{
	arr_row_list = NULL;
}

// void HistoryRecordModel::CreateItem(const QString& RelationPson, const QString& gpName, const QString& msglstTime, const QString& msgcount)
// {
// 	HistoryRecordItem* item = NULL;
// 	if(RelationPson != NULL)
// 	{
// 		//bool autoJoin = Biz::Session::currentAccount().FindGroupJoin(jid);
// 		item = new HistoryRecordItem;
// 		item->setColumnCount(4);
// 		item->setData(RelationPson, HistoryRecordItem::RelatePerson);
// 		item->setData(gpName, HistoryRecordItem::GroupName);
// 		item->setData(msglstTime, HistoryRecordItem::MsgLstTime);
// 		item->setData(msgcount, HistoryRecordItem::MsgCount);
// 		
// 
// 		appendRow(item);
// 	}
// }
// void HistoryRecordModel::updateGroupName(const QString& jid, const QString& gpName)
// {
// 
// }
// void HistoryRecordModel::removeItem(const QString& jid, const QString& fullName)
// {
// 	QModelIndexList indexes = match(index(0, 0, QModelIndex()), HistoryRecordItem::RelatePerson, jid, -1, Qt::MatchFlag::MatchExactly);
// 	for (int i = 0; i < indexes.size(); ++i)
// 	{
// 		HistoryRecordItem* p =  (HistoryRecordItem*)itemFromIndex(indexes.at(i));        
// 		if(p)
// 			removeRow(p->row());
// 	}
// }
// void HistoryRecordModel::updateGroupAvatar(const QString& jid)
// {
// 
// }
// void HistoryRecordModel::clearData()
// {
// 	this->clear();
// }

void HistoryRecordModel::setHorizontalHeaderList(QStringList horizontalHeaderList)
{
	horizontal_header_list = horizontalHeaderList;
}
void HistoryRecordModel::setVerticalHeaderList(QStringList verticalHeaderList)
{
	vertical_header_list = verticalHeaderList;
}
int HistoryRecordModel::rowCount(const QModelIndex &parent ) const
{
	if(vertical_header_list.size() > 0)
		return vertical_header_list.size();

	if(NULL == arr_row_list)
		return 0;
	else
		return arr_row_list->size();
}
int HistoryRecordModel::columnCount(const QModelIndex &parent ) const
{
	if(horizontal_header_list.size() > 0)
		return horizontal_header_list.size();

	if(NULL == arr_row_list)
		return 0;
	else if(arr_row_list->size() < 1)
		return 0;
	else
		return arr_row_list->at(0).size();
}
QVariant HistoryRecordModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
		return QVariant();

	if(NULL == arr_row_list)
		return QVariant();

	if(arr_row_list->size() < 1)
		return QVariant();

	if (role == Qt::TextAlignmentRole) 
	{
		return int(Qt::AlignLeft | Qt::AlignVCenter);
	} 
	else if (role == Qt::DisplayRole) 
	{
		if(index.row() >= arr_row_list->size())
			return QVariant();
		if(index.column() >= arr_row_list->at(0).size())
			return QVariant();
		return arr_row_list->at(index.row()).at(index.column());
	}
	return QVariant();
}

bool HistoryRecordModel::setData( const QModelIndex &index, const QVariant &value, int role /*= Qt::EditRole */ )
{
	if (role == Qt::DisplayRole) 
	{
		if(index.row() >= arr_row_list->size())
			return false;

		QList<QVariant> list = value.toList();
		if (!list.isEmpty())
		{
			if (list.size() > arr_row_list->at(0).size())
			{
				return false;
			}
			for (int nI = 0; nI < list.size(); nI++)
			{
				(*arr_row_list)[index.row()][nI] = list.at(nI).toString();
			}
		}

		if (!value.toString().isEmpty())
		{
			if(index.column() >= arr_row_list->at(0).size())
				return false;
			(*arr_row_list)[index.row()][index.column()] = value.toString();
		}
		return true;
	}
	return QAbstractItemModel::setData(index,value,role);
}

QVariant HistoryRecordModel::headerData(int section, Qt::Orientation orientation, int role ) const
{
	if(role==Qt::DisplayRole)  
	{  
		if(orientation==Qt::Horizontal) // 水平表头  
		{  
			if(horizontal_header_list.size() > section)
				return horizontal_header_list[section];
			else
				return QVariant(); 
		}  
		else
		{
			if(vertical_header_list.size() > section)
				return vertical_header_list[section]; // 垂直表头  
			else
				return QVariant();
		}
	}  

	return QVariant(); 
}
Qt::ItemFlags HistoryRecordModel::flags(const QModelIndex &index) const
{
	if (!index.isValid())
		return Qt::NoItemFlags;

	Qt::ItemFlags flag = QAbstractItemModel::flags(index);  

	// flag|=Qt::ItemIsEditable // 设置单元格可编辑,此处注释,单元格无法被编辑  
	return flag;  
}
void HistoryRecordModel::setModalDatas(QList< QStringList > *rowlist)
{
	arr_row_list = rowlist;
}
void HistoryRecordModel::refrushModel()
{
	beginResetModel();
	endResetModel();
	//emit updateCount(this->rowCount(QModelIndex()));
}

 QModelIndex HistoryRecordModel::index( int row, int column, const QModelIndex &parent /*= QModelIndex( ) */ ) const
 {
 	
	 int a = 0;
	if ( ! parent.isValid() )
		return QAbstractItemModel::createIndex(row, column, a);
		int parent_idx = parent.internalId();
		int idx = parent_idx * 2 + ( row + 1 );
	return QAbstractItemModel::createIndex(row, column, idx );
 }
 
 QModelIndex HistoryRecordModel::parent( const QModelIndex &child ) const
 {
 	
	if (child.internalId() == 0)
		return QModelIndex();
		int parent_idx = (child.internalId() - 1 )/2;
	return createIndex( (parent_idx+1) % 2, 0, parent_idx );
 }



HistoryRecordDelegate::HistoryRecordDelegate()
{

}
QSize HistoryRecordDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	Q_UNUSED(option);
	Q_UNUSED(index);
	return QSize(148, 28);
}
void HistoryRecordDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	//return QItemDelegate::paint (painter, option, index);
// 	painter->save();
// 	painter->setRenderHint(QPainter::TextAntialiasing);
// 
// 	QColor selectedBg(223, 223, 223);
// 	QColor alternateBg(239, 245, 254);
// 	QColor selectedText(51, 51, 51);
// 	QColor nameTextColor(51, 51, 51);
// 	QColor statusTextColor(102, 102, 102);
// 	QColor timeColor(102, 102, 102);
// 	QColor unreadColor(Qt::GlobalColor::white);
// 	QColor frameColor(150,150,150);
// 
// //	QRect rect = option.rect;
// 	QPen penDivision;
// 
// 
// 
// 	//名字
// 	QFont font;
// 	font.setPixelSize(12);
// 
 	if (index.column() == 0 || index.column() == 1 || index.column() == 2 || index.column() == 3 )
 	{
 		QString context = index.model()->data(index, Qt::DisplayRole).toString();
 		QStyleOptionViewItem myOption = option; 
 		myOption.displayAlignment = Qt::AlignLeft | Qt::AlignVCenter; // 处理文本的对齐方式 (不重要)  
 
 		drawDisplay(painter, myOption, myOption.rect, context); // 写回处理后的值  
 		drawFocus(painter, myOption, myOption.rect); // 如果当前项具有焦点，它就绘制一个焦点矩形(不重要)  
 	}
//  	else if (index.column() == 1)
//  	{
//  		QString context = index.model()->data(index, Qt::DisplayRole).toString();
//  		QStyleOptionViewItem myOption = option; 
//  		myOption.displayAlignment = Qt::AlignRight | Qt::AlignVCenter; // 处理文本的对齐方式 (不重要)  
//  
//  		drawDisplay(painter, myOption, myOption.rect, context); // 写回处理后的值  
//  		drawFocus(painter, myOption, myOption.rect); // 如果当前项具有焦点，它就绘制一个焦点矩形(不重要)  
//  	}
//  	else if (index.column() == 2)
//  	{
//  		QString context = index.model()->data(index, Qt::DisplayRole).toString();
//  		QStyleOptionViewItem myOption = option; 
//  		myOption.displayAlignment = Qt::AlignRight | Qt::AlignVCenter; // 处理文本的对齐方式 (不重要)  
//  
//  		drawDisplay(painter, myOption, myOption.rect, context); // 写回处理后的值  
//  		drawFocus(painter, myOption, myOption.rect); // 如果当前项具有焦点，它就绘制一个焦点矩形(不重要)  
//  	}if (index.column() == 3)
//  	{
//  		QString context = index.model()->data(index, Qt::DisplayRole).toString();
//  		QStyleOptionViewItem myOption = option; 
//  		myOption.displayAlignment = Qt::AlignRight | Qt::AlignVCenter; // 处理文本的对齐方式 (不重要)  
//  
//  		drawDisplay(painter, myOption, myOption.rect, context); // 写回处理后的值  
//  		drawFocus(painter, myOption, myOption.rect); // 如果当前项具有焦点，它就绘制一个焦点矩形(不重要)  
//  	}
 	else
 	{
 		QItemDelegate::paint(painter, option, index); 
 	}





	/*rect = option.rect;
	rect.moveTop(rect.y() + 5);
	rect.setLeft(option.rect.x() + 12+ AVATER_WIDTH + 10  + 16);
	painter->setFont(font);
	painter->setPen(nameTextColor);

	QString nameText = index.model()->data(index, Qt::DisplayRole).toString();
	QFontMetrics fontMetrics(font);
	nameText = fontMetrics.elidedText(nameText, Qt::ElideRight, rect.width() - 8);*/
	//painter->drawText(rect, nameText);

}