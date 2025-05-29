#ifndef HELLOLIB_IANIMAL_HPP
#define HELLOLIB_IANIMAL_HPP

#include <ostream>

namespace hellolib
{

/*
* @brief Animal interface
*/
class IAnimal
{
public:
    virtual std::ostream & speak(std::ostream & out) = 0;
};

}

#endif