#include "text_math/integer.hpp"
#include "text_math/decimal.hpp"

using namespace TextMath;

int main() {
    Decimal a("-0000.00090"), b;
    b = "-99.9110000000";
    std::cout << b.get() << std::endl;
    return 0;
}