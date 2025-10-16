#pragma once
class CPrinter 
{
public:
	static CPrinter& GetInstance();
	void Print(const char* _pText) const;

private:
	CPrinter();
	~CPrinter();

	CPrinter(const CPrinter&) = delete;
	CPrinter& operator = (const CPrinter&) = delete;
};