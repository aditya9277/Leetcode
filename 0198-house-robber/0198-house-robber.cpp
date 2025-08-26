class Solution {
public:
    int t[101] ;
    int solve(int n, int i , vector<int> & nums){
        if(i>=n) return 0;

        if(t[i]!=-1) return t[i];

        int steal = nums[i] + solve(n, i+2,nums);
        int skip = solve(n,i+1,nums);

        return t[i] =  max(steal, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==0) return 0;
        if(n==1) return nums[0];
        memset(t, -1, sizeof(t));

        return solve(n, 0, nums);
        
    }
};