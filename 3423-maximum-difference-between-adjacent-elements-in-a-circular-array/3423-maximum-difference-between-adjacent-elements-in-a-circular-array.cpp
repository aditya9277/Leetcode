class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        if(n<2) return 0;
        
        for(int i=0;i<n;i++){
            int circular = (i + 1) % n;
            ans=max(ans,abs(nums[i]-nums[circular]));
            
        }

        return ans;
        
    }
};