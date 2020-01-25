#ifndef SEARCHCOMMAND_H_
#define SEARCHCOMMAND_H_

#include "Command.h"
#include "Container.hpp"

class SearchCommand : public Command
{
public:
    SearchCommand(std::shared_ptr<Library> library);
    virtual ~SearchCommand();

    const std::string &getName() override;
    void execute(const Container<std::string> &arguments) override;

    inline static const std::string NAME = "Search";
};

#endif
