// Greedy
class Solution {
public:
  bool isPossible(vector<int>& nums) {
    unordered_map<int, int> countMap;
    for (int n : nums) {
      countMap[n]++;
    }

    unordered_map<int, int> tailCountMap;
    for (int n : nums) {
      if (countMap[n] == 0) {
        continue;
      }

      if (tailCountMap[n - 1] > 0) {
        countMap[n]--;
        tailCountMap[n - 1]--;
        tailCountMap[n]++;
      } else if (countMap[n + 1] > 0 && countMap[n + 2] > 0) {
        countMap[n]--;
        countMap[n + 1]--;
        countMap[n + 2]--;
        tailCountMap[n + 2]++;
      } else {
        return false;
      }
    }

    return true;
  }
};

// Map + heap, O(nlogn)
class Solution {
public:
  bool isPossible(vector<int>& nums) {
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> endNumToLengthHeapMap;
    for (int n : nums) {
      const auto& itr = endNumToLengthHeapMap.find(n - 1);
      if (itr == endNumToLengthHeapMap.end() || itr->second.size() == 0) {
        endNumToLengthHeapMap[n].push(1);
        continue;
      }

      auto& lengthHeap = endNumToLengthHeapMap[n - 1];
      int newLength = lengthHeap.top() + 1;
      lengthHeap.pop();
      endNumToLengthHeapMap[n].push(newLength);
    }
    
    for (const auto& [endNum, lengthHeap] : endNumToLengthHeapMap) {
      if (lengthHeap.size() > 0 && lengthHeap.top() < 3) {
        return false;
      }
    }

    return true;
  }
};