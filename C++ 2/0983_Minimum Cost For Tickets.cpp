class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> costMap(days.back() + 1);
        for (int i = 0; i < days.size(); i++) {
            int d = days[i];
            costMap[d] = min({
                costMap[d >= 1 ? d - 1 : 0] + costs[0],
                costMap[d >= 7 ? d - 7 : 0] + costs[1],
                costMap[d >= 30 ? d - 30 : 0] + costs[2]
            });
            
            if (i < days.size() - 1) {
                fill(costMap.begin() + days[i], costMap.begin() + days[i + 1], costMap[d]);
            }
        }
        
        return costMap[days.back()];
    }
};