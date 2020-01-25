#ifndef LIBRARYLOADER_H_
#define LIBRARYLOADER_H_

#include <iostream>
#include <memory>
#include <string>

class Book;
class Reader;
class Author;
class Library;

class LibraryLoader
{

public:
	LibraryLoader();

	std::shared_ptr<Library> load(const std::string &absoluteFilename);

private:
	void readBooks(std::ifstream &fin, std::shared_ptr<Library> library);
	std::shared_ptr<Book> readSingleBook(std::ifstream &fin,
										 std::shared_ptr<Library> library);
	void readBookTitle(std::ifstream &fin, std::shared_ptr<Book> book);
	void readPublicationYear(std::ifstream &fin, std::shared_ptr<Book> book);
	void readPrice(std::ifstream &fin, std::shared_ptr<Book> book);
	void readRatings(std::ifstream &fin, std::shared_ptr<Book> book);
	void readContentRows(std::ifstream &fin, std::shared_ptr<Book> book);
	void readAuthorNameAndCreateAuthor(std::ifstream &fin,
									   std::shared_ptr<Book> book, std::shared_ptr<Library> library);

	void readAuthors(std::ifstream &fin, std::shared_ptr<Library> library);
	void readSingleAuthor(std::ifstream &fin,
						  std::shared_ptr<Library> library);
	std::shared_ptr<Author> getAuthor(std::ifstream &fin,
									  std::shared_ptr<Library> library);
	void readAge(std::ifstream &fin, std::shared_ptr<Author> author);
	void readNationality(std::ifstream &fin, std::shared_ptr<Author> author);
	void readWrittenBooks(std::ifstream &fin, std::shared_ptr<Author> author,
						  std::shared_ptr<Library> library);
	void readReadBooks(std::ifstream &fin, std::shared_ptr<Author> author,
					   std::shared_ptr<Library> library);

	void readReaders(std::ifstream &fin, std::shared_ptr<Library> library);
	std::shared_ptr<Reader> readSingleReader(std::ifstream &fin,
											 std::shared_ptr<Library> library);
	void readName(std::ifstream &fin, std::shared_ptr<Reader> reader);
	std::shared_ptr<Reader> getReader(std::ifstream &fin,
									  std::shared_ptr<Library> library);
	void readAge(std::ifstream &fin, std::shared_ptr<Reader> reader);
	void readNationality(std::ifstream &fin, std::shared_ptr<Reader> reader);
	void readReadBooks(std::ifstream &fin, std::shared_ptr<Reader> reader,
					   std::shared_ptr<Library> library);

	void readBooksCount(std::ifstream &fin, std::shared_ptr<Library> library);
	void checkIntegerNumberLine(const std::string &line);
	bool containsOnlyDigits(const std::string &line);
	bool canFitInInt(const std::string &line);
};

#endif
