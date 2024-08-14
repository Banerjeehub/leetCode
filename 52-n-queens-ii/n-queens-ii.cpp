class Solution {
public:
    bool isCheck(int row, int col, int n, vector<string>& board) {
        int dr(row), dc(col);
        // same row

        while (dc >= 0) {
            if (board[dr][dc] == 'Q')
                return false;
            dc--;
        }

        dr = row;
        dc = col;

        // upper diagonal

        while (dr >= 0 && dc >= 0) {
            if (board[dr][dc] == 'Q')
                return false;
            dr--;
            dc--;
        }

        // lower diagonal
        dr = row;
        dc = col;
        while (dc >= 0 && dr < n) {
            if (board[dr][dc] == 'Q')
                return false;
            dr++;
            dc--;
        }

        return true;
    }
    void solve(int col, int n, vector<string>& board,
               int &ans) {
        if (col == n) {
            ans++;
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isCheck(row, col, n, board)) {
                board[row][col] = 'Q';
                solve(col + 1, n, board, ans);
                board[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {

        int ans = 0;
        string str(n, '.');
        vector<string> board(n, str);
        solve(0, n, board, ans);
        return ans;
    }
};