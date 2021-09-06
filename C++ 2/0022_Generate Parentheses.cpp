class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> allStrs;
        string str;
        dfs(n, 0, str, allStrs);

        return allStrs;
    }

private:
    void dfs(int n, int openCount, string& str, vector<string>& allStrs) {
        if (n == 0 && openCount == 0) {
            allStrs.push_back(str);
            return;
        }

        if (n > 0) {
            str.push_back('(');
            dfs(n - 1, openCount + 1, str, allStrs);
            str.pop_back();
        }

        if (openCount > 0) {
            str.push_back(')');
            dfs(n, openCount - 1, str, allStrs);
            str.pop_back();
        }
    }
};