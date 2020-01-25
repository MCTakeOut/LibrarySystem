#include "PrintInfoCommand.h"
#include "StringToIntegerConverter.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>

#include "Library.h"

PrintInfoCommand::PrintInfoCommand(std::shared_ptr<Library> library) : Command(library)
{
}

PrintInfoCommand::~PrintInfoCommand()
{
}

const std::string &PrintInfoCommand::getName()
{
	return NAME;
}

void PrintInfoCommand::execute(const Container<std::string> &arguments)
{
	if (arguments.getSize() != 1)
	{
		std::cerr << "Invalid arguments for Print info command" << std::endl;
		return;
	}
	library->printInfoPerson(arguments.getElement(0));
}
