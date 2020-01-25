#include "DisplayFromRowCommand.h"
#include "StringToIntegerConverter.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>

#include "Library.h"

DisplayFromRowCommand::DisplayFromRowCommand(std::shared_ptr<Library> library) : Command(library)
{
}

DisplayFromRowCommand::~DisplayFromRowCommand()
{
}

const std::string &DisplayFromRowCommand::getName()
{
    return NAME;
}

void DisplayFromRowCommand::execute(const Container<std::string> &arguments)
{
    if (arguments.getSize() != 2)
    {
        std::cerr << "Invalid arguments for Display from row command" << std::endl;
        return;
    }
    library->displayContentFromRowTillEnd(arguments.getElement(0), StringToIntegerConverter::convert(arguments.getElement(1)));
}
