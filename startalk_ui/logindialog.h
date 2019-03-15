#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include "LocalManDialog.h"
#include "AccountData.h"

#include "define.h"
#include "ProgressDialog.h"
#include "CallbackReceiver.h"

class LoginWidget;
class Account;
class WebLoginWidget;
class AccountListWidget;
class LoginAccountConfigInfo;
namespace Ui
{
    class LoginDialog;
}

class LoginDialog : public LocalManDialog
{
    Q_OBJECT

public:
    LoginDialog(QWidget *parent = 0);
    ~LoginDialog();
	void setLoginWidget();
    void resetLoginWidget();

    void loadLastAccountItem();
    quint64 getSaveVer() {return mSaveVersion;}
    void updateLoginInfo(const QString& errString);
    void onSuccess();
    ProgressDialog * getUpdateProgressDialog(){return dlg;};
    void setLoginTip(const QString& str,bool bWarnign);
private:
	void ShowAccountListWidget(bool bret);
	void initAccountWidget();
	void callKeyBord();
private slots:
    void onLoginSucceed();
    void onLoginFailure(int,int);
    void onDisconnect();
	void onProgressDisplay(const qint64 done, const qint64 total);
	void onUpdateLoginInfo(const QString& strmsg);
    
    void onSubmit(bool);
    void onAutoLoginStateChanged(int);
    void onRememberStateChanged(int);        
    void onLoginInfo(const QString& loginInfo);
	void onAccountItemSelected(const QSharedPointer<Biz::LoginAccountConfigInfo>& loginaccount);
	void onServerPolicyVillation(int nError, const QString& reason);
protected:
    virtual void keyPressEvent( QKeyEvent * );
    virtual bool eventFilter( QObject *, QEvent * );
	virtual void mousePressEvent( QMouseEvent * );
	//virtual void showEvent( QShowEvent * );
// 	virtual void moveEvent( QMoveEvent * );
// 
// 	virtual void mouseMoveEvent( QMouseEvent * );
signals:
    void sgLoginSuccess(const QString&);
    void sgLoginFail(const QString&);

	


	
	

private:
    Ui::LoginDialog* ui;
	ProgressDialog *dlg;
	Biz::CallbackReceiver* mReceiver;
	quint64 mSaveVer;
    quint64 mSaveVersion;
	AccountListWidget *m_pAccountListWidget;
	//QPushButton *pbtnercode;
};

#endif // LOGINDIALOG_H
