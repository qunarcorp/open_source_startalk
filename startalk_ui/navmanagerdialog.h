#ifndef NAVMANAGERDIALOG_H
#define NAVMANAGERDIALOG_H

#include "localmanwidget.h"
#include "UtilHelper.h"
#include <QListWidgetItem>

class LoginParamSettingDialog;
namespace Ui
{
	class NavManagerDialog;
}
class NavManagerDialog : public LocalManWidget
{
	Q_OBJECT
//	friend Util::SingletonTemplete<NavManagerDialog>;
public:
	enum ItemDataType
	{
		ItemDataNavUrl = Qt::UserRole + 1800,  //导航
		ItemDataTitle,                         //名称
		ItemDataField						  //域名
	};
	NavManagerDialog(QWidget *parent=NULL);
	~NavManagerDialog();
	void showNavManagerDialog();
	void InitData();

public slots:
	void onAddNav();
	void ondeleteNav();
	void onApplyNav();
	void onCloseclicked();
	void onListWidgetItemClick(QListWidgetItem *item);
	void onAdverClicked();
	void onSelectNone();
private:
	void LoadnavInfor();
	void insertOneItem(const QString&title, const QString& navurl, bool bsave=true);
	//void saveNavconfigInfor(const QString& title, const QString& navurl);
	void saveChangeNavconfigInfor(const QString&title, const QString& yu, const QString& nav);
	void ChangeValue(const QString&title, const QString& yu, const QString& nav);
	//void ChangeNav(const QString& nav, const QString& yu, const QString&nav);
protected:
	virtual bool eventFilter( QObject *, QEvent * );

private:
	Ui::NavManagerDialog *ui;
	LoginParamSettingDialog *m_pLoginParamSettingDialog;
	QString mLastTitle;
	QString mLastNav;
	QListWidgetItem *mCurrentpitem;
};
//typedef Util::SingletonTemplete<NavManagerDialog> NavManagerDialogSingleton;
#endif // NAVMANAGERDIALOG_H
