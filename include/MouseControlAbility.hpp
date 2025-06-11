#ifndef MOUSE_CONTROL_ABILITY_HPP
#define MOUSE_CONTROL_ABILITY_HPP

#include "Ability.hpp"
#include <string>

class MouseControlAbility : public Ability {
public:
    void run() override;
    std::string getPurpose() const override;

    void moveMouse(int x, int y);
};

#endif // MOUSE_CONTROL_ABILITY_HPP