#include "text_math/integer.hpp"
#include "text_math/decimal.hpp"

using namespace TextMath;

int main() {
    Integer a("-010000"), b(a);
    
    std::cout << b.get();
    return 0;
}