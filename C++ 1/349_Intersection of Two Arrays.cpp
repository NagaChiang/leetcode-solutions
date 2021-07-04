#include <vector>

// Note: It's tricky to use a big array instead of a map.

class Solution
{

public:

	std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2)
	{
		// Record element in the shorter vector
		std::vector<int> shortNums, longNums;
		if(nums1.size() >= nums2.size())
		{
			// nums2 is shorter
			shortNums = nums2;
			longNums = nums1;
		}
		else
		{
			// nums1 is shorter
			shortNums = nums1;
			longNums = nums2;
		}

		// Record each element contained in nums1
		const int SIZE = 1000;
		bool isContained[SIZE] = { false };
		for(int i = 0; i < shortNums.size(); i++)
		{
			isContained[shortNums[i]] = true;
		}

		// Compared to nums2
		bool isBothContained[SIZE] = { false };
		for(int i = 0; i < longNums.size(); i++)
		{
			int num = longNums[i];
			if(isContained[num])
			{
				isBothContained[num] = true;
			}
		}

		// Convert map to vector
		std::vector<int> intersection;
		for(int i = 0; i < SIZE; i++)
		{
			if(isBothContained[i])
				intersection.push_back(i);
		}

		return intersection;
	}
};