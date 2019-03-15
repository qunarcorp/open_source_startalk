#ifndef COLLECTIONTREEVIEW_H
#define COLLECTIONTREEVIEW_H

#include <QTreeView>
#include <QHeaderView>

class CollectionTreeItemModel;
class CollectionTreeItemSortProxyModel;
class CollectionItem;
namespace Biz
{
	class CollectionBindUserInfo;
	 class CallbackReceiver;
	 class RoomVcard;
}

class CollectionTreeView : public QTreeView
{
	Q_OBJECT

public:
	CollectionTreeView(QWidget *parent=0);
	~CollectionTreeView();
public:
	QString selectedUserID();
public slots:
	void onCollectionBindUserList(QList <QSharedPointer<Biz::CollectionBindUserInfo>> inforlist);
		
	void doubleClicked(const QModelIndex& index);
	void clicked(const QModelIndex& index);
	void keyPressEvent(QKeyEvent* event1);
	void showChatDialog_helper();
	void expand_helper();
	void onCollectionPortrait(const QString& id);
	void onUpdateGroupHeader(const QString& groupjid);
	void onInitRoomsVcard(QList<QSharedPointer<Biz::RoomVcard>> list);
	void OnUserVcardChange(const QStringList& userinforlist);
	void onCollectionBindUser(QList <QSharedPointer<Biz::CollectionBindUserInfo>> inforlist);
public:
	void CreateChildrenItem(const QString&parentid, const CollectionItem*parentItem);
	void initList();
private:
	CollectionTreeItemModel*  mcollectionTreeItemModel;
	CollectionTreeItemSortProxyModel* mcollectionItemSortFilterModel;
	Biz::CallbackReceiver* mReceiver;
	QMap<QString, QStringList> mCollectionItemInfo;// 代收中获取到每个绑定的id 后面有多少个聊天框item信息
	quint64 lastDbClickTick;
	QStringList mbindUserlist; //这个里面主要是存放是否有绑定的用户
};

#endif // COLLECTIONTREEVIEW_H
