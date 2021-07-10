class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        
        vector<vector<int>> results;
        results.push_back(intervals[0]);
        for (auto& interval : intervals) {
            vector<int>& lastInterval = results.back();
            if (lastInterval[1] >= interval[0]) {
                lastInterval = {lastInterval[0], max(lastInterval[1], interval[1])};
            } else {
                results.push_back(interval);
            }
        }
        
        return results;
    }
};