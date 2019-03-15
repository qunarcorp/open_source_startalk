#ifndef RECENTSESSIONLIST_H
#define RECENTSESSIONLIST_H

#include <QWidget>
#include "QListWidget"
#include "CoreObject.h"
#include <QListView>
#include <QAction>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>



class rosterItemModel;
class rosterItemSortFilterProxyModel;

class RecentRosterModel;
class RecentItemView;

class BaseChatDialog;
class QListWidgetItemSortable;
namespace Biz{
    class RosterItem;
    class RosterList;
    class XmppMessage;
    class CallbackReceiver;
    class ImSelfPerson;

}

class RecentSessionList : public QListWidget
{
	Q_OBJECT

public:
    RecentSessionList(QWidget *parent = 0);
    ~RecentSessionList();


protected:


private:
    virtual void resizeEvent(QResizeEvent *);

private:
   
    QPoint startPos;    // 用于计算会话拖拽
};

#endif // RECENTSESSIONLIST_H
