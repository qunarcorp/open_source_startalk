#include "Framework_p.h"
#include <QtWidgets/QApplication>

#include <QSizeGrip>
#include <QDesktopWidget>

#include "constants.h"

#include "LvtuService.h"
#include "SystemIcon.h"
#include "LanguageHelper.h"
#include "logindialog.h"
#include "MainDialog.h"
#include "DealMessageBox.h"
#include "Session.h"
#include "SettingData.h"
#include "Account.h"
#include "ConfigureHelper.h"
#include "../3rd/quazip/JlCompress.h"
#include "gloableeventobject.h"
#include "Session.h"
#include "Account.h"
#include "AccountData.h"

#include "UIFrame.h"
#include "LoginController.h"


#include "loginmanager.h"
#include "accountmanager.h"

#include "SystemDefine.h"
#include "editablesettings.h"
#ifdef _WINDOWS
#include <windows.h>
#include <windowsx.h>
#include <TlHelp32.h>
#endif
namespace MainApp
{
	FrameworkPrivate::FrameworkPrivate()
        :loginDialog(NULL),menu(NULL), actionDeleCatch(NULL), actionShowWnd(NULL),actionResetWnd(NULL)
		,actionLogsFiles(NULL), actionQuit(NULL),actionLogout(NULL),actionEmaillogs(NULL),mbretSuccess(false)
    {
        //多语言环境
		QLocale locale;
		LanguageHelper::locale(Locale_zhCN);
// 		if (locale.language() == QLocale::English)
// 		{
// 			LanguageHelper::locale(Locale_enUS);
// 		}
// 		else if (locale.language() == QLocale::Chinese)
// 		{
// 			LanguageHelper::locale(Locale_zhCN);
// 		}
        
        loginDialog = NULL;
        mainDialog  = NULL;

        //Biz::LvtuService::instance();
        //Biz::HttpService::instance();

		connect(qApp, &QApplication::aboutToQuit, this, &FrameworkPrivate::onApplicationQuit);
		connect(GloableEventObject::getInstance(), &GloableEventObject::sgShowDeleteCatchMenu, this, &FrameworkPrivate::onShowDeleteCatchMenu);
        connect(Biz::Session::getLoginManager(),&Biz::LoginManager::sgLoginStatusChange,this,&FrameworkPrivate::onLoginStatusChange);
		connect(Biz::Session::getLoginManager(), &Biz::LoginManager::sgConnected, this, &FrameworkPrivate::onLoginSuccess);
	}

	FrameworkPrivate::~FrameworkPrivate()
	{
        if (NULL!=mainDialog)
        {
            delete mainDialog;
			mainDialog = NULL;
        }
	} 

	void FrameworkPrivate::onApplicationQuit()
	{
		//退出前释放所有单例对象
        //mainDialog->deleteLater();
        loginDialog = NULL;
        if (NULL!=mainDialog)
        {
            delete mainDialog;
            mainDialog = NULL;
        }

        mainDialog  = NULL;

        //Biz::LvtuService::release();
        //Biz::HttpService::release();

        LanguageHelper::release();
#ifdef _WINDOWS
        SystemIcon::instance().release();
#endif
	}

    void FrameworkPrivate::showLoginWindow()
    {
        

        loginDialog = new LoginDialog();
        mainDialog = new MainDialog();
        mainDialog->setSizeGripEnabled(true);        
        mainDialog->hide();


        loginDialog->show();
        loginDialog->activateWindow();
        MainApp::UIFrame::getLoginController()->showNormalLoginDialog();
    }

    void FrameworkPrivate::onLoginSuccess()
    {
        showMainWindow();
	
		 SystemIcon::instance().setTrayIconText(Biz::Session::getAccountManager()->accountData().LoginAccount());
		 //SystemIcon::instance().setToolTip(strUserid);
		 mbretSuccess = true;
    }

