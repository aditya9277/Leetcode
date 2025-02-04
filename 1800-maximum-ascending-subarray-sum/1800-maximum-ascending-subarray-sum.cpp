class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans=0;
        if(nums.size()==1) return nums[0];

        for(int i=0;i<nums.size()-1;i++){
            int sum=nums[i];
            for(int j=i;j<nums.size();j++){
                if(nums[j+1]>=nums[j]){
                    sum+=nums[j+1];
                }
                else break;
            }
            ans=max(ans,sum);  
        }
        return ans;
        
    }
};