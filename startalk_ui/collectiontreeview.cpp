#include "collectiontreeview.h"
#include "collectiontreeitemmodel.h"
#include "collectiontreeitemsortproxymodel.h"
#include "collectionitem.h"
#include "Session.h"
#include "conversationmanager.h"
#include "CallbackReceiver.h"
#include <QKeyEvent>
#include "UIFrame.h"
#include "ConversationController.h"
#include "SystemConfigData.h"
#include "UserVcardManager.h"
#include "portraithelper.h"
#include "GroupManager.h"

CollectionTreeView::CollectionTreeView(QWidget *parent)
	: QTreeView(parent)
	, mReceiver(new Biz::CallbackReceiver(this))
	,lastDbClickTick(0)
{
	mcollectionTreeItemModel = new CollectionTreeItemModel(this);
	mcollectionItemSortFilterModel = new CollectionTreeItemSortProxyModel(this);
	mcollectionItemSortFilterModel->setSourceModel(mcollectionTreeItemModel);
	this->setModel(mcollectionTreeItemModel);
	mcollectionTreeItemModel->sort(0);    

	this->header()->hide();
	this->setEditTriggers(QAbstractItemView::NoEditTriggers);  
	setItemDelegate(new CollectionItemDelegate());

	setStyleSheet ("border:none;background:#00000000;");

	connect(Biz::Session::getConverSationManager(), &Biz::ConverSationManager::sgCollectionBindUser, this, &CollectionTreeView::onCollectionBindUser );
	connect(Biz::Session::getUserVcardManager(), &Biz::UserVcardManager::sgPortraitUpdate, this, & CollectionTreeView::onCollectionPortrait);
	connect(Biz::Session::getUserVcardManager(),&Biz::UserVcardManager::sgGroupHeaderUpdate,this,&CollectionTreeView::onUpdateGroupHeader);
	connect(Biz::Session::getGroupManager(),&Biz::GroupManager::sgInitRoomVcardListAsync,this,&CollectionTreeView::onInitRoomsVcard);
	connect(Biz::Session::getUserVcardManager(), &Biz::UserVcardManager::sgUseVcardChanged, this, & CollectionTreeView::OnUserVcardChange);

	setContextMenuPolicy(Qt::CustomContextMenu);  

	setExpandsOnDoubleClick(false);
	setRootIsDecorated(false);

	connect(this, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(doubleClicked(QModelIndex)));
	connect(this, SIGNAL(clicked(QModelIndex)), this, SLOT(clicked(QModelIndex)));
	//initList();
}

CollectionTreeView::~CollectionTreeView()
{

}

QString CollectionTreeView::selectedUserID()
{
	QModelIndex currentIndex = this->currentIndex();
	if( currentIndex.isValid() )
		return currentIndex.data(CollectionItem::UserID).toString();        
	return QString("");
}

void CollectionTreeView::onCollectionBindUserList( QList <QSharedPointer<Biz::CollectionBindUserInfo>> inforlist )
{
	if (inforlist.size() <= 0)
	{
		return;
	}

	//mcollectionTreeItemModel->initCollectionBindItem(inforlist);
	QStringList strIds;
	for (QSharedPointer<Biz::CollectionBindUserInfo> oneitem: inforlist)
	{
		if (!oneitem.isNull())
		{
			QString userId = oneitem->BindUserId();
			auto cbSuccess = [this, userId](int ncount)
			{
				mcollectionTreeItemModel->createCollectionBindUser(userId, ncount);
				CollectionItem *pCollection = mcollectionTreeItemModel->getBindUser(userId);
				CreateChildrenItem(userId, pCollection);
			};

			auto cbfail = []{};

			auto callback = mReceiver->createCallback<int>(cbSuccess, cbfail);
			Biz::Session::getConverSationManager()->getCollectionBindUserUnReadCount(userId ,callback);
			strIds.push_back(userId);
		}
		
	}

	Biz::Session::getUserVcardManager()->getDomainCollectionUsersVcardByfore(strIds);

}

void CollectionTreeView::doubleClicked( const QModelIndex& index )
{
	showChatDialog_helper();
	lastDbClickTick = QDateTime::currentMSecsSinceEpoch();
}

void CollectionTreeView::clicked( const QModelIndex& index )
{
	if (500>QDateTime::currentMSecsSinceEpoch()-lastDbClickTick)
	{
		return;
	}
	expand_helper();
}

