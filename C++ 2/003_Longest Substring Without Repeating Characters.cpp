class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> charToLastIndex(256, -1);
        int maxLength = 0;
        int start = 0;
        for (int end = start; end < s.size(); end++) {
            if (charToLastIndex[s[end]] >= start) {            
                start = charToLastIndex[s[end]] + 1;
            }
            
            charToLastIndex[s[end]] = end;
            maxLength = max(maxLength, end - start + 1);
        }
        
        return maxLength;
    }
};