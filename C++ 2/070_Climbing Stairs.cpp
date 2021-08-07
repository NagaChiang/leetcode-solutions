class Solution {
public:
    int climbStairs(int n) {
        vector<int> map(n + 1);
        map[1] = 1;
        map[2] = 2;
        
        for (int i = 3; i <= n; i++) {
            map[i] = map[i - 1] + map[i - 2];
        }
        
        return map[n];
    }
};