class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>&board, vector<vector<int>>&visited)
    {
        int n = board.size();
        int m = board[0].size();
        visited[i][j] = 1;
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        for(int it=0; it<4; it++)
        {
            int nr = i + dr[it];
            int nc = j + dc[it];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && board[nr][nc] == 'O')
            {
                dfs(nr, nc, board, visited);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>visited(n, vector<int>(m, 0));


        for(int i=0; i<m; i++)
        {
            if(!visited[0][i] && board[0][i] == 'O')
            {
                dfs(0, i, board, visited);
            }
            if(!visited[n-1][i] && board[n-1][i] == 'O')
            {
                dfs(n-1, i, board, visited);
            }
        }
        for(int i=0; i<n; i++)
        {
            if(!visited[i][0] && board[i][0] == 'O')
            {
                dfs(i, 0, board, visited);
            }
            if(!visited[i][m-1] && board[i][m-1] == 'O')
            {
                dfs(i, m-1, board, visited);
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!visited[i][j] && board[i][j] == 'O'){
                    visited[i][j] = 1;
                    board[i][j] = 'X';
                }
            }
        }
    }
};