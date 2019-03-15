#ifdef _WINDOWS
#include "mdump.h"
#include <time.h>
#include <shlwapi.h>
#include <dbghelp.h>
#include <tchar.h>
#include <wtypes.h>
#pragma comment( lib, "dbghelp.lib" )

typedef BOOL ( WINAPI * MINIDUMPWRITEDUMP )(HANDLE hProcess, DWORD dwPid, HANDLE hFile, MINIDUMP_TYPE DumpType,
                                            CONST PMINIDUMP_EXCEPTION_INFORMATION ExceptionParam,
                                            CONST PMINIDUMP_USER_STREAM_INFORMATION UserStreamParam,
                                            CONST PMINIDUMP_CALLBACK_INFORMATION CallbackParam);

CMiniDumper theCrashDumper;
TCHAR CMiniDumper::m_szAppName[MAX_PATH] = {0};
TCHAR CMiniDumper::m_szDumpDir[MAX_PATH] = {0};
int CMiniDumper::m_dDumpLevel = 0;
void CMiniDumper::Enable(LPCTSTR pszAppName, bool bShowErrors, LPCTSTR pszDumpDir)
{
    // if this assert fires then you have two instances of CMiniDumper which is not allowed
    _tcsncpy(m_szAppName, (LPTSTR)pszAppName, _countof(m_szAppName) - 1);
    m_szAppName[_countof(m_szAppName) - 1] = _T('\0');

    _tcsncpy(m_szDumpDir, (LPTSTR)pszDumpDir, _countof(m_szDumpDir) - 1);
    m_szDumpDir[_countof(m_szDumpDir) - 1] = _T('\0');
    PathAddBackslash((LPWSTR)m_szDumpDir);

    MINIDUMPWRITEDUMP pfnMiniDumpWriteDump = NULL;
    HMODULE hDbgHelpDll                    = GetDebugHelperDll((FARPROC*)&pfnMiniDumpWriteDump, bShowErrors);
    if (hDbgHelpDll)
    {
        if (pfnMiniDumpWriteDump)
            SetUnhandledExceptionFilter(TopLevelFilter);
        FreeLibrary(hDbgHelpDll);
        hDbgHelpDll          = NULL;
        pfnMiniDumpWriteDump = NULL;
    }
}

void CMiniDumper::SetDumpLevel(int dDumpLevel)
{
    m_dDumpLevel = dDumpLevel;
}

#define DBGHELP_HINT _T("You can get the required DBGHELP.DLL by downloading the \"User Mode Process Dumper\" from \"Microsoft Download Center\".\r\n\r\n") \
    _T("Extract the \"User Mode Process Dumper\" and locate the \"x86\" folder. Copy the DBGHELP.DLL from the \"x86\" folder into your UUMessager installation folder and/or into your Windows system/system32 folder.")

HMODULE CMiniDumper::GetDebugHelperDll(FARPROC* ppfnMiniDumpWriteDump, bool bShowErrors)
{
    *ppfnMiniDumpWriteDump = NULL;
    HMODULE hDll = LoadLibrary((LPCWSTR)_T("DBGHELP.DLL"));
    if (hDll != NULL)
    {
        *ppfnMiniDumpWriteDump = GetProcAddress(hDll, ("MiniDumpWriteDump"));
    }

    return hDll;
}

