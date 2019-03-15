#include "RobotSearchedListWidgetAdapter.h"
#include "RobotSearchedItem.h"
#include "Session.h"
#include "portraithelper.h"
#include "Account.h"
#include "Player.h"
RobotListWidgetAdapter::RobotListWidgetAdapter(QListView *parent)
	: ListWidgetBaseAdapter(parent)
{

}

RobotListWidgetAdapter::~RobotListWidgetAdapter()
{

}

QWidget* RobotListWidgetAdapter::CreateNewWidget(const QModelIndex& index)
{
	QString rbtId = index.data(RobotShearchedDataRbtId).toString();
	if (!rbtId.isEmpty())
	{
		RobotSearchedItem* pItem = new RobotSearchedItem();
		pItem->setPixmap(Biz::PortraitHelper::getUserProtraitByDefault(rbtId,Biz::DEFAULT_PATH_ROBOT));
		pItem->setId(rbtId);
		pItem->setName(Biz::Session::currentAccount().getUserNameById(rbtId));
		pItem->setShowType(RobotSearchedItem::ShowType_List);

		return pItem;
	}
	return NULL;
	
}

QSize RobotListWidgetAdapter::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	return QSize(38,38);
}

RobotSearchResultListAdapter::RobotSearchResultListAdapter(QListView* parent)
	: ListWidgetBaseAdapter(parent)
{

}

RobotSearchResultListAdapter::~RobotSearchResultListAdapter()
{

}

QWidget* RobotSearchResultListAdapter::CreateNewWidget(const QModelIndex& index)
{
	QString rbtId = index.data(RobotShearchedDataRbtId).toString();
	if (!rbtId.isEmpty() && rbtCatche.contains(rbtId))
	{
		QSharedPointer<Biz::RobotVcard> spData = rbtCatche.value(rbtId);
		if (!spData.isNull())
		{
			RobotSearchedItem* pItem = new RobotSearchedItem();
			pItem->setPixmap(Biz::PortraitHelper::getUserProtraitByDefault(rbtId,Biz::DEFAULT_PATH_ROBOT));
			pItem->setId(rbtId);
			pItem->setName(spData->RbtName());
			pItem->setShowType(RobotSearchedItem::ShowType_Search);
			return pItem;
		}
	}
	return NULL;
}

QSize RobotSearchResultListAdapter::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	return QSize(38,38);
}

void RobotSearchResultListAdapter::setRobotVcard(const QMap<QString,QSharedPointer<Biz::RobotVcard>>& rbtMap)
{
	rbtCatche = rbtMap;
}
