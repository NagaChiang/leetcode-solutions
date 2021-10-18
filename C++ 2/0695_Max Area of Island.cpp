class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int maxArea = 0;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 1 && !visited[i][j]) {
          int area = 0;
          dfs(i, j, grid, visited, area);

          maxArea = max(maxArea, area);
        }
      }
    }

    return maxArea;
  }

  void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited, int& area) {
    static const int dirs[4][2] = {
      {1, 0},
      {-1, 0},
      {0, 1},
      {0, -1},
    };

    area++;
    visited[x][y] = true;
    for (int d = 0; d < 4; d++) {
      int i = x + dirs[d][0];
      int j = y + dirs[d][1];
      if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1 && !visited[i][j]) {
        dfs(i, j, grid, visited, area);
      }
    }
  }
};