class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> counts(n + 1);
        counts[0] = 0;
        for (int i = 1; i <= n; i++) {
            counts[i] = counts[i & (i - 1)] + 1; // Set lowest valid bit to 0, +1
        }
        
        return counts;
    }
};

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> counts(n + 1);
        counts[0] = 0;
        for (int i = 1; i <= n; i++) {
            if (i & 1 == 1) {
                // Odd
                counts[i] = counts[i - 1] + 1;
            } else {
                // Even
                counts[i] = counts[i >> 1];
            }
        }
        
        return counts;
    }
};

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> counts(n + 1);
        for (int i = 0; i <= n; i++) {
            int num = i;
            int count = 0;
            while (num != 0) {
                num &= num - 1;
                count++;
            }
            
            counts[i] = count;
        }
        
        return counts;
    }
};