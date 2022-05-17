#ifndef PRO2_U_5_STUDENT_H
#define PRO2_U_5_STUDENT_H

#include <vector>
#include <string>

class Student
{
private:
	std::string name, nachname, gruppe;

public:
	static int sort;

	Student(std::string n, std::string nn, std::string g);

	std::string get_name() const;

	std::string get_nachname() const;

	std::string get_gruppe() const;

	bool operator>(const Student& s);

	bool operator<(const Student& s);

	static void read_them_all(std::vector<Student>& v);
};

#endif
