#ifndef BOOK_H_
#define BOOK_H_

#include <memory>
#include <string>

#include "Container.hpp"
#include "Content.h"

class Reader;
class Author;
class LibraryLoader;

class Book
{

	std::string title;
	Content content;
	std::shared_ptr<Author> author;
	double price;
	Container<double> ratings;
	int publicationYear;

public:
	Book();
	Book(const std::string &title, const Content &content,
		 std::shared_ptr<Author> author, const double &price = 0.0,
		 const Container<double> &ratings = Container<double>(),
		 int publicationYear = 0);
	Book(const std::string &title, int publicationYear,
		 std::shared_ptr<Author> author, int price);
	Book(const std::string &title);

	Book(const Book &other) = delete;

	bool operator==(const Book &other) const;

	const std::string &getTitle() const;
	const Content &getContent() const;
	std::shared_ptr<Author> getAuthor() const;
	double getPrice() const;
	const Container<double> &getRatings() const;
	int getPublicationYear() const;

	int getNumberOfRows() const;
	int getNumberOfTimesItWasReadByReaders(
		const Container<std::shared_ptr<Reader>> &readers) const;
	int getNumberOfTimesItWasReadByAuthors(
		const Container<std::shared_ptr<Author>> &authors) const;
	double getOverallRating() const;
	void addRating(double rating);

	void setAuthor(const std::shared_ptr<Author> &author);
	void setContent(const Content &content);
	void setPrice(double price);
	void setPublicationYear(int publicationYear);
	void setRatings(const Container<double> &ratings);
	void setTitle(const std::string &title);

	void appendRowToContent(const std::string &row);

private:
	int getNumberOfTimesItWasReadBySingleReader(const Reader *reader) const;
};

#endif
