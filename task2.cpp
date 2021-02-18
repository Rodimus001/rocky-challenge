#include <iostream>
#include <math.h>

int GCD(int x, int y)
{
	x = abs(x);
	y = abs(y);
	
	if (!x) return y;
	if (!y) return x;

	int max = x, min = y;

	if (y > x)
	{
		max = y;
		min = x;
	}

	while (max % min)
	{
		int tmp = max % min;
		max = min;
		min = tmp;
	}

	if (!(max % min)) return min;

	if (!(max % min))
	{
		return min;
	}

	return 1;
}

int RecGCD(int x, int y)
{
	if (!x) return y;
	if (!y) return x;
	if (x == y) return x;
	if (x > y) return RecGCD(x - y, y);
	return RecGCD(x, y - x);
}

int main()
{
	int x = 264;
	int y = 120;

	std::cout << "Iterative GCD function result: " << GCD(x, y);
	std::cout << "Recursive GCD function result: " << RecGCD(x, y);
}