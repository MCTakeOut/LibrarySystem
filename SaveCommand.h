#ifndef SAVECOMMAND_H_
#define SAVECOMMAND_H_

#include <memory>
#include <string>

#include "Command.h"
#include "Container.hpp"

class SaveCommand : public Command
{
public:
	SaveCommand(std::shared_ptr<Library> library);
	virtual ~SaveCommand();

	const std::string &getName() override;
	void execute(const Container<std::string> &arguments) override;

	inline static const std::string NAME = "save";
};

#endif
