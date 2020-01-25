#ifndef SEARCHBOOKCOMMAND_H_
#define SEARCHBOOKCOMMAND_H_

#include "Command.h"
#include "Container.hpp"

class SearchBookCommand : public Command
{
public:
    SearchBookCommand(std::shared_ptr<Library> library);
    virtual ~SearchBookCommand();

    const std::string &getName() override;
    void execute(const Container<std::string> &arguments) override;

    inline static const std::string NAME = "Search book";
};

#endif
