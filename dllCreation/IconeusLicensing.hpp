#ifndef ICONEUS_LICENSING_H
#define ICONEUS_LICENSING_H

//#include <boost/program_options.hpp>
//namespace po = boost::program_options;
#include "keylok.h"
#include "keylokclass.h"
#include <string>

#ifndef NOBUILD
	#define DLLLicSPEC __declspec(dllexport)
#else
	#define DLLLicSPEC __declspec(dllimport)
#endif

static inline const std::string help("help");


class IconeusLicensing {

public:

	DLLLicSPEC IconeusLicensing();

	//po::options_description DLLLicSPEC getDesc();

	DLLLicSPEC ~IconeusLicensing() =default;

private:

	//po::options_description desc_;
	//po::variables_map vm_;
	CKeylok keyLock_;

};

#endif