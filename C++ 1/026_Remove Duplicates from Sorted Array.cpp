#include <vector>

class Solution
{

public:

	int removeDuplicates(std::vector<int>& nums)
	{
		if(nums.size() == 0)
			return 0;

		int scanned = 0;
		for(int i = 0; i < nums.size(); i++)
		{
			// Get the value of fast pointer
			if(nums[i] != nums[scanned])
			{
				scanned++;
				nums[scanned] = nums[i];
			}
		}

		return scanned + 1;
	}
};