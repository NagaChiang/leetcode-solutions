class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            const int middle = (left + right) / 2;
            if (target < nums[middle]) {
                if (nums[middle] > nums[right] && target < nums[left]) {
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
            } else if (target > nums[middle]) {
                if (nums[middle] < nums[left] && target > nums[right]) {
                    right = middle - 1;
                } else {
                    left = middle + 1;
                }
            } else {
                return middle;
            }
        }
        
        return -1;
    }
};