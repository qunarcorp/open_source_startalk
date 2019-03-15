#ifndef MultiDialogContainer_H
#define MultiDialogContainer_H
#include <QStackedWidget>
#include <QSplitterHandle>

#include "localmanwidget.h"

#include "SearchResultDialog.h"
#include "BaseChatDialog.h"
#include "loginmanager.h"
#include "LineEdit.h"
namespace Ui{
    class MultiDialogContainer;
}

namespace Biz
{
    class CallbackReceiver;
	class WebUserInfo;
	class GroupAtInfo;
    class ImSession;
    class AdvDataItem;
}

class RosterListWidget;
class ExtendedSessionListView;
class QListWidgetItemSortable;
class RecentItemView;
class NewsDialog;
class SearchUserListWidget;
class SlidingStackedWidget;

class MultiDialogContainer : public QWidget
{
    Q_OBJECT
public:
    MultiDialogContainer(QWidget *parent);
    ~MultiDialogContainer();
public:
    /*!
     * 功能 : 获取multidialog的左侧的会话窗口的stack视图句柄
     */
    QStackedWidget* getBaseChatDialogStatckWidget();
    /*!
     * 功能 : 获取二级惨淡的stack栏的句柄
     */
    QStackedWidget* getLevelStacked();
    /*!
     * 功能 :获取包括二级菜单的stack栏和搜索头部的multidialog的右侧边栏句柄
     */
    QWidget* getSessionList();

	/*!
     * 功能 :对于组合控件中获取包括二级菜单的stack栏和搜索头部的multidialog的右侧边栏句柄
     */
    QWidget* getCombinationList();

    /*!
     * 功能 : 最近联系人的stack
     */
    SlidingStackedWidget* getExtendPanelStacked();
	/*!
     * 功能 : 组合视图中的stack
     */
	SlidingStackedWidget* getCombinationExtendPanelStacked();
    /*!
     * 功能 : 设置搜索框获得焦点
     */
    void setSearchViewFocus();

	//显示代收绑定账号的信息
	void showCollectionBindUserInfo(const QString&Userid);

public:

	//显示笔记本的信息
	void showNoteInfor();

	// 显示空的绘画框框
    void showEmptyChatdialog();

	// show 聊天窗口的子窗口
	void showChatDialog(QWidget* view);

    void showWorkPlaceWidget();

	void updateUnReadPositionImage(const QString&id);

    void keyPressEvent(QKeyEvent *event);

    void onDisconnect();

    void updateConversationCountTip(int ncount);

    void closeAdvWidget();
     
    void openAdvWidget(const QList<QSharedPointer<Biz::AdvDataItem>>& imagelist);

protected:
    void initTipPopBtn();
    void onLoginSuccess();
    void onLoginFail(int nMainError, int nSubError);
    void onReconnetCount(int frame);
	void InitSubscriptionListView();
	void InitNoteInfor();
private:
	void showCustemWidget(QWidget* view);
	void showWebWidget(QWidget* view);
	void addOneNote(const QString&title, const QString&id);
private:
    void animotionUp();
    void animotionDown();

    void SearchMoveDown();
    void SearchMoveUp();
    void SearchSelected();
    void onClose(bool);

    virtual void closeEvent(QCloseEvent *);
	virtual bool eventFilter(QObject *obj, QEvent *event);

public:
    bool animationing;
	bool bReConnected;
	bool mbtnCollerofChange;
private:
    Ui::MultiDialogContainer* ui;

    QSplitterHandle* pHandler;
    QPushButton* m_pReconnectPushBtn;
    Biz::CallbackReceiver* mReceiver;

    /*!
     * 功能 : 公众账号列表
     */
    //PublicNumDialog* mRobotListDlg;
    /*!
     * 功能 : 好友消息窗口
     */
    NewsDialog* mFriendMessageDlg;
    /*!
     * 功能 : 人员搜索
     */
    SearchUserListWidget* m_pSearchUserListWidget;

    webview* m_pWorkPlaceView;


    QTimeLine* m_pLoadMessageProgressTimeer;

    QTimeLine autoReConnTimer;
    bool isAutoReConnentWhenDisconnected;
    SlidingStackedWidget* pExtendListStatcked;

	QMenu *mEditMenu;
	QAction *mActionSelectAll;
	QAction *mActionCopy;
	QAction *mActionPast;
signals:
    void sgTracertUser(const QString& userid);

    void sgReConnToServer(bool autoConn);
	void sgSendUnReadMsgId(const QString &Userid, const QStringList&msgidlist);
	void sgSendUnReadGroupMsglst(const QString&Jid, quint64 lst);
	void sgResizeMainWidget(bool bret);

    public slots:
		void onhttpRespFail();
		void onFriendsUserAttached(const QString& userid, bool btype);

		void onCloseRobotWidget(const QString& rbtid);
        void onSearchTextChanged(const QString & text);
		void onEditPast();

        void onSearchChatResult(const QString& str);
        void onSearchGroupResult(const QString& str);
        void onRobotResult(const QString& conversationId);
        void onAnimationFinish();

        void onJiagouTabShow();
        void onRecentTabShow();

        void onJiagouGroupAttached(const QString& groupName);
        void onJiagouUserAttached(const QString& userid);

        void onOpenGroupChat();
        void onOpenUserChat();

        void onReconnect(bool autoConn);
        void onNetworkAvailabeChange(bool,bool);
		void onNetworkDisabled(bool,bool);
        
		void onReLoginFail(const QString&errormsg);
        void onLoginStatusChange(Biz::LoginStatus oldstatus,Biz::LoginStatus newstatus);
		void onHDProtraitUpdate(const QString& userJid);


        void onTopMostConversationChanged(const QList<Biz::ImSession>& changedSession);
		void onNoticeTipConversationChanged(const QList<Biz::ImSession>& changedSession);

        void onLoadMessageProgress(bool end);
		void onServerPolicyViolationRelogin(int nerror);
		//记事本相关
		void onAddNote();
		void onAddSubNote();
		void onNoteBtnClicked();

		void onMoreSelectResult(const QString& id, const QString& searchKey);
		void onHistoryRecord();
};



#endif // LOCALMANDIALOG_H
