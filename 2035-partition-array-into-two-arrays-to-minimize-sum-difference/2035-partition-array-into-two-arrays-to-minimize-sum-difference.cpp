

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int n = N / 2;
        
        vector<vector<int>> left_sums(n + 1);
        vector<vector<int>> right_sums(n + 1);

        generate_sums(0, n, nums, left_sums);
        generate_sums(n, N, nums, right_sums);
        
        for (int i = 0; i <= n; ++i) {
            sort(left_sums[i].begin(), left_sums[i].end());
            left_sums[i].erase(unique(left_sums[i].begin(), left_sums[i].end()), left_sums[i].end());
            sort(right_sums[i].begin(), right_sums[i].end());
        }

        long long total_sum = accumulate(nums.begin(), nums.end(), 0LL);
        
        int min_diff = INT_MAX;

        for (int k = 0; k <= n; ++k) {
            for (int s1_left : left_sums[k]) {
                int rem_k = n - k;
                auto& s_rights = right_sums[rem_k];
                
                long long target_s_right = total_sum / 2 - s1_left;
                
                auto it = lower_bound(s_rights.begin(), s_rights.end(), target_s_right);

                if (it != s_rights.end()) {
                    long long s_right = *it;
                    long long current_S1 = s1_left + s_right;
                    min_diff = min(min_diff, (int)abs(total_sum - 2 * current_S1));
                }

                if (it != s_rights.begin()) {
                    it--;
                    long long s_right = *it;
                    long long current_S1 = s1_left + s_right;
                    min_diff = min(min_diff, (int)abs(total_sum - 2 * current_S1));
                }
            }
        }
        return min_diff;
    }

private:
    void generate_sums(int start_idx, int end_idx, const vector<int>& arr, vector<vector<int>>& sums) {
        int sz = end_idx - start_idx;
        int limit = 1 << sz;
        for (int i = 0; i < limit; ++i) {
            int current_sum = 0;
            int count = 0;
            for (int j = 0; j < sz; ++j) {
                if ((i >> j) & 1) {
                    current_sum += arr[start_idx + j];
                    count++;
                }
            }
            sums[count].push_back(current_sum);
        }
    }
};