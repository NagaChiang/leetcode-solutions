class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        static const int alphabetCount = 26;

        if (s.size() < p.size()) {
            return {};
        }

        int pattern[alphabetCount] = {};
        for (char c : p) {
            pattern[c - 'a']++;
        }

        int charCounts[alphabetCount] = {};
        for (int i = 0; i < p.size(); i++) {
            charCounts[s[i] - 'a']++;
        }

        vector<int> indexes;
        for (int i = 0; i < s.size(); i++) {
            bool isSame = true;
            for (int j = 0; j < alphabetCount; j++) {
                if (pattern[j] != charCounts[j]) {
                    isSame = false;
                    break;
                }
            }

            if (isSame) {
                indexes.push_back(i);
            }

            charCounts[s[i] - 'a']--;

            int nextEnd = i + p.size();
            if (nextEnd < s.size()) {
                charCounts[s[nextEnd] - 'a']++;
            } else {
                break;
            }
        }

        return indexes;
    }
};