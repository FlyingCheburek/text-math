#ifndef INTEGER_HPP
#define INTEGER_HPP
#include "number.hpp"

namespace TextMath {
    class Integer final : public Number {
    public:
        Integer() noexcept;
        Integer(std::string number);
        Integer(const long long number) noexcept;
    };
}

#endif