class Solution
{

public:

	int singleNumber(vector<int>& nums)
	{
		// The sum of XOR every element = the single one
		int sumXor = 0;
		for(int i = 0; i < nums.size(); i++)
		{
			sumXor ^= nums[i];
		}

		return sumXor;
	}

};