#include <vector>

// Note:
// Test cases are like this
// [1,3,5,null,null,null,null]
// 3
// [2, 3, 4, 6]
// 4

class Solution
{

public:

	void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
	{
		// From the end of the nums1
		int index_1 = m - 1;
		int index_2 = n - 1;
		for(int i = m + n - 1; i >= 0; i--)
		{
			if(index_1 < 0)
			{
				// Out of nums1
				nums1[i] = nums2[index_2];
				index_2--;
			}
			else if(index_2 < 0)
			{
				// Out of nums2
				nums1[i] = nums1[index_1];
				index_1--;
			}
			else if(nums1[index_1] >= nums2[index_2])
			{
				// nums1 bigger
				nums1[i] = nums1[index_1];
				index_1--;
			}
			else
			{
				// nums2 bigger
				nums1[i] = nums2[index_2];
				index_2--;
			}
		}
	}
};

// Wrong (But I like it)
class Solution
{

public:

	void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
	{
		// Loop through nums2
		for(int i = 0, j = 0; j < nums2.size(); j++)
		{
			// Find place in nums1
			for(; i < nums1.size() && nums1[i] < nums2[j]; i++) {}

			// Insert
			nums1.insert(nums1.begin() + i, nums2[j]);
			i++;
		}
	}
};