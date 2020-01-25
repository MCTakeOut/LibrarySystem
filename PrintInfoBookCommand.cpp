#include "PrintInfoBookCommand.h"
#include "StringToIntegerConverter.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>

#include "Library.h"

PrintInfoBookCommand::PrintInfoBookCommand(std::shared_ptr<Library> library) : Command(library)
{
}

PrintInfoBookCommand::~PrintInfoBookCommand()
{
}

const std::string &PrintInfoBookCommand::getName()
{
	return NAME;
}

void PrintInfoBookCommand::execute(const Container<std::string> &arguments)
{
	if (arguments.getSize() != 1)
	{
		std::cerr << "Invalid arguments for Print info book command"
				  << std::endl;
		return;
	}
	library->printInfoBook(arguments.getElement(0));
}
