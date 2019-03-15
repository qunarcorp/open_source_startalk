#ifndef LISTWIDGETBASEADAPTER_H
#define LISTWIDGETBASEADAPTER_H

#include <QObject>
#include <QListView>
#include <QListWidget>
#include <QItemDelegate>
enum ListWidgetBaseAdapterRole
{
    ListWidgetBaseAdapterRoleBase = Qt::UserRole,
    ListWidgetBaseAdapterRoleDisableSelecte,
    ListWidgetBaseAdapterUserRoleBase = ListWidgetBaseAdapterRoleBase + 1000,
};
class ListWidgetBaseAdapter : public QItemDelegate
{
public:
	ListWidgetBaseAdapter(QAbstractItemView* parent);
	ListWidgetBaseAdapter(QAbstractItemView* parent,const QColor& clrNormal,const QColor& clrHover,const QColor& clrSelect);
	virtual QWidget* CreateNewWidget(const QModelIndex& index) = 0;
    virtual void updateData(QWidget* pWidget,const QModelIndex& index,const QStyleOptionViewItem& option);
    virtual int count();
    
    inline void setNormalBackground(const QColor& color){this->mNormalBackground = color;};
    inline void setHoverBackground(const QColor& color){this->mHoverBackground = color;};
    inline void setSelectBackground(const QColor& color){this->mSelectBackground = color;};


protected:
	void dealWidget(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index);
	virtual void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;
protected:
    inline QAbstractItemView* getListView(){return pWidget;};
private:
	QAbstractItemView * pWidget;
	QColor mNormalBackground;
	QColor mHoverBackground;
	QColor mSelectBackground;
};

#endif // LISTWIDGETBASEADAPTER_H
