#include "SearchUserListWidget.h"
#include <QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QLabel>
#include <QColor>
#include "MessageListData.h"
#include "SpellHelper.h"
#include "portraithelper.h"

enum ItemType
{
    ListWidgetItemRoleTypeGroup,
    ListWidgetItemRoleTypeItem,
    ListWidgetItemRoleTypeEmpty,
	ListWidgetItemRoleTypeMore,
	ListWidgetItemRoleRecord
};
enum ListWidgetItemRoles
{
    ListWidgetItemRolesBase = ListWidgetBaseAdapterUserRoleBase,
    ListWidgetItemRoleType,

    ListWidgetItemRolesGroupBase,
    ListWidgetItemRoleGroupName,
    ListWidgetItemRoleGroupSortIndex,

    ListWidgetItemRoleItemBase,
    ListWidgetItemRoleItemSortableKey,
    ListWidgetItemRoleItemId,
    ListWidgetItemRoleItemChatType,
    ListWidgetItemRoleItemTitle,
    ListWidgetItemRoleItemDescription

};

const int HASMORE = 11;
const int MSGRECORD=12;

#pragma region sortableListViewItem
class SearchResultListWidgetSortableItem : public QListWidgetItem
{
public:
    explicit SearchResultListWidgetSortableItem(QListWidget *view = 0, int type = Type)
        : QListWidgetItem(view,type){};
    ~SearchResultListWidgetSortableItem(){};
public:
    // 同组内进行排序，不同组不排序，排序按照value1的拼音进行排序
    virtual bool operator <(const QListWidgetItem &other) const
    {
        bool bAtTop = true;
        // 组序号是正序
        int thisIndex = data(ListWidgetItemRoleGroupSortIndex).toInt();
        int otherIndex = other.data(ListWidgetItemRoleGroupSortIndex).toInt();

        // 判断大组
        if (thisIndex<otherIndex)
        {
            return bAtTop;
        }
        // 判断大组
        if (thisIndex>otherIndex)
        {
            return !bAtTop;
        }

        // 同组 ，判断类别
        ItemType thisType = (ItemType)this->data(ListWidgetItemRoleType).toInt();
        ItemType otherType = (ItemType)other.data(ListWidgetItemRoleType).toInt();
        if (thisType < otherType)
        {
            return bAtTop;
        }
        if (thisType > otherType)
        {
            return !bAtTop;
        }

        // 同组且同类
        QString thisSortKey = this->data(ListWidgetItemRoleItemSortableKey).toString();
        QString otherSortKey = other.data(ListWidgetItemRoleItemSortableKey).toString();
        return thisSortKey.compare(otherSortKey)<=0?bAtTop:!bAtTop;
    }
public:
};
#pragma endregion sortableListViewItem

#pragma region ItemWidget
class SearchUserWidget : public QWidget
{
public:
    SearchUserWidget() : QWidget(NULL){
        this->setObjectName(QStringLiteral("widget"));
        this->setGeometry(QRect(130, 110, 381, 42));
        this->setStyleSheet(QString::fromUtf8("QWidget\n"
            "{\n"
            " font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\"\n"
            "}\n"
            "\n"
            "QLabel#title\n"
            "{\n"
            "	font-size:14px;\n"
            "	color:#333333;\n"
            "}\n"
            "\n"
            "QLabel#desctription\n"
            "{\n"
            "	font-size:10px;\n"
            "	color:#666666;\n"
            "}"));
        horizontalLayout = new QHBoxLayout(this);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setContentsMargins(28, 0, 0, 0);
        header = new QLabel(this);
        header->setObjectName(QStringLiteral("header"));
        header->setMinimumSize(QSize(28, 28));
        header->setMaximumSize(QSize(28, 28));
        //header->setScaledContents(false);

        horizontalLayout->addWidget(header);

        widget_2 = new QWidget(this);
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setSpacing(1);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setContentsMargins(0, 5, 0, 5);
        title = new QLabel(widget_2);
        title->setObjectName(QStringLiteral("title"));

        verticalLayout->addWidget(title);

        desctription = new QLabel(widget_2);
        desctription->setObjectName(QStringLiteral("desctription"));
        desctription->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(desctription);


        horizontalLayout->addWidget(widget_2);
    };
    ~SearchUserWidget(){};

