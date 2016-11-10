#include <unordered_map>

// 6 ms
class Solution
{

public:

	bool isHappy(int n)
	{
		// Record every number; If duplicates happen -> infinite loop
		std::unordered_map<int, bool> isCalculated;
		bool isHappyNum = true;
		while(n != 1)
		{
			// Sum of all digits
			int temp = n;
			int sum = 0;
			while(temp > 0)
			{
				int digit = temp % 10;
				sum += digit * digit;
				temp /= 10;
			}

			// Check the number has appeared or not
			if(isCalculated[sum])
			{
				// Duplicate
				isHappyNum = false;
				break;
			}
			else
			{
				// New
				isCalculated[sum] = true;
				n = sum;
			}
		}

		return isHappyNum;
	}
};