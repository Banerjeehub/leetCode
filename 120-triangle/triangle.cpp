class Solution {
public:
    int f(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp)
    {
        if(i == triangle.size()-1) return triangle[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int d = triangle[i][j] + f(i+1, j, triangle, dp);
        int dg = triangle[i][j] + f(i+1, j+1, triangle, dp);

        return dp[i][j] = min(d, dg);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(triangle.size(), vector<int>(triangle.size(), -1));
        return f(0, 0, triangle, dp);
    }
};