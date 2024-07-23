class Solution {
public:
    int f(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp)
    {
        if(i == 0 && j == 0) return grid[0][0];
        if(i < 0 || j < 0) return 1e7;
        if(dp[i][j] != -1) return dp[i][j];
        int left = grid[i][j] + f(i, j-1, grid, dp);
        int top = grid[i][j] + f(i-1, j, grid, dp);

        return dp[i][j] =  min(left, top);
    }
    int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<int> dp(m, 0);

    // Initialize the first cell
    dp[0] = grid[0][0];

    // Initialize the first row
    for (int j = 1; j < m; j++) {
        dp[j] = dp[j-1] + grid[0][j];
    }

    // Process the rest of the grid
    for (int i = 1; i < n; i++) {
        // Update the first cell of the current row
        dp[0] += grid[i][0];
        for (int j = 1; j < m; j++) {
            dp[j] = grid[i][j] + min(dp[j], dp[j-1]);
        }
    }

    return dp[m-1];
}

};