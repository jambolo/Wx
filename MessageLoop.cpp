// #include "PrecompiledHeaders.h"

#include "Wx.h"

#pragma warning( disable: 4127  )   // conditional expression is constant

namespace Wx
{
//! This function waits for messages and dispatches them. It does not return until a WM_QUIT message is received. If
//! an idle function is supplied, the idle function is called rather than waiting for a message when there are none
//! to be processed.
//!
//! @param	hWnd	Window handle
//! @param	pCB		The address of the idle function to be called when there are no messages to process, or 0.

int MessageLoop(HWND hWnd, MessageLoopIdleCallback pCB /* = 0*/)
{
    bool skipIdle = false;

    while (true)
    {
        MSG msg;

        // If there is no idle function, or the idle function no longer needs to be called, or there is a message
        // waiting, get (or wait for) the next message and process it. Otherwise, call the idle function.

        if (pCB == 0 || skipIdle || PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
        {
            int const rc = GetMessage(&msg, NULL, 0, 0);
            if (rc == -1)
            {
                DWORD const error = GetLastError();
                LPVOID      lpMsgBuf;

                FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                              NULL,
                              error,
                              MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),   // Default language
                              (LPTSTR)&lpMsgBuf,
                              0,
                              NULL);

                // Display the error message.

                MessageBox(NULL, (LPCTSTR)lpMsgBuf, "GetMessage Error", MB_OK | MB_ICONINFORMATION);

                // Free the buffer.
                LocalFree(lpMsgBuf);

                return error;
            }

            else if (rc != 0)
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
            else
            {
                return (int)msg.wParam;
            }

            skipIdle = false;   // Allow the idle function to be called again now that a message has been processed.
        }
        else
        {
            // Call the idle function. If it returns false, it no longer needs to be called -- set 'skipIdle' so it
            // won't be called again until after another message is processed.

            skipIdle = !pCB(hWnd);
        }
    }
}
} // namespace Wx
