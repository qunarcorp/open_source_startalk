#include "Framework.h"
#include <QtWidgets/QApplication>
#include <QtNetwork>
#include <QDesktopWidget>
#include <QSharedMemory>

#ifdef _LINUX
#include <QDBusConnection>
#endif

#include "mdump.h"
#include "Framework_p.h"
#include "LanguageHelper.h"
#include "MainDialog.h"
#include "UiHelper.h"
#include "LvtuService.h"
#include "../LocalManUtils/Log.h"
#include "../LocalManUtils/SystemDefine.h"
#include "../LocalManBiz/AccountData.h"
#include "../LocalManBiz/Session.h"
#include "../LocalManBiz/Roster.h"
#include "RosterListWidget.h"
#include "../LocalManBiz/ConfigureHelper.h"
#include <QFontDatabase>
#include "../LocalManUtils/UtilHelper.h"
#include "NotifyWindow.h"
#include "../LocalManUtils/LogProcess.h"

#include "SystemIcon.h"
#include "LogWriter.h"
#include "SettingData.h"
#ifdef _WINDOWS
#include "DumpHandle.h"
#endif

#include "SystemConfigData.h"
#include "editablesettings.h"

namespace MainApp
{
    static FrameworkPrivate* mFrameworkPrivate;
    QSharedMemory Framework::smInstance;
    qint64 Framework::appStartTick;

#ifdef _WINDOWS
    HANDLE Framework::hMutex = NULL;
#endif


    Framework::Framework()
    {
    }

    Framework::~Framework()
    {

    }


    bool Framework::Initialize()
    {

        appStartTick = QDateTime::currentMSecsSinceEpoch();

       

        ////////////////////////////////////////////////////////////////////////
		
		Biz::Session::loadEditableSettings();
		Biz::Session::loadLoginAccountConfigInfo();
       
        Biz::Session::loadSystemConfig();
        Biz::Session::loadLoginNavSetting();

        Biz::ConfigureHelper::parseLoginNavInfo(Biz::Session::getLoginNavSetting()->NavData());

		Biz::ConfigureHelper::parseLoginSecondNavInfo(Biz::Session::getLoginNavSetting()->SecondNavData());

        Biz::Session::loadSettingConfig(QApplication::desktop()->screenGeometry().width(), 
            QApplication::desktop()->screenGeometry().height());

		Biz::Session::loadNavConfigListInfo();

        ///////////////////////////////////////////////////////////////////////
        //先初始化LOG
        Log::init(qApp->applicationPid(),Biz::ConfigureHelper::getLogsDir());



        mFrameworkPrivate = new FrameworkPrivate();

        //最后一个窗口关闭时不退出进程
#ifdef _WINDOWS
        qApp->setQuitOnLastWindowClosed(false);
#endif // DEBUG

        //

        //设备的唯一值

        if (!QSslSocket::supportsSsl())
        {
            Q_ASSERT(false);
        }
        else
        {
            QSslConfiguration config = QSslConfiguration::defaultConfiguration();
			config.setPeerVerifyMode(QSslSocket::VerifyNone);
			//config.setProtocol(QSsl::TlsV1_1);
            QSslConfiguration::setDefaultConfiguration(config);
        }
        qApp->setOrganizationName(Util::ORGANIZATION_NAME);
        qApp->setApplicationName(Util::APPLICATION_NAME);




#ifdef _WINDOWS
        qInstallMessageHandler(Util::Log::console);

        Util::DumpHandle::Init(Biz::ConfigureHelper::getLogsDir());

#endif
        //注册跨线程对象
        registerMetaTypes();

        //更换主题
        MainApp::changeTheme(Biz::Session::getSettingConfig()->themeName());


        //init systray
#ifdef _WINDOWS
        mFrameworkPrivate->initSystemIcon();
#endif



        LogWriter* pLogWriter = new LogWriter();
        Log::registerWriter(pLogWriter);
#ifdef _WINDOWS
        LogProcess::Instance()->registerWriter(pLogWriter);
#endif

        //请求决定逻辑，自动登录还是显示登录窗口
        mFrameworkPrivate->showLoginWindow();
        return true;
    }

    void Framework::release()
    {
        delete mFrameworkPrivate;
        mFrameworkPrivate = NULL;

        //最后释放LOG
        Log::release();
#ifdef _WINDOWS
        LogProcess::Release();
#endif
    }
    void Framework::onLogout()
    {
         if(mFrameworkPrivate)
            mFrameworkPrivate->onLogout();
    }

    void Framework::onQuit()
    {
        if(mFrameworkPrivate)
            mFrameworkPrivate->onQuit(false);
    }

    qint64 Framework::startTick()
    {
        return appStartTick;
    }

    void Framework::showOrHideMainWindow(int showType)
    {
        if(mFrameworkPrivate)
            mFrameworkPrivate->showOrHideMainWindow(showType);
    }

    void Framework::collectLogs()
    {
        if(mFrameworkPrivate)
            mFrameworkPrivate->onOpenlogFiles();
    }

    void Framework::clearCaches()
    {
        if(mFrameworkPrivate)
            mFrameworkPrivate->onDeleteCatch();
    }

    bool Framework::anyProgressHere()
    {

        return false;
    }
}
