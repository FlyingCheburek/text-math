#ifndef NUMBER_HPP
#define NUMBER_HPP
#include <iostream>
#include <stdexcept>

namespace TextMath {
    class Number {
    public:
        enum Type {
            INTEGER,
            DECIMAL,
            INVALID
        }; 

    protected:
        std::string content;
        Type type = INVALID;

    public:
        std::string get() const noexcept;
        Type get_type() const noexcept; 
        static Type find_type(const std::string text) noexcept;
    };
    void trim_zeroes(std::string& integer) noexcept;
}

#endif