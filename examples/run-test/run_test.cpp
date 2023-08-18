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
    RUN_TEST(TestSum);
    RUN_TEST(FailureTest);
}


int main() {
    TestCode();
    return 0;
}