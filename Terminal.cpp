#include "Terminal.h"

#include <stddef.h>
#include <iostream>

#include "CloseCommand.h"
#include "CommandFactory.h"
#include "ExitCommand.h"
#include "Library.h"
#include "OpenCommand.h"

class Library;

class CommandFactory;

Terminal::Terminal(std::shared_ptr<Library> library)
{
	this->library = library;
}

std::pair<std::shared_ptr<Command>, std::shared_ptr<Container<std::string>>> Terminal::parseCommandLine(
	const std::string &commandLine)
{
	std::pair<std::string, std::string> commandNameAndArgumentsPair =
		getCommandNameAndArgments(commandLine);

	std::shared_ptr<Command> command = CommandFactory::createCommand(
		commandNameAndArgumentsPair.first, library);
	std::shared_ptr<Container<std::string>> arguments = extractArguments(
		commandNameAndArgumentsPair.second);
	if (!arguments)
	{
		command = nullptr;
	}

	return std::make_pair(command, arguments);
}

std::pair<std::string, std::string> Terminal::getCommandNameAndArgments(
	const std::string &commandLine)
{
	char nameDelimiter = '\"';
	size_t idx = commandLine.find(nameDelimiter);
	if (idx != std::string::npos)
	{
		return std::make_pair(commandLine.substr(0, idx - 1),
							  commandLine.substr(idx));
	}
	else
	{
		return std::make_pair(commandLine.substr(0), "");
	}
}

std::shared_ptr<Container<std::string>> Terminal::extractArguments(
	const std::string &argumentsString)
{
	std::shared_ptr<Container<std::string>> arguments = std::make_shared<
		Container<std::string>>();

	int i = 0;
	while (i < argumentsString.length())
	{
		if (argumentsString[i] == '\"')
		{
			std::string stringArgument = parseStringArgument(argumentsString,
															 i);
			if (stringArgument == "")
			{
				return nullptr;
			}
			i += stringArgument.length() + 1;
			arguments->insert(stringArgument);
		}
		else if ('0' <= argumentsString[i] && argumentsString[i] <= '9')
		{
			std::string numberArgument = parseNumberArgument(argumentsString,
															 i);
			i += numberArgument.length() - 1;
			arguments->insert(numberArgument);
		}
		else if (argumentsString[i] != ' ')
		{
			std::cerr << "Invalid command arguments format" << std::endl;
			return nullptr;
		}

		i++;
	}

	return arguments;
}

std::string Terminal::parseStringArgument(const std::string &argumentString,
										  int i)
{
	i++; // skip first '"'
	int j = i;
	while (j < argumentString.length())
	{
		if (argumentString[j] == '\"')
		{
			return argumentString.substr(i, j - i);
		}
		j++;
	}

	std::cerr << "Invalid string argument format - missing \"" << std::endl;
	return "";
}

std::string Terminal::parseNumberArgument(const std::string &argumentsString,
										  int i)
{
	int j = i;
	while (j < argumentsString.length())
	{
		if (!('0' <= argumentsString[j] && argumentsString[j] <= '9'))
		{
			return argumentsString.substr(i, j - i);
		}
		j++;
	}
	return argumentsString.substr(i, j - i);
}

void Terminal::run()
{
	bool stopped = false;
	bool waitForOpenCommand = true;
	while (!stopped)
	{
		std::string commandLine;
		std::getline(std::cin, commandLine, '\n');
		std::pair<std::shared_ptr<Command>,
				  std::shared_ptr<Container<std::string>>>
			commandPair =
				parseCommandLine(commandLine);

		/*std::cout << commandPair.first->getName() << std::endl;
		 std::cout << commandPair.second->getSize() << std::endl;
		 std::cout << commandPair.second->getElement(0) << std::endl;*/

		if (commandPair.first != nullptr)
		{
			if (waitForOpenCommand == false || commandPair.first->getName() == OpenCommand::NAME)
			{
				waitForOpenCommand = false;
				if (commandPair.first->getName() == ExitCommand::NAME)
				{
					stopped = true;
				}
				else if (commandPair.first->getName() == CloseCommand::NAME)
				{
					waitForOpenCommand = true;
					commandPair.first->execute(*commandPair.second);
				}
				else
				{
					commandPair.first->execute(*commandPair.second);
				}
			}
		}
	}
}
