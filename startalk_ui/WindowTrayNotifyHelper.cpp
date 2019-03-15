#ifdef _WINDOWS
#include "WindowTrayNotifyHelper.h"
#include <wtypes.h>
#include <commctrl.h>


typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);  

typedef struct _TBBUTTONX32 { 
    int iBitmap; 
    int idCommand; 
    BYTE fsState; 
    BYTE fsStyle; 
    BYTE bReserved[2]; // padding for alignment 
    DWORD_PTR dwData; 
    INT_PTR iString; 
} TBBUTTONX32; 

typedef struct _TBBUTTONX64 { 
    int iBitmap; 
    int idCommand; 
    BYTE fsState; 
    BYTE fsStyle; 
    BYTE bReserved[6]; // padding for alignment 
    DWORD_PTR dwData; 
    INT_PTR iString; 
} TBBUTTONX64;

BOOL IsWow64()  
{  
    BOOL bIsWow64 = FALSE;  

    LPFN_ISWOW64PROCESS   
        fnIsWow64Process = (LPFN_ISWOW64PROCESS)GetProcAddress(  
        GetModuleHandle(L"kernel32"),"IsWow64Process");  

    if (NULL != fnIsWow64Process)  
    {  
        if (!fnIsWow64Process(GetCurrentProcess(),&bIsWow64))  
        {  
            // handle error  
        }  
    }  
    return bIsWow64;  
}  


HWND FindTrayWnd()  
{  
    HWND hWnd = NULL;  

    hWnd = FindWindow(L"Shell_TrayWnd", NULL);  
    hWnd = FindWindowEx(hWnd, NULL, L"TrayNotifyWnd", NULL);  
    hWnd = FindWindowEx(hWnd, NULL, L"SysPager", NULL);  
    hWnd = FindWindowEx(hWnd, NULL, L"ToolbarWindow32", NULL);  


    return hWnd;  
}  

HWND FindNotifyIconOverflowWindow()  
{  
    HWND hWnd = NULL;  

    hWnd = FindWindow(L"NotifyIconOverflowWindow", NULL);  
    hWnd = FindWindowEx(hWnd, NULL, L"ToolbarWindow32", NULL);  

    return hWnd;  
}  

QRect EnumNotifyWindow(HWND hWnd)  
{  
    QRect qrect;
    DWORD dwProcessId = 0;  
    GetWindowThreadProcessId(hWnd,&dwProcessId);  

    HANDLE hProcess = OpenProcess(PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_VM_WRITE, FALSE, dwProcessId);  

    LPVOID lAddress = VirtualAllocEx(hProcess, 0, 4096, MEM_COMMIT, PAGE_READWRITE);  
    if ( lAddress==NULL ){  
       // IMHelper::Assert(false);
        CloseHandle(hProcess);
        return qrect;  
    }  
    DWORD lTextAdr = 0;  
    BYTE buff[1024] = {0};  
    QString strTile;   
    int nDataOffset = sizeof(TBBUTTON) - sizeof(INT_PTR) - sizeof(DWORD_PTR);  
    int nStrOffset = 18;   
    if ( IsWow64() ){  
        nDataOffset+=4;  
        nStrOffset+=6;  
    }  

    int lButton = SendMessage(hWnd, TB_BUTTONCOUNT, 0, 0);  
    for (int i = 0; i < lButton; i++) {  
        auto ret = SendMessage(hWnd, TB_GETBUTTON, i, (LPARAM)lAddress);  
        ret = ReadProcessMemory(hProcess, (LPVOID)((DWORD)lAddress + nDataOffset), &lTextAdr, 4, 0);  
        if ( lTextAdr!=-1 ) {  
            ret = ReadProcessMemory(hProcess, (LPCVOID)lTextAdr, buff, 1024, 0);  
            auto hMainWnd = (HWND)(*((DWORD*)buff));  
            auto strFilePath = QString::fromUtf16((const ushort*)&buff + nStrOffset);
            //strTile = (WCHAR *)buff + nStrOffset + MAX_PATH;  
            if(ret == 0) 
                continue;

            DWORD id = 0;
            GetWindowThreadProcessId(hMainWnd, &id);

            auto currPid = GetCurrentProcessId();
            if(currPid != id)
                continue;

            RECT hwndRc = {0, 0};
            GetWindowRect(hWnd, &hwndRc);

            LPVOID rect = VirtualAllocEx(hProcess,0,sizeof(RECT), MEM_COMMIT, PAGE_READWRITE);  
            if(rect == NULL){
               // IMHelper::Assert(false);
                VirtualFreeEx(hProcess, lAddress, 0, MEM_RELEASE);  
                CloseHandle(hProcess);
                return qrect;
            }
            ret = SendMessage(hWnd,TB_GETITEMRECT,(WPARAM)i,(LPARAM)rect);

            RECT rc = {0}; 
            ret = ReadProcessMemory(hProcess, rect, &rc, sizeof(rc),0);
            VirtualFreeEx(hProcess, rect, 0, MEM_RELEASE);

            //MapWindowPoints(hWnd, NULL, (LPPOINT)&rc, 2); 
            qrect.setRect(rc.left + hwndRc.left, rc.top + hwndRc.top, 
                rc.right - rc.left - 2, 
                rc.bottom - rc.top - 2); 

            break;

        }  
    }  
    VirtualFreeEx(hProcess, lAddress, 0, MEM_RELEASE);  
    CloseHandle(hProcess);  

    return qrect;
}  

WindowTrayNotifyHelper::WindowTrayNotifyHelper(void)
{
}


WindowTrayNotifyHelper::~WindowTrayNotifyHelper(void)
{
}

QRect WindowTrayNotifyHelper::FindMyIcon( )
{
    auto rect = EnumNotifyWindow(FindTrayWnd());
    if(rect.isEmpty())
        rect = EnumNotifyWindow(FindNotifyIconOverflowWindow());
    return rect;
}

#endif
