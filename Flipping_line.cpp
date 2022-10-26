#include <iostream>

void flipLine()
{
	std::string str = "message";

	for (int i = 0, j = str.length() - 1; i <= str.length() / 2; )
	{
		//std::cout << str[i] << "\t" << str[j] << std::endl; //show movable symbols in each iteration
		char temp = str[i];
		str[i++] = str[j];
		str[j--] = temp;
	}

	std::cout << str;
}