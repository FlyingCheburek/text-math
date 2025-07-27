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

std::string Number::get() const noexcept
{
    return content;
}

Number::Type Number::get_type() const noexcept{
    return type;
}

void TextMath::trim_zeroes(std::string &integer) noexcept {
    bool negative = integer.front() == '-';
    if (negative)
        integer.erase(0,1);
    size_t trim_idx = integer.find_first_not_of('0');
    if (trim_idx == std::string::npos)
        integer = "0";
    else if (trim_idx != integer.length() - 1)
        integer = integer.substr(trim_idx);
        if (negative) integer = "-" + integer;
}
