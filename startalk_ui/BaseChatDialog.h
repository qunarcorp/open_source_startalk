#ifndef BASECHATDIALOG_H
#define BASECHATDIALOG_H

#include <QTimeLine>
#include "attachmentmanager.h"
#include <QWidget>
#include <QMenu>
#include <QEvent>
#include "CustomDefine.h"

class webview;
//class QWebInspector;
class TextEdit;
class QComboBox;
class EmotionTabDialog;
class IMessageBubble;
class ChatWebPage;
class ChatCommObject;
class CloseableButtonView;
class NoticeInfoTip;



namespace Biz{
    class CallbackReceiver;
    class XmppMessage;
	class NoticeStrInfor;
}

enum BubbleDirection{
    BubbleDirectionOther = 0,
    BubbleDirectionSelf = 10000
};

enum BubbleType{
    BubbleDirectionImage = 0,
    BubbleDirectionAll = 1
};

class MimeTypeMessage
{
public:
    enum MimeType
    {
        MimeTypeText = 0,
        MimeTypeIMG ,
        MimeTypeEMT ,
        MimeTypeSpite
    };
    class MimeTypeInfo
    {
    public:
        MimeType type;
        QString value1;
        QString value2;
        bool compare(const MimeTypeInfo& other)
        {
            return this->type == other.type 
                && this->value1 == other.value1
                && this->value2 == other.value2;
        };
        bool operator==(const MimeTypeInfo& other) 
        {
            return this->type == other.type 
                && this->value1 == other.value1
                && this->value2 == other.value2;
        }
    };
    bool compare( const MimeTypeMessage& other) const {
        if (this->infos.size()!=other.infos.size())
        {
            return false;
        }
        return this->infos == other.infos;
    }
    QList<MimeTypeInfo> infos;
};

class BaseChatDialog : public QWidget
{
    Q_OBJECT

public:
    BaseChatDialog(QWidget *parent);
    ~BaseChatDialog();
public:
    virtual void onMessageReceived(const QSharedPointer<Biz::XmppMessage>&) = 0;
    virtual void onUpdateVoiceImage(const QString& messageid,const QString& img) {};
    virtual void updatePresence(const QString& userId, int status) {};
    virtual void onLoadRosterDisplayname(const QString& userID, const QString& displayName); 
    virtual void getImageSize(int& w,int& h);

    virtual void showAtNotice(const QString& sender,const QString& msg, const QString &msgid);
    virtual void messageSendPrepare(const QSharedPointer<Biz::XmppMessage>& spMessage) = 0;
	virtual void showAtBlock(const QString&conversationId, const QString&msgid );
	virtual void onSendFile(const QString&filePath);

	virtual void onCollectionMessageReceived(const QSharedPointer<Biz::XmppMessage>&msg) = 0;
	virtual void onShowNotifyInfor(const QList <QSharedPointer<Biz::NoticeStrInfor>>& list,int type ){};

public:
    void loadChatHtml(webview *webview, const QString& strhtml);

    QList<QSharedPointer<Biz::XmppMessage>> transMessageBody(const QList<QSharedPointer<Biz::XmppMessage>>& msgs);

    void setCounversationId(const QString& conversationId);
    QString conversationId();

	void updatePreSendMsg(const QSharedPointer<MimeTypeMessage>& willsendmsg);
	void SetParentId(const QString& id);
	QString getParentId();
	void SetChatType(int type);
	int getChatType();
	bool getConsultIsSeatFlag(const QString& conversationId);
protected:
	
    virtual void replaceImage(const QString& id,const QString& src) {};

    virtual void onClearContents(bool bret=false){};//need reload
    virtual void keyPressEvent(QKeyEvent *event);

    // need reload
    virtual void preFormatMessageToHtml(QSharedPointer<Biz::XmppMessage> spMessage,bool isHistory,bool hasMore, bool& bShow);
    virtual void afterFormatShowMessage(QSharedPointer<Biz::XmppMessage> spMessage,bool isHistory,bool hasMore);
	virtual void afterSendCode();

	virtual void onSnapFinish(const QString&wid);
	virtual void onSnapCancel(const QString& wid);
	virtual void sendSayHelloMessage();

	virtual void loadRawHtml() {};
	virtual void loadNormalHtml(){};
	virtual void onOpenUrl(const QString& id){};
	virtual void getMoreHistoryMsg(quint64 timestamp, int count,bool firstcall, bool breviewmore=false){};
	
