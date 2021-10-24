class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> pathCounts(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (obstacleGrid[i][j] == 1) {
          pathCounts[i][j] = 0;
          continue;
        }
        
        if (i == 0 && j == 0) {
          pathCounts[i][j] = 1;
          continue;
        }

        if (i > 0) {
          pathCounts[i][j] += pathCounts[i - 1][j];
        }

        if (j > 0) {
          pathCounts[i][j] += pathCounts[i][j - 1];
        }
      }
    }

    return pathCounts[m - 1][n - 1];
  }
};