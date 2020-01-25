#include <memory>

#include "Library.h"
#include "Terminal.h"

int main()
{

	std::shared_ptr<Library> library = std::make_shared<Library>();

	Terminal terminal(library);
	terminal.run();

	return 0;
}
///home/mctakeout/Documents/LibrarySystemLast/resources Library-Valid-File-Example