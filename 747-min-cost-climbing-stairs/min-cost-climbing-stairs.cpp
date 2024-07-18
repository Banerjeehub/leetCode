class Solution {
public:
    int f(int index, vector<int>&cost, vector<int>&dp)
    {
        if(index == 0) return cost[0];
        if(index < 0) return 0;
        if(dp[index] != -1) return dp[index];
        int one = cost[index] + f(index-1, cost, dp);
        int two = cost[index] + f(index-2, cost, dp);

        return dp[index] = min(one, two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>memo(n+1, -1);
        return min(f(n-1, cost, memo), f(n-2, cost, memo));
    }
};