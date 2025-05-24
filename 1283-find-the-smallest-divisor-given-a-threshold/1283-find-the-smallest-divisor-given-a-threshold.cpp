class Solution {
public:
    int checkSum(vector<int>& nums, int mid){
        int sum=0;
        for(int i:nums){
            sum+= (i+mid-1)/mid;
        }

        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1;
        int r=*max_element(nums.begin(),nums.end());

        while(l<r){
            int mid = l+(r-l)/2;
            if(checkSum(nums,mid)<=threshold){
                r=mid;
            }
            else l=mid+1;
        }

        return l;
        
    }
};