LONG CMiniDumper::TopLevelFilter(struct _EXCEPTION_POINTERS* pExceptionInfo)
{
    LONG lRetValue                         = EXCEPTION_CONTINUE_SEARCH;
    TCHAR szResult[MAX_PATH + 1024]        = {0};
    MINIDUMPWRITEDUMP pfnMiniDumpWriteDump = NULL;
    HMODULE hDll                           = GetDebugHelperDll((FARPROC*)&pfnMiniDumpWriteDump, true);
    if (hDll)
    {
        if (pfnMiniDumpWriteDump)
        {
            // Ask user if they want to save a dump file
            // Do *NOT* localize that string (in fact, do not use MFC to load it)!

            // Create full path for DUMP file
            TCHAR szDumpPath[MAX_PATH];
            _tcsncpy(szDumpPath, m_szDumpDir, _countof(szDumpPath) - 1);
            szDumpPath[_countof(szDumpPath) - 1] = _T('\0');
            size_t uDumpPathLen = _tcslen(szDumpPath);

            TCHAR szBaseName[MAX_PATH];
            _tcsncpy(szBaseName, m_szAppName, _countof(szBaseName) - 1);
            szBaseName[_countof(szBaseName) - 1] = _T('\0');
            size_t uBaseNameLen = _tcslen(szBaseName);

            time_t tNow = time(NULL);
            _tcsftime(szBaseName + uBaseNameLen, _countof(szBaseName) - uBaseNameLen, _T("_%Y%m%d-%H%M%S"), localtime(&tNow));
            szBaseName[_countof(szBaseName) - 1] = _T('\0');

            // Replace spaces and dots in file name.
            LPTSTR psz = (LPTSTR)szBaseName;
            while (*psz != _T('\0'))
            {
                if (*psz == _T('.'))
                    *psz = _T('-');
                else if (*psz == _T(' '))
                    *psz = _T('_');
                psz++;
            }
            if (uDumpPathLen < _countof(szDumpPath) - 1)
            {
                _tcsncat(szDumpPath, szBaseName, _countof(szDumpPath) - uDumpPathLen - 1);
                szDumpPath[_countof(szDumpPath) - 1] = _T('\0');
                uDumpPathLen                         = _tcslen(szDumpPath);
                if (uDumpPathLen < _countof(szDumpPath) - 1)
                {
                    _tcsncat(szDumpPath, _T(".dmp"), _countof(szDumpPath) - uDumpPathLen - 1);
                    szDumpPath[_countof(szDumpPath) - 1] = _T('\0');
                }
            }

            HANDLE hFile = CreateFile((LPCWSTR)szDumpPath, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
            if (hFile != INVALID_HANDLE_VALUE)
            {
                _MINIDUMP_EXCEPTION_INFORMATION ExInfo = {0};
                ExInfo.ThreadId          = GetCurrentThreadId();
                ExInfo.ExceptionPointers = pExceptionInfo;
                ExInfo.ClientPointers    = NULL;

                MINIDUMP_TYPE type = (MINIDUMP_TYPE)m_dDumpLevel;
                //MiniDumpNormal
                BOOL bOK = ( *pfnMiniDumpWriteDump )( GetCurrentProcess(), GetCurrentProcessId(), hFile, type, &ExInfo, NULL, NULL );
                if (bOK)
                {
                    // Do *NOT* localize that string (in fact, do not use MFC to load it)!
                    _sntprintf(szResult, _countof(szResult) - 1, _T("Saved dump file to \"%s\".\r\n\r\nPlease send this file together with a detailed bug report to support@UUMessager.com !\r\n\r\nThank you for helping to improve UUMessager."), szDumpPath);
                    szResult[_countof(szResult) - 1] = _T('\0');
                    lRetValue                        = EXCEPTION_EXECUTE_HANDLER;
                }
                else
                {
                    // Do *NOT* localize that string (in fact, do not use MFC to load it)!
                    _sntprintf(szResult, _countof(szResult) - 1, _T("Failed to save dump file to \"%s\".\r\n\r\nError: %u"), szDumpPath, GetLastError());
                    szResult[_countof(szResult) - 1] = _T('\0');
                }
                CloseHandle(hFile);
            }
            else
            {
                // Do *NOT* localize that string (in fact, do not use MFC to load it)!
                _sntprintf(szResult, _countof(szResult) - 1, _T("Failed to create dump file \"%s\".\r\n\r\nError: %u"), szDumpPath, GetLastError());
                szResult[_countof(szResult) - 1] = _T('\0');
            }
        }
        FreeLibrary(hDll);
        hDll                 = NULL;
        pfnMiniDumpWriteDump = NULL;
    }

//     if (szResult[0] != _T('\0'))
//         MessageBox(NULL, szResult, m_szAppName, MB_ICONINFORMATION | MB_OK);

#ifndef _DEBUG
    // Exit the process only in release builds, so that in debug builds the exceptio is passed to a possible
    // installed debugger
    ExitProcess(400);
#else

    return lRetValue;
#endif
}
#endif
