#ifndef LIBRARY_H_
#define LIBRARY_H_

#include "Author.h"
#include "Book.h"
#include "Container.hpp"
#include "Reader.h"
#include "TextMatches.h"

class LibraryLoader;

class Library
{

	Container<std::shared_ptr<Book>> books;
	Container<std::shared_ptr<Author>> authors;
	Container<std::shared_ptr<Reader>> readers;

public:
	Library(
		const Container<std::shared_ptr<Book>> &books = Container<
			std::shared_ptr<Book>>(),
		const Container<std::shared_ptr<Author>> &authors = Container<
			std::shared_ptr<Author>>(),
		const Container<std::shared_ptr<Reader>> &readers = Container<
			std::shared_ptr<Reader>>());

	const Container<std::shared_ptr<Author>> &getAuthors() const;
	const Container<std::shared_ptr<Book>> &getBooks() const;
	const Container<std::shared_ptr<Reader>> &getReaders() const;

	void printInfoBook(const std::string &title) const;
	void printInfoPerson(const std::string &name) const;
	void displayAllContent(const std::string &title) const;
	void displayContentFromRowTillEnd(const std::string &title,
									  int startRow) const;
	void dislpayContentInRange(const std::string &title, int startRow,
							   int endRow) const;

	void addReader(const std::string &name, const std::string &nationality,
				   int age);
	void addReader(std::shared_ptr<Reader> reader);

	void addAuthor(const std::string &name, const std::string &nationality,
				   int age);
	void addAuthor(std::shared_ptr<Author> author);

	void addBook(const std::string &title, int publicationYear,
				 const std::string &authorName, int price);
	void addBook(std::shared_ptr<Book> book);

	void removeBook(const std::string &title);
	void removePerson(const std::string &name);

	void hasReadBook(const std::string &name, const std::string &title) const;
	void hasWrittenBook(const std::string &name,
						const std::string &title) const;

	void readBook(const std::string &title, const std::string &name);
	void rateBook(const std::string &title, const std::string &name,
				  double rating);
	void appendContent(const std::string &title, int rowCount);
	void insertContent(const std::string &title, int startRow, int rowCount);
	void deleteContentFromRowTillEnd(const std::string &title, int startRow);
	void deleteContentInRange(const std::string &title, int startRow,
							  int endRow);

	std::shared_ptr<TextMatches> searchTextInBook(const std::string &title,
												  const std::string &text) const;
	Container<TextMatches> searchTextInAllBooks(const std::string &text) const;

	void clear();
	void open(const std::string &absoluteFilename);
	void exit();
	void save(/*TODO Some way that it knows the default absoluteFilename */);
	void saveAs(const std::string &absoluteFilename);

	std::shared_ptr<Author> searchPersonInAuthors(
		const std::string &name) const;
	std::shared_ptr<Book> searchBook(const std::string &title) const;
	std::shared_ptr<Reader> searchPersonInReaders(
		const std::string &name) const;

private:
	// std::shared_ptr<Author> searchPersonInAuthors(
	// 		const std::string &name) const;
	// using search to update created author in load
	std::shared_ptr<Reader> searchPersonInAuthorsAndReaders(
		const std::string &name) const;
	void printBooks(const Container<std::shared_ptr<Book>> &books) const;
	void removeBookFromAuthors(std::shared_ptr<Book> book);
	void removeBookFromReaders(std::shared_ptr<Book> book);
	void removeReader(const std::string &name);
	void removeAuthor(const std::string &name);
	void removeAllBooksFromAuthor(const std::string &name);
};

#endif
