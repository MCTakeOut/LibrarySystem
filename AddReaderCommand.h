#ifndef ADDREADERCOMMAND_H_
#define ADDREADERCOMMAND_H_

#include "Command.h"
#include "Container.hpp"

class AddReaderCommand : public Command
{
public:
    AddReaderCommand(std::shared_ptr<Library> library);
    virtual ~AddReaderCommand();

    const std::string &getName() override;
    void execute(const Container<std::string> &arguments) override;

    inline static const std::string NAME = "Add reader";
};
#endif
