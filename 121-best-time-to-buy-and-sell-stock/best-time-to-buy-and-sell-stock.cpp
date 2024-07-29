class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxAns = INT_MIN;
        int buy = INT_MAX;
        int profit = INT_MIN;

        for(int it : prices)
        {
            buy = min(buy, it);
            profit = it - buy;
            maxAns = max(maxAns, profit);
        }

        return maxAns;
    }
};