class Solution {
public:
    int f(int i, int tar, vector<int>&coins, vector<vector<int>>&dp)
    {
        if(i == 0)
        {
            if(tar % coins[0] == 0) return tar / coins[0];
            else return 1e9;
        }
        if(dp[i][tar] != -1) return dp[i][tar];
        int notTake = f(i-1, tar, coins, dp);
        int take = INT_MAX;
        if(coins[i] <= tar) take = 1 + f(i, tar - coins[i], coins, dp);
        return dp[i][tar] =  min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount + 1, -1));
        int ans =  f(n-1, amount, coins, dp);
        if(ans >= 1e9) return -1;
        return ans;
    }
};