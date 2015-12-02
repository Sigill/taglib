/***************************************************************************
    copyright           : (C) 2011 by Mathias Panzenböck
    email               : grosser.meister.morti@gmx.net
 ***************************************************************************/

/***************************************************************************
 *   This library is free software; you can redistribute it and/or modify  *
 *   it  under the terms of the GNU Lesser General Public License version  *
 *   2.1 as published by the Free Software Foundation.                     *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful, but   *
 *   WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,            *
 *   MA  02110-1301  USA                                                   *
 ***************************************************************************/

#ifndef TAGLIB_ITPROPERTIES_H
#define TAGLIB_ITPROPERTIES_H

#include "taglib.h"
#include "audioproperties.h"

namespace TagLib {
  namespace IT {
    class TAGLIB_EXPORT Properties : public AudioProperties {
      friend class File;
    public:
      /*! Flag bits. */
      enum {
        Stereo                  =   1,
        Vol0MixOptimizations    =   2,
        UseInstruments          =   4,
        LinearSlides            =   8,
        OldEffects              =  16,
        LinkEffects             =  32,
        UseMidiPitchController  =  64,
        RequestEmbeddedMidiConf = 128
      };

      /*! Special bits. */
      enum {
        MessageAttached  = 1,
        MidiConfEmbedded = 8
      };

      Properties(AudioProperties::ReadStyle propertiesStyle);
      virtual ~Properties();

      int length()               const;
      int lengthInSeconds()      const;
      int lengthInMilliseconds() const;
      int bitrate()              const;
      int sampleRate()           const;
      int channels()             const;

      ushort lengthInPatterns()  const;
      bool   stereo()            const;
      ushort instrumentCount()   const;
      ushort sampleCount()       const;
      ushort patternCount()      const;
      ushort version()           const;
      ushort compatibleVersion() const;
      ushort flags()             const;
      ushort special()           const;
      unsigned char  globalVolume()      const;
      unsigned char  mixVolume()         const;
      unsigned char  tempo()             const;
      unsigned char  bpmSpeed()          const;
      unsigned char  panningSeparation() const;
      unsigned char  pitchWheelDepth()   const;

      void setChannels(int channels);
      void setLengthInPatterns(ushort lengthInPatterns);
      void setInstrumentCount(ushort instrumentCount);
      void setSampleCount (ushort sampleCount);
      void setPatternCount(ushort patternCount);
      void setVersion     (ushort version);
      void setCompatibleVersion(ushort compatibleVersion);
      void setFlags       (ushort flags);
      void setSpecial     (ushort special);
      void setGlobalVolume(unsigned char globalVolume);
      void setMixVolume   (unsigned char mixVolume);
      void setTempo       (unsigned char tempo);
      void setBpmSpeed    (unsigned char bpmSpeed);
      void setPanningSeparation(unsigned char panningSeparation);
      void setPitchWheelDepth  (unsigned char pitchWheelDepth);

    private:
      Properties(const Properties&);
      Properties &operator=(const Properties&);

      class PropertiesPrivate;
      PropertiesPrivate *d;
    };
  }
}

#endif
