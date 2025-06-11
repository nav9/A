#ifndef SYSTEM_MONITOR_ABILITY_HPP
#define SYSTEM_MONITOR_ABILITY_HPP

#include "Ability.hpp"
#include <string>

class SystemMonitorAbility : public Ability {
public:
    void run() override;
    std::string getPurpose() const override;
};

#endif // SYSTEM_MONITOR_ABILITY_HPP