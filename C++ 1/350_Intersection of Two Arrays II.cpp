#include <vector>
#include <unordered_map>
#include <algorithm>

// Map
// 22 ms
class Solution
{

public:

	std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2)
	{
		std::vector<int> intersection;

		// Counting elements of num1
		std::unordered_map<int, int> numCounts_1;
		for(int i = 0; i < nums1.size(); i++)
			numCounts_1[nums1[i]]++;

		// Compared to num2
		std::unordered_map<int, int> bothCounts;
		for(int i = 0; i < nums2.size(); i++)
		{
			int num = nums2[i];

			// Intersection
			if(bothCounts[num] < numCounts_1[num])
			{
				bothCounts[num]++;
				intersection.push_back(num);
			}
		}

		return intersection;
	}
};

// Sorting
// 9 ms
class Solution
{

public:

	std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2)
	{
		// Sort
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());

		// Find the intersection
		std::vector<int> intersection;
		std::vector<int>::iterator itr1 = nums1.begin();
		std::vector<int>::iterator itr2 = nums2.begin();
		while(itr1 != nums1.end() && itr2 != nums2.end())
		{
			if(*itr1 < *itr2)
				itr1++;
			else if(*itr1 > *itr2)
				itr2++;
			else
			{
				intersection.push_back(*itr1);
				itr1++;
				itr2++;
			}
		}

		return intersection;
	}
};