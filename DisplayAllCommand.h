#ifndef DISPLAYALLCOMMAND_H_
#define DISPLAYALLCOMMAND_H_

#include "Command.h"
#include "Container.hpp"

class DisplayAllCommand : public Command
{
public:
    DisplayAllCommand(std::shared_ptr<Library> library);
    virtual ~DisplayAllCommand();

    const std::string &getName() override;
    void execute(const Container<std::string> &arguments) override;
    inline static const std::string NAME = "Display all";
};

#endif
