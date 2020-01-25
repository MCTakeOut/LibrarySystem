#ifndef REMOVEBOOKCOMMAND_H_
#define REMOVEBOOKCOMMAND_H_

#include "Command.h"
#include "Container.hpp"

class RemoveBookCommand : public Command
{
public:
	RemoveBookCommand(std::shared_ptr<Library> library);
	virtual ~RemoveBookCommand();

	const std::string &getName() override;
	void execute(const Container<std::string> &arguments) override;

	inline static const std::string NAME = "Remove book";
};

#endif
