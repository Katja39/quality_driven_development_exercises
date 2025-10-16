#include <iostream>
#include "../exercises/1_asserts.h"
#include "../exercises/2_test.h"
//#include "../exercises/3_exception.h"


void showMenu() 
{
	std::cout << "\nChoose an exercise:" << std::endl;
	std::cout << "1: Asserts" << std::endl;
	std::cout << "2: Tests" << std::endl;
	//std::cout << "3: Exceptions" << std::endl;
	std::cout << "0: Exit" << std::endl;
	std::cout << "> ";
}

int main()
{
	while (true) 
	{
		showMenu();

		int choice;
		if (!(std::cin >> choice)) 
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please enter a number.\n";
			continue;
		}

		switch (choice) 
		{
		case 1:
			exercise1_asserts();
			break;
		case 2:
			exercise2_tests();
			break;
		/*case 3:
			exercise3_exceptions();
		*/
		case 0:
			std::cout << "Exiting...\n";
			return 0;
		default:
			std::cout << "Invalid choice. Please try again.\n";
			break;
		}
	}
}
