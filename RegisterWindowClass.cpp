/** @file *//********************************************************************************************************

                                               RegisterWindowClass.cpp

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Wx/RegisterWindowClass.cpp#7 $

	$NoKeywords: $

 ********************************************************************************************************************/

#include "PrecompiledHeaders.h"

#include "Wx.h"


namespace Wx
{


/********************************************************************************************************************/
/*																													*/
/********************************************************************************************************************/

//!
//! @param	all		See the documentation for @c WNDCLASSEX for the meaning of each parameter.

ATOM RegisterWindowClass(	UINT		style, 
							WNDPROC		lpfnWndProc, 
							HINSTANCE	hInstance, 
							LPCTSTR		lpszClassName,
							HCURSOR		hCursor			/* = NULL*/, 
							HBRUSH		hbrBackground	/* = NULL*/, 
							HICON		hIcon			/* = NULL*/, 
							HICON		hIconSm			/* = NULL*/,
							LPCTSTR		lpszMenuName	/* = NULL*/, 
							int			cbClsExtra		/* = 0*/, 
							int			cbWndExtra		/* = 0*/ ) 
{
	WNDCLASSEX	wc;

	wc.cbSize			= sizeof( WNDCLASSEX );
	wc.style			= style; 
	wc.lpfnWndProc		= lpfnWndProc; 
	wc.cbClsExtra		= cbClsExtra; 
	wc.cbWndExtra		= cbWndExtra; 
	wc.hInstance		= hInstance; 
	wc.hIcon			= hIcon; 
	wc.hCursor			= hCursor; 
	wc.hbrBackground	= hbrBackground; 
	wc.lpszMenuName		= lpszMenuName; 
	wc.lpszClassName	= lpszClassName;
	wc.hIconSm			= hIconSm; 

	return RegisterClassEx( &wc );
}



} // namespace Wx