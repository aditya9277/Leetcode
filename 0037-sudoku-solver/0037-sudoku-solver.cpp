class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(cols));
        memset(boxes, 0, sizeof(boxes));

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    int mask = 1 << num;
                    rows[i] |= mask;
                    cols[j] |= mask;
                    boxes[i / 3][j / 3] |= mask;
                }
            }
        }
        solve(board);
    }

private:
    int rows[9];
    int cols[9];
    int boxes[3][3];

    bool solve(vector<vector<char>>& board) {
        int r = -1, c = -1;
        int min_candidates = 10;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    int candidates = 0;
                    int taken = rows[i] | cols[j] | boxes[i / 3][j / 3];
                    for (int k = 1; k <= 9; ++k) {
                        if (!((taken >> k) & 1)) {
                            candidates++;
                        }
                    }
                    if (candidates < min_candidates) {
                        min_candidates = candidates;
                        r = i;
                        c = j;
                    }
                }
            }
        }

        if (r == -1) {
            return true;
        }

        int taken = rows[r] | cols[c] | boxes[r / 3][c / 3];
        for (int num = 1; num <= 9; ++num) {
            int mask = 1 << num;
            if (!(taken & mask)) {
                board[r][c] = num + '0';
                rows[r] |= mask;
                cols[c] |= mask;
                boxes[r / 3][c / 3] |= mask;

                if (solve(board)) {
                    return true;
                }

                board[r][c] = '.';
                rows[r] &= ~mask;
                cols[c] &= ~mask;
                boxes[r / 3][c / 3] &= ~mask;
            }
        }
        
        return false;
    }
};