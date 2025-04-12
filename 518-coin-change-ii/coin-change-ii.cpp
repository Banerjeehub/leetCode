class Solution {
public:
    int helper(int amount, int idx, vector<int>&coins, vector<vector<int>>&dp)
    {
        if(idx == 0)
        {
            return (amount % coins[idx] == 0) ? 1 : 0;
            
        }
        if(dp[idx][amount] != -1) return dp[idx][amount];
        int notTake = helper(amount, idx-1, coins, dp);
        int take = 0;

        if(amount >= coins[idx])
        {
            take = helper(amount - coins[idx], idx, coins, dp);
        }

        return dp[idx][amount] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        
        vector<vector<int>>dp(coins.size(), vector<int>(amount+1, -1));
        return helper(amount, coins.size()-1, coins, dp);
    }
};