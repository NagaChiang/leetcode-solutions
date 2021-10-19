class Solution {
  public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    // 0: unvisited
    // 1: visiting
    // 2: visited
    vector<int> statuses(numCourses);

    vector<vector<int>> preArrays(numCourses);
    for (const auto& pre : prerequisites) {
      preArrays[pre[0]].push_back(pre[1]);
    }

    vector<int> orders;
    for (int i = 0; i < numCourses; i++) {
      if (!findOrder(i, preArrays, statuses, orders)) {
        return {};
      }
    }

    return orders;
  }

  bool findOrder(int course, vector<vector<int>>& preArrays, vector<int>& statuses, vector<int>& orders) {
    if (statuses[course] == 1) {
      return false;
    }

    if (statuses[course] == 2) {
      return true;
    }

    statuses[course] = 1;
    for (int pre : preArrays[course]) {
      if (!findOrder(pre, preArrays, statuses, orders)) {
        return false;
      }
    }

    orders.push_back(course);
    statuses[course] = 2;

    return true;
  }
};