class Solution
{
    
public:
    
    bool hasAlternatingBits(int n)
    {
        bool isAlterBits = true;
        int lastBit = 2; // Not 0 or 1
        int num = n;
        while (num > 0)
        {
            int bit = num & 1;
            if (bit == lastBit)
            {
                isAlterBits = false;
                break;
            }
            
            lastBit = bit;
            num >>= 1;
        }
        
        return isAlterBits;
    }
};