	virtual void sendMessageComplete(const QSharedPointer<Biz::XmppMessage>& spMessage);
	virtual void sendMessageResult(bool isSuccess);

	//输入框中的文本
	void appendWillSendMsg();
	void ShowInputWillSendMsg();
	void cleanWillSendMsg();

	//音视频聊天中发送ping
	void SendPingByVideoAndAudeo(int Mediatype);
	void setLastInforItem(const QList<QSharedPointer<Biz::XmppMessage>>& message);
protected:
	
	void sendPicutre(const QString& picFullPath);
	void sendFile(const QString& fileFullPath);
    void appendMessage(bool isHistory, bool hasMore, const QList<QSharedPointer<Biz::XmppMessage>>& message, int ntype);
    void appendMessage(bool isHistory, bool hasMore, const QSharedPointer<Biz::XmppMessage>& message, int ntype=1);

    void appendUnreadTipMessage(const QSharedPointer<Biz::XmppMessage>& spMessage);
    void appendLocalFile(const QString& filepath);
    void appendLocalPicture(const QString& picpath);
	void appendUnreadTipMessageDown(const QSharedPointer<Biz::XmppMessage>& spMessage);

    QString getLocalCopyByUrl(const QString& url);

    void updateCurrentTick(qint64 tick);
	void setScrollPos(int pos);

	bool appendRawMessage(const QSharedPointer<Biz::XmppMessage>& message);
    void appendRecentMessage(const QSharedPointer<MimeTypeMessage>& spMtMsg);

    QString getSelectImagePath();
    QString ChangeCharactor(const QString& strval);


    bool onAltS_Pressed();
    bool onCtrl_EnterPressed();
    bool onEnter_Pressed();
	bool onShift_EnterPressed();
    void cancelAnyNotice();

    void setupWebView(webview* pWebView);
    void setupTextEdit(TextEdit* pTextEdit);
	void sendVidioOrAutioMessage(int type);
	void SendGroupRoomVideoMessage(const QString&json, const QString&groupjid);

	void onOpenUrlbyPcWeb(const QString& url);
	void setTextEditStyle();
protected:
    void initWebContextMenu(webview* view);

	void dochangeBodyAtInofr(const QSharedPointer<Biz::XmppMessage>&msg);

	void showDebugView(); 
	bool bm_bIsSeat;
private:
	//QSharedPointer<QWebInspector> inspector;
    void innerPlayVoice(const QSharedPointer<Biz::XmppMessage>& spMessage);
    void innerParseClipboardData();
    QMimeData* innerParseClipboardData(const QMimeData* sourceMime);

	void ShowTipMessageOnHistory();
	
	bool isConsultChatItem(const QString& conversationId);
protected:
	//鼠标到达name控件上
	bool mbhover;
    QString strTmpCustomContextMenuMsgId;
    QString currentImageSrc;
    QString currentImageurlSrc;
    bool    m_bSelfWebCopy;
    QList<QSharedPointer<Biz::XmppMessage>> m_lstMsgCatch;
    bool m_bWebLoadFinshed;
    QString strEmotionFilePath;
    QString strDownloadFileLocal;
    TextEdit *textEdit;
    webview* mPWebView;

    QList<QSharedPointer<MimeTypeMessage>> m_recentSendMessage;

    const int MaxRecentMessageLimit;
    ChatWebPage*    mPage;
    ChatCommObject* mCommObject;
    Biz::CallbackReceiver* receiver;
	//输入的消息
	QSharedPointer<MimeTypeMessage> m_WillSendMsg;
	QString m_cctext; //接收到的消息中的值存放在此
	QString m_bu;

	//代收中的父id 和类型， 区别于普通的聊天框
	QString mparentId;
	int mChatType;
	bool mMarkdown;
	int noticeType;
	NoticeInfoTip *m_noticeInfotipGlobal;
	NoticeInfoTip *m_noticeInfotipAppoint;
private:
	QString m_sConversationID;
    QTimeLine m_voiceImagesTimer;
    QStringList m_voiceImagesLst;
    int m_voiceImageIndex;
    QString m_messageid;
    qint64 lastMsgTime;
	QMimeData* PastTextmimeData;

