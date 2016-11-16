// Note: The number of 2s are much more than 5s.

class Solution
{

public:

	int trailingZeroes(int n)
	{
		// Count 5 factors
		int numFive = 0;
		while(n >= 5)
		{
			numFive += n / 5;
			n /= 5;
		}

		return numFive;
	}
};