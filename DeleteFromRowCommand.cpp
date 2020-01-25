#include "DeleteFromRowCommand.h"
#include "StringToIntegerConverter.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>

#include "Library.h"

DeleteFromRowCommand::DeleteFromRowCommand(std::shared_ptr<Library> library) : Command(library)
{
}

DeleteFromRowCommand::~DeleteFromRowCommand()
{
}

const std::string &DeleteFromRowCommand::getName()
{
    return NAME;
}

void DeleteFromRowCommand::execute(const Container<std::string> &arguments)
{
    if (arguments.getSize() != 2)
    {
        std::cerr << "Invalid arguments for Delete from row command" << std::endl;
        return;
    }
    library->deleteContentFromRowTillEnd(arguments.getElement(0), StringToIntegerConverter::convert(arguments.getElement(1)));
}
