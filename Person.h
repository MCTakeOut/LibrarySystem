#ifndef PERSON_H_
#define PERSON_H_

#include <memory>
#include "Book.h"
#include "Container.hpp"

class Person
{
private:
	std::string name;
	std::string nationality;
	int age;

public:
	Person(const std::string &name = "", const std::string &nationality = "",
		   int age = 0);
	const std::string &getName() const;
	void setName(const std::string &name);
	const std::string &getNationality() const;
	void setNationality(const std::string &nationality);
	int getAge() const;
	void setAge(const int age);

	bool operator==(const Person &other) const;
};

#endif
