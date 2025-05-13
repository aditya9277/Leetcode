class Solution {
public:
    int m,n;
    int result;
    int nonObs;
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};

    void backT(vector<vector<int>>& grid, int ct, int i, int j){

        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==-1) return;
        
        if(grid[i][j]==2){
            if(ct==nonObs) {
                result++;   
            }
            return;
        }

        grid[i][j]=-1;

        for(auto &dir:directions){
            int _i = i+ dir[0];
            int _j = j+ dir[1];

            backT(grid, ct+1,_i,_j);
        }

        grid[i][j]=0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        m = grid.size();
        n=grid[0].size();

        int start=0, end=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) nonObs++;

                if(grid[i][j]==1){
                    start=i;
                    end=j;
                }
            }
        }

        nonObs++;
        int ct=0;

        backT(grid, ct, start, end);

        return result;
        
        
    }
};