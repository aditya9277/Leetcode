class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //brute force
        // int x=0,len=0;
        // for(int i=0;i<nums.size();i++){
        //     x=k;
        //     for(int j=i;j<nums.size();j++){
        //         if(nums[j]==0 && x>0){
        //             x--;
        //         }
        //         else if(nums[j]==0 && x==0){
        //             break;
        //         }
        //         len=max(len,j-i+1);
        //     }
        // }

        int l=0,r=0,zeros=0,len=0;
        while(r<nums.size()){
            if(nums[r]==0){
                zeros++;
            }
            if(zeros>k){
                if(nums[l]==0){
                    zeros--;       
                }
                l++;
            }
            len=max(len,r-l+1);
            r++;
            
        }

        return len;
        
    }
};