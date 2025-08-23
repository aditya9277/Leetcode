#include <vector>
#include <numeric>
#include <stack>
#include <algorithm>

class Solution {
public:
    int maximumScore(std::vector<int>& nums, int k) {
        int n = nums.size();
        
        int max_val = 0;
        for (int x : nums) {
            max_val = std::max(max_val, x);
        }

        std::vector<int> prime_scores(max_val + 1, 0);
        for (int i = 2; i <= max_val; ++i) {
            if (prime_scores[i] == 0) { 
                for (long long j = i; j <= max_val; j += i) {
                    prime_scores[j]++;
                }
            }
        }
        
        std::vector<int> ps(n);
        for(int i = 0; i < n; ++i) {
            ps[i] = prime_scores[nums[i]];
        }
        
        std::vector<int> left_boundary(n);
        std::stack<int> st_left;
        for (int i = 0; i < n; ++i) {
            while (!st_left.empty() && ps[st_left.top()] < ps[i]) {
                st_left.pop();
            }
            left_boundary[i] = st_left.empty() ? -1 : st_left.top();
            st_left.push(i);
        }
        
        std::vector<int> right_boundary(n);
        std::stack<int> st_right;
        for (int i = n - 1; i >= 0; --i) {
            while (!st_right.empty() && ps[st_right.top()] <= ps[i]) {
                st_right.pop();
            }
            right_boundary[i] = st_right.empty() ? n : st_right.top();
            st_right.push(i);
        }

        std::vector<int> indices(n);
        std::iota(indices.begin(), indices.end(), 0);
        
        std::sort(indices.begin(), indices.end(), [&](int a, int b) {
            return nums[a] > nums[b];
        });

        long long score = 1;
        long long MOD = 1e9 + 7;

        for (int i : indices) {
            if (k == 0) break;
            
            long long count = (long long)(i - left_boundary[i]) * (right_boundary[i] - i);
            long long num_to_take = std::min((long long)k, count);
            
            score = (score * power(nums[i], num_to_take, MOD)) % MOD;
            k -= num_to_take;
        }

        return (int)score;
    }

private:
    long long power(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }
};