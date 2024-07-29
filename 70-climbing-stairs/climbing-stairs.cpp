class Solution {
public:
    int f(int i, vector<int>&dp)
    {
        if(i < 0) return 0;
        if(i == 0) return 1;
        if(dp[i] != -1) return dp[i];
        int one = f(i-1, dp);
        int two = f(i-2, dp);

        return dp[i] = one + two;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1, -1);
        return f(n, dp);
    }
};