class Solution {
public:
    int f(int index, vector<int>&arr, vector<int>&dp)
    {
        if(index == 0) return arr[index];
        if(index < 0) return 0;
        if(dp[index] != -1) return dp[index];
        int pick = arr[index] + f(index - 2, arr, dp);
        int notP = f(index-1, arr, dp);

        return dp[index] = max(pick, notP);
    }
    int rob(vector<int>& nums) {
        int index = nums.size();
         if(index == 1) return nums[0];

        vector<int>first, second, dp1(nums.size(), -1), dp2(nums.size(), -1);

        for(int i=0; i<nums.size(); i++)
        {
            if(i != 0) first.push_back(nums[i]);
            if(i != nums.size() - 1) second.push_back(nums[i]);
        }


        return max(f(first.size()-1, first, dp1), f(second.size()-1, second, dp2));

    }
};