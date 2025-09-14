class Solution {
public:
    int solve(vector<int> &coins, int target, int idx, vector<vector<int>> &dp){

        if(idx==0){
            if(target%coins[0] == 0) {
                return target/coins[0];
            }
            else return 1e9;
        }

        if(dp[idx][target]!=-1) return dp[idx][target];

        int skip = 0 + solve(coins, target, idx-1, dp);
        int take = INT_MAX;
        if(coins[idx]<=target){
            take = 1 + solve(coins, target - coins[idx], idx, dp);
        }

        return dp[idx][target] =  min(skip, take);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));

        int ans = solve(coins,amount, coins.size()-1, dp);

        if(ans>=1e9){
            return -1;
        }


        return ans;

        
    }
};