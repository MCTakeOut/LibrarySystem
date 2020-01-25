#ifndef CLOSECOMMAND_H_
#define CLOSECOMMAND_H_

#include <memory>
#include <string>

#include "Command.h"
#include "Container.hpp"

class CloseCommand : public Command
{
public:
	CloseCommand(std::shared_ptr<Library> library);
	virtual ~CloseCommand();

	const std::string &getName() override;
	void execute(const Container<std::string> &arguments) override;

	inline static const std::string NAME = "close";
};

#endif
