#include "hellolib/IAnimal.hpp"
#include "hellolib/Cow.hpp"

#include <sstream>

#include <gtest/gtest.h>

using namespace hellolib;


/*
* @ brief test that the cow says moo
* @ detail Procedure: Create a cow
*                     Ask the cow to speak
*          Expected: The cow will indeed say "Moo"
*/
TEST(TestDeserialize, plainData)
{
    std::unique_ptr<IAnimal> cow{new Cow()};
    
    std::ostringstream out;
    cow->speak(out);
    EXPECT_EQ(out.str(), "Moo\n");
}