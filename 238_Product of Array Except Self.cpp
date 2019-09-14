class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int> products = vector<int>(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < products.size(); j++)
            {
                if (i != j)
                {
                    products[j] *= nums[i];
                }
            }
        }
        
        return products;
    }
};
