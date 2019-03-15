#include "groupmsgfilterview.h"
#include "ui_GroupMsgFilterView.h"
#include "TitlebarWidget.h"
#include "CallbackReceiver.h"
#include "animationreactor.h"
#include "Session.h"
#include "GroupManager.h"
#include "UserVcardManager.h"
#include "diywidgit/customviews/qframelayout.h"
#include "UIFrame.h"
#include "ConversationController.h"


class GroupMsgFilterItem : public QTreeWidgetItem
{
public:

	virtual bool operator <(const QTreeWidgetItem &other) const
	{
		bool desc = false;

		int thisType = data(0,GroupMsgFilterAdapter::GroupMsgFilterItemData::GroupMsgFilterItemDataType).toInt ();
		int otherType  = other.data (0,GroupMsgFilterAdapter::GroupMsgFilterItemData::GroupMsgFilterItemDataType).toInt ();

		if (GroupMsgFilterAdapter::GroupMsgFilterItemType::GroupMsgFilterItemType_Range != thisType 
			&& GroupMsgFilterAdapter::GroupMsgFilterItemType::GroupMsgFilterItemType_Range == thisType)
			return desc;
		else if (GroupMsgFilterAdapter::GroupMsgFilterItemType::GroupMsgFilterItemType_Range == thisType 
			&& GroupMsgFilterAdapter::GroupMsgFilterItemType::GroupMsgFilterItemType_Range != thisType)
			return !desc;
		else
		{
// 			if (GroupMsgFilterAdapter::GroupMsgFilterItemType::GroupMsgFilterItemType_Range == thisType)
// 			{
// 				quint64 thisRangeMin = data(0,GroupMsgFilterAdapter::GroupMsgFilterItemData::GroupMsgFilterItemDataRangeMin).toULongLong ();
// 				quint64 otherRangeMin = other.data(0,GroupMsgFilterAdapter::GroupMsgFilterItemData::GroupMsgFilterItemDataRangeMin).toULongLong ();
// 				return thisRangeMin < otherRangeMin ? !desc : desc;
// 			}
// 			else
			{
				// 同一个组里面，会话多的在上面
				int nItemcount = data (0, GroupMsgFilterAdapter::GroupMsgFilterItemData::GroupMsgFilterItemDataCount).toULongLong ();
				int  notherItemcount = other.data (0, GroupMsgFilterAdapter::GroupMsgFilterItemData::GroupMsgFilterItemDataCount).toULongLong ();

				return nItemcount > notherItemcount? !desc : desc;
			}
		}
		return desc;
	}
};


GroupMsgFilterView::GroupMsgFilterView(QWidget *parent)
	: LocalManDialog(parent)
	,ui(new Ui::GroupMsgFilterView())
	,mCallbackReceiver(new Biz::CallbackReceiver(this))
	,m_pAdapter(NULL)
{
	ui->setupUi(this);

	using namespace Qt;
	auto remove = WindowTitleHint;
	auto add = FramelessWindowHint | WindowMinMaxButtonsHint;
	setAttribute(Qt::WA_AlwaysShowToolTips, true);
	setAttribute(Qt::WA_TranslucentBackground, true); 
	overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));
#ifdef QCHAT
	setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
#else
	setWindowIcon(QIcon(":/Images/Deal.ico"));
#endif
	setWindowTitle(QStringLiteral("消息过滤"));

	auto titlebar = ui->titlebar;
	titlebar->setMaxable(false);
	connect(titlebar, &TitlebarWidget::sgCloseOnClicked, this, &GroupMsgFilterView::onMin);
	connect(titlebar, &TitlebarWidget::sgMinOnClicked, this, &GroupMsgFilterView::onMin);

	m_pAdapter = new GroupMsgFilterAdapter(ui->treeWidget);
	ui->treeWidget->setItemDelegate(m_pAdapter);

	ui->treeWidget->setExpandsOnDoubleClick(false);
	ui->treeWidget->setIndentation(0);

	connect (ui->treeWidget,&QTreeWidget::itemExpanded,m_pAdapter,&GroupMsgFilterAdapter::onGroupItemExpendChange);
	connect (ui->treeWidget,&QTreeWidget::itemCollapsed,m_pAdapter,&GroupMsgFilterAdapter::onGroupItemExpendChange);

	connect (ui->treeWidget,&QTreeWidget::itemClicked,m_pAdapter,&GroupMsgFilterAdapter::onGroupItemClicked);

