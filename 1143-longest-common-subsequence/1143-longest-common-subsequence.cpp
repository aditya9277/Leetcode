class Solution {
public:
    int solve(string s1, string s2, int i, int j, vector<vector<int>> &dp){
        if(i>=s1.length() || j>=s2.length()) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]) return dp[i][j] =  1 + solve(s1, s2, i+1, j+1, dp);
        else return dp[i][j] = max(solve(s1, s2, i+1, j, dp), solve(s1, s2, i, j+1, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(text1, text2, 0, 0, dp);
        
    }
};