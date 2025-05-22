class Solution {
public:
    int findFirst(vector<int>& nums, int target, int n) {
        int l = 0;
        int r = n - 1;

        int leftMost = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) {
                leftMost = mid; // might be an answer
                r = mid - 1;    // look more on left
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return leftMost;
    }

    int findLast(vector<int> &nums, int target, int n) {
        int l = 0;
        int r = n - 1;
        int rightMost = -1;

        while (l <= r) {
            int mid = l +(r-l)/2;
            if(nums[mid]==target){
                rightMost = mid; //might be an answer;
                l=mid+1; //look more on right
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return rightMost;

    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int first = findFirst(nums, target, n);
        int last = findLast(nums, target, n);

        return {first,last};
    }
};