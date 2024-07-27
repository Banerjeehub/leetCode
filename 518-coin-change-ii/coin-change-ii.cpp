class Solution {
public:
    int f(int i, int target, vector<int>&coins, vector<vector<int>>&dp)
    {
        if(i == 0)
        {
            return (target % coins[0] == 0);
        }
        if(dp[i][target] != -1) return dp[i][target];
        int notTake = f(i-1, target, coins, dp);
        int take = 0;
        if(coins[i] <= target) take = f(i, target - coins[i], coins, dp);

        return dp[i][target] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int>prev(amount+1, 0), curr(amount+1, 0);
        for(int i=0; i<=amount; i++) 
        {
            prev[i] = (i % coins[0] == 0);
        }

        for(int i=1; i<n; i++)
        {
            for(int j=0; j<=amount; j++)
            {
                int notTake = prev[j];
                int take = 0;
                if(coins[i] <= j) take = curr[j-coins[i]];

                curr[j] = take + notTake;
            }
            prev = curr;
        }

        return prev[amount];
        // return f(n-1, amount, coins, dp);
    }
};