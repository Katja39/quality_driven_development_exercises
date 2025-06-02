#include <iostream>
#include "../exercises/1_asserts.h"
#include "../exercises/2_test.h"

int main()
{
	bool loop = true;
	int i = 0;

	while (loop)
	{
		i = 0;

		std::cout << "\nChoose an exercice" << std::endl;
		std::cout << "1: Asserts" << std::endl;
		std::cout << "2: Tests" << std::endl;

		std::cin >> i;

		switch (i)
		{
		case 1: exercise1_asserts();
			break;
		case 2:
			exercise2_tests();
			break;
		default:
			loop = false;
			break;
		}
	}

	return 0;
}
