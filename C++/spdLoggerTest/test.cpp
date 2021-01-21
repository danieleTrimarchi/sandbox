#include <iostream> 
#include "spdlog/spdlog.h"
#include<windows.h>

namespace spd = spdlog;

void main(int argc, char** argv) {

    HANDLE  hConsole;
    int k;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // you can loop k higher to see more color choices
    while (true) {
        Sleep(1000);

        for (k = 0; k < 256; k++)    
        {
            // pick the colorattribute k you want
            SetConsoleTextAttribute(hConsole, k);
            std::cout << k << " I want to be nice today!" << std::endl;

            // reset the logging
            SetConsoleTextAttribute(hConsole, 0);

        }
    }
}

/*void main(int argc, char** argv){

	std::cout << "Hello,world\n";
	std::cout << "argv[0]= "<< argv[1] << std::endl; 

    auto console = spd::stdout_color_mt(argv[1]);

    while (true) {
        Sleep(1000);
        console->info("Welcome to spdlog!");
        console->error("Some error message with arg{}..", 1);

        console->warn("simple warning message");
        console->warn("Easy padding in numbers like {:08d}", 12);
        console->critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
        console->info("Support for floats {:03.2f}", 1.23456);
        console->info("Positional args are {1} {0}..", "too", "supported");
        console->info("{:<30}", "left aligned");
    }

    spd::get("console")->info("loggers can be retrieved from a global registry using the spdlog::get(logger_name) function");

    // --------------------------------------------------
    // Create basic file logger (not rotated)
    auto my_logger = spd::basic_logger_mt("basic_logger", "basic-log.txt");
    my_logger->flush_on(spdlog::level::trace);

    spdlog::set_level(spdlog::level::trace);

    my_logger->trace("A new trace message");
    my_logger->debug("A new debug message");
    my_logger->info("A new info message");
    my_logger->warn("A new warn message");
    my_logger->error("A new error message");
    my_logger->critical("A new critical message");
    
    // --------------------------------------------------
    // Create a file rotating logger with 5mb size max and 3 rotated files
//    auto rotating_logger = spd::rotating_logger_mt("some_logger_name", "logs/rotating.txt", 1048576 * 5, 3);
//    for (int i = 0; i < 10; ++i)
//    {
//        rotating_logger->info("{} * {} equals {:>10}", i, i, i * i);
//    }


}
*/