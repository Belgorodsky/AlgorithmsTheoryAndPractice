#include <cassert>
#include <cstdint>
#include <iostream>

template <class Int>
Int gcd(Int a, Int b)
{
	static_assert(std::is_integral<Int>::value, "a and b must be integral");
    
	if (!a)
		return b;
	else if (!b)
		return a;
    
    return gcd(b, a % b);
}

int main(void)
{
	std::int32_t a, b;
	std::cin >> a >> b;
	std::cout << gcd(a, b) << std::endl;
	return 0;
}