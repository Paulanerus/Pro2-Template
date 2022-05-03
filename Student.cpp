#include "Student.h"

Student::Student(std::string n, std::string nn, char g)
{
	this->name = n;
	this->nachname = nn;
	this->gruppe = g;
}

std::string Student::get_name()
{
	return this->name;
}

std::string Student::get_nachname()
{
	return this->nachname;
}

char Student::get_gruppe()
{
	return this->gruppe;
}