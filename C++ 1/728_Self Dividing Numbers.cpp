class Solution
{
    
public:
    
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> nums;
        for (int i = left; i <= right; i++)
        {
            if (IsSelfDividingNumber(i))
                nums.push_back(i);
        }
        
        return nums;
    }
    
    bool IsSelfDividingNumber(int num)
    {
        bool isSelfDividing = true;
        int n = num;
        while (n > 0)
        {
            int digit = n % 10;
            if ((digit == 0) || (num % digit != 0))
            {
                isSelfDividing = false;
                break;
            }
            
            n /= 10;
        }
        
        return isSelfDividing;
    }
};
