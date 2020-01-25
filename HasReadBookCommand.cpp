#include "HasReadBookCommand.h"
#include "StringToIntegerConverter.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>

#include "Library.h"

HasReadBookCommand::HasReadBookCommand(std::shared_ptr<Library> library) : Command(library)
{
}

HasReadBookCommand::~HasReadBookCommand()
{
}

const std::string &HasReadBookCommand::getName()
{
    return NAME;
}

void HasReadBookCommand::execute(const Container<std::string> &arguments)
{
    if (arguments.getSize() != 2)
    {
        std::cerr << "Invalid arguments for Has read book command" << std::endl;
        return;
    }
    library->hasReadBook(arguments.getElement(0), arguments.getElement(1));
}
