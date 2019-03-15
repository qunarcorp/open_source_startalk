#include "combinationlistview.h"
#include "combinationitemmodel.h"
#include "combinationitem.h"
#include "Session.h"
#include "Account.h"
#include "combinationitemsortproxymodel.h"
#include "staffmanager.h"
#include "SystemDefine.h"
CombinationListView::CombinationListView(QWidget *parent)
	: QListView(parent),lastDbClickTick(0)
{
	mcombinationItemModel = new CombinationItemModel(this);
	pSortFilterModel = new CombinationItemSortProxyModel(this);
	pSortFilterModel->setSourceModel(mcombinationItemModel);
	this->setModel(pSortFilterModel);
	pSortFilterModel->sort(0);    

	setEditTriggers(QAbstractItemView::NoEditTriggers);
	setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
	setItemDelegate(new CombinationItemDelegate());

	connect(this, SIGNAL(clicked(QModelIndex)), this, SLOT(onitemClicked(QModelIndex)));
	connect(this, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(onItemdoubleClicked(QModelIndex)));
	connect(Biz::Session::getStaffManager(), &Biz::StaffManager::sgWorkSpaceWaitCount, this, &CombinationListView::onWorkSpaceCountChange );
}

CombinationListView::~CombinationListView()
{

}

void CombinationListView::setItemExtendable(const QString& id,bool bExtendable)
{
	QString strDispName = Biz::Session::currentAccount().getUserNameById(id);
	if(strDispName.isEmpty())
		strDispName = id;

	 CombinationItem* pItem =  mcombinationItemModel->getOrCreateItem(id, strDispName);
     if (NULL!=pItem)
         pItem->setCombinationExtendable (bExtendable);
}

void CombinationListView::onitemClicked( const QModelIndex&index )
{
	if (1000>QDateTime::currentMSecsSinceEpoch()-lastDbClickTick)
	{
		return;
	}

	QString id = index.model()->data(index, CombinationItem::Combinationid).toString();

	emit sgcombinationItemClicked(id);
}

void CombinationListView::onItemdoubleClicked( const QModelIndex& index )
{
	lastDbClickTick = QDateTime::currentMSecsSinceEpoch();

	QString Jid = index.model()->data(index, CombinationItem::Combinationid).toString();
	if (Jid.isEmpty())
	{
		return;
	}
	
}

void CombinationListView::addOneItem( const QString& id,const QString& name)
{
	
	mcombinationItemModel->getOrCreateItem(id, name);
	

	Log::e(QString("CombinationListView::addOneItem id =%1").arg(id));
}

void CombinationListView::setItemImage(const QString& id, const QImage& image)
{
    mcombinationItemModel->setItemIconImage (id,image);
}

void CombinationListView::setItemUnReadIconable( const QString& id, bool bable )
{
	QString strDispName = Biz::Session::currentAccount().getUserNameById(id);
	if(strDispName.isEmpty())
		strDispName = id;

	CombinationItem* pItem =  mcombinationItemModel->getOrCreateItem(id, strDispName);
	if (NULL!=pItem)
		pItem->setCombinationUnReadIconable (bable);
}

void CombinationListView::setItemUnReadCount( const QString&id, int ncount )
{
	QString strDispName = Biz::Session::currentAccount().getUserNameById(id);
	if(strDispName.isEmpty())
		strDispName = id;

	CombinationItem* pItem =  mcombinationItemModel->getOrCreateItem(id, strDispName);
	if (NULL!=pItem)
		pItem->setCombinationUnReadIconCount(ncount);
}

void CombinationListView::deleteOneItem( const QString&jid, const QString& strDispName )
{
	CombinationItem* pItem =  mcombinationItemModel->getOrCreateItem(jid, strDispName);
	if (NULL!=pItem)
	this->mcombinationItemModel->removeCombinationItem(jid);
}

void CombinationListView::onWorkSpaceCountChange( int ncount )
{
	int nsize = this->mcombinationItemModel->rowCount();
	for (int nI = 0; nI < nsize; nI++)
	{
		QModelIndex index = mcombinationItemModel->index(nI, 0);
		QString Jid = index.model()->data(index, CombinationItem::Combinationid).toString();
		if (!Jid.isEmpty() && Jid.compare(Util::WorkPlaceId, Qt::CaseInsensitive) == 0)
		{

			setItemUnReadIconable(Jid, true);
			setItemUnReadCount(Jid, ncount);
		}

	}

}