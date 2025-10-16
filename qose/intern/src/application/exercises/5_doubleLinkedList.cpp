#include "5_doubleLinkedList.h"
#include <stdexcept>

CDoubleLinkedList::CDoubleLinkedList():m_pHead(nullptr), m_pTail(nullptr), m_Size(0)
{
}

CDoubleLinkedList::~CDoubleLinkedList()
{
	while (!IsEmpty()) PopBack();
}

void CDoubleLinkedList::PushBack(int _Value) {
    SNode* pNewNode = new SNode(_Value, m_pTail, nullptr); 

    if (m_pTail)
        m_pTail->m_pNext = pNewNode;
    else
        m_pHead = pNewNode;

    m_pTail = pNewNode;
    ++m_Size;
}

void CDoubleLinkedList::PopBack()
{
    if (!m_pTail) return;

    SNode* pTemp = m_pTail;
    m_pTail = m_pTail->m_pPrev;

    if (m_pTail)
        m_pTail->m_pNext = nullptr;
    else
        m_pHead = nullptr;

    delete pTemp;
    --m_Size;
}

int CDoubleLinkedList::GetFront() const {
    if (IsEmpty()) {
        throw std::out_of_range("List is empty");
    }

    return m_pHead->m_Value;
}

bool CDoubleLinkedList::IsEmpty() const
{
    return m_Size == 0;
}

int CDoubleLinkedList::GetElementCount() const
{
    return m_Size;
}
