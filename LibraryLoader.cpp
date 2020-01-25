#include "LibraryLoader.h"

#include <cassert>
#include <fstream>

#include "Author.h"
#include "Book.h"
#include "Library.h"
#include "StringToDoubleConverter.h"
#include "StringToIntegerConverter.h"

LibraryLoader::LibraryLoader()
{
}

std::shared_ptr<Library> LibraryLoader::load(
	const std::string &absoluteFilename)
{
	std::shared_ptr<Library> library = std::make_shared<Library>();

	std::ifstream fin(absoluteFilename);
	std::string line;
	while (getline(fin, line, '\n'))
	{
		if (line == "####### BOOKS #######")
		{
			readBooks(fin, library);
		}
		else if (line == "####### AUTHORS #######")
		{
			readAuthors(fin, library);
		}
		else if (line == "####### READERS #######")
		{
			readReaders(fin, library);
		}
		else
		{
			std::cerr << "Section name: "
					  << "|" << line << "|" << std::endl;
			assert(false && "Invalid file format - invalid section name");
		}
	}

	return library;
}

void LibraryLoader::readBooks(std::ifstream &fin,
							  std::shared_ptr<Library> library)
{
	std::string line;
	getline(fin, line, '\n');
	while (line != "####### END BOOKS #######")
	{
		if (line == "##### BOOK #####")
		{
			std::shared_ptr<Book> book = readSingleBook(fin, library);
			library->addBook(book);
		}
		else
		{
			assert(false && "Invalid file format");
		}
		getline(fin, line, '\n');
	}
}

std::shared_ptr<Book> LibraryLoader::readSingleBook(std::ifstream &fin,
													std::shared_ptr<Library> library)
{
	std::shared_ptr<Book> book = std::make_shared<Book>();
	std::string line;
	getline(fin, line, '\n');
	while (line != "##### END BOOK #####")
	{
		if (line == "### Title ###")
		{
			readBookTitle(fin, book);
		}
		else if (line == "### Publication Year ###")
		{
			readPublicationYear(fin, book);
		}
		else if (line == "### Price ###")
		{
			readPrice(fin, book);
		}
		else if (line == "### RATINGS ###")
		{
			readRatings(fin, book);
		}
		else if (line == "### CONTENT ROWS ###")
		{
			readContentRows(fin, book);
		}
		else if (line == "### Author Name ###")
		{
			readAuthorNameAndCreateAuthor(fin, book, library);
		}
		else
		{
			std::cerr << "Section name: "
					  << "|" << line << "|" << std::endl;
			assert(false && "Invalid file format - invalid section name");
		}
		getline(fin, line, '\n');
	}
	return book;
}

void LibraryLoader::readBookTitle(std::ifstream &fin,
								  std::shared_ptr<Book> book)
{
	std::string line;
	getline(fin, line, '\n');
	book->setTitle(line);
}

void LibraryLoader::readPublicationYear(std::ifstream &fin,
										std::shared_ptr<Book> book)
{
	std::string line;
	getline(fin, line, '\n');
	book->setPublicationYear(StringToIntegerConverter::convert(line));
}

void LibraryLoader::readPrice(std::ifstream &fin, std::shared_ptr<Book> book)
{
	std::string line;
	getline(fin, line, '\n');
	book->setPrice(StringToIntegerConverter::convert(line));
}

void LibraryLoader::readRatings(std::ifstream &fin,
								std::shared_ptr<Book> book)
{
	std::string line;
	getline(fin, line, '\n');
	while (line != "### END RATINGS ###")
	{
		book->addRating(StringToDoubleConverter::convert(line));
		getline(fin, line, '\n');
	}
}

void LibraryLoader::readContentRows(std::ifstream &fin,
									std::shared_ptr<Book> book)
{
	std::string line;
	getline(fin, line, '\n');
	while (line != "### END CONTENT ROWS ###")
	{
		book->appendRowToContent(line);
		getline(fin, line, '\n');
	}
}

