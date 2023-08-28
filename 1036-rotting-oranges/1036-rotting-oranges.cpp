class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int rowSize = grid.size();
        int colSize = grid[0].size();
        int freshCount = 0;

        queue<pair<pair<int, int>, int>>q;
        vector<vector<int>>visited(rowSize, vector<int>(colSize, -1));

        for(int i=0; i<rowSize; i++)
        {
            for(int j=0; j<colSize; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
                else
                {
                    visited[i][j] = 0;
                }
                if(grid[i][j] == 1) freshCount++;
            }
        }

        vector<int>delRow, delCol;
        delRow = {0, 0, -1, +1};
        delCol = {+1, -1, 0, 0};

        int result = 0;
        int count = 0;

        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            result = max(result, t);

            for(int i=0; i<4; i++)
            {
                int newRow = r + delRow[i];
                int newCol = c + delCol[i];
                
                if(newRow >= 0 && newRow < rowSize
                && newCol >= 0 && newCol < colSize
                && grid[newRow][newCol] == 1 
                && visited[newRow][newCol] != 2)
                {
                    q.push({{newRow, newCol}, t+1});
                    visited[newRow][newCol] = 2;
                    count++;
                }
            }
        }

        if(count != freshCount) return -1;
        return result;

    }
};