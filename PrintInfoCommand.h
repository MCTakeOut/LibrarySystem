#ifndef PRINTINFOCOMMAND_H_
#define PRINTINFOCOMMAND_H_

#include "Command.h"
#include "Container.hpp"

class PrintInfoCommand : public Command
{
public:
	PrintInfoCommand(std::shared_ptr<Library> library);
	virtual ~PrintInfoCommand();

	const std::string &getName() override;
	void execute(const Container<std::string> &arguments) override;

	inline static const std::string NAME = "Print info";
};

#endif
