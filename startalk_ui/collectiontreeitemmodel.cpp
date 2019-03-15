#include "collectiontreeitemmodel.h"
#include "collectionitem.h"
#include "Player.h"
#include "portraithelper.h"
#include "Session.h"
#include "UserVcardManager.h"

CollectionTreeItemModel::CollectionTreeItemModel(QObject *parent)
	: QStandardItemModel(parent)
{

}

CollectionTreeItemModel::~CollectionTreeItemModel()
{

}

void CollectionTreeItemModel::initCollectionBindItem( const QList <QSharedPointer<Biz::CollectionBindUserInfo>>& inforlist)
{
	for (QSharedPointer<Biz::CollectionBindUserInfo> oneItem: inforlist)
	{
		if (!oneItem.isNull())
		{
			CollectionItem *pcollectionItem = new CollectionItem(oneItem->BindUserId(), oneItem->BindUserName());
			pcollectionItem->setCollectionItemType(CollectionItem::CollectionBindUser);

			QPixmap pixmap = Biz::PortraitHelper::getUserPortrait(oneItem->BindUserId());
			pcollectionItem->setAvatar(pixmap.toImage());
			//pcollectionItem->setBindUserUnReadCount(10);



			this->appendRow(pcollectionItem);
			m_BindUserItemMap.insert(oneItem->BindUserId(), pcollectionItem);
			QList<QString> temp;
			m_UserItemMapOfBlong.insert(oneItem->BindUserId(), temp);
		}
		
	}
}

void CollectionTreeItemModel::createCollectionBindUser( const QString& bindUserId, int ncount )
{
	if (!m_BindUserItemMap.contains(bindUserId))
	{
		QString displayname = Biz::Session::getUserVcardManager()->getUserNameByConversationId(bindUserId);
		if (displayname.isEmpty())
		{
			displayname = Biz::MessageUtil::makeSureUserId(bindUserId);
		}
		CollectionItem *pcollectionItem = new CollectionItem(bindUserId, displayname);
		pcollectionItem->setCollectionItemType(CollectionItem::CollectionBindUser);

		QPixmap pixmap = Biz::PortraitHelper::getUserPortrait(bindUserId);
		pcollectionItem->setAvatar(pixmap.toImage());
		pcollectionItem->setBindUserUnReadCount(ncount);

		this->appendRow(pcollectionItem);
		m_BindUserItemMap.insert(bindUserId, pcollectionItem);

		QList<QString> temp;
		m_UserItemMapOfBlong.insert(bindUserId, temp);
	}
	else //进行数据的调整
	{
		CollectionItem *pcollectionItem = getBindUser(bindUserId);
		if (pcollectionItem)
		{
			pcollectionItem->setBindUserUnReadCount(ncount);
		}

		//然后看看子项有没有未读的
		
	}
	
}

