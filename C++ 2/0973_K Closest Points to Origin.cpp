class Solution {
  public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    const auto compare = [](const vector<int>& a, const vector<int>& b) {
      return (a[0] * a[0]) + (a[1] * a[1]) > (b[0] * b[0]) + (b[1] * b[1]);
    };

    priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> heap(compare);
    for (const vector<int> point : points) {
      heap.push(point);
    }

    vector<vector<int>> tops;
    for (int i = 0; i < k; i++) {
      tops.push_back(heap.top());
      heap.pop();
    }

    return tops;
  }
};