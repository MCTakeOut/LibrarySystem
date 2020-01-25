
#include "OpenCommand.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>

#include "Container.hpp"
#include "Library.h"

OpenCommand::OpenCommand(std::shared_ptr<Library> library) : Command(library)
{
}

OpenCommand::~OpenCommand()
{
}

const std::string &OpenCommand::getName()
{
	return NAME;
}

void OpenCommand::execute(const Container<std::string> &arguments)
{
	if (arguments.getSize() != 1)
	{
		std::cerr << "Invalid arguments for Open command" << std::endl;
		return;
	}

	library->open(arguments.getElement(0));
}
