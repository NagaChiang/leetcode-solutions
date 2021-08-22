class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rowCount = heights.size();
        int colCount = heights[0].size();
        vector<vector<int>> map(rowCount, vector<int>(colCount, 0));
        vector<vector<int>> cells;
        for (int i = 0; i < rowCount; i++) {
            traverseFlow(i, 0, heights, map, 1, cells);
            traverseFlow(i, colCount - 1, heights, map, 2, cells);
        }
        
        for (int i = 0; i < colCount; i++) {
            traverseFlow(0, i, heights, map, 1, cells);
            traverseFlow(rowCount - 1, i, heights, map, 2, cells);
        }
        
        return cells;
    }
    
    void traverseFlow(int row, int col, vector<vector<int>>& heights, vector<vector<int>>& map, int mask, vector<vector<int>>& cells) {
        static const vector<vector<int>> offsets = {
            {1, 0},  
            {-1, 0},  
            {0, 1},  
            {0, -1},  
        };
        
        vector<vector<int>> stack;
        stack.push_back({row, col});
        while (!stack.empty()) {
            vector<int> pos = stack.back();
            stack.pop_back();
            
            if (map[pos[0]][pos[1]] & mask) {
                continue;
            }
            
            map[pos[0]][pos[1]] |= mask;
            if (map[pos[0]][pos[1]] == 3) {
                cells.push_back({pos[0], pos[1]});
            }
            
            for (int i = 0; i < offsets.size(); i++) {
                int r = pos[0] + offsets[i][0];
                int c = pos[1] + offsets[i][1];
                if (r < 0 || c < 0 || r >= heights.size() || c >= heights[0].size() || heights[r][c] < heights[pos[0]][pos[1]]) {
                    continue;
                }
                
                stack.push_back({r, c});
            }
        }
    }
};