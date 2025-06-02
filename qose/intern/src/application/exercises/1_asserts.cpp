#define HAS_ASSERTS

#include <iostream>
#include <string>

#include <cassert>
#include "1_test_assert.h"
#include "1_asserts.h"

float g_Values[5];

void SetValue(int _Index, float _Value)
{
	assert((_Index >= 0) && (_Index < 5));
	g_Values[_Index] = _Value;
}

static int GetHashValue(const char* _pCharArray, int _Length) {
	//Assertions for input values
	assert(_pCharArray != nullptr);
	//assert(_pCharArray != nullptr && "Char array pointer must not be null");
	assert(_Length >= 0);
	//assert(_Length >= 0 && "Length must be non-negative");

	if (_pCharArray == nullptr || _Length <= 0) {
		return 0;
	}

	int Hash = 0;
	for (int i = 0; i < _Length; i++) {
		Hash = 31 * Hash + _pCharArray[i];
		assert(Hash >= 0);
		//assert(Hash >= 0 && "Hash value overflow detected"); //n>5
	}
	return Hash;
}


void exercise1_asserts()
{
	/*Task0
	std::cout << "x=5" << std::endl;
	int x = 5;
	assert(x == 5);  // ok

	int Index = 0;
	std::cout << "Input array range" << std::endl;
	std::cin >> Index;

	if ((Index >= 0) && (Index < 5))
	{
		SetValue(Index, 10.0f);
	}*/

	/*
	* Task1
	* How Java Calculates String Hashcode
	* s[0]*31^(n-1) + s[1]*31^(n-2) + ... + s[n-1]
	* s[i] is the i-th character of the String and n the length of the String
	*/

	//Task3 Calculate hash

	std::string Input;
	std::cout << "Type in a word to calculate the hash value" << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, Input);

	int hash = GetHashValue(Input.c_str(), Input.length());
	std::cout << "Calculated hash " << hash << "\n" << std::endl;


	//Custom Assert
	std::cout << "Custom assert" << std::endl;

	CDefaultAssertHandler* pHandler = new CDefaultAssertHandler();

	CAssertSystem::GetInstance().SetHandler(pHandler);

	int Value = 0;

	std::cout << "Enter a value. An assert will be triggered if the value is 3 or less" << std::endl;

	std::cin >> Value;

	CUSTOM_TEST_ASSERT(Value > 3);

	CAssertSystem::GetInstance().SetHandler(nullptr);

	delete pHandler;
}