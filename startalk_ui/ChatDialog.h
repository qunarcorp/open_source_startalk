#ifndef CHATDIALOG_H
#define CHATDIALOG_H

#include "CoreObject.h"
#include <QWidget>
#include "BaseChatDialog.h"
#include "MessageListData.h"
#include "EmotionTabDialog.h"
#include <QDragEnterEvent>
#include "MultiDialogContainer.h"
#ifdef QCHAT
#include "Quickreplymsgdialog.h"
#endif
namespace Ui{
    class ChatDialog;
}

namespace Biz{
    class CallbackReceiver;
    class XmppMessage;
    class ImSelfPerson;
	class NoticeStrInfor;
}

class WebPage;
class EmotionDialog;
class CloseableButtonView;
class EncryptChatDialog;



class ChatDialog : public BaseChatDialog
{
    Q_OBJECT

public:
    ChatDialog(MultiDialogContainer* cntainer,QWidget *parent=0);
    ~ChatDialog();

    //void editFocus();
    void closeEvent(QCloseEvent *event);

    void onLoadRosterDisplayname(const QString& userID, const QString& displayName);
    void setupUiQss(QString qssfileName);
    void setNoticeInfo(const QString& notice);
    void setChannelId(const QString& channelid);
    void selectFileAndSend();


	QString getcctext() {return m_cctext;}

	QString getbu(){return m_bu;}
	void onSendFile(const QString&filePath);

public:
    MultiDialogContainer *getMultiDialogContainer(){return pContainer;};
    void showRightExtendPanel( );
    void hideRightExtendPanel();
    bool IsVisibleRightExtendPanel();
	void showProductUrl(const QString& url);
	QString getProductId();
	QString getbusinessline();
public:
    virtual void onLoadRoster(const QString& userID, const QString& displayName);
private:


    void SetfontSize(int nsize);
    void InitFontSize();
    void onGetMore(quint64, int, bool, bool breviewmore=false);



    void onTextChanged();
    void onSnapFinish(const QString&wid);
    void onSnapCancel(const QString& wid);

    //进行拖拽文件的事件
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    void showPlatInfor( const QSharedPointer<Biz::XmppMessage>& message);

	
protected:
    virtual void updatePresence(const QString& userId, int status);
    virtual void onUpdateVoiceImage(const QString& messageid,const QString& img);
    virtual void showEvent(QShowEvent *);
    virtual void getImageSize(int& w,int& h);
    virtual void messageSendPrepare(const QSharedPointer<Biz::XmppMessage>& spMessage);

    virtual void preFormatMessageToHtml(QSharedPointer<Biz::XmppMessage> spMessage,bool isHistory,bool hasMore,bool& bshow);
	virtual void afterSendCode();
	virtual void onCollectionMessageReceived(const QSharedPointer<Biz::XmppMessage>&msg) {};
	virtual void onOpenUrl( const QString& id );
	virtual void onShowNotifyInfor(const QList <QSharedPointer<Biz::NoticeStrInfor>>& list , int type );
	virtual void getHistoryByPage( int count, quint64 lasttime, Biz::UnitCallback<QSharedPointer<Biz::MessageListData>>* callback );

	virtual void showTransChatHistory(const QString& from );
	virtual void showSigleCreateMuc();
public:
    void onMessageDispatch(const QSharedPointer<Biz::XmppMessage>& spMessage);
    bool onNoteMessage(const QSharedPointer<Biz::XmppMessage>& spMessage);
    bool onProductInfo888Message(const QSharedPointer<Biz::XmppMessage>& spMessage);
    void setDisplayName(const QString& name);
protected:
    void doSetHeaderImage();
    void loadNormalHtml();
    void dropFileToEdit(const QString& filePath);
    void dropFileToWebArea(const QString& filePath);
    void doMergeMessageCache(const QSharedPointer<Biz::MessageListData>& messageList);
    /*
    * 给wechat的at用的专门的函数
    */
    QString makeBackupInfo(const QString& body);
	void setleNotice(const QString&text);

	void doGetSubKey( const QString&MainKey );
    void doCreateMainKey();
	void SetChangeIcon( const QString& jid );
	void GetUrlbyMsgid( const QString& strid );
	
protected:
    Ui::ChatDialog* ui;
    Biz::CallbackReceiver* mReceiver;
    bool m_bInhertAttribute;
    QTimeLine mGetHistoryMessageTimerout;
	virtual void resizeEvent( QResizeEvent * );
private:

