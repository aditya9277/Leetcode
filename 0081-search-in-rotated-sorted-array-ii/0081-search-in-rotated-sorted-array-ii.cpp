class Solution {
public:
    int findPivot(vector<int> &nums, int n){
        int l = 0;
        int r=n-1;

        while(l<r){
            int mid = l +(r-l)/2;
            if(nums[mid]>nums[r]){
                l=mid+1;
            }
            else{
                r=mid;
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
        if(bs(nums, target,0,pivot-1, n)) return true;
        
        //apply bs on right
        if(bs(nums, target,pivot, n-1, n)) return true;

        return false;
    }
};