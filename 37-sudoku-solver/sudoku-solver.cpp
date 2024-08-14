class Solution {
public:
    bool isSafe(int row, int col, char num, vector<vector<char>>& board)
    {
        for(int i=0; i<board.size(); i++)
        {
            if(board[i][col] == num) return false;
            if(board[row][i] == num) return false;

        }

        int sr = (row/3) * 3;
        int sc = (col/3) * 3;

        for(int i=sr; i<sr+3; i++)
        {
            for(int j=sc; j<sc+3; j++)
            {
                if(board[i][j] == num) return false;
            }
        }
        return true;
    }
    bool helper(int row, int col, vector<vector<char>>& board)
    {
        if(row == board.size()) return true;
        int nRow = 0;
        int nCol = 0;
        if(col == board[0].size()-1)
        {
            nRow = row + 1;
            nCol = 0;
        }
        else
        {
            nRow = row;
            nCol = col + 1;
        }
        if(board[row][col] != '.')
        {
            if(helper(nRow, nCol, board)) return true;
        }
        else
        {
            for(int i='1'; i<='9'; i++)
            {
                if(isSafe(row, col, i, board))
                {
                    board[row][col] = i;
                    if(helper(nRow, nCol, board)) return true;
                    else board[row][col] = '.';
                }
            }
        }

        return false;

    }
    void solveSudoku(vector<vector<char>>& board) { helper(0, 0, board); }
};