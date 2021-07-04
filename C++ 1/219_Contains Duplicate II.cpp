#include <vector>
#include <unordered_map>

class Solution
{

public:

	bool containsNearbyDuplicate(std::vector<int>& nums, int k)
	{
		std::unordered_map<int, int> lastIndex;
		for(int i = 0; i < nums.size(); i++)
		{
			int element = nums[i];
			if(lastIndex.find(element) != lastIndex.end())
			{
				// Has appeared
				if(i - lastIndex[element] <= k)
					return true;
			}
			
			// Remember the index
			lastIndex[element] = i;
		}

		return false;
	}
};