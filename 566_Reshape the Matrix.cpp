class Solution
{
    
public:
    
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c)
    {
        if (!CanReshape(nums, r, c))
            return nums;
        
        vector<vector<int>> matrix = vector<vector<int>>();
        vector<int> newRow;
        int i = 0;
        for (vector<int> row : nums)
        {
            for (int num : row)
            {
                newRow.push_back(num);
                i++;
                
                if (i >= c)
                {
                    i = 0;
                    matrix.push_back(newRow);
                    newRow.clear();
                }
            }
        }
        
        return matrix;
    }
    
    bool CanReshape(vector<vector<int>>& nums, int r, int c)
    {
        return (nums.size() * nums[0].size()) == (r * c);
    }
};
