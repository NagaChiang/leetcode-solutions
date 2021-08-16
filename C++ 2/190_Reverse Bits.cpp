class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        static const int bitCount = sizeof(n) * 8;
        
        uint32_t reversed = 0;
        for (int i = 0; i < bitCount; i++) {
            if (n & (1 << i)) {
                reversed |= (1 << (bitCount - 1 - i));
            }
        }
        
        return reversed;
    }
};