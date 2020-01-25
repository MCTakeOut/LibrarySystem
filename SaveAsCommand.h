#ifndef SAVEASCOMMAND_H_
#define SAVEASCOMMAND_H_

#include <memory>
#include <string>

#include "Command.h"
#include "Container.hpp"

class SaveAsCommand : public Command
{
public:
	SaveAsCommand(std::shared_ptr<Library> library);
	virtual ~SaveAsCommand();

	const std::string &getName() override;
	void execute(const Container<std::string> &arguments) override;

	inline static const std::string NAME = "save as";
};

#endif
