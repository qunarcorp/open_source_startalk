#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include "CoreObject.h"
#include <QtGui/QBitmap>
#include <QtGui/QRegion>
#include <QtGui/QPainter>
#include "localmanwidget.h"

namespace Ui
{
	class MainDialog;
}

namespace Biz
{
	class Account;
    class UserLoginResponse;
    class LoginManager;
}

namespace ApiResponse
{
    class UserLoginItem;
}

class LoginWidget;
class MainWidget;
//class ConsoleDialog;
class MainDialog : public LocalManWidget
{
	Q_OBJECT

public:
	MainDialog(QWidget *parent = 0);
	~MainDialog();

	void showMainWidget();
    void showConsoleDialog();
    void Logout();
    void setDefaultWindow();

    void setTitle(const QString& title);
    void resizeMainwidget(bool bExtendModeShow);

private:
    void intThemeButton();
private slots:
	void onShowMainWidge();
	void onHideMainWidge();
    void onShake();
    void onShakeMove(int framevalue);
    void onShakeOver();
    void onNodifyWindowClicked(const QString& userID);
    void onSystemIconChanged(const QString& path, const QString& userID, const QString& userNickName, const QString& title);
    void onUnreadMsgChanged(int count,bool hasNoCountUnreadMsg);
protected:
    bool nativeEvent(const QByteArray & eventType, void * message, long * result);

    virtual void keyPressEvent(QKeyEvent *event);
    virtual void mouseDoubleClickEvent(QMouseEvent *);
    virtual void moveEvent(QMoveEvent *);

    virtual void resizeEvent(QResizeEvent *);
private:
	Ui::MainDialog* ui;
	MainWidget* mMainWidget;
	QTimeLine* shakeTimer;
    QPoint wndpose;
    bool bExtendModeShow;
private:
    static const int sExtendWidth;
}; 
#endif // MAINDIALOG_H
