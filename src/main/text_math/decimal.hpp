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
        
        void set_precision(const size_t precision);
        size_t get_precision() const noexcept;

    private:
        inline static void to_decimal(std::string& integer);
        void decimal_trim_zeroes();
    };
}

#endif