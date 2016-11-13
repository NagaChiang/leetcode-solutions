#include <vector>

class Solution
{

public:

	int rob(std::vector<int>& nums)
	{
		// Greedy
		int prevMax = 0; // i - 1
		int currMax = 0; // i
		for(int i = 0; i < nums.size(); i++)
		{
			int prev = prevMax; // i - 2
			int curr = currMax; // i - 1
			prevMax = curr >= prev ? curr : prev;
			currMax = prev + nums[i];			
		}

		return currMax >= prevMax ? currMax : prevMax;
	}
};