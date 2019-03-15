#ifndef PROGRESSDIALOG_H
#define PROGRESSDIALOG_H

#include "localmanwidget.h"
namespace Ui {class ProgressDialog;};

class ProgressDialog : public LocalManWidget
{
	Q_OBJECT

public:
	ProgressDialog(QWidget *parent=0);
	~ProgressDialog();
	void setRangeBar(qint64 done, qint64 total);
	void setSavePath(const QString &strSavePath);
private slots:
	void onButtonClicked();
	
signals:
	void sgclose();
private:
	Ui::ProgressDialog *ui;
	QString strmSavePath;

};

#endif // PROGRESSDIALOG_H