    void FrameworkPrivate::showMainWindow()
    {
        int lastx = Biz::Session::getSettingConfig()->MainDlgX();
        int lasty = Biz::Session::getSettingConfig()->MainDlgY();

		Log::e(QString("showMainWindow: lastx,y:(%1,%2)").arg(lastx).arg(lasty));

        int lastRight = lastx+mainDialog->width();
        int lastBottom = lasty+mainDialog->height();
		Log::e(QString("showMainWindow: lastRight,Bottom:(%1,%2)").arg(lastRight).arg(lastBottom));


        // 屏幕总和
        int screenwidth = QApplication::desktop()->screenGeometry().width();
        int screenheight = QApplication::desktop()->screenGeometry().height();
		Log::e(QStringLiteral("showMainWindow: 屏幕总和 screenwidth,height:(%1,%2)").arg(screenwidth).arg(screenheight));

        // 窗口位置是否在屏幕内
        if (lastx>=screenwidth || lasty >= screenheight // 直接在屏幕外了
            || (mainDialog->width()<screenwidth && lastRight > screenwidth) // 本来宽度是可以再一屏显示的，却分屏了
            || (mainDialog->height()<screenheight && lastBottom > screenheight) // 高度不分屏；
            )
        {
            // 重新计算窗口需要显示的位置，为当前窗口居中
            int nNewY = (QApplication::desktop()->screenGeometry().height()-mainDialog->height())/2;
            int nNewX =(QApplication::desktop()->screenGeometry().width()-mainDialog->width())/2;
            mainDialog->move(nNewX, nNewY);
	
			Log::e(QStringLiteral("showMainWindow: 窗口位置不在屏幕内，强制显示在屏幕内 nNewY,X:(%1,%2)").arg(nNewY).arg(nNewX));
        }
        else
        {
			
            mainDialog->move(Biz::Session::getSettingConfig()->MainDlgX(), Biz::Session::getSettingConfig()->MainDlgY());
			
			Log::e(QStringLiteral("showMainWindow: 窗口位置在屏幕内 MainDlgX,Y:(%1,%2)").arg(Biz::Session::getSettingConfig()->MainDlgX())
				.arg(Biz::Session::getSettingConfig()->MainDlgY()));
        }
        mainDialog->show();

    }

    void FrameworkPrivate::onShowWindow()
    {
        if(mainDialog != NULL && loginDialog->isHidden())
        {
            if( mainDialog->isMinimized() || !mainDialog->isVisible())
                mainDialog->showNormal();
            else
                mainDialog->activateWindow();
        }
        
        if (loginDialog->isActiveWindow())
        {
            if( loginDialog->isMinimized() )
            {
                loginDialog->showNormal();
            }
            else
            {
                loginDialog->activateWindow();
            }
            UIFrame::getLoginController()->showNormalLoginDialog();
        }        
    }
    void FrameworkPrivate::onLogout()
    {
		Log::e("FrameworkPrivate::onLogout");
        if(mainDialog != NULL)
        {
            Biz::Session::getSettingConfig()->MainDlgX(mainDialog->x());
            Biz::Session::getSettingConfig()->MainDlgY(mainDialog->y());
            Biz::Session::getSettingConfig()->MainDlgWidth(mainDialog->width());
            Biz::Session::getSettingConfig()->MainDlgHeight(mainDialog->height());
            Biz::Session::saveSettingConfig(); 
            Biz::Session::saveEditableSettings();
            mainDialog->Logout();
            Biz::Session::unregisterAccount();
            mainDialog->close();
			mbretSuccess = false;
        }
        if(loginDialog != NULL)
        {
            loginDialog->showNormal();           
            UIFrame::getLoginController()->showNormalLoginDialog();
			
        }
    }
    void FrameworkPrivate::onQuit(bool)
    {
        if( mainDialog != NULL){

            if (!MainApp::UIFrame::getNotifyCenterController ()->alertMessage("",T_("MessageBox_Quit"),QStringLiteral("取消"),QStringLiteral("确定")))
                return;

            Biz::Session::getSettingConfig()->MainDlgX(mainDialog->x());
            Biz::Session::getSettingConfig()->MainDlgY(mainDialog->y());
            Biz::Session::getSettingConfig()->MainDlgWidth(mainDialog->width());
            Biz::Session::getSettingConfig()->MainDlgHeight(mainDialog->height());

            if (NULL!=mainDialog)
            {
                delete mainDialog;
                mainDialog = NULL;
            }

            Biz::Session::saveSettingConfig();
            Biz::Session::saveEditableSettings();
        }
		mbretSuccess = false;
        Log::e("FrameworkPrivate::onQuit");
        Biz::Session::unregisterAccount(); 
		KillProcess("");
        qApp->quit();

    }
    
