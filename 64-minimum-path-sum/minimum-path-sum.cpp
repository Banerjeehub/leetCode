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
        vector<vector<int>>dp(n, vector<int>(m, 0));
        dp[0][0] = grid[0][0];

        for(int i=1; i<m; i++)
        {
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        for(int i=1; i<n; i++)
        {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        for(int i=1; i<n; i++)
        {
            for(int j=1; j<m; j++)
            {
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n-1][m-1];
    }
};