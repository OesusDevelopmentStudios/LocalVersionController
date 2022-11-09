#pragma once

#include <string>
#include <vector>

namespace lvc
{

namespace enums
{
//enum class ECommand;
//enum class EOption;
}

namespace input
{

struct Option
{
    int option;
    std::string longName;
    std::string shortName;

    Option(int option, std::string longName, std::string shortName)
        : option(option)
        , longName(longName)
        , shortName(shortName)
    {}

    friend bool operator==(const Option &o1, const Option &o2)
    {
        return o1.option == o2.option 
            || o1.longName == o2.longName
            || o1.shortName == o2.shortName;
    }
};

struct Command
{
    int operation;
    std::string longName;
    std::string shortName;
    std::vector<Option> options;

    Command(int operation, std::string longName, std::string shortName, std::vector<Option> options)
        : operation(operation)
        , longName(longName)
        , shortName(shortName)
        , options(options)
    {}

    friend bool operator==(const Command &c1, const Command &c2)
    {
        return c1.operation == c2.operation 
            || c1.longName == c2.longName
            || c1.shortName == c2.shortName;
    }
};

class InputParser
{
public:
    InputParser();

    int parse(int argc, char** args);
private:
    void addCommand(int operation, std::string longName, std::string shortName, std::vector<Option> options);
    void addOption(int option, std::string longName, std::string shortName);
    void registerCommands();
    void registerOptions();

    std::vector<Command> commands_;
    std::vector<Option> options_;
};

}  // namespace input
}  // namespace lvc