    void FrameworkPrivate::initSystemIcon()
    {
        //托盘及托盘菜单

		if (menu)
		{
			delete menu;
		}
		if (actionShowWnd)
		{
			delete actionShowWnd;
		}
		if (actionDeleCatch)
		{
			delete actionDeleCatch;
		}
		if (actionResetWnd)
		{
		}
		if (actionLogsFiles)
		{
			delete actionLogsFiles;
		}
		if (actionLogout)
		{
			delete actionLogout;
		}
		if (actionQuit)
		{
			delete actionQuit;
		}
		if (actionEmaillogs)
		{
			delete actionEmaillogs;
		}
		menu = new QMenu();
		actionShowWnd = new QAction(T_("TrayMenu_Item1"), menu);
		menu->addAction(actionShowWnd);
		connect(actionShowWnd, &QAction::triggered, this, &FrameworkPrivate::onShowWindow);

		actionDeleCatch = new QAction(T_("TrayMenu_Item6"), menu);
		menu->addAction(actionDeleCatch);
		connect(actionDeleCatch, &QAction::triggered, this, &FrameworkPrivate::onDeleteCatch);
		actionDeleCatch->setVisible(false);

		menu->addSeparator();

		actionResetWnd = new QAction(QStringLiteral("显示登录框")/*T_("TrayMenu_Item4")*/, menu);
		menu->addAction(actionResetWnd);
		connect(actionResetWnd, &QAction::triggered, this, &FrameworkPrivate::onShowChatDlg);

		actionLogsFiles = new QAction(T_("TrayMenu_Item5"), menu);
		menu->addAction(actionLogsFiles);
		connect(actionLogsFiles, &QAction::triggered, this, &FrameworkPrivate::onOpenlogFiles);
#ifdef _WINDOWS
		actionEmaillogs = new QAction(T_("TrayMenu_Item7"), menu);
		menu->addAction(actionEmaillogs);
		connect(actionEmaillogs, &QAction::triggered, this, &FrameworkPrivate::onEmaillogs);
#endif // _WINDOWS


		menu->addSeparator();

		actionLogout = new QAction(T_("TrayMenu_Item3"), menu);
		menu->addAction(actionLogout);
		connect(actionLogout, &QAction::triggered, this, &FrameworkPrivate::onLogout);

		actionQuit = new QAction(T_("TrayMenu_Item2"), menu);
		menu->addAction(actionQuit);
		connect(actionQuit, &QAction::triggered, this, &FrameworkPrivate::onQuit);

        SystemIcon::instance().setMenuAndTooltip(menu, T_("Application_Name"));
        SystemIcon::instance().setVisible(true);
		SystemIcon::instance().setdevicePixelRatio(qApp->devicePixelRatio());
    }

    void FrameworkPrivate::showOrHideMainWindow(int showType)
    {
        return;
        if (NULL != mainDialog)
        {
            if (showType!=0)
            {
                //mainDialog->show();
                //mainDialog->activateWindow();
				//if(!mainDialog->isVisible() || mainDialog->isMinimized())
				if(!mainDialog->isActiveWindow() || mainDialog->isMinimized())
				{
					QApplication::setActiveWindow(mainDialog);
					mainDialog->showNormal();
				}
				else 
				{
					mainDialog->hide();
				}
				
            }
            else 
            {
                //mainDialog->hide();
				if (mainDialog->isMinimized())
				{
					//mainDialog->show();
					QApplication::setActiveWindow(mainDialog);
					mainDialog->showNormal();
				}
				else if (!mainDialog->isActiveWindow())//if (mainDialog->isVisible())
				{
					//mainDialog->hide();
					if (!mainDialog->isHidden())
					{
						QApplication::setActiveWindow(mainDialog);
						mainDialog->showNormal();
						mainDialog->show();
					}
				}
				
            }
        }
    }

