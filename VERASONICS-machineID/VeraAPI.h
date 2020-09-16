#ifndef VERA_API_H
#define VERA_API_H

#ifdef __cplusplus
extern "C" {
#endif


#ifdef BUILDING_EXAMPLE_DLL
#define DLLSPEC __declspec(dllexport)
#else
#define DLLSPEC __declspec(dllimport)
#endif

struct apiStruct;

//struct apiStruct* DLLSPEC initVerasonicsAPI(); 
struct apiStruct* DLLSPEC initVerasonicsAPI(); 
void DLLSPEC endVerasonicsAPI(struct apiStruct*); 

const char* DLLSPEC getLastError(struct apiStruct* apistruct);

//void DLLSPEC performGetEepromInfo(); 

const char* DLLSPEC getMachineSN(struct apiStruct* apistruct);


#ifdef __cplusplus
} // end extern "C"
#endif


#endif 
