

class Solution {
public:
    std::vector<int> maxPoints(std::vector<std::vector<int>>& grid, std::vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();
        int k = queries.size();

        // 1. Create indexed queries and sort them by query value.
        // This allows us to process queries in increasing order of their threshold.
        std::vector<std::pair<int, int>> indexed_queries;
        for (int i = 0; i < k; ++i) {
            indexed_queries.push_back({queries[i], i});
        }
        std::sort(indexed_queries.begin(), indexed_queries.end());

        // 2. Initialize data structures for the search.
        std::vector<int> ans(k);
        
        // Min-priority queue to store {value, row, col} of cells on the frontier.
        // It always gives us the cell with the smallest value to explore next.
        std::priority_queue<std::tuple<int, int, int>, 
                              std::vector<std::tuple<int, int, int>>, 
                              std::greater<std::tuple<int, int, int>>> pq;
        
        // visited array to avoid processing a cell more than once.
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
        
        int points_count = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // 3. Start the search from the top-left cell (0, 0).
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        // 4. Process each sorted query.
        for (const auto& iq : indexed_queries) {
            int query_val = iq.first;
            int original_idx = iq.second;

            // 5. Expand the reachable component.
            // Add all cells from the frontier (pq) that have a value less than the current query value.
            while (!pq.empty()) {
                auto [val, r, c] = pq.top();
                
                // If the smallest value on the frontier is not strictly less than the query,
                // we can't expand further for this query. Stop and move to the next query.
                if (val >= query_val) {
                    break;
                }
                pq.pop();
                points_count++;

                // Explore neighbors of the newly added cell.
                for (int i = 0; i < 4; ++i) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    // If a neighbor is valid and not yet visited, add it to the frontier.
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                        visited[nr][nc] = true;
                        pq.push({grid[nr][nc], nr, nc});
                    }
                }
            }
            
            // 6. The current points_count is the answer for this query.
            // Store it in the original position.
            ans[original_idx] = points_count;
        }

        return ans;
    }
};