// Dynamic programming
// 6 ms
class Solution
{

public:

	int climbStairs(int n)
	{
		// Small numbers
		if(n <= 2)
			return n > 0 ? n : 0;

		// DP
		int climbWays[n + 1] = { 0 };
		climbWays[1] = 1;
		climbWays[2] = 2;
		for(int i = 3; i < n + 1; i++)
		{
			climbWays[i] = climbWays[i - 1] + climbWays[i - 2];
		}

		return climbWays[n];
	}
};