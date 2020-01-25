
#include "CommandFactory.h"

#include <cassert>
#include <iostream>

#include "CloseCommand.h"
#include "ExitCommand.h"
#include "OpenCommand.h"
#include "SaveAsCommand.h"
#include "SaveCommand.h"
#include "AddAuthorCommand.h"
#include "AddBookCommand.h"
#include "AddReaderCommand.h"
#include "AppendCommand.h"
#include "DeleteFromRowCommand.h"
#include "DeleteInRangeCommand.h"
#include "DisplayAllCommand.h"
#include "DisplayFromRowCommand.h"
#include "DisplayInRangeCommand.h"
#include "HasReadBookCommand.h"
#include "HasWrittenBookCommand.h"
#include "InsertCommand.h"
#include "PrintInfoBookCommand.h"
#include "PrintInfoCommand.h"
#include "RateCommand.h"
#include "ReadCommand.h"
#include "RemoveBookCommand.h"
#include "RemoveCommand.h"
#include "SearchBookCommand.h"
#include "SearchCommand.h"

class Command;

CommandFactory::CommandFactory()
{
}

CommandFactory::~CommandFactory()
{
}

std::shared_ptr<Command> CommandFactory::createCommand(
	const std::string &commandName, std::shared_ptr<Library> library)
{
	if (commandName == OpenCommand::NAME)
	{
		return std::make_shared<OpenCommand>(library);
	}
	else if (commandName == ExitCommand::NAME)
	{
		return std::make_shared<ExitCommand>(library);
	}
	else if (commandName == SaveAsCommand::NAME)
	{
		return std::make_shared<SaveAsCommand>(library);
	}
	else if (commandName == CloseCommand::NAME)
	{
		return std::make_shared<CloseCommand>(library);
	}
	else if (commandName == SaveCommand::NAME)
	{
		return std::make_shared<SaveCommand>(library);
	}
	else if (commandName == AddAuthorCommand::NAME)
	{
		return std::make_shared<AddAuthorCommand>(library);
	}
	else if (commandName == AddBookCommand::NAME)
	{
		return std::make_shared<AddBookCommand>(library);
	}
	else if (commandName == AddReaderCommand::NAME)
	{
		return std::make_shared<AddReaderCommand>(library);
	}
	else if (commandName == AppendCommand::NAME)
	{
		return std::make_shared<AppendCommand>(library);
	}
	else if (commandName == DeleteFromRowCommand::NAME)
	{
		return std::make_shared<DeleteFromRowCommand>(library);
	}
	else if (commandName == DeleteInRangeCommand::NAME)
	{
		return std::make_shared<DeleteInRangeCommand>(library);
	}
	else if (commandName == DisplayAllCommand::NAME)
	{
		return std::make_shared<DisplayAllCommand>(library);
	}
	else if (commandName == DisplayFromRowCommand::NAME)
	{
		return std::make_shared<DisplayFromRowCommand>(library);
	}
	else if (commandName == DisplayInRangeCommand::NAME)
	{
		return std::make_shared<DisplayInRangeCommand>(library);
	}
	else if (commandName == HasReadBookCommand::NAME)
	{
		return std::make_shared<HasReadBookCommand>(library);
	}
	else if (commandName == HasWrittenBookCommand::NAME)
	{
		return std::make_shared<HasWrittenBookCommand>(library);
	}
	else if (commandName == InsertCommand::NAME)
	{
		return std::make_shared<InsertCommand>(library);
	}
	else if (commandName == PrintInfoBookCommand::NAME)
	{
		return std::make_shared<PrintInfoBookCommand>(library);
	}
	else if (commandName == PrintInfoCommand::NAME)
	{
		return std::make_shared<PrintInfoCommand>(library);
	}
	else if (commandName == RateCommand::NAME)
	{
		return std::make_shared<RateCommand>(library);
	}
	else if (commandName == ReadCommand::NAME)
	{
		return std::make_shared<ReadCommand>(library);
	}
	else if (commandName == RemoveBookCommand::NAME)
	{
		return std::make_shared<RemoveBookCommand>(library);
	}
	else if (commandName == SearchBookCommand::NAME)
	{
		return std::make_shared<SearchBookCommand>(library);
	}
	else if (commandName == SearchCommand::NAME)
	{
		return std::make_shared<SearchCommand>(library);
	}
	else
	{
		std::cerr << "Invalid command: "
				  << "\"" << commandName << "\""
				  << std::endl;
	}
	return nullptr;
}
