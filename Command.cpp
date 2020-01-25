
#include "Command.h"

#include <memory>

class Library;

Command::Command(std::shared_ptr<Library> library) : library(library)
{
}

Command::~Command()
{
}
