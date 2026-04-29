#include "hellolib/Cow.hpp"

#include <iostream>

struct Poop {
    int x;
    int y;
};

int main(/*int argc, char **argv*/) {
    std::cout << "Howdy Ya'll. The Cow says: \n";

    hellolib::Cow bessy;
    bessy.speak(std::cout);
    std::cout << std::flush;

    return 0;
}
