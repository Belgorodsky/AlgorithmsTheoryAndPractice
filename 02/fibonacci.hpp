#pragma once
#include <cassert>
#include <iostream>
#include <array>
#include <cstdint>


template<std::size_t maxIndex>
class Fibonacci final
{
public:
	static int get(int n)
	{
		static_assert(maxIndex <= 80, "fibonacci value of maxIndex more then UINT64_MAX");
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
					table[i] = table[i-2] + table[i-1];
				}
			}
			return table[n];
		}

		return n;
	}
private:
	static std::array<std::size_t, 1 + maxIndex> table;
};


template<std::size_t maxIndex>
std::array<std::size_t, 1 + maxIndex> Fibonacci<maxIndex> ::table = {};

template<>
class Fibonacci<0> final
{
public:
	static int get(int n)
	{
		assert(!n);
		return 0;
	}
};

template<>
class Fibonacci<1> final
{
public:
	static int get(int n)
	{
		assert(n <= 1);
		assert(n >= 0);
		return n;
	}
};

int main()
{
	int n;
	std::cin >> n;
	std::cout << Fibonacci<40>::get(n) << std::endl;
	return 0;
}

