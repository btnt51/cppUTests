#include <cppUTests/cppUTests.hpp>


int sum(int a, int b) {
    return a+b;
}

void TestSum() {
    ASSERT_EQUAL(sum(2,2), 4);
}

void FailureTest() {
    ASSERT_EQUAL(sum(2,2), 5);
}

void TestCode() {
    TEST(TestSum);
    TEST(FailureTest);
    RUNTESTS();
}


int main() {
    TestCode();
    return 0;
}