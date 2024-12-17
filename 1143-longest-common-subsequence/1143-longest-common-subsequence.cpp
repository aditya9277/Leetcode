#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= m; i++) {
            int prev_diag = 0; 
            for (int j = 1; j <= n; j++) {
                int temp = dp[j]; 
                if (text1[i - 1] == text2[j - 1]) {
                    dp[j] = prev_diag + 1; 
                } else {
                    dp[j] = max(dp[j], dp[j - 1]); 
                }
                prev_diag = temp; 
            }
        }

        return dp[n];
    }
};