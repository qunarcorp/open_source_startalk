#ifndef ROSTERLISTVIEW_H
#define ROSTERLISTVIEW_H

#include "CoreObject.h"
#include <QListView>
#include <QAction>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>
#include "conversationlistwidget.h"



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
	class MessageUtil;
}



class RosterListWidget : public ConversationListWidget
{
    Q_OBJECT

public:
    RosterListWidget(QWidget *parent=0);
    ~RosterListWidget();

    void updateNoticeOption(const QString& jid,bool bNotice);
    void autoscrolltoTop();
protected:
    virtual void contextMenuEvent(QContextMenuEvent *);
private:
    void closeItem(const QString& converstionid);
    void onRostListDown();
    void onRostListUp();
protected:
    virtual void doCloseLastItemChat();
  
private:
    bool isItemWidgetVisable(QWidget* pwidiget);
   

private:
    QMenu* groupMenu;
    QMenu* itemMemu;

    QAction* pGroupRecvWithNotice;
    QAction* pGroupRecvWithoutNotice;

	QAction* pSignalRecvWithNotice;
	QAction* pSignalRecvWithoutNotice;


    QAction* m_pActionSetTop;
	QAction* m_pActionFriendAction;
	QAction* m_pActionStarPresonAction;
	QAction* m_pActionBlackNameAction;

    Biz::CallbackReceiver* mReceiver;
    
    QPushButton* unreadBtn;

    public slots:
		void onAddBlackName(const QString& jid, int rt);
        void profile(bool check);
        void setting(bool check);
        void quit(bool check);
        void close(bool check);
        void remove(bool check);
        void clearAllUnreadCount();
        void addMarkUserInfo();

        void onRecvWithNotice(bool);
        void onRecvWithoutNotice(bool);
        void onToggleGroupSetTop(bool);
		void onAddFriends(bool);
		void onAddBlackNameList(bool);
		void onAddStarPersonNameList(bool);

        // Biz::Account::sgRoomListNameReceived
        void onRoomListNameReceived(const QStringList& mapData);
        // Biz::Account::sgSetGroupName
        // Biz::Account::sgChatWebUpdateStatus
        void onChatWebUpdateStatus(const QString& groupjid, bool bret);
        // Biz::UserVcardManager::sgOnlineUserChanged
        void onUpdatePresence(const QStringList& onlineUserLst);
        void onRobotVcardUpdated(const QStringList& updatedList);
		void onUpdateUserVcard(const QStringList& userinforlist);
		void onUpdatePortrait(const QString& userJid);
        void onMainThemeChanged();
		//查看资料信息
		void ViewDataInfo();
		void onBlackNameListUpdate(const QStringList& blacknamelist);
};

#endif // ROSTERLISTVIEW_H
