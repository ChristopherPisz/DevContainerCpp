#ifndef HELLOLIB_COW_HPP
#define HELLOLIB_COW_HPP

#include "hellolib/BaseAnimal.hpp"

#include <ostream>

namespace hellolib
{

class Cow : public BaseAnimal
{
public:
    const unsigned NUM_LEGS = 4;

    Cow();
    virtual ~Cow() = default;

    std::ostream & speak(std::ostream & out) override;
};

}

#endif