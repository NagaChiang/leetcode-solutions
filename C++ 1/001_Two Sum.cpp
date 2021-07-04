#include <vector>
#include <unordered_map>

class Solution
{

public:

	std::vector<int> twoSum(std::vector<int>& nums, int target)
	{
		std::vector<int> indices;
		std::unordered_map<int, int> mapNumIndex;
		for(int i = 0; i < nums.size(); i++)
		{
			int num = nums[i];

			// Look up in map
			int complement = target - num;
			if(mapNumIndex.find(complement) != mapNumIndex.end())
			{
				// Found
				indices.push_back(mapNumIndex[complement]);
				indices.push_back(i);
				break;
			}
			else
			{
				// Not found
				mapNumIndex[num] = i;
			}
		}

		return indices;
	}
};