#include <vector>
#include <algorithm>
#include <limits>

// Fast
class Solution
{

public:

	int thirdMax(std::vector<int>& nums)
	{
		int count = 0;
		int max[3] = { INT_MIN };
		for(int i = 0; i < nums.size(); i++)
		{
			int num = nums[i];

			// Skip duplicates
			if((count >= 1 && num == max[0])
				|| (count >= 2 && num == max[1])
				|| (count >= 3 && num == max[2]))
				continue;

			// Sort it into array
			if(count == 0)
			{
				max[0] = num;
				count++;
			}
			else if(count < 1 || (count >= 1 && num > max[0]))
			{
				max[2] = max[1];
				max[1] = max[0];
				max[0] = num;
				count++;
			}
			else if(count < 2 || (count >= 2 && num > max[1]))
			{
				max[2] = max[1];
				max[1] = num;
				count++;
			}
			else if(count < 3 || (count >= 3 && num > max[2]))
			{
				max[2] = num;
				count++;
			}
		}

		// Return first if third not exists
		if(count >= 3)
			return max[2];
		else
			return max[0];
	}
};

// Slow but general
class Solution
{

public:

	int thirdMax(std::vector<int>& nums)
	{
		std::vector<int> maxs;
		for(int i = 0; i < nums.size(); i++)
		{
			// Push new element and sort
			maxs.push_back(nums[i]);
			std::sort(maxs.begin(), maxs.end(), std::greater<int>());

			// Remove duplicate
			for(int j = 0; j < maxs.size() - 1; j++)
			{
				if(maxs[j] == maxs[j + 1])
					maxs.erase(maxs.begin() + j);
			}

			// Too much elements
			if(maxs.size() > 3)
				maxs.pop_back();
		}

		return maxs.size() == 3 ? maxs[2] : maxs[0];
	}
};