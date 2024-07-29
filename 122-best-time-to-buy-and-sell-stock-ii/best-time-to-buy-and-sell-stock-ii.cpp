class Solution {
public:
    int f(int idx, int lib, vector<int>&prices, vector<vector<int>>&dp)
    {
        if(idx == prices.size()) return 0;
        int profit = 0;

        if(dp[idx][lib] != -1) return dp[idx][lib];

        if(lib)
        {
            profit = max((-prices[idx]+f(idx+1, 0, prices,dp)),
            f(idx+1, 1, prices,dp));
        }
        else profit = max((prices[idx]+f(idx+1, 1, prices,dp)),
        f(idx+1, 0, prices,dp));

        return dp[idx][lib] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1, vector<int>(2, 0));
        //return f(0, 1, prices, dp);

        dp[prices.size()][0] = dp[prices.size()][1] = 0;

        for(int i=prices.size()-1; i>=0; i--)
        {
            for(int j=0; j<=1; j++)
            {
                int profit = 0;
                if(j)
                {
                    profit = max(-prices[i]+dp[i+1][0],
                    dp[i+1][1]);
                }
                else profit = max(prices[i]+dp[i+1][1],
                dp[i+1][0]);

                dp[i][j] = profit;
            }
        }

        return dp[0][1];



    }
};