#include <vector>

/*
Original List : 1 2 3 4 5 6 7
After reversing all numbers : 7 6 5 4 3 2 1
After reversing first k numbers : 5 6 7 4 3 2 1
After revering last n - k numbers : 5 6 7 1 2 3 4 --> Result
*/

class Solution
{

public:

	void rotate(std::vector<int>& nums, int k)
	{
		int modK = k % nums.size();

		// Reverse all
		std::reverse(nums.begin(), nums.end());

		// Reverse first k
		std::reverse(nums.begin(), nums.begin() + modK);

		// Reverse last n - k
		std::reverse(nums.begin() + modK, nums.end());
	}
};