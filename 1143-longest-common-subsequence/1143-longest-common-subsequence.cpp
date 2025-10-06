class Solution {
public:
    //memo approach reaches TLE
    int solve(string s1, string s2, int i, int j, vector<vector<int>> &dp){
        if(i>=s1.length() || j>=s2.length()) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]) return dp[i][j] =  1 + solve(s1, s2, i+1, j+1, dp);
        else return dp[i][j] = max(solve(s1, s2, i+1, j, dp), solve(s1, s2, i, j+1, dp));
    }
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        // return solve(text1, text2, 0, 0, dp);

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j] =  1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[m][n];
    }
};