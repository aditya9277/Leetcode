class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minR = INT_MAX, maxR = INT_MIN;
        int minC = INT_MAX, maxC = INT_MIN;
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    minR = min(minR, i);
                    maxR = max(maxR, i);
                    minC = min(minC, j);
                    maxC = max(maxC, j);
                }
            }
        }
        
        int h = maxR - minR + 1;
        int w = maxC - minC + 1;
        
        return h * w;
    }
};