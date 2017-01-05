#pragma once

#if !defined(WX_WX_H)
#define WX_WX_H

#include <objbase.h>
#include <windows.h>

#include <Misc/exceptions.h>

//! Miscellaneous Windows support functions

namespace Wx
{
//! A windows device context (DC) wrapper

class DeviceContext
{
public:

    //! Constructor
    DeviceContext(HWND hWnd)
        : hWnd_(hWnd)
        , hDC_(::GetDC(hWnd))
    {
    }

    //! Destructor
    ~DeviceContext()
    {
        ReleaseDC(hWnd_, hDC_);
    }

    // non-copyable
    DeviceContext(DeviceContext const &) = delete;
    DeviceContext & operator =(DeviceContext const &) = delete;

    //! Returns the device context handle
    HDC GetDC() const { return hDC_; }

private:

    HDC hDC_;          //!< Device context handle
    HWND hWnd_;        //!< Window handle
};

//! A class that initializes COM while it is in scope
class ComInitializer
{
public:

    //! Constructor
    //
    //! @param	pvReserved	Use the default value
    ComInitializer(LPVOID pvReserved = NULL)  // , DWORD dwCoInit = COINIT_MULTITHREADED )
    {
        CoInitialize(pvReserved);  // , dwCoInit );
    }

    // Destructor
    ~ComInitializer()
    {
        CoUninitialize();
    }
};

//! An exception to throw when a Win32 function returns a failure

class Win32ErrorException : public std::exception
{
public:

    //! Constructor
    //
    //! @param	code	The error code (default is S_OK)
    //! @param	sMsg	The error message (default is "Win32 error reported")

    Win32ErrorException(HRESULT code = S_OK, char const * sMsg = "Win32 error reported") throw ()
        : std::exception(sMsg)
        , code_(code)
    {
    }

    // Destructor
    virtual ~Win32ErrorException() override throw ()= default;

    //! @name Overrides std::exception
    //@{
    //	virtual const char *what() const;
    //@}

    //! Returns the error code
    virtual HRESULT code() const
    {
        return code_;
    }

private:

    HRESULT code_;
};

//! Registers a window class. Returns NULL if failed
ATOM RegisterWindowClass(UINT      style,
                         WNDPROC   lpfnWndProc,
                         HINSTANCE hInstance,
                         LPCTSTR   lpszClassName,
                         HCURSOR   hCursor       = NULL,
                         HBRUSH    hbrBackground = NULL,
                         HICON     hIcon         = NULL,
                         HICON     hIconSm       = NULL,
                         LPCTSTR   lpszMenuName  = NULL,
                         int       cbClsExtra    = 0,
                         int       cbWndExtra    = 0);

//! Idle function for MessageLoop(). Returns @c true if it should be called again immediately if the queue is empty.
//
//! This function is is a parameter to MessageLoop() and is called whenever the message queue is empty. If it
//! returns @c true, then it will be called again immediately if the message queue is empty. If it returns
//! @c false, it will not be called until a message has been processed and the queue is empty again.
//!
//! @param	hWnd	Window handle
using MessageLoopIdleCallback = bool (*)(HWND hWnd);

//! Standard windows message loop. Returns the value in the WM_QUIT message.
int MessageLoop(HWND hWnd, MessageLoopIdleCallback pCB = nullptr);

//! @name Debugging Functions
//!
//@{

#if defined(_DEBUG)

//! Dumps the device's caps to the debugger output window
void DumpDeviceCaps(HDC hDC);

#endif // defined( _DEBUG )

//! Returns the COM object's current reference count.
//
//!
//! @param	pObject	COM object pointer

template <typename T>
inline ULONG GetReferenceCount(T * pObject)
{
    pObject->AddRef();
    return pObject->Release();
}
//@}

//! @name Other Miscellaneous
//!
//@{

//! Releases a COM object and resets the pointer to @c NULL.
//
//!
//! @param	pObject	COM object pointer

template <typename T>
inline void SafeRelease(T * & pObject)
{
    if (pObject != NULL)
    {
        pObject->Release();
        pObject = NULL;
    }
}

//@}
}  // namespace Wx

//! Asserts that the HRESULT value indicates success.
//
//!
//! @param	hr	@c HRESULT value
//!
//! @hideinitializer

#if defined(_DEBUG)

#include <Misc/Assert.h>

#define assert_succeeded(hr) \
    (void)(SUCCEEDED(hr) ||  \
           (non_standard_assert_display( #hr " indicates failure.", __FILE__, __LINE__), 0))

#else // defined ( _DEBUG )

#define assert_succeeded(hr) ((void)0)

#endif // defined( _DEBUG )

#endif // !defined(WX_WX_H)
