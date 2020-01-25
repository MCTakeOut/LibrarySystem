#ifndef CONTENT_H_
#define CONTENT_H_

#include <climits>
#include <string>

#include "Container.hpp"

class Content
{
	Container<std::string> rows;

public:
	Content(const Container<std::string> &rows = Container<std::string>());
	Content(const Content &other) = delete;

	int getNumberOfRows() const;
	const std::string getRow(int idx) const;

	void appendRow(const std::string &row);

	static const int MAX_ROWS = INT_MAX;

	void print() const;
};

#endif
