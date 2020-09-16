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

enum initApi {
	succeed,
	failed
};

DLLSPEC struct apiStruct*  createAPIStruct();
DLLSPEC void  deleteApiStruct(struct apiStruct*);

DLLSPEC initApi  initVerasonicsAPI(struct apiStruct*); 
DLLSPEC void  endVerasonicsAPI(); 

DLLSPEC const char*  getLastError(struct apiStruct*);

DLLSPEC //void  performGetEepromInfo(); 

DLLSPEC const char*  getMachineSN(struct apiStruct*);


#ifdef __cplusplus
} // end extern "C"
#endif


#endif 
