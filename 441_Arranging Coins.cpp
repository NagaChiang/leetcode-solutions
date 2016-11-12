#include <math.h>

class Solution
{

public:

	int arrangeCoins(int n)
	{
		int numRow = 0;
		for(int i = 1; n >= 0; i++)
		{
			// Row
			n -= i;

			// Check remaining
			if(n >= 0)
				numRow++;
		}

		return numRow;
	}
};

// Math
class Solution
{

public:

	int arrangeCoins(int n)
	{
		return (int)(sqrt(8 * (long)n + 1) - 1) / 2;
	}
};