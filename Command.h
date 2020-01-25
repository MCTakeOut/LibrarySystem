
#ifndef COMMAND_H_
#define COMMAND_H_

#include <memory>
#include <string>

#include "Container.hpp"

class Library;

class Command
{

protected:
	std::shared_ptr<Library> library;

public:
	Command(std::shared_ptr<Library> library);
	virtual ~Command();

	virtual const std::string &getName() = 0;
	virtual void execute(const Container<std::string> &arguments) = 0;
};

#endif
