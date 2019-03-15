#ifndef PERSONINFOR_EMPLOYDIALOG_H
#define PERSONINFOR_EMPLOYDIALOG_H


#include "LocalManDialog.h"
#include "ui_PersonInfor_EmployDialog.h"

class Personinfor_employDialog : public LocalManDialog
{
	Q_OBJECT

public:
	Personinfor_employDialog(LocalManDialog *parent=NULL);
	~Personinfor_employDialog();

private:
	Ui::PersonInfor_employDialog ui;
	void onGetPersonInfor();

	virtual bool eventFilter( QObject *, QEvent * );
	private slots:
		void onButtonOk();
		void onUserVcardUpdate(const QStringList& users);
};
#endif // PERSONINFOR_EMPLOYDIALOG_H
