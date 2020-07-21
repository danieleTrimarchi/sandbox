#include <iostream> 
#include <string>
#include <fstream> 

void f(std::ofstream& of) {
	std::string msg("myMsg");
	of << msg;
	of.flush();
	std::string msg2("myMsg2");
	of << msg;
	of.flush();
}

void fnew(std::ofstream& of) {
	std::string msg("myMsgNew");
	of << msg;
	of.flush();
	std::string msg2("myMsgNew2");
	of << msg;
	of.flush();
}

void main(){

	std::cout << "Hello,world\n";
	std::ofstream ofsOld;
	std::ofstream ofsNew;
	ofsOld.open("checkRegionOld.txt", std::ofstream::out | std::ofstream::trunc);
	ofsNew.open("checkRegionNew.txt", std::ofstream::out | std::ofstream::trunc);

	f(ofsOld);
	fnew(ofsNew);

	ofsOld.close();
	ofsNew.close();
}
