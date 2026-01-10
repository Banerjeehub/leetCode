class Solution {
public:
    void helper(int idx, int n, vector<int>& col, vector<int>& diag,
                vector<int>& antiDiag, vector<string>& temp,
                vector<vector<string>>& ans) {
        if (idx == n) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!col[i] && !diag[idx - i + (n - 1)] && !antiDiag[idx + i]) {
                string tempRow(n, '.');
                tempRow[i] = 'Q';
                temp.push_back(tempRow);
                col[i] = 1;
                diag[idx - i + (n - 1)] = 1;
                antiDiag[idx + i] = 1;
                helper(idx + 1, n, col, diag, antiDiag, temp, ans);
                tempRow[i] = '.';
                temp.pop_back();
                col[i] = 0;
                diag[idx - i + (n - 1)] = 0;
                antiDiag[idx + i] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp;
        vector<int> col(n, 0);
        vector<int> diag(n * 2, 0), antiDiag(n * 2, 0);
        helper(0, n, col, diag, antiDiag, temp, ans);
        return ans;
    }
};