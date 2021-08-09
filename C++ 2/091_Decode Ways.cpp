class Solution {
public:
    int numDecodings(string s) {
        vector<int> nums(s.size());
        for (int i = 0; i < s.size(); i++) {
            nums[i] = s[i] - '0';
        }
        
        int lastLast = 0;
        int last = 0;
        for (int i = 0; i < nums.size(); i++) {
            int current = 0;
            if (isValidCode(nums[i])) {
                if (i == 0) {
                    current++;
                } else {
                    current += last;
                }
            }
            
            if (i > 0 && isValidCode(nums[i - 1], nums[i])) {
                if (i <= 1) {
                    current++;
                } else {
                    current += lastLast;
                }
            }
            
            lastLast = last;
            last = current;
        }
        
        return last;
    }
    
private:
    bool isValidCode(int one) {
        return 1 <= one && one <= 9;
    }
    
    bool isValidCode(int ten, int one) {
        if (ten == 1) {
            return 0 <= one && one <= 9;
        }
        
        if (ten == 2) {
            return 0 <= one && one <= 6;
        }
        
        return false;
    }
};