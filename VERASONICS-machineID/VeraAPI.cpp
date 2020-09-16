
#include "VeraAPI.h"

#include <iostream>
#include <string>
#include <sstream> 

#include <VC_Threads.h>
#include <VH_Dma.h>
#include <VH_DeviceDriver.h>
#include <VH_Hardware.h>
#include <VH_HardwareAdapterPrototypes.h>
#include <VH_HardwarePrototypes.h>
#include <VH_PciSwitchRegisters.h>
#include <parseArgs.h>
#include <getEepromInfo.h>

enum class InfoType
{
    infoType_Generic,
    infoType_Specific,
    infoType_All,
    infoType_Unknown
};

struct GetEepromInfoParams
{
    VH_BoardId m_BoardId = Vh_BrdNone;
    InfoType m_InfoType = InfoType::infoType_Unknown;
    VC_BOOL m_ShowLabels = FALSE;    
};


struct apiStruct {
  VH_HardwareOpenResult hardwareOpenResult = Vh_HardwareOpenResultSuccess;
  GetEepromInfoParams getEepromInfoParams ={};
  std::string lastError; 
  std::string serialNumber; 
};


struct apiStruct* createAPIStruct() {
    return new apiStruct; 
}


void deleteApiStruct(struct apiStruct* api) {
    delete api;
}

const char* getLastError(struct apiStruct* api) {

    return api->lastError.c_str();
}

initApi initVerasonicsAPI(struct apiStruct* api) {

  api->hardwareOpenResult = VH_OpenHardware(FALSE);

  if(api->hardwareOpenResult == Vh_HardwareOpenResultSuccess)
  {
      // Attempt to place the FPGAs in their runtime state
      if(!VH_IsHardwareReady())
      {
          // Attempt to open the hardware with a lock
          api->hardwareOpenResult = VH_OpenHardware(TRUE);
          if(api->hardwareOpenResult == Vh_HardwareOpenResultSuccess)
          {
              VH_LoadFpgaRuntime(FALSE, FALSE);
              return initApi::succeed;
          }
      }
    }
    
    api->lastError = 
        std::string(APP_NAME) + 
        " " GET_EEPROM_INFO_NAME " Error - Failed to open hardware because:\n" 
        + VH_GetHardwareOpenResultAsString(api->hardwareOpenResult) + "\n";

    return initApi::failed;
}


void endVerasonicsAPI() {

  VH_CloseHardware();

}


