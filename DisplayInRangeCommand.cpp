#include "DisplayInRangeCommand.h"
#include "StringToIntegerConverter.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>

#include "Library.h"

DisplayInRangeCommand::DisplayInRangeCommand(std::shared_ptr<Library> library) : Command(library)
{
}

DisplayInRangeCommand::~DisplayInRangeCommand()
{
}

const std::string &DisplayInRangeCommand::getName()
{
    return NAME;
}

void DisplayInRangeCommand::execute(const Container<std::string> &arguments)
{
    if (arguments.getSize() != 3)
    {
        std::cerr << "Invalid arguments for Display in range command" << std::endl;
        return;
    }
    library->dislpayContentInRange(arguments.getElement(0), StringToIntegerConverter::convert(arguments.getElement(1)), StringToIntegerConverter::convert(arguments.getElement(2)));
}
