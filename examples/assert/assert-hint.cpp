#include <cppUTests/cppUTests.hpp>
#include <string>

using std::string_literals::operator""s;
int main() {
    ASSERT_HINT(2 + 2 == 5, "This will fail"s);
    return 0;
}