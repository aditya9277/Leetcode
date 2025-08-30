#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1;
        int count = 0;
        int currentSum = 0;
        for (int num : nums) {
            currentSum += num;
            if (prefixSumCount.count(currentSum - k)) {
                count += prefixSumCount[currentSum - k];
            }
            prefixSumCount[currentSum]++;
        }
        return count;
    }
};