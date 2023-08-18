#ifndef CPPUTESTS_HPP
#define CPPUTESTS_HPP

#include "implementations.hpp"

#define ASSERT_EQUAL(a, b) cppUTests::AssertEqualImpl((a), (b), #a, #b, __FILE__, __FUNCTION__, __LINE__, ""s)

#define ASSERT_EQUAL_HINT(a, b, hint) cppUTests::AssertEqualImpl((a), (b), #a, #b, __FILE__, __FUNCTION__, __LINE__, (hint))

#define ASSERT(expr) cppUTests::AssertImpl(!!(expr), #expr, __FILE__, __FUNCTION__, __LINE__, ""s)

#define ASSERT_HINT(expr, hint) cppUTests::AssertImpl(!!(expr), #expr, __FILE__, __FUNCTION__, __LINE__, (hint))

#define RUN_TEST(func) cppUTests::RunTestImpl(func,(#func))  

#endif