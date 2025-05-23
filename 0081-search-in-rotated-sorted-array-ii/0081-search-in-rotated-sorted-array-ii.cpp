class Solution {
    //same approach as of Search in Rotated Sorted Array I, just cuz of duplicates a small tweak
public:
    int findPivot(vector<int> &nums, int n){
        int l = 0;
        int r=n-1;

        while(l<r){
            //as it contains duplicates, it can lead to wrong pivot so a small tweak here

            //skip duplicates from both left and right
            // while(l<r && nums[l]==nums[l+1]) l++; //skip from left
            // while(l<r && nums[r]==nums[r-1]) r--; //skip from right
            //rest whole approach is same
            int mid = l +(r-l)/2;
            if(nums[mid]>nums[r]){
                l=mid+1;
            }
            else if(nums[mid]<nums[r]){
                r=mid;
            }
            else{
                r--;
            }
        }
        return r;
    }

    bool bs(vector<int>&nums, int target, int l, int r, int n){
        while(l<=r){
            int mid = l+(r-l)/2;

            if(nums[mid]==target) return true;

            if(nums[mid]<target) l=mid+1;
            else{
                r=mid-1;
            }
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        //cswm approach

        int n=nums.size();

        int pivot = findPivot(nums,n);

        //apply bs on left
        if(bs(nums, target,pivot, n-1, n)) return true;
        if(bs(nums, target,0,pivot-1, n)) return true;
        
        //apply bs on right

        return false;
    }
};