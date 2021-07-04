class Solution
{
    
public:
    
    int hammingDistance(int x, int y)
    {
        int distance = 0;
        int diff = x ^ y;
        while (diff > 0)
        {
            if (diff & 1)
                distance++;
            diff >>= 1;
        }
        
        return distance;
    }
};
