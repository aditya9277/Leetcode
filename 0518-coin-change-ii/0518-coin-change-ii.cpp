class Solution {
public:
    int solve(vector<int> &coins, int target, int idx, vector<vector<int>> &dp){

        if(idx==0){
            return (target%coins[0] == 0 ? 1: 0);
        }

        if(dp[idx][target]!=-1) return dp[idx][target];

        int skip = solve(coins, target, idx-1, dp);
        int take = 0;
        if(coins[idx]<=target){
            take = solve(coins, target - coins[idx], idx, dp); 
        }

        return dp[idx][target] =  skip + take;

    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount+1, -1));

        int ans = solve(coins,amount, coins.size()-1, dp);
        
        return ans;
    }
};