class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> products(nums.size(), 1);

    int left = 1;
    int right = 1;
    for (int i = 0; i < nums.size(); i++) {
      products[i] *= left;
      left *= nums[i];

      int revIndex = nums.size() - 1 - i;
      products[revIndex] *= right;
      right *= nums[revIndex];
    }

    return products;
  }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answers;

        int product = 1;
        for (int i = 0; i < nums.size(); i++) {
            answers.emplace_back(product);
            product *= nums[i];
        }
        
        product = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            answers[i] *= product;
            product *= nums[i];
        }
        
        return answers;
    }
};