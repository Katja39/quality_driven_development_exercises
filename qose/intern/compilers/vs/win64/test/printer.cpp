#include "printer.h"
#include <iostream>

CPrinter& CPrinter::GetInstance() 
{
	static CPrinter s_Instance;
	return s_Instance;
}

void CPrinter::Print(const char* _pText) const
{
	std::cout << _pText;
}

CPrinter::CPrinter() 
{

}

CPrinter::~CPrinter() 
{

}