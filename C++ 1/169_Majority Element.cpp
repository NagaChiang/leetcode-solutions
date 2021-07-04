#include <vector>
#include <unordered_map>
#include <algorithm>

// Map
// 46 ms
class Solution
{

public:

	int majorityElement(std::vector<int>& nums)
	{
		// Counting
		std::unordered_map<int, int> mapCounts;
		for(int i = 0; i < nums.size(); i++)
		{
			mapCounts[nums[i]]++;
		}

		// Check if more than n/2
		int major = -1;
		for(int i = 0; i < nums.size(); i++)
		{
			if(mapCounts[nums[i]] > nums.size() / 2)
			{
				major = nums[i];
				break;
			}
		}

		return major;
	}
};

// Boyer–Moore majority vote algorithm
// 22 ms
class Solution
{

public:

	int majorityElement(std::vector<int>& nums)
	{
		// Counting
		int candidate = 0;
		int count = 0;
		for(int i = 0; i < nums.size(); i++)
		{
			if(count == 0)
			{
				// New candidate
				candidate = nums[i];
				count = 1;
			}
			else
			{
				// Check candidate
				if(nums[i] == candidate)
				{
					count++;

					// More than n/2
					if(count > nums.size() / 2)
						break;
				}
				else
					count--;
			}
		}

		return candidate;
	}
};

// Sorting
// 53 ms
class Solution
{

public:

	int majorityElement(std::vector<int>& nums)
	{
		// Sort
		std::sort(nums.begin(), nums.end());

		return nums[nums.size() / 2];
	}
};

// Divide and conquer
// Wrong: Can't handle equality situation
struct Element
{
	int value;
	int count;
};

class Solution
{

public:

	int majorityElement(std::vector<int>& nums)
	{
		return getMajorElement(nums, 0, nums.size()).value;
	}

private:

	Element getMajorElement(std::vector<int>& nums, int indexStart, int length)
	{
		// Only one element remaining
		if(length == 1)
		{
			Element major;
			major.value = nums[indexStart];
			major.count = 1;
			return major;
		}

		// Divide and conquer
		Element left = getMajorElement(nums, indexStart, length / 2);
		Element right = getMajorElement(nums, indexStart + length / 2, length - (length / 2));
		return left.count >= right.count ? left : right;
	}
};