class Solution {
public:
  void solve(vector<vector<char>>& board) {
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (i != 0 && j != 0 && i != board.size() - 1 && j != board[0].size() - 1) {
          continue;
        }

        if (board[i][j] != 'O') {
          continue;
        }

        dfs(i, j, board);
      }
    }

    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (board[i][j] == 'V') {
          board[i][j] = 'O';
        } else if (board[i][j] == 'O') {
          board[i][j] = 'X';
        }
      }
    }
  }

  void dfs(int x, int y, vector<vector<char>>& board) {
    static const int dirCount = 4;
    static const pair<int, int> dirs[dirCount] = {
      {1, 0},
      {-1, 0},
      {0, 1},
      {0, -1},
    };

    board[x][y] = 'V';
    for (int d = 0; d < dirCount; d++) {
      int i = x + dirs[d].first;
      int j = y + dirs[d].second;
      if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size() && board[i][j] == 'O') {
        dfs(i, j, board);
      }
    }
  }
};