class Solution {
public:
  vector<vector<int>> findFarmland(vector<vector<int>>& land) {
    vector<vector<int>> groups;
    for (int i = 0; i < land.size(); i++) {
      for (int j = 0; j < land[0].size(); j++) {
        if (land[i][j] != 1) {
          continue;
        }

        int r = i;
        int c = j;
        while (r + 1 < land.size() && land[r + 1][c] == 1) {
          r++;
        }

        while (c + 1 < land[0].size() && land[r][c + 1] == 1) {
          c++;
        }

        groups.push_back({i, j, r, c});

        for (int a = i; a <= r; a++) {
          for (int b = j; b <= c; b++) {
            land[a][b] = 0;
          }
        }
      }
    }

    return groups;
  }
};