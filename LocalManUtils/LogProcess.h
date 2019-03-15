#ifdef _WINDOWS
#pragma once
#include "CoreObject.h"
#include "DispathThread.h"
#include <QXmppLogger.h>
#include <Windows.h>

namespace Util
{
	class LogProcess : public QObject
	{	
		Q_OBJECT
	public:	
		~LogProcess(void);
		void registerWriter(LogWriter* writer);
        void setHwnd(HWND hWnd);
		static LogProcess* Instance();
		static void Release();
		static void CreateLogProcess();	
	private:
		enum LogLevel{
			DEBUG = 0,
			INFO,
			WARN,
			ERR,			
			CONSOLE,
			XMPP
		};
		LogProcess(void);	
		LogProcess(const LogProcess&);
		LogProcess& operator=(const LogProcess&);				
		void WriteLog(LogLevel type, const QString& log);		
		void WriteXmpp(LogLevel nType, int type, const QString& str);

		static LogProcess* mInst;
		LogWriter* mWriter;		
        HWND hWnd;
	public slots:
		void LogDebug(const QString&);
		void LogError(const QString&);
		void LogInfo(const QString&);
		void LogWarn(const QString&);		
		void LogConsole(QtMsgType, const QString&);
		void LogXmpp(int type, const QString& val);

	};

}
#endif
