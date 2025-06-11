#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>
#include <nlohmann/json.hpp>

class Config {
public:
    Config(const std::string& path);
    nlohmann::json get() const;

private:
    nlohmann::json configData;
};

#endif // CONFIG_HPP