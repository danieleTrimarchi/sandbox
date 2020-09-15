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


void DLLSPEC performGetEepromInfo(); 


#ifdef __cplusplus
} // end extern "C"
#endif

#endif 
