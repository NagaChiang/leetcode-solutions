class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max = 0;
        int left = 0;
        int right = heights.size() - 1;
        while (left < right) {
            int leftValue = heights[left];
            int rightValue = heights[right];
            int area = min(leftValue, rightValue) * (right - left);
            if (area > max) {
                max = area;
            }
            
            if (leftValue < rightValue) {
                while (left < right && heights[left] <= leftValue) {
                    left++;
                }
            } else {
                while (left < right && heights[right] <= rightValue) {
                    right--;
                }
            }
        }
        
        return max;
    }
};