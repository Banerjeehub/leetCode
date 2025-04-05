class Solution {
public:
    int maxProfit(int idx, int lib, vector<int>&prices, vector<vector<int>>&dp)
    {
        if(idx == prices.size()) return 0;
        if(dp[idx][lib] != -1) return dp[idx][lib];
        int profit = 0;
        if(lib)
        {
            profit = max(-prices[idx] + maxProfit(idx+1, 0, prices, dp), maxProfit(idx+1, 1, prices, dp));
        }
        else
        {
            profit = max(prices[idx] + maxProfit(idx+1, 1, prices, dp), maxProfit(idx+1, 0, prices, dp));
        }

        return dp[idx][lib] = profit;
    }
    int maxProfit(vector<int>& prices) {
        
        vector<vector<int>>dp(prices.size()+1, vector<int>(2, -1));
        return maxProfit(0, 1, prices, dp);

    }
};