#include "integer.hpp"

using namespace TextMath;

Integer::Integer() noexcept : Number() { content = "0"; type = INTEGER; }

Integer::Integer(std::string number) : Number() {
    type = INTEGER;
    switch(find_type(number)) {
        case INTEGER:
            content = number;
            break;
        case DECIMAL:
            content = number;
            to_integer(content);
            break;
        default:
            throw std::invalid_argument("Invalid number format for Integer initialization.");
    }
}

Integer::Integer(const long long number) noexcept : Number() {
    type = INTEGER;
    content = std::to_string(number);
}

Integer::Integer(Number* number) {
   type = INTEGER;
   switch(number->get_type()) {
        case INTEGER:
            content = number->get();
            break;
        case DECIMAL:
            content = number->get();
            to_integer(content);
            break;
        default:
            throw std::invalid_argument("Invalid TextMath::Number pointer provided for Integer initialization.");
    }
}

inline void Integer::to_integer(std::string &decimal){
    decimal.erase(decimal.find('.'));
}
