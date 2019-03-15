#ifndef QIMDROPLISTVIEW_H
#define QIMDROPLISTVIEW_H

#include <QWidget>
#include <QLabel>
#include "ListWidgetBaseAdapter.h"

class QIMDropListViewUserData;
class QIMProtectedHeaderView;

class QIMDropListView : public QWidget
{
    Q_OBJECT

public:
    QIMDropListView(QWidget *parent);
    ~QIMDropListView();
    QString getCurrentText();
    QSharedPointer<QIMDropListViewUserData> getCurrentUserData();
    // 这个接口太奇怪了，不过没啥办法，为了让下拉页展示出来，只能先这么土鳖着吧。
    void setContentViewParent(QWidget* subParent);
    void setData(const QList<QSharedPointer<QIMDropListViewUserData>>& contentList);
    void setCurrentText(const QString& m_text);
    void setSpacing(int nspace){this->m_nSpacing = nspace;};
    int count();

public:
    virtual QWidget* createHeaderView(QWidget* widget);
    virtual QWidget* createContentView(QWidget* content);

    virtual void showPopup();
    virtual void hidePopup();

protected:
    virtual void mousePressEvent (QMouseEvent* event);
    virtual void mouseReleaseEvent (QMouseEvent * event);

    virtual bool eventFilter (QObject *, QEvent *);
private:
    QWidget* _createDefaultHeaderView(QWidget* widget);
    QWidget* _createDefaultContentView(QWidget* widget);

    void showPopupFromMouseEvent(QMouseEvent* event);
private:
    bool        m_bChecked;
    int         m_nSpacing;
    QWidget*    m_pContentView;
    QLabel*     m_pSelectedText;
    QListWidget*m_pListView;
signals:
    void currentTextChanged(const QString& text);
    void currentUserDataChanged(const QSharedPointer<QIMDropListViewUserData>& userData);

    void popupVisableChanged(bool bVisable);
};

class QIMProtectedHeaderView : public QWidget
{
public:
    QIMDropListView* getDropListView(){return q;};
private:
    QIMDropListView* q;
};

class QIMDropListViewUserData : public QObjectUserData
{
public:
    QString m_text;
    QString m_hoverText;
};


class QIMDropListAdapter : public ListWidgetBaseAdapter
{
public:
    enum DropListData
    {
        DropListDataBase = Qt::UserRole,
        DropListDataItemId = DropListDataBase+1
    };
   
public:
    QIMDropListAdapter(QListView* parent);
    ~QIMDropListAdapter();
    virtual QWidget* CreateNewWidget(const QModelIndex& index);
    virtual QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
    virtual void updateData(QWidget* pWidget,const QModelIndex& index,const QStyleOptionViewItem& option);
public:
    int count() const {return values.size();};
    void setData(const QList<QSharedPointer<QIMDropListViewUserData>>& contentList);
    QSharedPointer<QIMDropListViewUserData> getData(const QString& value);
private:
    QMap<QString,QSharedPointer<QIMDropListViewUserData>> values;

};


#endif // QIMDROPLISTVIEW_H
