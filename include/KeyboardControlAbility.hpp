#ifndef KEYBOARD_CONTROL_ABILITY_HPP
#define KEYBOARD_CONTROL_ABILITY_HPP

#include "Ability.hpp"
#include <string>

class KeyboardControlAbility : public Ability {
public:
    void run() override;
    std::string getPurpose() const override;

    void simulateKeyPress(int keycode);
};

#endif // KEYBOARD_CONTROL_ABILITY_HPP