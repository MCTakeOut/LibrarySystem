#ifndef ADDAUTHORCOMMAND_H_
#define ADDAUTHORCOMMAND_H_

#include "Command.h"
#include "Container.hpp"

class AddAuthorCommand : public Command
{
public:
    AddAuthorCommand(std::shared_ptr<Library> library);
    virtual ~AddAuthorCommand();

    const std::string &getName() override;
    void execute(const Container<std::string> &arguments) override;

    inline static const std::string NAME = "Add author";
};

#endif
