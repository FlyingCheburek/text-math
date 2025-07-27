#include "integer.hpp"

using namespace TextMath;

Integer::Integer() noexcept : Number() { content = "0"; }

Integer::Integer(std::string number) : Number() {
    switch(get_type(number)) {
        case INTEGER:
            content = number;
            break;
        case DECIMAL:
            number.erase(number.find('.'));
            content = number;
            break;
        default:
            throw std::invalid_argument("Invalid number format for Integer initialization.");
    }
}

Integer::Integer(const long long number) noexcept : Number() {
    content = std::to_string(number);
}