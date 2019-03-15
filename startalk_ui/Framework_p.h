#ifndef FRAMEWORKPRIVATE_H
#define FRAMEWORKPRIVATE_H

#include "CoreObject.h"
#include <QMenu>

#include "loginmanager.h"

namespace Util
{
    class AsyncCallback;
}

namespace Biz
{
    class LoginManager;
}

class LoginDialog;
class MainDialog;
namespace MainApp
{
    class LvtuService;
	class FrameworkPrivate : public QObject
	{
		Q_OBJECT

        friend class Framework;
    public:

		FrameworkPrivate();
		~FrameworkPrivate();

        void onShowWindow();
        void onLogout();
        void onQuit(bool);
        void initSystemIcon();	
		void initialize();
	private:
		void KillProcess(QString ProcessName);
	public slots:
		void onDeleteCatch();
		void onShowChatDlg();
        void showMainWindow();
        void showLoginWindow();
		void onApplicationQuit();
        void onLoginSuccess();
        void showOrHideMainWindow(int showType);
		void onOpenlogFiles();
		void onShowDeleteCatchMenu();
        void onLoginStatusChange(Biz::LoginStatus oldstatus,Biz::LoginStatus newstatus);
		void onEmaillogs();
    private:
		void showMainWindowReset();
        LoginDialog* loginDialog;
        MainDialog*  mainDialog;
		QMenu *menu;
		QAction *actionShowWnd;
		QAction *actionDeleCatch;
		QAction *actionResetWnd;
		QAction *actionLogsFiles;
		QAction *actionLogout;
		QAction *actionQuit;
		QAction *actionEmaillogs;
		bool mbretSuccess;
	}; 
}

#endif // FRAMEWORKPRIVATE_H
