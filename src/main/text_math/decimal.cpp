#include "decimal.hpp"

using namespace TextMath;

Decimal::Decimal() noexcept : Number() { content = "0.0"; }

Decimal::Decimal(const char *number) {
    switch(get_type(number)) {
        case DECIMAL:
            content = number;
            break;
        case INTEGER:
            content = std::string(number) + ".0";
            break;
        default:
            throw std::invalid_argument("Invalid number format for Decimal initialization.");
    }
}

Decimal::Decimal(const float number) {
    content = std::to_string(number);
}

Decimal::Decimal(const double number) { 
    content = std::to_string(number);
}
