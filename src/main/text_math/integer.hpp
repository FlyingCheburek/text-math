#ifndef INTEGER_HPP
#define INTEGER_HPP
#include "number.hpp"

namespace TextMath {
    class Integer final : public Number {
    public:
        Integer() noexcept;
        Integer(std::string number);
        Integer(const long long number) noexcept;
        Integer(Number& number);

        Integer& operator=(const Number& other) noexcept;
        Integer& operator=(const std::string& number);

    private:
        inline static void to_integer(std::string& decimal);
    };
}

#endif 