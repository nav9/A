#ifndef OSINFO_ABILITY_HPP
#define OSINFO_ABILITY_HPP

#include "Ability.hpp"
#include <string>

class OSInfoAbility : public Ability {
public:
    void run() override;
    std::string getPurpose() const override;
};

#endif // OSINFO_ABILITY_HPP