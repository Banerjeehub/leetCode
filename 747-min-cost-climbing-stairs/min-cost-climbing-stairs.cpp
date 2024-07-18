class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        cost.push_back(0);

        for(int i=2; i<=n; i++)
        {
            cost[i] += min(cost[i-1] , cost[i-2]);
        }

        return min(cost[n], cost[n-1]);
    }
};