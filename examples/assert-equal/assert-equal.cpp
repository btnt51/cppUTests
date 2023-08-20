#include "cppUTests/cppUTests.hpp"

#include <string>

using std::string_literals::operator""s;

int main() {
    std::string hello = "hello"s;
    ASSERT_EQUAL_FULL_INFO(hello.size(), 6u);

    return 0;
}