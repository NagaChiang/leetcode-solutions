class Solution {
public:
  bool canReach(vector<int>& arr, int start) {
    vector<bool> visited(arr.size());
    return canReach(start, arr, visited);
  }

  bool canReach(int n, vector<int>& arr, vector<bool>& visited) {
    if (visited[n]) {
      return false;
    }

    if (arr[n] == 0) {
      return true;
    }

    visited[n] = true;

    int left = n - arr[n];
    if (left >= 0 && canReach(left, arr, visited)) {
      return true;
    }

    int right = n + arr[n];
    if (right < arr.size() && canReach(right, arr, visited)) {
      return true;
    }

    return false;
  }
};