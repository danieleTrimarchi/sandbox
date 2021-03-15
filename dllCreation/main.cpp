
#include <iostream>
#include "keylokclass.h"
#include "keylok.h"

int main(int argc, char** argv) {

    CKeylok keylock;
    if (keylock.CheckForKeyLok())
        std::cout << "Dongle found " << std::endl;
    else
        std::cout << "Dongle not found " << std::endl;
    std::cout << "Test OK!" << std::endl;
}