void CollectionTreeView::keyPressEvent( QKeyEvent* event1 )
{
	if(event1->key() == Qt::Key_Return)
	{
		showChatDialog_helper();
	}
	QTreeView::keyPressEvent(event1);
}

void CollectionTreeView::showChatDialog_helper()
{
	QModelIndex currentIndex = this->currentIndex();

	QString userName = selectedUserID();
	if(userName.isEmpty())
		return;

	Biz::Session::getConverSationManager()->setConversationMessageRead(userName);
	CollectionItem* pItem =  mcollectionTreeItemModel->getBindItemOfBlog( userName, Biz::MessageUtil::makeSureUserId(userName));
	if(pItem)
	{
		//pItem->setUnreadCount(0);
		//emit sgChatDialog(userName, pItem->getDisplayName());
	}
}

void CollectionTreeView::expand_helper()
{
	QModelIndex currentIndex = this->currentIndex(); 
	if( currentIndex.isValid() ) 
	{
		QString parentId;
		if (currentIndex.data(CollectionItem::CollectionBindType).toInt()==CollectionItem::CollectionBindUser)
		{
			QString gid =  currentIndex.data(CollectionItem::UserID).toString();
			parentId = gid;
			CollectionItem* ri = mcollectionTreeItemModel->getBindUser(gid);

			if (isExpanded(currentIndex)&&ri->rowCount()>0)
			{
				setExpanded(currentIndex,false);
			}
			else 
			{

				CreateChildrenItem(gid,ri);

				setExpanded(currentIndex,true);
			}

			MainApp::UIFrame::getConversationController()->activeCollectionUser(gid);
		}
		else
		{
			QString userid = currentIndex.data(CollectionItem::UserID).toString();

			if (!userid.isEmpty())
			{
				//父节点的id
				QModelIndex parentIndex = mcollectionTreeItemModel->parent(currentIndex);
				QString parentId = parentIndex.data(CollectionItem::UserID).toString();

				CollectionItem* item = mcollectionTreeItemModel->getBindItemOfBlog(parentId, userid);

				MainApp::UIFrame::getConversationController()->activeCollectionConversation(parentId,userid);
				//未读数全部置成已读

				item->setBindUserItemUnReadCount(0);

				auto updateSuccess = [this, parentId](int ncount)
				{
					//设置一下父item 上的未读数
					auto cbSuccess = [this, parentId](int ncount)
					{
						CollectionItem *parentItem = mcollectionTreeItemModel->getBindUser(parentId);
						parentItem->setBindUserUnReadCount(ncount);
					};

					auto cbfail = []{};

					auto callback = mReceiver->createCallback<int>(cbSuccess, cbfail);
					Biz::Session::getConverSationManager()->getCollectionBindUserUnReadCount(parentId ,callback);
				};

				auto updatefail = []{};

				auto updatecallback = mReceiver->createCallback<bool>(updateSuccess, updatefail);
				Biz::Session::getConverSationManager()->setCollectionReadFlag(parentId, userid, updatecallback);

				QString id = "collection_rbt" + QString("@") + Biz::Session::getSystemConfig()->getXmppDomain();
				Biz::Session::getConverSationManager()->setLocalCoversationMessageRead(id);

			}

		}
	}
}

void CollectionTreeView::CreateChildrenItem( const QString&parentid, const CollectionItem*parentItem )
{
	QString bindid = parentid;

	auto cbSuccess = [this, bindid, parentItem](const QMap<QString, int>& list)
	{
		mCollectionItemInfo.insert(bindid, list.keys());

		mcollectionTreeItemModel->createCollectionConversationId(list, parentItem);

		QStringList ids = list.keys();
		QStringList signalids;
		for(QString id: ids)
		{
			if (id.contains("@conference."))
			{
				Biz::Session::getUserVcardManager()->getCollectionRoomVcardByfore(id);
			}
			else
			{
				signalids.push_back(id);
			}
		}

		Biz::Session::getUserVcardManager()->getDomainCollectionUsersVcardByfore(signalids);
	};

	auto cbfail = []{};

	auto callback = mReceiver->createCallback<QMap<QString, int>>(cbSuccess, cbfail);
	Biz::Session::getConverSationManager()->getCollectionConversationIdbyBindUserId(bindid, callback);
}

