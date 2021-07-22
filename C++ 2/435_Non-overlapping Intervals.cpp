class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        
        int count = 0;
        int end = -INT_MAX;
        for (int i = 0; i < intervals.size(); i++) {
            if (end <= intervals[i][0]) {
                // Not overlapped
                count++;
                end = intervals[i][1];
            }
        }
        
        return intervals.size() - count;
    }
};

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        
        int overlapCount = 0;
        int end = -INT_MAX;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][0] < end) {
                // Overlapped
                overlapCount++;
            } else {
                end = intervals[i][1];
            }
        }
        
        return overlapCount;
    }
};