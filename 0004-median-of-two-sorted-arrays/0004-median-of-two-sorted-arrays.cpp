class Solution {
public:
    double merge(vector<int> &nums1,vector<int> &nums2,int m,int n){
        vector<int> temp;
        int left=0;
        int right=0;
        while(left<m && right<n){
            if(nums1[left]<=nums2[right]){
                temp.push_back(nums1[left]);
                left++;
            }
            else{
                temp.push_back(nums2[right]);
                right++;
            }
        }
        while(left<m){
            temp.push_back(nums1[left]);
            left++;
        }
        while(right<n){
            temp.push_back(nums2[right]);
            right++;
        }
        int size = temp.size();
        if (size % 2 == 0) {
            // If even, take the average of the two middle elements
            return (temp[size / 2 - 1] + temp[size / 2]) / 2.0;
        } else {
            // If odd, return the middle element
            return temp[size / 2];
        }

    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        double ans = merge(nums1,nums2,m,n);
        return ans;

        
    }
};