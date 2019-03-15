#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#include "CoreObject.h"
#include <functional>

#ifdef _WINDOWS
#include <windows.h>
#include <windowsx.h>
#endif

namespace Biz {
    class AsyncCallback;
}

namespace MainApp {

	class Framework
	{
	public:
		Framework();
		~Framework();

        static bool Initialize();
        static void release();
        static void onLogout();
        static void onQuit();
        static qint64 startTick();
        static void showOrHideMainWindow(int showType);
		static void collectLogs();
		static void clearCaches();
        static bool anyProgressHere();

    private:
        static QSharedMemory smInstance;
        static qint64 appStartTick; 
#ifdef _WINDOWS
    public:
        static HANDLE hMutex;
#endif

	};
}

#endif // FRAMEWORK_H
