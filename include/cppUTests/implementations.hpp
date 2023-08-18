#ifndef IMPLEMENTATIONS_HPP
#define IMPLEMENTATIONS_HPP

#include <iostream>
#include <string>

#include "utility.hpp"

namespace cppUTests {

template <typename T, typename U>
void AssertEqualImpl(const T& t, const U& u, const std::string& t_str, const std::string& u_str, const std::string& file,
                     const std::string& func, unsigned line, const std::string& hint) {
    if (t != u) {
        std::cerr << std::boolalpha;
        std::cerr << file << "("s << line << "): "s << func << ": "s;
        std::cerr << "ASSERT_EQUAL("s << t_str << ", "s << u_str << ") failed: "s;
        std::cerr << t << " != "s << u << "."s;
        if (!hint.empty()) {
            std::cerr << " Hint: "s << hint;
        }
        std::cerr << std::endl;
        abort();
    }
}


void AssertImpl(bool value, const std::string& expr_str, 
                const std::string& file, const std::string& func, 
                unsigned line, const std::string& hint);


template <typename FUNC>
void RunTestImpl(FUNC function, const std::string & funcion_str) {
    /* Напишите недостающий код */
    function();
    std::cerr << funcion_str << " OK" << std::endl;
}

}

#endif