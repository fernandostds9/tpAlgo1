// Version del 5/11/2018
// IGNACIO HERRERA 274/18
// FERNANDO REGERT 282/15


#include <iostream>
#include "gtest/gtest.h"

int main(int argc, char **argv) {
    std::cout << "Implementando TPI!!" << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}