	bool m_codehightlight;
	QString m_codeStyle;
	QString m_codeType;
	QString mspline; 
private:
    QMenu *mWebViewMenu;
    QAction *mActionWebViewSeleAll;
    QAction *mActionWebViewCopy;
    QAction *mActionWebViewSaveAs;
    QAction *mActionWebSaveAsCustomEmoj;
    QAction *mActionWebRevoke;
    QAction *mACtionWebShareOneMessage;
	QAction *mACtionWebReferenceMessage;
protected:
    CloseableButtonView* mpUpUnread;
    CloseableButtonView* mpAtNotice;
    CloseableButtonView* m_pShareToButton;

private:
    /*QString mChatDlgJid;*/
    bool m_bWebShereMessageSelectStatus;

    public slots:
		void onCodeHightLight(bool bret, const QString& style, const QString&type);
		void onCodeStyle(const QString& style);
		void onCodeType(const QString& style);
        void onImageClicked(QString str, QString urlsrc);
        void onImageDbClicked(QString str, QString urlsrc);
        void onSpaceClicked();
        void onVoicePlay(const QString& guid);
        void onVoicePlayStart(const QString& guid,bool self);
        void onVoicePlayEnd(const QString& guid,bool self);
        void onOpenfile(const QString& msgid);
        void onOpenfilePath(const QString& msgid);
        void onSendFileByWebClick(const QString& guid);
		void onCancelSendFileByWebClick(const QString& msgid);
        void onSaveAs(const QString& msgid);
        void onSaveAsPic(const QString& localPath);
        void onSelectEmotion(const QString& wid,const QString& pkgid, const QString &shortcut);
        void onEmojUrlImageSelected(const QString& wid,const QString& pkgid, const QString &shortcut);
        void onEmojImageSelected(const QString& wid,const QString& imagepath);


        void onTextEditPaste();

        void onShowCustomContextMenu(const QString& msgid,int option);
        void onWebViewCopy();
        void onSingleImageCopy();
        void onClipBoardSelectChanged();
        void onWebClearContents();
        void onWebSelectAllPage();
        void onWebViewSaveAs();
        void onWebViewSaveCustomEmoj();
        void onWebRevokeMessage();
		void onWebViewCopyMenu();
        void onWebViewShareOnMessage();
        void onWebViewShareSelectedMessages(const QString& sharecoversationId);
		void onWebViewReferenceOnMessage();


        void onUpdateMessageSendStatus(const QSharedPointer<Biz::XmppMessage>& spMessage);
        void onResendMessage(const QString& message);

        void onCurrentConversationChange(const QString& curConversationID,const QString& lastConversationId);
        void onConversationActived(const QString& curConversationID);
        void onMainDialogVisableChange(bool visibility);

        void onBtnActionShareLocalMessage();

        void onWebJsShareLocalMessage(const QString& shareconversaionId,const QStringList& messageids);

        void onConversationReadedByOtherClient(const QString& conversationid,quint64 ulLastTimeInDb);
        void onAllConversationReadedByOtherClient(quint64 ulLastTimeInDb);

		void onConversationMessageStateChange(const QString& conversationId,QMap<QString,QPair<int,int>> msgStatus);


        void openInternalUrl(const QString& url);
		void sendRequestUrl(const QString& url);
        void onSendClick(bool);

        void onUploadFileProgress(const QString&key, qint64 done, qint64 total);
        void onUploadFileOver(const QString& key);
        void onRecvFileProgressDisplay(const QString& key, const QString&filename,qint64 done, qint64 total);
		void onUpdateReplaceImage(const QString& msgid, const QString& newfilepath);
		void onInsertTextPast();
		void onInsertImagePast();
		void onSetHistoryMsgCount(int ncount);
		void onBaseOpenUrl(const QString& id);
		void onSendMessage(const QString& body, int type, const QString&conversationId);
		void onSendMessageByType(const QString& body, int mediatype, int sourcetype,const QString&conversationId);

		void onSelfFontChange();

		void onProblemListClick(const QString& infor);
		void onProblemListMoreClick(const QString& msgId); 
		void onProblemListTakeUpClick(const QString& msgId);
		void onHintsClick(const QString& type, const QString& infor);
		void linkClicked(const QUrl &url); 

		void onLookMeetingClick(const QString& url);

		void onSendProductCard(void);

};

#endif // BASECHATDIALOG_H
