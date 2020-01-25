#ifndef DISPLAYINRANGECOMMAND_H_
#define DISPLAYINRANGECOMMAND_H_

#include "Command.h"
#include "Container.hpp"

class DisplayInRangeCommand : public Command
{
public:
    DisplayInRangeCommand(std::shared_ptr<Library> library);
    virtual ~DisplayInRangeCommand();

    const std::string &getName() override;
    void execute(const Container<std::string> &arguments) override;

    inline static const std::string NAME = "Display in range";
};

#endif
