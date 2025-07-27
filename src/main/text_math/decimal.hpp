#ifndef DECIMAL_HPP
#define DECIMAL_HPP
#include "number.hpp"

namespace TextMath {
    class Decimal final : public Number {
    public:
        Decimal() noexcept;
        Decimal(const char* number);
        Decimal(const float number);
        Decimal(const double number);
    };
}

#endif