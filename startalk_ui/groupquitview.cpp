#include "groupquitview.h"
#include "ui_groupquitview.h"
#include "diywidgit/customviews/qframelayout.h"
#include "animationreactor.h"
#include "CallbackReceiver.h"
#include "BizCallback.h"

#include "UIFrame.h"
#include "NotifyCenterController.h"

#include "Session.h"
#include "MessageManager.h"
#include "GroupManager.h"
#include "accountmanager.h"

#include "Account.h"

#include "GroupListData.h"

class GroupQuitItem : public QTreeWidgetItem
{
public:

    virtual bool operator <(const QTreeWidgetItem &other) const
    {
        bool desc = false;

        int thisType = data(0,GroupQuitAdapter::GroupQuitItemData::GroupQuitItemDataType).toInt ();
        int otherType  = other.data (0,GroupQuitAdapter::GroupQuitItemData::GroupQuitItemDataType).toInt ();

        if (GroupQuitAdapter::GropQuitItemType::GropQuitItemType_Range != thisType 
            && GroupQuitAdapter::GropQuitItemType::GropQuitItemType_Range == thisType)
            return desc;
        else if (GroupQuitAdapter::GropQuitItemType::GropQuitItemType_Range == thisType 
            && GroupQuitAdapter::GropQuitItemType::GropQuitItemType_Range != thisType)
            return !desc;
        else
        {
            if (GroupQuitAdapter::GropQuitItemType::GropQuitItemType_Range == thisType)
            {
                quint64 thisRangeMin = data(0,GroupQuitAdapter::GroupQuitItemData::GroupQuitItemDataRangeMin).toULongLong ();
                quint64 otherRangeMin = other.data(0,GroupQuitAdapter::GroupQuitItemData::GroupQuitItemDataRangeMin).toULongLong ();
                return thisRangeMin < otherRangeMin ? !desc : desc;
            }
            else
            {
                // 同一个组里面，时间小的在上面
                quint64 thisItemTime = data (0, GroupQuitAdapter::GroupQuitItemData::GroupQuitItemDataTimestamp).toULongLong ();
                quint64 otherItemTime = other.data (0, GroupQuitAdapter::GroupQuitItemData::GroupQuitItemDataTimestamp).toULongLong ();

                return thisItemTime < otherItemTime ? !desc : desc;
            }
        }
        return desc;
    }
};

GroupQuitView::GroupQuitView(QWidget *parent)
    : LocalManDialog(parent)
    , m_pAdapter(NULL)
    , mCallbackReceiver(NULL)
{

    mCallbackReceiver = new Biz::CallbackReceiver(this);

    ui = new Ui::GroupQuitView();
    ui->setupUi(this);

    using namespace Qt;
    auto remove = WindowTitleHint;
	// add by wangchao 2018.08.30
    auto add = FramelessWindowHint | WindowMinMaxButtonsHint | WindowStaysOnTopHint;
    setAttribute(Qt::WA_AlwaysShowToolTips, true);
    setAttribute(Qt::WA_TranslucentBackground, true); 
    overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));
#ifdef QCHAT
    setWindowIcon(QIcon(":/Images/Deal_chat.ico"));
#else
    setWindowIcon(QIcon(":/Images/Deal.ico"));
#endif
    setWindowTitle(QStringLiteral("批量退群"));

    auto titlebar = ui->titlebar;
    titlebar->setMaxable(false);
    connect(titlebar, &TitlebarWidget::sgCloseOnClicked, this, &GroupQuitView::onMin);
    connect(titlebar, &TitlebarWidget::sgMinOnClicked, this, &GroupQuitView::onMin);



    m_pAdapter = new GroupQuitAdapter(ui->treeWidget);
    ui->treeWidget->setItemDelegate(m_pAdapter);

    ui->treeWidget->setExpandsOnDoubleClick(false);
    ui->treeWidget->setIndentation(0);

    connect (ui->treeWidget,&QTreeWidget::itemExpanded,m_pAdapter,&GroupQuitAdapter::onGroupItemExpendChange);
    connect (ui->treeWidget,&QTreeWidget::itemCollapsed,m_pAdapter,&GroupQuitAdapter::onGroupItemExpendChange);

    connect (ui->treeWidget,&QTreeWidget::itemClicked,m_pAdapter,&GroupQuitAdapter::onGroupItemClicked);

    connect (m_pAdapter,&GroupQuitAdapter::sgGroupSelectCountChange,[this](int count){

        ui->warning->setText(0 == count ? 0: QStringLiteral("*选中%1个，退出群组后将无法查看聊天记录，如果有重要信息请预先保存").arg (count));
        ui->quit->setEnabled(0 != count);
    });


    connect (ui->quit,&QPushButton::clicked,this,&GroupQuitView::onQuitGroupClick);

    ui->sw->setCurrentWidget(ui->emptypage);
}

