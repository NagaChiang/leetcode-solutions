class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        
        long long sum = 0;
        long long bestSum = LLONG_MIN;
        for (long long n : nums)
        {
            sum = max(n, sum + n);
            bestSum = max(bestSum, sum);
        }
        
        return bestSum;
    }
};
