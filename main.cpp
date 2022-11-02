#include "base_convertion.h"

bool check_if_int(std::string &);

int main() {
	// get input
	std::string base, new_base, num;
	std::cout << "Enter origional base: ";
	std::cin >> base;
	std::cout << "Enter new base: ";
	std::cin >> new_base;

	// check if the base is integer
	if (!check_if_int(base) || !check_if_int(new_base))
	{
		std::cout << "base is not an integer" << std::endl;
		return 1;
	}

	std::cout << "Enter number to convert: ";
	std::cin >> num;
	std::string new_num = convert_base(stoi(base), stoi(new_base), num);
	if (new_num != "")
		std::cout << "converted to: " << new_num << std::endl;
}

bool check_if_int(std::string &num_str)
{
	for (auto &curr : num_str)
	{
		if (!isdigit(curr))
			return false;
	}
	return true;
}