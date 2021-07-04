class Solution
{
    
public:
    
    int distributeCandies(vector<int>& candies)
    {
        std::sort(candies.begin(), candies.end());
        
        int count = 1;
        for (int i = 1; (i < candies.size()) && (count < candies.size() / 2); i++)
        {
            if (candies[i - 1] < candies[i])
                count++;
        }
        
        return count;
    }
};
