class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        vector<int> copiedNums = nums;
        sort(copiedNums.begin(), copiedNums.end());
        for(int i = 1; i < copiedNums.size(); i++)
        {
            if(copiedNums[i] == copiedNums[i - 1]) {
                return true;
            }
        }
        
        return false;
    }
};