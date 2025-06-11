#include "Config.hpp"
#include <fstream>

Config::Config(const std::string& path) {
    std::ifstream file(path);
    if (file.is_open()) {
        file >> configData;
    }
}

nlohmann::json Config::get() const {
    return configData;
}