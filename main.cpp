#include "A.hpp"
#include "OSInfoAbility.hpp"
#include "SystemMonitorAbility.hpp"
#include "ScreenshotAbility.hpp"
#include "MouseControlAbility.hpp"
#include "KeyboardControlAbility.hpp"
#include "WindowManagerAbility.hpp"
#include <memory>

int main() {
    std::vector<std::shared_ptr<Ability>> abilities;
    abilities.push_back(std::make_shared<OSInfoAbility>());
    abilities.push_back(std::make_shared<SystemMonitorAbility>());
    abilities.push_back(std::make_shared<ScreenshotAbility>());
    abilities.push_back(std::make_shared<MouseControlAbility>());
    abilities.push_back(std::make_shared<KeyboardControlAbility>());
    abilities.push_back(std::make_shared<WindowManagerAbility>());    

    A agent(abilities);
    agent.run();

    return 0;
}
