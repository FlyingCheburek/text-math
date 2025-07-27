#include "text_math/integer.hpp"
#include "text_math/decimal.hpp"

using namespace TextMath;

int main() {
    Integer a("-999");
    Decimal b(&a);

    Decimal c("123.05");
    Integer d(&c);

    std::cout << d.get() << "\n";
    return 0;
}