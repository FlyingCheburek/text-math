#ifndef DECIMAL_HPP
#define DECIMAL_HPP
#include "number.hpp"
#include "integer.hpp"

namespace TextMath {
    class Decimal final : public Number {
    private:
        Integer precision = 2;

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