class Solution {
public:
    int f(int i, int sum, vector<vector<int>>& dp, vector<int>& coins){
        if(i==0){
            if(sum%coins[i]==0){
                return sum/coins[i];
            }
            else{return 1e9;}
        }
        if(dp[i][sum]!=-1){return dp[i][sum];}
        int nt=f(i-1, sum, dp, coins), tk=1e9;
        if(sum>=coins[i]){
            tk=1+f(i, sum-coins[i], dp, coins);
        }
        return dp[i][sum]=min(tk, nt);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        int ans=f(n-1, amount, dp, coins);
        if(ans>=1e9){return -1;}
        return ans;
    }
};