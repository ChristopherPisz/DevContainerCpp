#ifndef HELLOLIB_BASEANIMAL_HPP
#define HELLOLIB_BASEANIMAL_HPP

#include "hellolib/IAnimal.hpp"

#include <ostream>

namespace hellolib {

class BaseAnimal : public IAnimal {
  public:
    BaseAnimal() = default;
    explicit BaseAnimal(unsigned int numLegs);

    std::ostream &speak(std::ostream &out) override;

  protected:
    unsigned int m_numLegs = 0;
};

} // namespace hellolib

#endif