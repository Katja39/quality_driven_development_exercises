#include "1_test_assert.h"
#include <iostream>

void CAssertHandler::OnError(const char* pMessage, const char* pFile, unsigned int line)
{
	OnInternError(pMessage, pFile, line);
}


void CDefaultAssertHandler::OnInternError(const char* _pMessage, const char* _pFile, unsigned int _Line)
{
	std::cout << "Assert" << _pMessage << "in file" << _pFile << "and line" << _Line << std::endl;
}


//Scott Meyers Singleton
//good on startup, bad on shutdown
CAssertSystem& CAssertSystem::GetInstance()
{
	static CAssertSystem s_Instance;
	return s_Instance;
}

CAssertSystem::CAssertSystem() : m_pHandler(nullptr)
{
}

void CAssertSystem::SetHandler(CAssertHandler* _pHandler)
{
	m_pHandler = _pHandler;
}

void CAssertSystem::OnError(const char* _pMessage, const char* _pFile, unsigned int _Line)
{
	m_pHandler->OnError(_pMessage, _pFile, _Line);
}
