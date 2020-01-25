#include "RemoveCommand.h"
#include "StringToIntegerConverter.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>

#include "Library.h"

RemoveCommand::RemoveCommand(std::shared_ptr<Library> library) : Command(library)
{
}

RemoveCommand::~RemoveCommand()
{
}

const std::string &RemoveCommand::getName()
{
    return NAME;
}

void RemoveCommand::execute(const Container<std::string> &arguments)
{
    if (arguments.getSize() != 1)
    {
        std::cerr << "Invalid arguments for Remove command" << std::endl;
        return;
    }
    library->removePerson(arguments.getElement(0));
}
