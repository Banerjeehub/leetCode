class Solution {
public:
    int solve(int n, vector<int>&dp)
    {
        if(n <= 0) return dp[n] = 0;
        if(n == 1) return dp[n] = 1;
        if(n ==  2) return dp[n] = 2;
        if(dp[n] != -1) return dp[n];

        return dp[n] = solve(n-1, dp) + solve(n-2, dp);
        
    }
    int climbStairs(int n) {
        vector<int>dp(n+1, -1);
        solve(n, dp);
        return dp[n];
    }
};