class Solution {
private:
    enum class Phase {
        top,
        right,
        bottom,
        left,
    };
    
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int height = matrix.size();
        int width = matrix[0].size();
        int numSize = height * width;
        
        vector<int> nums;
        int row = 0;
        int col = 0;
        int round = 0;
        Phase phase = Phase::top;
        while (nums.size() < numSize) {
            nums.push_back(matrix[row][col]);
            switch (phase) {
                case Phase::top:
                    if (col == width - 1 - round) {
                        phase = Phase::right;
                        row++;
                    } else {
                        col++;
                    }
                    break;
                
                case Phase::right:
                    if (row == height - 1 - round) {
                        phase = Phase::bottom;
                        col--;
                    } else {
                        row++;
                    }
                    break;
                    
                case Phase::bottom:
                    if (col == round) {
                        phase = Phase::left;
                        row--;
                    } else {
                        col--;
                    }
                    break;
                    
                case Phase::left:
                    if (row == round + 1) {
                        phase = Phase::top;
                        col++;
                        
                        round++;
                    } else {
                        row--;
                    }
                    break;
            }
        }
        
        return nums;
    }
};