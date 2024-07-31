class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& visited, vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        visited[r][c] = 1;

        for(int i=0; i<4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && grid[nr][nc] == 1)
            {
                dfs(nr, nc, visited, grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>visited(n, vector<int>(m, 0));
        for(int i=0; i<m; i++)
        {
            if(!visited[0][i] && grid[0][i] == 1)
            {
                dfs(0, i, visited, grid);
            }
            if(!visited[n-1][i] && grid[n-1][i] == 1)
            {
                dfs(n-1, i, visited, grid);
            }
        }
        for(int i=0; i<n; i++)
        {
            if(!visited[i][0] && grid[i][0] == 1)
            {
                dfs(i, 0, visited, grid);
            }
            if(!visited[i][m-1] && grid[i][m-1] == 1)
            {
                dfs(i, m-1, visited, grid);
            }
        }

        int count = 0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!visited[i][j] && grid[i][j] == 1) count++;
            }
        }

        return count;
    }
};