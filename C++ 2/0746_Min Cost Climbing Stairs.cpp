class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int lastLast = cost[0];
        int last = cost[1];
        for (int i = 2; i < cost.size(); i++) {
            int current = min(lastLast, last) + cost[i];
            lastLast = last;
            last = current;
        }
        
        return min(lastLast, last);
    }
};