GroupQuitView::~GroupQuitView()
{
    delete ui;
}

void GroupQuitView::showEvent(QShowEvent * e)
{
    if (NULL != m_pAdapter)
        m_pAdapter->clearData ();

    ui->sw->setCurrentWidget(ui->emptypage);

    AnimationReactorSingleton::getInstance ()->opacityInWidget (this,100);


    auto uicbSuccess = [this](const QMap<QString,quint64>& groupsLastMessageTime){
        if (NULL!=m_pAdapter)
        {
            m_pAdapter->setGroupData (groupsLastMessageTime);
            ui->sw->setCurrentWidget(ui->wrap);
        }
    };

    auto uicbFailer  = []{};
    Biz::UnitCallback<QMap<QString,quint64>>* uicb = mCallbackReceiver->createCallback<QMap<QString,quint64>> (uicbSuccess,uicbFailer);
    Biz::Session::getMessageManager ()->getGroupsLastMessageTime (uicb);
}

void GroupQuitView::onQuitGroupClick(bool b)
{
    if (!MainApp::UIFrame::getNotifyCenterController ()->alertMessageWithCancle (QStringLiteral("退出群组后将无法查看聊天记录，是否继续?")))
        return;

    QStringList groupids = m_pAdapter->getCheckedGroupId ();

    for (QString groupid : groupids)
    {
         Biz::Session::getGroupManager ()->leaveGroup (groupid);
    }
}



void GroupQuitView::setTips(const QString& tips)
{
    ui->tip->setText(tips);
}


GroupQuitItemGroupView::GroupQuitItemGroupView()
{
    QWidget* pWidget = new QWidget(this);
    pWidget->setObjectName ("GroupQuitItemGroupView");

    m_pCheckBox = new QCheckBox(this);
    m_pCheckBox->setObjectName ("select");
    m_pContent = new QLabel(this);
    m_pContent->setAlignment (Qt::AlignLeft|Qt::AlignVCenter);
    m_pContent->setObjectName ("groupcontent");

    m_pExpendIcon = new QLabel(this);
    m_pExpendIcon->setScaledContents (true);
    m_pExpendIcon->setFixedSize (24,24);
    m_pExpendIcon->setPixmap(QPixmap(":Images/icon/pointup.png"));
    m_pExpendIcon->setObjectName ("expendicon");

    m_pCount = new QLabel(this);
    m_pCount->setAlignment (Qt::AlignLeft|Qt::AlignVCenter);
    m_pCount->setObjectName ("groupcount");
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


    this->setStyleSheet ("#GroupQuitItemGroupView {border:none;background:#D7D7D7;margin-bottom:1px;}\r\n \
                         #GroupQuitItemGroupView QLabel#groupcontent{color:#333333;}\r\n \
                         #GroupQuitItemGroupView QLabel#groupcount{color:#999999;}\r\n \
                         #GroupQuitItemGroupView  QCheckBox::indicator {width: 11px;height: 11px;border:1px solid #696969;border-radius:2px;background:#00000000;}\r\n \
                         #GroupQuitItemGroupView  QCheckBox::indicator:unchecked {image:none;}\r\n \
                         #GroupQuitItemGroupView  QCheckBox::indicator:checked {image: url(:/Images/icon/commen/checkbox_check.png);  }\r\n \
                         #GroupQuitItemGroupView QCheckBox::indicator:indeterminate {image: url(:/Images/icon/commen/checkbox_indeterminate.png);  }\r\n \
                         ");

}

GroupQuitItemGroupView::~GroupQuitItemGroupView()
{

}

