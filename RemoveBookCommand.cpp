#include "RemoveBookCommand.h"
#include "StringToIntegerConverter.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>

#include "Library.h"

RemoveBookCommand::RemoveBookCommand(std::shared_ptr<Library> library) : Command(library)
{
}

RemoveBookCommand::~RemoveBookCommand()
{
}

const std::string &RemoveBookCommand::getName()
{
    return NAME;
}

void RemoveBookCommand::execute(const Container<std::string> &arguments)
{
    if (arguments.getSize() != 1)
    {
        std::cerr << "Invalid arguments for Remove book command" << std::endl;
        return;
    }
    library->removeBook(arguments.getElement(0));
}
