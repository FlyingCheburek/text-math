#include "text_math/integer.hpp"
#include "text_math/decimal.hpp"

using namespace TextMath;

int main() {
    Decimal a("-00010.0000001"), b;
    b = "99.9110000000";
    std::cout << b.get() << std::endl;
    return 0;
}