/*void performGetEepromInfo() {

    VC_BOOL isReady;
    VC_BOOL success;
    struct VH_EepromInfo eepromInfoBuffer;
   
      success = VH_GetEepromInfo(g_GetEepromInfoParams.m_BoardId, &eepromInfoBuffer);
      if(success)
      {
          switch(g_GetEepromInfoParams.m_InfoType)
          {
              case infoType_Generic:
                  printf("EEPROM Status:%s\n"
                         "Name:%s\n"
                         "Part #:%s\n"
                         "Serial #:%s\n"
                         "Manufacturer Date:%s\n"
                         "Manufacturer Part #:%s\n",
                         VH_GetChipStatusAsString(eepromInfoBuffer.ei_EepromState),
                         &eepromInfoBuffer.ei_ModuleName[0],
                         &eepromInfoBuffer.ei_ModulePartNumber[0],
                         &eepromInfoBuffer.ei_SerialNumber[0],
                         &eepromInfoBuffer.ei_DateOfManufacture[0],
                         &eepromInfoBuffer.ei_ManufacturedPartNumber[0]);
                  break;              case infoType_Specific:
                  switch(g_GetEepromInfoParams.m_BoardId)
                  {
                      case Vh_TPC:
                          printf("EEPROM Status:%s\n"
                                 "Profile 1-4 Index:%u\n"
                                 "Profile 5 Index:%u\n",
                                 VH_GetChipStatusAsString(eepromInfoBuffer.ei_EepromState),
                                 eepromInfoBuffer.ei_BoardSpecificValue[Vh_TpcSpecificAttrMaxProfile1to4Index],
                                 eepromInfoBuffer.ei_BoardSpecificValue[Vh_TpcSpecificAttrMaxProfile5Index]);
                          break;
                      case Vh_SHI:
                        printf("EEPROM Status:%s\n"
                 "Connector Style Index:%u\n"
                 "Connector Count:%u\n",
                 VH_GetChipStatusAsString(eepromInfoBuffer.ei_EepromState),
                 eepromInfoBuffer.ei_BoardSpecificValue[Vh_ShiSpecificAttrConnectorStyleIndex],
                 eepromInfoBuffer.ei_BoardSpecificValue[Vh_ShiSpecificAttrConnectorCount]);
					break;
                      case Vh_UTA:
                          printf("EEPROM Status:%s\n"
                                 "Connector Style Index:%u\n"
                                 "Connector Count:%u\n"
                               "Special Features:%u\n",
                                 VH_GetChipStatusAsString(eepromInfoBuffer.ei_EepromState),
                                 eepromInfoBuffer.ei_BoardSpecificValue[Vh_UtaSpecificAttrConnectorStyleIndex],
                                 eepromInfoBuffer.ei_BoardSpecificValue[Vh_UtaSpecificAttrConnectorCount],
                 eepromInfoBuffer.ei_BoardSpecificValue[Vh_UtaSpecificAttrSpecialFeatures]);
                          break;
                      case Vh_BKP:
                          printf("EEPROM Status:%s\n"
                                 "Max Profile 1-4 Index:%u\n"
                                 "Max Profile 5 Index:%u\n"
                                 "HIFU Cap Index:%u\n"
                               "HIFU Amperage Limit Index:%u\n"
                               "Is IIc Supported:%u\n",
                                 VH_GetChipStatusAsString(eepromInfoBuffer.ei_EepromState),
                                 eepromInfoBuffer.ei_BoardSpecificValue[Vh_BkpSpecificAttrMaxProfile1to4Index],
                                 eepromInfoBuffer.ei_BoardSpecificValue[Vh_BkpSpecificAttrMaxProfile5Index],
                                 eepromInfoBuffer.ei_BoardSpecificValue[Vh_BkpSpecificAttrHifuCapacitorIndex],
                 eepromInfoBuffer.ei_BoardSpecificValue[Vh_BkpSpecificAttrHifuAmperageIndex],
                 eepromInfoBuffer.ei_BoardSpecificValue[Vh_BkpSpecificAttrIsIicSupported]);
                          break;
                      case Vh_ACQ1:
                      case Vh_ACQ2:
                      case Vh_ACQ3:
                      case Vh_ACQ4:
                          printf("EEPROM Status:%s\n"
                                 "Max Tx Voltage Index:%u\n"
                                 "Profile 5 Supported:%u\n"
                                 "Tx Circuit Index:%u\n"
                                 "Rx Circuit Index:%u\n"
                                 "Gate Driver Supply Index:%u\n"
                                 "Transceiver Thermal Index:%u\n",
                                 VH_GetChipStatusAsString(eepromInfoBuffer.ei_EepromState),
                                 eepromInfoBuffer.ei_BoardSpecificValue[Vh_AcqSpecificAttrMaxTransmitVoltageIndex],
                                 eepromInfoBuffer.ei_BoardSpecificValue[Vh_AcqSpecificAttrIsProfile5Supported],
                                 eepromInfoBuffer.ei_BoardSpecificValue[Vh_AcqSpecificAttrTransmitCircuitIndex],
                                 eepromInfoBuffer.ei_BoardSpecificValue[Vh_AcqSpecificAttrReceiveCircuitIndex],
                                 eepromInfoBuffer.ei_BoardSpecificValue[Vh_AcqSpecificAttrGateDriverSupplyCurrentIndex],
                                 eepromInfoBuffer.ei_BoardSpecificValue[Vh_AcqSpecificAttrTransceiverThermalIndex]);
                          break;
                      default:
                          break;
                  }
                  break;
              case infoType_All:
                  switch(g_GetEepromInfoParams.m_BoardId)
                  {
                      case Vh_TPC:
                          printf("EEPROM Status:%s\n"
                                 "Name:%s\n"
                                 "Part #:%s\n"
                                 "Serial #:%s\n"
                                 "Manufacturer Date:%s\n"
                                 "Manufacturer Part #:%s\n"
                                 "Profile 1-4 Index:%u\n"
                                 "Profile 5 Index:%u\n",
                                 VH_GetChipStatusAsString(eepromInfoBuffer.ei_EepromState),
                                 &eepromInfoBuffer.ei_ModuleName[0],
                                 &eepromInfoBuffer.ei_ModulePartNumber[0],
                                 &eepromInfoBuffer.ei_SerialNumber[0],
                                 &eepromInfoBuffer.ei_DateOfManufacture[0],
                                 &eepromInfoBuffer.ei_ManufacturedPartNumber[0],
                                 eepromInfoBuffer.ei_BoardSpecificValue[Vh_TpcSpecificAttrMaxProfile1to4Index],
                                 eepromInfoBuffer.ei_BoardSpecificValue[Vh_TpcSpecificAttrMaxProfile5Index]);
                          break;
                      case Vh_SHI:
                        printf("EEPROM Status:%s\n"
                 "Name:%s\n"
                 "Part #:%s\n"
                 "Serial #:%s\n"
                 "Manufacturer Date:%s\n"
                 "Manufacturer Part #:%s\n"
                 "Connector Style Index:%u\n"
                 "Connector Count:%u\n",
                 VH_GetChipStatusAsString(eepromInfoBuffer.ei_EepromState),
                 &eepromInfoBuffer.ei_ModuleName[0],
                 &eepromInfoBuffer.ei_ModulePartNumber[0],
                 &eepromInfoBuffer.ei_SerialNumber[0],
                 &eepromInfoBuffer.ei_DateOfManufacture[0],
                 &eepromInfoBuffer.ei_ManufacturedPartNumber[0],
                 eepromInfoBuffer.ei_BoardSpecificValue[Vh_ShiSpecificAttrConnectorStyleIndex],
                 eepromInfoBuffer.ei_BoardSpecificValue[Vh_ShiSpecificAttrConnectorCount]);
                        break;
                      case Vh_UTA:
                          printf("EEPROM Status:%s\n"
                                 "Name:%s\n"
                                 "Part #:%s\n"
                                 "Serial #:%s\n"
                                 "Manufacturer Date:%s\n"
                                 "Manufacturer Part #:%s\n"
                                 "Connector Style Index:%u\n"
                                 "Connector Count:%u\n"
                               "Special Features:%u\n",
                                 VH_GetChipStatusAsString(eepromInfoBuffer.ei_EepromState),
                                 &eepromInfoBuffer.ei_ModuleName[0],
                                 &eepromInfoBuffer.ei_ModulePartNumber[0],
                                 &eepromInfoBuffer.ei_SerialNumber[0],
                                 &eepromInfoBuffer.ei_DateOfManufacture[0],
                                 &eepromInfoBuffer.ei_ManufacturedPartNumber[0],
                                 eepromInfoBuffer.ei_BoardSpecificValue[Vh_UtaSpecificAttrConnectorStyleIndex],
                                 eepromInfoBuffer.ei_BoardSpecificValue[Vh_UtaSpecificAttrConnectorCount],
                 eepromInfoBuffer.ei_BoardSpecificValue[Vh_UtaSpecificAttrSpecialFeatures]);
                          break;
                      case Vh_BKP:
                          printf("EEPROM Status:%s\n"
                                 "Name:%s\n"
                                 "Part #:%s\n"
                                 "Serial #:%s\n"
                                 "Manufacturer Date:%s\n"
                                 "Manufacturer Part #:%s\n"
                                 "Max Profile 1-4 Index:%u\n"
                                 "Max Profile 5 Index:%u\n"
                                 "HIFU Cap Index:%u\n"
                               "HIFU Amperage Limit Index:%u\n"
                 "Is IIc Supported:%u\n",
                                 VH_GetChipStatusAsString(eepromInfoBuffer.ei_EepromState),
                                 &eepromInfoBuffer.ei_ModuleName[0],
                                 &eepromInfoBuffer.ei_ModulePartNumber[0],
                                 &eepromInfoBuffer.ei_SerialNumber[0],
                                 &eepromInfoBuffer.ei_DateOfManufacture[0],
                                 &eepromInfoBuffer.ei_ManufacturedPartNumber[0],
                                 eepromInfoBuffer.ei_BoardSpecificValue[Vh_BkpSpecificAttrMaxProfile1to4Index],
                                 eepromInfoBuffer.ei_BoardSpecificValue[Vh_BkpSpecificAttrMaxProfile5Index],
                                 eepromInfoBuffer.ei_BoardSpecificValue[Vh_BkpSpecificAttrHifuCapacitorIndex],
                 eepromInfoBuffer.ei_BoardSpecificValue[Vh_BkpSpecificAttrHifuAmperageIndex],
                 eepromInfoBuffer.ei_BoardSpecificValue[Vh_BkpSpecificAttrIsIicSupported]);
                          break;
                      case Vh_ACQ1:
                      case Vh_ACQ2:
                      case Vh_ACQ3:
                      case Vh_ACQ4:
                          printf("EEPROM Status:%s\n"
                                 "Name:%s\n"
                                 "Part #:%s\n"
                                 "Serial #:%s\n"
                                 "Manufacturer Date:%s\n"
                                 "Manufacturer Part #:%s\n"
                                 "Max Tx Voltage Index:%u\n"
                                 "Profile 5 Supported:%u\n"
                                 "Tx Circuit Index:%u\n"
                                 "Rx Circuit Index:%u\n"
                                 "Gate Driver Supply Index:%u\n"
                                 "Transceiver Thermal Index:%u\n",
                                 VH_GetChipStatusAsString(eepromInfoBuffer.ei_EepromState),
                                 &eepromInfoBuffer.ei_ModuleName[0],
                                 &eepromInfoBuffer.ei_ModulePartNumber[0],
                                 &eepromInfoBuffer.ei_SerialNumber[0],
                                 &eepromInfoBuffer.ei_DateOfManufacture[0],
                                 &eepromInfoBuffer.ei_ManufacturedPartNumber[0],
                                 eepromInfoBuffer.ei_BoardSpecificValue[Vh_AcqSpecificAttrMaxTransmitVoltageIndex],
                                 eepromInfoBuffer.ei_BoardSpecificValue[Vh_AcqSpecificAttrIsProfile5Supported],
                                 eepromInfoBuffer.ei_BoardSpecificValue[Vh_AcqSpecificAttrTransmitCircuitIndex],
                                 eepromInfoBuffer.ei_BoardSpecificValue[Vh_AcqSpecificAttrReceiveCircuitIndex],
                                 eepromInfoBuffer.ei_BoardSpecificValue[Vh_AcqSpecificAttrGateDriverSupplyCurrentIndex],
                                 eepromInfoBuffer.ei_BoardSpecificValue[Vh_AcqSpecificAttrTransceiverThermalIndex]);
                          break;
                      default:
                          break;
                  }
                  break;
              default:
                  break;
        }
    }
}*/

const char* getMachineSN(struct apiStruct* api) {

    if(api ==  nullptr)
        return nullptr;

    struct VH_EepromInfo eepromInfoBuffer;
    if (VH_GetEepromInfo(api->getEepromInfoParams.m_BoardId, &eepromInfoBuffer)){
        api->serialNumber = eepromInfoBuffer.ei_SerialNumber;
        return api->serialNumber.c_str(); 
    }
    
    return nullptr;
}
