#ifndef PRO2_U_5_STUDENT_H
#define PRO2_U_5_STUDENT_H

#include <vector>
#include <string>

class Student
{
private:
	std::string name, nachname, gruppe;

public:
	Student(std::string n, std::string nn, std::string g);

	std::string get_name() const;

	std::string get_nachname() const;

	std::string get_gruppe() const;

	static void read_them_all(std::vector<Student>& v);
};

#endif
