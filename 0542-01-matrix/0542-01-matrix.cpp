class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rowSize = mat.size();
        int colSize = mat[0].size();

        queue<pair<pair<int, int>, int>>q;
        vector<vector<int>>visited(rowSize, vector<int>(colSize, 0));
        vector<vector<int>>result(rowSize, vector<int>(colSize, 0));
        vector<int>delRow, delCol;

        delRow = {0, 0, 1, -1};
        delCol = {1, -1, 0, 0};

        for(int i=0 ;i<rowSize; i++)
        {
            for(int j=0; j<colSize; j++)
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
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;

            q.pop();
            result[row][col] = steps;

            for(int i=0; i<4; i++)
            {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(newRow >= 0 && newRow < rowSize
                && newCol >= 0 && newCol < colSize
                && !visited[newRow][newCol])
                {
                    visited[newRow][newCol] = 1;
                    q.push({{newRow, newCol}, steps+1});
                }
            }

        }

        return result;


    }
};