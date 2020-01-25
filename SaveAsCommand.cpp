#include "SaveAsCommand.h"

#include "Library.h"
#include <cassert>
#include <iostream>
#include <memory>
#include <string>

SaveAsCommand::SaveAsCommand(std::shared_ptr<Library> library) : Command(library)
{
}

SaveAsCommand::~SaveAsCommand()
{
}

const std::string &SaveAsCommand::getName()
{
	return NAME;
}

void SaveAsCommand::execute(const Container<std::string> &arguments)
{
	if (arguments.getSize() != 1)
	{
		std::cerr << "Invalid arguments for Save as command" << std::endl;
		return;
	}
	library->saveAs(arguments.getElement(0));
}
