class Solution {
public:
    void dfs(int row, int col, int n, int m, int &count,
             vector<vector<int>>& visited, vector<vector<int>>& grid) {
        if (row < 0 || col < 0 || row >= n || col >= m || visited[row][col] ||
            grid[row][col] != 1)
            return;
        visited[row][col] = 1;
        count++;
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            dfs(nr, nc, n, m, count, visited, grid);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        int maxCount = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    int count = 0;
                    dfs(i, j, n, m, count, visited, grid);
                    maxCount = max(maxCount, count);
                }
            }
        }

        return maxCount;
    }
};