// 	connect (m_pAdapter,&GroupMsgFilterAdapter::sgGroupSelectCountChange,[this](int count){
// 
// 		ui->warning->setText(0 == count ? 0: QStringLiteral("*选中%1个，退出群组后将无法查看聊天记录，如果有重要信息请预先保存").arg (count));
// 		ui->quit->setEnabled(0 != count);
// 	});


	connect (ui->ok,&QPushButton::clicked,this,&GroupMsgFilterView::onGroupMsgFilterClick);

	ui->stackedWidget->setCurrentWidget(ui->Emptypage);

}


GroupMsgFilterView::~GroupMsgFilterView()
{

}

void GroupMsgFilterView::setGroupId( const QString&groupId )
{
	if (groupId != mGroupId)
	{
		mSelectInformap.remove(mGroupId);
	}
	mGroupId = groupId;
}

void GroupMsgFilterView::onGroupMsgFilterClick()
{
	QStringList groupids = m_pAdapter->getCheckedGroupId ();
	//记下来所选择的人
	mSelectInformap.insert(mGroupId, groupids);

	if (m_pAdapter->getselectRangeType() == GroupMsgFilterAdapter::GroupItemAtType)
	{
		emit MainApp::UIFrame::getConversationController()->sgGroupChatMsgAtFilter(mGroupId, groupids);
	}
	else
	{
		emit MainApp::UIFrame::getConversationController()->sgGroupChatMsgFilter(mGroupId, groupids);
		
	}
	this->close();

	
}
void GroupMsgFilterView::showInfo()
{
	if (NULL != m_pAdapter)
		m_pAdapter->clearData ();

	ui->stackedWidget->setCurrentWidget(ui->Emptypage);

	AnimationReactorSingleton::getInstance ()->opacityInWidget (this,100);

	//获取这个群里面的所有成员

	auto uicbSuccess = [this](const QMap<QString,int>& groupMemberMsgcountmap){
		if (NULL!=m_pAdapter)
		{
			QStringList atlist = MainApp::UIFrame::getConversationController()->getAtInforMemberList(mGroupId);
			m_pAdapter->setGroupMsgData (groupMemberMsgcountmap, atlist);
			if (mSelectInformap.contains(mGroupId))
			{
				m_pAdapter->setSelectIds(mSelectInformap.value(mGroupId));
			}
			
			ui->stackedWidget->setCurrentWidget(ui->Filterpage);
		}
	};

	auto uicbFailer  = []{};
	Biz::UnitCallback<QMap<QString,int>>* uicb = mCallbackReceiver->createCallback<QMap<QString,int>> (uicbSuccess,uicbFailer);
	Biz::Session::getGroupManager()->getGroupMemberMsgCount (mGroupId,  uicb);
}
void GroupMsgFilterView::showEvent( QShowEvent *e )
{
	
}

GroupMsgFilterAdapter::GroupMsgFilterAdapter( QAbstractItemView* parent )
	:ListWidgetBaseAdapter(parent)
	,lastclicktimestamp(0)
	,mselectRangetype(GroupRangeType::GroupItemMsgType)
{

}

GroupMsgFilterAdapter::~GroupMsgFilterAdapter()
{

}

