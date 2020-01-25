#include "RateCommand.h"
#include "StringToIntegerConverter.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>

#include "Library.h"

RateCommand::RateCommand(std::shared_ptr<Library> library) : Command(library)
{
}

RateCommand::~RateCommand()
{
}

const std::string &RateCommand::getName()
{
    return NAME;
}

void RateCommand::execute(const Container<std::string> &arguments)
{
    if (arguments.getSize() != 3)
    {
        std::cerr << "Invalid arguments for Rate command" << std::endl;
        return;
    }
    library->rateBook(arguments.getElement(0), arguments.getElement(1), StringToIntegerConverter::convert(arguments.getElement(3)));
}
