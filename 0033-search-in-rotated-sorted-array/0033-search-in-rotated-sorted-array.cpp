class Solution {
public:
    int solve(vector<int> &arr, int target, int n){
        int l=0;
        int r=n-1;

        while(l<=r){
            int mid = l+(r-l)/2;

            if(arr[mid]==target) return mid;

            if(arr[l]<=arr[mid]){
                if(arr[l]<=target && target<=arr[mid]){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            else{
                if(arr[mid]<=target && target<=arr[r]){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();

        int idx = solve(nums,target, n);
        return idx;
        
    }
};