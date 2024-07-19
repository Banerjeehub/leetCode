class Solution {
public:
    // int f(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp)
    // {
    //     if(i == 0 && j==0) return grid[i][j];
    //     if(i < 0 || j < 0) return 1e9;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int top = grid[i][j] + f(i-1, j, grid, dp); //2
    //     int left = grid[i][j] + f(i, j-1, grid, dp); // 3

    //     return dp[i][j] =  min(top, left);
    // }
    // int minPathSum(vector<vector<int>>& grid) {
        
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     vector<vector<int>>dp(n, vector<int>(m, -1));
    //     return f(n-1, m-1, grid, dp);
    // }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Initialize the dp array
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Set the value of the starting point
        dp[0][0] = grid[0][0];

        // Fill the first row (can only come from the left)
        for (int j = 1; j < m; ++j) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        // Fill the first column (can only come from above)
        for (int i = 1; i < n; ++i) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        // Fill the rest of the dp array
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // The bottom-right corner contains the answer
        return dp[n - 1][m - 1];
    }
};
