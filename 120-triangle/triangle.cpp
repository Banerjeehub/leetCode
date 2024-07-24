class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(triangle.size(), vector<int>(triangle.size(), 0));
        
        for(int i=0; i<triangle.size(); i++) 
            dp[triangle.size()-1][i] = triangle[triangle.size()-1][i];

        for(int i=n-2; i>=0; i--)
        {
            for(int j=i; j>=0; j--)
            {
                int d = triangle[i][j] + dp[i+1][j];
                int dg = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(d, dg);
            }
        }

        return dp[0][0];

    }
};