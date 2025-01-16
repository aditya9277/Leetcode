class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                int x=nums1[i]^nums2[j];
                ans=ans^x;
            }
        }
        return ans;

        
    }
};