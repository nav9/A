#ifndef WINDOW_MANAGER_ABILITY_HPP
#define WINDOW_MANAGER_ABILITY_HPP

#include "Ability.hpp"
#include <string>

class WindowManagerAbility : public Ability {
public:
    void run() override;
    std::string getPurpose() const override;

    void listWindows();
    void moveWindow(unsigned long windowId, int x, int y);
};

#endif // WINDOW_MANAGER_ABILITY_HPP