class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        //vector<vector<int>>dp(triangle.size(), vector<int>(triangle.size(), 0));
        vector<int>dp(n, 0);

        dp[0] = triangle[0][0];

        for(int row=1; row<n; row++)
        {
            for(int col=row; col>=0; col--)
            {
                if(col == 0)
                {
                    dp[col] = triangle[row][col] + dp[col];
                }
                else if(col == row)
                {
                    dp[col] = triangle[row][col] + dp[col-1];
                }
                else
                {
                    dp[col] = triangle[row][col] + min(dp[col], dp[col-1]);
                }
            }
        }

        int ans = INT_MAX;
        for(int i=0; i<n; i++)
        {
            ans = min(ans, dp[i]);
        }

        return ans;

    }
};