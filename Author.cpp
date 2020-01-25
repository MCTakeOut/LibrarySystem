#include "Author.h"
#include "Book.h"
#include <string.h>

Author::Author(const std::string &name, const std::string &nationality,
			   const int &age, const Container<std::shared_ptr<Book>> &writtenBooks,
			   const Container<std::shared_ptr<Book>> &readBooks) : Reader(name, nationality, age, readBooks)
{
	this->writtenBooks = writtenBooks;
}

Container<std::shared_ptr<Book>> &Author::getWrittenBooks()
{
	return writtenBooks;
}

const Container<std::shared_ptr<Book>> &Author::getWrittenBooks() const
{
	return writtenBooks;
}

bool Author::hasWrittenBook(const std::string &title) const
{
	std::shared_ptr<Book> book = std::make_shared<Book>(title);
	int bookIdx = writtenBooks.search(book);
	return bookIdx != writtenBooks.INVALID_INDEX;
}

void Author::setWrittenBooks(Container<std::shared_ptr<Book>> &writtenBooks)
{
	this->writtenBooks = writtenBooks;
}

void Author::writeBook(std::shared_ptr<Book> book)
{
	writtenBooks.insert(book);
}
// Author::~Author() {
// 	// TODO Auto-generated destructor stub
// }
