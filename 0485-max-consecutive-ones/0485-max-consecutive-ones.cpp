class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ct=0;
        int mct=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) ct++;
            else{
                ct=0;
            }
            mct=max(mct,ct);

        }
        return mct;
        
    }
};