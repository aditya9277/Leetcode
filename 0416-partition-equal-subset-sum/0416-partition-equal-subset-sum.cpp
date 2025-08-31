class Solution {
public:
    bool solve(vector<int> &a, int idx, int target){
        if(target==0) return true;
        if(idx==0) return (target==a[0]);

        bool skip = solve(a, idx-1, target);
        bool take = false;
        if(target>=a[idx]){
            take = solve(a, idx-1, target - a[idx]);
        }

        return (skip ||take);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int s=0;

        for(int i : nums){
            s +=i;
        }
        if(s&1) return false;
        else s/=2;

        return solve(nums, n-1, s);
        
    }
};