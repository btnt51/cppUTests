#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <ostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using std::string_literals::operator""s;

namespace cppUTests{



template<typename Element, typename Element2>
std::ostream& operator<<(std::ostream &out, const std::map<Element, Element2> container) {
    out << "<"s;
    bool first = true;
    for(const auto &[key, value]:container) {
        if(!first)
            out << ", "s;
        out << "("s;
        out << key;
        out << ", "s;
        out << value;
        out << ")"s;
        first = false;
    }
    out << ">"s;
    return out;
}

template<typename Container>
std::ostream& Print(std::ostream &out, const Container & container) {
    for(auto &el : container)  { 
        if(el != *(container.begin()))
            out << ", "s << el;
        else
            out << el;
    }
    return out;
}

template<typename Element>
std::ostream& operator<<(std::ostream &out, const std::vector<Element> container) {
    out << "["s;
    Print(out, container);
    out << "]"s;
    return out;
}


template<typename Element>
std::ostream& operator<<(std::ostream &out, const std::set<Element> container) {
    out << "{"s;
    Print(out, container);
    out << "}"s;
    return out;
}
}


#endif