void CollectionTreeItemModel::createCollectionConversationId( const QMap<QString, int>& conversationmap, const CollectionItem*parentItem )
{
	
		for (QString itemId: conversationmap.keys())
		{
			QString displayname = Biz::Session::getUserVcardManager()->getUserNameByConversationId(itemId);
			if(displayname.isEmpty())
			{
				displayname = itemId;
			}
// 			if (!m_UserItemMap.contains(itemId))
// 			{
// 				CollectionItem *pcollectionItem = new CollectionItem(itemId, displayname, "");
// 				pcollectionItem->setCollectionItemType(CollectionItem::CollectionBindItem);
// 
// 				QPixmap pixmap = Biz::PortraitHelper::getUserPortrait(itemId);
// 				pcollectionItem->setAvatar(pixmap.toImage());
// 
// 				pcollectionItem->setBindUserItemUnReadCount(conversationmap.value(itemId));
// 				
// 				((CollectionItem*)parentItem)->appendRow(pcollectionItem);
// 				m_UserItemMap.insert(itemId, pcollectionItem);
// 			}
// 			else
// 			{
// 				CollectionItem *pcollectionItem = getBindItem(itemId);
// 				if(pcollectionItem)
// 				{
// 					pcollectionItem->setBindUserItemUnReadCount(conversationmap.value(itemId));
// 				}
// 			}
	
			QString parentId = parentItem->data(CollectionItem::UserID).toString(); 
			if (m_UserItemMapOfBlong.contains(parentId))
			{
				QList<QString> listmap = m_UserItemMapOfBlong.value(parentId);
				if (listmap.size() >0)
				{

					if (!listmap.contains(itemId))
					{
						CollectionItem *pcollectionItem = new CollectionItem(itemId, displayname, "");
						pcollectionItem->setCollectionItemType(CollectionItem::CollectionBindItem);

						QPixmap pixmap = Biz::PortraitHelper::getUserPortrait(itemId);
						pcollectionItem->setAvatar(pixmap.toImage());

						pcollectionItem->setBindUserItemUnReadCount(conversationmap.value(itemId));

						((CollectionItem*)parentItem)->appendRow(pcollectionItem);

						QMap<QString, CollectionItem*> Itemp;
						Itemp.insert(itemId, pcollectionItem);
						m_UserItemMap.insert(itemId, pcollectionItem);
						listmap.push_back(itemId);
						m_UserItemMapOfBlong.insert(parentId, listmap);
						QList <QMap<QString, CollectionItem*>> list = m_userItemMapOfBloginItem.value(parentId);
						list.push_back(Itemp);
						m_userItemMapOfBloginItem.insert(parentId, list);
					}
					else
					{
						CollectionItem *pcollectionItem = getBindItemOfBlog(parentId, itemId);
						if(pcollectionItem)
						{
							pcollectionItem->setBindUserItemUnReadCount(conversationmap.value(itemId));
						}
					}

				}
				else
				{
					CollectionItem *pcollectionItem = new CollectionItem(itemId, displayname, "");
					pcollectionItem->setCollectionItemType(CollectionItem::CollectionBindItem);

					QPixmap pixmap = Biz::PortraitHelper::getUserPortrait(itemId);
					pcollectionItem->setAvatar(pixmap.toImage());

					pcollectionItem->setBindUserItemUnReadCount(conversationmap.value(itemId));

					((CollectionItem*)parentItem)->appendRow(pcollectionItem);

					QMap<QString, CollectionItem*> Itemp;
					Itemp.insert(itemId, pcollectionItem);
					m_UserItemMap.insert(itemId, pcollectionItem);
					listmap.push_back(itemId);
					m_UserItemMapOfBlong.insert(parentId, listmap);
					QList <QMap<QString, CollectionItem*>> list = m_userItemMapOfBloginItem.value(parentId);
					list.push_back(Itemp);
					m_userItemMapOfBloginItem.insert(parentId, list);
				}
				
			}

	}
}

CollectionItem * CollectionTreeItemModel::getBindUser( const QString&id )
{
	return m_BindUserItemMap.value(id);
}

CollectionItem * CollectionTreeItemModel::getBindItem( const QString&id )
{

	return m_UserItemMap.value(id);
}

CollectionItem * CollectionTreeItemModel::getBindItemOfBlog( const QString& parentId, const QString& id )
{
	CollectionItem * pRetitem = NULL;
	QList<QMap <QString, CollectionItem*> > list = m_userItemMapOfBloginItem.value(parentId);
	if (list.size() <= 0)
	{
		return pRetitem;
	}

	
	for (QMap<QString, CollectionItem*> onemap: list)
	{
		if (onemap.keys().contains(id))
		{
			pRetitem = onemap.value(id);
			break;
		}
	}

	return pRetitem;
}

QStringList CollectionTreeItemModel::getItemOfBlogById( const QString& strid )
{
	QStringList list;
	for (QString id: m_UserItemMapOfBlong.keys())
	{
		if (m_UserItemMapOfBlong.value(id).contains(strid))
		{
			list.push_back(id);
		}
	}

	return list;
}
