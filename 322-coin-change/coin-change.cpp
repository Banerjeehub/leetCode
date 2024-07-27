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
        //vector<vector<int>>dp(n, vector<int>(amount + 1, 0));
        vector<int>prev(amount+1, 0), curr(amount+1, 0);

        for(int i=0; i<=amount; i++)
        {
            if(i % coins[0] == 0)
            {
                prev[i] = i / coins[0];
            }
            else prev[i] = 1e9;
        }

        for(int i=1; i<n; i++)
        {
            for(int j=0; j<=amount; j++)
            {
                int notTake = prev[j];
                int take = INT_MAX;
                if(j >= coins[i]) take = 1 + curr[j - coins[i]];

                curr[j] = min(take, notTake);
            }
            prev = curr;
        }

        if(prev[amount] >= 1e9) return -1;
        return prev[amount];








        // int ans =  f(n-1, amount, coins, dp);
        // if(ans >= 1e9) return -1;
        // return ans;
    }
};