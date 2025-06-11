#ifndef A_HPP
#define A_HPP

#include <vector>
#include <memory>
#include "Ability.hpp"

class A {
public:
    A(const std::vector<std::shared_ptr<Ability>>& abilities);
    ~A();
    void run();

private:
    std::vector<std::shared_ptr<Ability>> abilities;
};

#endif // A_HPP