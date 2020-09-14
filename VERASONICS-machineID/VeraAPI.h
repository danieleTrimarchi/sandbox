#ifndef VERA_API_H
#define VERA_API_H

#include <string>

#include <VC_Threads.h>
#include <VH_Dma.h>
#include <VH_DeviceDriver.h>
#include <VH_Hardware.h>
#include <VH_HardwareAdapterPrototypes.h>
#include <VH_HardwarePrototypes.h>
#include <VH_PciSwitchRegisters.h>
#include <parseArgs.h>
#include <getEepromInfo.h>


class VeraAPI {

public: 

  enum InfoType
  {
      infoType_Generic,
      infoType_Specific,
      infoType_All,
      infoType_Unknown
  };

  struct GetEepromInfoParams
  {
      enum VH_BoardId m_BoardId;
      enum InfoType m_InfoType;
      VC_BOOL m_ShowLabels;
  };

  GetEepromInfoParams g_GetEepromInfoParams;


  void performGetEepromInfo(); 

};

#endif 