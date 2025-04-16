
#include <iostream>
#include "asserts.h";

int main()
{
	bool loop = true;
	int i = 0;

	while (loop)
	{
	i = 0;

    std::cout << "Choose the exercices" << std::endl;
    std::cout << "1: Asserts" << std::endl;

	std::cin >> i;

	switch (i)
	{
	case 1: asserts();
		break;
	default:
		loop = false;
		break;
	}
	}
}