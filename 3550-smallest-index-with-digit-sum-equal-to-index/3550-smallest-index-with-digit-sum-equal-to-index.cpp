class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            int num=nums[i];
            while(num!=0){
                int digit=num%10;
                num/=10;
                sum+=digit;
            }
            if(sum==i){
                if(ans ==-1 || i<ans){

                ans = i;
                }
            }
            
        }
        return ans;
        
    }
};