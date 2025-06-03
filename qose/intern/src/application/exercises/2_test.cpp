#include "unittest/ut_test.h"

#include <iostream>

#include "2_test.h"
#include "2_ring_buffer.h"

void TestConstructor()
{
    std::cout << "[TestConstructor] Starting test\n";

    CRingBuffer Buffer;
    UT_CHECK(Buffer.GetNumberValues() == 0);

    std::cout << "[TestConstructor] Buffer is empty as expected.\n\n";
}

void TestClear()
{
    std::cout << "[TestClear] Starting test\n";

    CRingBuffer Buffer;
    Buffer.Write(1.0f);
    Buffer.Write(2.0f);
    std::cout << "[TestClear] Two values written, number of values: " << Buffer.GetNumberValues() << "\n";

    UT_CHECK(Buffer.GetNumberValues() == 2);

    Buffer.Clear();
    std::cout << "[TestClear] Buffer cleared, number of values: " << Buffer.GetNumberValues() << "\n";

    UT_CHECK(Buffer.GetNumberValues() == 0);

    float value = Buffer.Read();
    std::cout << "[TestClear] Reading from empty buffer returns: " << value << "\n";

    UT_CHECK(value == 0.0f);

    std::cout << "[TestClear] Test completed successfully.\n\n";
}

void TestWriteRead()
{
    std::cout << "[TestWriteRead] Starting test\n";

    CRingBuffer Buffer;
    Buffer.Write(3.5f);
    Buffer.Write(7.1f);
    std::cout << "[TestWriteRead] Two values written, number of values: " << Buffer.GetNumberValues() << "\n";

    UT_CHECK(Buffer.GetNumberValues() == 2);

    float v1 = Buffer.Read();
    float v2 = Buffer.Read();

    std::cout << "[TestWriteRead] Read values: " << v1 << ", " << v2 << "\n";

    UT_CHECK(v1 == 3.5f);
    UT_CHECK(v2 == 7.1f);
    UT_CHECK(Buffer.GetNumberValues() == 0);

    std::cout << "[TestWriteRead] Test completed successfully.\n\n";
}

void TestOverwrite()
{
    std::cout << "[TestOverwrite] Starting test\n";

    CRingBuffer Buffer;

    constexpr int TotalWrites = CRingBuffer::GetMaxNumberOfValues() + 3;  // force overflow
    std::cout << "[TestOverwrite] Writing " << TotalWrites << " values to buffer with max size "
        << CRingBuffer::GetMaxNumberOfValues() << "\n";

    for (int i = 0; i < TotalWrites; ++i)
    {
        Buffer.Write((float)i);
    }

    std::cout << "[TestOverwrite] Number of values after writing: " << Buffer.GetNumberValues() << "\n";
    UT_CHECK(Buffer.GetNumberValues() == CRingBuffer::GetMaxNumberOfValues());

    int expectedStart = TotalWrites - CRingBuffer::GetMaxNumberOfValues();
    std::cout << "[TestOverwrite] Expected values start at: " << expectedStart << "\n";

    for (int i = expectedStart; i < TotalWrites; ++i)
    {
        float v = Buffer.Read();
        std::cout << "[TestOverwrite] Read value: " << v << "\n";
        UT_CHECK(v == (float)i);
    }

    UT_CHECK(Buffer.GetNumberValues() == 0);

    std::cout << "[TestOverwrite] Test completed successfully.\n\n";
}

int exercise2_tests()
{
    std::cout << "Starting RingBuffer tests\n\n";

    TestConstructor();
    TestClear();
    TestWriteRead();
    TestOverwrite();

    std::cout << "All tests passed successfully\n";
    return 0;
}