#ifndef HASREADBOOKCOMMAND_H_
#define HASREADBOOKCOMMAND_H_

#include "Command.h"
#include "Container.hpp"

class HasReadBookCommand : public Command
{
public:
    HasReadBookCommand(std::shared_ptr<Library> library);
    virtual ~HasReadBookCommand();

    const std::string &getName() override;
    void execute(const Container<std::string> &arguments) override;

    inline static const std::string NAME = "Has read book";
};

#endif
