#ifndef HELLOLIB_BASEANIMAL_HPP
#define HELLOLIB_BASEANIMAL_HPP

#include "hellolib/IAnimal.hpp"

#include <ostream>

namespace hellolib
{

class BaseAnimal : public IAnimal
{
public:
    BaseAnimal() = default;
    BaseAnimal(unsigned int numLegs);
    virtual ~BaseAnimal() = default;

    std::ostream & speak(std::ostream & out) override;

protected:
    unsigned int m_numLegs;
};

}

#endif