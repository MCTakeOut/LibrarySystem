#include "HasWrittenBookCommand.h"
#include "StringToIntegerConverter.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>

#include "Library.h"

HasWrittenBookCommand::HasWrittenBookCommand(std::shared_ptr<Library> library) : Command(library)
{
}

HasWrittenBookCommand::~HasWrittenBookCommand()
{
}

const std::string &HasWrittenBookCommand::getName()
{
    return NAME;
}

void HasWrittenBookCommand::execute(const Container<std::string> &arguments)
{
    if (arguments.getSize() != 2)
    {
        std::cerr << "Invalid arguments for Has written book command" << std::endl;
        return;
    }
    library->hasWrittenBook(arguments.getElement(0), arguments.getElement(0));
}
