
#ifndef EXITCOMMAND_H_
#define EXITCOMMAND_H_

#include <memory>
#include <string>

#include "Command.h"
#include "Container.hpp"

class ExitCommand : public Command
{
public:
	ExitCommand(std::shared_ptr<Library> library);
	virtual ~ExitCommand();

	const std::string &getName() override;
	void execute(const Container<std::string> &arguments) override;

	inline static const std::string NAME = "exit";
};

#endif
