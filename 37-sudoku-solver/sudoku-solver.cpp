class Solution {
public:
    bool row[9][10] = {false};
    bool col[9][10] = {false};
    bool box[9][10] = {false};

    vector<pair<int,int>> empty;

    bool solve(int idx, vector<vector<char>>& board) {
        if (idx == empty.size()) return true;

        int r = empty[idx].first;
        int c = empty[idx].second;
        int b = (r / 3) * 3 + (c / 3);

        for (int d = 1; d <= 9; d++) {
            if (!row[r][d] && !col[c][d] && !box[b][d]) {
                board[r][c] = d + '0';
                row[r][d] = col[c][d] = box[b][d] = true;

                if (solve(idx + 1, board)) return true;

                board[r][c] = '.';
                row[r][d] = col[c][d] = box[b][d] = false;
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        // Initialize constraints & empty cells
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    empty.push_back({i, j});
                } else {
                    int d = board[i][j] - '0';
                    int b = (i / 3) * 3 + (j / 3);
                    row[i][d] = col[j][d] = box[b][d] = true;
                }
            }
        }

        solve(0, board);
    }
};