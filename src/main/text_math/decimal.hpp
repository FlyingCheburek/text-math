#ifndef DECIMAL_HPP
#define DECIMAL_HPP
#include "number.hpp"

namespace TextMath {
    class Decimal final : public Number {
    public:
        Decimal() noexcept;
        Decimal(std::string number);
        Decimal(const float number);
        Decimal(const double number);
        Decimal(Number* number);

    private:
        inline static void to_decimal(std::string& integer);
    };
}

#endif