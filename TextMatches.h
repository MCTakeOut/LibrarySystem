#ifndef TEXTMATCHES_H_
#define TEXTMATCHES_H_

#include <memory>

#include "Container.hpp"
#include "MatchingRange.h"
#include "Book.h"

class TextMatches
{
	std::shared_ptr<Book> book;
	Container<MatchingRange> matchingRanges;

public:
	TextMatches(std::shared_ptr<Book> book);

	void addMatchRange(int startRow, int startColumn, int endRow, int endColumn);
};

#endif
