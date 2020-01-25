#ifndef READER_H_
#define READER_H_

#include <memory>
#include <string>
#include "Container.hpp"
#include "Person.h"

class LibraryLoader;
class Book;

class Reader : public Person
{
	Container<std::shared_ptr<Book>> readBooks;

public:
	Reader(const std::string &name = "", const std::string &nationality = "",
		   int age = 0, const Container<std::shared_ptr<Book>> &readBooks = Container<std::shared_ptr<Book>>());

	Container<std::shared_ptr<Book>> &getReadBooks();
	const Container<std::shared_ptr<Book>> &getReadBooks() const;
	void setReadBooks(Container<std::shared_ptr<Book>> &readBooks);

	bool hasReadBook(const std::string &title) const;
	void readBook(std::shared_ptr<Book> book);
};

#endif
