#include <vector>


class Solution
{

public:

	int removeElement(std::vector<int>& nums, int val)
	{
		int j = 0;
		for(int i = 0; i < nums.size(); i++)
		{
			// Put elements to the front except for val
			if(nums[i] != val)
			{
				nums[j] = nums[i];
				j++;
			}
		}

		return j;
	}
};

// Ignore order
class Solution
{

public:

	int removeElement(std::vector<int>& nums, int val)
	{
		int length = nums.size();
		int i = 0;
		while(i < length)
		{
			if(nums[i] == val)
			{
				// Take any element from the end
				nums[i] = nums[length - 1];
				length--;
			}
			else
			{
				// Not val
				i++;
			}
		}

		return length;
	}
};

// Cheat!
class Solution
{

public:

	int removeElement(std::vector<int>& nums, int val)
	{
		for(int i = 0; i < nums.size(); i++)
		{
			if(nums[i] == val)
			{
				nums.erase(nums.begin() + i);
				i--;
			}
		}

		return nums.size();
	}
};