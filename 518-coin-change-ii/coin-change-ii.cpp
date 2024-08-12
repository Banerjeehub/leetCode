class Solution {
public:
    int f(int idx, int amount, vector<int>&coins, vector<vector<int>>&dp)
    {
        if(idx == 0)
        {
            return (amount % coins[0] == 0);
        }

        if(dp[idx][amount] != -1) return dp[idx][amount];

        int notTake = f(idx-1, amount, coins, dp);
        int take = 0;
        if(amount >= coins[idx]) take = f(idx, amount-coins[idx], coins, dp);

        return dp[idx][amount] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, 0));
        //return f(n-1, amount, coins, dp);
        vector<int>prev(amount+1, 0), curr(amount+1, 0);

        for(int i=0; i<=amount; i++)
        {
            if(i % coins[0] == 0) prev[i] = 1;  
        }

        for(int i=1; i<n; i++)
        {
            for(int j=0; j<=amount; j++)
            {
                int notTake = prev[j];
                int take = 0;
                if(j >= coins[i]) take = curr[j-coins[i]];

                curr[j] = take + notTake;
            }
            prev = curr;
        }

        return prev[amount];
    }
};