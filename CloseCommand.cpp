#include "CloseCommand.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>

#include "Library.h"

CloseCommand::CloseCommand(std::shared_ptr<Library> library) : Command(library)
{
}

CloseCommand::~CloseCommand()
{
}

const std::string &CloseCommand::getName()
{
	return NAME;
}

void CloseCommand::execute(const Container<std::string> &arguments)
{
	if (arguments.getSize() != 0)
	{
		std::cerr << "Invalid arguments for Close command" << std::endl;
		return;
	}
	library->clear();
}
