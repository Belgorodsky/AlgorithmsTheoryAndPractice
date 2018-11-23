#include <cassert>
#include <cstdint>
#include <iostream>
#include <algorithm>

template <class Int>
Int gcd(Int a, Int b)
{
	static_assert(std::is_integral<Int>::value, "a and b must be integral");

    while (a && b)
    {
        a = a % b;
        std::swap(a, b);
    }
    
    return a ? a : b;
}

int main(void)
{
	std::int32_t a, b;
	std::cin >> a >> b;
	std::cout << gcd(a, b) << std::endl;
	return 0;
}