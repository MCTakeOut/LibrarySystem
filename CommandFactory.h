#ifndef COMMANDFACTORY_H_
#define COMMANDFACTORY_H_

#include <memory>
#include <string>

class Library;

class Command;

class CommandFactory
{
public:
	CommandFactory();
	virtual ~CommandFactory();

	static std::shared_ptr<Command> createCommand(
		const std::string &commandName, std::shared_ptr<Library> library);
};

#endif
