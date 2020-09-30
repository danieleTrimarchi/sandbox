
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

#include <Windows.h>

enum class InfoType
{
    infoType_Generic,
    infoType_Specific,
    infoType_All,
    infoType_Unknown
};

struct GetEepromInfoParams
{
    VH_BoardId m_BoardId = Vh_SHI;
    InfoType m_InfoType = InfoType::infoType_Specific;
    VC_BOOL m_ShowLabels = FALSE;    
};


struct apiStruct {
  HINSTANCE hDLL;               // Handle to DLL
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

typedef enum VH_HardwareOpenResult(VH_CALL* PFN_VH_OpenHardware)(VC_BOOL);
typedef VC_BOOL (VH_CALL* PFN_VH_IsHardwareReady)();
typedef enum VH_HardwareResult (VH_CALL* PFN_VH_LoadFpgaRuntime)(VC_BOOL, VC_BOOL);
typedef const char* (VH_CALL* PFN_VH_GetHardwareOpenResultAsString)(enum VH_HardwareOpenResult);
typedef VC_BOOL (VH_CALL* PFN_VH_CloseHardware)();
typedef VC_BOOL(VH_CALL* PFN_VH_GetEepromInfo)(enum VH_BoardId,struct VH_EepromInfo*);

#define LOAD_FCN_PTR(dll,fname) \
    PFN_##fname fname##_fun = (PFN_##fname)GetProcAddress(dll, #fname); \
    if (!fname##_fun) \
        throw std::runtime_error(#fname " in libVerasonicsHal-NG could not be loaded.");

initApi initVerasonicsAPI(struct apiStruct* api) {

    api->hDLL = LoadLibrary("libVerasonicsHal-NG");
    if (api->hDLL != NULL)
    {
        // Load : VH_CALL VH_OpenHardware(VC_BOOL exclusiveMode);
        LOAD_FCN_PTR(api->hDLL, VH_OpenHardware); 
        LOAD_FCN_PTR(api->hDLL, VH_IsHardwareReady);
        LOAD_FCN_PTR(api->hDLL, VH_LoadFpgaRuntime);
        LOAD_FCN_PTR(api->hDLL, VH_GetHardwareOpenResultAsString);

        api->hardwareOpenResult = VH_OpenHardware_fun(FALSE);

        if (api->hardwareOpenResult == Vh_HardwareOpenResultSuccess)
        {
            // Attempt to place the FPGAs in their runtime state
            if (!VH_IsHardwareReady_fun())
            {
                // Attempt to open the hardware with a lock
                api->hardwareOpenResult = VH_OpenHardware_fun(TRUE);
                if (api->hardwareOpenResult == Vh_HardwareOpenResultSuccess)
                {
                    VH_LoadFpgaRuntime_fun(FALSE, FALSE);
                    return initApi::succeed;
                }
            }
            else
                return initApi::succeed;
        }

        api->lastError =
            std::string(APP_NAME) +
            " " GET_EEPROM_INFO_NAME " Error - Failed to open hardware because:\n"
            + VH_GetHardwareOpenResultAsString_fun(api->hardwareOpenResult) + "\n";

        return initApi::failed;
    }

    throw std::runtime_error("libVerasonicsHal-NG could not be loaded.");
    return initApi::failed;
}


void endVerasonicsAPI(struct apiStruct* api) {

    if (api->hDLL != NULL) {
        LOAD_FCN_PTR(api->hDLL, VH_CloseHardware);
        VH_CloseHardware_fun();

        FreeLibrary(api->hDLL);
    }
}

const char* getMachineSN(struct apiStruct* api) {


    if(api ==  nullptr || api->hDLL != NULL){
        throw std::runtime_error("NO API in getMachineSN");
        return nullptr;
    }

    struct VH_EepromInfo eepromInfoBuffer;
    
    LOAD_FCN_PTR(api->hDLL, VH_GetEepromInfo);
    VC_BOOL success = VH_GetEepromInfo_fun(api->getEepromInfoParams.m_BoardId, &eepromInfoBuffer);
    if (success){
        api->serialNumber = eepromInfoBuffer.ei_SerialNumber;
        return api->serialNumber.c_str(); 
    }
    else  {
        throw std::runtime_error("NO success in getMachineSN");
    }

    return nullptr;
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

