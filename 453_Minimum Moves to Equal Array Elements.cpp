#include <limits>
#include <vector>

// Note: Add n-1 elements by 1 = Substract 1 element by 1

// 73 ms
class Solution
{

public:

	int minMoves(std::vector<int>& nums)
	{
		// Find min
		int min = std::numeric_limits<int>::max();
		for(int i = 0; i < nums.size(); i++)
		{
			if(nums[i] < min)
				min = nums[i];
		}

		// Sum of the difference between min and other elements
		int sum = 0;
		for(int i = 0; i < nums.size(); i++)
			sum += nums[i] - min;

		return sum;
	}
};