#ifndef APPENDCOMMAND_H_
#define APPENDCOMMAND_H_

#include "Command.h"
#include "Container.hpp"

class AppendCommand : public Command
{
public:
    AppendCommand(std::shared_ptr<Library> library);
    virtual ~AppendCommand();

    const std::string &getName() override;
    void execute(const Container<std::string> &arguments) override;

    inline static const std::string NAME = "Append";
};
#endif