QWidget* GroupMsgFilterAdapter::CreateNewWidget( const QModelIndex& index )
{
	int type = index.data (GroupMsgFilterItemDataType).toInt ();
	if (GroupMsgFilterItemType_Range == type)
	{
		QString strContent = index.data (GroupMsgFilterItemDataDisplay).toString ();
		QString strItemid   = index.data (GroupMsgFilterItemDataId).toString ();
		QTreeWidget* pTreeWidget = (QTreeWidget*)getListView ();
		GroupMsgFilterRangeItemView* pRangeView = new GroupMsgFilterRangeItemView();
		pRangeView->m_pContent->setText (strContent);
		
		connect (pRangeView->m_pCheckBox,&QCheckBox::clicked,[this,pRangeView,strItemid]{
			pRangeView->m_pCheckBox->setCheckState (pRangeView->m_pCheckBox->isChecked ()?Qt::CheckState::Checked:Qt::CheckState::Unchecked);
			onGroupItemCheckClick (strItemid,pRangeView->m_pCheckBox->isChecked ());

		});
		return pRangeView;
	}
	else
	{
		QString strContent = index.data (GroupMsgFilterItemDataDisplay).toString ();
		QString strItemid   = index.data (GroupMsgFilterItemDataId).toString ();
		QString parentId = index.data(GroupMsgFilterItemDataParentid).toString();
		QString strContent2 = index.data(GroupMsgFilterItemDataSecondDisplay).toString();
		QString strItemid2   = index.data (GroupMsgFilterItemDataSecondId).toString ();

		bool ischeck = false;

		QTreeWidgetItem* pRangeItem = findParentItem (parentId);
		QTreeWidget* pTreeWidget = (QTreeWidget*)getListView ();
		GroupMsgFilterRangeItemView* pRangeView = (GroupMsgFilterRangeItemView*)pTreeWidget->itemWidget (pRangeItem,0);

		if (NULL!=pRangeView)
			ischeck = (pRangeView->m_pCheckBox->checkState() == Qt::CheckState::Checked);

		GroupMsgFilterItemView* pItemView = new GroupMsgFilterItemView();
		pItemView->m_MsgFilterItem[0]->m_pContent->setText (strContent);
		pItemView->m_MsgFilterItem[0]->m_pCheckBox->setChecked (ischeck);
		connect (pItemView->m_MsgFilterItem[0]->m_pCheckBox,&QCheckBox::clicked,[this,pItemView,strItemid]{

			onItemCheckClickFirst (strItemid,pItemView->m_MsgFilterItem[0]->m_pCheckBox->isChecked ());
		});
		if (mSelectId.contains(strItemid))
		{
			pItemView->m_MsgFilterItem[0]->m_pCheckBox->setChecked (true);
			onItemCheckClickFirst (strItemid,pItemView->m_MsgFilterItem[0]->m_pCheckBox->isChecked ());
		}

		if (strContent2.isEmpty())
		{
			pItemView->m_MsgFilterItem[1]->m_pCheckBox->setVisible(false);
		}
		else
		{
			pItemView->m_MsgFilterItem[1]->m_pContent->setText(strContent2);
			pItemView->m_MsgFilterItem[1]->m_pCheckBox->setChecked(ischeck);

			connect (pItemView->m_MsgFilterItem[1]->m_pCheckBox,&QCheckBox::clicked,[this,pItemView,strItemid2]{
				onItemCheckClickSecond (strItemid2,pItemView->m_MsgFilterItem[1]->m_pCheckBox->isChecked ());
			});
		}
		if (mSelectId.contains(strItemid2))
		{
			pItemView->m_MsgFilterItem[1]->m_pCheckBox->setChecked(true);
			onItemCheckClickSecond (strItemid2,pItemView->m_MsgFilterItem[1]->m_pCheckBox->isChecked ());
		}


		
		return pItemView;
	}
}

QSize GroupMsgFilterAdapter::sizeHint( const QStyleOptionViewItem &option, const QModelIndex &index ) const
{
	return QSize(32,32);
}

void GroupMsgFilterAdapter::updateData( QWidget* pWidget,const QModelIndex& index,const QStyleOptionViewItem& option )
{

}

void GroupMsgFilterAdapter::clearData()
{
	QTreeWidget* pTreeWidget = (QTreeWidget*)getListView ();
	pTreeWidget->clear ();
	mGroupMemberMsgMap.clear();
	mtreeWidgetItemMaps.clear();
	mtreeWidgetRangeMaps.clear();
}

void GroupMsgFilterAdapter::setGroupMsgData( const QMap<QString, int>& groupmemberMsgcountmap , const QStringList&atlist)
{
	clearData();

	QStringList groupMemberlist = groupmemberMsgcountmap.keys();

	mGroupMemberMsgMap = groupmemberMsgcountmap;

	//创建两个项
	setTreeMember(QStringLiteral("群中所有成员"),groupMemberlist);
	
	//
	//setTreeMember(QStringLiteral("群中活跃度高"),groupMemberlist);

	//群组at的消息的人
	if (atlist.size() > 0)
	{
		setTreeMember(QStringLiteral("@过你的人"), atlist);
	}
	


}

