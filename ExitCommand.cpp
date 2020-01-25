
#include "ExitCommand.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>

#include "Library.h"

ExitCommand::ExitCommand(std::shared_ptr<Library> library) : Command(library)
{
}

ExitCommand::~ExitCommand()
{
}

const std::string &ExitCommand::getName()
{
	return NAME;
}

void ExitCommand::execute(const Container<std::string> &arguments)
{
	if (arguments.getSize() != 0)
	{
		std::cerr << "Invalid arguments for Exit command" << std::endl;
		return;
	}
	library->exit();
}
