#ifndef CPPUTESTS_HPP
#define CPPUTESTS_HPP

#include "implementations.hpp"

#define ASSERT_EQUAL(a, b) cppUTests::AssertEqualImpl((a), (b), #a, #b, false, __FILE__, __FUNCTION__, __LINE__, ""s)

#define ASSERT_EQUAL_FULL_INFO(a, b) cppUTests::AssertEqualImpl((a), (b), #a, #b, true, __FILE__, __FUNCTION__, __LINE__, ""s)

#define ASSERT_EQUAL_HINT(a, b, hint) cppUTests::AssertEqualImpl((a), (b), #a, #b, false, __FILE__, __FUNCTION__, __LINE__, (hint))

#define ASSERT_EQUAL_HINT_FULL_INFO(a, b, hint) cppUTests::AssertEqualImpl((a), (b), #a, #b, true, __FILE__, __FUNCTION__, __LINE__, (hint))

#define ASSERT(expr) cppUTests::AssertImpl(!!(expr), #expr, false, __FILE__, __FUNCTION__, __LINE__, ""s)

#define ASSERT_FULL_INFO(expr) cppUTests::AssertImpl(!!(expr), #expr, true, __FILE__, __FUNCTION__, __LINE__, ""s)

#define ASSERT_HINT(expr, hint) cppUTests::AssertImpl(!!(expr), #expr, false, __FILE__, __FUNCTION__, __LINE__, (hint))

#define ASSERT_HINT_FULL_INFO(expr, hint) cppUTests::AssertImpl(!!(expr), #expr, true, __FILE__, __FUNCTION__, __LINE__, (hint))

#define RUN_TEST(func) cppUTests::RunTestImpl(func,(#func))  

#endif