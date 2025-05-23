class Solution {
public:
    //very good observation is this, that as every number appears twice , and one number appears once
    //so if this pattern is going on, first number of pair will be at even idx , and other one at odd
    //if a single element comes in b/w, means that will break this pattern of even and odd indices pairs

    //so we just check for this pattern, if pattern is fine , we check next half of array, by doing l = mid+1;
    //and if pattern is not satisfied, means that a single element is occured on left, so we check on left half of array, by doing r=mid.
    int singleNonDuplicate(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;

        while(l<r){
            int mid = l+(r-l)/2;

            if(mid%2==0 && nums[mid]==nums[mid+1] || mid&1 && nums[mid]==nums[mid-1]){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }

        return nums[r];


        
    }
};