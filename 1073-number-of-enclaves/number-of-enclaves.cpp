class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&visited)
    {
        int n = grid.size();
        int m = grid[0].size();
        visited[i][j] = 1;

        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        for(int id=0; id<4; id++)
        {
            int nr = i + dr[id];
            int nc = j + dc[id];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && grid[nr][nc] == 1)
            {
                dfs(nr, nc, grid, visited);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n, vector<int>(m ,0));
        for(int i=0; i<n; i++)
        {
            if(grid[i][0] == 1 && !visited[i][0])
            {
                dfs(i, 0, grid, visited);
            }
            if(grid[i][m-1] == 1 && !visited[i][m-1])
            {
                dfs(i, m-1, grid, visited);
            }
        }

        for(int i=0; i<m; i++)
        {
            if(grid[0][i] == 1 && !visited[0][i])
            {
                dfs(0, i, grid, visited);
            }

            if(grid[n-1][i] == 1 && !visited[n-1][i])
            {
                dfs(n-1, i, grid, visited);
            }
        }
        int count = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!visited[i][j] && grid[i][j] == 1)
                {
                    count++;
                }
            }
        }

        return count;
    }
};