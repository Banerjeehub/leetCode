class Solution {
public:
    int rob(int idx, vector<int>&nums, vector<int>&dp)
    {
        if(idx < 0) return 0;
        if(dp[idx] != -1) return dp[idx];
        int take = nums[idx] + rob(idx-2, nums, dp);
        int notTake = rob(idx-1, nums, dp);

        return dp[idx] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1, -1);
        return rob(nums.size()-1, nums, dp);
    }
};