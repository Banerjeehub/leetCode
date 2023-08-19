class Solution {
private:
    void BFS(int first, int second, vector<vector<int>>&visited, vector<vector<char>>&grid)
    {
        visited[first][second] = 1;
        queue<pair<int,int>>q;
        int rowSize = grid.size();
        int colSize = grid[0].size();
        q.push({first, second});

        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int row = -1; row <= 1; row++)
            {
                for(int col = -1; col <= 1; col++)
                {
                    int newRow = r + row;
                    int newCol = c + col;

                    if(row != 0 && col != 0) continue;

                    if(newRow >= 0 && newRow < rowSize &&
                       newCol >= 0 && newCol < colSize &&
                       !visited[newRow][newCol] && grid[newRow][newCol] == '1')
                       {
                           visited[newRow][newCol] = 1;
                           q.push({newRow, newCol});
                       }
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int rowSize = grid.size();
        int colSize = grid[0].size();

        vector<vector<int>>visited(rowSize, vector<int>(colSize, 0));
        int count = 0;

        for(int row = 0; row < rowSize; row++)
        {
            for(int col = 0; col < colSize; col++)
            {
                if(!visited[row][col] && grid[row][col] == '1')
                {
                    count++;
                    BFS(row, col, visited, grid);
                }
            }
        }

        return count;
    }
};