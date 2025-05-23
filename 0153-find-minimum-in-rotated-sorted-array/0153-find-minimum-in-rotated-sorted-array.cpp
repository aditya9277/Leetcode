class Solution {
public:
    //just find the rotation point, its the first/smallest element
    //Mostly in questions , which have a rotated sorted array 
    //pivot index find karna he bs
    int findpivot(vector<int>& nums, int n){
        int l=0;
        int r=n-1;
        while(l<r){ //while finding pivot , if we take l<=r , then it will be stuck in loop, so l<r.
            int mid = l+(r-l)/2;

            if(nums[mid]>nums[r]) l=mid+1; //if nums[mid] > nums[r], means pivot will be on right
            else r=mid; //similarly, if nums[mid]<nums[r] means pivot can be mid or in the left itself;
        }
        return nums[r];
    }
    int findMin(vector<int>& nums) {
        int n=nums.size();
        return findpivot(nums, n);

        //easy boi
        
    }
};