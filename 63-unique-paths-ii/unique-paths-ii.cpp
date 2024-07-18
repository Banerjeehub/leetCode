class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // If the starting cell has an obstacle, then return 0 as no paths can go through
        if (grid[0][0] == 1) return 0;

        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Initialize the starting point
        dp[0][0] = 1;

        // Initialize the first column
        for (int i = 1; i < n; ++i) {
            dp[i][0] = (grid[i][0] == 1) ? 0 : dp[i - 1][0];
        }

        // Initialize the first row
        for (int j = 1; j < m; ++j) {
            dp[0][j] = (grid[0][j] == 1) ? 0 : dp[0][j - 1];
        }

        // Fill the dp array
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (grid[i][j] != 1) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};
