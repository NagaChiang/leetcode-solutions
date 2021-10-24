class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0 && j == 0) {
          continue;
        }

        int minPath = INT_MAX;
        if (i > 0) {
          minPath = min(minPath, grid[i - 1][j]);
        }

        if (j > 0) {
          minPath = min(minPath, grid[i][j - 1]);
        }

        grid[i][j] += minPath;
      }
    }

    return grid[m - 1][n - 1];
  }
};