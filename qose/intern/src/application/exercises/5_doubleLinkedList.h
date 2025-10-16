#pragma once

class CDoubleLinkedList 
{
private:
	struct SNode {
		int m_Value;
		SNode* m_pPrev;
		SNode* m_pNext;

		SNode(int val, SNode* p = nullptr, SNode* n = nullptr)
			: m_Value(val), m_pPrev(p), m_pNext(n) {}
	};

	SNode* m_pHead;
	SNode* m_pTail;
	int m_Size;

public:
	CDoubleLinkedList();
	~CDoubleLinkedList();

	void PushBack(int _Value);
	void PopBack();
	int GetFront() const;
	bool IsEmpty() const;
	int GetElementCount() const;
};