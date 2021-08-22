class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> charCounts(26, 0);
        int maxLength = 0;
        int maxCharCount = 0;
        int start = 0;
        for (int end = start; end < s.size(); end++) {
            charCounts[s[end] - 'A']++;
            
            maxCharCount = max(maxCharCount, charCounts[s[end] - 'A']);
            int otherCount = (end - start + 1) - maxCharCount;
            if (otherCount > k) {
                charCounts[s[start] - 'A']--;
                start++;
            } else {
                maxLength = max(maxLength, end - start + 1);
            }
        }
        
        return maxLength;
    }
};