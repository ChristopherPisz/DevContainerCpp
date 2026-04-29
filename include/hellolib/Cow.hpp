#ifndef HELLOLIB_COW_HPP
#define HELLOLIB_COW_HPP

#include "hellolib/BaseAnimal.hpp"

#include <ostream>

namespace hellolib {

class Cow : public BaseAnimal {
  public:
    static const unsigned NUM_LEGS = 4;

    Cow();
    ~Cow() override = default;

    Cow(const Cow &) = delete;
    Cow &operator=(const Cow &) = delete;
    Cow(const Cow &&) = delete;
    Cow &operator=(const Cow &&) = delete;

    std::ostream &speak(std::ostream &out) override;
};

} // namespace hellolib

#endif