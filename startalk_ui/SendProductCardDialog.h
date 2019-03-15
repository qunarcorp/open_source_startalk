#ifndef SENDPRODUCTCARDDIALOG_H
#define SENDPRODUCTCARDDIALOG_H

#include <QWidget> 
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QPushButton>
#include <QHBoxLayout>
#include "LocalManDialog.h" 
#include "TitlebarWidget.h"

class SendProductCardDialog : public LocalManDialog
{
	Q_OBJECT

public:
	SendProductCardDialog(QWidget *parent);
	~SendProductCardDialog();
	QString getProductCardJson();
private:
	void initUI();
	
    QWidget *widget_bk;
    TitlebarWidget *titlebar;   
    QLabel *productTitleLabel;
    QTextEdit *productContentTextEdit; 
	QWidget *bottomBtnView;
	QHBoxLayout *hBoxLayout;
	QSpacerItem *bottomSpacerItem;
	QPushButton *pbSendBtn;
	QPushButton *pbCancelBtn;
private slots: 
	void onClickedOk();
	void onClickedCancle();
};

#endif // SENDPRODUCTCARDDIALOG_H
