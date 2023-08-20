#include <cppUTests/utility.hpp>
#include <cppUTests/implementations.hpp>
#include <cstdlib>

namespace cppUTests {

std::vector<std::pair<std::function<void()>, std::string>> TestService::arrayOfFuncs = {};

void TestService::addTest(std::function<void ()> func, const std::string &func_str) {
    arrayOfFuncs.push_back(std::make_pair(func, func_str));
}

void TestService::RunTests() {
    std::cerr << "Tests: " << arrayOfFuncs.size() << std::endl;
    for(std::size_t i = 0; i < arrayOfFuncs.size(); ++i) {
        arrayOfFuncs.at(i).first();
        std::cerr << "Test#" << i << ":" << arrayOfFuncs.at(i).second << " OK" << std::endl; 
    }
    std::cerr << "All tests were finished" << std::endl;
}

void AssertImpl(bool value, const std::string& expr_str, const bool fullInfo, const std::string& file, const std::string& func, unsigned line,
                const std::string& hint) {
    if (!value) {
        std::cerr << (fullInfo ? file : NormalizeString(file)) << "("s << line << "): "s << func << ": "s;
        std::cerr << "ASSERT("s << expr_str << ") failed."s;
        if (!hint.empty()) {
            std::cerr << " Hint: "s << hint;
        }
        std::cerr << std::endl;
        abort();
    }
}

}
