class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> numSet;
        int num = n;
        while (numSet.find(num) == numSet.end()) {
            numSet.insert(num);
            
            int sum = 0;
            while (num > 0) {
                int i = num % 10;
                sum += i * i;
                
                num /= 10;
            }
            
            if (sum == 1) {
                return true;
            }
            
            num = sum;
        }
        
        return false;
    }
};

