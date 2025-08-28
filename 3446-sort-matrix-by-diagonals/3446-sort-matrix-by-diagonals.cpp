#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional>

class Solution {
public:
    std::vector<std::vector<int>> sortMatrix(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) {
            return grid;
        }

        // Maps to store elements of each diagonal
        // Key for bottom-left (including main) is i - j
        // Key for top-right is j - i
        std::unordered_map<int, std::vector<int>> bottomLeftDiagonals;
        std::unordered_map<int, std::vector<int>> topRightDiagonals;

        // 1. Extract elements and group them by diagonal
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i >= j) { // Bottom-left triangle including the main diagonal
                    bottomLeftDiagonals[i - j].push_back(grid[i][j]);
                } else { // Top-right triangle
                    topRightDiagonals[j - i].push_back(grid[i][j]);
                }
            }
        }

        // 2. Sort the diagonals based on the rules
        // Bottom-left diagonals: non-increasing (descending) order
        for (auto& pair : bottomLeftDiagonals) {
            std::sort(pair.second.begin(), pair.second.end(), std::greater<int>());
        }
        // Top-right diagonals: non-decreasing (ascending) order
        for (auto& pair : topRightDiagonals) {
            std::sort(pair.second.begin(), pair.second.end());
        }

        // 3. Place the sorted elements back into the grid
        // Use maps to keep track of the current index for each sorted diagonal vector
        std::unordered_map<int, int> bottomLeftIndices;
        std::unordered_map<int, int> topRightIndices;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i >= j) {
                    int key = i - j;
                    grid[i][j] = bottomLeftDiagonals[key][bottomLeftIndices[key]++];
                } else {
                    int key = j - i;
                    grid[i][j] = topRightDiagonals[key][topRightIndices[key]++];
                }
            }
        }

        return grid;
    }
};