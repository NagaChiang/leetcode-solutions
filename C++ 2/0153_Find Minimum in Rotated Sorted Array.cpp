class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            if (left == right) {
                break;
            }

            int mid = (left + right) / 2;
            if (nums[left] > nums[mid]) {
                // New start on left side
                right = mid;
            } else if (nums[mid] > nums[right]) {
                // New start on right side
                left = mid + 1;
            } else {
                // Not rotated
                right = mid;
            }
        }

        return nums[left];
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            if (nums[left] < nums[right]) {
                break;
            }
            
            const int middle = (left + right) / 2;
            if (nums[left] <= nums[middle]) {
                left = middle + 1;
            } else {
                right = middle;
            }
        }
        
        return nums[left];
    }
};