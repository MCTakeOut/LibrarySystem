#include "DeleteInRangeCommand.h"
#include "StringToIntegerConverter.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>

#include "Library.h"

DeleteInRangeCommand::DeleteInRangeCommand(std::shared_ptr<Library> library) : Command(library)
{
}

DeleteInRangeCommand::~DeleteInRangeCommand()
{
}

const std::string &DeleteInRangeCommand::getName()
{
    return NAME;
}

void DeleteInRangeCommand::execute(const Container<std::string> &arguments)
{
    if (arguments.getSize() != 3)
    {
        std::cerr << "Invalid arguments for Delete in range command" << std::endl;
        return;
    }
    library->deleteContentInRange(arguments.getElement(0), StringToIntegerConverter::convert(arguments.getElement(1)), StringToIntegerConverter::convert(arguments.getElement(2)));
}
