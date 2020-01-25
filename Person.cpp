#include "Person.h"

Person::Person(const std::string &name, const std::string &nationality, int age) : name(name), nationality(nationality), age(age)
{
}

const std::string &Person::getName() const
{
	return name;
}

void Person::setName(const std::string &name)
{
	this->name = name;
}

const std::string &Person::getNationality() const
{
	return nationality;
}

void Person::setNationality(const std::string &nationality)
{
	this->nationality = nationality;
}

int Person::getAge() const
{
	return age;
}

void Person::setAge(const int age)
{
	this->age = age;
}

bool Person::operator==(const Person &other) const
{
	return name == other.name;
}
