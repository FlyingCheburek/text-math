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
    trim_left_zeroes(content);
}

Integer::Integer(const long long number) noexcept : Number() {
    type = INTEGER;
    content = std::to_string(number);
}

Integer::Integer(Number &number) {
   type = INTEGER;
   switch(number.get_type()) {
        case INTEGER:
            content = number.get();
            break;
        case DECIMAL:
            content = number.get();
            to_integer(content);
            break;
        default:
            throw std::invalid_argument("Invalid TextMath::Number pointer provided for Integer initialization.");
    }
}

Integer& Integer::operator=(const Number &other) noexcept{
    this->content = other.get();
    if (other.get_type() == DECIMAL) 
        to_integer(this->content);   
    return *this;
}

Integer& Integer::operator=(const std::string &number){
    switch(find_type(number)) {
        case INTEGER:
            content = number;
            break;
        case DECIMAL:
            content = number;
            to_integer(content);
            break;
        default:
            throw std::invalid_argument("Invalid format assigned to object of type TextMath::Integer");
    }
    trim_left_zeroes(content);
    return *this;
}

inline void Integer::to_integer(std::string &decimal){
    decimal.erase(decimal.find('.'));
}
