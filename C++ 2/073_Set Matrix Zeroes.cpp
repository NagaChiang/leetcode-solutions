// Space O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowCount = matrix.size();
        int colCount = matrix[0].size();
        
        // Mark first element as flag
        bool isFirstColZero = false;
        for (int i = 0; i < rowCount; i++) {
            if (matrix[i][0] == 0) {
                isFirstColZero = true;
            }
            
            for (int j = 1; j < colCount; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // Zero out elements depending on flags except for first row and column
        for (int i = 1; i < rowCount; i++) {
            for (int j = 1; j < colCount; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // First row
        if (matrix[0][0] == 0) {
            for (int i = 0; i < colCount; i++) {
                matrix[0][i] = 0;
            }
        }
        
        // First column
        if (isFirstColZero) {
            for (int i = 0; i < rowCount; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};