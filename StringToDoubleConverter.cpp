#include "StringToDoubleConverter.h"

double StringToDoubleConverter::convert(const std::string &stringNumber)
{
	return std::stod(stringNumber);
}
