#include <vector>

// Dynamic programming
class NumArray
{

	std::vector<int> _sums;

public:

	NumArray(std::vector<int> &nums)
	{
		// Calculate the sums
		for(int i = 0; i < nums.size(); i++)
		{
			if(i == 0)
				_sums.push_back(nums[0]);
			else
				_sums.push_back(_sums[i - 1] + nums[i]);
		}
	}

	int sumRange(int i, int j)
	{
		return _sums[j] - (i > 0 ? _sums[i - 1] : 0);
	}
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);