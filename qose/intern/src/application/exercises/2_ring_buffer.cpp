#include "2_ring_buffer.h"

CRingBuffer::CRingBuffer()
	:m_NumberOfValues(0)
	,m_ReadPosition(0)
	,m_WritePosition(0)
{
	m_Values.fill(0.0f);
}

float CRingBuffer::Read()
{
	if (m_NumberOfValues == 0)
	{
		return 0.0f;
	}

	float Value = m_Values[m_ReadPosition];
	m_ReadPosition = (m_ReadPosition + 1) % s_MaxNumberOfValues;
	--m_NumberOfValues;

	return Value;
}

void CRingBuffer::Write(float _NewValue)
{
	m_Values[m_WritePosition] = _NewValue;
	m_WritePosition = (m_WritePosition + 1) % s_MaxNumberOfValues;

	if (m_NumberOfValues < s_MaxNumberOfValues)
	{
		++m_NumberOfValues;
	}
	else
	{
		// Buffer is full, overwrite oldest value -> advance read position
		m_ReadPosition = (m_ReadPosition + 1) % s_MaxNumberOfValues;
	}
}

int CRingBuffer::GetNumberValues() const
{
	return m_NumberOfValues;
}

void CRingBuffer::Clear() 
{
	m_NumberOfValues = 0;
	m_Values.fill(0.0f);
	m_ReadPosition = 0;
	m_WritePosition = 0;
}

int CRingBuffer::GetSize()
{
	return m_NumberOfValues;
}

bool CRingBuffer::IsEmpty() const
{
	if (m_NumberOfValues == 0) 
	{
		return true;
	}

	return false;
}

bool CRingBuffer::IsFull() const
{
	if (m_NumberOfValues == s_MaxNumberOfValues)
	{
		return true;
	}

	return false;
}