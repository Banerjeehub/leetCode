class Solution {
private:
    void helper(int row, int col, vector<vector<char>>&board, vector<vector<int>>&visited,
                vector<int>delRow, vector<int>delCol)
        {
            visited[row][col] = 1;
            int rowSize = board.size();
            int colSize = board[0].size();

            for(int i=0; i<4; i++)
            {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(newRow >= 0 and newRow < rowSize
                and newCol >= 0 and newCol < colSize
                and !visited[newRow][newCol] and
                board[newRow][newCol] == 'O')
                {
                    helper(newRow, newCol, board, visited, delRow, delCol);
                }
            }
        }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>>visited(n, vector<int>(m, 0));
        vector<int>delRow, delCol;
        delRow = {0, 0, 1, -1};
        delCol = {1, -1, 0, 0};

        for(int i=0; i<m; i++)
        {
            if(!visited[0][i] && board[0][i] == 'O')
            {
                helper(0, i, board, visited, delRow, delCol);
            }
            if(!visited[n-1][i] && board[n-1][i] == 'O')
            {
                helper(n-1, i, board, visited, delRow, delCol);
            }
        }
        for(int i=0; i<n; i++)
        {
            if(!visited[i][0] && board[i][0] == 'O')
            {
                helper(i, 0, board, visited, delRow, delCol);
            }
            if(!visited[i][m-1] && board[i][m-1] == 'O')
            {
                helper(i,m-1, board, visited, delRow, delCol);
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!visited[i][j] and board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};