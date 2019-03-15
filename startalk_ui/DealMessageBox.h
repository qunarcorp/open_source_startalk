#ifndef DEALMESSAGEBOX_H
#define DEALMESSAGEBOX_H

#include "LocalManDialog.h"
#include <QDialog>
#include "NotifyCenterController.h"
namespace Ui {class DealMessageBox;};
class DealMessageBox : public LocalManDialog
{
    Q_OBJECT
        friend class MainApp::NotifyCenterController;
private:
    DealMessageBox(QDialog *parent = 0);
    ~DealMessageBox();
public:
	//增加一个单独模式的
	static DealMessageBox*getInstanc(QDialog*parent);
    enum MessageButton{
        MessageButton_Confirm = 0x0001,
        MessageButton_Cancel = 0x0002,
    };
    void setButton(int button);
    void setDisplayText(const QString&);

    void setConfirmText(const QString& text);
    void setCancelText(const QString& text);
	void reject();
	void setmyflag(bool bret);
	
private:
	bool m_flag;

	static DealMessageBox * m_DealmsgBox;
private slots:
    void onConfirmClicked(bool);
    void onCancelClicked(bool);
	void onopenUrl(QString url);
private:
    Ui::DealMessageBox *ui;
};

#endif // DEALMESSAGEBOX_H