QStringList GroupMsgFilterAdapter::getCheckedGroupId()
{
	QStringList retList;
	QTreeWidget* pTreeWidget = (QTreeWidget*)getListView ();
	for (QString oneitemId : mtreeWidgetItemMaps.keys ())
	{
		QTreeWidgetItem* pItem = mtreeWidgetItemMaps.value(oneitemId);
		QTreeWidgetItem *parentItem = pItem->parent();
		QString strid = parentItem->data(0, GroupMsgFilterItemDataId).toString();
		int tmp = 0;
		if (strid == QStringLiteral("@过你的人"))
		{
			tmp = GroupItemAtType;
		}
		else
		{
			tmp = GroupItemMsgType;
		}
		

		int checkstatus = pItem->data (0,GroupMsgFilterItemDataSelectStatus).toInt ();
		if (Qt::CheckState::Checked == checkstatus)
		{
			retList.append(pItem->data(0, GroupMsgFilterItemDataId).toString());
		}
		int secondcheckstatus = pItem->data(0, GroupMsgFilterItemDataSecondSelectStatus).toInt();
		if (Qt::CheckState::Checked == secondcheckstatus)
		{
			retList.append(pItem->data(0, GroupMsgFilterItemDataSecondId).toString());
		}

// 		QString FirstretId = pItem->data(0, GroupMsgFilterItemDataId).toString();
// 		QString SecondId  = pItem->data(0, GroupMsgFilterItemDataSecondId).toString();
// 		
// 		if ( (!SecondId.isEmpty() && (SecondId == oneitemId)) && (Qt::CheckState::Checked== pItem->data(0, GroupMsgFilterItemDataSecondSelectStatus).toInt())&&(mselectRangetype == tmp) )
// 			retList.append(oneitemId);
// 		if ( (!FirstretId.isEmpty()&& (FirstretId == oneitemId)) && (Qt::CheckState::Checked == pItem->data (0,GroupMsgFilterItemDataSelectStatus).toInt ()) && (mselectRangetype == tmp))
// 			retList.append(oneitemId);

	}
	retList.removeDuplicates();
	return retList;
}

void GroupMsgFilterAdapter::setSelectIds( const QStringList& ids )
{
	mSelectId = ids;
}

void GroupMsgFilterAdapter::setTreeMember(const QString&displayname, const QStringList& ids )
{
	QTreeWidgetItem* pParentItem = NULL;
	GroupMsgFilterItem* pItem = new GroupMsgFilterItem;
	pItem->setData (0,ListWidgetBaseAdapterRoleDisableSelecte,true);
	pItem->setData (0,GroupMsgFilterItemDataType,GroupMsgFilterItemType_Range);
	pItem->setData (0,GroupMsgFilterItemDataDisplay,displayname);
	pItem->setData (0,GroupMsgFilterItemDataId,displayname);
	mtreeWidgetRangeMaps.insert(displayname, pItem);
	QTreeWidget* pTreeWidget = (QTreeWidget*)getListView ();
	pTreeWidget->addTopLevelItem(pItem);
	pParentItem = pItem;
	
	for (int nI = 0; nI < ids.size(); )
	{
		
		QString one = ids.at(nI);
		QString two;
		if (nI+1 < ids.size())
		{
			two = ids.at(nI+1);
		}
		else
			two = "";

		GroupMsgFilterItem* pItemChild = new GroupMsgFilterItem;

		QString displayName = Biz::Session::getUserVcardManager()->getUserNameByConversationId (one);
		pItemChild->setData (0,ListWidgetBaseAdapterRoleDisableSelecte,true);
		pItemChild->setData (0,GroupMsgFilterItemDataType,GroupMsgFilterItemType_Item);
		pItemChild->setData (0,GroupMsgFilterItemDataDisplay,displayName);
		pItemChild->setData (0,GroupMsgFilterItemDataId,one);
		pItemChild->setData (0, GroupMsgFilterItemDataParentid, displayname);
		pItemChild->setData (0, GroupMsgFilterItemDataCount, mGroupMemberMsgMap.value(one));
		mtreeWidgetItemMaps.insert (one,pItemChild);
		if (!two.isEmpty())
		{
			displayName = Biz::Session::getUserVcardManager()->getUserNameByConversationId (two);
			pItemChild->setData (0,GroupMsgFilterItemDataType,GroupMsgFilterItemType_Item);
			pItemChild->setData(0,ListWidgetBaseAdapterRoleDisableSelecte,true);
			pItemChild->setData (0,GroupMsgFilterItemDataSecondDisplay,displayName);
			pItemChild->setData (0, GroupMsgFilterItemDataCount, mGroupMemberMsgMap.value(two));
			pItemChild->setData (0,GroupMsgFilterItemDataSecondId,two);
			mtreeWidgetItemMaps.insert (two,pItemChild);
		}
	
		
		pParentItem->addChild (pItemChild);
		
		nI+=2;
	}



// 	for (QString oneid: ids)
// 	{
// 		GroupMsgFilterItem* pItemChild = new GroupMsgFilterItem;
// 
// 		QString displayName = Biz::Session::getUserVcardManager()->getUserNameByConversationId (oneid);
// 		pItemChild->setData (0,ListWidgetBaseAdapterRoleDisableSelecte,true);
// 		pItemChild->setData (0,GroupMsgFilterItemDataType,GroupMsgFilterItemType_Item);
// 		pItemChild->setData (0,GroupMsgFilterItemDataDisplay,displayName);
// 		pItemChild->setData (0,GroupMsgFilterItemDataId,oneid);
// 		pItemChild->setData (0, GroupMsgFilterItemDataParentid, displayname);
// 		pItemChild->setData (0, GroupMsgFilterItemDataCount, mGroupMemberMsgMap.value(oneid));
// 		pParentItem->addChild (pItemChild);
// 
// 		
// 	}
	if (displayname == QStringLiteral("群中所有成员"))
	{
		pParentItem->setExpanded (true);
	}
	//pTreeWidget->expandAll ();
	//pTreeWidget->sortItems (0,Qt::AscendingOrder);
}


