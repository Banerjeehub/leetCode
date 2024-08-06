class Solution {
public:
    int f(int i, int amount, vector<int>&coins, vector<vector<int>>&dp)
    {
        if(i == 0)
        {
            if(amount % coins[0] == 0) return amount/coins[0];
            else return 1e7;
        }
        if(dp[i][amount] != -1) return dp[i][amount];
        int notTake = f(i-1, amount, coins, dp);
        int take = INT_MAX;
        if(amount >= coins[i])
        {
            take = 1 + f(i, amount-coins[i], coins, dp);
        }

        return dp[i][amount] = min(take, notTake);

    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(), vector<int>(amount+1, -1));
        int ans = f(coins.size()-1, amount, coins, dp);
        if(ans >= 1e7) return -1;
        return ans;
    }
};