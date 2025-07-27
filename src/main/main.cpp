#include "text_math/integer.hpp"
#include "text_math/decimal.hpp"

using namespace TextMath;

int main() {
    Integer a("-999");
    Decimal b("100.06");

    a = "111.91231";
    b = "891.1238123923";

    std::cout << b.get() << "\n";
    return 0;
}