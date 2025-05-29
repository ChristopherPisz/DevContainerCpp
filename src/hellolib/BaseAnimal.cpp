#include "hellolib/BaseAnimal.hpp"

#include <ostream>

namespace hellolib
{

BaseAnimal::BaseAnimal(unsigned int numLegs)
    : IAnimal()
    , m_numLegs(numLegs)
{}

std::ostream & BaseAnimal::speak(std::ostream & out)
{
    return out << "Generic animal noises" << std::endl;
}

}