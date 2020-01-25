#ifndef INSERTCOMMAND_H_
#define INSERTCOMMAND_H_

#include "Command.h"
#include "Container.hpp"

class InsertCommand : public Command
{
public:
    InsertCommand(std::shared_ptr<Library> library);
    virtual ~InsertCommand();

    const std::string &getName() override;
    void execute(const Container<std::string> &arguments) override;

    inline static const std::string NAME = "Insert";
};

#endif
