class Solution {
public:
  string frequencySort(string s) {
    unordered_map<char, int> charFreqMap;
    for (char c : s) {
        charFreqMap[c]++;
    }

    priority_queue<pair<int, char>> heap;
    for (const auto& [c, count] : charFreqMap) {
        heap.push(make_pair(count, c));
    }

    string result;
    while (!heap.empty()) {
        auto [count, c] = heap.top();
        heap.pop();
        for (int i = 0; i < count; i++) {
        result.push_back(c);
        }
    }

    return result;
  }
};