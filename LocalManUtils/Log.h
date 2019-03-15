#pragma once
#include "CoreObject.h"
#include <QXmppLogger.h>

namespace Util
{
    class LogWriter;
	class Log
	{
	public:
		static void init(int pid,const QString& path);
		//最后再释放日志
		static void release();

		enum LogLevel{
			DEBUG = 0,
			INFO,
			WARN,
			ERR,
			ASSERT,
		};
		static void d(const QString&);
		static void e(const QString&);
		static void i(const QString&);
		static void w(const QString&);
		static void rt(const QString&);
		static void wll(const QString&);

		static void assert(bool);
		static void assertl(bool, const QString&);

		static void console(QtMsgType, const QMessageLogContext&, const QString&);
        static void xmpp(QXmppLogger::MessageType, const QString&);

		static void setLogLevel(LogLevel level);

		static QString Folder();

        static void registerWriter(LogWriter* writer);
	}; 
}

