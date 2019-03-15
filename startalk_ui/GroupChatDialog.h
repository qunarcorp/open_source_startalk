#ifndef GROUPCHATDIALOG_H
#define GROUPCHATDIALOG_H

#include "BaseChatDialog.h"
#include "CoreObject.h"
#include <QWidget>
#include <QPushButton>
#include <QLabel>


namespace Ui{
    class GroupChatDialog;
}

namespace Biz{
    class CallbackReceiver;
    class GeneralCallback;
    class XmppMessage;
    class ImSelfPerson;
    class GroupMemberModule;
    class MessageListData;
}




class ChatCommObject;
class WebPage;
class GroupVisitorModel;
class EmotionDialog;
class MultiDialogContainer;
class AtNoticeTip;
class QXmppMucRoomMemberIq;
class GroupVisitorSortProxyModel;
class SearchResultDialog;
class SearchAtResultDialog;
class NoticeInfoTip;
class VisitorItem;

class GroupChatDialog : public BaseChatDialog
{
    Q_OBJECT

public:
    GroupChatDialog(MultiDialogContainer* cntainer,QWidget *parent = 0);
    ~GroupChatDialog();
    void closeEvent(QCloseEvent *event);

    void initSettings();
    void initExtendBtn();
    void showAtNotice(const QString& sender,const QString& msg, const QString &msgid);
	void showAtBlock( const QString&conversationId, const QString&msgid );
	void onSendFile(const QString&filePath);

protected:
    virtual void contextMenuEvent(QContextMenuEvent *e);
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void updatePresence(const QString& userId, int status);
    virtual void onUpdateVoiceImage(const QString& messageid,const QString& img);
    virtual void showEvent(QShowEvent *);
    virtual void wheelEvent(QWheelEvent *);
    virtual void getImageSize(int& w,int& h);
    virtual void messageSendPrepare (const QSharedPointer<Biz::XmppMessage>& spMessage);
    
    virtual void preFormatMessageToHtml(QSharedPointer<Biz::XmppMessage> spMessage,bool isHistory,bool hasMore, bool& bshow);
	virtual void timerEvent( QTimerEvent * );
	virtual void afterSendCode();
	virtual void onCollectionMessageReceived(const QSharedPointer<Biz::XmppMessage>&msg) {};
	virtual void resizeEvent( QResizeEvent *event );
	virtual void onShowNotifyInfor(const QList <QSharedPointer<Biz::NoticeStrInfor>>& list , int type );
protected:
    void getMoreHistoryMsg(quint64 timestamp, int count,bool firstcall, bool breviewmore=false);
    void onHistoryAppend( const QSharedPointer<Biz::MessageListData>& messageList );
    void onHistoryMore(quint64, int height);

    void showExtendPanel(bool force);
    void hideEXtendPanel(bool force);

    void dropFileToEdit(const QString& filePath);
    void dropFileToWebArea(const QString& filePath);

    void doUpdateGroupMemberCount();


    void onSnapFinish(const QString&wid);
    void onSnapCancel(const QString& wid);

    void AddItem(QString strText);
    void SearchMoveDown();
    void SearchMoveUp();
    void SearchSelected();
    //进行拖拽文件的事件
    void dragEnterEvent(QDragEnterEvent *event);
    bool matchKey(const QStringList &grouplist, const QString&strkey);


    void doMergeMessageCache(const QSharedPointer<Biz::MessageListData>& messageList);
    void InitFontSize();
    void SetFontSize(int nsize);
    QString makeBackupInfo(const QString& body);
	//void dochangeBodyAtInofr(const QSharedPointer<Biz::XmppMessage>&list);
	
private:
    void SetChangeIcon( const QString& jid );

    void refreshFileMessage();
	void loadGroupMember();
	void setMsgMediaTypeByAt(const QSharedPointer<Biz::XmppMessage>& spMessage);
private:
    Ui::GroupChatDialog* ui;
    GroupVisitorModel* mGroupVisitorModel;
    Biz::CallbackReceiver* mReceiver;
   // SearchResultDialog* searchResultDlg;
	SearchAtResultDialog* searchAtResultDlg;

