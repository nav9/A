#include "Logger.hpp"
#include <chrono>
#include <ctime>

Logger::Logger(const std::string& filePath) {
    logFile.open(filePath, std::ios::app);
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

void Logger::log(const std::string& message) {
    std::lock_guard<std::mutex> lock(logMutex);
    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    logFile << std::ctime(&now) << ": " << message << std::endl;
}