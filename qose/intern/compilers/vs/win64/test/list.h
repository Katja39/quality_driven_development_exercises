#pragma once
class CList {
public:
	void PopBack();
	void PushBack(float _Value);

private:
	struct SNode 
	{
		float m_Value;
		SNode* m_pNext;
		SNode* 
	};
};