    MultiDialogContainer* pContainer;

    QTimeLine mTypingFlagObtain;
    quint64 mTypingTick;


    QMenu *mEditMenu;
    QAction *mActionCopy;
    QAction *mActionPast;
    QAction *mActionSelectAll;


    QString channelId;

    bool rightPanelShowed;
    QString mMoodInfo;

    bool mbhover;
    QString mlastPlatInfo;

    QMap<QString,QString> mWechatUserInfoDic;
	
	QString mProductId;
	QString mBusinessline;
	EncryptChatDialog *m_EncryptChatdlg;
	
signals:
    void sgCloseDlg(const QString& jid);
    void sgShowDlg(const QString& jid);
    public slots:
		void onTransferReturnResult(const QString& peerid, const QString& transid, bool bret, int type);
        void onReplyWechatUser(const QString& messagid);

        void onUserOfCity(const QString& userid, const QString&city);
        void onUserMoodInforChange(const QString& userid, const QString&moodinfor);
        void onMessageReceived(const QSharedPointer<Biz::XmppMessage>&);
        void onTypingMessageReceived(const QSharedPointer<Biz::XmppMessage>&);
        void onClose(bool);
        // js script to client
        // client to js script

        // ui evet slot
        void onGloableFontSizeChanged(int size);
        void doShowProductInfo(const QString&userid, const QSharedPointer<Biz::XmppMessage>&);
        void onEditCopy();
        void onEditPast();
        void onEditSelectAll();
        void onShowEditMenu(const QPoint&pt);

        void onInputChanged();
        //void onSendClick(bool);
        void onHistoryAppend( const QSharedPointer<Biz::MessageListData>& messageList);
        void onHistoryMore(quint64, int height);

        bool eventFilter(QObject *obj, QEvent *event);
        
        void onRosterCardUpdate(const QString& jid);
        void onShowUnreadMsgPop(const QString& nickname, const QString& message);
        void onHideUnreadMsgPop();
        void onHideUpUnreadMessageTip();
        void onShowUnreadMessageTip();

        void onClearContents(bool bret=false);
        // void onSendHtmlFile(const QString& guid);

        void onUpdatePresence(const QStringList& onlineUsers);

        void onReloadSimpleOfflineMsg(const QString&userid);
        void onLoadHtmlFinish(bool b);
        void onLoadHtmlFinishByReConn(bool b);
        void onSelectResult(WId id, const QString& strSelect);


        void onChatWebUpdateStatus(const QString& userid, bool bret);
        void onTransferInfor(const QSharedPointer<Biz::XmppMessage>&);
        void onTranferFailInfor(const QString&);
        void onShowChatUserInfor();
        void doShowWelcome(const QString&userid, const QSharedPointer<Biz::XmppMessage>&);
        void onVcardUpdate(const QStringList& userinforlist);

        void onpbAdvertInfo();
        void onShowSystemNotifyInfo( const QString& strUsrId, const QString& strInfo );


        void onRightFunctionPanelVisibleChange();

        void onSelectAndSendFile(const QString& strAbsFilePath);
        void onTransChatPersenSelect(WId id,const QString &strPersonId);
        void onSendShakeMessage();
        void onSendQuickReplay(const QString& jid,const QString& message);

        virtual void paintEvent( QPaintEvent * );
		void onhttpgetapicall(const QString& url);
		void onAudioChat();
		void onVidioChat();
		void onOpenRobot();
		void onRobotSendMsg(const QString&conversation, const QString&msg);

		void onChatEncrypt();
		void onCloseEncryptChat(const QString& conversationId);
		void onCancelEncryptChat(const QString& conversationId);
		void onDecryptChat(const QString& conversationId);
		void onEncryptChat(const QString& conversationId);
		void onEncryptMsgInfo(const QString&conversationId, const QSharedPointer<Biz::XmppMessage>& msg);
		void onPopMenu(const QString&id);
		void onPortraitUpdate(const QString& jid);
		void onLocalArgeeOrRefuse(const QString& id, int tyep);

		

};

#endif // CHATDIALOG_H
