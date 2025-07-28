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

void Number::trim_left_zeroes(std::string &integer) noexcept {
    bool negative = integer.front() == '-';
    if (negative)
        integer.erase(0,1);
    size_t trim_idx = integer.find_first_not_of('0');
    if (trim_idx == std::string::npos) {
        integer = "0";
        return;
    }
    else if (trim_idx != integer.length() - 1)
        integer = integer.substr(trim_idx);
        
    if (negative) integer = "-" + integer;
}

void Number::trim_right_zeroes(std::string &integer) noexcept {
    bool negative = integer.front() == '-';
    if (negative)
        integer.erase(0,1);
    size_t trim_idx = integer.find_last_not_of('0');
    if (trim_idx == std::string::npos) {
        integer = "0";
        return;
    }
    else
        integer = integer.substr(0,trim_idx+1);
    if (negative) integer = "-" + integer;
}

std::pair<std::string, std::string> Number::split_decimal(const std::string &decimal) noexcept {
    size_t point_idx = decimal.find('.');
    return std::make_pair<std::string, std::string>(decimal.substr(0, point_idx), decimal.substr(point_idx+1));
}
