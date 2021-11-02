class Solution {
public:
  int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    vector<vector<int>> children(n);
    for (int i = 0; i < n; i++) {
      if (i == headID) {
        continue;
      }

      children[manager[i]].push_back(i);
    }

    return getMaxTime(headID, children, informTime);
  }

  int getMaxTime(int id, vector<vector<int>>& children, vector<int>& informTime) {
    int maxTime = 0;
    for (int child : children[id]) {
      maxTime = max(maxTime, getMaxTime(child, children, informTime));
    }

    return maxTime + informTime[id];
  }
};