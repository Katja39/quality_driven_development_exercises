#include "list.h"

void CList::PushBack(float _Value) 
{
	SNode* pNode = new SNode();

	pNode->m_Value = _Value;
	pNode->m_pNext = nullptr;
	pNode->m_pPrevious = m_pLast;

	if (pNode->m_pPrevious != nullptr) 
	{
		pNode->m_pPrevious->m_pNext = pNode;
	}
	else 
	{
		m_pFirst = pNode;
	}

	m_pLast = pNode;
}

void CList::PopBack() {
	SNODE* pLast = m_Last->m_pPrevious;

	if (pLast == nullptr)
	{
		m_pFirst = nullptr;
	}
	else
	{
		pLast->m_pNext = nullptr;
	}

	delete m_pLast;

	m_pLast = pLast;
}