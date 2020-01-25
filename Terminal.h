#ifndef TERMINAL_H_
#define TERMINAL_H_

#include <memory>
#include <string>
#include <utility>

#include "Container.hpp"

class Library;

class Command;

class Terminal
{

	std::shared_ptr<Library> library;

public:
	Terminal(std::shared_ptr<Library> library);

	void run();
	std::pair<std::shared_ptr<Command>, std::shared_ptr<Container<std::string>>> parseCommandLine(
		const std::string &commandLine);
	std::string extractCommandName(const std::string &commandLine);
	std::pair<std::string, std::string> getCommandNameAndArgments(
		const std::string &commandLine);
	std::shared_ptr<Container<std::string>> extractArguments(
		const std::string &commandLine);
	std::string parseStringArgument(const std::string &argumentString, int i);
	std::string parseNumberArgument(const std::string &argumentsString, int i);
};

#endif
