class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int maxCandie = INT_MIN;
        vector<bool>ans;
        for(int i : candies) maxCandie = max(maxCandie, i);
        for(int i=0; i<candies.size(); i++)
        {
            if(candies[i] + extraCandies >= maxCandie)
            {
                ans.push_back(true);
            }
            else ans.push_back(false);
        }

        return ans;
    }
};