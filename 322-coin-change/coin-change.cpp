class Solution {
public:
    int f(int idx, int amount, vector<int>&coins, vector<vector<int>>&dp)
    {
        if(idx == 0)
        {
            if(amount % coins[0] == 0) return amount / coins[0];
            return 1e7;
        }

        if(dp[idx][amount] != -1) return dp[idx][amount];

        int notTake = f(idx-1, amount,  coins, dp);
        int take = 1e7;
        if(amount >= coins[idx])
        {
            take = 1 + f(idx, amount-coins[idx], coins, dp);
        }

        return dp[idx][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        int ans = f(n-1, amount, coins, dp);
        if(ans == 1e7) return -1;
        return ans;
        
    }
};