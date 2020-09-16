#ifndef VERA_API_HPP
#define VERA_API_HPP

#include "VeraAPI.h"
#include <string>
#include <stdexcept>

namespace VeraSonics {

	class VeraAPI {

		public: 

			VeraAPI():
			 api(::createAPIStruct()) 
			{
				if( ::initVerasonicsAPI(api) != initApi::succeed )
					throw std::runtime_error( 	std::string("The Verasonics API could not be initialised: \n") +
												::getLastError(api));
			}

			~VeraAPI() {
				::endVerasonicsAPI();
				::deleteApiStruct(api);
			}

			std::string getMachineSN() {
				const char* machineSN = ::getMachineSN(api);
				if(machineSN==nullptr)
					throw std::runtime_error( std::string("\nERROR= ") + ::getLastError(api) );
		  		else
		  			return machineSN; 
			}
	

		private: 
			struct apiStruct* api;

	}; 

}

#endif