class Solution {
public:
    void bfs(int row, int col, int n, int m, vector<vector<int>>& visited, vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = 1;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();

            for (int i = 0; i < 4; ++i) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                    !visited[nr][nc] && grid[nr][nc] == '1') {
                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    bfs(i, j, n, m, visited, grid);
                    count++;
                }
            }
        }

        return count;
    }
};