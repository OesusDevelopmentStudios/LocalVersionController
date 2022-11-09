#include "input/InputParser.hpp"

#include <algorithm>
#include <iostream>

#include <enums/ECommand.hpp>
#include <enums/EOption.hpp>

namespace lvc::input
{

InputParser::InputParser()
{
    registerOptions();
    registerCommands();
}

int InputParser::parse(int argc, char** args)
{
    for (int i=0; i<argc; i++)
    {
        std::cout << args[i] << std::endl;
    }

    return argc;
}

void InputParser::addCommand(int operation, std::string longName, std::string shortName, std::vector<Option> options)
{
    Command command(operation, longName, shortName, options);

    if (std::find(commands_.begin(), commands_.end(), command) != commands_.end())
    {
        std::cout << "Not a valid command - operation/shortName/longName already in use" << std::endl;
    }
    else
    {
        commands_.push_back(command);
    }
}

void InputParser::addOption(int option, std::string longName, std::string shortName)
{
    //TODO
}

void InputParser::registerCommands()
{
    addCommand(1, "push", "ph", {});
    addCommand(2, "status", "st", {});
    addCommand(3, "pull", "pl", {});
}

void InputParser::registerOptions()
{
    //TODO
}

}  // namespace::input