void LibraryLoader::readAuthorNameAndCreateAuthor(std::ifstream &fin,
												  std::shared_ptr<Book> book, std::shared_ptr<Library> library)
{
	std::string line;
	getline(fin, line, '\n');
	std::shared_ptr<Author> author = std::make_shared<Author>(line);
	library->addAuthor(author);
	book->setAuthor(author);
}

void LibraryLoader::readAuthors(std::ifstream &fin,
								std::shared_ptr<Library> library)
{
	std::string line;
	getline(fin, line, '\n');
	while (line != "####### END AUTHORS #######")
	{
		if (line == "##### AUTHOR #####")
		{
			readSingleAuthor(fin, library);
		}
		else
		{
			std::cerr << "Section name: "
					  << "|" << line << "|" << std::endl;
			assert(false && "Invalid file format - invalid section name");
		}
		getline(fin, line, '\n');
	}
}

void LibraryLoader::readSingleAuthor(std::ifstream &fin,
									 std::shared_ptr<Library> library)
{
	std::shared_ptr<Author> author = getAuthor(fin, library);
	std::string line;
	getline(fin, line, '\n');
	while (line != "##### END AUTHOR #####")
	{
		if (line == "### Age ###")
		{
			readAge(fin, author);
		}
		else if (line == "### Nationality ###")
		{
			readNationality(fin, author);
		}
		else if (line == "### WRITTEN BOOKS ###")
		{
			readWrittenBooks(fin, author, library);
		}
		else if (line == "### READ BOOKS ###")
		{
			readReadBooks(fin, author, library);
		}
		else
		{
			std::cerr << "Section name: "
					  << "|" << line << "|" << std::endl;
			assert(false && "Invalid file format - invalid section name");
		}
		getline(fin, line, '\n');
	}
}

std::shared_ptr<Author> LibraryLoader::getAuthor(std::ifstream &fin,
												 std::shared_ptr<Library> library)
{
	std::shared_ptr<Author> author;
	std::string line;
	getline(fin, line, '\n');
	if (line == "### Name ###")
	{
		getline(fin, line, '\n');
		author = library->searchPersonInAuthors(line);
		if (!author)
		{
			std::cerr << "author name= "
					  << "|" << line << "|" << std::endl;
			assert(
				false && "Wrong file content. Current author doesn't have books in the library");
		}
	}
	else
	{
		std::cerr << "Section name: "
				  << "|" << line << "|" << std::endl;
		assert(false && "Invalid file format - invalid section name");
	}
	return author;
}

void LibraryLoader::readAge(std::ifstream &fin,
							std::shared_ptr<Author> author)
{
	std::string line;
	getline(fin, line, '\n');
	int number = StringToIntegerConverter::convert(line);
	author->setAge(StringToIntegerConverter::convert(line));
}

void LibraryLoader::readNationality(std::ifstream &fin,
									std::shared_ptr<Author> author)
{
	std::string line;
	getline(fin, line, '\n');
	author->setNationality(line);
}

void LibraryLoader::readWrittenBooks(std::ifstream &fin,
									 std::shared_ptr<Author> author, std::shared_ptr<Library> library)
{
	std::shared_ptr<Book> book;
	std::string line;
	getline(fin, line, '\n');
	while (line != "### END WRITTEN BOOKS ###")
	{
		book = library->searchBook(line);
		if (book == nullptr)
		{
			std::cerr << "Written book " << line << " from author "
					  << author->getName()
					  << " is not in our book repository. It will be skipped."
					  << std::endl;
		}
		else
		{
			author->writeBook(book);
		}
		getline(fin, line, '\n');
	}
}

