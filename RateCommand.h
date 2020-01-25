#ifndef RATECOMMAND_H_
#define RATECOMMAND_H_

#include "Command.h"
#include "Container.hpp"

class RateCommand : public Command
{
public:
	RateCommand(std::shared_ptr<Library> library);
	virtual ~RateCommand();

	const std::string &getName() override;
	void execute(const Container<std::string> &arguments) override;
	inline static const std::string NAME = "Rate";
};

#endif
