class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        int subsets = 1<<n;

        for(int num = 0;num<subsets;num++){
            vector<int> ds;

            for(int i =0;i<n;i++){
                if(num&(1<<i)) ds.push_back(nums[i]);
            }

            ans.push_back(ds);
        }
        
        return ans;
    }
};