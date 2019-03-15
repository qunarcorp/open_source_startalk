#include "ListWidgetBaseAdapter.h"

#include <QPainter>
#include <QStylePainter>
#include <QListView>
#include <QPushButton>
#include <QListWidget>

ListWidgetBaseAdapter::ListWidgetBaseAdapter(QAbstractItemView* parent) : QItemDelegate(parent)
{
	pWidget = parent;
	mNormalBackground = mHoverBackground = mSelectBackground = QColor::fromRgb(0,0,0,0);
}

ListWidgetBaseAdapter::ListWidgetBaseAdapter(QAbstractItemView* parent,const QColor& clrNormal,const QColor& clrHover,const QColor& clrSelect): QItemDelegate(parent)
{
	pWidget = parent;
	mNormalBackground = clrNormal;
	mHoverBackground = clrHover;
	mSelectBackground = clrSelect;
}

void ListWidgetBaseAdapter::paint( QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index ) const 
{
	painter->save();
	painter->setRenderHint(QPainter::TextAntialiasing);

	QRect rect2 = option.rect;

	if (option.state & QStyle::State_Selected)
	{
        painter->fillRect(option.rect, 
            index.data(ListWidgetBaseAdapterRoleDisableSelecte).toBool()?mNormalBackground:mSelectBackground);
	}
	else if (option.state & QStyle::State_MouseOver)
	{
        painter->fillRect(option.rect, 
            index.data(ListWidgetBaseAdapterRoleDisableSelecte).toBool()?mNormalBackground:mHoverBackground);
	}
	else
	{
		painter->fillRect(option.rect, mNormalBackground);
	}
	ListWidgetBaseAdapter* pThis = const_cast<ListWidgetBaseAdapter*>(this);
	if (NULL!=pThis)
	{
		pThis->dealWidget(painter,option,index);
	}
}




void ListWidgetBaseAdapter::dealWidget(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index)
{
	QWidget* pw2 = ((QListView*)pWidget)->indexWidget(index);
	if (NULL ==  pw2)
	{
		QWidget* pbtn= CreateNewWidget(index);
		if (NULL!=pbtn)
		{
			QRect rect2 = option.rect;
			pbtn->setFixedSize(rect2.width(),rect2.height());
			pbtn->move(rect2.topLeft());
			((QListView*)pWidget)->setIndexWidget(index, pbtn);
		}
	}
	else
	{
		QRect rect2 = option.rect;
		pw2->setFixedSize(rect2.width(),rect2.height());
		pw2->move(rect2.topLeft());
        updateData(pw2,index,option);
	}
}

void ListWidgetBaseAdapter::updateData(QWidget* pWidget,const QModelIndex& index,const QStyleOptionViewItem& option)
{

}

int ListWidgetBaseAdapter::count()
{
    return 0;
}