GroupQuitItemView::GroupQuitItemView()
{
    QWidget* pWidget = new QWidget(this);
    pWidget->setObjectName ("GroupQuitItemView");

    m_pCheckBox = new QCheckBox(this);
    m_pCheckBox->setObjectName ("select");
    m_pContent = new QLabel(this);
    m_pContent->setAlignment (Qt::AlignLeft|Qt::AlignVCenter);
    m_pContent->setObjectName ("content");

    m_pLaseMessageTime = new QLabel(this);
    m_pLaseMessageTime->setObjectName ("expendicon");
    m_pLaseMessageTime->setAlignment (Qt::AlignRight|Qt::AlignVCenter);

    QFrameLayout* pLayout = new QFrameLayout(pWidget);
    pLayout->appendWidget (m_pCheckBox,ALINE_LEFT|ALINE_VCENTER,QMargins(10,0,0,0));
    pLayout->appendWidget (m_pContent,ALINE_LEFT|ALINE_MATCHHEIGHT|ALINE_MATCHWIDTH,QMargins(30,0,70,0));
    pLayout->appendWidget (m_pLaseMessageTime,ALINE_RIGHT|ALINE_MATCHHEIGHT,QMargins(0,0,10,0));
    pWidget->setLayout (pLayout);

    QFrameLayout* pWrap = new QFrameLayout(this);
    pWrap->appendWidget (pWidget,ALINE_FILL,QMargins(0,0,0,0));
    this->setLayout(pWrap);


    this->setStyleSheet ("#GroupQuitItemView {border:none;}\r\n \
                         #GroupQuitItemView QLabel{color:#666666;}\r\n \
                         #GroupQuitItemView  QCheckBox::indicator {width: 11px;height: 11px;border:1px solid #696969;border-radius:2px;background:#00000000;}\r\n \
                         #GroupQuitItemView  QCheckBox::indicator:unchecked {image:none;}\r\n \
                         #GroupQuitItemView  QCheckBox::indicator:checked {image: url(:/Images/icon/commen/checkbox_check.png);  }\r\n \
                         #GroupQuitItemView QCheckBox::indicator:indeterminate {image: url(:/Images/icon/commen/checkbox_indeterminate.png);  }\r\n \
                         ");

   

}

GroupQuitItemView::~GroupQuitItemView()
{

}

QWidget* GroupQuitAdapter::CreateNewWidget(const QModelIndex& index)
{
    int type = index.data (GroupQuitItemDataType).toInt ();
    if (GropQuitItemType_Range == type)
    {
        QString strContent = index.data (GroupQuitItemDataContent).toString ();
        QString strItemid   = index.data (GroupQuitItemDataId).toString ();
        QTreeWidget* pTreeWidget = (QTreeWidget*)getListView ();
        GroupQuitItemGroupView* pRangeView = new GroupQuitItemGroupView();
        pRangeView->m_pContent->setText (strContent);

        connect (pRangeView->m_pCheckBox,&QCheckBox::clicked,[this,pRangeView,strItemid]{
            pRangeView->m_pCheckBox->setCheckState (pRangeView->m_pCheckBox->isChecked ()?Qt::CheckState::Checked:Qt::CheckState::Unchecked);
            onGroupItemCheckClick (strItemid,pRangeView->m_pCheckBox->isChecked ());
        });
        return pRangeView;
    }
    else
    {
        QString strContent = index.data (GroupQuitItemDataContent).toString ();
        QString strItemid   = index.data (GroupQuitItemDataId).toString ();
        quint64 timestamp  = index.data (GroupQuitItemDataTimestamp).toULongLong ();

        bool ischeck = false;

        QTreeWidgetItem* pRangeItem = findGroup (timestamp);
        QTreeWidget* pTreeWidget = (QTreeWidget*)getListView ();
        GroupQuitItemGroupView* pRangeView = (GroupQuitItemGroupView*)pTreeWidget->itemWidget (pRangeItem,0);

        if (NULL!=pRangeView)
            ischeck = (pRangeView->m_pCheckBox->checkState() == Qt::CheckState::Checked);

        GroupQuitItemView* pItemView = new GroupQuitItemView();
        pItemView->m_pContent->setText (strContent);

        pItemView->m_pCheckBox->setChecked (ischeck);

        QString data = QDateTime::fromMSecsSinceEpoch (timestamp).date ().toString ("MM-dd");

        if (0 == timestamp)
            data = QStringLiteral("30天前");

        pItemView->m_pLaseMessageTime->setText (data);
        connect (pItemView->m_pCheckBox,&QCheckBox::clicked,[this,pItemView,strItemid]{
            onItemCheckClick (strItemid,pItemView->m_pCheckBox->isChecked ());
        });
        return pItemView;
    }
}

QSize GroupQuitAdapter::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QSize(32,32);
}

