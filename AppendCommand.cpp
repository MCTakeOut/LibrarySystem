#include "AppendCommand.h"
#include "StringToIntegerConverter.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>

#include "Library.h"

AppendCommand::AppendCommand(std::shared_ptr<Library> library) : Command(library)
{
}

AppendCommand::~AppendCommand()
{
}

const std::string &AppendCommand::getName()
{
    return NAME;
}

void AppendCommand::execute(const Container<std::string> &arguments)
{
    if (arguments.getSize() != 2)
    {
        std::cerr << "Invalid arguments for Append command" << std::endl;
        return;
    }
    library->appendContent(arguments.getElement(0), StringToIntegerConverter::convert(arguments.getElement(1)));
}
