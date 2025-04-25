#ifndef TEST_ASSERT_H
#define TEST_ASSERT_H

#include <iostream>

#define TEST_ASSERT(condition) \
    do { \
        if (!(condition)) { \
            std::cerr << "Assertion failed: " << #condition << "\n" \
                      << "File: " << __FILE__ << "\n" \
                      << "Line: " << __LINE__ << std::endl; \
            std::terminate(); \
        } \
    } while (false)

#endif
