class Solution {
public:
    int f(int idx, int n, int liberty, vector<int>&prices, vector<vector<int>>&dp)
    {
        if(idx >= n) return 0;
        if(dp[idx][liberty] != -1) return dp[idx][liberty];
        int profit = 0;
        if(liberty)
        {
            profit = max(-prices[idx] + f(idx+1, n, 0, prices, dp), f(idx+1, n, liberty, prices, dp));
        }
        else
        {
            profit = max(prices[idx] + f(idx+2, n, 1, prices, dp), f(idx+1, n, liberty, prices, dp));
        }
        return dp[idx][liberty] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return f(0, n, 1, prices, dp);
    }
};