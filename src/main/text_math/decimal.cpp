#include "decimal.hpp"

using namespace TextMath;

Decimal::Decimal() noexcept : Number() { content = "0.0"; type = DECIMAL; }

Decimal::Decimal(std::string number) {
    type = DECIMAL;
    switch(find_type(number)) {
        case DECIMAL:
            content = number;
            break;
        case INTEGER:
            content = number;
            to_decimal(content);
            break;
        default:
            throw std::invalid_argument("Invalid number format for Decimal initialization.");
    }
}

Decimal::Decimal(const float number) {
    type = DECIMAL;
    content = std::to_string(number);
}

Decimal::Decimal(const double number) { 
    type = DECIMAL;
    content = std::to_string(number);
}

Decimal::Decimal(Number& number) {
    type = DECIMAL;
    switch(number.get_type()) {
        case DECIMAL:
            content = number.get();
            break;
        case INTEGER:
            content = number.get();
            to_decimal(content);
            break;
        default:
            throw std::invalid_argument("Invalid TextMath::Number pointer provided for Decimal initialization.");
    }
}

Decimal& Decimal::operator=(const Number &other) noexcept { 
    this->content = other.get();
    if (other.get_type() == INTEGER) 
        to_decimal(this->content);   
    return *this;
}

Decimal& Decimal::operator=(const std::string &number){
    switch(find_type(number)) {
        case DECIMAL:
            content = number;
            break;
        case INTEGER:
            content = number;
            to_decimal(content);
            break;
        default:
            throw std::invalid_argument("Invalid format assigned to object of type TextMath::Decimal");
    }
    return *this;
}

inline void Decimal::to_decimal(std::string &integer){
    integer += ".0";
}