GroupQuitAdapter::GroupQuitAdapter(QAbstractItemView* parent) : ListWidgetBaseAdapter(parent)
    ,lastclicktimestamp(0)
{
     connect (Biz::Session::getGroupManager (),&Biz::GroupManager::sgGroupLeavedReceived,this,&GroupQuitAdapter::onGroupDestroyed);

      connect (Biz::Session::getGroupManager (),&Biz::GroupManager::sgGroupDestroyed,this,&GroupQuitAdapter::onGroupDestroyed);
      connect (Biz::Session::getGroupManager (),&Biz::GroupManager::sgDelRegisterReceived,[this](const QString& groupBareJid,const QString& userid){
          if (0 == Biz::MessageUtil::compareJid (userid,Biz::Session::getAccountManager ()->accountData ().UserID ()))
          {
              this->onGroupDestroyed (groupBareJid);
          }
      });
}

GroupQuitAdapter::~GroupQuitAdapter()
{

}


void GroupQuitAdapter::onGroupItemCheckClick(const QString& itemid,bool bcheck)
{
    QTreeWidget* pTreeWidget = (QTreeWidget*)getListView ();
    // 将名下所有的孩子都给变成和自己一样的值
    if (NULL!=pTreeWidget)
    {
        QString content = itemid;
        QTreeWidgetItem* pRangeItem = treeWidgetRangeMaps.value (content);
        if (NULL!=pRangeItem)
        {
            int childCount = pRangeItem->childCount ();
            for (int i=0;i<childCount;i++)
            {
                QTreeWidgetItem*pItem = pRangeItem->child (i);
                pItem->setData (0,GroupQuitItemDataSelectStatus,bcheck?Qt::CheckState::Checked:Qt::CheckState::Unchecked);
                GroupQuitItemView* pwidget= (GroupQuitItemView*)pTreeWidget->itemWidget (pItem,0);
                if (NULL!=pwidget)
                {
                    pwidget->m_pCheckBox->setChecked (bcheck);
                }
            }
        }

        emit sgGroupSelectCountChange(getCheckedGroupId ().size ());
    }
}

void GroupQuitAdapter::onItemCheckClick(const QString& itemid,bool bcheck)
{
    QTreeWidget* pTreeWidget = (QTreeWidget*)getListView ();
    if (NULL!=pTreeWidget)
    {
        QTreeWidgetItem* pItem = treeWidgetItemMaps.value (itemid);
        if (NULL!=pItem)
        {
            pItem->setData (0,GroupQuitItemDataSelectStatus,bcheck?Qt::CheckState::Checked:Qt::CheckState::Unchecked);
            QTreeWidgetItem* pRangeItem = pItem->parent ();
            recheckRangeItem (pRangeItem);
        }

        emit sgGroupSelectCountChange (getCheckedGroupId ().size ());
    }
}

void GroupQuitAdapter::onGroupItemExpendChange(QTreeWidgetItem* item)
{
    if (NULL!=item)
    {
        if (GropQuitItemType_Range==item->data (0,GroupQuitItemDataType))
        {
            QTreeWidget* pTreeWidget = (QTreeWidget*)getListView ();
            GroupQuitItemGroupView* pItemView = (GroupQuitItemGroupView*)pTreeWidget->itemWidget (item,0);
            if (NULL!=pItemView)
            {
                bool bExpaned = item->isExpanded ();
                pItemView->m_pExpendIcon->setPixmap (QPixmap(bExpaned?":Images/icon/pointup.png":":Images/icon/pointdown.png"));
            }
        }
    }
}

