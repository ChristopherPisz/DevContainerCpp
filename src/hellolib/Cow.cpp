#include "hellolib/Cow.hpp"

#include <ostream>

namespace hellolib
{

Cow::Cow()
    : BaseAnimal(NUM_LEGS)
{}

std::ostream & Cow::speak(std::ostream & out)
{
    return out << "Moo" << std::endl;
}

}