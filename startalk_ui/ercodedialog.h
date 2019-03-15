#ifndef ERCODEDIALOG_H
#define ERCODEDIALOG_H

#include "localmanwidget.h"
namespace Ui {class ErCodeDialog;};
class ErCodeDialog : public LocalManWidget
{
	Q_OBJECT

public:
	static ErCodeDialog* getInstance(QWidget*parent);
	void setErCodePixmap(const QPixmap& pixmap);
private:
	static ErCodeDialog* instance;
	ErCodeDialog(QWidget *parent);
	~ErCodeDialog();
public slots:
	void onClosed();
private:
	Ui::ErCodeDialog *ui;
};

#endif // ERCODEDIALOG_H
