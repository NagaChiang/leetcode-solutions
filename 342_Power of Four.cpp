class Solution
{

public:

	bool isPowerOfFour(int n)
	{
		// Zero or negtive
		if(n <= 0)
			return false;

		// Divide by 4
		while(n % 4 == 0)
		{
			n /= 4;
		}

		// Check if the remain is 1
		return n == 1;
	}
};