	void FrameworkPrivate::onShowChatDlg()
	{
		showMainWindowReset();
	}

	void FrameworkPrivate::showMainWindowReset()
	{
		QDesktopWidget *desktop = QApplication::desktop();
		int nMainScreen = desktop->primaryScreen();//主屏的索引

		int ncountScreen = desktop->screenCount();

		QRect  rectscreen = desktop->screenGeometry(nMainScreen);
		int width = desktop->width();
		int height = desktop->height();

		Log::e(QStringLiteral("showMainWindowReset: 主屏索引=%1 屏幕个数=%2 主屏的Rect=(w=%3,h=%4)").arg(nMainScreen).arg(ncountScreen).arg(rectscreen.width()).arg(rectscreen.height()));


		if (Biz::Session::currentAccount().accountData().UserID().isEmpty())
		{
			
			QRect rect = loginDialog->geometry();
			Log::e(QString("showMainWindowReset: loginDialog begin x,y:(%1,%2)").arg(rect.left()).arg(rect.top()));

			// 屏幕总和
			int screenwidth = rectscreen.width();
			int screenheight = rectscreen.height();

			// 重新计算窗口需要显示的位置，为当前窗口居中
			int nNewY = (screenheight-loginDialog->height())/2;
			int nNewX = (screenwidth-loginDialog->width())/2;
			loginDialog->move(nNewX, nNewY);
            loginDialog->showNormal();

            loginDialog->activateWindow();
            UIFrame::getLoginController()->showNormalLoginDialog();

		}
		else
		{
			

			int lastx = Biz::Session::getSettingConfig()->MainDlgX();
			int lasty = Biz::Session::getSettingConfig()->MainDlgY();

			Log::e(QString("showMainWindowReset: lastx,y:(%1,%2)").arg(lastx).arg(lasty));

			int nMainDlgWidth = mainDialog->width();
			int nMainDlgHeight = mainDialog->height();
			Log::e(QString("showMainWindowReset: nMainDlgWidth,Height:(%1,%2)").arg(nMainDlgWidth).arg(nMainDlgHeight));

			int lastRight = lastx+mainDialog->width();
			int lastBottom = lasty+mainDialog->height();
			Log::e(QString("showMainWindowReset: lastRight,Bottom:(%1,%2)").arg(lastRight).arg(lastBottom));


			// 屏幕总和
			int screenwidth = rectscreen.width();
			int screenheight = rectscreen.height();
			Log::e(QStringLiteral("showMainWindowReset: 主屏幕宽和高 screenwidth,height:(%1,%2)").arg(screenwidth).arg(screenheight));


			// 重新计算窗口需要显示的位置，为当前窗口居中
			int nNewY = (screenheight-mainDialog->height())/2;
			int nNewX =(screenwidth-mainDialog->width())/2;
			mainDialog->move(nNewX, nNewY);
			Log::e(QStringLiteral("showMainWindowReset: mainDialog 窗口位置不在屏幕内，强制显示在屏幕内 nNewY,X:(%1,%2)").arg(nNewY).arg(nNewX));
			mainDialog->setGeometry(nNewX, nNewY, nMainDlgWidth, nMainDlgHeight);
			mainDialog->showMainWidget();
			mainDialog->showNormal();
            mainDialog->activateWindow();
		}
	}

