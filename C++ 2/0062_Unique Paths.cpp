// Combination
// C (m + n - 2) / (m - 1)
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long count = 1;
        for (int i = n, j = 1; i <= m + n - 2, j <= m - 1; i++, j++) {
            count = count * i / j;
        }
        
        return count;
    }
};

// DP: Optimized
// rowPathCounts[j] = [i - 1][j]
// rowPathCounts[j - 1] = [i][j - 1]
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> rowPathCounts(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                rowPathCounts[j] += rowPathCounts[j - 1];
            }
        }
        
        return rowPathCounts[n - 1];
    }
};

// DP
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> pathCounts(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    pathCounts[i][j] = 1;
                } else {
                    if (i > 0) {
                        pathCounts[i][j] += pathCounts[i - 1][j];
                    }
                    
                    if (j > 0) {
                        pathCounts[i][j] += pathCounts[i][j - 1];
                    }
                }
            }
        }
        
        return pathCounts[m - 1][n - 1];
    }
};