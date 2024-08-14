class Solution {
public:
    bool isSafe(int row, int col, vector<string>&board, int n)
    {
        int dc = col;
        int dr = row;

        // current row
        while(dc >= 0)
        {
            if(board[dr][dc] == 'Q') return false;
            dc--;
        }
        dc = col;
        dr = row;

        while(dr >= 0 && dc >= 0)
        {
            if(board[dr][dc] == 'Q') return false;
            dr--;
            dc--;
        }

        dr = row;
        dc = col;

        while(dr < n && dc >= 0)
        {
            if(board[dr][dc] == 'Q') return false;
            dr++;
            dc--;
        }

        return true;
    }
    void solve(int col, int n, vector<string>&board,  vector<vector<string>>&ans)
    {
        if(col == n)
        {
            ans.push_back(board);
            return;
        }

        for(int row=0; row<n; row++)
        {
            if(isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                solve(col+1, n, board, ans);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>>ans;
        string str(n, '.');
        vector<string>board(n, str);
        solve(0, n, board, ans);
        return ans;

        

    }
};