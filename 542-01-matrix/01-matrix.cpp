class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>visited(n, vector<int>(m, 0));
        vector<vector<int>>result(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>>q;


        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j] == 0)
                {
                    visited[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }

        while(!q.empty())
        {
            auto top = q.front();
            int x = q.front().first.first;
            int y = q.front().first.second;
            int d = q.front().second;
            q.pop();

            result[x][y] = d;

            int dr[] = {0, 0, 1, -1};
            int dc[] = {1, -1, 0, 0};
            for(int i=0; i<4; i++)
            {
                int nr = x + dr[i];
                int nc = y + dc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && mat[nr][nc] == 1)
                {
                     q.push({{nr, nc}, d + 1});
                    visited[nr][nc] = 1;
                }
            }
        }

        return result;


    }
};