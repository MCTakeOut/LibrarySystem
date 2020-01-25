#include "Book.h"

#include <cmath>

#include "Author.h"
#include "Reader.h"

Book::Book() : content(), price(0.0), publicationYear(0)
{
}

Book::Book(const std::string &title, const Content &content,
		   std::shared_ptr<Author> author, const double &price,
		   const Container<double> &ratings, int publicationYear) : title(title), author(author), price(price), publicationYear(publicationYear)
{
	this->content = content;
	this->ratings = ratings;
}

Book::Book(const std::string &title, int publicationYear,
		   std::shared_ptr<Author> author, int price) : title(title), author(author), price(price), publicationYear(publicationYear)
{
}

Book::Book(const std::string &title) : title(title), price(0.0), publicationYear(0)
{
}

bool Book::operator==(const Book &other) const
{
	return title == other.title;
}

std::shared_ptr<Author> Book::getAuthor() const
{
	return author;
}

const Content &Book::getContent() const
{
	return content;
}

double Book::getPrice() const
{
	return price;
}

int Book::getPublicationYear() const
{
	return publicationYear;
}

const Container<double> &Book::getRatings() const
{
	return ratings;
}

const std::string &Book::getTitle() const
{
	return title;
}

int Book::getNumberOfRows() const
{
	return content.getNumberOfRows();
}

int Book::getNumberOfTimesItWasReadByReaders(
	const Container<std::shared_ptr<Reader>> &readers) const
{
	int count = 0;
	for (int i = 0; i < readers.getSize(); i++)
	{
		std::shared_ptr<Reader> reader = readers.getElement(i);
		count += getNumberOfTimesItWasReadBySingleReader(reader.get());
	}

	return count;
}

int Book::getNumberOfTimesItWasReadByAuthors(
	const Container<std::shared_ptr<Author>> &authors) const
{
	int count = 0;
	for (int i = 0; i < authors.getSize(); i++)
	{
		std::shared_ptr<Reader> author = authors.getElement(i);
		count += getNumberOfTimesItWasReadBySingleReader(author.get());
	}

	return count;
}

int Book::getNumberOfTimesItWasReadBySingleReader(const Reader *reader) const
{
	int count = 0;
	const Container<std::shared_ptr<Book>> &readBooks = reader->getReadBooks();
	for (int j = 0; j < readBooks.getSize(); j++)
	{
		std::shared_ptr<Book> book = readBooks.getElement(j);
		if (this == book.get())
		{
			count++;
		}
	}

	return count;
}

double Book::getOverallRating() const
{
	double ratingSum = 0.0;
	for (int i = 0; i < ratings.getSize(); i++)
	{
		ratingSum += ratings.getElement(i);
	}

	double rating = ratingSum / ratings.getSize();
	double floorRating = floor(rating);
	if (rating - floorRating < 0.5)
	{
		return floorRating;
	}
	else
	{
		return floorRating + 0.5;
	}

	return rating;
}

void Book::addRating(double rating)
{
	ratings.insert(rating);
}

void Book::setAuthor(const std::shared_ptr<Author> &author)
{
	this->author = author;
}

void Book::setContent(const Content &content)
{
	this->content = content;
}

void Book::setPrice(double price)
{
	this->price = price;
}

void Book::setPublicationYear(int publicationYear)
{
	this->publicationYear = publicationYear;
}

void Book::setRatings(const Container<double> &ratings)
{
	this->ratings = ratings;
}

void Book::setTitle(const std::string &title)
{
	this->title = title;
}

void Book::appendRowToContent(const std::string &row)
{
	content.appendRow(row);
}