	void setMoreSheet(bool bret)
	{
		if (bret)
		{
			this->setStyleSheet(QString::fromUtf8("QWidget\n"
				"QLabel#title\n"
				"{\n"
				"	font-size:14px;\n"
				"   font-weight:bold;"
				"	color:#FF0000;\n"
				"}\n"
				));
		}
		else
		{
			this->setStyleSheet(QString::fromUtf8("QWidget\n"
				"{\n"
				" font-family:\"\345\276\256\350\275\257\351\233\205\351\273\221\"\n"
				"}\n"
				"\n"
				"QLabel#title\n"
				"{\n"
				"	font-size:14px;\n"
				"	color:#333333;\n"
				"}\n"
				"\n"
				"QLabel#desctription\n"
				"{\n"
				"	font-size:10px;\n"
				"	color:#666666;\n"
				"}"));
		}

	};
public:
    void setTitle(const QString& strTitle)
    {
        this->title->setText(strTitle);
        this->title->setToolTip(strTitle);
    };
    void setDescription(const QString& strDes)
    {
        this->desctription->setText(strDes);
        this->desctription->setToolTip(strDes);
    };
    void hideIcon()
    {
        this->header->setVisible(false);
    };
    void hideDescription(){
        this->desctription->setVisible(false);
    };
    void setIcon(const QPixmap& pixmap)
    {
		QPixmap pix = pixmap;
		pix = QPixmap::fromImage(pix.toImage().scaled(header->size()));
        this->header->setPixmap(pix);
        //this->header->setScaledContents(true);
    }
    
	void setHeadSize(QSize size)
	{
		header->setFixedSize(size);
	}

	void setTitleStyle()
	{
		this->title->setStyleSheet("	font-size:14px;\n"
									"   text-align:center;"
									"   font-weight:bold;"
									"	color:#8B658B;\n");
	}
private:
    QHBoxLayout *horizontalLayout;
    QLabel *header;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QLabel *title;
    QLabel *desctription;
};
#pragma endregion

