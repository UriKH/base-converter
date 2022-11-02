#include "base_convertion.h"

#define ERROR_INT -1
#define MAX_BASE 35

std::string dec_to_other(int, int);
int to_decimal(int, std::string &);

std::string convert_base(int base, int new_base, std::string &num)
{
	// check number is in format
	for (auto &curr : num)
	{
		if (!isalnum(curr))
		{
			std::cout << "number not in format" << std::endl;
			return "";
		}
	}

	if (base > MAX_BASE || new_base > MAX_BASE)
		return "";

	int dec_num = to_decimal(base, num);
	if (dec_num == ERROR_INT)
		return "";

	if (new_base == 10)
		return std::to_string(dec_num);

	return dec_to_other(new_base, dec_num);
}

int to_decimal(int base, std::string &num){
	char curr;
	int dec_num = 0, digit;

	// convert to decimal format
	for (int i = 0; i < num.size(); i++)
	{
		curr = num[i];
		if (isdigit(curr))
			digit = (int)curr - '0';
		else
		{
			curr = toupper(curr);
			digit = 10 + curr - 'A'; // represent alphabetic character as digit of bases
		}
		if (digit > base)
		{
			std::cout << "number not in format" << std::endl;
			return ERROR_INT;
		}
		dec_num += digit * pow(base, num.size() - i - 1);
	}
	return dec_num;
}

std::string dec_to_other(int new_base, int dec_num)
{
	// convert from decimal base to other base
	int rem;
	std::vector<char> new_num;

	while (dec_num > 0)
	{
		rem = dec_num % new_base;
		if (rem <= 9)
			new_num.push_back((char)rem + '0');
		else
			new_num.push_back((char)('A' + rem - 10));

		dec_num = floor(dec_num / new_base);
	}

	std::reverse(new_num.begin(), new_num.end());
	return std::string(new_num.begin(), new_num.end());
}