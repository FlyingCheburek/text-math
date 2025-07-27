#include "number.hpp"
#include <regex>

using namespace TextMath;

Number::Type Number::get_type(const std::string text) noexcept {
    if (std::regex_match(text, std::regex("^-?\\d+$")))
        return INTEGER;

    else if (std::regex_match(text, std::regex("^-?\\d*\\.\\d+$"))) 
        return DECIMAL;
    
    return INVALID;
}
