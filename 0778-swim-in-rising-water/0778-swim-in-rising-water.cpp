class Solution {
public:
    int n;
    vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0,-1}};
    bool isPossible(int t, int i, int j, vector<vector<int>>& grid, vector<vector<int>> &vis){
        //explore all path via dfs
        if(i<0 || i>=n || j<0 || j>=n || vis[i][j]==true || grid[i][j]>t){
            return false;
        }
        vis[i][j]=true;

        if(i==n-1 && j==n-1) return true;

        for(auto &d : dir){
            int _i = i + d[0];
            int _j = j+ d[1];

            if(isPossible(t, _i ,_j, grid, vis)) return true;
        }
        return false;

    }
    //finding max time from minimised path
    //bs on answers
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int l = grid[0][0], r = n*n - 1;
        int ans = 0;

        while(l<=r){
            int mid = l +(r-l)/2;

            vector<vector<int>> vis(n, vector<int>(n, false));

            if(isPossible(mid, 0, 0, grid, vis)){
                ans = mid;
                r = mid-1;
            }
            else{
               l=mid+1;
            }
        }

        return ans;
        
    }
};