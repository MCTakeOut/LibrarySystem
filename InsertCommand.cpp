#include "InsertCommand.h"
#include "StringToIntegerConverter.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>

#include "Library.h"

InsertCommand::InsertCommand(std::shared_ptr<Library> library) : Command(library)
{
}

InsertCommand::~InsertCommand()
{
}

const std::string &InsertCommand::getName()
{
    return NAME;
}

void InsertCommand::execute(const Container<std::string> &arguments)
{
    if (arguments.getSize() != 3)
    {
        std::cerr << "Invalid arguments for Insert command" << std::endl;
        return;
    }
    library->insertContent(arguments.getElement(0), StringToIntegerConverter::convert(arguments.getElement(1)), StringToIntegerConverter::convert(arguments.getElement(2)));
}
