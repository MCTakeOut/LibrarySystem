#ifndef ADDBOOKCOMMAND_H_
#define ADDBOOKCOMMAND_H_

#include "Command.h"
#include "Container.hpp"

class AddBookCommand : public Command
{
public:
    AddBookCommand(std::shared_ptr<Library> library);
    virtual ~AddBookCommand();

    const std::string &getName() override;
    void execute(const Container<std::string> &arguments) override;

    inline static const std::string NAME = "Add book";
};

#endif
