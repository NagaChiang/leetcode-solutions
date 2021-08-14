class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> allCombs;
        vector<int> comb;
        dfs(candidates, target, 0, allCombs, comb);
        
        return allCombs;
    }
    
private:
    void dfs(vector<int>& candidates, int target, int index, vector<vector<int>>& allCombs, vector<int>& comb) {
        if (target == 0) {
            allCombs.push_back(comb);
            return;
        }
        
        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] > target) {
                continue;
            }
            
            comb.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, allCombs, comb);
            comb.pop_back();
        }
    }
};