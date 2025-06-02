#pragma once

class CAssertHandler
{
	public:
		// virtual destructor, because this class can be inherited
		virtual ~CAssertHandler() = default;
	
	public:
		//Only calls the corresponding intern method
		void OnError(const char* _pMessage, const char* pFile, unsigned int _Line);
		//abstract, class also abstract
		//Public virtual methods are bad style, so OnInternError
	
	private:
		virtual void OnInternError(const char* _pMessage, const char* _pFile, unsigned int _Line) = 0;
};


class CDefaultAssertHandler : public CAssertHandler
{
	private:
		void OnInternError(const char* _pMessage, const char* _pFile, unsigned int _Line) override;
};


//AssertSystem owns the AssertHandler (which defines what happens during an assertion)
class CAssertSystem
{
	public:
		//Singleton
		//AssertSystem global
		static CAssertSystem& GetInstance();
	
	public:
		void SetHandler(CAssertHandler* _pHandler);
	
	public:
		//Only calls the corresponding intern method
		void OnError(const char* _pMessage, const char* pFile, unsigned int _Line);
	
	private:
		CAssertHandler* m_pHandler;
	
	private:
		CAssertSystem();
		~CAssertSystem() = default;
	
	private:
		CAssertSystem(const CAssertSystem&) = delete;
		CAssertSystem& operator = (CAssertSystem&) = delete;
};

#ifdef HAS_ASSERTS
#define CUSTOM_TEST_ASSERT(Expression) if (!(Expression)) CAssertSystem::GetInstance().OnError(#Expression, __FILE__, __LINE__)
#else
#define CUSTOM_TEST_ASSERT(Expression) ((void) 0)
#endif