#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        int max_prefix_val = 0;
        int max_diff = 0;

        for (int num : nums) {
            ans = max(ans, (long long)max_diff * num);
            max_diff = max(max_diff, max_prefix_val - num);
            max_prefix_val = max(max_prefix_val, num);
        }
        
        return ans;
    }
};