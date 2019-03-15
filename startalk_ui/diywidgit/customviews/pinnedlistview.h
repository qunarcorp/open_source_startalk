#pragma  once

#include <QWidget>
#include <QSortFilterProxyModel>
#include <QItemDelegate>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QTreeView>
#include <QPropertyAnimation>
#include <QScrollBar>
#include <QPushButton>
#include <QContextMenuEvent>


class PinnedListViewDelegate : public QItemDelegate
{

public:
    PinnedListViewDelegate(QObject* parent);
    ~PinnedListViewDelegate();
public:
    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    virtual QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
};
class PinnedListItem : public QStandardItem {
public:
    explicit PinnedListItem(const QStandardItem* otheritem);
    explicit PinnedListItem();
    ~PinnedListItem();

};


class PinnedListItemModel : public QStandardItemModel {
public:
    PinnedListItemModel(QObject* parent);
    ~PinnedListItemModel();
};


class PinnedListItemSortFilterProxyModel : public QSortFilterProxyModel
{
public:
    PinnedListItemSortFilterProxyModel(QObject* parent);
    ~PinnedListItemSortFilterProxyModel();

    virtual bool lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const;
};

class SmoothVScrollBar : public  QScrollBar
{
    Q_OBJECT
public:
    explicit SmoothVScrollBar(QWidget *parent=0);
    explicit SmoothVScrollBar(Qt::Orientation, QWidget *parent=0);
    ~SmoothVScrollBar();
public:
protected:
    virtual void wheelEvent (QWheelEvent *);
private:
    int m_nOneStepDuration;
    int m_nLastPosition;
    bool m_bForward;
    QPropertyAnimation* m_pScrollAnimation;

    bool bSmooth;
    protected slots:
        void onScrollBarValueChanged(int value); 
        void onScrollBarActionTriggered(int value);
};

class PinnedListView : public QWidget
{
    Q_OBJECT
public:
    enum UserColumnName {
        UCN_Type    = Qt::UserRole,
        UCN_ID      ,
        UCN_Name    ,
        UCN_SortKey ,
        UCN_HeaderImage,
		UCN_NoticeTip
    };
    
public:
    PinnedListView(QWidget *parent = 0);
    ~PinnedListView();
public:
    void insertItem(const QString& jid);
    void insertItem(const QString& jid,const QString& jidName);
    void setItemName(const QString& jid,const QString& jidName);
    void setItemImage(const QString& jid,const QImage& image);
    void activeItem(const QString& jid);
    void deleteItem(const QString& jid);
    
    void clearAll();

    const QString currentSelectJid();

protected:
    virtual void contextMenuEvent(QContextMenuEvent *e);
    virtual void contextMenuEvent(const QString& jid);
	void setGroupNoticeTipChangeinned( const QString&jid, int addoption, int removeoption);
	void setGroupNoticeTipinned(const QString&jid, int noticeflag);
private:
    QTreeView*  m_pTreeView;
    PinnedListItemModel* m_pDataModel;
    PinnedListItemSortFilterProxyModel* m_pSortModel;
    QPushButton*     m_pHeaderText;

    quint64 lastDbClickTick;
signals:
    void sgContextMenuEvent (const QString& jid);
    void sgItemDoubleClicked(const QString& jid);
    void sgItemClicked(const QString& jid);
    void sgListEmpty();
    protected slots:
        void onItemDoubleClicked(const QModelIndex& index);
        void onItemClicked(const QModelIndex& index);
};

