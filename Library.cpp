#include "Library.h"

#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <memory>
#include <string>

#include "Author.h"
#include "Book.h"
#include "Container.hpp"
#include "Reader.h"
#include "TextMatches.h"
#include "Content.h"
#include "LibraryLoader.h"

Library::Library(const Container<std::shared_ptr<Book>> &books,
				 const Container<std::shared_ptr<Author>> &authors,
				 const Container<std::shared_ptr<Reader>> &readers)
{
	this->books = books;
	this->authors = authors;
	this->readers = readers;
}

const Container<std::shared_ptr<Author>> &Library::getAuthors() const
{
	return authors;
}

const Container<std::shared_ptr<Book>> &Library::getBooks() const
{
	return books;
}

const Container<std::shared_ptr<Reader>> &Library::getReaders() const
{
	return readers;
}

void Library::printInfoBook(const std::string &title) const
{
	std::shared_ptr<Book> book = searchBook(title);
	std::cout << book->getNumberOfRows() << std::endl;
	std::cout << book->getPublicationYear() << std::endl;
	std::cout << book->getAuthor()->getName() << std::endl;
	std::cout << book->getPrice() << std::endl;
	std::cout << book->getOverallRating() << std::endl;
	std::cout
		<< book->getNumberOfTimesItWasReadByReaders(readers) + book->getNumberOfTimesItWasReadByAuthors(authors)
		<< std::endl;
}

std::shared_ptr<Book> Library::searchBook(const std::string &title) const
{
	for (int i = 0; i < books.getSize(); i++)
	{
		std::shared_ptr<Book> book = books.getElement(i);
		if (book->getTitle() == title)
		{
			return book;
		}
	}
	return nullptr;
}

void Library::printInfoPerson(const std::string &name) const
{
	std::shared_ptr<Author> author = searchPersonInAuthors(name);
	if (author == nullptr)
	{
		std::shared_ptr<Reader> reader = searchPersonInReaders(name);
		if (reader != nullptr)
		{
			std::cout << reader->getAge() << std::endl;
			std::cout << reader->getNationality() << std::endl;
			std::cout << reader->getReadBooks().getSize() << std::endl;
			printBooks(reader->getReadBooks());
		}
	}
	else
	{
		std::cout << author->getAge() << std::endl;
		std::cout << author->getNationality() << std::endl;
		std::cout << author->getReadBooks().getSize() << std::endl;
		printBooks(author->getReadBooks());
		printBooks(author->getWrittenBooks());
	}
}

void Library::printBooks(const Container<std::shared_ptr<Book>> &books) const
{
	for (int i = 0; i < books.getSize(); i++)
	{
		std::shared_ptr<Book> book = books.getElement(i);
		std::cout << book->getTitle() << std::endl;
		std::cout << book->getNumberOfRows() << std::endl;
	}
}

std::shared_ptr<Author> Library::searchPersonInAuthors(
	const std::string &name) const
{
	for (int i = 0; i < authors.getSize(); i++)
	{
		std::shared_ptr<Author> author = authors.getElement(i);
		if (author->getName() == name)
		{
			return author;
		}
	}
	return nullptr;
}

std::shared_ptr<Reader> Library::searchPersonInReaders(
	const std::string &name) const
{
	for (int i = 0; i < readers.getSize(); i++)
	{
		std::shared_ptr<Reader> reader = readers.getElement(i);
		if (reader->getName() == name)
		{
			return reader;
		}
	}
	return nullptr;
}

std::shared_ptr<Reader> Library::searchPersonInAuthorsAndReaders(
	const std::string &name) const
{
	std::shared_ptr<Author> author = searchPersonInAuthors(name);
	if (author == nullptr)
	{
		std::shared_ptr<Reader> reader = searchPersonInReaders(name);
		return reader;
	}
	return author;
}

void Library::displayAllContent(const std::string &title) const
{
	displayContentFromRowTillEnd(title, 0);
}

void Library::displayContentFromRowTillEnd(const std::string &title,
										   int startRow) const
{
	dislpayContentInRange(title, startRow, Content::MAX_ROWS);
}

void Library::dislpayContentInRange(const std::string &title, int startRow,
									int endRow) const
{
	assert(startRow <= endRow);

	std::shared_ptr<Book> book = searchBook(title);
	endRow = std::min(endRow, book->getContent().getNumberOfRows());
	for (int i = startRow; i < endRow; i++)
	{
		std::cout << i + 1 << " " << book->getContent().getRow(i) << std::endl;
	}
}

void Library::addReader(const std::string &name, const std::string &nationality,
						int age)
{
	std::shared_ptr<Reader> reader = std::make_shared<Reader>(name, nationality,
															  age);
	readers.insert(reader);
}

void Library::addReader(std::shared_ptr<Reader> reader)
{
	readers.insert(reader);
}

void Library::addAuthor(const std::string &name, const std::string &nationality,
						int age)
{
	std::shared_ptr<Author> author = std::make_shared<Author>(name, nationality,
															  age);
	authors.insert(author);
}

void Library::addAuthor(std::shared_ptr<Author> author)
{
	authors.insert(author);
}

void Library::addBook(const std::string &title, int publicationYear,
					  const std::string &authorName, int price)
{
	std::shared_ptr<Author> author = searchPersonInAuthors(authorName);
	std::shared_ptr<Book> book = std::make_shared<Book>(title, publicationYear,
														author, price);
	books.insert(book);
}

void Library::addBook(std::shared_ptr<Book> book)
{
	books.insert(book);
}

