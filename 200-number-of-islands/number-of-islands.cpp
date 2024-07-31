class Solution {
public:
    int dfs(int i, int j, int n, int m, vector<vector<char>>& grid,
            vector<vector<int>>& vis) {

        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] ||
            grid[i][j] != '1')
            return 0;
        vis[i][j] = 1;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

       
            for (int dj = 0; dj <4; dj++) {
                int nr = i + dx[dj];
                int nc = j + dy[dj];
                dfs(nr, nc, n, m, grid, vis);
            }
        

        return 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    count += dfs(i, j, n, m, grid, vis);
                }
            }
        }

        return count;
    }
};