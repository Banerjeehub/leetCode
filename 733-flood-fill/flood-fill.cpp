class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>>visited(n, vector<int>(m, 0));
        queue<pair<int, int>>q;
        q.push({sr, sc});
        int initColor = image[sr][sc];
        image[sr][sc] = color;
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int dr[] = {1, -1, 0, 0};
            int dc[] = {0, 0, 1, -1};

            for(int i=0; i<4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && image[nr][nc] == initColor)
                {
                    q.push({nr, nc});
                    visited[nr][nc] = 1;
                    image[nr][nc] = color;
                }
            }
        }

        return image;

        
    }
};