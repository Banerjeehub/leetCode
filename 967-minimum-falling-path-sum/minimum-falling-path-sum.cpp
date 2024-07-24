class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));

        for(int i=0; i<n; i++) dp[0][i] = matrix[0][i];

        for(int i=1; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int ld = 1e8, rd = 1e8;
                int up = matrix[i][j] + dp[i-1][j];
                if(j - 1 >= 0)
                {
                    ld = matrix[i][j] + dp[i-1][j-1];
                }
                if(j + 1 < n) rd = matrix[i][j] + dp[i-1][j+1];

                dp[i][j] = min(up, min(ld, rd));
            }
        }
        int ans = INT_MAX;
        for(int i=0; i<n; i++)
        {
            ans = min(ans, dp[n-1][i]);
        }

        return ans;
    }
};