#include "Log.h"
#include "DispathThread.h"
#include "LogWriter.h"
#include "CrcHelper.h"
#include "CryptoHelper.h"
#include "SystemDefine.h"
#ifdef _WINDOWS
#include <windows.h>
#include <tchar.h>
#endif



namespace Util
{
    class LogPrivate{
    public:
        LogPrivate(int pid,const QString& path)
            :mWriter(NULL)
        {
            mLogLevel = Log::DEBUG;
            mPid = pid;
            logfolder = path+"/"+QString::number(mPid)+"/";
            logfolder = logfolder.replace("//","/");
            QDir dir;
            if(!dir.exists(logfolder))
                dir.mkpath(logfolder);

        }
        ~LogPrivate()
        {
            mDispatchThread.quit();
            mDispatchThread.wait();
            delete mWriter;
            mWriter = NULL;
        }

        int mPid;
        QString logfolder;
        Log::LogLevel mLogLevel;
        DispathThread mDispatchThread;
        LogWriter* mWriter;

        const Log::LogLevel& LogLevel() const { return mLogLevel; }
        void LogLevel(Log::LogLevel& val) { mLogLevel = val; }


        //         QString LogFolder() {
        // #ifdef _WINDOWS
        //             TCHAR buffer[MAX_PATH] = {0};
        //             GetEnvironmentVariable(LPCTSTR(L"APPDATA"), buffer, MAX_PATH);  
        // 
        //             QString appPath = QString("%1/%2/%3").arg(QString::fromUtf16 (buffer)).arg(Util::COMPANY_NAME).arg("logs");
        //             appPath.replace("\\","/");
        // #else
        //             QString appPath = QCoreApplication::applicationDirPath();
        // #endif
        // #if _DEBUG
        //             appPath.append("/DEBUG");
        // #endif
        //             QDir dir(appPath);
        //             if(!dir.exists())
        //             {
        //                 dir.mkpath(appPath);
        //             }
        //             return QString("%1/%2/").arg(appPath).arg(mPid);
        //         }

        void WriteLog(Log::LogLevel level, const QString& val) {
            QSharedPointer<QString> folder(new QString(logfolder));
            QSharedPointer<QString> data(new QString(val));
            mDispatchThread.QueueAction([level, folder, data, this](){

                QString encodeText = *data;


                if (NULL!=mWriter)
                {
                    QString logString = QString("%1 %2\r\n").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz")).arg(encodeText);

                    switch(level){
                    case Log::DEBUG:
                        emit mWriter->sgDebug(logString);
                        break;
                    case Log::INFO:
                        emit mWriter->sgInfo(logString);
                        break;
                    case Log::WARN:
                        emit mWriter->sgWarn(logString);
                        break;
                    case Log::ERR:
                        emit mWriter->sgError(logString);
                        break;
                    case Log::ASSERT:
                        break;
                    }
                }


                QFile file(*folder + "Detail.log");
                if(!file.open(QIODevice::WriteOnly | QIODevice::Append)){
                    Q_ASSERT(false);
                    return;
                }

                QTextStream out(&file);
                //#ifndef _DEBUG
                //                QString encodeVal;
                //                Util::CryptoHelper::Encode(*data,encodeVal);
                //                encodeText = QString("encodetext:%1").arg(encodeVal);
                //#endif

                QString logString = QString("%1 %2\r\n").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz")).arg(encodeText);

#ifdef _DEBUG
                out << logString;
#else
                if( level >= Log::WARN)
                    out << logString;
#endif // _DEBUG
            });
        }

        void WriteXmpp( QXmppLogger::MessageType type, const QString& val ){

            QSharedPointer<QString> folder(new QString(logfolder));
            QSharedPointer<QString> data(new QString(val));
            mDispatchThread.QueueAction([type, folder, data, this](){

                if(mWriter==NULL)
                    return;
                emit mWriter->sgXmpp(type, *data);

                QString filePath = *folder + "Xmpp.log";
                QFile file(filePath);
                if(!file.open(QIODevice::WriteOnly | QIODevice::Append)){
                    Q_ASSERT(false);
                    return;
                }

                QTextStream out(&file);
                out << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz") << endl;
                QString logType;
                switch(type)
                {
                case QXmppLogger::MessageType::SentMessage:
                    logType="send:";
                    break;
                case QXmppLogger::MessageType::InformationMessage:
                    logType = "info:";
                    break;
                case QXmppLogger::MessageType::WarningMessage:
                    logType = "warn:";
                    break;
                case QXmppLogger::MessageType::ReceivedMessage:
                    logType = "recv:";
                    break;
                case QXmppLogger::MessageType::AnyMessage:
                    logType = "any:";
                    break;
                case QXmppLogger::MessageType::DebugMessage:
                    logType = "debug:";
                    break;
                }                

                QString encodeText = *data;
                //#ifndef _DEBUG
                //                QString encodeVal;
                //                Util::CryptoHelper::Encode(*data,encodeVal);
                //                 encodeText = QString("encodetext:%1").arg(encodeVal);
                //#endif

                out<<logType<<encodeText << endl << endl;




                //out << QString("%1 %2").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz")).arg(*data) << endl;
            });
        }

