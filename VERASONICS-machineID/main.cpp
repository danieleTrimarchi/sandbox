#include <iostream>
#include <string>

#include <VH_Hardware.h>
#include <VC_Threads.h>

#include <VH_PciSwitchRegisters.h>
#include <parseArgs.h>
#include <VH_HardwarePrototypes.h>
#include <getBoardStatus.h>

int main() {

	std::cout<<"hello, world"<<std::endl;
    // VH_OpenHardware implemented in D:\VERASONICS\vantageCloned-4.2.0-2001220500-srcs\dev-libs\hal-lib\c-lib\src\VH_Hardware.c
    // it lives in HAL-NG 'C' Shared Library." : System/libVerasonicsHal-NG.dll
    //                                           System/   VerasonicsHal-NG.lib
    enum VH_HardwareOpenResult hardwareOpenResult;
    hardwareOpenResult = VH_OpenHardware(FALSE);  // false means read-only, we are only doing queries
		
	// Generate our status string
	std::string status( VH_GetHardwareOpenResultAsString(hardwareOpenResult) );
	std::cout << "VERASONICS HARDWARE OPEN STATUS: \n\t" << status << std::endl;
	
    if(hardwareOpenResult == Vh_HardwareOpenResultSuccess) {

		std::cout<<"Hardware open Success!";
		
		// This comes from : getBoardStatus.c :: performGetBoardStatus
		enum VH_BoardStatus boardStatus;
		boardStatus = VH_GetBoardStatus(VH_BoardId::Vh_SHI);
			
 		printf("%s Status:%s\n",
           VH_GetBoardIdAsAbbrString(VH_BoardId::Vh_SHI),
           VH_GetBoardStatusAsString(boardStatus));

		if( VH_IsBoardDetected(VH_BoardId::Vh_SHI) || 
			VH_IsBoardReady(VH_BoardId::Vh_SHI)  || 
			VH_IsBoardReadyAndCalibrated(VH_BoardId::Vh_SHI) ) {
			
/* 				chipStatus =  Hardware.getChipStatus(brdId, ChipId.eeprom);
				eepromInfo = Hardware.getEepromInfo(brdId);
				SN_verasonic = char(eepromInfo.serialNumber);
 */			
				status = VH_GetChipStatus(VH_BoardId::Vh_SHI, Vh_ChipEeprom);
				VC_BOOL result = VH_GetEepromInfo(VH_BoardId::Vh_SHI, NULL);

			}

		VH_CloseHardware();

	} else { 

		// This comes from : getBoardStatus.c :: performGetBoardStatus
         printf(APP_NAME " " GET_BOARD_STATUS_NAME " Error - Failed to open hardware because:%s\n", VH_GetHardwareOpenResultAsString(hardwareOpenResult));

	}

	return 0;
}

