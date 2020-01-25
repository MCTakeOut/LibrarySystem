#include "SearchCommand.h"
#include "StringToIntegerConverter.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>

#include "Library.h"

SearchCommand::SearchCommand(std::shared_ptr<Library> library) : Command(library)
{
}

SearchCommand::~SearchCommand()
{
}

const std::string &SearchCommand::getName()
{
    return NAME;
}

void SearchCommand::execute(const Container<std::string> &arguments)
{
    if (arguments.getSize() != 1)
    {
        std::cerr << "Invalid arguments for Search command" << std::endl;
        return;
    }
    library->searchTextInAllBooks(arguments.getElement(0));
}