QTreeWidgetItem* GroupMsgFilterAdapter::findParentItem( const QString&parentid )
{
	QTreeWidget* pTreeWidget = (QTreeWidget*)getListView ();
	if (NULL!=pTreeWidget)
	{
		int topLevelItem = pTreeWidget->topLevelItemCount ();
		for (int i=0; i < topLevelItem;i++)
		{
			QTreeWidgetItem* pItem = pTreeWidget->topLevelItem(i);
			QString id = pItem->data (0,GroupMsgFilterItemDataId).toString ();
			
			if (id == parentid)
			{
				return pItem;
			}
		}
	}
	return NULL;
}

void GroupMsgFilterAdapter::recheckRangeItem( QTreeWidgetItem* pRangeItem )
{
	QTreeWidget* pTreeWidget = (QTreeWidget*)getListView ();
	// 遍历所有的孩子，看看是不是都不check了
	int childCount = pRangeItem->childCount ();
	int ncheckCount = 0;
	for (int i=0;i<childCount;i++)
	{
		QTreeWidgetItem*pItem = pRangeItem->child (i);
		if (NULL != pItem)
		{
			int checkstatus = pItem->data (0,GroupMsgFilterItemDataSelectStatus).toInt ();
			if (Qt::CheckState::Checked == checkstatus)
				ncheckCount++;
			checkstatus = pItem->data(0, GroupMsgFilterItemDataSecondSelectStatus).toInt();
			if (Qt::CheckState::Checked == checkstatus)
				ncheckCount++;
		}
	}
	GroupMsgFilterRangeItemView* pRangeView = (GroupMsgFilterRangeItemView*)pTreeWidget->itemWidget (pRangeItem,0);
	if (NULL != pRangeView )
	{
		if (0 == ncheckCount)
			pRangeView->m_pCheckBox->setCheckState (Qt::CheckState::Unchecked);
		else if (ncheckCount == childCount)
			pRangeView->m_pCheckBox->setCheckState (Qt::CheckState::Checked);
// 		else 
// 			pRangeView->m_pCheckBox->setCheckState (Qt::CheckState::PartiallyChecked);
	}
}

void GroupMsgFilterAdapter::onGroupItemCheckClick( const QString& itemid,bool bcheck )
{
	QTreeWidget* pTreeWidget = (QTreeWidget*)getListView ();
	// 将名下所有的孩子都给变成和自己一样的值
	if (NULL!=pTreeWidget)
	{
		QString content = itemid;
		QTreeWidgetItem* pRangeItem = mtreeWidgetRangeMaps.value (content);
		if (NULL!=pRangeItem)
		{
			int childCount = pRangeItem->childCount ();
			for (int i=0;i<childCount;i++)
			{
				QTreeWidgetItem*pItem = pRangeItem->child (i);
				pItem->setData (0,GroupMsgFilterItemDataSelectStatus,bcheck?Qt::CheckState::Checked:Qt::CheckState::Unchecked);
				QString strid = pItem->data(0,GroupMsgFilterItemDataSecondId).toString();
				if (!strid.isEmpty())
				{
					pItem->setData (0,GroupMsgFilterItemDataSecondSelectStatus,bcheck?Qt::CheckState::Checked:Qt::CheckState::Unchecked);
				}
				GroupMsgFilterItemView* pwidget= (GroupMsgFilterItemView*)pTreeWidget->itemWidget (pItem,0);
				if (NULL!=pwidget)
				{
					pwidget->m_MsgFilterItem[0]->m_pCheckBox->setChecked (bcheck);
					if (!strid.isEmpty())
					{
						pwidget->m_MsgFilterItem[1]->m_pCheckBox->setChecked (bcheck);
					}
				}
			}
		}

		
	}
}

