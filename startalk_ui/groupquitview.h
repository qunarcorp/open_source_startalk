#ifndef GROUPQUITVIEW_H
#define GROUPQUITVIEW_H

#include <QWidget>
#include <QCheckBox>
#include <QLabel>
#include <QTreeWidgetItem>
#include "UtilHelper.h"
#include "LocalManDialog.h"
#include "ListWidgetBaseAdapter.h"

namespace Ui {class GroupQuitView;};

namespace Biz {class CallbackReceiver;};


class GroupQuitItemGroupView : public QWidget{
    Q_OBJECT
public:
    GroupQuitItemGroupView();
    ~GroupQuitItemGroupView();
    QCheckBox*      m_pCheckBox;
    QLabel*         m_pContent;
    QLabel*         m_pExpendIcon;
    QLabel*         m_pCount;
};



class GroupQuitItemView : public QWidget{
    Q_OBJECT
public:
    GroupQuitItemView();
    ~GroupQuitItemView();
    QCheckBox*      m_pCheckBox;
    QLabel*         m_pContent;
    QLabel*         m_pLaseMessageTime;
};

// adapter 同时具备了itemview 的可见性，listview的可见性。和上层控件的无关性。
class  GroupQuitAdapter : public ListWidgetBaseAdapter
{
    Q_OBJECT
public:
        enum GropQuitItemType
    {
        GropQuitItemType_Item,
        GropQuitItemType_Range
    };

        enum GroupQuitItemData
    {
        GroupQuitItemDataBase = ListWidgetBaseAdapterUserRoleBase,
        GroupQuitItemDataRangeMin,
        GroupQuitItemDataRangeMax,
        GroupQuitItemDataTimestamp,
        GroupQuitItemDataContent,
        GroupQuitItemDataId,
        GroupQuitItemDataSelectStatus,
        GroupQuitItemDataChildCount,
        GroupQuitItemDataType
    };
public:
    GroupQuitAdapter(QAbstractItemView* parent);
    ~GroupQuitAdapter();
    virtual QWidget* CreateNewWidget(const QModelIndex& index);
    virtual QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
      virtual void updateData(QWidget* pWidget,const QModelIndex& index,const QStyleOptionViewItem& option);

    void setGroupData(const QMap<QString,quint64>& groups);

    void deleteItem(const QString& id);

    void clearData();

    QStringList getCheckedGroupId();
private:
    QTreeWidgetItem* findGroup(quint64 lasttime);
    void recheckRangeItem(QTreeWidgetItem* prange);
private:
    QMap<QString,QTreeWidgetItem*> treeWidgetItemMaps;
    QMap<QString,QTreeWidgetItem*> treeWidgetRangeMaps;

    quint64 lastclicktimestamp;
signals:
    void sgGroupSelectCountChange(int count);
    public slots:
        // 去修改子item的check状态
        void onGroupItemCheckClick(const QString& itemid,bool bcheck);
        // 去修改组展示的check状态
        void onItemCheckClick(const QString& itemid,bool bcheck);
        // 变箭头
        void onGroupItemExpendChange(QTreeWidgetItem* item);
        // 
        void onGroupItemClicked(QTreeWidgetItem *item, int column);
        //
         void onGroupDestroyed(const QString& groupBareJid);

       

};

class GroupQuitView : public LocalManDialog
{
    Q_OBJECT
        friend class Util::SingletonTemplete<GroupQuitView>;
public:
    void setTips(const QString& tips);
protected:
    void showEvent (QShowEvent * e);
private:
    GroupQuitView(QWidget *parent = 0);
    ~GroupQuitView();
    
private:
    Ui::GroupQuitView *ui;
    GroupQuitAdapter* m_pAdapter;
    Biz::CallbackReceiver* mCallbackReceiver;

public:
    void onQuitGroupClick (bool b);
};

typedef Util::SingletonTemplete<GroupQuitView> GroupQuitViewSingleton;

#endif // GROUPQUITVIEW_H
