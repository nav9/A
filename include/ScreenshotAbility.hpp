#ifndef SCREENSHOT_ABILITY_HPP
#define SCREENSHOT_ABILITY_HPP

#include "Ability.hpp"
#include <string>
#include <vector>

class ScreenshotAbility : public Ability {
public:
    void run() override;
    std::string getPurpose() const override;

private:
    std::vector<unsigned char> lastScreenshot;
};

#endif // SCREENSHOT_ABILITY_HPP