void GroupMsgFilterAdapter::onItemCheckClickFirst( const QString& itemid,bool bcheck )
{
	QTreeWidget* pTreeWidget = (QTreeWidget*)getListView ();
	if (NULL!=pTreeWidget)
	{
		QTreeWidgetItem* pItem = mtreeWidgetItemMaps.value (itemid);
		if (NULL!=pItem)
		{
			pItem->setData (0,GroupMsgFilterItemDataSelectStatus,bcheck?Qt::CheckState::Checked:Qt::CheckState::Unchecked);
			QTreeWidgetItem* pRangeItem = pItem->parent ();
			recheckRangeItem (pRangeItem);
		}
	}
}

void GroupMsgFilterAdapter::onItemCheckClickSecond( const QString& itemid,bool bcheck )
{
	QTreeWidget* pTreeWidget = (QTreeWidget*)getListView ();
	if (NULL!=pTreeWidget)
	{
		QTreeWidgetItem* pItem = mtreeWidgetItemMaps.value (itemid);
		if (NULL!=pItem)
		{
			pItem->setData (0,GroupMsgFilterItemDataSecondSelectStatus,bcheck?Qt::CheckState::Checked:Qt::CheckState::Unchecked);
			QTreeWidgetItem* pRangeItem = pItem->parent ();
			recheckRangeItem (pRangeItem);
		}
	}
}

void GroupMsgFilterAdapter::onGroupItemExpendChange( QTreeWidgetItem *item )
{
	if (NULL!=item)
	{
		if (GroupMsgFilterItemType_Range==item->data (0,GroupMsgFilterItemDataType))
		{
			QTreeWidget* pTreeWidget = (QTreeWidget*)getListView ();
			GroupMsgFilterRangeItemView* pItemView = (GroupMsgFilterRangeItemView*)pTreeWidget->itemWidget (item,0);
			if (NULL!=pItemView)
			{
				bool bExpaned = item->isExpanded ();
				pItemView->m_pExpendIcon->setPixmap (QPixmap(bExpaned?":Images/icon/pointup.png":":Images/icon/pointdown.png"));
			}
			QString strid = item->data(0, GroupMsgFilterItemDataId).toString();
			if (strid == QStringLiteral("@过你的人"))
			{
				mselectRangetype = GroupItemAtType;
			}
			else
			{
				mselectRangetype = GroupItemMsgType;
			}
		}
	}
}

void GroupMsgFilterAdapter::onGroupItemClicked( QTreeWidgetItem *item, int column )
{
	if (QApplication::doubleClickInterval () > (QDateTime::currentMSecsSinceEpoch ()-lastclicktimestamp))
		return;

	lastclicktimestamp = QDateTime::currentMSecsSinceEpoch ();

	if (NULL!=item)
	{
		if (GroupMsgFilterItemType_Range==item->data (0,GroupMsgFilterItemDataType))
		{
			item->setExpanded (!item->isExpanded ());
			QString strid = item->data(0, GroupMsgFilterItemDataId).toString();
			if (strid == QStringLiteral("@过你的人"))
			{
				mselectRangetype = GroupItemAtType;
			}
			else
			{
				mselectRangetype = GroupItemMsgType;
			}
		}
		else
		{
			// 写这里不大合适，这个逻辑应该是由单击引起的。
		}
	}
}