void CollectionTreeView::onCollectionPortrait( const QString& id )
{
	if (id.isEmpty())
	{
		return;
	}
	//判断一下，有代收的继续往下走，如果没代收的，就直接返回
	if (mbindUserlist.size() <= 0)
	{
		return;
	}

	CollectionItem *pUserItem = mcollectionTreeItemModel->getBindUser(id);
	if (pUserItem)
	{
		QPixmap pixmap = Biz::PortraitHelper::getUserPortrait(id);
		pUserItem->setAvatar(pixmap.toImage());

		QString displayname = Biz::Session::getUserVcardManager()->getUserNameByConversationId(id);
		pUserItem->setBindUserDisplay(displayname);
	}


	QStringList list = mcollectionTreeItemModel->getItemOfBlogById(id);
	for (QString parentId: list)
	{
		CollectionItem *pItem = mcollectionTreeItemModel->getBindItemOfBlog(parentId, id);
		if (pItem)
		{
			QPixmap pixmap = Biz::PortraitHelper::getUserPortrait(id);
			pItem->setAvatar(pixmap.toImage());

			QString displayname;
			if (id.contains("@conference."))
			{
				displayname = Biz::Session::getGroupManager()->getGroupLocalNickNamebyId(id);
			}
			else
			{
				displayname = Biz::Session::getUserVcardManager()->getUserNameByConversationId(id);
			}
			pItem->setBindUserItemDisplay(displayname);
		}
	}

}

void CollectionTreeView::onUpdateGroupHeader( const QString& groupjid )
{
	if (groupjid.isEmpty())
	{
		return;
	}
	//判断一下，有代收的继续往下走，如果没代收的，就直接返回
	if (mbindUserlist.size() <= 0)
	{
		return;
	}

	QStringList list = mcollectionTreeItemModel->getItemOfBlogById(groupjid);
	for (QString parentId: list)
	{
		CollectionItem *pItem = mcollectionTreeItemModel->getBindItemOfBlog(parentId, groupjid);
		if (pItem)
		{
			QPixmap pixmap = Biz::PortraitHelper::getUserPortrait(groupjid);
			pItem->setAvatar(pixmap.toImage());
		}
	}
}

void CollectionTreeView::onInitRoomsVcard(QList<QSharedPointer<Biz::RoomVcard>> list)
{
	if (list.size() <= 0)
	{
		return;
	}

	for(QSharedPointer<Biz::RoomVcard> item: list)
	{
		if (!item.isNull())
		{
			QString mucName = item->RoomId();
			QString nickName = item->RoomName();

			QStringList list = mcollectionTreeItemModel->getItemOfBlogById(mucName);
			for (QString parentId: list)
			{
				CollectionItem *pItem = mcollectionTreeItemModel->getBindItemOfBlog(parentId, mucName);
				if (pItem)
				{
					pItem->setBindUserItemDisplay(nickName);
				}
			}
		}
		
	}
}

void CollectionTreeView::OnUserVcardChange( const QStringList& userinforlist )
{
	if (userinforlist.size() <= 0)
	{
		return ;
	}
	//判断一下，有代收的继续往下走，如果没代收的，就直接返回
	if (mbindUserlist.size() <= 0)
	{
		return;
	}

	foreach (QString userid, userinforlist)
	{
		QSharedPointer<Biz::ImSelfPerson> person = Biz::Session::getUserVcardManager()->userVcard(userid);
		if (!person.isNull())
		{
			QString userid = person->strUserId;
			QStringList list = mcollectionTreeItemModel->getItemOfBlogById(userid);
			for (QString parentId: list)
			{
				CollectionItem *pItem = mcollectionTreeItemModel->getBindItemOfBlog(parentId, userid);
				if (pItem)
				{
					pItem->setBindUserItemDisplay(person->displayName());
				}
			}
		}
	}
}

void CollectionTreeView::onCollectionBindUser( QList <QSharedPointer<Biz::CollectionBindUserInfo>> inforlist )
{

	if (inforlist.size() <= 0)
	{
		return;
	}
	for (QSharedPointer<Biz::CollectionBindUserInfo> oneitem: inforlist)
	{
		if (!oneitem.isNull())
		{
			QString userId = oneitem->BindUserId();
			mbindUserlist.push_back(userId);
		}
		
	}
}

void CollectionTreeView::initList()
{
	auto cbSuccess = [this](const QList <QSharedPointer<Biz::CollectionBindUserInfo>>& list)
	{

		onCollectionBindUserList(list);
	};

	auto cbfail = []{};

	auto callback = mReceiver->createCallback<QList <QSharedPointer<Biz::CollectionBindUserInfo>>>(cbSuccess, cbfail);
	Biz::Session::getConverSationManager()->getCollectionBindUserList(callback);
}