#include "CoreObject.h"
#include "dataapplication.h"
#if (defined _WINDOWS) && !(defined WIN64)
#include "cefclient/cefclient.h"

#endif // WINDOWS
#include "Framework.h"

#include <QMessageBox>
#include <QDebug>

#include "consoleoutput.h"

#ifdef _WINDOWS
#include <windows.h>
#include <tchar.h>
#endif

#ifdef _LINUX
#include <QDBusConnection>
#include <QDBusMessage>
#include "singleprogresobject.h"
#endif

#ifdef Q_OS_WIN
#include <Windows.h>
#include <winuser.h>
#endif

//===============支持高清屏幕===============================
const float DEFAULT_DPI = 96.0;
#ifdef Q_OS_WIN
float winDpiScale()
{
    HDC screen = GetDC(NULL);
    FLOAT dpiX = static_cast<FLOAT>( GetDeviceCaps( screen, LOGPIXELSX ) );
    ReleaseDC( 0, screen );

    return dpiX / DEFAULT_DPI;
}
#endif

#ifndef DPI_ENUMS_DECLARED
typedef enum PROCESS_DPI_AWARENESS
{
    PROCESS_DPI_UNAWARE = 0,
    PROCESS_SYSTEM_DPI_AWARE = 1,
    PROCESS_PER_MONITOR_DPI_AWARE = 2
} PROCESS_DPI_AWARENESS;
#endif
typedef BOOL (WINAPI * SETPROCESSDPIAWARE_T)(void);
typedef HRESULT (WINAPI * SETPROCESSDPIAWARENESS_T)(PROCESS_DPI_AWARENESS);
bool win32_SetProcessDpiAware(void) {
    bool ret = false;
#ifdef Q_OS_WIN

#ifndef DPI_ENUMS_DECLARED
    typedef enum PROCESS_DPI_AWARENESS
    {
        PROCESS_DPI_UNAWARE = 0,
        PROCESS_SYSTEM_DPI_AWARE = 1,
        PROCESS_PER_MONITOR_DPI_AWARE = 2
    } PROCESS_DPI_AWARENESS;
#endif
    typedef BOOL (WINAPI * SETPROCESSDPIAWARE_T)(void);
    typedef HRESULT (WINAPI * SETPROCESSDPIAWARENESS_T)(PROCESS_DPI_AWARENESS);

    HMODULE shcore = LoadLibraryA("Shcore.dll");
    SETPROCESSDPIAWARENESS_T SetProcessDpiAwareness = NULL;
    if (shcore) {
        SetProcessDpiAwareness = (SETPROCESSDPIAWARENESS_T) GetProcAddress(shcore, "SetProcessDpiAwareness");
    }
    HMODULE user32 = LoadLibraryA("User32.dll");
    SETPROCESSDPIAWARE_T SetProcessDPIAware = NULL;
    if (user32) {
        SetProcessDPIAware = (SETPROCESSDPIAWARE_T) GetProcAddress(user32, "SetProcessDPIAware");
    }
    qDebug()<<"SetProcessDpiAwareness---"<<*SetProcessDpiAwareness;

    if (SetProcessDpiAwareness) {
        ret = SetProcessDpiAwareness(PROCESS_PER_MONITOR_DPI_AWARE) == S_OK;
    } else if (SetProcessDPIAware) {
        ret = SetProcessDPIAware() != 0;
    }
    if (user32) {
        FreeLibrary(user32);
    }
    if (shcore) {
        FreeLibrary(shcore);
    }
#endif // Q_OS_WIN

#if QT_VERSION >= QT_VERSION_CHECK(5,6,0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#else
    //float sca =  winDpiScale();
    //sca = qRound(sca);
    // qDebug()<<"sca:"<<sca;
    //QByteArray b = QByteArray::number(sca,'f',0);
    //qputenv("QT_DEVICE_PIXEL_RATIO",b);
#endif // QT_VERSION
    return ret;
}

// 自定义消息处理程序
void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{

    QByteArray localMsg = msg.toLocal8Bit();
    QString outputString;
    switch (type) {
    case QtDebugMsg:
        outputString = QString("Debug: %1 (%2:%3, %4)")
            .arg (localMsg.constData ())
            .arg (context.file)
            .arg(context.line)
            .arg (context.function);
        break;
    case QtWarningMsg:
        outputString = QString("Warning: %1 (%2:%3, %4)")
            .arg (localMsg.constData ())
            .arg (context.file)
            .arg(context.line)
            .arg (context.function);
        fprintf(stdout, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtCriticalMsg:
        outputString = QString("Critical: %1 (%2:%3, %4)")
            .arg (localMsg.constData ())
            .arg (context.file)
            .arg(context.line)
            .arg (context.function);
        fprintf(stdout, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtFatalMsg:
        outputString = QString("Fatal: %1 (%2:%3, %4)")
            .arg (localMsg.constData ())
            .arg (context.file)
            .arg(context.line)
            .arg (context.function);
        fprintf(stdout, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
    }
    int a  = 10;
    a = 20;
}

int main(int argc, char *argv[])
{
	
#ifdef Q_OS_WIN
    //支持高清屏
    win32_SetProcessDpiAware();
#endif

#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	//QApplication::setAttribute(Qt::AA_EnableHighDpiScaling,true);
	//QCoreApplication::setAttribute(Qt::AA_UseSoftwareOpenGL);
	//QApplication::addLibraryPath("../plugins");
#else
	//QApplication::addLibraryPath("./plugins");
#endif
#ifdef _WINDOWS
     //qInstallMessageHandler(myMessageOutput);
#endif // _WINDOWS
	DataApplication a(argc, argv);
  //  cDebug() << "test11";

	//QString strtest = "{\"k\":123}";
// 	QJsonObject obj;
// 	obj.insert("k", "123456");
// 	obj.insert("v", "10000");
// 	QString strData22 = QJsonDocument(obj).toJson(QJsonDocument::Compact);
	///////////
	//QApplication::addLibraryPath("./plugins");
	///////////
	//增加多语言支持  
	QTranslator translator;
	translator.load(QString(":/Images/qt_zh_CN"));
	a.installTranslator(&translator);
	a.setAutoSipEnabled(true); // 自动弹出系统软键盘
	if( !MainApp::Framework::Initialize() ){
        return 1;
    }
    auto ret = a.exec();
    MainApp::Framework::release();

    return ret;
}
