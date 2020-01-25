#include "SaveCommand.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <string>

#include "Library.h"

SaveCommand::SaveCommand(std::shared_ptr<Library> library) : Command(library)
{
}

SaveCommand::~SaveCommand()
{
}

const std::string &SaveCommand::getName()
{
	return NAME;
}

void SaveCommand::execute(const Container<std::string> &arguments)
{
	if (arguments.getSize() != 0)
	{
		std::cerr << "Invalid arguments for Save command" << std::endl;
		return;
	}
	library->save();
}
