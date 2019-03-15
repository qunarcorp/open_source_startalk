#ifndef ADDNAVDIALOG_H
#define ADDNAVDIALOG_H

#include <QWidget>
#include "LocalManDialog.h"
#include "UtilHelper.h"

namespace Ui
{
	class AddNavDialog;
}

class AddNavDialog : public LocalManDialog
{
	Q_OBJECT
	friend Util::SingletonTemplete<AddNavDialog>;
public:
	void showAddNavDialog();
	QString getCompanyUrl();
private:
	AddNavDialog(QWidget *parent=NULL);
	~AddNavDialog();

public slots:
	void onCloseclicked();
	void onButtonOk();
private:
	Ui::AddNavDialog *ui;
	QString m_InputCompNav;
};

typedef Util::SingletonTemplete<AddNavDialog> AddNavDialogSingleton;
#endif // ADDNAVDIALOG_H
