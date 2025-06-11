#include "OSInfoAbility.hpp"
#include <iostream>

#if defined(_WIN32)
    #define OS_NAME "Windows"
#elif defined(__APPLE__) && defined(__MACH__)
    #define OS_NAME "macOS"
#elif defined(__linux__)
    #define OS_NAME "Linux"
#elif defined(__unix__)
    #define OS_NAME "Unix"
#else
    #define OS_NAME "Unknown"
#endif

void OSInfoAbility::run() {
    std::cout << "Running on: " << OS_NAME << std::endl;
}

std::string OSInfoAbility::getPurpose() const {
    return "Detect OS information";
}