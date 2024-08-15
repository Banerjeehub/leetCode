class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int buy = INT_MAX;
        int maxProfit = INT_MIN;

        for(auto it : prices)
        {
            buy = min(buy, it);
            maxProfit = max(maxProfit, (it - buy));
        }

        return maxProfit;
    }
};