class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            n &= n - 1; // Set lowest 1 to 0
            count++;
        }
        
        return count;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        static const int bitCount = sizeof(n) * 8;
        
        int count = 0;
        for (int i = 0; i < bitCount; i++) {
            if (n & (1 << i)) {
                count++;
            }
        }
        
        return count;
    }
};