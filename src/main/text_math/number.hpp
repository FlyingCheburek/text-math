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

        static void trim_left_zeroes(std::string& integer) noexcept;
        static void trim_right_zeroes(std::string& integer) noexcept;
        static std::pair<std::string, std::string> split_decimal(const std::string& decimal) noexcept;

    public:
        std::string get() const noexcept;
        Type get_type() const noexcept; 
        static Type find_type(const std::string text) noexcept;
    };
}

#endif