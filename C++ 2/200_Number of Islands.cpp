class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const vector<pair<int, int>> offsets = {
            make_pair(-1, 0),
            make_pair(1, 0),
            make_pair(0, -1),
            make_pair(0, 1),
        };
        
        int count = 0;
        int width = grid.size() - 1;
        int height = grid[0].size() - 1;
        for (int x = 0; x <= width; x++) {
            for (int y = 0; y <= height; y++) {
                if (grid[x][y] == '1') {
                    count++;
                    
                    vector<pair<int, int>> stack;
                    stack.push_back(make_pair(x, y));
                    while (!stack.empty()) {
                        auto pos = stack.back();
                        stack.pop_back();
                        grid[pos.first][pos.second] = '0';
                        
                        for (int i = 0; i < offsets.size(); i++) {
                            int posX = pos.first + offsets[i].first;
                            int posY = pos.second + offsets[i].second;
                            if (posX >= 0 && posY >= 0 && posX <= width && posY <= height && grid[posX][posY] == '1') {
                                stack.push_back(make_pair(posX, posY));
                            }
                        }
                    }
                }
            }
        }
        
        return count;
    }
};