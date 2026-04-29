#ifndef HELLOLIB_IANIMAL_HPP
#define HELLOLIB_IANIMAL_HPP

#include <ostream>

namespace hellolib {

/*
 * @brief Animal interface
 */
class IAnimal {
  public:
    IAnimal() = default;
    virtual ~IAnimal() = default;

    IAnimal(const IAnimal &) = delete;
    IAnimal &operator=(const IAnimal &) = delete;
    IAnimal(IAnimal &&) = delete;
    IAnimal &operator=(IAnimal &&) = delete;

    virtual std::ostream &speak(std::ostream &out) = 0;
};

} // namespace hellolib

#endif