#ifndef CHATTOOLBAR_H
#define CHATTOOLBAR_H

#include <QWidget>
#include "ui_chattoolbar.h"

enum DISABLEFUNCTION
{
    BTN_SHOCK       = 0x1,
    BTN_TRANS       = 0x2,
    BTN_QUICK       = 0x4,      
    BTN_HISTORYLOCAL= 0x8,
    BTN_HISTORY     = 0x10,
	BTN_RCODE       = 0x20,
    BTN_SHARE       = 0x40,
	BTN_VIDIOAUD    = 0x80,
	BTN_ROBOT       = 0x100,
	BTN_CLOSESESSION = 0x200,
	BTN_CODE		= 0x400,

	BTN_ALL_FUNCTION = 0x7ff
};

class ChatToolBar : public QWidget
{
    Q_OBJECT

public:
    ChatToolBar(QWidget *parent = 0);
    ~ChatToolBar();
    void setConversationId(const QString& conversationId);
    void emitSendFileBtn();
    void setBtnEenable(int nMask);
	int getBtnEnableMask();
	void setGroupVideoButtonNoArrow();
	void setCodeHightLight(bool bret);
	
private:
    void addFunctionBtns();
	void initCodeControl();
private:
	int  showMask;
    Ui::ChatToolBar ui;

    QMenu *mTransferChatMenu;
    QAction *mTransferNum;
    QAction *mTransferRelation;
    QAction *mTransferCollega;

    QMenu *mJietusetting;
    QAction *mHideMainwidge;
    QAction *mMakeQtalkJietu;
    QAction *mGnome_ScreenShot;

    QString mConversationId;
	QMenu *mVidioAndAudio;
	QAction *mAudioaction; //“Ù∆µ
	QAction *mVidioaction; // ”∆µ
signals:
    void sgSendFile(const QString& strAbsPath);
    void sgItemSelected(const QString& id,const QString &str);
    void sgSendShake();
    void sgShareMessage();
    void sgOpenInternalUrl(const QString& url);
	void sgSendRequestUrl(const QString& url);

	void sgAudioAction();
	void sgVidioAction();
	void sgVidioandAudioClicked();
	void sgCodeHightLight(bool bret, const QString& style, const QString&type);
	void sgCodeStyle(const QString& style);
	void sgCodeType(const QString& type);
	void sgOpenRobot();
	void sgGroupFilterMsg();

	void sgchatencrypt();
	void sgCloseSessionBtnClicked();
	void sgSendProductCard();

public slots:
    void onFontClicked(bool);
    void onEmotionClicked(bool);
    void onJietuClicked(bool);
    void onBtnJietuSetting();
    void onHideMainWidgetoggled( bool bchecked );
    void onMakeQutalkJietutoggled(bool bchecked);
    void onGnomeScreenJietutoggled(bool bchecked);


    void onShakeClicked(bool);
    void onSendFileClicked(bool);

    void onScanRcode(bool);

    void onHistoryRecord();
    void onHistoryRecordWeb();
    void onQuickReplyMsg();

    

    void onTransferNum();
    void onTransferRelation();
    void onTransferCollega();
    void onTransferChat();

	void onVidioAction(bool bcheck);
	void onAudioAction(bool bcheck);
};

#endif // CHATTOOLBAR_H
