class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) {
            return 0;
        }

        int m = mat.size();
        int n = mat[0].size();
        int totalCount = 0;
        std::vector<int> heights(n, 0);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }

            std::vector<int> sum(n, 0);
            std::stack<int> st;

            for (int j = 0; j < n; ++j) {
                while (!st.empty() && heights[st.top()] >= heights[j]) {
                    st.pop();
                }

                if (st.empty()) {
                    sum[j] = (j + 1) * heights[j];
                } else {
                    int p = st.top();
                    sum[j] = sum[p] + (j - p) * heights[j];
                }
                st.push(j);
            }
            
            for (int count : sum) {
                totalCount += count;
            }
        }

        return totalCount;

        
    }
};