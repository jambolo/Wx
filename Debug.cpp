#include "Wx.h"

#include <sstream>

#if defined(_DEBUG)

static void appendIfSet(std::ostringstream & message, HDC hDC, int index, DWORD bit, char const * name)
{
    if ((GetDeviceCaps(hDC, index) & bit) != 0)
        message << " " << name;
}
#define APPEND_IF_SET(message, hDC, index, bit) appendIfSet(message, hDC, index, bit, #bit)

//!
//! @param	hDC		Device context

void Wx::DumpDeviceCaps(HDC hDC)
{
    std::ostringstream message;

    message << "Device Caps:" << std::endl
            << "    DRIVERVERSION = " << GetDeviceCaps(hDC, DRIVERVERSION) << std::endl
            << "    TECHNOLOGY = " << GetDeviceCaps(hDC, TECHNOLOGY) << std::endl
            << "    HORZSIZE = " << GetDeviceCaps(hDC, HORZSIZE) << std::endl
            << "    VERTSIZE = " << GetDeviceCaps(hDC, VERTSIZE) << std::endl
            << "    HORZRES = " << GetDeviceCaps(hDC, HORZRES) << std::endl
            << "    VERTRES = " << GetDeviceCaps(hDC, VERTRES) << std::endl
            << "    LOGPIXELSX = " << GetDeviceCaps(hDC, LOGPIXELSX) << std::endl
            << "    LOGPIXELSY = " << GetDeviceCaps(hDC, LOGPIXELSY) << std::endl
            << "    BITSPIXEL = " << GetDeviceCaps(hDC, BITSPIXEL) << std::endl
            << "    PLANES = " << GetDeviceCaps(hDC, PLANES) << std::endl
            << "    NUMBRUSHES = " << GetDeviceCaps(hDC, NUMBRUSHES) << std::endl
            << "    NUMPENS = " << GetDeviceCaps(hDC, NUMPENS) << std::endl
            << "    NUMFONTS = " << GetDeviceCaps(hDC, NUMFONTS) << std::endl
            << "    NUMCOLORS = " << GetDeviceCaps(hDC, NUMCOLORS) << std::endl
            << "    ASPECTX = " << GetDeviceCaps(hDC, ASPECTX) << std::endl
            << "    ASPECTY = " << GetDeviceCaps(hDC, ASPECTY) << std::endl
            << "    ASPECTXY = " << GetDeviceCaps(hDC, ASPECTXY) << std::endl
            << "    PDEVICESIZE = " << GetDeviceCaps(hDC, PDEVICESIZE) << std::endl
            << "    CLIPCAPS = " << GetDeviceCaps(hDC, CLIPCAPS) << std::endl
            << "    SIZEPALETTE = " << GetDeviceCaps(hDC, SIZEPALETTE) << std::endl
            << "    NUMRESERVED = " << GetDeviceCaps(hDC, NUMRESERVED) << std::endl
            << "    COLORRES = " << GetDeviceCaps(hDC, COLORRES) << std::endl
            << "    PHYSICALWIDTH = " << GetDeviceCaps(hDC, PHYSICALWIDTH) << std::endl
            << "    PHYSICALHEIGHT = " << GetDeviceCaps(hDC, PHYSICALHEIGHT) << std::endl
            << "    PHYSICALOFFSETX = " << GetDeviceCaps(hDC, PHYSICALOFFSETX) << std::endl
            << "    PHYSICALOFFSETY = " << GetDeviceCaps(hDC, PHYSICALOFFSETY) << std::endl
            << "    VREFRESH = " << GetDeviceCaps(hDC, VREFRESH) << std::endl
            << "    SCALINGFACTORX = " << GetDeviceCaps(hDC, SCALINGFACTORX) << std::endl
            << "    SCALINGFACTORY = " << GetDeviceCaps(hDC, SCALINGFACTORY) << std::endl
            << "    BLTALIGNMENT = " << GetDeviceCaps(hDC, BLTALIGNMENT) << std::endl;
    message << "    SHADEBLENDCAPS = (" << GetDeviceCaps(hDC, SHADEBLENDCAPS) << ")";
    APPEND_IF_SET(message, hDC, SHADEBLENDCAPS, SB_CONST_ALPHA);
    APPEND_IF_SET(message, hDC, SHADEBLENDCAPS, SB_GRAD_RECT);
    APPEND_IF_SET(message, hDC, SHADEBLENDCAPS, SB_GRAD_TRI);
    APPEND_IF_SET(message, hDC, SHADEBLENDCAPS, SB_PIXEL_ALPHA);
    APPEND_IF_SET(message, hDC, SHADEBLENDCAPS, SB_PREMULT_ALPHA);
    message << std::endl;

    message << "    RASTERCAPS = (" << GetDeviceCaps(hDC, RASTERCAPS) << ")";
    APPEND_IF_SET(message, hDC, RASTERCAPS, RC_BANDING);
    APPEND_IF_SET(message, hDC, RASTERCAPS, RC_BITBLT);
    APPEND_IF_SET(message, hDC, RASTERCAPS, RC_BITMAP64);
    APPEND_IF_SET(message, hDC, RASTERCAPS, RC_DI_BITMAP);
    APPEND_IF_SET(message, hDC, RASTERCAPS, RC_DIBTODEV);
    APPEND_IF_SET(message, hDC, RASTERCAPS, RC_FLOODFILL);
    APPEND_IF_SET(message, hDC, RASTERCAPS, RC_PALETTE);
    APPEND_IF_SET(message, hDC, RASTERCAPS, RC_SCALING);
    APPEND_IF_SET(message, hDC, RASTERCAPS, RC_STRETCHBLT);
    APPEND_IF_SET(message, hDC, RASTERCAPS, RC_STRETCHDIB);
    message << std::endl;

    message << "    CURVECAPS = (" << GetDeviceCaps(hDC, CURVECAPS) << ")";
    APPEND_IF_SET(message, hDC, CURVECAPS, CC_CHORD);
    APPEND_IF_SET(message, hDC, CURVECAPS, CC_CIRCLES);
    APPEND_IF_SET(message, hDC, CURVECAPS, CC_ELLIPSES);
    APPEND_IF_SET(message, hDC, CURVECAPS, CC_INTERIORS);
    APPEND_IF_SET(message, hDC, CURVECAPS, CC_PIE);
    APPEND_IF_SET(message, hDC, CURVECAPS, CC_ROUNDRECT);
    APPEND_IF_SET(message, hDC, CURVECAPS, CC_STYLED);
    APPEND_IF_SET(message, hDC, CURVECAPS, CC_WIDE);
    APPEND_IF_SET(message, hDC, CURVECAPS, CC_WIDESTYLED);
    message << std::endl;

    message << "    LINECAPS = (" << GetDeviceCaps(hDC, LINECAPS) << ")";
    APPEND_IF_SET(message, hDC, LINECAPS, LC_INTERIORS);
    APPEND_IF_SET(message, hDC, LINECAPS, LC_MARKER);
    APPEND_IF_SET(message, hDC, LINECAPS, LC_POLYLINE);
    APPEND_IF_SET(message, hDC, LINECAPS, LC_POLYMARKER);
    APPEND_IF_SET(message, hDC, LINECAPS, LC_STYLED);
    APPEND_IF_SET(message, hDC, LINECAPS, LC_WIDE);
    APPEND_IF_SET(message, hDC, LINECAPS, LC_WIDESTYLED);
    message << std::endl;

    message << "    POLYGONALCAPS = (" << GetDeviceCaps(hDC, POLYGONALCAPS) << ")";
    APPEND_IF_SET(message, hDC, POLYGONALCAPS, PC_INTERIORS);
    APPEND_IF_SET(message, hDC, POLYGONALCAPS, PC_POLYGON);
    APPEND_IF_SET(message, hDC, POLYGONALCAPS, PC_RECTANGLE);
    APPEND_IF_SET(message, hDC, POLYGONALCAPS, PC_SCANLINE);
    APPEND_IF_SET(message, hDC, POLYGONALCAPS, PC_STYLED);
    APPEND_IF_SET(message, hDC, POLYGONALCAPS, PC_WIDE);
    APPEND_IF_SET(message, hDC, POLYGONALCAPS, PC_WIDESTYLED);
    APPEND_IF_SET(message, hDC, POLYGONALCAPS, PC_WINDPOLYGON);
    message << std::endl;

    message << "    TEXTCAPS = (" << GetDeviceCaps(hDC, TEXTCAPS) << ")";
    APPEND_IF_SET(message, hDC, TEXTCAPS, TC_OP_CHARACTER);
    APPEND_IF_SET(message, hDC, TEXTCAPS, TC_OP_STROKE);
    APPEND_IF_SET(message, hDC, TEXTCAPS, TC_CP_STROKE);
    APPEND_IF_SET(message, hDC, TEXTCAPS, TC_CR_90);
    APPEND_IF_SET(message, hDC, TEXTCAPS, TC_CR_ANY);
    APPEND_IF_SET(message, hDC, TEXTCAPS, TC_SF_X_YINDEP);
    APPEND_IF_SET(message, hDC, TEXTCAPS, TC_SA_DOUBLE);
    APPEND_IF_SET(message, hDC, TEXTCAPS, TC_SA_INTEGER);
    APPEND_IF_SET(message, hDC, TEXTCAPS, TC_SA_CONTIN);
    APPEND_IF_SET(message, hDC, TEXTCAPS, TC_EA_DOUBLE);
    APPEND_IF_SET(message, hDC, TEXTCAPS, TC_IA_ABLE);
    APPEND_IF_SET(message, hDC, TEXTCAPS, TC_UA_ABLE);
    APPEND_IF_SET(message, hDC, TEXTCAPS, TC_SO_ABLE);
    APPEND_IF_SET(message, hDC, TEXTCAPS, TC_RA_ABLE);
    APPEND_IF_SET(message, hDC, TEXTCAPS, TC_VA_ABLE);
    APPEND_IF_SET(message, hDC, TEXTCAPS, TC_SCROLLBLT);
    message << std::endl;

    message << "    COLORMGMTCAPS = (" << GetDeviceCaps(hDC, COLORMGMTCAPS) << ")";
    APPEND_IF_SET(message, hDC, COLORMGMTCAPS, CM_CMYK_COLOR);
    APPEND_IF_SET(message, hDC, COLORMGMTCAPS, CM_DEVICE_ICM);
    APPEND_IF_SET(message, hDC, COLORMGMTCAPS, CM_GAMMA_RAMP);
    message << std::endl;

    OutputDebugString(message.str().c_str());
}

#endif // defined( _DEBUG )