void LibraryLoader::readReadBooks(std::ifstream &fin,
								  std::shared_ptr<Author> author, std::shared_ptr<Library> library)
{
	std::shared_ptr<Book> book;
	std::string line;
	getline(fin, line, '\n');
	while (line != "### END READ BOOKS ###")
	{
		book = library->searchBook(line);
		if (book == nullptr)
		{
			std::cerr << "Read book " << line << " from author "
					  << author->getName()
					  << " is not in our book repository. It will be skipped."
					  << std::endl;
		}
		else
		{
			author->readBook(book);
		}
		getline(fin, line, '\n');
	}
}

void LibraryLoader::readReaders(std::ifstream &fin,
								std::shared_ptr<Library> library)
{
	std::string line;
	getline(fin, line, '\n');
	while (line != "####### END READERS #######")
	{
		if (line == "##### READER #####")
		{
			std::shared_ptr<Reader> reader = readSingleReader(fin, library);
			library->addReader(reader);
		}
		else
		{
			std::cerr << "Section name: "
					  << "|" << line << "|" << std::endl;
			assert(false && "Invalid file format - invalid section name");
		}
		getline(fin, line, '\n');
	}
}

std::shared_ptr<Reader> LibraryLoader::readSingleReader(std::ifstream &fin,
														std::shared_ptr<Library> library)
{
	std::shared_ptr<Reader> reader = std::make_shared<Reader>();
	std::string line;
	getline(fin, line, '\n');
	while (line != "##### END READER #####")
	{
		if (line == "### Name ###")
		{
			readName(fin, reader);
		}
		else if (line == "### Age ###")
		{
			readAge(fin, reader);
		}
		else if (line == "### Nationality ###")
		{
			readNationality(fin, reader);
		}
		else if (line == "### READ BOOKS ###")
		{
			readReadBooks(fin, reader, library);
		}
		else
		{
			std::cerr << "Section name: "
					  << "|" << line << "|" << std::endl;
			assert(false && "Invalid file format - invalid section name");
		}
		getline(fin, line, '\n');
	}
	return reader;
}

void LibraryLoader::readName(std::ifstream &fin,
							 std::shared_ptr<Reader> reader)
{
	std::string line;
	getline(fin, line, '\n');
	reader->setName(line);
}

void LibraryLoader::readAge(std::ifstream &fin,
							std::shared_ptr<Reader> reader)
{
	std::string line;
	getline(fin, line, '\n');
	checkIntegerNumberLine(line);
	reader->setAge(StringToIntegerConverter::convert(line));
}

void LibraryLoader::readNationality(std::ifstream &fin,
									std::shared_ptr<Reader> reader)
{
	std::string line;
	getline(fin, line, '\n');
	reader->setNationality(line);
}

void LibraryLoader::readReadBooks(std::ifstream &fin,
								  std::shared_ptr<Reader> reader, std::shared_ptr<Library> library)
{
	std::shared_ptr<Book> book;
	std::string line;
	getline(fin, line, '\n');
	while (line != "### END READ BOOKS ###")
	{
		book = library->searchBook(line);
		if (book == nullptr)
		{
			std::cerr << "Read book " << line << " from reader "
					  << reader->getName()
					  << " is not in our book repository. It will be skipped."
					  << std::endl;
		}
		else
		{
			reader->readBook(book);
		}
		getline(fin, line, '\n');
	}
}

void LibraryLoader::readBooksCount(std::ifstream &fin,
								   std::shared_ptr<Library> library)
{
	std::string line;
	getline(fin, line, '\n');
	checkIntegerNumberLine(line);
	// skip saving this information
}

void LibraryLoader::checkIntegerNumberLine(const std::string &line)
{
	assert(containsOnlyDigits(line) && canFitInInt(line));
}

bool LibraryLoader::containsOnlyDigits(const std::string &line)
{
	for (int i = 0; i < line.length(); i++)
	{
		if (!('0' <= line[i] && line[i] <= '9'))
		{
			return false;
		}
	}
	return true;
}

bool LibraryLoader::canFitInInt(const std::string &line)
{
	return containsOnlyDigits(line) && line.length() < 1e9;
}
