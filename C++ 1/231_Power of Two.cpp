class Solution
{

public:

	bool isPowerOfTwo(int n)
	{
		// Zero or negtive
		if(n <= 0)
			return false;

		// Divide by 2
		while(n % 2 == 0)
		{
			n /= 2;
		}

		// Check if the remain is 1
		return n == 1;
	}
};