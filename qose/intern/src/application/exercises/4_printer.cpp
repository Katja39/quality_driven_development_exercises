#include "4_printer.h"
#include <iostream>

//Practice exam 1, task 1
// Summary task:
// Implement a CPrinter class with:
// - Print method that outputs given text to the console
// - prevent multiple instances
// - Blocked unauthorized instantiation / copying

// singleton instance
CPrinter& CPrinter::GetInstance() 
{
	static CPrinter s_Instance;
	return s_Instance;
}

void CPrinter::Print(const char* _pText) const
{
	std::cout << _pText;
}

int exercise4_printer() 
{
	CPrinter& rInstance = CPrinter::GetInstance();
	rInstance.Print("Test text");

	return 0;
}