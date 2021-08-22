class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> charCounts(256, 0);
        for (int i = 0; i < t.size(); i++) {
            charCounts[t[i]]++;
        }

        int remainCount = t.size();
        int minStart = 0;
        int minEnd = -1;
        int start = 0;
        int end = start;
        while (end < s.size()) {
            if (charCounts[s[end]] > 0) {
                remainCount--;
            }
            
            charCounts[s[end]]--;
            
            while (remainCount == 0) {
                if (minEnd < 0 || end - start < minEnd - minStart) {
                    minStart = start;
                    minEnd = end;
                }
                
                if (charCounts[s[start]] == 0) {
                    remainCount++;
                }
                
                charCounts[s[start]]++;
                start++;
            }
            
             end++;
        }
                       
        return minEnd >= 0 ? s.substr(minStart, minEnd - minStart + 1) : "";
    }
};