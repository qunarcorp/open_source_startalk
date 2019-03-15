#ifndef ROSTERTREEVIEW_H
#define ROSTERTREEVIEW_H

#include <QTreeView>
#include <QXmppPresence.h>
#include <QHeaderView>
#include <QAction>
#include <QList>
#include "RosterList.h"

namespace Biz{
    class XmppMessage;
    class CallbackReceiver;
}
class RosterTreeItemModel;
class RosterTreeItemSortProxyModel;
class RosterTreeView : public QTreeView
{
    Q_OBJECT

public:
    RosterTreeView(QWidget *parent = 0);
    ~RosterTreeView();
    QString getDisplayName(const QString& peerId);
    void searchContact(const QString& key, QStringList& resultList);
    void openChatDialog(const QString& peerId);
	RosterTreeItemModel*getRosterTreeItemModel() {return mRosterTreeItemModel;};
public slots:
    void onRosterListChanged(const QVariantList& roaster);
    void onTraceItem(const QString& userid);
	void oncleanData();
	
private:
    Biz::CallbackReceiver* mReceiver;
    RosterTreeItemModel*  mRosterTreeItemModel;
    RosterTreeItemSortProxyModel* mRosterItemSortFilterModel;
    QAction mChat;
    quint64 lastDbClickTick;

    QMenu* mMenu;
	QAction *pAddFriend;
private slots:
    //void mousePressed(const QModelIndex& index);
    void doubleClicked(const QModelIndex& index);
    void clicked(const QModelIndex& index);
    void keyPressEvent(QKeyEvent* event1);
    void showChatDialog_helper();
    void expand_helper();
    void slotCustomContextMenu(const QPoint &pos);

    QString selectedUserID();
	
signals:
    void sgChatDialog(const QString& userID, const QString& displayName);
    void sgGroupAttached(const QString& groupname);
    void sgUserAttached(const QString& userid);
};

#endif // ROSTERTREEVIEW_H
