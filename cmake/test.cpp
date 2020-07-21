#include <iostream> 

void main(){

	std::cout << "Hello,world\n";
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
