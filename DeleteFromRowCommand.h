#ifndef DELETEFROMROWCOMMAND_H_
#define DELETEFROMROWCOMMAND_H_

#include "Command.h"
#include "Container.hpp"

class DeleteFromRowCommand : public Command
{
public:
    DeleteFromRowCommand(std::shared_ptr<Library> library);
    virtual ~DeleteFromRowCommand();

    const std::string &getName() override;
    void execute(const Container<std::string> &arguments) override;

    inline static const std::string NAME = "Delete from row";
};

#endif
