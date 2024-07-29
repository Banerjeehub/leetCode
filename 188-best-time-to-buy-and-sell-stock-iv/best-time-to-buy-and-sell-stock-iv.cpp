class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        // return f(0, 1, 2, prices, dp);

        for (int i = 0; i <= n; i++) {
            for (int lib = 0; lib <= 1; lib++) {
                dp[i][lib][0] = 0;
            }
        }

        for (int lib = 0; lib <= 1; lib++) {
            for (int cap = 0; cap <= k; cap++) {

                dp[n][lib][cap] = 0;
            }
        }

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int lib = 0; lib <= 1; lib++) {
                for (int cap = 1; cap <= k; cap++) {
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

        return dp[0][1][k];
    }
};