        //增加一个记录运行的日志
        void WriteRunTimeLog(Log::LogLevel level, const QString& val) {
            QSharedPointer<QString> folder(new QString(logfolder));
            QSharedPointer<QString> data(new QString(val));
            mDispatchThread.QueueAction([level, folder, data, this](){

                QString encodeText = *data;


                if (NULL!=mWriter)
                {
                    QString logString = QString("%1 %2\r\n").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz")).arg(encodeText);

                    switch(level){
                    case Log::DEBUG:
                        emit mWriter->sgDebug(logString);
                        break;
                    case Log::INFO:
                        emit mWriter->sgInfo(logString);
                        break;
                    case Log::WARN:
                        emit mWriter->sgWarn(logString);
                        break;
                    case Log::ERR:
                        emit mWriter->sgError(logString);
                        break;
                    case Log::ASSERT:
                        break;
                    }
                }


                QFile file(*folder + "DetailRunTime.log");
                if(!file.open(QIODevice::WriteOnly | QIODevice::Append)){
                    Q_ASSERT(false);
                    return;
                }

                QTextStream out(&file);
                //#ifndef _DEBUG
                //                QString encodeVal;
                //                Util::CryptoHelper::Encode(*data,encodeVal);
                //                encodeText = QString("encodetext:%1").arg(encodeVal);
                //#endif

                QString logString = QString("%1 %2\r\n").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz")).arg(encodeText);

#ifdef _DEBUG
                out << logString;
#else
                if( level >= Log::WARN)
                    out << logString;
#endif // _DEBUG
            });
        }

		//音视频写javascrip 中的日志
		//增加一个记录运行的日志
		void WriteLocalLog(Log::LogLevel level, const QString& val) {
			QSharedPointer<QString> folder(new QString(logfolder));
			QSharedPointer<QString> data(new QString(val));
			mDispatchThread.QueueAction([level, folder, data, this](){

				QString encodeText = *data;


				if (NULL != mWriter)
				{
					QString logString = QString("%1 %2\r\n").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz")).arg(encodeText);

					switch (level){
					case Log::DEBUG:
						emit mWriter->sgDebug(logString);
						break;
					case Log::INFO:
						emit mWriter->sgInfo(logString);
						break;
					case Log::WARN:
						emit mWriter->sgWarn(logString);
						break;
					case Log::ERR:
						emit mWriter->sgError(logString);
						break;
					case Log::ASSERT:
						break;
					}
				}


				QFile file(*folder + "locallog.log");
				if (!file.open(QIODevice::WriteOnly | QIODevice::Append)){
					Q_ASSERT(false);
					return;
				}

				QTextStream out(&file);
				//#ifndef _DEBUG
				//                QString encodeVal;
				//                Util::CryptoHelper::Encode(*data,encodeVal);
				//                encodeText = QString("encodetext:%1").arg(encodeVal);
				//#endif

				QString logString = QString("%1 %2\r\n").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz")).arg(encodeText);

#ifdef _DEBUG
				out << logString;
#else
				if (level >= Log::WARN)
					out << logString;
#endif // _DEBUG
			});
		}


        //音视频写javascrip 中的日志
        //增加一个记录运行的日志
        void WriteQDebug(const QString& val) {
            QSharedPointer<QString> folder(new QString(logfolder));
            QSharedPointer<QString> data(new QString(val));
            mDispatchThread.QueueAction([folder, data, this](){

                QString encodeText = *data;

                QFile file(*folder + "qdebug.log");
                if (!file.open(QIODevice::WriteOnly | QIODevice::Append)){
                    Q_ASSERT(false);
                    return;
                }

                QTextStream out(&file);
                

                QString logString = QString("%1 %2\r\n").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz")).arg(encodeText);

                out << logString;
            });
        }

