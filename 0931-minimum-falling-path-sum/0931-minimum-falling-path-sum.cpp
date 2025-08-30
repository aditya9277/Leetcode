//recur + memo gives TLE at last becuase of recursion stack space overflow
// class Solution {
// public:
//     int solve(vector<vector<int>>& mat, int i, int j, vector<vector<int>>& dp){
//         if(j<0 || j>=mat[0].size()) return 1e9;
//         if(i==0) return mat[0][j];
//         if(dp[i][j]!=-1) return dp[i][j];
//         int ld = mat[i][j] + solve(mat,i-1,j-1,dp);
//         int rd = mat[i][j] + solve(mat, i-1, j+1,dp);
//         int up = mat[i][j] + solve(mat, i-1, j,dp);
//         return dp[i][j] =  min(up, min(ld, rd));

//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         int mini = 1e9;

//         vector<vector<int>> dp(m, vector<int>(n,-1));

//         for(int j=0;j<n;j++){
//             mini = min(mini, solve(matrix, m-1, j,dp));
//         }
//         return mini;
//     }
// };

class Solution {
    //bottom up approach
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n,0));

        for(int j=0;j<n;j++){
            dp[0][j] = matrix[0][j];
        }

        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                int up = matrix[i][j] + dp[i-1][j];
                int ld = matrix[i][j] + (j-1>=0 ? dp[i-1][j-1]:1e9);
                int rd = matrix[i][j] + (j+1<n ? dp[i-1][j+1]:1e9);

                dp[i][j] = min({up,ld,rd});
            }
        }


        int mini = dp[n-1][0];

        for(int j=1;j<n;j++){
            mini = min(mini, dp[n-1][j]);
        }

        return mini;
    }
};