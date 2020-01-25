#ifndef DISPLAYFROMROWCOMMAND_H_
#define DISPLAYFROMROWCOMMAND_H_

#include "Command.h"
#include "Container.hpp"

class DisplayFromRowCommand : public Command
{
public:
    DisplayFromRowCommand(std::shared_ptr<Library> library);
    virtual ~DisplayFromRowCommand();

    const std::string &getName() override;
    void execute(const Container<std::string> &arguments) override;

    inline static const std::string NAME = "Display from row";
};

#endif
