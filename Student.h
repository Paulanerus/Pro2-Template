#ifndef PRO2_U_5_STUDENT_H
#define PRO2_U_5_STUDENT_H

#include "string"

class Student
{
private:
	std::string name, nachname;
	char gruppe;
public:
	Student(std::string n, std::string nn, char g);

	std::string get_name();

	std::string get_nachname();

	char get_gruppe();
};

#endif
