#include "AddReaderCommand.h"
#include "StringToIntegerConverter.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>

#include "Library.h"

AddReaderCommand::AddReaderCommand(std::shared_ptr<Library> library) : Command(library)
{
}

AddReaderCommand::~AddReaderCommand()
{
}

const std::string &AddReaderCommand::getName()
{
    return NAME;
}

void AddReaderCommand::execute(const Container<std::string> &arguments)
{
    if (arguments.getSize() != 3)
    {
        std::cerr << "Invalid arguments for Add reader command" << std::endl;
        return;
    }
    library->addReader(arguments.getElement(0), arguments.getElement(1), StringToIntegerConverter::convert(arguments.getElement(2)));
}