	void FrameworkPrivate::onOpenlogFiles()
	{
		QString logfolder = Biz::ConfigureHelper::getLogsDir()+"/";
		logfolder = logfolder.replace("//","/");

		QString strUserid = Biz::Session::currentAccount().accountData().UserID();
		if (!strUserid.isEmpty())
		{
			QString strdbPath = Biz::ConfigureHelper::user_DatabasePath(strUserid);
			//判断logs文件夹里是否有localman.db
			//如果没有，进行copy过来，如果存在，删除存在的，然后再进行copy
			QString logfiledbpath = logfolder;
            logfiledbpath += (!Util::ENV_OPTION || Biz::Session::getEditableSettings()->BetaEnvEnable())?Constant::DATABASENAME_BETA:Constant::DATABASENAME;
            QFile::remove(logfiledbpath);
            QFile::copy(strdbPath, logfiledbpath);
		}
		

		QString localPath = logfolder;
#ifdef _WINDOWS
		//进行压缩成zip的包
		QString strDesk = Biz::ConfigureHelper::getDeskWindowPath() + "log.zip";
		strDesk = strDesk.replace("//","/");
		if (QFile::exists(strDesk))
		{
			QFile::remove(strDesk);
		}

		bool bRet = JlCompress::compressDir(strDesk, logfolder);
		if (bRet)
		{
			strDesk.replace("/","\\");//将地址中的"/"替换为"\"，因为在Windows下使用的是"\"。
			QProcess::startDetached("explorer /select," + strDesk);
		}
		
#else
		localPath.replace("\\", "/");
		QProcess::execute("nautilus " +  localPath + "\"");
#endif
	}

	void FrameworkPrivate::onDeleteCatch()
	{
		Log::e(QStringLiteral("FrameworkPrivate::onDeleteCatch 清理缓存"));

		Biz::Session::currentAccount().DeleteCatch();
	}

	void FrameworkPrivate::onShowDeleteCatchMenu()
	{
#ifdef _WINDOWS
        actionResetWnd->setText(T_("TrayMenu_Item4"));
        actionDeleCatch->setVisible(true);
#endif // _WINDOWS
	}

    void FrameworkPrivate::onLoginStatusChange(Biz::LoginStatus oldstatus,Biz::LoginStatus newstatus)
    {
        if (newstatus == Biz::LoginStatus_Connect)
        {
            QString currUser = Biz::Session::getAccountManager()->accountData().UserID();
            showMainWindow();
        }
    }

	//强制杀死该进程
	void FrameworkPrivate::KillProcess( QString ProcessName )
	{
#ifdef _WINDOWS

// 		bool result = false;
// 		QString str1;
// 		HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0) ; 
// 		PROCESSENTRY32 pInfo; 
// 		pInfo.dwSize = sizeof(pInfo);
// 		Process32First(hSnapShot, &pInfo);
// 		do 
// 		{
// 			str1 = QString::fromUtf16(reinterpret_cast<const unsigned short*>(pInfo.szExeFile));
// 			if (str1 == ProcessName) 
// 			{
// 				result = true;
// 				QString cmd;
// 				cmd = QString("taskkill /F /PID %1 /T").arg(pInfo.th32ProcessID);  
// 				system(cmd.toLatin1().data());
// 			} 
// 		} while(Process32Next(hSnapShot, &pInfo) ); 
// 		return result;

		QString cmd;
		cmd = QString("taskkill /F /PID %1 /T").arg(qApp->applicationPid());
		//system(cmd.toLatin1().data());
		QProcess::execute(cmd.toLatin1().data());
#else
		QString cmd;
		cmd = QString("kill %1 ").arg(qApp->applicationPid());
		QProcess::execute(cmd.toLatin1().data());
#endif // _WINDOWS

		
	}


	void FrameworkPrivate::onEmaillogs()
	{
		
		//判断一下，看看，是否登录成功， 如果登录成功
		//发送文件到文件服务器上
		if (mbretSuccess)
		{
			Biz::Session::getAccountManager()->collectLogsToSendEmail(NULL);
		}
		else
		{
			Biz::Session::getAccountManager()->collectLogsToSendEmailBeforLogin(NULL);
		}
		
	}

}
