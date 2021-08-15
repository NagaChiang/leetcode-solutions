class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> chars;
        for (char c : s) {
            if (!isalnum(c)) {
                continue;
            }
            
            chars.push_back(tolower(c));
        }
        
        int left = (chars.size() - 1) / 2;
        int right = chars.size() / 2;
        while (left >= 0 && right < chars.size()) {
            if (chars[left] != chars[right]) {
                return false;
            }
            
            left--;
            right++;
        }
        
        return true;
    }
};