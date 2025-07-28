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
        bool operator==(const Number& other) const noexcept;

    private:
        inline static void to_integer(std::string& decimal);
        inline static std::string to_integer_copy(std::string decimal);
    };
}

#endif 