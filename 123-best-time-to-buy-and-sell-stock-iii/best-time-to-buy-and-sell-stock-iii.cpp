class Solution {
public:
    int f(int idx, int lib, int cap, vector<int>& prices,
          vector<vector<vector<int>>>& dp) {
        if (cap == 0)
            return 0;
        if (idx == prices.size())
            return 0;

        if (dp[idx][lib][cap] != -1)
            return dp[idx][lib][cap];
        int profit = 0;
        if (lib) {
            profit = max(-prices[idx] + f(idx + 1, 0, cap, prices, dp),
                         f(idx + 1, 1, cap, prices, dp));
        } else {
            profit = max(prices[idx] + f(idx + 1, 1, cap - 1, prices, dp),
                         f(idx + 1, 0, cap, prices, dp));
        }

        return dp[idx][lib][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        // return f(0, 1, 2, prices, dp);

        for (int i = 0; i <= n; i++) {
            for (int lib = 0; lib <= 1; lib++) {
                dp[i][lib][0] = 0;
            }
        }

        for (int lib = 0; lib <= 1; lib++) {
            for (int cap = 0; cap <= 2; cap++) {
                
                dp[n][lib][cap] = 0;
            }
        }

        for(int idx=n-1; idx>=0; idx--)
        {
            for(int lib=0; lib<=1; lib++)
            {
                for(int cap=1; cap<=2; cap++)
                {
                    int profit = 0;
                    if (lib) {
                        profit = max(-prices[idx] + dp[idx + 1][0][cap],
                                    dp[idx + 1][1][cap]);
                    } else {
                        profit = max(prices[idx] + dp[idx + 1][1][cap - 1],
                                    dp[idx + 1][0][cap]);
                    }

                    dp[idx][lib][cap] = profit;
                }
            }
        }

        return dp[0][1][2];
    }
};