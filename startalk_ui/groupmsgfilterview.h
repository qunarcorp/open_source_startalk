#ifndef GROUPMSGFILTERVIEW_H
#define GROUPMSGFILTERVIEW_H

#include "LocalManDialog.h"
#include "ListWidgetBaseAdapter.h"
#include <QTreeWidget>
#include <QCheckBox>
#include <QLabel>
#include "UtilHelper.h"

namespace Ui{class GroupMsgFilterView;}
namespace Biz{class CallbackReceiver;}

class GroupMsgFilterRangeItemView : public QWidget{
	Q_OBJECT
public:
	GroupMsgFilterRangeItemView();
	~GroupMsgFilterRangeItemView();
	QCheckBox*      m_pCheckBox;
	QLabel*         m_pContent;
	QLabel*         m_pExpendIcon;
	QLabel*         m_pCount;
};

class MsgFilterItem : public QWidget{
	Q_OBJECT
public:
	MsgFilterItem(QWidget*parent);
	~MsgFilterItem();
	QCheckBox*      m_pCheckBox;
	QLabel*         m_pContent;

};


class GroupMsgFilterItemView : public QWidget{
	Q_OBJECT
public:
	GroupMsgFilterItemView();
	~GroupMsgFilterItemView();
// 	QCheckBox*      m_pCheckBoxOne;
// 	QLabel*         m_pContentOne;
// 
// 	QCheckBox*      m_pCheckBoxTwo;
// 	QLabel*         m_pContentTwo;

	MsgFilterItem *m_MsgFilterItem[2];

};


class GroupMsgFilterAdapter : public ListWidgetBaseAdapter
{
	Q_OBJECT
public:
	enum GroupRangeType
	{
		GroupItemMsgType,
		GroupItemAtType
	};
	enum GroupMsgFilterItemType
	{
		GroupMsgFilterItemType_Item,
		GroupMsgFilterItemType_Range
	};
	enum GroupMsgFilterItemData
	{
		GroupMsgFilterItemDataBase = ListWidgetBaseAdapterUserRoleBase,
		GroupMsgFilterItemDataDisplay,
		GroupMsgFilterItemDataId,
		GroupMsgFilterItemDataSelectStatus,
		GroupMsgFilterItemDataCount,
		GroupMsgFilterItemDataType,
		GroupMsgFilterItemDataParentid,
		GroupMsgFilterItemDataSecondDisplay,
		GroupMsgFilterItemDataSecondId,
		GroupMsgFilterItemDataSecondSelectStatus
		

	};
public:
	GroupMsgFilterAdapter(QAbstractItemView* parent);
	~GroupMsgFilterAdapter();
	virtual QWidget* CreateNewWidget(const QModelIndex& index);
	virtual QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
	virtual void updateData(QWidget* pWidget,const QModelIndex& index,const QStyleOptionViewItem& option);
	
	 void clearData();
	 void setGroupMsgData(const QMap<QString, int>& groupmemberMsgcountmap, const QStringList&atlist );
	 QStringList getCheckedGroupId();
	 int getselectRangeType(){return mselectRangetype;};
	 void setSelectIds(const QStringList& ids);
protected:
	void setTreeMember(const QString&display, const QStringList& ids );
	QTreeWidgetItem* findParentItem(const QString&id);
	 void recheckRangeItem(QTreeWidgetItem* prange);
private:
	QMap<QString, int> mGroupMemberMsgMap;
	QMap<QString,QTreeWidgetItem*> mtreeWidgetItemMaps;
	QMap<QString,QTreeWidgetItem*> mtreeWidgetRangeMaps;
	quint64 lastclicktimestamp;
	int mselectRangetype;
	QStringList mSelectId;
public slots:
	// 去修改子item的check状态
	void onGroupItemCheckClick(const QString& itemid,bool bcheck);
	// 去修改组展示的check状态
	void onItemCheckClickFirst(const QString& itemid,bool bcheck);
	void onItemCheckClickSecond(const QString& itemid,bool bcheck);
	// 变箭头
	void onGroupItemExpendChange(QTreeWidgetItem* item);
	// 
	void onGroupItemClicked(QTreeWidgetItem *item, int column);
};


class GroupMsgFilterView : public LocalManDialog
{
	Q_OBJECT
		friend class Util::SingletonTemplete<GroupMsgFilterView>;
public:
	GroupMsgFilterView(QWidget *parent=0);
	~GroupMsgFilterView();
	void setGroupId(const QString&groupId);
	void showInfo();
protected:
	virtual void showEvent( QShowEvent * );
private:
	Ui::GroupMsgFilterView * ui;

	GroupMsgFilterAdapter* m_pAdapter;
	Biz::CallbackReceiver* mCallbackReceiver;
	QString mGroupId;
	QMap<QString, QStringList> mSelectInformap;

	public slots:
		void onGroupMsgFilterClick();

};

typedef Util::SingletonTemplete<GroupMsgFilterView> GroupMsgFilterViewSingleton;

#endif // GROUPMSGFILTERVIEW_H
