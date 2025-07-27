#ifndef INTEGER_HPP
#define INTEGER_HPP
#include "number.hpp"

namespace TextMath {
    class Integer : public Number {
    public:
        Integer() noexcept;
        Integer(const char* number);
        Integer(const long long number) noexcept;
    };
}

#endif