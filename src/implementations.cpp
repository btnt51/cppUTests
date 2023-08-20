#include "cppUTests/utility.hpp"
#include <cppUTests/implementations.hpp>
#include <cstdlib>

namespace cppUTests {
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
