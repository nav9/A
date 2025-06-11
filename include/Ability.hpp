#ifndef ABILITY_HPP
#define ABILITY_HPP

#include <string>

class Ability {
public:
    virtual ~Ability() = default;
    virtual void run() = 0;
    virtual std::string getPurpose() const = 0;
};

#endif // ABILITY_HPP