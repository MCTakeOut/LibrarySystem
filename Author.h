#ifndef AUTHOR_H_
#define AUTHOR_H_

#include <memory>
#include <string>

#include "Container.hpp"
#include "Reader.h"

class Book;
class LibraryLoader;

class Author : public Reader
{
	Container<std::shared_ptr<Book>> writtenBooks;

public:
	Author(const std::string &name = "", const std::string &nationality = "",
		   const int &age = 0,
		   const Container<std::shared_ptr<Book>> &writtenBooks = Container<
			   std::shared_ptr<Book>>(),
		   const Container<std::shared_ptr<Book>> &readBooks = Container<
			   std::shared_ptr<Book>>());

	Container<std::shared_ptr<Book>> &getWrittenBooks();
	const Container<std::shared_ptr<Book>> &getWrittenBooks() const;
	void setWrittenBooks(Container<std::shared_ptr<Book>> &writtenBooks);

	bool hasWrittenBook(const std::string &title) const;

	void writeBook(std::shared_ptr<Book> book);
};

#endif
