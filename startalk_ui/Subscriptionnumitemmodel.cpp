#include "Subscriptionnumitemmodel.h"
#include "subscriptionnumitem.h"
#include "Log.h"
SubScriptionNumItemModel::SubScriptionNumItemModel(QObject *parent)
	: QStandardItemModel(parent)
{



}

SubScriptionNumItemModel::~SubScriptionNumItemModel()
{

}

SubscriptionNumItem * SubScriptionNumItemModel::getOrCreateItem( const QString& jid, const QString& gpName/*=NULL*/ )
{
	Log::assert(!jid.isEmpty());

	if(mjidSubScriptionItemMap.contains(jid)) {
		return mjidSubScriptionItemMap[jid];
	} else {
		SubscriptionNumItem* item = NULL;
		if(gpName != NULL)
		{
			//bool autoJoin = Biz::Session::currentAccount().FindGroupJoin(jid);
			item = new SubscriptionNumItem(jid, gpName, false);        
			mjidSubScriptionItemMap[jid] = item;

			appendRow(item);
		}        
		return item;
	}
}
