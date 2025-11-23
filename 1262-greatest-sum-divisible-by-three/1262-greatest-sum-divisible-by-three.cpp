class Solution {
public:
    int recur(vector<int> &nums, int rem, int i , vector<vector<int>> &dp){
        if(i>=nums.size()){
            if(rem==0) return 0;
            return INT_MIN;

        }

        if(dp[i][rem]!=-1) return dp[i][rem];
        int take = nums[i] + recur(nums, (nums[i]+rem)%3, i+1, dp);
        int skip = recur(nums, rem, i+1, dp);
        return dp[i][rem] =  max(skip, take);
    }
    int maxSumDivThree(vector<int>& nums) {
        int n= nums.size();

        vector<vector<int>> t(n, vector<int>(3,-1));
        return recur(nums, 0, 0 , t);
        
    }
};