GroupMsgFilterRangeItemView::GroupMsgFilterRangeItemView()
{
	QWidget* pWidget = new QWidget(this);
	pWidget->setObjectName ("GroupMsgFilterRangeItemView");

	m_pCheckBox = new QCheckBox(this);
	m_pCheckBox->setObjectName ("select");
	m_pContent = new QLabel(this);
	m_pContent->setAlignment (Qt::AlignLeft|Qt::AlignVCenter);
	m_pContent->setObjectName ("rangecontent");

	m_pExpendIcon = new QLabel(this);
	m_pExpendIcon->setScaledContents (true);
	m_pExpendIcon->setFixedSize (24,24);
	m_pExpendIcon->setPixmap(QPixmap(":Images/icon/pointup.png"));
	m_pExpendIcon->setObjectName ("expendicon");

	m_pCount = new QLabel(this);
	m_pCount->setAlignment (Qt::AlignLeft|Qt::AlignVCenter);
	m_pCount->setObjectName ("itemcount");
	m_pCount->setFixedWidth (100);

	QFrameLayout* pLayout = new QFrameLayout(pWidget);
	pLayout->appendWidget (m_pCheckBox,ALINE_LEFT|ALINE_VCENTER,QMargins(10,0,0,0));
	pLayout->appendWidget (m_pContent,ALINE_LEFT|ALINE_MATCHHEIGHT|ALINE_MATCHWIDTH,QMargins(30,0,40,0));
	pLayout->appendWidget (m_pCount,ALINE_LEFT|ALINE_MATCHHEIGHT,QMargins(30,0,40,0));
	pLayout->appendWidget (m_pExpendIcon,ALINE_RIGHT|ALINE_VCENTER,QMargins(0,0,10,0));
	pWidget->setLayout (pLayout);

	QFrameLayout* pWrap = new QFrameLayout(this);
	pWrap->appendWidget (pWidget,ALINE_FILL,QMargins(0,0,0,0));
	this->setLayout(pWrap);


	this->setStyleSheet ("#GroupMsgFilterRangeItemView {border:none;background:#D7D7D7;margin-bottom:1px;}\r\n \
						 #GroupMsgFilterRangeItemView QLabel#groupcontent{color:#333333;}\r\n \
						 #GroupMsgFilterRangeItemView QLabel#groupcount{color:#999999;}\r\n \
						 #GroupMsgFilterRangeItemView  QCheckBox::indicator {width: 11px;height: 11px;border:1px solid #696969;border-radius:2px;background:#00000000;}\r\n \
						 #GroupMsgFilterRangeItemView  QCheckBox::indicator:unchecked {image:none;}\r\n \
						 #GroupMsgFilterRangeItemView  QCheckBox::indicator:checked {image: url(:/Images/icon/commen/checkbox_check.png);  }\r\n \
						 #GroupMsgFilterRangeItemView QCheckBox::indicator:indeterminate {image: url(:/Images/icon/commen/checkbox_indeterminate.png);  }\r\n \
						 ");

}

GroupMsgFilterRangeItemView::~GroupMsgFilterRangeItemView()
{

}

