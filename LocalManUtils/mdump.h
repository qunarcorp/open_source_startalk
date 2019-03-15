#ifndef _MDUMP_H_
#define _MDUMP_H_

#ifdef _WINDOWS
#include <stdio.h>
#include <stdlib.h>
#include <TCHAR.h>
#include <Windows.h>

struct _EXCEPTION_POINTERS;

class CMiniDumper
{
public:
	static void Enable(LPCTSTR pszAppName, bool bShowErrors, LPCTSTR pszDumpDir);
    static void SetDumpLevel(int dDumpLevel);

private:
    static int   m_dDumpLevel;
	static TCHAR m_szAppName[MAX_PATH];
	static TCHAR m_szDumpDir[MAX_PATH];

	static HMODULE GetDebugHelperDll(FARPROC* ppfnMiniDumpWriteDump, bool bShowErrors);
	static LONG WINAPI TopLevelFilter(struct _EXCEPTION_POINTERS* pExceptionInfo);
};

extern CMiniDumper theCrashDumper;
#endif
#endif
