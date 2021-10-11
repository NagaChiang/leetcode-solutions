class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    static const int charSize = 26;

    if (s1.size() > s2.size()) {
      return false;
    }

    int charNeeds[charSize] = {0};
    for (char c : s1) {
      charNeeds[c - 'a']++;
    }

    for (int i = 0; i < s1.size() - 1; i++) {
      charNeeds[s2[i] - 'a']--;
    }

    int unmatch = 0;
    for (int i = 0; i < charSize; i++) {
      if (charNeeds[i] != 0) {
        unmatch++;
      }
    }

    for (int start = 0, end = s1.size() - 1; end < s2.size(); start++, end++) {
      int endIndex = s2[end] - 'a';
      charNeeds[endIndex]--;

      if (charNeeds[endIndex] == 0) {
        unmatch--;
      } else if (charNeeds[endIndex] == -1) {
        unmatch++;
      }
      
      if (unmatch == 0) {
        return true;
      }
      
      int startIndex = s2[start] - 'a';
      charNeeds[startIndex]++;

      if (charNeeds[startIndex] == 0) {
        unmatch--;
      } else if (charNeeds[startIndex] == 1) {
        unmatch++;
      }
    }

    return false;
  }
};