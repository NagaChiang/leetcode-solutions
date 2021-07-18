class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int offset = 0; offset <= 1; offset++) {
                int left = i;
                int right = i + offset;
                while (left >= 0 && right < s.size()) {
                    if (s[left] != s[right]) {
                        break;
                    }

                    count++;
                    left--;
                    right++;
                }
            }
        }
        
        return count;
    }
};