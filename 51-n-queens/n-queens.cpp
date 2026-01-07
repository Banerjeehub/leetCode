class Solution {
public:
    void helper(int row, int n, vector<int>& colPos, vector<int>& diag,
                vector<int>& antDig, vector<string>& temp,
                vector<vector<string>> &ans) {
        if (row == n) {
            ans.push_back(temp);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (!colPos[col] && !diag[row - col + (n - 1)] && !antDig[row + col]) {
                string rowString(n, '.'); // "...."
                rowString[col] = 'Q';     // "..Q."
                temp.push_back(rowString);
                colPos[col] = 1;
                diag[row-col + (n - 1)] = 1;
                antDig[row + col] = 1;
                helper(row+1, n, colPos, diag, antDig, temp, ans);
                temp.pop_back();
                colPos[col] = 0;
                diag[row-col + (n - 1)] = 0;
                antDig[row + col] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> colPos(n, 0);
        vector<int> diag(2 * n - 1, 0);
        vector<int> antDig(2 * n - 1, 0);
        vector<vector<string>> ans;
        vector<string> temp;
        helper(0, n, colPos, diag, antDig, temp, ans);
        return ans;
    }
};