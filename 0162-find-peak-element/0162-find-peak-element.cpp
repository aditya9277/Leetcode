class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        // if(nums.size()==1) return 0;
        // if(nums.size()==2) return (nums[0]>nums[1])? 0:1;
        // if(nums[0]>nums[1] ) return 0;
        // if(nums[n-1]>nums[n-2]) return n-1;
        int l=0;
        int r=n-1;

        while(l<r){
            int mid = l +(r-l)/2;

            // if(nums[mid]>nums[mid+1] &&  nums[mid]>nums[mid-1]) return mid;
            //another approach can be , just skipping the above step, eventually when l==r, they will be at the peak only.
            //so returning l or r , will give the ans, and all the edge cases will be handled automatically

            if(nums[mid]<nums[mid+1]) l=mid+1;
            else{
                r=mid;
            }
        }

        return l;
        
    }
};