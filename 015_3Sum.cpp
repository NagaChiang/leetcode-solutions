// General n-sum solution
class Solution
{
    const int SUM_SIZE = 3;
    
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {   
        vector<vector<int>> seenArrays = vector<vector<int>>();
        vector<vector<int>> ansArrays = vector<vector<int>>();
        for (int num : nums)
        {
            vector<vector<int>> nextArrays = seenArrays;
            for (vector<int> array : seenArrays)
            {
                if (array.size() < SUM_SIZE)
                {
                    vector<int> newArray = array;
                    newArray.push_back(num);
                    nextArrays.push_back(newArray);
                    
                    // Check sum
                    if (newArray.size() == SUM_SIZE)
                    {
                        int sum = 0;
                        for (int n : newArray)
                        {
                            sum += n;
                        }

                        if (sum == 0)
                        {
                            ansArrays.push_back(newArray);
                        }
                    }
                }
            }
            
            nextArrays.push_back(vector<int>{num});
            seenArrays = nextArrays;
        }
        
        // Remove duplicates
        for (int i = 0; i < ansArrays.size(); i++)
        {
            unordered_map<int, int> CountsA = unordered_map<int, int>();
            for (int n : ansArrays[i])
            {
                CountsA[n]++;
            }
            
            for (int j = ansArrays.size() - 1; j > i; j--)
            {
                unordered_map<int, int> CountsB = unordered_map<int, int>();
                for (int n : ansArrays[j])
                {
                    CountsB[n]++;
                }
                
                bool isDuplicated = true;
                for (const pair<int, int>& p : CountsA)
                {
                    int key = p.first;
                    int count = p.second;
                    const auto& itr = CountsB.find(key);
                    if (!(itr != CountsB.end() && count == itr->second))
                    {
                        isDuplicated = false;
                        break;
                    }
                }
                
                if (isDuplicated)
                {
                    ansArrays.erase(ansArrays.begin() + j);
                }
            }
        }
            
        return ansArrays;
    }
};
