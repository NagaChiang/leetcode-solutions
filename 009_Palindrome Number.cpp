class Solution
{

public:

	bool isPalindrome(int x)
	{
		if(x < 0)
			return false;

		// Find the divide for high digits
		int highDiv = 1;
		while(x / highDiv >= 10)
		{
			highDiv *= 10;
		}

		// Check
		int lowDiv = 1;
		while(highDiv >= lowDiv)
		{
			int highDigit = x / highDiv % 10;
			int lowDigit = x / lowDiv % 10;
			if(highDigit != lowDigit)
				return false;

			// Next divides
			highDiv /= 10;
			lowDiv *= 10;
		}

		return true;
	}
};