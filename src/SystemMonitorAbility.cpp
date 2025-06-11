#include "SystemMonitorAbility.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

void SystemMonitorAbility::run() {
    std::ifstream statFile("/proc/self/stat");
    if (!statFile) {
        std::cerr << "Failed to open /proc/self/stat\n";
        return;
    }

    std::string line;
    std::getline(statFile, line);
    std::istringstream iss(line);
    std::string token;
    for (int i = 0; i < 24; ++i) {
        iss >> token;
    }

    std::cout << "Memory usage estimate (vmRSS): " << token << " KB\n";
}

std::string SystemMonitorAbility::getPurpose() const {
    return "Monitor system resource usage";
}