#include <iostream>
#include <vector>
#include <string>
#include "Student.h"
#include "fstream"
#include "StudentFileNotFoundException.h"

std::ostream& operator<<(std::ostream& os, const Student& s)
{
	os << s.get_name() << " " << s.get_nachname() << " ist in der Gruppe: " << s.get_gruppe();

	return os;
}

template<typename T>
void print_vec(const std::vector<T>& v)
{
	for (auto& i: v)
	{
		std::cout << i << "\n";
	}

	std::cout << std::endl;
}

template<typename T>
void simple_sort(std::vector<T>& v)
{
	for (size_t i = 0; i < v.size() - 1; i++)
	{
		size_t min = i;
		for (size_t j = i + 1; j < v.size(); j++)
		{
			if (v.at(j) < v.at(min))
			{
				min = j;
			}
		}

		std::swap(v.at(i), v.at(min));
	}
}

void shuffle_students(std::vector<Student>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		std::swap(v[std::rand() % v.size()], v[std::rand() % v.size()]);
	}
}

template<typename T>
void insert_sort(std::vector<T>& v)
{
	for (int i = 0; i < v.size() - 1; i++)
	{
		T element = v.at(i + 1);
		int j = i;

		while (j >= 0 && (element < v.at(j)))
		{
			v[j + 1] = v[j];
			j--;
		}

		v[j + 1] = element;
	}
}

template<typename T>
void bubble_sort(std::vector<T>& v)
{
	for (size_t i = 0; i < v.size() - 1; i++)
	{
		for (size_t j = i + 1; j < v.size(); j++)
		{
			if (v.at(i) > v.at(j))
			{
				std::swap(v.at(i), v.at(j));
			}
		}
	}
}

int main()
{
	std::srand(time(nullptr));

	std::vector<int> v = { 10, 7, 9, 8, 1, 2, 3, 4, 5, 6 };

	std::vector<std::string> v2 = { "Bali", "Jonas", "Ingo", "Adam", "Detlef", "Ewald", "Carl", "Georg", "Harald",
									"Floarian" };
	print_vec(v);
	simple_sort(v);
	print_vec(v);

	std::cout << "=================================================" << std::endl;

	print_vec(v2);
	simple_sort(v2);
	print_vec(v2);

	std::cout << "=================================================" << std::endl;

	std::vector<Student> students;

	try
	{
		Student::read_them_all(students);
	}
	catch (StudentFileNotFoundException& e)
	{
		std::cout << "[EXCEPTION] Datei existiert nicht/kann nicht geoeffnet werden!" << std::endl;
	}

	print_vec(students);

	std::cout << "Sortierung: Name dann Gruppe" << std::endl;

	std::cout << "Simple Sort" << std::endl;
	std::cout << "=================================================" << std::endl;

	shuffle_students(students);

	Student::sort = 0;

	simple_sort(students);

	Student::sort = 1;

	simple_sort(students);

	print_vec(students);

	std::cout << "Bubble Sort" << std::endl;
	std::cout << "=================================================" << std::endl;

	shuffle_students(students);

	Student::sort = 0;

	bubble_sort(students);

	Student::sort = 1;

	bubble_sort(students);

	print_vec(students);

	std::cout << "Insert Sort" << std::endl;
	std::cout << "=================================================" << std::endl;

	shuffle_students(students);

	Student::sort = 0;

	insert_sort(students);

	Student::sort = 1;

	insert_sort(students);

	print_vec(students);

	std::cout << "Sortierung: Gruppe dann Nachname" << std::endl;

	std::cout << "Simple Sort" << std::endl;
	std::cout << "=================================================" << std::endl;

	shuffle_students(students);

	Student::sort = 1;

	simple_sort(students);

	Student::sort = 2;

	simple_sort(students);

	print_vec(students);

	std::cout << "Bubble Sort" << std::endl;
	std::cout << "=================================================" << std::endl;

	shuffle_students(students);

	Student::sort = 1;

	bubble_sort(students);

	Student::sort = 2;

	bubble_sort(students);

	print_vec(students);

	std::cout << "Insert Sort" << std::endl;
	std::cout << "=================================================" << std::endl;

	shuffle_students(students);

	Student::sort = 1;

	insert_sort(students);

	Student::sort = 2;

	insert_sort(students);

	print_vec(students);

	return 0;
}
