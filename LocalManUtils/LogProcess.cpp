#ifdef _WINDOWS
#include "LogProcess.h"
#include "LogWriter.h"

namespace Util
{
	LogProcess* LogProcess::mInst = NULL;

	LogProcess::LogProcess(void)
	{
        hWnd = NULL;
	}


	LogProcess::~LogProcess(void)
	{
        
	}
    void LogProcess::setHwnd(HWND h)
    {
        hWnd = h;
    }
	void LogProcess::registerWriter( LogWriter* writer )
	{
		mWriter = writer;

        bool ret =connect(mWriter, &LogWriter::sgDebug, this, &LogProcess::LogDebug);
        ret = connect(mWriter, &LogWriter::sgError, this, &LogProcess::LogError);
        ret = connect(mWriter, &LogWriter::sgInfo, this, &LogProcess::LogInfo);
        ret = connect(mWriter, &LogWriter::sgWarn, this, &LogProcess::LogWarn);
        ret = connect(mWriter, &LogWriter::sgXmpp, this, &LogProcess::LogXmpp);
        ret = connect(mWriter, &LogWriter::sgConsole, this, &LogProcess::LogConsole);			
	}

	LogProcess* LogProcess::Instance(){
		if( mInst == NULL)
			mInst = new LogProcess();
		return mInst;
	}

	void LogProcess::Release()
	{
		if( mInst )
		{			
			delete mInst;
			mInst = NULL;
		}
	}

	void LogProcess::LogDebug(const QString& log)
	{
        WriteLog(LogLevel::DEBUG,log);
	}
	void LogProcess::LogError(const QString& log)
	{
        WriteLog(LogLevel::ERR, log);
	}
	void LogProcess::LogInfo(const QString& log)
	{
        WriteLog(LogLevel::INFO, log);
	}
	void LogProcess::LogWarn(const QString& log)
	{
        WriteLog(LogLevel::WARN, log);
	}

	void LogProcess::LogConsole(QtMsgType, const QString& log)
	{
        WriteLog(LogLevel::CONSOLE, log);
	}
	void LogProcess::LogXmpp(int type, const QString& log)
	{
        WriteXmpp(LogLevel::XMPP, type, log);
	}


	void LogProcess::WriteLog(LogLevel nType, const QString& str)
	{ 
		QString logStr = QString("%1%2").arg(nType).arg(str);		
 		auto tmpBuf = logStr.toUtf8();
 	
        if(hWnd == NULL)
            return;
        HWND receiveWnd = ::FindWindow(NULL, TEXT("ConsoleDialog"));  
        if (receiveWnd == NULL)  
            return; 
        COPYDATASTRUCT copyData = { 0 };
        copyData.lpData = (PVOID)tmpBuf.data();
        copyData.cbData = tmpBuf.length();
        ::SendMessage(receiveWnd, WM_COPYDATA, (WPARAM)hWnd, (LPARAM)&copyData );
	}
	
	void LogProcess::WriteXmpp(LogLevel nType, int type, const QString& str)
	{ 
		if( type == 8)
			type = 0;
		else if(type == 16)
			type = 1;		

		QString logStr = QString("%1%2%3").arg(nType).arg(type).arg(str);		
		auto tmpBuf = logStr.toUtf8();
        if(hWnd == NULL)
            return;
        HWND receiveWnd = ::FindWindow(NULL, TEXT("ConsoleDialog"));  
        if (receiveWnd == NULL)  
            return; 

        COPYDATASTRUCT copyData = { 0 };
        copyData.lpData = (PVOID)tmpBuf.data();
        copyData.cbData = tmpBuf.length();
        ::SendMessage(receiveWnd, WM_COPYDATA, (WPARAM)hWnd, (LPARAM)&copyData );   
	}

 	void LogProcess::CreateLogProcess()		
 	{ 
		STARTUPINFO si;
		PROCESS_INFORMATION pi;

		ZeroMemory( &si, sizeof(si) );
		si.cb = sizeof(si);
		ZeroMemory( &pi, sizeof(pi) );		

#if _DEBUG
		QString exePath = QString("%1/%2").arg(qApp->applicationDirPath()).arg("LocalManLogD.exe");	
#else
        QString exePath = QString("%1/%2").arg(qApp->applicationDirPath()).arg("LocalManLog.exe");	
#endif
		exePath = exePath.replace("/","\\");
		
		
		// Start the child process. 
		if( !CreateProcess( NULL,   // No module name (use command line)
			(LPWSTR)exePath.utf16(),       // Command line
			NULL,           // Process handle not inheritable
			NULL,           // Thread handle not inheritable
			FALSE,          // Set handle inheritance to FALSE
			0,              // No creation flags
			NULL,           // Use parent's environment block
			NULL,           // Use parent's starting directory 
			&si,            // Pointer to STARTUPINFO structure
			&pi )           // Pointer to PROCESS_INFORMATION structure
			) 
		{
			DWORD dwErr = GetLastError();
			printf( "CreateProcess failed (%d).\n", GetLastError() );
			return;
		}

		// Wait until child process exits.
		//WaitForSingleObject( pi.hProcess, INFINITE );

		// Close process and thread handles. 
		CloseHandle( pi.hProcess );
		CloseHandle( pi.hThread );
 	}
}
#endif
