class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int width = matrix.size();
        
        // Transpose
        for (int i = 0; i < width; i++) {
            for (int j = i; j < width; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Reverse left/right
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < width / 2; j++) {
                swap(matrix[i][j], matrix[i][width - 1 - j]);
            }
        }
    }
};