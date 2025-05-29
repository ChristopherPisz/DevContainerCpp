#include "hellolib/Cow.hpp"

#include <iostream>


int main(int argc, char ** argv)
{
    std::cout << "Howdy Ya'll. The Cow says: " << std::endl;

    hellolib::Cow bessy;
    bessy.speak(std::cout);

    return 0;
}
