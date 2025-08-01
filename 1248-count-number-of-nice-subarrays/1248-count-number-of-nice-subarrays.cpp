class Solution {
public:
int solve(vector<int>& nums, int k){
    int cnt = 0, l = 0, r = 0, odd = 0;

    while(r < nums.size()) {
        if(nums[r] % 2 == 1) {  // count if it's odd
            odd++;
        }

        while(odd > k) {
            if(nums[l] % 2 == 1) {
                odd--;
            }
            l++;
        }

        cnt += (r - l + 1);
        r++;
    }

    return cnt;
}

    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k-1);
        
        
    }
};