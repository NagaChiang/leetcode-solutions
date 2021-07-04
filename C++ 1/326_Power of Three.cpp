// Keep dividing
// 48 ms
class Solution
{

public:

	bool isPowerOfThree(int n)
	{
		// Zero or negtive
		if(n <= 0)
			return false;

		// Divide by 3
		while(n % 3 == 0)
		{
			n /= 3;
		}

		// Check if the remain is 1
		return n == 1;
	}
};

// Integer limitations
// 65 ms
class Solution
{

public:

	bool isPowerOfThree(int n)
	{
		return n > 0 && 1162261467 % n == 0;
	}
};