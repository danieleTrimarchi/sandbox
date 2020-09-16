#include <iostream>
//#include "VeraAPI.h"
#include "VeraAPI.hpp"

int main() {

	/*struct apiStruct* api = createAPIStruct(); 
	initApi result = initVerasonicsAPI(api);

	if(result==initApi::succeed) {
	
		const char* machineSN = getMachineSN(api);
		if(machineSN==nullptr)
			std::cout << "\nERROR= " << getLastError(api) << std::endl;
  		else
  			std::cout << "Returned machine id: " << machineSN << std::endl; 
	
	} else {
  			std::cout << "The Verasonics API could not be initialised: \n" << 
  			getLastError(api) << std::endl; 		
	}

	endVerasonicsAPI();
	deleteApiStruct(api);
*/
	try {
		VeraSonics::VeraAPI api; 
		std::cout << api.getMachineSN() << std::endl; 
	} catch (std::exception& e){
		std::cout<< e.what() << std::endl;
	} 

	return 0;
}