SearchUserListWidget::SearchUserListWidget(QWidget *parent)
    : QListWidget(parent)
{
    pAdapter = new SearchUserListWidgetAdapter(this);

    using namespace Qt;
    auto remove = WindowTitleHint;
    auto add = Qt::Tool |FramelessWindowHint | Qt::Popup;
    overrideWindowFlags( (Qt::WindowFlags)((windowFlags() & ~remove) | add));

    this->setItemDelegate(pAdapter);

    this->setSortingEnabled(true);

    this->resize(300,400); 
    setStyleSheet("QListWidget{border: 1px solid #3A3A3A;background-color:#EEF0F0F0;}");

    connect(this, &QListWidget::itemClicked, this, &SearchUserListWidget::onItemClicked);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

SearchUserListWidget::~SearchUserListWidget()
{
}


void SearchUserListWidget::setListData(const QList<Biz::SearchResulteItemGroupModule>& dataList)
{
    clearData();
    mDataList = dataList;
    int fixheight = 0;

    int sortGroupIndex = 0;
	//点击按钮进行搜索历史记录
	fixheight += 28;
	SearchResultListWidgetSortableItem* itemMore = new SearchResultListWidgetSortableItem(this);
	itemMore->setData(ListWidgetItemRoleType,ListWidgetItemRoleRecord);
	QString strRecordTitle = QStringLiteral("            点击搜索聊天记录");
	itemMore->setData(ListWidgetItemRoleGroupName,strRecordTitle);
	itemMore->setData(ListWidgetItemRoleGroupSortIndex,++sortGroupIndex);
	itemMore->setData(ListWidgetItemRoleItemChatType, MSGRECORD);
	itemMore->setData(ListWidgetItemRoleItemId,"SearchID");
	addItem(itemMore);

    for (Biz::SearchResulteItemGroupModule groupModule:mDataList)
    {
        if (groupModule.mItemList.isEmpty())
        {
            continue;
        }
        sortGroupIndex++;
		//标题
        SearchResultListWidgetSortableItem* item = new SearchResultListWidgetSortableItem(this);
        item->setData(ListWidgetItemRoleType,ListWidgetItemRoleTypeGroup);
        item->setData(ListWidgetBaseAdapterRoleDisableSelecte,true);
        item->setData(ListWidgetItemRoleGroupName,groupModule.groupName);
        item->setData(ListWidgetItemRoleGroupSortIndex,sortGroupIndex);
        addItem(item);
        fixheight += 28;
        fixheight += groupModule.mItemList.size()*42;
        QList<Biz::SearchResulteItemModule> showList = groupModule.mItemList.mid(0,200);
		//标题下面的项
        for (Biz::SearchResulteItemModule itemModule:showList)
        {
            SearchResultListWidgetSortableItem* item = new SearchResultListWidgetSortableItem(this);
            item->setData(ListWidgetItemRoleType,ListWidgetItemRoleTypeItem);
            item->setData(ListWidgetItemRoleItemId,itemModule.conversationId);
            item->setData(ListWidgetItemRoleItemTitle,itemModule.valueFirst);
            item->setData(ListWidgetItemRoleItemDescription,itemModule.valueSecend);
            item->setData(ListWidgetItemRoleItemChatType,itemModule.chatType);
            item->setData(ListWidgetItemRoleGroupSortIndex,sortGroupIndex);
            item->setData(ListWidgetItemRoleItemSortableKey,itemModule.valueFirst);
            addItem(item);
        }

		//这地方有一个更多按钮
		if (groupModule.hasmore)
		{
			fixheight += 28;
			SearchResultListWidgetSortableItem* itemMore = new SearchResultListWidgetSortableItem(this);
			itemMore->setData(ListWidgetItemRoleType,ListWidgetItemRoleTypeMore);
			QString strnewTitle = QStringLiteral("查看更多%1").arg(groupModule.groupName);
			itemMore->setData(ListWidgetItemRoleGroupName,strnewTitle);
			itemMore->setData(ListWidgetItemRoleGroupSortIndex,++sortGroupIndex);
			itemMore->setData(ListWidgetItemRoleItemChatType, HASMORE);
			itemMore->setData(ListWidgetItemRoleItemId,groupModule.id);
			addItem(itemMore);
		}

    }

	int ncount = count();
	

    if (0== ncount)
    {

        // 加一个默认选项
//         SearchResultListWidgetSortableItem* item = new SearchResultListWidgetSortableItem(this);
//         item->setData(ListWidgetItemRoleType,ListWidgetItemRoleTypeGroup);
//         item->setData(ListWidgetItemRoleGroupName,QStringLiteral("打开与[%1]的会话").arg(m_searchKey));
//         item->setData(ListWidgetItemRoleItemChatType,Biz::ChatMessage);
//         item->setData(ListWidgetItemRoleItemId,Biz::MessageUtil::makeSureUserJid(m_searchKey));
//         
//         addItem(item);
//         fixheight += 28;
		setNotSearch(sortGroupIndex++, fixheight);
    }


    if (ncount>0)
    {
		sortGroupIndex++;
		setNotSearch(sortGroupIndex, fixheight);

        setCurrentRow(qMin(1,count()-1));
    }


    
    if (count()==0)
        this->hide();
    else
    {
        fixheight = qMin(fixheight,400);
        this->setFixedHeight(fixheight+10);// 10个像素的的buffer,可能得去掉
        this->scrollToTop();
        this->show();
        this->activateWindow();
    }
}

void SearchUserListWidget::onItemClicked(QListWidgetItem *pItem)
{
    if (NULL!=pItem )
    {
        if (pItem->data(ListWidgetBaseAdapterRoleDisableSelecte).toBool())
        {
            // 没响应
            return;
        }

        QString conversationId = pItem->data(ListWidgetItemRoleItemId).toString();
		
        int chattype = pItem->data(ListWidgetItemRoleItemChatType).toInt();

        if (!conversationId.isEmpty())
        {
            if (Biz::ChatMessage == chattype)
            {
				if (!conversationId.contains("@"))
				{
					conversationId = Biz::MessageUtil::makeSureUserJid(conversationId);
				}
                emit sgItemSelected(conversationId);
            }
            if (Biz::GroupMessage == chattype)
            {
				if (!conversationId.contains("@"))
				{
					conversationId = Biz::MessageUtil::makeSureGroupJid(conversationId);
				}
                emit sgGroupSelected(conversationId);
            }
            if (Biz::subscription == chattype)
            {
                emit  sgRobotSelected(conversationId);
            }
			if (chattype == 11)
			{
				emit sgMoreSelected(conversationId, m_searchKey);
			}
			if(chattype == 12)
			{
				emit sgHistoryRecord();
			}
			if (Biz::UnKnow == chattype)
			{
				emit sgItemSelected(conversationId);
			}
        }
		if (chattype != 11)
		{
			this->hide();
		}
        
    }
}

void SearchUserListWidget::clearData()
{
    this->clear();
}

void SearchUserListWidget::setNotSearch( int nsearch, int& height )
{
	SearchResultListWidgetSortableItem* item = new SearchResultListWidgetSortableItem(this);
	item->setData(ListWidgetItemRoleType,ListWidgetItemRoleTypeGroup);
	item->setData(ListWidgetBaseAdapterRoleDisableSelecte,true);
	item->setData(ListWidgetItemRoleGroupName,QStringLiteral("找不到或离职的点击这里"));
	item->setData(ListWidgetItemRoleGroupSortIndex,nsearch);
	addItem(item);
	height += 28;
	height += 42;
	//在后面加一个默认的选项
	SearchResultListWidgetSortableItem* itemdefault = new SearchResultListWidgetSortableItem(this);
	itemdefault->setData(ListWidgetItemRoleItemId,m_searchKey);
	itemdefault->setData(ListWidgetItemRoleType,ListWidgetItemRoleTypeItem);
	itemdefault->setData(ListWidgetItemRoleItemTitle,QStringLiteral("打开与[%1]的会话").arg(m_searchKey));
	itemdefault->setData(ListWidgetItemRoleItemChatType,Biz::UnKnow);
	itemdefault->setData(ListWidgetItemRoleGroupSortIndex,nsearch);

	addItem(itemdefault);
}

void SearchUserListWidget::setMoveDown()
{
	if (count() <= 0)
	{
		return;
	}
    int currrentRow = this->currentRow();
    int nextCurrentRow = (currrentRow+1) % count();

    QListWidgetItem* pItem = item(nextCurrentRow);
    if (NULL!= pItem && ListWidgetItemRoleTypeGroup == pItem->data(ListWidgetItemRoleType).toInt())
    {
        nextCurrentRow = (nextCurrentRow+1) % count();
    }
    setCurrentRow(nextCurrentRow);
}

void SearchUserListWidget::setMoveUp()
{
    int currrentRow = this->currentRow();
    int nextCurrentRow = (currrentRow - 1 + count())%count();
    QListWidgetItem* pItem = item(nextCurrentRow);
    if (NULL!= pItem && ListWidgetItemRoleTypeGroup == pItem->data(ListWidgetItemRoleType).toInt())
    {
        nextCurrentRow = (nextCurrentRow - 1 + count())%count();
    }
    setCurrentRow(nextCurrentRow);
}

void SearchUserListWidget::selectItem()
{
    QListWidgetItem* pItem = this->currentItem();
    onItemClicked(pItem);
}

#pragma region Adapter
SearchUserListWidgetAdapter::SearchUserListWidgetAdapter(QListView *parent)
    : ListWidgetBaseAdapter(parent,QColor::fromRgb(0,0,0,0),QColor::fromRgb(0x1b,0xa9,0xba),QColor::fromRgb(0x1b,0xa9,0xba))
{

}

SearchUserListWidgetAdapter::~SearchUserListWidgetAdapter()
{

}

QWidget* SearchUserListWidgetAdapter::CreateNewWidget(const QModelIndex& index)
{
    int roleType = index.data(ListWidgetItemRoleType).toInt();
	if (ListWidgetItemRoleRecord == roleType)
	{
		QString groupName = index.data(ListWidgetItemRoleGroupName).toString();
		SearchUserWidget* pWidget = new SearchUserWidget();
		pWidget->hideIcon();
		pWidget->hideDescription();
		pWidget->setTitle(groupName);
		pWidget->setTitleStyle();

		return pWidget;
	}
    if (ListWidgetItemRoleTypeGroup == roleType)
    {
        QString groupName = index.data(ListWidgetItemRoleGroupName).toString();
        SearchUserWidget* pWidget = new SearchUserWidget();
        pWidget->hideIcon();
        pWidget->hideDescription();
        pWidget->setTitle(groupName);
		
		pWidget->setMoreSheet(false);
		
        return pWidget;
    }
	if (ListWidgetItemRoleTypeMore == roleType)
	{
		QString groupName = index.data(ListWidgetItemRoleGroupName).toString();
		SearchUserWidget* pWidget = new SearchUserWidget();
		pWidget->hideDescription();
		pWidget->setTitle(groupName);
		
		pWidget->setMoreSheet(true);
		QPixmap pixmap = Biz::PortraitHelper::loadPixmap(":/Images/icon/search.png");
		pWidget->setHeadSize(QSize(26, 26));
		pWidget->setIcon(pixmap.scaled(QSize(25, 25), Qt::KeepAspectRatio, Qt::SmoothTransformation));
		
		return pWidget;
		
	}
    if (ListWidgetItemRoleTypeItem == roleType)
    {
        QString title = index.data(ListWidgetItemRoleItemTitle).toString();
        QString desc = index.data(ListWidgetItemRoleItemDescription).toString();
        QString id = index.data(ListWidgetItemRoleItemId).toString();
        SearchUserWidget* pWidget = new SearchUserWidget();
        if (desc.isEmpty())
            pWidget->hideDescription();
        else
            pWidget->setDescription(desc);
        pWidget->setTitle(title);
		//pWidget->setHeadSize(QSize(42, 42));
        QPixmap pixmap = Biz::PortraitHelper::getUserPortrait(id);
        pWidget->setIcon(pixmap);

        return pWidget;
    }
    if (ListWidgetItemRoleTypeEmpty == roleType)
    {
        QString groupName = index.data(ListWidgetItemRoleGroupName).toString();
        SearchUserWidget* pWidget = new SearchUserWidget();
        pWidget->hideIcon();
        pWidget->hideDescription();
        pWidget->setTitle(groupName);
        return pWidget;
    }
    return NULL;
}

QSize SearchUserListWidgetAdapter::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    int roleType = index.data(ListWidgetItemRoleType).toInt();
    if (ListWidgetItemRoleTypeGroup == roleType)
    {
        return QSize(28,28);
    }
    if (ListWidgetItemRoleTypeItem == roleType)
    {
        return QSize(42,42);
    }
	
    return QSize(28,28);
}
#pragma endregion Adapter