class Solution {
public:
    int dfs(int row, int col, int n, int m,vector<vector<int>>& visited, vector<vector<char>>& grid)
    {
        if(row < 0 || col < 0 || row >= n || col >= m || visited[row][col] || grid[row][col] != '1') return 0;

        visited[row][col] = 1;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for(int x=0; x<4; x++)
        {
            int nr = dx[x] + row;
            int nc = dy[x] + col;
            dfs(nr, nc, n, m, visited, grid);
        }

        return 1;

    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(grid.size(), vector<int>(grid[0].size(), 0));
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(!visited[i][j] && grid[i][j] == '1')
                {
                    count += dfs(i, j, n, m, visited, grid);
                }
            }
        }

        return count;
    }
};