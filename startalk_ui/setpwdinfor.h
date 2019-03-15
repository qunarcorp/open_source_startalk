#ifndef SETPWDINFOR_H
#define SETPWDINFOR_H

#include "LocalManDialog.h"
namespace Ui { class setPwdInfor;}
#include "UtilHelper.h"

class setpwdInfor : public LocalManDialog
{
	Q_OBJECT
	//friend Util::SingletonTemplete<setpwdInfor>;
public:
	enum UpdateUserChoose
	{
		ChooseCancel,
		ChooseOK
	};
	void showPwdInfor(int type);
//private:
	setpwdInfor(QWidget *parent=NULL);
	~setpwdInfor();

	QString gettitle();
	QString getdescription();
	QString getpwd();
private:
	Ui::setPwdInfor *ui;
	QString mtitle;
	QString mdesc;
	QString mpwd;
	QString mSecpwd;
public slots:
	void onClose();
	void onBtnCancel();
	void onBtnOk();
};
//typedef Util::SingletonTemplete<setpwdInfor> setpwdInforSingleton;
#endif // SETPWDINFOR_H
