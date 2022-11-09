#include <iostream>

#include "input/InputParser.hpp"

int main(int argc, char** argv)
{
    lvc::input::InputParser inputParser;
    inputParser.parse(argc, argv);

    return 0;
}