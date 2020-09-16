#include <iostream>
//#include "VeraAPI.h"
#include "VeraAPI.hpp"

int main() {

	try {
		VeraSonics::VeraAPI api; 
		std::cout << api.getMachineSN() << std::endl; 

	} catch (std::exception& e){
		std::cout<<"Exception caught:\n"<<e.what() << std::endl;
	}

	return 0;
}

