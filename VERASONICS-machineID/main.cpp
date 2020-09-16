#include <iostream>
# include "VeraAPI.h"

int main() {

	struct apiStruct* api = initVerasonicsAPI();

  	if(getLastError(api) == nullptr)
	  	std::cout << "Returned machine id: " << getMachineSN(api) << std::endl; 
	else
		std::cout << "\nERROR= " << getLastError(api) << std::endl;

	endVerasonicsAPI(api);

	return 0;
}

