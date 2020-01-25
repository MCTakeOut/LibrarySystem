
#ifndef OPENCOMMAND_H_
#define OPENCOMMAND_H_

#include <memory>
#include <string>

#include "Command.h"
#include "Container.hpp"

class OpenCommand : public Command
{
public:
	OpenCommand(std::shared_ptr<Library> library);
	virtual ~OpenCommand();

	const std::string &getName() override;
	void execute(const Container<std::string> &arguments) override;

	inline static const std::string NAME = "open";
};

#endif
