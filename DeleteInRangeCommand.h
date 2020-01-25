#ifndef DELETEINRANGECOMMAND_H_
#define DELETEINRANGECOMMAND_H_

#include "Command.h"
#include "Container.hpp"

class DeleteInRangeCommand : public Command
{
public:
    DeleteInRangeCommand(std::shared_ptr<Library> library);
    virtual ~DeleteInRangeCommand();

    const std::string &getName() override;
    void execute(const Container<std::string> &arguments) override;

    inline static const std::string NAME = "Delete in range";
};

#endif
