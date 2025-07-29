// class Solution {
// public:
//     void solve(int i , int curr, int maxi,int size, vector<int>& nums, vector<int>& ans ){
//         if(i==nums.size()){
//             if(curr == maxi){
//                 ans.push_back(size);
//             }
//             return;
//         }

//         //take
//         solve(i+1, curr | nums[i], maxi, size+1, nums, ans);
//         //not take
//         solve(i+1, curr, maxi, size, nums, ans);

//     }
//     vector<int> smallestSubarrays(vector<int>& nums) {
//         int maxi = 0;
//         vector<int> ans;
//         int size = 0;
//         for(int num : nums) maxi |=num;

//         solve(0,0,maxi,size,nums,ans);

//         return ans;


        
//     }
// };

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> nearest(32, -1);
        vector<int> ans(n);
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 32; j++) {
                if (nums[i] & (1 << j)) {
                    nearest[j] = i;
                }
            }
            
            int lastSetBit = i;
            for (int j = 0; j < 32; j++) {
                lastSetBit = max(lastSetBit, nearest[j]);
            }

            ans[i] = lastSetBit - i + 1;
        }
        
        return ans;
    }
};