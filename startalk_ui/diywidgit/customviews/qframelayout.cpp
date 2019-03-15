#include "qframelayout.h"
#include "QDebug"
#include <QLayout>
#include <QWidget>

#include <QMargins>

class QFrameLayoutPrivate 
{
public:
    QFrameLayoutPrivate() {}

    QList<QWidget*> widgetList;
    QMap<QWidget*,int> mapWidgetAlinment;
    QMap<QWidget*,QMargins> mapWidgetMargins;
    QMargins paddings;
};


QFrameLayout::QFrameLayout(QWidget *parent)
    : QLayout(parent)
    , d(new QFrameLayoutPrivate)
{
}

QFrameLayout::~QFrameLayout()
{

}


void QFrameLayout::appendWidget(QWidget* widget,int aline /*= ALINE_TOPLEFT*/,QMargins margins /*= QMargins()*/)
{
    if (widget==NULL || d->widgetList.contains(widget))
    {
        return ;
    }

	widget->setParent(this->parentWidget());
    d->widgetList.push_back(widget);
    d->mapWidgetAlinment.insert(widget,aline);
    d->mapWidgetMargins.insert(widget,margins);

    widget->raise();
}


QWidget* QFrameLayout::takeWidget(QWidget* widget)
{
    if (d->widgetList.contains(widget))
    {
        d->widgetList.removeOne(widget);
    }
    return widget;
}

QWidget* QFrameLayout::takeIndex(int index)
{
    if (d->widgetList.size()<index)
    {
        QWidget* item = d->widgetList.at(index);
        d->widgetList.removeAt(index);
        return item;
    }
    else
    {
        return NULL;
    }
}



QSize QFrameLayout::sizeHint() const
{
    QSize size(0,0);
    int heightOffset = d->paddings.left() + d->paddings.right();
    int widthOffset = d->paddings.top() + d->paddings.bottom();
    for (QWidget* widget: d->widgetList)
    {
        // 计算所有视图中的最大的宽高hint
        size.setHeight(qMax(size.height(),heightOffset + widget->sizeHint().height()));
        size.setWidth(qMax(size.width(),widthOffset + widget->sizeHint().width()));
    }
    
    return size;
}

QSize QFrameLayout::minimumSize() const
{
    QSize size(0,0);
    int heightOffset = d->paddings.left() + d->paddings.right();
    int widthOffset = d->paddings.top() + d->paddings.bottom();
    for (QWidget* widget: d->widgetList)
    {
        // 计算所有视图中的最大的宽高hint
        size.setHeight(qMax(size.height(),heightOffset + widget->minimumHeight()));
        size.setWidth(qMax(size.width(),widthOffset + widget->minimumWidth()));
    }

    return size;
}

QSize QFrameLayout::maximumSize() const
{
    QSize size(0,0);

    int heightOffset = d->paddings.left() + d->paddings.right();
    int widthOffset = d->paddings.top() + d->paddings.bottom();

    for (QWidget* widget: d->widgetList)
    {
        // 计算所有视图中的最大的宽高hint
        size.setHeight(qMax(size.height(),heightOffset + widget->maximumHeight()));
        size.setWidth(qMax(size.width(),widthOffset + widget->maximumWidth()));
    }

    return size;
}

void QFrameLayout::setGeometry(const QRect& rect)
{

    for (QWidget* widget: d->widgetList)
    {
        QMargins margins = d->mapWidgetMargins.value(widget);
        int ap = d->mapWidgetAlinment.value(widget);

        QRect fixedRect =  widget->geometry();
        QPoint topLeft = fixedRect.topLeft();
        QPoint bottomRight = fixedRect.bottomRight();

        if (ALINE_LEFT == (ALINE_LEFT&ap))
        {
            topLeft.setX(rect.left() + d->paddings.left()+margins.left());
        }
        if (ALINE_TOP == (ALINE_TOP&ap))
        {
            topLeft.setY(rect.top() + d->paddings.top()+margins.top());
        }
        if (ALINE_RIGHT == (ALINE_RIGHT&ap))
        {
            bottomRight.setX(rect.right()- d->paddings.right()-margins.right());
        }
        if (ALINE_BOTTOM == (ALINE_BOTTOM&ap))
        {
            bottomRight.setY(rect.bottom() -d->paddings.bottom()-margins.bottom());
        }

        if (ALINE_LEFT == (ALINE_LEFT&ap) && ALINE_RIGHT != (ALINE_RIGHT&ap))
        {
            bottomRight.setX(topLeft.x()+fixedRect.width()-1);
        }

        if (ALINE_LEFT != (ALINE_LEFT&ap) && ALINE_RIGHT == (ALINE_RIGHT&ap))
        {
            topLeft.setX(bottomRight.x()-fixedRect.width()+1);
        }

        if (ALINE_TOP == (ALINE_TOP&ap) && ALINE_BOTTOM != (ALINE_BOTTOM&ap))
        {
            bottomRight.setY(topLeft.y()+fixedRect.height()-1);
        }
        if (ALINE_TOP != (ALINE_TOP&ap) && ALINE_BOTTOM == (ALINE_BOTTOM&ap))
        {
            topLeft.setY(bottomRight.y()-fixedRect.height()+1);
        }
        if (ALINE_VCENTER == (ALINE_VCENTER&ap))
        {
            topLeft.setY((rect.height() 
                - d->paddings.top()
                - d->paddings.bottom()
                - widget->height())/2);
            topLeft.setY (topLeft.y ()+margins.top ()-margins.bottom ());
            bottomRight.setY(topLeft.y()+widget->height()-1);
        }
        if (ALINE_HCENTER == (ALINE_HCENTER&ap))
        {
            topLeft.setX((rect.width() 
                - d->paddings.left()
                - d->paddings.right()
                - widget->width())/2);
            topLeft.setX (topLeft.x ()+margins.left ()-margins.right ());
            bottomRight.setX(topLeft.x()+widget->width()-1);
        }

        

        fixedRect = QRect(topLeft,bottomRight);
        widget->setGeometry(fixedRect);
    }

}

bool QFrameLayout::isEmpty() const
{
     return d->widgetList.isEmpty();
}




void QFrameLayout::setContentsMargins(int left, int top, int right, int bottom)
{
    if (d->paddings.left() == left
        && d->paddings.top() == top
        && d->paddings.right() == right
        && d->paddings.bottom() == bottom)
    {
        return;
    }

    d->paddings = QMargins(left,top,right,bottom);

    invalidate();
}

void QFrameLayout::addItem(QLayoutItem *)
{
}

QLayoutItem * QFrameLayout::itemAt(int index) const
{
    return NULL;
}

QLayoutItem * QFrameLayout::takeAt(int index)
{
    return NULL;
}

int QFrameLayout::count() const
{
    return 0;
}

