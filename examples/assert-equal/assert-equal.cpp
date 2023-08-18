#include "cppUTests/cppUTests.hpp"

#include <string>

using std::string_literals::operator""s;

int main() {
    std::string hello = "hello"s;
    ASSERT_EQUAL(hello.size(), 6u);

    return 0;
}