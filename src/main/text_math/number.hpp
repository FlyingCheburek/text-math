#ifndef NUMBER_HPP
#define NUMBER_HPP
#include <iostream>

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

    public:
        static Type get_type(const std::string text) noexcept;
    };
}

#endif