void GroupQuitAdapter::setGroupData(const QMap<QString,quint64>& groups)
{
    QTreeWidget* pTreeWidget = (QTreeWidget*)getListView ();
    pTreeWidget->clear ();
    treeWidgetItemMaps.clear ();
    treeWidgetRangeMaps.clear ();

    // 创建组，这里半写死就可以
    // 创建组，这里半写死就可以
    QDateTime dt = QDateTime::currentDateTime ();
    dt.setTime(QTime());
    dt = dt.addDays (-1);
    quint64 currentTimeStamp = QDateTime::currentMSecsSinceEpoch () - Biz::Session::currentAccount ().getTimeOffsetFromServer ();
    quint64 baseTimeStame = dt.toMSecsSinceEpoch()-Biz::Session::currentAccount ().getTimeOffsetFromServer ();

    QList<QPair<QPair<quint64,quint64>,QString>> groupDatas;
    groupDatas.append (QPair<QPair<quint64,quint64>,QString>(QPair<quint64,quint64>(baseTimeStame - (quint64)60*60*24*1000*15,currentTimeStamp),QStringLiteral("常用群")));
    groupDatas.append (QPair<QPair<quint64,quint64>,QString>(QPair<quint64,quint64>(baseTimeStame - (quint64)60*60*24*1000*30,baseTimeStame - (quint64)60*60*24*1000*15),QStringLiteral("15天未活跃")));
    groupDatas.append (QPair<QPair<quint64,quint64>,QString>(QPair<quint64,quint64>(0,baseTimeStame - (quint64)60*60*24*1000*30),QStringLiteral("30天未活跃")));


    for (QString grouid : groups.keys ())
    {
        quint64 lasttime = groups.value (grouid);
        QTreeWidgetItem* pParentItem = findGroup (lasttime);
        if (NULL == pParentItem)
        {
            for (QPair<QPair<quint64,quint64>,QString> pair:groupDatas)
            {
                if (lasttime >= pair.first.first)
                {
                    GroupQuitItem* pItem = new GroupQuitItem;
                    pItem->setData (0,ListWidgetBaseAdapterRoleDisableSelecte,true);
                    pItem->setData (0,GroupQuitItemDataType,GropQuitItemType_Range);
                    pItem->setData (0,GroupQuitItemDataRangeMin,pair.first.first);
                    pItem->setData (0,GroupQuitItemDataRangeMax,pair.first.second);
                    pItem->setData (0,GroupQuitItemDataContent,pair.second);
                    pItem->setData (0,GroupQuitItemDataId,pair.second);
                    QTreeWidget* pTreeWidget = (QTreeWidget*)getListView ();
                    pTreeWidget->addTopLevelItem(pItem);
                    pParentItem = pItem;
                    treeWidgetRangeMaps.insert (pair.second,pItem);
                    break;
                }
            }
        }
        if (NULL!=pParentItem)
        {
            GroupQuitItem* pItem = new GroupQuitItem;

            QString groupName = Biz::Session::getGroupManager ()->getGroupNickName (grouid);
            pItem->setData (0,ListWidgetBaseAdapterRoleDisableSelecte,true);
            pItem->setData (0,GroupQuitItemDataType,GropQuitItemType_Item);
            pItem->setData (0,GroupQuitItemDataTimestamp,lasttime);
            pItem->setData (0,GroupQuitItemDataContent,groupName);
            pItem->setData (0,GroupQuitItemDataId,grouid);
            treeWidgetItemMaps.insert (grouid,pItem);
            pParentItem->addChild (pItem);
            pParentItem->setData (0, GroupQuitItemDataChildCount, pParentItem->childCount ());
        }
    }

    pTreeWidget->expandAll ();
    pTreeWidget->sortItems (0,Qt::AscendingOrder);
}

QTreeWidgetItem* GroupQuitAdapter::findGroup(quint64 lasttime)
{
    QString data = QDateTime::fromMSecsSinceEpoch (lasttime).date ().toString ("MM-dd");
    QTreeWidget* pTreeWidget = (QTreeWidget*)getListView ();
    if (NULL!=pTreeWidget)
    {
        int topLevelItem = pTreeWidget->topLevelItemCount ();
        for (int i=0; i < topLevelItem;i++)
        {
            QTreeWidgetItem* pItem = pTreeWidget->topLevelItem(i);
            quint64 nMin = pItem->data (0,GroupQuitItemDataRangeMin).toULongLong ();
            quint64 nMax = pItem->data (0,GroupQuitItemDataRangeMax).toULongLong ();
            if (nMin <= lasttime && lasttime < nMax)
            {
                return pItem;
            }
        }
    }
    return NULL;
}

void GroupQuitAdapter::deleteItem(const QString& id)
{
    QTreeWidget* pTreeWidget = (QTreeWidget*)getListView ();
    if (NULL!=pTreeWidget && treeWidgetItemMaps.contains (id))
    {
        QTreeWidgetItem* pItem = treeWidgetItemMaps.value (id);
        if (NULL!=pItem)
        {
            QTreeWidgetItem* pParentItem = pItem->parent ();
            if (NULL!=pParentItem)
            {
                pParentItem->takeChild (pParentItem->indexOfChild (pItem));
                delete pItem;
                if (0 == pParentItem->childCount ())
                {
                    QString rangeText = pParentItem->data (0,GroupQuitItemDataContent).toString ();
                    treeWidgetRangeMaps.remove (rangeText);
                    pTreeWidget->takeTopLevelItem (pTreeWidget->indexOfTopLevelItem (pParentItem));
                    delete pParentItem;
                }
            }
        }
        treeWidgetItemMaps.remove (id);
    }
}

