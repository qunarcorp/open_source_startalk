#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QToolButton>
#include <QComboBox>
#include "SearchResultDialog.h"
//#include "EmotionDialog.h"
#include "EmotionTabDialog.h"
#ifdef QCHAT
#include "Quickreplymsgdialog.h"
#endif // QCHAT


#include "../3rd/hotkey/MyGlobalShortCut.h"
#include "define.h"
#ifdef _WINDOWS
#include <windows.h>
#else
#include "../3rd/hotkey/QxtGlobalShortcut/qxtglobalshortcut.h"
#endif
class ProgressDialog;

class ChatDialog;
class QXmppMucRoomListIq;
class MainDialog;
class SlidingStackedWidget;
namespace Ui{
	class MainWidget;
}

namespace Biz{
    class Account;
    class CallbackReceiver;
    class XmppMessage;
    class ImSession;
    class MessageListData;
	class GroupAtInfo;
}
namespace MainApp
{
	class CombinationController;
}
namespace ApiResponse{
    class RosterProfile;
}
class BaseChatDialog;
class GroupListView;
class PresenceChangeWidget;
class TrayIconHoverNoticeWidget;
class FriendsListView;
class MultiDialogContainer;
class CombinationListView;

class MainWidget : public QWidget
{
	Q_OBJECT

public:
	MainWidget();
	~MainWidget();
    void doLogout();

    void activeChatsBtn();
     void showAddGroup(const QString&preeid);
private:
	void initCombinationListItem();
    
    void initRecentItem();
   
    void initChattingListItem();
    void initRobotEvent();

    
	

	
    void updatePresenceNode(const QVariantMap& rosterNode);

    void autoReply(const QString& peerid);
	
    
    QStackedWidget* getLevelStacked();

	
protected:
	void showAtNotice(const QString&jid, const QSharedPointer<Biz::XmppMessage>& msg);
	void ShowWebWindowsEx(const QString&userid, const QString&display, const QString&url, const QSharedPointer<Biz::XmppMessage>& msg);

    /*!
        * 功能 : 完成消息提醒，会话排序（更新时间戳）,消息路由，更新阅读指针
    */
    void messageNotify(const QString& peerid,const QString& peername,const QSharedPointer<Biz::XmppMessage>& msg);

	void InitKeyHook();
	void setPresence(int presence);
	void onMessageReceivedInner(const QSharedPointer<Biz::XmppMessage>& msg,bool bsend);
	void onPersonCfgChange();
	void doEncryptMessage(const QSharedPointer<Biz::XmppMessage>& msg);
	void doCollectionInfor(const QSharedPointer<Biz::XmppMessage>& msg);
	virtual void keyPressEvent( QKeyEvent * );
private:
	Ui::MainWidget* ui;
	QString m_cctext; //记录接收到消息中的cctext字段
	QString m_bu;
private:
    struct TabItems{
        QAbstractButton* btn;
        QWidget* level1;
        QString  title;
    };
    Biz::CallbackReceiver* mReceiver;
    QList<TabItems*> tabItems;

    QMenu* m_settingsMenu;
	FriendsListView *friendslistview;
	
    QSharedPointer<MultiDialogContainer> mRecentChatMultiDialog;
    int mTimerId;
    int mAwayPrecentTimer;
	int mWorkSpaceTimer;
	int mawayTimesNumber;
	bool mbenablepush;
	bool mbayway;
	bool mbSendPush;
	QLabel *m_label;//设置按钮上放置一个label

    QSharedPointer<PresenceChangeWidget> mPresentWidget;

	CombinationListView *mcombinationlistview;
	QAction *mactionChatPwd;
	QAction *mactionPwdBox;

#ifdef _WINDOWS
	MyGlobalShortCut* shortcutMsg;
	MyGlobalShortCut* shortcutscreen;
	MyGlobalShortCut* shortcutsearch;
	MyGlobalShortCut* shortcutbord;
#else
	// 5.7的自带包没有 qpa的包。先注释掉吧
#if 0
	QxtGlobalShortcut* shortcutMsg;
	QxtGlobalShortcut* shortcutscreen;
	QxtGlobalShortcut* shortcutsearch;
	QxtGlobalShortcut* shortcutbord;

#endif
#endif // 
    QSet<QString> m_getOfflienList;
	QString mstrCurrentMsgOfOwerId;

	
	QMap<QString, quint64> m_getOfflinelsttm;//这个是Jid,最后一条消息的时间


signals:
    void sgMin(bool);
    void sgMax(bool);
    void sgClose(bool);
    void sgSystemIconChanged(const QString& path, const QString& userID, const QString& userNickName, const QString& title);
    void sgGroupMessageReceived(const QSharedPointer<Biz::XmppMessage>& msg);
    void sgAddOneFriend(const QString& userid, int ntype = 0);
	void sgResizeMainWidget(bool bRet);
    private slots:
	
        void onTabClicked(bool);
        
        void onMessageReceived(const QSharedPointer<Biz::XmppMessage>&);
        void onTypingMessageReceived(const QSharedPointer<Biz::XmppMessage>& msg);
        void onSystemMessageReceived( const QSharedPointer<Biz::XmppMessage>& msg );
        void onGroupMessageReceived(const QSharedPointer<Biz::XmppMessage>&);
        void onRobotReceived(const QSharedPointer<Biz::XmppMessage>& msg);
        void onWeiDaoYouMessageReceived(const QSharedPointer<Biz::XmppMessage>& msg);
        void onRevokeMessageReceived(const QSharedPointer<Biz::XmppMessage>& msg);

        void onMainMenuButtonPressed();
        void Action_Menu_addGroup();
        void onQuit(bool);
        void onPortraitClicked(bool);
        void onSelfCardUpdate(const QString& bearJid);
        void onUserPresenceChanged(int index);
        bool eventFilter(QObject *obj, QEvent *event);
        void onDisconnect();
        void timerEvent( QTimerEvent * );
        void onQuitGroup(bool);
       
        void onPresenceChanged(const QVariantList& presenceList);

        void onShowRecentWidget(const QString& jid);
        void onLoginSucceed();
		void onSearchRobot();
        void onSearchFriends();


        //void onRecentImSessionRecv(const QList<Biz::ImSession>& imSessions);
        
		//判断是不是自己的的号退群
        void onDelRegisterRecvied(const QString& groupJid, const QString& jid);
		void onWebChatMessageReceivedEx(const QSharedPointer<Biz::XmppMessage>&);

        

        void onAutoUpdateVersion(const QSharedPointer<Biz::CheckVersionUpdate>& updateInfo,const QString& localPaht);
		void OnLoginUpdate();
        protected slots:
            void onhotKeyGetMsg();
            void onhotKeyJietu();
            void onhotKeyMainBord();
            void onhotKeySearch();
            void onRegistHotKey(const QString&hotkey, int ntype);
            void onUnRegistHotKey(int ntype);

            void onSystemTrayDbClieck();
            void onReConnToServer(bool autoConn);
            void onDingdan();
            void onUnreadMsgChanged(int count,bool bHasTipOfUnreadmark);
			
			void onUnreadWorksChanged(int count);
			void onCreatePwdBox();
			void onCreateChatPwd();
			void onDeleteChatPwd();
			void onZhuxiao();
			void onCollectionSet();

	public slots:
        void onLogout(bool);
			


};

#endif // MAINWIDGET_H
