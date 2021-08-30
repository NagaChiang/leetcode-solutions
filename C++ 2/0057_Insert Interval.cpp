class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> newIntervals; 
        bool inserted = false;
        for (const auto& interval : intervals) {
            if (interval[1] < newInterval[0]) {
                // Before new interval
                newIntervals.push_back(interval);
            } else if (newInterval[1] < interval[0]) {
                // After new interval
                if (!inserted) {
                    newIntervals.push_back(newInterval);
                    inserted = true;
                }
                
                newIntervals.push_back(interval);
            } else {
                // Overlapped with new interval
                newInterval[0] = min(interval[0], newInterval[0]);
                newInterval[1] = max(interval[1], newInterval[1]);
            }
        }
        
        if (!inserted) {
            newIntervals.push_back(newInterval);
        }
        
        return newIntervals;
    }
};