/*
 *  Copyright (C) 2016-2018 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#pragma once

#include "Savestate.h"
#include "SavestateDatabase.h"

#include <stdint.h>
#include <string>

namespace KODI
{
namespace GAME
{
  class CGameClient;
  class IMemoryStream;

  class CSavestateReader
  {
  public:
    ~CSavestateReader();

    bool Initialize(const std::string& path, const CGameClient* gameClient);
    bool ReadSave(IMemoryStream* memoryStream);
    uint64_t GetFrameCount(void) const { return m_frameCount; }

  private:
    CSavestate         m_savestate;
    CSavestateDatabase m_db;
    uint64_t           m_frameCount = 0;
  };
}
}
