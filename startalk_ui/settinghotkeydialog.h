#ifndef SETTINGHOTKEYDIALOG_H
#define SETTINGHOTKEYDIALOG_H

#include <QDialog>
#include "localmanwidget.h"

namespace Ui {class SettingHotKeyDialog;};

class SettingHotKeyDialog : public LocalManWidget
{
	Q_OBJECT

public:
	SettingHotKeyDialog(QWidget *parent=0);
	~SettingHotKeyDialog();
	void SetHotKey(const QString&htkey, int ntype);
	QString GetHotKey();
public slots:
	void OnOkButton();
	void OnCancleButton();
	//bool eventFilter(QObject *obj, QEvent *event);
	
signals:
	void sgSetOkButtonInfor(const QString& strHotKey, int ntype);
protected:
	virtual void showEvent( QShowEvent * );

	virtual void keyPressEvent( QKeyEvent *event );

private:
	Ui::SettingHotKeyDialog *ui;
	QString mStrHotKey;
	QString inputHotkey;
	int ntype;
};

#endif // SETTINGHOTKEYDIALOG_H
