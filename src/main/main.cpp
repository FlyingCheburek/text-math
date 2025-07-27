#include "text_math/integer.hpp"
using namespace TextMath;

int main() {
    Integer a(-999);
    Number b(a);
    std::cout << b.get() << std::endl;
    return 0;
}