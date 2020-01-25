#include "AddAuthorCommand.h"
#include "StringToIntegerConverter.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>

#include "Library.h"

AddAuthorCommand::AddAuthorCommand(std::shared_ptr<Library> library) : Command(library)
{
}

AddAuthorCommand::~AddAuthorCommand()
{
}

const std::string &AddAuthorCommand::getName()
{
    return NAME;
}

void AddAuthorCommand::execute(const Container<std::string> &arguments)
{
    if (arguments.getSize() != 3)
    {
        std::cerr << "Invalid arguments for Add author command" << std::endl;
        return;
    }
    library->addAuthor(arguments.getElement(0), arguments.getElement(1), StringToIntegerConverter::convert(arguments.getElement(2)));
}
