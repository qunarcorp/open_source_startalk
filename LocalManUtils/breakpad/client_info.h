

#ifndef CLIENT_WINDOWS_CRASH_GENERATION_CLIENT_INFO_H__
#define CLIENT_WINDOWS_CRASH_GENERATION_CLIENT_INFO_H__

#include <Windows.h>

#ifndef _IMAGEHLP_
#include <DbgHelp.h>
#endif


#include "inc/minidump_format.h"
#include "inc/scoped_ptr.h"

namespace google_breakpad
{

struct CustomInfoEntry
{
    // Maximum length for name and value for client custom info.
    static const int kNameMaxLength = 64;
    static const int kValueMaxLength = 64;

    CustomInfoEntry()
    {
        // Putting name and value in initializer list makes VC++ show warning 4351.
        set_name( NULL );
        set_value( NULL );
    }

    CustomInfoEntry( const wchar_t* name_arg, const wchar_t* value_arg )
    {
        set_name( name_arg );
        set_value( value_arg );
    }

    void set_name( const wchar_t* name_arg )
    {
		ZeroMemory( value , kNameMaxLength * sizeof(wchar_t) );

        if ( !name_arg )
        {
            name[0] = L'\0';
            return;
        }
        wcsncpy_s( name, kNameMaxLength - 1, name_arg , kNameMaxLength - 1 );
    }

    void set_value( const wchar_t* value_arg )
    {
		ZeroMemory( value , kValueMaxLength * sizeof(wchar_t) );
        if ( !value_arg )
        {
            value[0] = L'\0';
            return;
        }

        wcsncpy_s( value, kValueMaxLength - 1, value_arg , kValueMaxLength - 1 );
    }

    void set( const wchar_t* name_arg, const wchar_t* value_arg )
    {
        set_name( name_arg );
        set_value( value_arg );
    }

    wchar_t name[kNameMaxLength];
    wchar_t value[kValueMaxLength];
};


struct CustomClientInfo 
{
  const CustomInfoEntry* entries;
  int count;
};

// Abstraction for a crash client process.
class ClientInfo
{
public:
    // Creates an instance with the given values. Gets the process
    // handle for the given process id and creates necessary event
    // objects.
    ClientInfo( DWORD pid,
                MINIDUMP_TYPE dump_type,
                DWORD* thread_id,
                EXCEPTION_POINTERS** ex_info,
                MDRawAssertionInfo* assert_info,
                const CustomClientInfo& custom_client_info );

    ~ClientInfo();

    DWORD pid() const
    {
        return pid_;
    }
    MINIDUMP_TYPE dump_type() const
    {
        return dump_type_;
    }
    EXCEPTION_POINTERS** ex_info() const
    {
        return ex_info_;
    }
    MDRawAssertionInfo* assert_info() const
    {
        return assert_info_;
    }
    DWORD* thread_id() const
    {
        return thread_id_;
    }
    HANDLE process_handle() const
    {
        return process_handle_;
    }
    HANDLE dump_requested_handle() const
    {
        return dump_requested_handle_;
    }
    HANDLE dump_generated_handle() const
    {
        return dump_generated_handle_;
    }

    HANDLE dump_request_wait_handle() const
    {
        return dump_request_wait_handle_;
    }

    void set_dump_request_wait_handle( HANDLE value )
    {
        dump_request_wait_handle_ = value;
    }

    HANDLE process_exit_wait_handle() const
    {
        return process_exit_wait_handle_;
    }

    void set_process_exit_wait_handle( HANDLE value )
    {
        process_exit_wait_handle_ = value;
    }

    // Unregister all waits for the client.
    bool UnregisterWaits();

    bool Initialize();
    bool GetClientExceptionInfo( EXCEPTION_POINTERS** ex_info ) const;
    bool GetClientThreadId( DWORD* thread_id ) const;

    // Reads the custom information from the client process address space.
    bool PopulateCustomInfo();

    // Returns the client custom information.
    CustomClientInfo GetCustomInfo() const;

private:
    // Calcualtes the uptime for the client process, converts it to a stdstring and
    // stores it in the last entry of client custom info.
    void SetProcessUptime();


    // Client process ID.
    DWORD pid_;

    // Dump type requested by the client.
    MINIDUMP_TYPE dump_type_;

    // Address of an EXCEPTION_POINTERS* variable in the client
    // process address space that will point to an instance of
    // EXCEPTION_POINTERS containing information about crash.
    //
    // WARNING: Do not dereference these pointers as they are pointers
    // in the address space of another process.
    EXCEPTION_POINTERS** ex_info_;

    // Address of an instance of MDRawAssertionInfo in the client
    // process address space that will contain information about
    // non-exception related crashes like invalid parameter assertion
    // failures and pure calls.
    //
    // WARNING: Do not dereference these pointers as they are pointers
    // in the address space of another process.
    MDRawAssertionInfo* assert_info_;

    // Custom information about the client.
    CustomClientInfo custom_client_info_;

    // Contains the custom client info entries read from the client process
    // memory. This will be populated only if the method GetClientCustomInfo
    // is called.
    scoped_array<CustomInfoEntry> custom_info_entries_;

    // Address of a variable in the client process address space that
    // will contain the thread id of the crashing client thread.
    //
    // WARNING: Do not dereference these pointers as they are pointers
    // in the address space of another process.
    DWORD* thread_id_;

    // Client process handle.
    HANDLE process_handle_;

    // Dump request event handle.
    HANDLE dump_requested_handle_;

    // Dump generated event handle.
    HANDLE dump_generated_handle_;

    // Wait handle for dump request event.
    HANDLE dump_request_wait_handle_;

    // Wait handle for process exit event.
    HANDLE process_exit_wait_handle_;

    // Time when the client process started. It is used to determine the uptime
    // for the client process when it signals a crash.
    FILETIME start_time_;

    // Disallow copy ctor and operator=.
    ClientInfo( const ClientInfo& client_info );
    ClientInfo& operator=( const ClientInfo& client_info );
};

}  // namespace google_breakpad

#endif  // CLIENT_WINDOWS_CRASH_GENERATION_CLIENT_INFO_H__
