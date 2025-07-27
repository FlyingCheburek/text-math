#ifndef DECIMAL_HPP
#define DECIMAL_HPP
#include "number.hpp"

namespace TextMath {
    class Decimal final : public Number {
    private:
        size_t precision = 2;

    public:
        Decimal() noexcept;
        Decimal(std::string number);
        Decimal(const float number);
        Decimal(const double number);
        Decimal(Number& number);

        Decimal& operator=(const Number& other) noexcept;
        Decimal& operator=(const std::string& number);  

    private:
        inline static void to_decimal(std::string& integer);
    };
}

#endif