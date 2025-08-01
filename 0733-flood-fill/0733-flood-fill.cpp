class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        int original = image[sr][sc];
        if(original == color) return image;
        vis[sr][sc] = 1;
        image[sr][sc] = color;

        int drow[] = {-1,0,1,0}; 
        int dcol[] = {0,-1,0,1};
        q.push({sr,sc});

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for(int i = 0;i<4;i++){
                int row = r+ drow[i];
                int col = c + dcol[i];

                if(row>=0 && row<m && col>=0 && col<n && image[row][col]==original && vis[row][col]!=1){
                    q.push({row, col});
                    image[row][col] = color;
                    vis[row][col]=1;
                }
            }
        }

        return image;
        
    }
};