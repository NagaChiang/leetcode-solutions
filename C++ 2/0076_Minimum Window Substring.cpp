class Solution {
public:
  string minWindow(string s, string t) {
    static const int charSize = 256;
    int charNeedCounts[charSize] = {0};
    for (char c : t) {
      charNeedCounts[c]++;
    }

    int remainCount = t.size();
    int minStart = 0;
    int minEnd = INT_MAX;
    int start = 0;
    for (int end = 0; end < s.size(); end++) {
      if (charNeedCounts[s[end]] > 0) {
        remainCount--;
      }

      charNeedCounts[s[end]]--;

      while (remainCount == 0) {
        if (end - start < minEnd - minStart) {
          minStart = start;
          minEnd = end;
        }

        if (charNeedCounts[s[start]] == 0) {
          remainCount++;
        }

        charNeedCounts[s[start]]++;
        start++;
      }
    }

    if (minEnd == INT_MAX) {
      return "";
    }

    return s.substr(minStart, minEnd - minStart + 1);
  }
};