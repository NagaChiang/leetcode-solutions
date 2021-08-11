class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.size() == 0) {
            return true;
        }
        
        unordered_set<string> wordSet;
        for (const string& word : wordDict) {
            wordSet.insert(word);
        }
        
        int maxLength = 0;
        for (const string& word : wordDict) {
            maxLength = max(maxLength, (int) word.size());
        }
        
        vector<bool> isValidBefore(s.size() + 1);
        isValidBefore[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = i; j >= 0; j--) {
                if (i - j > maxLength) {
                    break;
                }
                
                if (isValidBefore[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                    isValidBefore[i] = true;
                    break;
                }
            }
        }
        
        return isValidBefore[s.size()];
    }
};