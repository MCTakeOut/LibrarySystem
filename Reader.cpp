#include "Reader.h"
#include "Book.h"

Reader::Reader(const std::string &name, const std::string &nationality, int age,
			   const Container<std::shared_ptr<Book>> &readBooks) : Person(name, nationality, age)
{
	this->readBooks = readBooks;
}

Container<std::shared_ptr<Book>> &Reader::getReadBooks()
{
	return readBooks;
}

const Container<std::shared_ptr<Book>> &Reader::getReadBooks() const
{
	return readBooks;
}

void Reader::setReadBooks(Container<std::shared_ptr<Book>> &readBooks)
{
	this->readBooks = readBooks;
}

bool Reader::hasReadBook(const std::string &title) const
{
	std::shared_ptr<Book> book = std::make_shared<Book>(title);
	int bookIdx = readBooks.search(book);
	return bookIdx != readBooks.INVALID_INDEX;
}

void Reader::readBook(std::shared_ptr<Book> book)
{
	readBooks.insert(book);
}
