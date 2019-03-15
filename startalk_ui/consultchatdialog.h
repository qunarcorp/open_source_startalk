#ifndef CONSULTCHATDIALOG_H
#define CONSULTCHATDIALOG_H

#include "CoreObject.h"
#include <QWidget>
#include "ChatDialog.h"

class ConsultChatDialog : public ChatDialog
{
	Q_OBJECT

public:
	ConsultChatDialog(MultiDialogContainer* cntainer,QWidget *parent=0);
	~ConsultChatDialog();

	QString getChatId();;

	virtual void onLoadRoster(const QString& userID, const QString& displayName); 
	void setVirtualJid(const QString& virtualid) { mVirtualId = virtualid;}
	void setRealJid(const QString& realjid) {mRealConversation = realjid;}
	void setIsSeat(bool b){ bm_bIsSeat = m_bIsSeat = b;}
	void resetUI(void);
protected:
	virtual void showTransChatHistory(const QString& from );
	virtual void preFormatMessageToHtml(QSharedPointer<Biz::XmppMessage> spMessage,bool isHistory,bool hasMore,bool& bshow);
	virtual void messageSendPrepare(const QSharedPointer<Biz::XmppMessage>& spMessage);
	virtual void showSigleCreateMuc();
private:
	void SendMsgByrealName(const QString&realname, QSharedPointer<Biz::XmppMessage>& message);
	void getRealName(QSharedPointer<Biz::XmppMessage>& message);

private:
	bool m_bIsSeat;
	QString mVirtualId;
	QString mRealConversation;

	public slots:
		void onRealConversationJidChange(const QString& virturalid,const QString& realJid);
		void onCloseRemoteSession();
};

#endif // CONSULTCHATDIALOG_H
