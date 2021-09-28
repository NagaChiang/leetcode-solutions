class Solution {
public:
  struct WordCount {
    string word;
    int count;

    WordCount(const string& w, int c) {
      word = w;
      count = c;
    }
  };

  vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> wordCountMap;
    for (const string& w : words) {
      wordCountMap[w]++;
    }

    const auto compare = [](const WordCount& a, const WordCount& b) {
      return a.count < b.count || (a.count == b.count && a.word > b.word);
    };

    priority_queue<WordCount, vector<WordCount>, decltype(compare)> heap(compare);
    for (const auto& [word, count] : wordCountMap) {
      heap.push(WordCount(word, count));
    }
    
    vector<string> tops;
    for (int i = 0; i < k; i++) {
      tops.push_back(heap.top().word);
      heap.pop();
    }

    return tops;
  }
};