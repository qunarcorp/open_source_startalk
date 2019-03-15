#ifndef ENCRYPTCHATDIALOG_H
#define ENCRYPTCHATDIALOG_H

#include "LocalManDialog.h"

namespace Ui
{
	class EncryptChatDialog;
}

class EncryptChatDialog : public LocalManDialog
{
	Q_OBJECT

public:
	EncryptChatDialog(QWidget *parent=NULL);
	~EncryptChatDialog();
	void setConversationId(const QString&conversationId);
	void setEncryptButtonType(bool btype);


public slots:
	void onCloseDialog();
	void onpbtCancel();
	void onpbtDecrypt();
	void onpbtEncrypt();
	void onEncryptChatResponeInfor(int type, const QString& conversationId, const QString&infor);
	void onTimeoutFinished();
private:
	Ui::EncryptChatDialog *ui;
	QString mConversationId;
	bool mbencrypt;
	QTimer *mWaiteTime;
};

#endif // ENCRYPTCHATDIALOG_H
