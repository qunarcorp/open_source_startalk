#ifdef _WINDOWS
#include "DumpHandle.h"

#include "breakpad/exception_handler.h"



#include <concrtrm.h>
#include <WinVer.h>
#pragma comment(lib,"Version.lib" )
namespace Util{

#pragma region [crash report]

    template <typename T, size_t N>
    char (&ArraySizeHelper(T (&array)[N]))[N];
#define ARRAY_SIZE(array) (sizeof(ArraySizeHelper(array)))
    void InitCrashReport(QString path);

#ifndef _DEBUG
    google_breakpad::ExceptionHandler *g_breakpad = NULL;
    bool DumpDoneCallback( const wchar_t*dump_path_c_, const wchar_t*dumpfile, void*,
        EXCEPTION_POINTERS* ex_info,
        MDRawAssertionInfo*, bool )
    {
        return true;
    }

    void InitCrashReport(QString savePath )
    {
        _CrtSetReportMode( _CRT_ASSERT, 0 );
        static google_breakpad::CustomInfoEntry os_entry( L"Platform: " , L"windows"/*CT2W( GetOSVersion() ).m_psz*/ );
        static google_breakpad::CustomInfoEntry clientver_entry( L"Client Version: " , L"0.0.0.0" );

        static google_breakpad::CustomInfoEntry entries[] = { os_entry, clientver_entry };

        static google_breakpad::CustomClientInfo custom_info = {	entries,
            ARRAY_SIZE( entries )
        };
        if (savePath.right(1)==QString("\\"))
        {
            savePath = savePath.left(savePath.length()-1);
        }
        const wchar_t * encodedName = reinterpret_cast<const wchar_t *>(savePath.utf16());   
        MINIDUMP_TYPE dump_type = /*MiniDumpWithFullMemory ;full_dump ? MiniDumpWithFullMemory :*/MiniDumpNormal;
        g_breakpad = new google_breakpad::ExceptionHandler( 
            encodedName, NULL, &DumpDoneCallback,
            NULL, google_breakpad::ExceptionHandler::HANDLER_ALL,
            dump_type, NULL, &custom_info 
            );
    }
#endif
#pragma endregion

    DumpHandle::DumpHandle(void)
    {
        mstrSavePath = "";
    }


    DumpHandle::~DumpHandle(void)
    {
    }

//     void DumpHandle::enable()
//     {
// 
//     }
    void DumpHandle::Init(QString path)
    {
#ifndef _DEBUG

        InitCrashReport(path);

#endif
    }

}
#endif
