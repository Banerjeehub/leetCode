class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>>dp(m, vector<int>(n, 0));

        for(int i=0; i<n; i++)
        {
            dp[0][i] = 1;
        }
        for(int i=0; i<m; i++)
        {
            dp[i][0] = 1;
        }

        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                int left = dp[i][j-1];
                int top = dp[i-1][j];

                dp[i][j] = left + top;
            }
        }

        return dp[m-1][n-1];
    }
};