void GroupQuitAdapter::onGroupItemClicked(QTreeWidgetItem *item, int column)
{
    if (QApplication::doubleClickInterval () > (QDateTime::currentMSecsSinceEpoch ()-lastclicktimestamp))
        return;

    lastclicktimestamp = QDateTime::currentMSecsSinceEpoch ();

    if (NULL!=item)
    {
        if (GropQuitItemType_Range==item->data (0,GroupQuitItemDataType))
        {
            item->setExpanded (!item->isExpanded ());
        }
        else
        {
            // 写这里不大合适，这个逻辑应该是由单击引起的。
        }
    }
}

void GroupQuitAdapter::clearData()
{
    QTreeWidget* pTreeWidget = (QTreeWidget*)getListView ();
    pTreeWidget->clear ();
    treeWidgetItemMaps.clear ();
    treeWidgetRangeMaps.clear ();
}

QStringList GroupQuitAdapter::getCheckedGroupId()
{
    QStringList retList;
    QTreeWidget* pTreeWidget = (QTreeWidget*)getListView ();
    for (QString groupid : treeWidgetItemMaps.keys ())
    {
        QTreeWidgetItem* pItem = treeWidgetItemMaps.value(groupid);
        if (Qt::CheckState::Checked == pItem->data (0,GroupQuitItemDataSelectStatus).toInt ())
            retList.append(groupid);
    }
    return retList;
}

void GroupQuitAdapter::onGroupDestroyed(const QString& groupBareJid)
{
    QTreeWidget* pTreeWidget = (QTreeWidget*)getListView ();
    if (treeWidgetItemMaps.contains (groupBareJid))
    {
        QTreeWidgetItem* pItem = treeWidgetItemMaps.value (groupBareJid);
		if (NULL != pItem)
		{
			QTreeWidgetItem* pRangeItem = pItem->parent ();
			if (NULL != pRangeItem)
			{
				QWidget* pwidget = pTreeWidget->itemWidget (pItem,0);
				pRangeItem->removeChild (pItem);
				delete pItem;
				delete pwidget;
				recheckRangeItem (pRangeItem);
				treeWidgetItemMaps.remove (groupBareJid);
				pRangeItem->setData (0, GroupQuitItemDataChildCount, pRangeItem->childCount ());
			}
			
		}
        
    }
}

void GroupQuitAdapter::recheckRangeItem(QTreeWidgetItem* pRangeItem)
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
			int checkstatus = pItem->data (0,GroupQuitItemDataSelectStatus).toInt ();
			if (Qt::CheckState::Checked == checkstatus)
				ncheckCount++;
		}
    }
    GroupQuitItemGroupView* pRangeView = (GroupQuitItemGroupView*)pTreeWidget->itemWidget (pRangeItem,0);
	if (NULL != pRangeView )
	{
		if (0 == ncheckCount)
			pRangeView->m_pCheckBox->setCheckState (Qt::CheckState::Unchecked);
		else if (ncheckCount == childCount)
			pRangeView->m_pCheckBox->setCheckState (Qt::CheckState::Checked);
		else 
			pRangeView->m_pCheckBox->setCheckState (Qt::CheckState::PartiallyChecked);
	}
    
}

void GroupQuitAdapter::updateData(QWidget* pWidget,const QModelIndex& index,const QStyleOptionViewItem& option)
{
    int type = index.data(GroupQuitItemDataType).toInt ();
    if (GropQuitItemType_Range == type)
    {
        GroupQuitItemGroupView* pGroupView = dynamic_cast<GroupQuitItemGroupView*>(pWidget);
        if (NULL!=pGroupView)
        {
            int count = index.data (GroupQuitItemDataChildCount).toInt ();
            pGroupView->m_pCount->setText (QString("(%1)").arg (count));
            QFontMetrics fm(pGroupView->m_pContent->font ());
            int contentwidth = fm.width (pGroupView->m_pContent->text ());
            QPoint pt = pGroupView->m_pContent->pos ();
            QPoint pt2(pt.x ()+contentwidth+10,pt.y ());
            pGroupView->m_pCount->move (pt2);
        }
    }
}
