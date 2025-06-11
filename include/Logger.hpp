#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <mutex>
#include <fstream>

class Logger {
public:
    Logger(const std::string& filePath);
    ~Logger();

    void log(const std::string& message);

private:
    std::mutex logMutex;
    std::ofstream logFile;
};

#endif // LOGGER_HPP