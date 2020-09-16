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

struct apiStruct* DLLSPEC createAPIStruct();
void DLLSPEC deleteApiStruct(struct apiStruct*);

initApi DLLSPEC initVerasonicsAPI(struct apiStruct*); 
void DLLSPEC endVerasonicsAPI(); 

const char* DLLSPEC getLastError(struct apiStruct*);

//void DLLSPEC performGetEepromInfo(); 

const char* DLLSPEC getMachineSN(struct apiStruct*);


#ifdef __cplusplus
} // end extern "C"
#endif


#endif 
