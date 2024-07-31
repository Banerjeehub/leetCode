class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        int freshCount = 0;
        queue<pair<pair<int, int>, int>>q;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                } else {
                    visited[i][j] = 0;
                }
                if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }
        int result = 0;
        int count = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            result = max(result, t);

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    grid[nr][nc] == 1 && visited[nr][nc] != 2) {
                    q.push({{nr, nc}, t + 1});
                    visited[nr][nc] = 2;
                    count++;
                }
            }
        }

        if (count != freshCount)
            return -1;
        return result;
    }
};