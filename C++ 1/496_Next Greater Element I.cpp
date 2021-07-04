class Solution
{
    
public:
    
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums)
    {
        vector<int> indexes;
        for (int i = 0; i < findNums.size(); i++)
        {
            int num = findNums[i];
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[j] == num)
                {
                    int index = -1;
                    for (int k = j + 1; k < nums.size(); k++)
                    {
                        if (nums[k] > num)
                        {
                            index = nums[k];
                            break;
                        }
                    }
                    
                    indexes.push_back(index);
                    break;
                }
            }
        }
        
        return indexes;
    }
};
