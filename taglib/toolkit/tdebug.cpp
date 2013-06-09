/***************************************************************************
    copyright            : (C) 2002 - 2008 by Scott Wheeler
    email                : wheeler@kde.org
 ***************************************************************************/

/***************************************************************************
 *   This library is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Lesser General Public License version   *
 *   2.1 as published by the Free Software Foundation.                     *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful, but   *
 *   WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA         *
 *   02110-1301  USA                                                       *
 *                                                                         *
 *   Alternatively, this file is available under the Mozilla Public        *
 *   License Version 1.1.  You may obtain a copy of the License at         *
 *   http://www.mozilla.org/MPL/                                           *
 ***************************************************************************/

#include "config.h"
#include "taglib_config.h"

#include "tdebug.h"
#include "tstring.h"
#include "tdebuglistener.h"

#include <bitset>
#include <cstdio>
#include <cstdarg>

using namespace TagLib;

namespace
{
  String format(const char *fmt, ...)
  {
    va_list args;
    va_start(args, fmt);

    char buf[256];

#if defined(HAVE_SNPRINTF)

    vsnprintf(buf, sizeof(buf), fmt, args);

#elif defined(HAVE_SPRINTF_S)

    vsprintf_s(buf, fmt, args);

#else

    // Be careful. May cause a buffer overflow.  
    vsprintf(buf, fmt, args);

#endif

    va_end(args);

    return String(buf);
  }
}

void TagLib::debug(const String &s)
{
#if !defined(NDEBUG) || defined(TAGLIB_TRACE_IN_RELEASE)
  
  getDebugListener()->printMessage("TagLib: " + s + "\n");

#endif
}

void TagLib::debugData(const ByteVector &v)
{
#if !defined(NDEBUG) || defined(TAGLIB_TRACE_IN_RELEASE)

  for(size_t i = 0; i < v.size(); ++i) 
  {
    String msg 
      = format("*** [%d] - char '%c' - int %d, 0x%02x, 0b", i, v[i], v[i], v[i]);

    std::bitset<8> b(v[i]);
    for(int j = 7; j >= 0; --j) 
      msg += format("%d", (b.test(j) ? 1 : 0));
   
    msg += "\n";

    getDebugListener()->printMessage(msg);
  }

#endif
}
