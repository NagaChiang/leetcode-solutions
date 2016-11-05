#include <vector>



// 1. All elements before the slow pointer (lastZeroIndex) are non-zeroes.
// 2. All elements between the current and slow pointer are zeroes.
class Solution {

public:

	void moveZeroes(std::vector<int>& nums)
	{
		int lastZeroIndex = 0;
		for(int i = 0; i < nums.size(); i++)
		{
			if(nums[i] != 0)
			{
				std::swap(nums[lastZeroIndex], nums[i]);
				lastZeroIndex++;
			}
		}
	}

};