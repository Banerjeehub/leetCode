class Solution {
private:
    void DFS(int row, int col, vector<vector<int>>&image, vector<vector<int>>&ans, vector<int>delRow, 
            vector<int>delCol, int iniColor, int newColor)
            {
                ans[row][col] = newColor;

                int rowSize = image.size();
                int colSize = image[0].size();

                for(int i=0; i<4; i++)
                {
                    int newRow = row + delRow[i];
                    int newCol = col + delCol[i];

                    if(newRow >= 0 && newRow < rowSize &&
                       newCol >= 0 && newCol < colSize &&
                       image[newRow][newCol] == iniColor && ans[newRow][newCol] != newColor)
                       {
                           DFS(newRow, newCol, image, ans, delRow, delCol, iniColor, newColor);
                       }
                }
            }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans = image;

        int iniColor = image[sr][sc];

        vector<int>delRow = {0, 0, -1, +1};
        vector<int>delCol = {1, -1, 0, 0};

        DFS(sr, sc, image, ans, delRow, delCol, iniColor, color);

        return ans;
    }

};