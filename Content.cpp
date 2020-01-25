#include "Content.h"

#include <iostream>

Content::Content(const Container<std::string> &rows)
{
	this->rows = rows;
}

int Content::getNumberOfRows() const
{
	return rows.getSize();
}

//!! Should it be string& or string because of the Container.hpp change?
const std::string Content::getRow(int idx) const
{
	return this->rows.getElement(idx);
}

void Content::appendRow(const std::string &row)
{
	rows.insert(row);
}

void Content::print() const
{
	for (int i = 0; i < rows.getSize(); i++)
	{
		std::cout << rows.getElement(i) << std::endl;
	}
}
