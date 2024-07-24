class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(triangle.size(), vector<int>(triangle.size(), 0));

        dp[0][0] = triangle[0][0];

        for(int row=1; row<n; row++)
        {
            for(int col=0; col<=row; col++)
            {
                if(col == 0)
                {
                    dp[row][col] = triangle[row][col] + dp[row-1][col];
                }
                else if(col == row)
                {
                    dp[row][col] = triangle[row][col] + dp[row-1][col-1];
                }
                else
                {
                    dp[row][col] = triangle[row][col] + min(dp[row-1][col], dp[row-1][col-1]);
                }
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