        void registerWriter( LogWriter* writer )
        {
            mWriter = writer;
        }
    };


    void chakan(QString path){  
        QDir dir(path);  

        foreach(QFileInfo mfi ,dir.entryInfoList())  
        {  
            QString paht = mfi.absoluteFilePath ();
            if(mfi.isFile())  
            {  
                quint64 lastModified = mfi.lastModified ().toMSecsSinceEpoch ();
                
                if ((QDateTime::currentMSecsSinceEpoch () - lastModified) > 1000*60*60*24*7)
                {
                    QFile::remove(mfi.absoluteFilePath ());

                    if (mfi.dir ().entryInfoList ().size () <= 2)
                        mfi.dir ().rmdir (mfi.path ());
                }
            }
            else  
            {  
                if (mfi.dir ().entryInfoList ().size () <= 2)
                    mfi.dir ().rmdir (mfi.absoluteFilePath ());

                if(mfi.fileName()=="." || mfi.fileName() == "..")continue;  
                chakan(mfi.absoluteFilePath());  
            }  
        }  
    }  


    static LogPrivate* mPrivate = NULL;
    void Log::init( int pid ,const QString& path)
    {
#ifdef _WINDOWS
        chakan(path);
#endif
        mPrivate = new LogPrivate(pid,path);
    }

    QString Log::Folder()
    {
        return "";
        /*return mPrivate->LogFolder();*/
    }

    void Log::release(){
        //         delete mPrivate;
        //         mPrivate = NULL;
    }

    void Log::setLogLevel( LogLevel level )
    {
        mPrivate->LogLevel(level);
    }

    void Log::d( const QString& val )
    {
        if(mPrivate->LogLevel() > DEBUG){
            return;
        }
        mPrivate->WriteLog(DEBUG, val);

    }

    void Log::e( const QString& val )
    {
        if(mPrivate->LogLevel() > ERR){
            return;
        }
        mPrivate->WriteLog(ERR, QString::number((long)QThread::currentThreadId()) + " " + val);
    }

    void Log::i( const QString& val)
    {
        if(mPrivate->LogLevel() > INFO){
            return;
        }
        mPrivate->WriteLog(INFO, val);
    }

    void Log::w( const QString& val )
    {
        if(mPrivate->LogLevel() > WARN){
            return;
        }
        mPrivate->WriteLog(WARN, val);
    }

    void Log::assert( bool val )
    {
        if (!val)
        {
            int a = 8;
            a = 9;
        }
        Q_ASSERT(val);

    }

    void Log::assertl( bool val, const QString& str)
    {
        Q_ASSERT(val);
        mPrivate->WriteLog(ERR, str);

    }

    void Log::console( QtMsgType type, const QMessageLogContext& context, const QString& msg )
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
            break;
        case QtCriticalMsg:
            outputString = QString("Critical: %1 (%2:%3, %4)")
                .arg (localMsg.constData ())
                .arg (context.file)
                .arg(context.line)
                .arg (context.function);
            break;
        case QtFatalMsg:
            outputString = QString("Fatal: %1 (%2:%3, %4)")
                .arg (localMsg.constData ())
                .arg (context.file)
                .arg(context.line)
                .arg (context.function);
        }

        outputString = QString("[%1] %2").arg((long)QThread::currentThreadId()).arg (outputString);
        mPrivate->WriteQDebug(outputString);
       
    }


    void Log::xmpp( QXmppLogger::MessageType type, const QString& val )
    {
        mPrivate->WriteXmpp(type, val);
        //mPrivate->WriteLog(INFO, val);
    }

    void Log::registerWriter( LogWriter* writer )
    {
        mPrivate->registerWriter(writer);
    }

    void Log::rt(const QString&val)
    {
        if(mPrivate->LogLevel() > ERR){
            return;
        }
        mPrivate->WriteRunTimeLog(ERR, QString::number((long)QThread::currentThreadId()) + " " + val);
    }
	//
	void Log::wll(const QString& log)
	{
		if (mPrivate->LogLevel() > ERR){
			return;
		}
		mPrivate->WriteLocalLog(ERR, QString::number((long)QThread::currentThreadId()) + " " + log);
	}

}
