#ifndef GROUPLISTVIEW_H
#define GROUPLISTVIEW_H

#include <QListView>
#include <QContextMenuEvent>
#include <QMenu>

#include "../QXmpp/custom/QXmppMucRoomListIq.h"
#include "diywidgit/customviews/pinnedlistview.h"

class GroupListView : public PinnedListView
{
    Q_OBJECT
public:
    GroupListView(QWidget *parent=NULL);
    ~GroupListView();
	void setGroupNoticeTip(const QString& groupjid, int noticeflag);
protected:
    virtual void contextMenuEvent (const QString& groupjid);
	
private slots:
    void onOpenSettingView(bool);
    void onLeaveGroup(bool);
    void onGroupNoticeTipChange(const QString& groupjid, int addoption, int removeoption);
	

private:
    QMenu* pContentMenu;
};

#endif // GROUPLISTVIEW_H
