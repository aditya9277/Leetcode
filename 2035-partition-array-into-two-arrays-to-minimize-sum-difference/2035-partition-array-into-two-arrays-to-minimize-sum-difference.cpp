
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int total_n = nums.size();
        int n = total_n / 2;
        long long total_sum = 0;
        for (int x : nums) {
            total_sum += x;
        }

        vector<int> left_half(nums.begin(), nums.begin() + n);
        vector<int> right_half(nums.begin() + n, nums.end());

        map<int, vector<long long>> left_sums;
        map<int, vector<long long>> right_sums;

        // Generate subset sums for left_half
        for (int i = 0; i < (1 << n); ++i) {
            long long current_sum = 0;
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    current_sum += left_half[j];
                    count++;
                }
            }
            left_sums[count].push_back(current_sum);
        }

        // Generate subset sums for right_half
        for (int i = 0; i < (1 << n); ++i) {
            long long current_sum = 0;
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    current_sum += right_half[j];
                    count++;
                }
            }
            right_sums[count].push_back(current_sum);
        }

        for (auto& pair : left_sums) {
            sort(pair.second.begin(), pair.second.end());
        }
        for (auto& pair : right_sums) {
            sort(pair.second.begin(), pair.second.end());
        }

        long long min_diff = LLONG_MAX;

        for (int k = 0; k <= n; ++k) { // k elements from left_half
            // We need (n - k) elements from right_half
            if (right_sums.find(n - k) == right_sums.end()) {
                continue;
            }

            for (long long l_sum : left_sums[k]) {
                // We want left_sum + r_sum to be close to total_sum / 2
                // Or equivalently, 2 * (l_sum + r_sum) should be close to total_sum
                // So, 2 * r_sum should be close to total_sum - 2 * l_sum
                long long target_for_2r = total_sum - 2 * l_sum;

                // Binary search for r_sum in right_sums[n - k]
                auto& r_vec = right_sums[n - k];
                
                // Find element >= target_for_2r / 2
                auto it = lower_bound(r_vec.begin(), r_vec.end(), target_for_2r / 2);

                if (it != r_vec.end()) {
                    long long r_sum1 = *it;
                    min_diff = min(min_diff, abs(2 * (l_sum + r_sum1) - total_sum));
                }
                if (it != r_vec.begin()) {
                    long long r_sum2 = *(--it);
                    min_diff = min(min_diff, abs(2 * (l_sum + r_sum2) - total_sum));
                }
            }
        }

        return min_diff;
    }
};