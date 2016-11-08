#include <vector>
#include <unordered_map>

class Solution
{

public:

	bool containsDuplicate(std::vector<int>& nums)
	{
		// Count elements
		bool hasDuplicate = false;
		std::unordered_map<int, int> numberCounts;
		for(int i = 0; i < nums.size(); i++)
		{
			numberCounts[nums[i]]++;

			// Check duplicate
			if(numberCounts[nums[i]] > 1)
			{
				hasDuplicate = true;
				break;
			}
		}

		return hasDuplicate;
	}
};

// Array version
class Solution
{

public:

	bool containsDuplicate(std::vector<int>& nums)
	{
		// Count elements
		bool hasDuplicate = false;
		int numberCounts[1000000] = { 0 };
		for(int i = 0; i < nums.size(); i++)
		{
			numberCounts[nums[i]]++;

			// Check duplicate
			if(numberCounts[nums[i]] > 1)
			{
				hasDuplicate = true;
				break;
			}
		}

		return hasDuplicate;
	}
};