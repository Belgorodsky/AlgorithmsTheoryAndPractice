#pragma once
#include <cassert>
#include <iostream>
#include <array>
#include <cstdint>


template<std::size_t maxIndex>
class FibonacciLastDigit final
{
public:
	static int get(int n)
	{
		assert(n <= maxIndex);
		assert(n >= 0);

		if (1 < n)
		{
			static int previous_index = 1;

			if (previous_index < n)
			{
				table[0] = 0;
				table[1] = 1;
				for(int i = 2; i <= n; ++i)
				{
					table[i] = (table[i-2] + table[i-1]) % 10;
				}
			}
			return table[n];
		}

		return n;
	}
private:
	static std::array<uint64_t, 1 + maxIndex> table;
};


template<std::size_t maxIndex>
std::array<uint64_t, 1 + maxIndex> FibonacciLastDigit<maxIndex> ::table = {};

template<>
class FibonacciLastDigit<0> final
{
public:
	static int get(int n)
	{
		assert(!n);
		return 0;
	}
};

template<>
class FibonacciLastDigit<1> final
{
public:
	static int get(int n)
	{
		assert(n <= 1);
		assert(n >= 0);
		return n;
	}
};

int main(void) {
	int n;
	std::cin >> n;
	std::cout << FibonacciLastDigit<10000000>::get(n) << std::endl;
	return 0;
}

