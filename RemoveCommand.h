#ifndef REMOVECOMMAND_H_
#define REMOVECOMMAND_H_

#include "Command.h"
#include "Container.hpp"

class RemoveCommand : public Command
{
public:
	RemoveCommand(std::shared_ptr<Library> library);
	virtual ~RemoveCommand();

	const std::string &getName() override;
	void execute(const Container<std::string> &arguments) override;

	inline static const std::string NAME = "Remove";
};

#endif
