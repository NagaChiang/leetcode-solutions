class Solution
{

public:

	int reverse(int x)
	{
		int result = 0;
		while(x != 0)
		{
			int nextResult = result * 10 + x % 10;
			x /= 10;

			// Test overflow
			if(nextResult / 10 != result)
			{
				result = 0;
				break;
			}

			result = nextResult;
		}

		return result;
	}
};