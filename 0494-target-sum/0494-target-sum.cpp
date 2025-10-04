class Solution {
public:
    int solve(vector<int>& nums, int i, int curr, int target, int sum, vector<vector<int>>& dp) {
        if (i == nums.size()) {
            if (curr == target)
                return 1;
            return 0;
        }

        if (dp[i][curr + sum] != -1)
            return dp[i][curr + sum];

        int plus = solve(nums, i + 1, curr + nums[i], target, sum,dp);
        int minus = solve(nums, i + 1, curr - nums[i], target,sum, dp);

        return dp[i][curr + sum] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, -1));

        return solve(nums, 0, 0, target, sum, dp);
    }
};