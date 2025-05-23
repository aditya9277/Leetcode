class Solution {
public:
    int findpivot(vector<int>& nums, int n){
        int l=0;
        int r=n-1;
        
        while(l<r){ 
            int mid = l+(r-l)/2;
            //this approach of skipping duplicates is failing, so we tried another tweak
            // while(l<r && nums[l]==nums[l+1]) l++;
            // while(l<r && nums[r]==nums[r-1]) r--;

            //  that is if nums[mid]==nums[r], we are not sure what to do , we just decrease r, and in this case, nums[l], will be the answer
            
            if(nums[mid]>nums[r]) l=mid+1; 
            else if(nums[mid]<nums[r]) r=mid;
            else{
                r--;
            } 
        }
        return nums[l];
    }
    int findMin(vector<int>& nums) {
        int n=nums.size();
        return findpivot(nums, n);

    }
};