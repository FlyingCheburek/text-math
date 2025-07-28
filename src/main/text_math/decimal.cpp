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
    decimal_trim_zeroes();
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
    decimal_trim_zeroes();
    return *this;
}

inline void Decimal::to_decimal(std::string &integer){
    integer += ".0";
}

void TextMath::Decimal::decimal_trim_zeroes(){
    auto parts = split_decimal(content);
    bool negative = parts.first.front() == '-';
    if (negative) parts.first.erase(0,1);
    trim_left_zeroes(parts.first);
    trim_right_zeroes(parts.second);
    content = ((negative && (parts.first != "0" || parts.second != "0")) ? "-" : "") + parts.first + "." + parts.second;
}

void TextMath::Decimal::set_precision(const size_t precision){
    if (precision < 1)
        throw std::invalid_argument("TextMath::Decimal::precision cannot be less than 0.");
    this->precision = precision;
}

size_t Decimal::get_precision() const noexcept {
    return precision;
}
