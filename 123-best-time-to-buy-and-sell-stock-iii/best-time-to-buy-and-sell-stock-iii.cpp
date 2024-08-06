class Solution {
public:
    int f(int idx, int liberty, int cap, vector<int>&prices, vector<vector<vector<int>>>&dp)
    {
        if(idx == prices.size()) return 0;
        if(cap == 0) return 0;
        if(dp[idx][liberty][cap] != -1) return dp[idx][liberty][cap];
        int profit = 0;
        if(liberty)
        {
            profit = max(-prices[idx]+f(idx+1, 0, cap, prices, dp), f(idx+1, liberty, cap, prices, dp));
        }
        else
        {
            profit = max(prices[idx]+f(idx+1, 1, cap-1, prices, dp), f(idx+1, liberty, cap, prices, dp));
        }

        return dp[idx][liberty][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 1, 2, prices, dp);
    }
};