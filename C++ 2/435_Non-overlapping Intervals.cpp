class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });
        
        int eraseCount = 0;
        int left = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[left][1] > intervals[i][0]) {
                eraseCount++;
                
                if (intervals[left][1] > intervals[i][1]) {
                    left = i;
                }
            } else {
                left = i;
            }
        }
        
        return eraseCount;
    }
};

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        
        int eraseCount = 0;
        int end = -INT_MAX;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][0] < end) {
                eraseCount++;
            } else {
                end = intervals[i][1];
            }
        }
        
        return eraseCount;
    }
};