class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> newIntervals;
        vector<int>& insertInterval = newInterval;
        bool inserted = false;
        for (const auto& interval : intervals) {
            if (interval[1] < insertInterval[0]) {
                newIntervals.push_back(interval);
            } else if (insertInterval[1] < interval[0]) {
                if (!inserted) {
                    newIntervals.push_back(insertInterval);
                    inserted = true;
                }
                
                newIntervals.push_back(interval);
            } else {
                insertInterval[0] = min(interval[0], insertInterval[0]);
                insertInterval[1] = max(interval[1], insertInterval[1]);
            }
        }
        
        if (!inserted) {
            newIntervals.push_back(insertInterval);
        }
        
        return newIntervals;
    }
};