    int startPos;
    bool bWebLoaded;


    QPropertyAnimation* popanimation;

    MultiDialogContainer* pContainer;
    // 群成员相关的
    GroupVisitorSortProxyModel* mGroupVisitorSortProxyModel;
    QMenu* m_MemberMenu;
    QAction *mActionSetAdmin;
    QAction *mActionCancleAdmin;
    QAction *mActionKick;
    QAction *mActionProfile;
    QString m_SelectUserId;

    QTimeLine mGetHistoryMessageTimerout;
    QMenu *mEditMenu;
    QAction *mActionEditCopy;
    QAction *mActionEditPast;
    QAction *mActionEditSelectAll;
	bool mbhover;
	bool mbloaded;
	
	static const int sMinNameWidth;
	static const int sMinNoticeWidth;
	QString mGroupCreator;
	
signals:
    void sgCloseDlg(const QString& jid);
    void sgDestroyDlg(const QString& jid);

    public slots:
	void onRefreshGroupMember();
        void onRosterCardChangeUpdate(const QStringList& userinforlist);
        void onSetTitle(const QString& groupJid, const QString& displayName);
        void onMessageReceived(const QSharedPointer<Biz::XmppMessage>&);
        void onGroupMemberListReceived(const QString& groupBareJid,const QList<QSharedPointer<Biz::GroupMemberModule>>& members);
        void onGroupMemberAddedAff(const QString& groupJid,const Biz::GroupMemberModule& amember);
        void onGroupMemberRemoved(const QString& groupJid,const QString& fullName);
        void onRosterPortraitUpdate(const QString& jid); 
        void onShowUnreadMsgPop(const QString& nickname, const QString& message);
        void onGroupAuthFaild(const QString& jid);
        void onInputChanged();
        void onClose(bool);
        void onInviteClicked(bool);
        void onLeaveClicked(bool);
        void onYijianClicked(bool);

        bool eventFilter(QObject *obj, QEvent *event);

        void doubleClicked(const QModelIndex& index);

        void onRoomInvitePresenceReceived(const QString& jid, const QString& userid, const QString& status);
        void onRoomLeaveOfMember(const QString& jid, const QString& userid);
        void onPopMenu(const QString& resource);
        void OnReloadOfflineMsg(const QString&groupid);
        void onLoadHtmlFinish(bool b);
        void onLoadHtmlFinishByReConn(bool b);
        void onClearContents(bool bret = false);
        void onUpdateGroupHeader(const QString& groujid);

        void onGloableFontSizeChanged(int size);
        void doShowProductInfo(const QString&userid, const QSharedPointer<Biz::XmppMessage>&);
        void onpbAdvertInfo();
        void onEditCopy();
        void onEditPast();
        void onEditSelectAll();
        void onShowEditMenu(const QPoint&pt);
        void onSearchResult(const QString& text);
        void onHideUnreadMsgPop();
        void onHideUpUnreadMessageTip();
        void onShowUnreadMessageTip();
       
        
        


        void SetAdmin();
        void CancleAdmin();
        void MoveMember();
        void onMemberProfile();

        void onSetting(bool b); 
        void onItemClicked(QAction *action);
        void onUpdatePresence(const QStringList& onlineUsers);

        void onRoomNameListReceived(const QStringList& groupJids);
        void onRoomVcardChanged(const QString& groupJid);

        /*
        *	send mail 大于x人的不让发邮件
        */
        void onSendMailForbidden(bool);
        void onSendMail(bool);


        void onSelectAndSendFile(const QString& strAbsFilePath);

		virtual void paintEvent( QPaintEvent * );

		void onVidioandAudioGroupChat();
		void ongotoVideoRoom(const QString& id);
		void onReturnfirstMsgid(const QString&msgatid, const QString&msgid, const QString& conversationId);
		void onGroupFilterMsg();

		void onGroupChatMsgFilter(const QString&conversationId, const QStringList&ids);
		void onGroupChatMsgAtFilter(const QString&conversationId, const QStringList&ids);
};

#endif // GROUPCHATDIALOG_H
