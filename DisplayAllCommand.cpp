#include "DisplayAllCommand.h"
#include "StringToIntegerConverter.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>

#include "Library.h"

DisplayAllCommand::DisplayAllCommand(std::shared_ptr<Library> library) : Command(library)
{
}

DisplayAllCommand::~DisplayAllCommand()
{
}

const std::string &DisplayAllCommand::getName()
{
    return NAME;
}

void DisplayAllCommand::execute(const Container<std::string> &arguments)
{
    if (arguments.getSize() != 1)
    {
        std::cerr << "Invalid arguments for Display all command" << std::endl;
        return;
    }
    library->displayAllContent(arguments.getElement(0));
}
