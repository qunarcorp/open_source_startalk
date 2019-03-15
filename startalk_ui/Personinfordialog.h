#ifndef PERSONINFORDIALOG_H
#define PERSONINFORDIALOG_H

#include "LocalManDialog.h"
#include "ui_PersonInforDialog.h"
#include "../QXmpp/custom/QXmppChatSelfInfoIq.h"

class PersonInforDialog : public LocalManDialog
{
	Q_OBJECT

public:
	PersonInforDialog(LocalManDialog *parent = NULL);
	~PersonInforDialog();

private slots:
	void onGetPersonInfor(const QString& iq);
	void onSavePersonInfor();
	void onSaveResultInfor(const QString& iqjson);
	void onUserVcardUpdate(const QStringList& users);

	virtual bool eventFilter( QObject *, QEvent * );

private:
	Ui::PersonInforDialog ui;
};

#endif // PERSONINFORDIALOG_H
