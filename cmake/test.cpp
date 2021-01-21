#include <iostream> 

#include <filesystem>
namespace fs = std::filesystem; 

void main(int argc, char** argv){

	std::cout << "Hello,world\n";
	std::cout << "argv[0]= "<< argv[0] << std::endl; 

	char basePath[255] = "";
	_fullpath(basePath, argv[0], sizeof(basePath));
	std::cout << "basePath= " << basePath << std::endl;

	// Get the executable path without the executable name
	 fs::path absPath(fs::absolute(fs::path(argv[0])));
	 std::cout << "fsPath2= " << absPath << std::endl;

	while (true) {

	}
	try {
		throw("Some message!");
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	catch (...) {
		std::cout << "unknown exception caught" << std::endl;
	}
}
