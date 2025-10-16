#pragma once
class CPrinter 
{
public:
	// Singleton
	static CPrinter& GetInstance();

	void Print(const char* _pText) const;

	CPrinter(const CPrinter&) = delete;
	CPrinter& operator = (const CPrinter&) = delete;

private:
	CPrinter() = default;
	~CPrinter() = default;
};

int exercise4_printer();