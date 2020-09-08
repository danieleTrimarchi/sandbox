#include <iostream>
#include <VC_Threads.h>
#include <VH_HardwarePrototypes.h>

void main() {

	std::cout<<"hello, world"<<std::endl;
    // VH_OpenHardware implemented in D:\VERASONICS\vantageCloned-4.2.0-2001220500-srcs\dev-libs\hal-lib\c-lib\src\VH_Hardware.c
    // it lives in HAL-NG 'C' Shared Library." : System/libVerasonicsHal-NG.dll
    //                                           System/   VerasonicsHal-NG.lib
    enum VH_HardwareOpenResult hardwareOpenResult;
    hardwareOpenResult = VH_OpenHardware(FALSE); 
    
    
}