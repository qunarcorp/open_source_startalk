#include "combinationitemmodel.h"
#include "combinationitem.h"
#include "Log.h"
CombinationItemModel::CombinationItemModel(QObject *parent)
	: QStandardItemModel(parent)
{

}

CombinationItemModel::~CombinationItemModel()
{

}

CombinationItem* CombinationItemModel::getOrCreateItem( const QString& id, const QString& Name )
{
	Log::assert(!id.isEmpty());
	if(mCombinationItemMap.contains(id)) 
	{
		return mCombinationItemMap.value(id);
	} 
	else
	{
		CombinationItem* item = NULL;
		if(Name != NULL)
		{
			item = new CombinationItem(id, Name);        
			mCombinationItemMap.insert(id, item);
			appendRow(item);
		}        
		return item;
	}
}

void CombinationItemModel::setItemIconImage(const QString&id,const QImage& image)
{
    if (mCombinationItemMap.contains (id) && NULL!=mCombinationItemMap.value (id))
    {
        mCombinationItemMap.value (id)->setIconImage (image);
    }
}

void CombinationItemModel::removeCombinationItem( const QString& jid )
{
	QModelIndexList indexes = match(index(0, 0, QModelIndex()), CombinationItem::Combinationid, jid, -1, Qt::MatchFlag::MatchExactly);
	for (int i = 0; i < indexes.size(); ++i)
	{
		CombinationItem* p =  (CombinationItem*)itemFromIndex(indexes.at(i));        
		if(p)
			removeRow(p->row());
	}
}
