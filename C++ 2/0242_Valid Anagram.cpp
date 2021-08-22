class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() == 0 || t.length() == 0 || s.length() != t.length()) {
            return false;
        }
        
        int counts[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }
        
        for (int count : counts) {
            if (count != 0) {
                return false;
            }
        }
        
        return true;
    }
};