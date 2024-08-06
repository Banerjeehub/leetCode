class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0;
        int maxProfit = INT_MIN;
        int buy = INT_MAX;

        for(auto it : prices)
        {
            if(it < buy)
            {
                buy = it;
            }

            profit = max(profit, it - buy);
            maxProfit = max(profit, maxProfit);
        }

        return maxProfit;

    }
};