GroupMsgFilterItemView::GroupMsgFilterItemView()
{
// 	QWidget* pWidget = new QWidget(this);
// 	pWidget->setObjectName ("GroupMsgFilterItemView");
// 
// 	m_pCheckBoxOne = new QCheckBox(this);
// 	m_pCheckBoxOne->setObjectName ("selectOne");
// 	m_pContentOne = new QLabel(this);
// 	m_pContentOne->setAlignment (Qt::AlignLeft|Qt::AlignVCenter);
// 	m_pContentOne->setObjectName ("contentOne");
// 
// 	m_pCheckBoxTwo = new QCheckBox(this);
// 	m_pCheckBoxTwo->setObjectName ("selectTwo");
// 	m_pContentTwo = new QLabel(this);
// 	m_pContentTwo->setAlignment (Qt::AlignLeft|Qt::AlignVCenter);
// 	m_pContentTwo->setObjectName ("contentTwo");
// 
// 	QFrameLayout* pLayout = new QFrameLayout(pWidget);
// 	pLayout->appendWidget (m_pCheckBoxOne,ALINE_LEFT|ALINE_VCENTER,QMargins(10,0,0,0));
// 	pLayout->appendWidget (m_pContentOne,ALINE_LEFT|ALINE_MATCHHEIGHT|ALINE_MATCHWIDTH,QMargins(30,0,70,0));
// 
// 	pLayout->appendWidget (m_pCheckBoxTwo,ALINE_RIGHT|ALINE_VCENTER,QMargins(80,0,110,0));
// 	pLayout->appendWidget (m_pContentTwo,ALINE_RIGHT|ALINE_MATCHHEIGHT|ALINE_MATCHWIDTH,QMargins(100,0,140,0));
// 	pWidget->setLayout (pLayout);
// 
// 	QFrameLayout* pWrap = new QFrameLayout(this);
// 	pWrap->appendWidget (pWidget,ALINE_FILL,QMargins(0,0,0,0));
// 	this->setLayout(pWrap);
// 
// 
// 	this->setStyleSheet ("#GroupMsgFilterItemView {border:none;}\r\n \
// 						 #GroupMsgFilterItemView QLabel{color:#666666;}\r\n \
// 						 #GroupMsgFilterItemView  QCheckBox::indicator {width: 11px;height: 11px;border:1px solid #696969;border-radius:2px;background:#00000000;}\r\n \
// 						 #GroupMsgFilterItemView  QCheckBox::indicator:unchecked {image:none;}\r\n \
// 						 #GroupMsgFilterItemView  QCheckBox::indicator:checked {image: url(:/Images/icon/commen/checkbox_check.png);  }\r\n \
// 						 #GroupMsgFilterItemView QCheckBox::indicator:indeterminate {image: url(:/Images/icon/commen/checkbox_indeterminate.png);  }\r\n \
// 						 ");


	for (int nI = 0; nI<2; nI++)
	{
		m_MsgFilterItem[nI] = new MsgFilterItem(this);
		m_MsgFilterItem[nI]->setObjectName (QString("MsgFilterItem%1").arg(nI+1));
	}

	QWidget* pWidget = new QWidget(this);
	pWidget->setObjectName ("MsgFilterItem");

	QFrameLayout* pLayout = new QFrameLayout(pWidget);
	pLayout->appendWidget (m_MsgFilterItem[0],ALINE_LEFT|ALINE_VCENTER,QMargins(10,0,180,0));
	pLayout->appendWidget (m_MsgFilterItem[1],ALINE_LEFT|ALINE_VCENTER,QMargins(230,0,400,0));
	pWidget->setLayout (pLayout);

	QFrameLayout* pWrap = new QFrameLayout(this);
	pWrap->appendWidget (pWidget,ALINE_FILL,QMargins(0,0,0,0));
	this->setLayout(pWrap);

	this->setStyleSheet ("#GroupMsgFilterItemView {border:none;}");
}

GroupMsgFilterItemView::~GroupMsgFilterItemView()
{

}

MsgFilterItem::MsgFilterItem(QWidget*parent)
{
	QWidget* pWidget = new QWidget(this);
	pWidget->setObjectName ("MsgFilterItem");

	m_pCheckBox = new QCheckBox(this);
	m_pCheckBox->setObjectName ("select");
	m_pContent = new QLabel(this);
	m_pContent->setAlignment (Qt::AlignLeft|Qt::AlignVCenter);
	m_pContent->setObjectName ("content");

	QFrameLayout* pLayout = new QFrameLayout(pWidget);
	pLayout->appendWidget (m_pCheckBox,ALINE_LEFT|ALINE_VCENTER,QMargins(10,0,0,0));
	pLayout->appendWidget (m_pContent,ALINE_LEFT|ALINE_MATCHHEIGHT|ALINE_MATCHWIDTH,QMargins(30,0,70,0));
	pWidget->setLayout (pLayout);

	QFrameLayout* pWrap = new QFrameLayout(this);
	pWrap->appendWidget (pWidget,ALINE_FILL,QMargins(0,0,0,0));
	this->setLayout(pWrap);


	this->setStyleSheet ("#MsgFilterItem {border:none;}\r\n \
						 #MsgFilterItem QLabel{color:#666666;}\r\n \
						 #MsgFilterItem  QCheckBox::indicator {width: 11px;height: 11px;border:1px solid #696969;border-radius:2px;background:#00000000;}\r\n \
						 #MsgFilterItem  QCheckBox::indicator:unchecked {image:none;}\r\n \
						 #MsgFilterItem  QCheckBox::indicator:checked {image: url(:/Images/icon/commen/checkbox_check.png);  }\r\n \
						 #MsgFilterItem QCheckBox::indicator:indeterminate {image: url(:/Images/icon/commen/checkbox_indeterminate.png);  }\r\n \
						 ");
}

MsgFilterItem::~MsgFilterItem()
{

}
