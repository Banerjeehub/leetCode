class Solution {
public:
    int f(int idx, int lib, vector<int>& prices, vector<vector<int>>& dp) {
        if (idx >= prices.size())
            return 0;
        if (dp[idx][lib] != -1)
            return dp[idx][lib];
        int profit = 0;
        if (lib) {
            profit = max(-prices[idx] + f(idx + 1, 0, prices, dp),
                         f(idx + 1, 1, prices, dp));
        } else {
            profit = max(prices[idx] + f(idx + 2, 1, prices, dp),
                         f(idx + 1, 0, prices, dp));
        }

        return dp[idx][lib] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return f(0, 1, prices, dp);
    }
};