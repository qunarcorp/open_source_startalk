#include "Subscriptionnumlistview.h"
#include "Session.h"
#include "AccountData.h"
#include "Account.h"
#include "SystemConfigData.h"
#include "Subscriptionnumitemmodel.h"
#include "Subscriptionnumitemsortproxymodel.h"
#include "subscriptionnumitem.h"

SubScriptionNumListView::SubScriptionNumListView(QWidget *parent)
	: QListView(parent)
{
	msubscriptionItemModel = new SubScriptionNumItemModel(this);
	pSortFilterModel = new SubScriptionNumItemSortProxyModel(this);
	pSortFilterModel->setSourceModel(msubscriptionItemModel);
	this->setModel(pSortFilterModel);
	pSortFilterModel->sort(0);    

	setEditTriggers(QAbstractItemView::NoEditTriggers);
	setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
	setItemDelegate(new SubscriptionNumItemDelegate());

	 connect(&Biz::Session::currentAccount(),&Biz::Account::sgMachineListRecive, this, &SubScriptionNumListView::onSubScriptionRecive );
}

SubScriptionNumListView::~SubScriptionNumListView()
{

}

void SubScriptionNumListView::onSubScriptionRecive( const QStringList& list )
{
	QString strhost = "@"+Biz::Session::getSystemConfig()->getXmppDomain();
	foreach(QString str, list)
		msubscriptionItemModel->getOrCreateItem(str+strhost, str);
}
