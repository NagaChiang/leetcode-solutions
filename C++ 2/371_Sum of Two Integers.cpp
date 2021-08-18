class Solution {
public:
    int getSum(int a, int b) {
        unsigned int aNum = static_cast<unsigned int>(a);
        unsigned int bNum = static_cast<unsigned int>(b);
        while (bNum != 0) {
            unsigned int sum = aNum ^ bNum;
            unsigned int carry = (aNum & bNum) << 1;
            aNum = sum;
            bNum = carry;
        }
        
        return aNum;
    }
};

class Solution {
public:
    int getSum(int a, int b) {
        static const int bitCount = sizeof(int) * 8;
        
        bool c = false;
        int result = 0;
        for (int i = 0; i < bitCount; i++) {
            bool aBit = a & (1 << i);
            bool bBit = b & (1 << i);
            bool resultBit = (aBit && !bBit && !c) || (!aBit && bBit && !c) || (!aBit && !bBit && c) || (aBit && bBit && c);
            c = (!aBit && bBit && c) || (aBit && !bBit && c) || (aBit && bBit && !c) || (aBit && bBit && c);
            
            if (resultBit) {
                result |= 1 << i;
            }
        }
        
        return result;
    }
};