void Library::removeBook(const std::string &title)
{
	std::shared_ptr<Book> book = searchBook(title);
	removeBookFromAuthors(book);
	removeBookFromReaders(book);
	books.remove(book);
}

void Library::removeBookFromAuthors(std::shared_ptr<Book> book)
{
	for (int i = 0; i < authors.getSize(); i++)
	{
		std::shared_ptr<Author> author = authors.getElement(i);
		author->getWrittenBooks().remove(book);
		author->getReadBooks().remove(book);
	}
}

void Library::removeBookFromReaders(std::shared_ptr<Book> book)
{
	for (int i = 0; i < readers.getSize(); i++)
	{
		std::shared_ptr<Reader> reader = readers.getElement(i);
		reader->getReadBooks().remove(book);
	}
}

void Library::removePerson(const std::string &name)
{
	removeReader(name);
	removeAuthor(name);
}

void Library::removeReader(const std::string &name)
{
	readers.remove(std::make_shared<Reader>(name));
}

void Library::removeAuthor(const std::string &name)
{
	removeAllBooksFromAuthor(name);

	std::shared_ptr<Author> author = searchPersonInAuthors(name);
	Container<std::shared_ptr<Book>> &writtenBooks = author->getWrittenBooks();
	//writtenBooks.clear();
}

void Library::removeAllBooksFromAuthor(const std::string &name)
{
	for (int i = 0; i < readers.getSize(); i++)
	{
		std::shared_ptr<Reader> reader = readers.getElement(i);
		Container<std::shared_ptr<Book>> &readBooks = reader->getReadBooks();
		Container<std::shared_ptr<Book>> updatedReadBooks;
		for (int i = 0; i < readBooks.getSize(); i++)
		{
			std::string authorName =
				readBooks.getElement(i)->getAuthor()->getName();
			if (authorName != name)
			{
				updatedReadBooks.insert(readBooks.getElement(i));
			}
		}
	}
}
//!! TO DO
// void Library::removeBookOfAuthors(const std::string& name,
// 		const Author& author) {

// }

void Library::hasReadBook(const std::string &name,
						  const std::string &title) const
{
	std::shared_ptr<Reader> reader = searchPersonInAuthorsAndReaders(name);
	char errorMessageTemplate[] = "There is no author or reader with name: ";
	assert(reader != nullptr && strcat(errorMessageTemplate, name.c_str()));
	if (reader->hasReadBook(title))
	{
		std::cout << "Yes" << std::endl;
	}
	else
	{
		std::cout << "No" << std::endl;
	}
}

void Library::hasWrittenBook(const std::string &name,
							 const std::string &title) const
{
	std::shared_ptr<Author> author = searchPersonInAuthors(name);
	char errorMessageTemplate[] = "There is no author with name: ";
	assert(author != nullptr && strcat(errorMessageTemplate, name.c_str()));
	if (author->hasWrittenBook(title))
	{
		std::cout << "Yes" << std::endl;
	}
	else
	{
		std::cout << "No" << std::endl;
	}
}

void Library::readBook(const std::string &title, const std::string &name)
{
	std::shared_ptr<Book> book = searchBook(title);
	char missingBookError[] = "There is no book with title: ";
	assert(book != nullptr && strcat(missingBookError, title.c_str()));
	book->getContent().print();

	std::shared_ptr<Reader> reader = searchPersonInAuthorsAndReaders(name);
	char missingPersonError[] = "There is no author or reader with name: ";
	assert(reader != nullptr && strcat(missingPersonError, name.c_str()));
	reader->readBook(book);
}

void Library::rateBook(const std::string &title, const std::string &name,
					   double rating)
{
	std::shared_ptr<Book> book = searchBook(title);
	if (book->getAuthor()->getName() != name)
	{
		book->addRating(rating);
	}
	else
	{
		std::cerr << "Author with name: " << name
				  << " can't rate their own books" << std::endl;
	}
}

void Library::appendContent(const std::string &title, int rowCount)
{
}

void Library::insertContent(const std::string &title, int startRow,
							int rowCount)
{
}

void Library::deleteContentFromRowTillEnd(const std::string &title,
										  int startRow)
{
}

void Library::deleteContentInRange(const std::string &title, int startRow,
								   int endRow)
{
}

std::shared_ptr<TextMatches> Library::searchTextInBook(const std::string &title,
													   const std::string &text) const
{
}
Container<TextMatches> Library::searchTextInAllBooks(const std::string &text) const
{
}

void Library::open(const std::string &absoluteFilename)
{
	LibraryLoader libraryLoader;
	*this = *(libraryLoader.load(absoluteFilename));
}

void Library::clear()
{
	books.clear();
	authors.clear();
	readers.clear();
}

void Library::exit()
{
}

void Library::save()
{
}

void Library::saveAs(const std::string &absoluteFilename)
{
}

/*
 std::shared_ptr<TextMatches> Library::searchTextInBook(const std::string &title, const std::string &text) const
 {

 /// book e namerenata kniga sys zaglavie 'title'
 Book fictiveBook(title);
 std::shared_ptr<Book> fictiveBookPtr = std::make_shared<Book>(fictiveBook);
 std::shared_ptr<Book> book = books.search(fictiveBookPtr);

 if (book == nullptr)
 {
 return nullptr;
 }

 TextMatches *textMatches = new TextMatches(book);

 Container<std::string> rows = book->getRows();
 for
 ... in rows
 {
 if
 match found... add to textMatches
 }

 return std::make_shared<TextMatches>(textMatches);
 }
 */
