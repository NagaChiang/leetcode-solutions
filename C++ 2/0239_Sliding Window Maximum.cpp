// Deque, O(n)
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> q;
    for (int i = 0; i < k - 1; i++) {
      while (!q.empty() && nums[i] >= nums[q.back()]) {
        q.pop_back();
      }

      q.push_back(i);
    }

    vector<int> maxs;
    for (int i = k - 1; i < nums.size(); i++) {
      while (!q.empty() && nums[i] >= nums[q.back()]) {
        q.pop_back();
      }

      q.push_back(i);

      while (q.front() <= i - k) {
        q.pop_front();
      }

      maxs.push_back(nums[q.front()]);
    }

    return maxs;
  }
};

// Heap, O(nlogn)
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    priority_queue<pair<int, int>> heap;
    for (int i = 0; i < k - 1; i++) {
      heap.push(make_pair(nums[i], i));
    }

    vector<int> maxs;
    for (int start = 0, end = k - 1; end < nums.size(); start++, end++) {
      heap.push(make_pair(nums[end], end));
      
      while (heap.top().second < start) {
        heap.pop();
      }

      maxs.push_back(heap.top().first);
    }

    return maxs;
  }
};