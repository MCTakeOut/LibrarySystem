#ifndef READCOMMAND_H_
#define READCOMMAND_H_

#include "Command.h"
#include "Container.hpp"

class ReadCommand : public Command
{
public:
	ReadCommand(std::shared_ptr<Library> library);
	virtual ~ReadCommand();

	const std::string &getName() override;
	void execute(const Container<std::string> &arguments) override;

	inline static const std::string NAME = "Read";
};

#endif
