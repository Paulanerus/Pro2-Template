#include "Student.h"
#include "StudentFileNotFoundException.h"
#include <fstream>
#include <string>

Student::Student(std::string n, std::string nn, std::string g)
{
	this->name = n;
	this->nachname = nn;
	this->gruppe = g;
}

std::string Student::get_name() const
{
	return this->name;
}

std::string Student::get_nachname() const
{
	return this->nachname;
}

std::string Student::get_gruppe() const
{
	return this->gruppe;
}

void Student::read_them_all(std::vector<Student>& v)
{
	std::fstream students_file;
	students_file.open("data/Studenten.txt");

	if (students_file.fail())
	{
		throw StudentFileNotFoundException();
	}

	std::string line;
	while (std::getline(students_file, line))
	{
		std::string elements[3];

		size_t counter = 0;

		for (char current: line)
		{
			if (current == '\t')
			{
				counter++;
				continue;
			}

			elements[counter] += current;
		}

		v.emplace_back(elements[1], elements[0], elements[2]);
	}

	students_file.close();
}