class Solution {   
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size()));
                if (dfs(board, word, 0, i, j, visited)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
private:
    bool dfs(const vector<vector<char>>& board, const string& word, int wordIndex, int row, int col, vector<vector<bool>>& visited) {
        static const vector<vector<int>> offsets = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1},
        };
        
        if (board[row][col] != word[wordIndex]) {
            return false;
        }
        
        if (wordIndex == word.size() - 1) {
            return true;
        }
        
        visited[row][col] = true;
        for (const auto& offset : offsets) {
            int newRow = row + offset[0];
            int newCol = col + offset[1];
            if (newRow < 0 || newRow >= board.size() || newCol < 0 || newCol >= board[0].size()) {
                continue;
            }
            
            if (visited[newRow][newCol]) {
                continue;
            }
            
            if (dfs(board, word, wordIndex + 1, newRow, newCol, visited)) {
                return true;
            }
        }
        
        visited[row][col] = false;
        
        return false;
    }
};