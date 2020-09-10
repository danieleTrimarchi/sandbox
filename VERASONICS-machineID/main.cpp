#include <iostream>
#include <string>

#include <VH_Hardware.h>
#include <VC_Threads.h>

#include <VH_PciSwitchRegisters.h>
#include <parseArgs.h>
#include <VH_HardwarePrototypes.h>

/*---------------------------------------------------------------------------------------
// This code comes from : VERASONICS\dev-apps\c-hwdiag-app
// Actually it can be seriously simplified to simply return VH_BoardId::Vh_SHI
char * BoardNames[] = {"TPC", "SHI", "BKP", "ACQ1", "ACQ2", "ACQ3", "ACQ4", "UTA", "ALL"};

enum VH_BoardId getBoardFromName(const char *boardName)
{
    int result = -1;
    int i, numBoards;

    if(boardName != NULL)
    {
        numBoards = VH_MAX_NUM_BOARDS;
        for(i = 0; i < numBoards; i++)
        {
            if(strcasecmp(boardName, BoardNames[i]) == 0)
            {
                result = i;
                break;
            }
        }
    }
    return result;
}*/
/*---------------------------------------------------------------------------------------*/

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
	
	switch(hardwareOpenResult){
		case Vh_HardwareOpenResultSuccess :
			std::cout<<"Hardware open Success!";
			enum VH_BoardId boardId = VH_BoardId::Vh_SHI;
			
			//todo: (this is matlab to be translated) 
		//	brdStatus = Hardware.getBoardStatus(brdId);
			
			break;
		
		case Vh_HardwareOpenResultFailedBecauseHardwareAdapterNotActivated : 
			std::cout<<"Hardware not activated!";
			break; 		
		default: 
			std::cout<<"Other case";
	}
	
	return 0;
}

