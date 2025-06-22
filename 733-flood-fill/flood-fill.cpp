class Solution {
public:
    void dfs(vector<vector<int>>& image, vector<vector<int>>& visited, int sr, int sc, int color, int initColor, int n, int m)
    {
        visited[sr][sc] = 1;
        image[sr][sc] = color;

        int dr[] = {0,0,1,-1};
        int dc[] = {1,-1,0,0};

        for(int i=0; i<4; i++)
        {
            int nr = sr + dr[i];
            int nc = sc + dc[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && image[nr][nc] == initColor)
            {
                dfs(image, visited, nr, nc, color, initColor, n, m);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>>visited(n, vector<int>(m, 0));
        dfs(image, visited, sr, sc, color, image[sr][sc], n, m);
        return image;
    }
};