/** @file *//********************************************************************************************************

                                                      Debug.cpp

						                    Copyright 2004, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/Wx/Debug.cpp#4 $

	$NoKeywords: $

 ********************************************************************************************************************/

#include "PrecompiledHeaders.h"

#include "Wx.h"

using namespace std;


#if defined( _DEBUG )

//!
//! @param	hDC		Device context

void Wx::DumpDeviceCaps( HDC hDC )
{
	ostringstream	message;

	message << "Device Caps:" << endl
			<< "    DRIVERVERSION = " << GetDeviceCaps( hDC, DRIVERVERSION ) << endl
			<< "    TECHNOLOGY = " << GetDeviceCaps( hDC, TECHNOLOGY ) << endl
			<< "    HORZSIZE = " << GetDeviceCaps( hDC, HORZSIZE ) << endl
			<< "    VERTSIZE = " << GetDeviceCaps( hDC, VERTSIZE ) << endl
			<< "    HORZRES = " << GetDeviceCaps( hDC, HORZRES ) << endl
			<< "    VERTRES = " << GetDeviceCaps( hDC, VERTRES ) << endl
			<< "    LOGPIXELSX = " << GetDeviceCaps( hDC, LOGPIXELSX ) << endl
			<< "    LOGPIXELSY = " << GetDeviceCaps( hDC, LOGPIXELSY ) << endl
			<< "    BITSPIXEL = " << GetDeviceCaps( hDC, BITSPIXEL ) << endl
			<< "    PLANES = " << GetDeviceCaps( hDC, PLANES ) << endl
			<< "    NUMBRUSHES = " << GetDeviceCaps( hDC, NUMBRUSHES ) << endl
			<< "    NUMPENS = " << GetDeviceCaps( hDC, NUMPENS ) << endl
			<< "    NUMFONTS = " << GetDeviceCaps( hDC, NUMFONTS ) << endl
			<< "    NUMCOLORS = " << GetDeviceCaps( hDC, NUMCOLORS ) << endl
			<< "    ASPECTX = " << GetDeviceCaps( hDC, ASPECTX ) << endl
			<< "    ASPECTY = " << GetDeviceCaps( hDC, ASPECTY ) << endl
			<< "    ASPECTXY = " << GetDeviceCaps( hDC, ASPECTXY ) << endl
			<< "    PDEVICESIZE = " << GetDeviceCaps( hDC, PDEVICESIZE ) << endl
			<< "    CLIPCAPS = " << GetDeviceCaps( hDC, CLIPCAPS ) << endl
			<< "    SIZEPALETTE = " << GetDeviceCaps( hDC, SIZEPALETTE ) << endl
			<< "    NUMRESERVED = " << GetDeviceCaps( hDC, NUMRESERVED ) << endl
			<< "    COLORRES = " << GetDeviceCaps( hDC, COLORRES ) << endl
			<< "    PHYSICALWIDTH = " << GetDeviceCaps( hDC, PHYSICALWIDTH ) << endl
			<< "    PHYSICALHEIGHT = " << GetDeviceCaps( hDC, PHYSICALHEIGHT ) << endl
			<< "    PHYSICALOFFSETX = " << GetDeviceCaps( hDC, PHYSICALOFFSETX ) << endl
			<< "    PHYSICALOFFSETY = " << GetDeviceCaps( hDC, PHYSICALOFFSETY ) << endl
			<< "    VREFRESH = " << GetDeviceCaps( hDC, VREFRESH ) << endl
			<< "    SCALINGFACTORX = " << GetDeviceCaps( hDC, SCALINGFACTORX ) << endl
			<< "    SCALINGFACTORY = " << GetDeviceCaps( hDC, SCALINGFACTORY ) << endl
			<< "    BLTALIGNMENT = " << GetDeviceCaps( hDC, BLTALIGNMENT ) << endl;
	message << "    SHADEBLENDCAPS = (" << GetDeviceCaps( hDC, SHADEBLENDCAPS ) << ")";
	if ( ( GetDeviceCaps( hDC, SHADEBLENDCAPS ) & SB_CONST_ALPHA ) != 0 ) { message << " SB_CONST_ALPHA"; }
	if ( ( GetDeviceCaps( hDC, SHADEBLENDCAPS ) & SB_GRAD_RECT ) != 0 ) { message << " SB_GRAD_RECT"; }
	if ( ( GetDeviceCaps( hDC, SHADEBLENDCAPS ) & SB_GRAD_TRI ) != 0 ) { message << " SB_GRAD_TRI"; }
	if ( ( GetDeviceCaps( hDC, SHADEBLENDCAPS ) & SB_PIXEL_ALPHA ) != 0 ) { message << " SB_PIXEL_ALPHA"; }
	if ( ( GetDeviceCaps( hDC, SHADEBLENDCAPS ) & SB_PREMULT_ALPHA ) != 0 ) { message << " SB_PREMULT_ALPHA"; }
	message << endl;
	message << "    RASTERCAPS = (" << GetDeviceCaps( hDC, RASTERCAPS ) << ")";
	if ( ( GetDeviceCaps( hDC, RASTERCAPS ) & RC_BANDING ) != 0 ) { message << " RC_BANDING"; }
	if ( ( GetDeviceCaps( hDC, RASTERCAPS ) & RC_BITBLT ) != 0 ) { message << " RC_BITBLT"; }
	if ( ( GetDeviceCaps( hDC, RASTERCAPS ) & RC_BITMAP64 ) != 0 ) { message << " RC_BITMAP64"; }
	if ( ( GetDeviceCaps( hDC, RASTERCAPS ) & RC_DI_BITMAP ) != 0 ) { message << " RC_DI_BITMAP"; }
	if ( ( GetDeviceCaps( hDC, RASTERCAPS ) & RC_DIBTODEV ) != 0 ) { message << " RC_DIBTODEV"; }
	if ( ( GetDeviceCaps( hDC, RASTERCAPS ) & RC_FLOODFILL ) != 0 ) { message << " RC_FLOODFILL"; }
	if ( ( GetDeviceCaps( hDC, RASTERCAPS ) & RC_PALETTE ) != 0 ) { message << " RC_PALETTE"; }
	if ( ( GetDeviceCaps( hDC, RASTERCAPS ) & RC_SCALING ) != 0 ) { message << " RC_SCALING"; }
	if ( ( GetDeviceCaps( hDC, RASTERCAPS ) & RC_STRETCHBLT ) != 0 ) { message << " RC_STRETCHBLT"; }
	if ( ( GetDeviceCaps( hDC, RASTERCAPS ) & RC_STRETCHDIB ) != 0 ) { message << " RC_STRETCHDIB"; }
	message << endl;
	message << "    CURVECAPS = (" << GetDeviceCaps( hDC, CURVECAPS ) << ")";
	if ( ( GetDeviceCaps( hDC, CURVECAPS ) & CC_CHORD ) != 0 ) { message << " CC_CHORD"; }
	if ( ( GetDeviceCaps( hDC, CURVECAPS ) & CC_CIRCLES ) != 0 ) { message << " CC_CIRCLES"; }
	if ( ( GetDeviceCaps( hDC, CURVECAPS ) & CC_ELLIPSES ) != 0 ) { message << " CC_ELLIPSES"; }
	if ( ( GetDeviceCaps( hDC, CURVECAPS ) & CC_INTERIORS ) != 0 ) { message << " CC_INTERIORS"; }
	if ( ( GetDeviceCaps( hDC, CURVECAPS ) & CC_PIE ) != 0 ) { message << " CC_PIE"; }
	if ( ( GetDeviceCaps( hDC, CURVECAPS ) & CC_ROUNDRECT ) != 0 ) { message << " CC_ROUNDRECT"; }
	if ( ( GetDeviceCaps( hDC, CURVECAPS ) & CC_STYLED ) != 0 ) { message << " CC_STYLED"; }
	if ( ( GetDeviceCaps( hDC, CURVECAPS ) & CC_WIDE ) != 0 ) { message << " CC_WIDE"; }
	if ( ( GetDeviceCaps( hDC, CURVECAPS ) & CC_WIDESTYLED ) != 0 ) { message << " CC_WIDESTYLED"; }
	message << endl;
	message << "    LINECAPS = (" << GetDeviceCaps( hDC, LINECAPS ) << ")";
	if ( ( GetDeviceCaps( hDC, LINECAPS ) & LC_INTERIORS ) != 0 ) { message << " LC_INTERIORS"; }
	if ( ( GetDeviceCaps( hDC, LINECAPS ) & LC_MARKER ) != 0 ) { message << " LC_MARKER"; }
	if ( ( GetDeviceCaps( hDC, LINECAPS ) & LC_POLYLINE ) != 0 ) { message << " LC_POLYLINE"; }
	if ( ( GetDeviceCaps( hDC, LINECAPS ) & LC_POLYMARKER ) != 0 ) { message << " LC_POLYMARKER"; }
	if ( ( GetDeviceCaps( hDC, LINECAPS ) & LC_STYLED ) != 0 ) { message << " LC_STYLED"; }
	if ( ( GetDeviceCaps( hDC, LINECAPS ) & LC_WIDE ) != 0 ) { message << " LC_WIDE"; }
	if ( ( GetDeviceCaps( hDC, LINECAPS ) & LC_WIDESTYLED ) != 0 ) { message << " LC_WIDESTYLED"; }
	message << endl;
	message << "    POLYGONALCAPS = (" << GetDeviceCaps( hDC, POLYGONALCAPS ) << ")";
	if ( ( GetDeviceCaps( hDC, POLYGONALCAPS ) & PC_INTERIORS ) != 0 ) { message << " PC_INTERIORS"; }
	if ( ( GetDeviceCaps( hDC, POLYGONALCAPS ) & PC_POLYGON ) != 0 ) { message << " PC_POLYGON"; }
	if ( ( GetDeviceCaps( hDC, POLYGONALCAPS ) & PC_RECTANGLE ) != 0 ) { message << " PC_RECTANGLE"; }
	if ( ( GetDeviceCaps( hDC, POLYGONALCAPS ) & PC_SCANLINE ) != 0 ) { message << " PC_SCANLINE"; }
	if ( ( GetDeviceCaps( hDC, POLYGONALCAPS ) & PC_STYLED ) != 0 ) { message << " PC_STYLED"; }
	if ( ( GetDeviceCaps( hDC, POLYGONALCAPS ) & PC_WIDE ) != 0 ) { message << " PC_WIDE"; }
	if ( ( GetDeviceCaps( hDC, POLYGONALCAPS ) & PC_WIDESTYLED ) != 0 ) { message << " PC_WIDESTYLED"; }
	if ( ( GetDeviceCaps( hDC, POLYGONALCAPS ) & PC_WINDPOLYGON ) != 0 ) { message << " PC_WINDPOLYGON"; }
	message << endl;
	message << "    TEXTCAPS = (" << GetDeviceCaps( hDC, TEXTCAPS ) << ")";
	if ( ( GetDeviceCaps( hDC, TEXTCAPS ) & TC_OP_CHARACTER ) != 0 ) { message << " TC_OP_CHARACTER"; }
	if ( ( GetDeviceCaps( hDC, TEXTCAPS ) & TC_OP_STROKE ) != 0 ) { message << " TC_OP_STROKE"; }
	if ( ( GetDeviceCaps( hDC, TEXTCAPS ) & TC_CP_STROKE ) != 0 ) { message << " TC_CP_STROKE"; }
	if ( ( GetDeviceCaps( hDC, TEXTCAPS ) & TC_CR_90 ) != 0 ) { message << " TC_CR_90"; }
	if ( ( GetDeviceCaps( hDC, TEXTCAPS ) & TC_CR_ANY ) != 0 ) { message << " TC_CR_ANY"; }
	if ( ( GetDeviceCaps( hDC, TEXTCAPS ) & TC_SF_X_YINDEP ) != 0 ) { message << " TC_SF_X_YINDEP"; }
	if ( ( GetDeviceCaps( hDC, TEXTCAPS ) & TC_SA_DOUBLE ) != 0 ) { message << " TC_SA_DOUBLE"; }
	if ( ( GetDeviceCaps( hDC, TEXTCAPS ) & TC_SA_INTEGER ) != 0 ) { message << " TC_SA_INTEGER"; }
	if ( ( GetDeviceCaps( hDC, TEXTCAPS ) & TC_SA_CONTIN ) != 0 ) { message << " TC_SA_CONTIN"; }
	if ( ( GetDeviceCaps( hDC, TEXTCAPS ) & TC_EA_DOUBLE ) != 0 ) { message << " TC_EA_DOUBLE"; }
	if ( ( GetDeviceCaps( hDC, TEXTCAPS ) & TC_IA_ABLE ) != 0 ) { message << " TC_IA_ABLE"; }
	if ( ( GetDeviceCaps( hDC, TEXTCAPS ) & TC_UA_ABLE ) != 0 ) { message << " TC_UA_ABLE"; }
	if ( ( GetDeviceCaps( hDC, TEXTCAPS ) & TC_SO_ABLE ) != 0 ) { message << " TC_SO_ABLE"; }
	if ( ( GetDeviceCaps( hDC, TEXTCAPS ) & TC_RA_ABLE ) != 0 ) { message << " TC_RA_ABLE"; }
	if ( ( GetDeviceCaps( hDC, TEXTCAPS ) & TC_VA_ABLE ) != 0 ) { message << " TC_VA_ABLE"; }
	if ( ( GetDeviceCaps( hDC, TEXTCAPS ) & TC_SCROLLBLT ) != 0 ) { message << " TC_SCROLLBLT"; }
	message << endl;
	message << "    COLORMGMTCAPS = (" << GetDeviceCaps( hDC, COLORMGMTCAPS ) << ")";
	if ( ( GetDeviceCaps( hDC, COLORMGMTCAPS ) & CM_CMYK_COLOR ) != 0 ) { message << " CM_CMYK_COLOR"; }
	if ( ( GetDeviceCaps( hDC, COLORMGMTCAPS ) & CM_DEVICE_ICM ) != 0 ) { message << " CM_DEVICE_ICM"; }
	if ( ( GetDeviceCaps( hDC, COLORMGMTCAPS ) & CM_GAMMA_RAMP ) != 0 ) { message << " CM_GAMMA_RAMP"; }
	message << endl;
	OutputDebugString( message.str().c_str() );
}


#endif // defined( _DEBUG )
