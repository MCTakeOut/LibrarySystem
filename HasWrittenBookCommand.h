#ifndef HASWRITTENBOOKCOMMAND_H_
#define HASWRITTENBOOKCOMMAND_H_

#include "Command.h"
#include "Container.hpp"

class HasWrittenBookCommand : public Command
{
public:
    HasWrittenBookCommand(std::shared_ptr<Library> library);
    virtual ~HasWrittenBookCommand();

    const std::string &getName() override;
    void execute(const Container<std::string> &arguments) override;

    inline static const std::string NAME = "Has written book";
};

#endif
