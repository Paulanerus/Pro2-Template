#include <iostream>
#include <vector>
#include <string>

template<typename T>
void print_vec(const std::vector<T>& v)
{
	for (auto& i: v)
	{
		std::cout << i << std::endl;
	}
}


int main()
{
	std::vector<int> v = { 10, 7, 9, 8, 1, 2, 3, 4, 5, 6 };

	std::vector<std::string> v2 = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j" };

	print_vec(v);

	//Sort

	print_vec(v2);

	return 0;
}
