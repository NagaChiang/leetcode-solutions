class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        static int mod = 1000000007;
        
        vector<int> targets(22);
        targets[0] = 1;
        for (int i = 1; i <= 21; i++) {
            targets[i] = targets[i - 1] * 2;
        }
        
        long count = 0;
        int max = 0;
        unordered_map<int, int> numCounts;
        for (int n : deliciousness) {
            for (int target : targets) {
                if (max + n < target) {
                    break;
                }
                
                if (numCounts.find(target - n) != numCounts.end()) {
                    count += numCounts[target - n];
                }
            }
            
            max = std::max(max, n);
            numCounts[n]++;
        }
        
        return count % mod;
    }
};