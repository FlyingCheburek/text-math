#include "text_math/integer.hpp"
#include "text_math/decimal.hpp"

using namespace TextMath;

int main() {
    Integer a("782348723487.0982321");
    Decimal x("9.56");
    Number b(a), c(x);
    std::cout << b.get() << " " << c.get() << std::endl;
    return 0;
}