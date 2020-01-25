#include "AddBookCommand.h"
#include "StringToIntegerConverter.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>

#include "Library.h"

AddBookCommand::AddBookCommand(std::shared_ptr<Library> library) : Command(library)
{
}

AddBookCommand::~AddBookCommand()
{
}

const std::string &AddBookCommand::getName()
{
    return NAME;
}

void AddBookCommand::execute(const Container<std::string> &arguments)
{
    if (arguments.getSize() != 4)
    {
        std::cerr << "Invalid arguments for Add book command" << std::endl;
        return;
    }
    library->addBook(arguments.getElement(0), StringToIntegerConverter::convert(arguments.getElement(1)), arguments.getElement(2), StringToIntegerConverter::convert(arguments.getElement(3)));
}
