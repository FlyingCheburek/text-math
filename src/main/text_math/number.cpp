#include "number.hpp"
#include <regex>

using namespace TextMath;

Number::Type Number::find_type(const std::string text) noexcept {
    if (std::regex_match(text, std::regex("^-?\\d+$")))
        return INTEGER;

    else if (std::regex_match(text, std::regex("^-?\\d*\\.\\d+$"))) 
        return DECIMAL;
    
    return INVALID;
}

std::string Number::get() const noexcept {
    return content;
}

Number::Type Number::get_type() const noexcept{
    return type;
}
