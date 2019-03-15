#ifndef COLLECTIONTREEITEMMODEL_H
#define COLLECTIONTREEITEMMODEL_H

#include <QStandardItemModel>
#include "collectionitem.h"
namespace Biz
{
	class CollectionBindUserInfo;
}

class CollectionTreeItemModel : public QStandardItemModel
{
	Q_OBJECT

public:
	CollectionTreeItemModel(QObject *parent);
	~CollectionTreeItemModel();
	void initCollectionBindItem(const QList <QSharedPointer<Biz::CollectionBindUserInfo>>& inforlist);
	void createCollectionBindUser(const QString& bindUserId, int ncount);
	void createCollectionConversationId(const QMap<QString, int>& conversationmap, const CollectionItem*parentItem);
	CollectionItem *getBindUser(const QString&id);
	CollectionItem *getBindItem(const QString&id);
	CollectionItem *getBindItemOfBlog(const QString& parentId, const QString& id);
	QStringList getItemOfBlogById(const QString& id);
private:
	QMap<QString, CollectionItem*> m_UserItemMap;
	QMap<QString, CollectionItem*> m_BindUserItemMap;
	QMap<QString, QList<QString>> m_UserItemMapOfBlong;
	QMap<QString, QList<QMap<QString, CollectionItem*>>> m_userItemMapOfBloginItem;
};

#endif // COLLECTIONTREEITEMMODEL_H
