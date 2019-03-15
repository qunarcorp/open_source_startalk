#ifndef MENUROBOTDIALOG_H
#define MENUROBOTDIALOG_H

#include <QWidget>
#include "ui_MenuRobotDialog.h"
#include "CoreObject.h"
#include "BaseChatDialog.h"
#include "ChatDialog.h"
#include "MessageListData.h"
//#include "EmotionDialog.h"
#include "EmotionTabDialog.h"
#include <QDragEnterEvent>
#include "MultiDialogContainer.h"
#ifdef QCHAT
#include "Quickreplymsgdialog.h"
#endif
namespace Ui{
    class MenuRobotDialog;
}

namespace Biz{
    class CallbackReceiver;
    class XmppMessage;
}

class ChatCommObject;
class EmotionDialog;

const int MAXCOUNT=20;
class MenuRobotDialog : public ChatDialog
{
    Q_OBJECT

public:
    MenuRobotDialog(MultiDialogContainer* cntainer,QWidget *parent=0);
    ~MenuRobotDialog();

public:
    void setInputAreaVisable(bool b);
    void setMenuAreaVisable(bool b);
//     void closeEvent(QCloseEvent *event);
//     void onLoadRosterDisplayname(const QString& userID, const QString& displayName);
//    void setupUiQss(QString qssfileName);

	void getRobotInfo();
    void setRobotDealBlock(int timeout,const QString& dealKey);
	void onLoadRoster(const QString& userID, const QString& displayName);
//    void setDisplayName(const QString& displayName);
	
protected:
    void parseRobotWeChatNotice(const QSharedPointer<Biz::XmppMessage>&,bool);
	void onOpenUrl(const QString &url);
	void messageSendPrepare(const QSharedPointer<Biz::XmppMessage>& spMessage);
private:
    void doShowQueryMsg(const QStringList& msgtype);
//     void doSetHeaderImage();
     void onGetMore(quint64, int, bool);

//    bool appendRawMessage(const QSharedPointer<Biz::XmppMessage>& message);
//    void onTextChanged();
//    void onSnapFinish(const QString&wid);
//    void onSnapCancel(const QString& wid);

//     void dragEnterEvent(QDragEnterEvent *event);
//     void dropEvent(QDropEvent *event);

//    void doMergeMessageCache(const QSharedPointer<Biz::MessageListData>& messageList);
//    void sendSayHelloMessage();
private:
     void loadRawHtml();
//     void loadNormalHtml();
private:
    void createRobotMenu();
    void createrobotSubMenu();
    void InitMsgTypeMenu();

protected:
//     virtual void replaceImage(const QString& id,const QString& src);
//     virtual void updatePresence(const QString& userId, int status);
//     virtual void onUpdateVoiceImage(const QString& messageid,const QString& img);
//     virtual void showEvent(QShowEvent *);
//     virtual void getImageSize(int& w,int& h);
//     virtual void resizeEvent(QResizeEvent * e);
//     virtual void sendMessage();
// 
//     virtual void sendPicutre(const QString& picFullPath);
//     virtual void sendFile(const QString& fileFullPath);
// 
    virtual void preFormatMessageToHtml(QSharedPointer<Biz::XmppMessage> spMessage,bool isHistory,bool hasMore,bool& toBeShow /*default 1*/);
    virtual void afterFormatShowMessage(QSharedPointer<Biz::XmppMessage> spMessage,bool isHistory,bool hasMore);
protected:
//    void dropFileToEdit(const QString& filePath);
//    void dropFileToWebArea(const QString& filePath);
    
    void GetUrlbyMsgid(const QString& strid);
    void SetChecked(const QString& strid, const QString& leftPromot,const QString& rightPromot);
    void  doGetSystemMsgTableCount();
	
	void doSetHeaderImage();
private:
//     Ui::MenuRobotDialog ui;
//     QString mPeerUserID;
//     Biz::CallbackReceiver* mReceiver;
//     QPushButton* poptip;
//     QPropertyAnimation* popanimation;
//     MultiDialogContainer* pContainer;

//     QTimeLine mGetHistoryMessageTimerout;
//     QTimeLine mTypingFlagObtain;
//     quint64 mTypingTick;
// 
//     QMenu *mEditMenu;
//     QAction *mActionCopy;
//     QAction *mActionPast;
//     QAction *mActionSelectAll;
// 
     QSharedPointer<Biz::RobotVcard> mspRobotInfo;

    //菜单进行选择
    QMenu *mMsgFilterMenu;
	QList<QPushButton*>* pBtnList;

//    int mCountSystemMsgRecord;
signals:
//    void sgCloseDlg(const QString& jid);
//    void sgShowDlg(const QString& jid);
//    void sgShowAddGroup(const QString& jid);
    public slots:
//        void onLoadRoster(const QString& userID, const QString& displayName);
        void onMessageReceived(const QSharedPointer<Biz::XmppMessage>&);
		void onCollectionMessageReceived( const QSharedPointer<Biz::XmppMessage>& msg );
//        void onClose(bool);

//        void onSendFileClicked(bool);
        void onUpdateRawHtmlElementStatus(const QString& vcardId,const QString& message);
		  void onConverStationMenuRobotType(const QString& conversationId);
         private slots:
        void onMsgTypeChanged();
        void onBtnMsgFilter();
//        void onEditCopy();
//        void onEditPast();
//        void onEditSelectAll();
//        void onShowEditMenu(const QPoint&pt);
//        void onSigleCreateMuc(bool);
//        void onInputChanged();
//        void onHistoryAppend( const QSharedPointer<Biz::MessageListData>& messageList);
//        void onHistoryMore(quint64);
//        void onOpenUrl(const QString &url);

//        bool eventFilter(QObject *obj, QEvent *event);
//        void onCancelSend();
//        void onRosterCardUpdate(const QString& jid);
//        void onShowUnreadMsgPop(const QString& nickname, const QString& message);
//        void onHideUnreadMsgPop();
//        void onPopTipClicked(bool checked);

//        void onClearContents();

//        void onHistoryRecord();
//        void onReloadSimpleOfflineMsg(const QString&userid);
//        void onLoadHtmlFinish(bool b);
//        void onLoadHtmlFinishByReConn(bool b);
//        void onSelectResult(const QString& strSelect);

//        void onVcardUpdateNotify(const QStringList& rbtids);

//        void onSelectAndSendFile(const QString& strAbsFilePath);
//        void onSendShakeMessage();



};

#endif // MENUROBOTDIALOG_H
