class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minBuyingPrice = INT_MAX;

        for(auto it : prices)
        {
            minBuyingPrice = min(minBuyingPrice, it);
            profit = max(it - minBuyingPrice, profit);
        }

        return profit;
    }
};