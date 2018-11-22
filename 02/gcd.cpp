#include <cassert>
#include <cstdint>
#include <iostream>

template <class Int>
Int gcd(Int a, Int b)
{
	static_assert(std::is_integral<Int>::value, "a and b must be integral");

	Int current_gcd = 1;
	if (!a)
		current_gcd = b;
	else if (!b)
		current_gcd = a;
	else if (a <= b)
		current_gcd = gcd(a, b % a);
	else
		current_gcd = gcd(a % b, b);

	return current_gcd;
}

int main(void)
{
	std::int32_t a, b;
	std::cin >> a >> b;
	std::cout << gcd(a, b) << std::endl;
	return 0;
}
