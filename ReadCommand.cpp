#include "ReadCommand.h"
#include "StringToIntegerConverter.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>

#include "Library.h"

ReadCommand::ReadCommand(std::shared_ptr<Library> library) : Command(library)
{
}

ReadCommand::~ReadCommand()
{
}

const std::string &ReadCommand::getName()
{
    return NAME;
}

void ReadCommand::execute(const Container<std::string> &arguments)
{
    if (arguments.getSize() != 2)
    {
        std::cerr << "Invalid arguments for Read command" << std::endl;
        return;
    }
    library->readBook(arguments.getElement(0), arguments.getElement(1));
}
