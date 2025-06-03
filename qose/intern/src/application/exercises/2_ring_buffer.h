#pragma once

#include <array>

class CRingBuffer
{
public:
	CRingBuffer();
	~CRingBuffer() = default;

	float Read();
	void Write(float _NewValue);
	int GetNumberValues() const;

	void Clear();
	int GetSize();

	bool IsEmpty() const;
	bool IsFull() const;

	static constexpr int GetMaxNumberOfValues() {return s_MaxNumberOfValues;};

private:
	static constexpr int s_MaxNumberOfValues = 8;

	using CArray = std::array<float, s_MaxNumberOfValues>;

	CArray m_Values;
	int    m_NumberOfValues;
	int    m_ReadPosition;
	int    m_WritePosition;
};
