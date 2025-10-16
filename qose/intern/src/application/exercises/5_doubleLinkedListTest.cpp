#include "unittest/ut_test.h"
#include "5_doubleLinkedList.h"
#include "5_doubleLinkedListTest.h"

UT_TEST(TestIsEmptyOnNewList)
{
    CDoubleLinkedList list;
    UT_CHECK(list.IsEmpty() == true);
    UT_CHECK(list.GetElementCount() == 0);
}

UT_TEST(TestPushBack)
{
    CDoubleLinkedList list;
    list.PushBack(1);
    UT_CHECK(list.IsEmpty() == false);
    UT_CHECK(list.GetElementCount() == 1);
    UT_CHECK(list.GetFront() == 1);

    list.PushBack(2);
    UT_CHECK(list.GetElementCount() == 2);
}

UT_TEST(TestPopBack)
{
    CDoubleLinkedList list;
    list.PushBack(1);
    list.PushBack(2);

    list.PopBack();
    UT_CHECK(list.GetElementCount() == 1);
    UT_CHECK(list.GetFront() == 1);

    list.PopBack();
    UT_CHECK(list.IsEmpty() == true);
}

UT_TEST(TestGetFront)
{
    CDoubleLinkedList list;
    list.PushBack(10);
    list.PushBack(20);

    UT_CHECK(list.GetFront() == 10);
}

UT_TEST(TestEmptyListExceptions)
{
    CDoubleLinkedList list;

    bool popBackException = false;
    try {
        list.PopBack();
    }
    catch (const std::out_of_range&) {
        popBackException = true;
    }
    UT_CHECK(popBackException == true);

    bool getFrontException = false;
    try {
        list.GetFront();
    }
    catch (const std::out_of_range&) {
        getFrontException = true;
    }
    UT_CHECK(getFrontException == true);
}

UT_TEST(TestElementCount)
{
    CDoubleLinkedList list;
    UT_CHECK(list.GetElementCount() == 0);

    list.PushBack(5);
    UT_CHECK(list.GetElementCount() == 1);

    list.PushBack(10);
    UT_CHECK(list.GetElementCount() == 2);

    list.PopBack();
    UT_CHECK(list.GetElementCount() == 1);
}