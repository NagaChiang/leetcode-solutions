class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> results;
        unordered_map<string, int> patternToGroupIndexMap;
        for (const string& word : strs) {
            string pattern = word;
            sort(pattern.begin(), pattern.end());          
            if (patternToGroupIndexMap.find(pattern) == patternToGroupIndexMap.end()) {
                patternToGroupIndexMap[pattern] = results.size();
                results.push_back({});
            }
            
            int groupIndex = patternToGroupIndexMap[pattern];
            results[groupIndex].push_back(word);
        }
        
        return results;
    }
};