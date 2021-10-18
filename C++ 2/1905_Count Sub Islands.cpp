class Solution {
public:
  int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int count = 0;
    for (int i = 0; i < grid2.size(); i++) {
      for (int j = 0; j < grid2[0].size(); j++) {
        if (grid1[i][j] == 1 && grid2[i][j] == 1 && isSubIsland(i, j, grid1, grid2)) {
          count++;
        }
      }
    }

    return count;
  }

  bool isSubIsland(int x, int y, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    static const int dirs[4][2] = {
      {1, 0},
      {-1, 0},
      {0, 1},
      {0, -1},
    };

    grid1[x][y] = 0;
    grid2[x][y] = 0;
    
    bool isSub = true;
    for (int d = 0; d < 4; d++) {
      int i = x + dirs[d][0];
      int j = y + dirs[d][1];
      if (i >= 0 && i < grid1.size() && j >= 0 && j < grid1[0].size() && grid2[i][j] == 1) {
        if (grid1[i][j] == 1 && grid2[i][j] == 1) {
          if (!isSubIsland(i, j, grid1, grid2)) {
            isSub = false;
          }
        } else {
          isSub = false;
        }     
      }
    }

    return isSub;
  }
};