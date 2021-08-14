// Expand around center
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 0) {
            return "";
        }
        
        int maxLeft = 0;
        int maxRight = 0;
        for (int i = 0; i < s.size(); i++) {
            int length1 = getPalindromeLength(s, i, i);
            int length2 = getPalindromeLength(s, i, i + 1);
            int maxLength = max(length1, length2);
            if (maxLength > maxRight - maxLeft + 1) {
                maxLeft = i - ((maxLength - 1) / 2);
                maxRight = i + (maxLength / 2);
            }
        }
        
        return s.substr(maxLeft, maxRight - maxLeft + 1);
    }
    
private:
    int getPalindromeLength(string& str, int left, int right) {
        int l = left;
        int r = right;
        while (0 <= l && r < str.size() && str[l] == str[r]) {
            l--;
            r++;
        }
        
        return max((r - l + 1) - 2, 0);
    }
};

// DP
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 0) {
            return "";
        }
        
        vector<vector<bool>> isValids(s.size(), vector<bool>(s.size()));
        for (int i = 0; i < s.size(); i++) {
            isValids[i][i] = true;
            if (i + 1 < s.size()) {
                isValids[i][i + 1] = s[i] == s[i + 1];
            }
        }
        
        int maxStart = 0;
        int maxEnd = 0;
        for (int end = 0; end < s.size(); end++) {
            for (int start = 0; start < end; start++) {
                if (s[start] == s[end] && (end - start == 1 || isValids[start + 1][end - 1])) {
                    isValids[start][end] = true;
                    if (end - start > maxEnd - maxStart) {
                        maxStart = start;
                        maxEnd = end;
                    }
                }
            }
        }
        
        return s.substr(maxStart, maxEnd - maxStart + 1);
    }
};