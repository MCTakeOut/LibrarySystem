#include "SearchBookCommand.h"
#include "StringToIntegerConverter.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>

#include "Library.h"

SearchBookCommand::SearchBookCommand(std::shared_ptr<Library> library) : Command(library)
{
}

SearchBookCommand::~SearchBookCommand()
{
}

const std::string &SearchBookCommand::getName()
{
    return NAME;
}

void SearchBookCommand::execute(const Container<std::string> &arguments)
{
    if (arguments.getSize() != 2)
    {
        std::cerr << "Invalid arguments for Search book command" << std::endl;
        return;
    }
    library->searchTextInBook(arguments.getElement(0),arguments.getElement(1));
}
