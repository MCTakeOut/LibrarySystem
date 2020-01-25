#ifndef PRINTINFOBOOKCOMMAND_H_
#define PRINTINFOBOOKCOMMAND_H_

#include "Command.h"
#include "Container.hpp"

class PrintInfoBookCommand : public Command
{
public:
	PrintInfoBookCommand(std::shared_ptr<Library> library);
	virtual ~PrintInfoBookCommand();

	const std::string &getName() override;
	void execute(const Container<std::string> &arguments) override;

	inline static const std::string NAME = "Print info book";
};

#endif
